






#if 700 < 700
  #undef 700
  #define 700 700
#endif
#if _GNU_SOURCE
#include <stdint.h>
#include <string.h>
#include <fenv.h>
#endif





typedef double number; 






number macro_min (number a, number b) { return a < b ? a : b; } 
number macro_sq (number x) { return x*x; } 
number macro_cube (number x) { return x*x*x; } 
int macro_sign (number x) { return (int)(x > 0 ? 1 : -1); } 
int macro_sign2 (number x) { return (int)(x > 0 ? 1 : x < 0 ? -1 : 0); } 
number macro_clamp (number x, number a, number b) {
  return x < a ? a : x > b ? b : x;
} 





#include <stdlib.h>


#include <stdio.h>


#include <stddef.h>


#include <stdint.h>


#include <stdbool.h>


#include <stdarg.h>


#include <string.h>


#include <float.h>


#include <limits.h>


#include <math.h>


#include <time.h>


#include <sys/time.h>


#include <sys/resource.h>





#define unmap(x,y)
#define trash(x)


void macro_BEGIN_FOREACH() {;}


# include <omp.h>
# define OMP(x) _Pragma(#x)

void macro_OMP_SERIAL()
{
  #undef OMP
  #define OMP(x)
  ;
  ;
  #undef OMP
#define OMP(x) _Pragma(#x)
  ;
}

#define _NVARMAX 65536
#define is_constant(v) ((v).i >= _NVARMAX)
#define constant(v) (is_constant(v) ? _constant[(v).i - _NVARMAX] : 1e30f)

#define systderr stderr
#define systdout stdout

# define qstderr() stderr
# define qstdout() stdout
# define ferr stderr
# define fout stdout
# define not_mpi_compatible()



static inline void qassert (const char * file, int line, const char * cond) {
  fprintf (ferr, "%s:%d: Assertion `%s' failed.\n", file, line, cond);
  abort();
}







#define sysmalloc malloc
#define syscalloc calloc
#define sysrealloc realloc
#define sysfree free
#define systrdup strdup




# define pmalloc(s,func,file,line) malloc(s)
# define pcalloc(n,s,func,file,line) calloc(n,s)
# define prealloc(p,s,func,file,line) realloc(p,s)
# define pfree(p,func,file,line) free(p)
# define pstrdup(s,func,file,line) strdup(s)









typedef struct {
  void * p;
  long max, len;
} Array;

Array * array_new()
{
  Array * a = ((Array *) pmalloc ((1)*sizeof(Array),__func__,__FILE__,0));
  a->p = NULL;
  a->max = a->len = 0;
  return a;
}

void array_free (Array * a)
{
  pfree (a->p,__func__,__FILE__,0);
  pfree (a,__func__,__FILE__,0);
}

void * array_append (Array * a, void * elem, size_t size)
{
  if (a->len + size >= a->max) {
    a->max += ( size > 4096 ? size : 4096);
    a->p = prealloc (a->p, a->max,__func__,__FILE__,0);
  }
  memcpy (((char *)a->p) + a->len, elem, size);
  a->len += size;
  return (void *)(((char *)a->p) + a->len - size);
}

void * array_shrink (Array * a)
{
  void * p = prealloc (a->p, a->len,__func__,__FILE__,0);
  pfree (a,__func__,__FILE__,0);
  return p;
}


# define tracing(...)
# define end_tracing(...)






#define tid() omp_get_thread_num()
#define pid() 0
#define npe() omp_get_num_threads()
#define mpi_all_reduce(v,type,op)
#define mpi_all_reduce_array(v,type,op,elem)
#define mpi_sum_reduce_init(s,v,type,op,elem)
#define mpi_sum_reduce_array(s,v,type,op,elem)

void macro_OMP_PARALLEL() {;}
#define OMP_PARALLEL(...) OMP(omp parallel __VA_ARGS__)

#define NOT_UNUSED(x) (void)(x)

void macro2_VARIABLES() { ; }
#define _index(a,m) (a.i)
#define val(a,k,l,m) data(k,l,m)[_index(a,m)]

double _val_higher_dimension = 0.;

#if (_GNU_SOURCE || __APPLE__) && !201511 && !_CADNA
double undefined;
# if __APPLE__
# include <stdint.h>
# include "fp_osx.h"
# endif
#if _GPU
# define enable_fpe(flags)
#else
# define enable_fpe(flags) feenableexcept (flags)
#endif
# define disable_fpe(flags) fedisableexcept (flags)
static void set_fpe (void) {
  int64_t lnan = 0x7ff0000000000001;
  if (!(sizeof (int64_t) == sizeof (double))) qassert ("/home/jacqhugo/basilisk/src/grid/config.h", 0, "sizeof (int64_t) == sizeof (double)");
  memcpy (&undefined, &lnan, sizeof (double));
  enable_fpe (FE_DIVBYZERO|FE_INVALID);
}
#else
# define undefined ((double) DBL_MAX)
# define enable_fpe(flags)
# define disable_fpe(flags)
static void set_fpe (void) {}
#endif



static FILE ** qpopen_pipes = NULL;

FILE * qpopen (const char * command, const char * type)
{
  if (pid() > 0)
    return fopen ("/dev/null", type);
  FILE * fp = popen (command, type);
  if (fp) {
    FILE ** i = qpopen_pipes;
    int n = 0;
    while (i && *i) { n++; i++; }
    qpopen_pipes = (FILE * *) prealloc (qpopen_pipes, (n + 2)*sizeof(FILE *),__func__,__FILE__,0);
    qpopen_pipes[n] = fp;
    qpopen_pipes[n+1] = NULL;
  }
  return fp;
}

int qpclose (FILE * fp)
{
  if (pid() > 0)
    return fclose (fp);
  FILE ** i = qpopen_pipes;
  while (i && *i) {
    if (*i == fp)
      *i = (FILE *) 1;
    i++;
  }
  return pclose (fp);
}

static void qpclose_all()
{
  FILE ** i = qpopen_pipes;
  while (i && *i) {
    if (*i != (FILE *) 1)
      pclose (*i);
    i++;
  }
  pfree (qpopen_pipes,__func__,__FILE__,0);
  qpopen_pipes = NULL;
}






FILE * lfopen (const char * name, const char * mode)
{
  char fname[80];
  sprintf (fname, "%s-%d", name, pid());
  return fopen (fname, mode);
}



const char * symbol_name (int sym);
int token_symbol (int token);
enum yysymbol_kind_t
{
  sym_YYEMPTY = -2,
  sym_YYEOF = 0,
  sym_YYerror = 1,
  sym_YYUNDEF = 2,
  sym_IDENTIFIER = 3,
  sym_I_CONSTANT = 4,
  sym_F_CONSTANT = 5,
  sym_STRING_LITERAL = 6,
  sym_FUNC_NAME = 7,
  sym_SIZEOF = 8,
  sym_PTR_OP = 9,
  sym_INC_OP = 10,
  sym_DEC_OP = 11,
  sym_LEFT_OP = 12,
  sym_RIGHT_OP = 13,
  sym_LE_OP = 14,
  sym_GE_OP = 15,
  sym_EQ_OP = 16,
  sym_NE_OP = 17,
  sym_AND_OP = 18,
  sym_OR_OP = 19,
  sym_MUL_ASSIGN = 20,
  sym_DIV_ASSIGN = 21,
  sym_MOD_ASSIGN = 22,
  sym_ADD_ASSIGN = 23,
  sym_SUB_ASSIGN = 24,
  sym_LEFT_ASSIGN = 25,
  sym_RIGHT_ASSIGN = 26,
  sym_AND_ASSIGN = 27,
  sym_XOR_ASSIGN = 28,
  sym_OR_ASSIGN = 29,
  sym_TYPEDEF_NAME = 30,
  sym_ENUMERATION_CONSTANT = 31,
  sym_TYPEDEF = 32,
  sym_EXTERN = 33,
  sym_STATIC = 34,
  sym_AUTO = 35,
  sym_REGISTER = 36,
  sym_INLINE = 37,
  sym_CONST = 38,
  sym_RESTRICT = 39,
  sym_VOLATILE = 40,
  sym_BOOL = 41,
  sym_CHAR = 42,
  sym_SHORT = 43,
  sym_INT = 44,
  sym_LONG = 45,
  sym_SIGNED = 46,
  sym_UNSIGNED = 47,
  sym_FLOAT = 48,
  sym_DOUBLE = 49,
  sym_VOID = 50,
  sym_COMPLEX = 51,
  sym_IMAGINARY = 52,
  sym_STRUCT = 53,
  sym_UNION = 54,
  sym_ENUM = 55,
  sym_ELLIPSIS = 56,
  sym_CASE = 57,
  sym_DEFAULT = 58,
  sym_IF = 59,
  sym_ELSE = 60,
  sym_SWITCH = 61,
  sym_WHILE = 62,
  sym_DO = 63,
  sym_FOR = 64,
  sym_GOTO = 65,
  sym_CONTINUE = 66,
  sym_BREAK = 67,
  sym_RETURN = 68,
  sym_ALIGNAS = 69,
  sym_ALIGNOF = 70,
  sym_ATOMIC = 71,
  sym_GENERIC = 72,
  sym_NORETURN = 73,
  sym_STATIC_ASSERT = 74,
  sym_THREAD_LOCAL = 75,
  sym_MAYBECONST = 76,
  sym_NEW_FIELD = 77,
  sym_TRACE = 78,
  sym_FOREACH_DIMENSION = 79,
  sym_REDUCTION = 80,
  sym_MACRO = 81,
  sym_ELLIPSIS_MACRO = 82,
  sym_MACRODEF = 83,
  sym_foreach_statement = 84,
  sym_85_ = 85,
  sym_86_ = 86,
  sym_87_ = 87,
  sym_88_ = 88,
  sym_89_ = 89,
  sym_90_ = 90,
  sym_91_ = 91,
  sym_92_ = 92,
  sym_93_ = 93,
  sym_94_ = 94,
  sym_95_ = 95,
  sym_96_ = 96,
  sym_97_ = 97,
  sym_98_ = 98,
  sym_99_ = 99,
  sym_100_ = 100,
  sym_101_ = 101,
  sym_102_ = 102,
  sym_103_ = 103,
  sym_104_ = 104,
  sym_105_ = 105,
  sym_106_ = 106,
  sym_107_ = 107,
  sym_108_ = 108,
  sym_YYACCEPT = 109,
  sym_translation_unit = 110,
  sym_primary_expression = 111,
  sym_expression_error = 112,
  sym_constant = 113,
  sym_enumeration_constant = 114,
  sym_string = 115,
  sym_generic_selection = 116,
  sym_generic_assoc_list = 117,
  sym_generic_association = 118,
  sym_postfix_expression = 119,
  sym_postfix_initializer = 120,
  sym_array_access = 121,
  sym_function_call = 122,
  sym_member_identifier = 123,
  sym_argument_expression_list = 124,
  sym_argument_expression_list_item = 125,
  sym_unary_expression = 126,
  sym_unary_operator = 127,
  sym_cast_expression = 128,
  sym_multiplicative_expression = 129,
  sym_additive_expression = 130,
  sym_shift_expression = 131,
  sym_relational_expression = 132,
  sym_equality_expression = 133,
  sym_and_expression = 134,
  sym_exclusive_or_expression = 135,
  sym_inclusive_or_expression = 136,
  sym_logical_and_expression = 137,
  sym_logical_or_expression = 138,
  sym_conditional_expression = 139,
  sym_assignment_expression = 140,
  sym_assignment_operator = 141,
  sym_expression = 142,
  sym_constant_expression = 143,
  sym_declaration = 144,
  sym_declaration_specifiers = 145,
  sym_init_declarator_list = 146,
  sym_init_declarator = 147,
  sym_storage_class_specifier = 148,
  sym_type_specifier = 149,
  sym_types = 150,
  sym_struct_or_union_specifier = 151,
  sym_struct_or_union = 152,
  sym_struct_declaration_list = 153,
  sym_struct_declaration = 154,
  sym_specifier_qualifier_list = 155,
  sym_struct_declarator_list = 156,
  sym_struct_declarator = 157,
  sym_enum_specifier = 158,
  sym_enumerator_list = 159,
  sym_enumerator = 160,
  sym_atomic_type_specifier = 161,
  sym_type_qualifier = 162,
  sym_function_specifier = 163,
  sym_alignment_specifier = 164,
  sym_declarator = 165,
  sym_direct_declarator = 166,
  sym_generic_identifier = 167,
  sym_pointer = 168,
  sym_type_qualifier_list = 169,
  sym_parameter_type_list = 170,
  sym_parameter_list = 171,
  sym_parameter_declaration = 172,
  sym_identifier_list = 173,
  sym_type_name = 174,
  sym_abstract_declarator = 175,
  sym_direct_abstract_declarator = 176,
  sym_type_not_specified = 177,
  sym_initializer = 178,
  sym_initializer_list = 179,
  sym_designation = 180,
  sym_designator_list = 181,
  sym_designator = 182,
  sym_static_assert_declaration = 183,
  sym_statement = 184,
  sym_labeled_statement = 185,
  sym_compound_statement = 186,
  sym_187_1 = 187,
  sym_block_item_list = 188,
  sym_block_item = 189,
  sym_expression_statement = 190,
  sym_selection_statement = 191,
  sym_for_scope = 192,
  sym_iteration_statement = 193,
  sym_for_declaration_statement = 194,
  sym_jump_statement = 195,
  sym_external_declaration = 196,
  sym_function_declaration = 197,
  sym_function_definition = 198,
  sym_declaration_list = 199,
  sym_basilisk_statements = 200,
  sym_macro_statement = 201,
  sym_reduction_list = 202,
  sym_reduction = 203,
  sym_reduction_operator = 204,
  sym_reduction_array = 205,
  sym_foreach_dimension_statement = 206,
  sym_forin_declaration_statement = 207,
  sym_forin_statement = 208,
  sym_forin_arguments = 209,
  sym_event_definition = 210,
  sym_event_parameters = 211,
  sym_event_parameter = 212,
  sym_boundary_definition = 213,
  sym_external_foreach_dimension = 214,
  sym_attribute = 215,
  sym_new_field = 216,
  sym_root = 217
};


enum typedef_kind_t {
  sym_SCALAR = sym_root + 1,
  sym_VECTOR,
  sym_TENSOR,
  sym_COORD,
  sym__COORD,
  sym_VEC4,
  sym_IVEC
};

#define attroffset(x) (offsetof(_Attributes,x))




typedef int Reduce;

void macro_foreach_face (char flags, Reduce reductions,
   const char * order)
{;}
void macro_einstein_sum() {;}
void macro_diagonalize (int a) {;}




#define dimensional(...)

#define show_dimension_internal(...)
#define display_value(...)
#define interpreter_verbosity(...)


static inline double noise() { return 1. - 2.*rand()/(double)RAND_MAX; }


typedef struct {
  long n;
  long tn;
  int depth;
  int maxdepth;
} Grid;
Grid * grid = NULL;

double X0 = 0., Y0 = 0., Z0 = 0.;

double L0 = 1.;


int N = 64;




typedef struct { int i; } scalar;

typedef struct {
  scalar x;

  scalar y;




} vector;

typedef struct {
  scalar * x;

  scalar * y;




} vectorl;

typedef struct {
  vector x;

  vector y;




} tensor;

struct { int x, y, z; } Period = {false, false, false};

typedef struct {
  double x, y, z;
} coord;

OMP(omp declare reduction (+ : coord :
      omp_out.x += omp_in.x,
      omp_out.y += omp_in.y,
      omp_out.z += omp_in.z))

void normalize (coord * n)
{
  double norm = 0.;
  
    norm += ( (n->x)*(n->x));    norm += ( (n->y)*(n->y));
  norm = sqrt(norm);
  
    n->x /= norm;    n->y /= norm;
}

void origin (double x, double y, double z) {
  X0 = x; Y0 = y; Z0 = z;
}

void size (double L) {
  L0 = L;
}

double zero (double s0, double s1, double s2) { return 0.; }






  enum { right, left, top, bottom };



int nboundary = 2*2;



double * _constant = NULL;
size_t datasize = 0;
typedef struct _Point Point;




typedef struct _Boundary Boundary;

struct _Boundary {
  void (* destroy) (Boundary * b);
  void (* level) (const Boundary * b, scalar * list, int l);

  void (* restriction) (const Boundary * b, scalar * list, int l);
};

static Boundary ** boundaries = NULL;

void add_boundary (Boundary * b) {
  int len = 0;
  if (boundaries) {
    Boundary ** i = boundaries;
    while (*i++) len++;
  }
  boundaries = (Boundary * *) prealloc (boundaries, (len + 2)*sizeof(Boundary *),__func__,__FILE__,0);
  boundaries[len] = b;
  boundaries[len+1] = NULL;
}

void free_boundaries() {
  if (!boundaries)
    return;
  Boundary ** i = boundaries, * b;
  while ((b = *i++))
    if (b->destroy)
      b->destroy (b);
    else
      pfree (b,__func__,__FILE__,0);
  pfree (boundaries,__func__,__FILE__,0);
  boundaries = NULL;
}

typedef struct {
  Boundary parent;
  int d;
} BoxBoundary;




typedef struct {
  int x;

  int y;




} ivec;
typedef double (* BoundaryFunc) (Point, Point, scalar, bool *);
typedef void (* BoundaryStencilFunc) (Point, Point, scalar, void *);
typedef struct {
  BoundaryFunc * boundary;
  BoundaryFunc * boundary_homogeneous;
  BoundaryStencilFunc * boundary_stencil;
  double (* gradient) (double, double, double);
  void (* delete) (scalar);
  char * name;
  ivec d;
  vector v;
  int face;
  bool nodump, freed;
  int block;
  scalar * depends;  

struct {
    int bc, io, width;
  } stencil;  

void (* prolongation) (Point, scalar);
  void (* restriction) (Point, scalar);  

void ** kdt;
  scalar nt, dmin, dmax;


} _Attributes;

static _Attributes * _attribute = NULL;







ivec Dimensions = {1,1};






int list_len (scalar * list)
{
  if (!list) return 0;
  int ns = 0;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ ns++;}}
  return ns;
}

scalar * list_append (scalar * list, scalar s)
{
  int len = list_len (list);
  list = (scalar *) prealloc (list, (len + 2)*sizeof(scalar),__func__,__FILE__,0);
  list[len] = s;
  list[len + 1].i = -1;
  return list;
}

scalar * list_prepend (scalar * list, scalar s)
{
  int len = list_len (list);
  list = (scalar *) prealloc (list, (len + 2)*sizeof(scalar),__func__,__FILE__,0);
  for (int i = len; i >= 1; i--)
    list[i] = list[i-1];
  list[0] = s;
  list[len + 1].i = -1;
  return list;
}

scalar * list_add (scalar * list, scalar s)
{
  {scalar*_i=(scalar*)( list);if(_i)for(scalar t=*_i;(&t)->i>=0;t=*++_i){
    if (t.i == s.i)
      return list;}}
  return list_append (list, s);
}

int list_lookup (scalar * l, scalar s)
{
  if (l != NULL)
    {scalar*_i=(scalar*)( l);if(_i)for(scalar s1=*_i;(&s1)->i>=0;s1=*++_i){
      if (s1.i == s.i)
 return true;}}
  return false;
}

scalar * list_copy (scalar * l)
{
  scalar * list = NULL;
  if (l != NULL)
    {scalar*_i=(scalar*)( l);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      list = list_append (list, s);}}
  return list;
}

scalar * list_concat (scalar * l1, scalar * l2)
{
  scalar * l3 = list_copy (l1);
  {scalar*_i=(scalar*)( l2);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    l3 = list_append (l3, s);}}
  return l3;
}

void list_print (scalar * l, FILE * fp)
{
  int i = 0;
  {scalar*_i=(scalar*)( l);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    fprintf (fp, "%s%s", i++ == 0 ? "{" : ",", _attribute[s.i].name);}}
  fputs (i > 0 ? "}\n" : "{}\n", fp);
}

int vectors_len (vector * list)
{
  if (!list) return 0;
  int nv = 0;
  {vector*_i=(vector*)( list);if(_i)for(vector v=*_i;(&v)->x.i>=0;v=*++_i){ nv++;}}
  return nv;
}

vector * vectors_append (vector * list, vector v)
{
  int len = vectors_len (list);
  list = (vector *) prealloc (list, (len + 2)*sizeof(vector),__func__,__FILE__,0);
  list[len] = v;
  list[len + 1] = (vector){{-1}};
  return list;
}

vector * vectors_add (vector * list, vector v)
{
  {vector*_i=(vector*)( list);if(_i)for(vector w=*_i;(&w)->x.i>=0;w=*++_i){ {
    bool id = true;
    
      if (w.x.i != v.x.i)
 id = false;      

if (w.y.i != v.y.i)
 id = false;
    if (id)
      return list;
  }}}
  return vectors_append (list, v);
}

vector * vectors_copy (vector * l)
{
  vector * list = NULL;
  if (l != NULL)
    {vector*_i=(vector*)( l);if(_i)for(vector v=*_i;(&v)->x.i>=0;v=*++_i){
      list = vectors_append (list, v);}}
  return list;
}

vector * vectors_from_scalars (scalar * s)
{
  vector * list = NULL;
  while (s->i >= 0) {
    vector v;
     {
      if (!(s->i >= 0)) qassert ("/home/jacqhugo/basilisk/src/common.h", 0, "s->i >= 0");
      v.x = *s++;
    } 

{
      if (!(s->i >= 0)) qassert ("/home/jacqhugo/basilisk/src/common.h", 0, "s->i >= 0");
      v.y = *s++;
    }
    list = vectors_append (list, v);
  }
  return list;
}

int tensors_len (tensor * list)
{
  if (!list) return 0;
  int nt = 0;
  {tensor*_i=(tensor*)( list);if(_i)for(tensor t=*_i;(&t)->x.x.i>=0;t=*++_i){ nt++;}}
  return nt;
}

tensor * tensors_append (tensor * list, tensor t)
{
  int len = tensors_len (list);
  list = (tensor *) prealloc (list, (len + 2)*sizeof(tensor),__func__,__FILE__,0);
  list[len] = t;
  list[len + 1] = (tensor){{{-1}}};
  return list;
}

tensor * tensors_from_vectors (vector * v)
{
  tensor * list = NULL;
  while (v->x.i >= 0) {
    tensor t;
     {
      if (!(v->x.i >= 0)) qassert ("/home/jacqhugo/basilisk/src/common.h", 0, "v->x.i >= 0");
      t.x = *v++;
    } 

{
      if (!(v->y.i >= 0)) qassert ("/home/jacqhugo/basilisk/src/common.h", 0, "v->x.i >= 0");
      t.y = *v++;
    }
    list = tensors_append (list, t);
  }
  return list;
}

static inline bool is_vertex_scalar (scalar s)
{
  
    if (_attribute[s.i].d.x != -1)
      return false;    

if (_attribute[s.i].d.y != -1)
      return false;
  return true;
}

scalar * all = NULL;
scalar * baseblock = NULL;



scalar (* init_scalar) (scalar, const char *);
scalar (* init_vertex_scalar) (scalar, const char *);
vector (* init_vector) (vector, const char *);
vector (* init_face_vector) (vector, const char *);
tensor (* init_tensor) (tensor, const char *);
void (* scalar_clone) (scalar, scalar);

typedef struct {
  clock_t c;
  struct timeval tv;
  double tm;
} timer;

timer timer_start (void)
{
  timer t;
  t.c = clock();
  gettimeofday (&t.tv, NULL);



  return t;
}

double timer_elapsed (timer t)
{
  struct timeval tvend;
  gettimeofday (&tvend, NULL);
  return ((tvend.tv_sec - t.tv.tv_sec) +
   (tvend.tv_usec - t.tv.tv_usec)/1e6);
}



const vector zerof = {{_NVARMAX+3},{_NVARMAX+4}};
const vector unityf = {{_NVARMAX+5},{_NVARMAX+6}};
const scalar unity = {_NVARMAX+7};
const scalar zeroc = {_NVARMAX+8};



        vector fm = {{_NVARMAX+9},{_NVARMAX+10}};
        scalar cm = {_NVARMAX+11};

void matrix_inverse3 (double m[3][3])
{
  double det = (m[0][0]*(m[1][1]*m[2][2] - m[2][1]*m[1][2]) -
  m[0][1]*(m[1][0]*m[2][2] - m[2][0]*m[1][2]) +
  m[0][2]*(m[1][0]*m[2][1] - m[2][0]*m[1][1]));
  if (!(det)) qassert ("/home/jacqhugo/basilisk/src/common.h", 0, "det");
  double m00 = m[0][0];
  m[0][0] = (m[1][1]*m[2][2] - m[1][2]*m[2][1])/det;
  double m01 = m[0][1];
  m[0][1] = (m[2][1]*m[0][2] - m[0][1]*m[2][2])/det;
  double m02 = m[0][2];
  m[0][2] = (m01*m[1][2] - m[1][1]*m[0][2])/det;
  double m10 = m[1][0];
  m[1][0] = (m[1][2]*m[2][0] - m[1][0]*m[2][2])/det;
  double m11 = m[1][1];
  m[1][1] = (m00*m[2][2] - m[2][0]*m02)/det;
  m[1][2] = (m10*m02 - m00*m[1][2])/det;
  double m20 = m[2][0];
  m[2][0] = (m10*m[2][1] - m[2][0]*m11)/det;
  m[2][1] = (m20*m01 - m00*m[2][1])/det;
  m[2][2] = (m00*m11 - m01*m10)/det;
}

double smatrix_inverse (const int n, double m[n][n], double pivmin)
{
  int indxc[n], indxr[n], ipiv[n];
  int i, icol = 0, irow = 0, j, k, l, ll;
  double big, dum, pivinv, minpiv = 1e30f;

  for (j = 0; j < n; j++)
    ipiv[j] = -1;

  for (i = 0; i < n; i++) {
    big = 0.0;
    for (j = 0; j < n; j++)
      if (ipiv[j] != 0)
 for (k = 0; k < n; k++) {
   if (ipiv[k] == -1) {
     if (fabs (m[j][k]) >= big) {
       big = fabs (m[j][k]);
       irow = j;
       icol = k;
     }
   }
 }
    ipiv[icol]++;
    if (irow != icol)
      for (l = 0; l < n; l++)
 do { double _tmp_ = m[irow][l]; m[irow][l] = m[icol][l]; m[icol][l] = _tmp_; } while(false);
    indxr[i] = irow;
    indxc[i] = icol;
    if (fabs (m[icol][icol]) < minpiv)
      minpiv = fabs (m[icol][icol]);
    if (minpiv < pivmin)
      break;
    pivinv = 1.0/m[icol][icol];
    m[icol][icol] = 1.0;
    for (l = 0; l < n; l++) m[icol][l] *= pivinv;
    for (ll = 0; ll < n; ll++)
      if (ll != icol) {
 dum = m[ll][icol];
 m[ll][icol] = 0.0;
 for (l = 0; l < n; l++)
   m[ll][l] -= m[icol][l]*dum;
      }
  }
  if (minpiv >= pivmin)
    for (l = n - 1; l >= 0; l--) {
      if (indxr[l] != indxc[l])
        for (k = 0; k < n; k++)
          do { double _tmp_ = m[k][indxr[l]]; m[k][indxr[l]] = m[k][indxc[l]]; m[k][indxc[l]] = _tmp_; } while(false);
    }
  return minpiv < pivmin ? 0. : minpiv;
}

void * matrix_new (int n, int p, size_t size)
{
  void ** m = ((void * *) pmalloc ((n)*sizeof(void *),__func__,__FILE__,0));
  char * a = ((char *) pmalloc ((n*p*size)*sizeof(char),__func__,__FILE__,0));
  for (int i = 0; i < n; i++)
    m[i] = a + i*p*size;
  return m;
}

double matrix_inverse (double ** m, int n, double pivmin)
{
  return smatrix_inverse (n, (double (*)[n])m[0], pivmin);
}

void matrix_free (void * m)
{
  pfree (((void **) m)[0],__func__,__FILE__,0);
  pfree (m,__func__,__FILE__,0);
}



typedef void (* free_solver_func) (void);

static Array * free_solver_funcs = NULL;

void free_solver_func_add (free_solver_func func)
{
  if (!free_solver_funcs)
    free_solver_funcs = array_new();
  array_append (free_solver_funcs, &func, sizeof(free_solver_func));
}



static char * display_defaults = NULL;

static void free_display_defaults() {
  pfree (display_defaults,__func__,__FILE__,0);
}

void display (const char * commands, bool overwrite)
{
  if (display_defaults == NULL)
    free_solver_func_add (free_display_defaults);
  if (overwrite) {
    pfree (display_defaults,__func__,__FILE__,0);
    display_defaults = pmalloc (strlen(commands) + 2,__func__,__FILE__,0);
    strcpy (display_defaults, "@");
    strcat (display_defaults, commands);
  }
  else {
    if (!display_defaults)
      display_defaults = pstrdup ("@",__func__,__FILE__,0);
    display_defaults =
      prealloc (display_defaults,
        strlen(display_defaults) + strlen(commands) + 1,__func__,__FILE__,0);
    strcat (display_defaults, commands);
  }
}



typedef struct {
  double x;

  double y;




} _coord;



typedef struct {
  float r, g, b, a;
} vec4;

typedef struct {
  coord x, y, z;
} mat3;

OMP(omp declare reduction (+ : mat3 :
      omp_out.x.x += omp_in.x.x,
      omp_out.x.y += omp_in.x.y,
      omp_out.x.z += omp_in.x.z,
      omp_out.y.x += omp_in.y.x,
      omp_out.y.y += omp_in.y.y,
      omp_out.y.z += omp_in.y.z,
      omp_out.z.x += omp_in.z.x,
      omp_out.z.y += omp_in.z.y,
      omp_out.z.z += omp_in.z.z
      ))

typedef struct {
  uint32_t s;
} Adler32Hash;

static
inline void a32_hash_init (Adler32Hash * hash)
{
  hash->s = 0;
}

static
inline void a32_hash_add (Adler32Hash * hash, const void * data, size_t size)
{
  const uint8_t * buffer = (const uint8_t*) data;
  for (size_t n = 0; n < size; n++, buffer++)
    hash->s = *buffer + (hash->s << 6) + (hash->s << 16) - hash->s;
}

static
inline uint32_t a32_hash (const Adler32Hash * hash)
{
  return hash->s;
}











typedef double real;

int Dimensions_scale = 1;


typedef struct {
  Grid g;
  char * d;
  size_t * shift;
} Multigrid;

struct _Point {
  int i;

  int j;




  int level;



  struct { int x, y; } n;




  int l;
  #define _BLOCK_INDEX , point.l



};
static Point last_point;










int nl = 1;





int _layer = 0;


void macro_foreach_block() {
  for (_layer = 0; _layer < nl; _layer++)
    ;
  _layer = 0;
}






void macro_foreach_block_inner (Point p) {
  for (p.l = 0; p.l < nl; p.l++)
    ;
  p.l = 0;
}





void macro_foreach_blockf (scalar _f, Point p) {
  for (p.l = 0; p.l < _attribute[_f.i].block; p.l++)
    ;
  p.l = 0;
}





#undef _index
#define _index(a,m)\
  (a.i + (_layer + point.l + m < _attribute[a.i].block ?\
   _layer + point.l + m : 0))\




#undef val
#define val(a,k,p,m) data(k,p,m)[_index(a,m)]


#undef val
#define val(a,k,l,m) (((real *)((Multigrid *)grid)->d)[point.j + (l) +\
       (point.i + (k))*(((size_t)(1 << point.level)*((int *)&Dimensions)[1]) + 2*2) +\
       ((Multigrid *)grid)->shift[point.level] +\
       _index(a,m)*((Multigrid *)grid)->shift[depth() + 1]])\




#define allocated(k,l,m) (point.i+(k) >= 0 && point.i+(k) < ((size_t)(1 << point.level)*((int *)&Dimensions)[0]) + 2*2 &&\
         point.j+(l) >= 0 && point.j+(l) < ((size_t)(1 << point.level)*((int *)&Dimensions)[1]) + 2*2)\




#define allocated_child(k,l,m) (level < depth() &&\
         point.i > 0 && point.i <= ((size_t)(1 << point.level)*((int *)&Dimensions)[0]) + 2 &&\
         point.j > 0 && point.j <= ((size_t)(1 << point.level)*((int *)&Dimensions)[1]) + 2)\




#define depth() (grid->depth)

#define fine(a,k,l,m)\
(((real *)((Multigrid *)grid)->d)[2*point.j - 2 + (l) +\
   (2*point.i - 2 + (k))*(((size_t)(1 << point.level)*((int *)&Dimensions)[1])*2 + 2*2) +\
   ((Multigrid *)grid)->shift[point.level + 1] +\
   _index(a,m)*((Multigrid *)grid)->shift[depth() + 1]])\



#define coarse(a,k,l,m)\
(((real *)((Multigrid *)grid)->d)[(point.j + 2)/2 + (l) +\
   ((point.i + 2)/2 + (k))*(((size_t)(1 << point.level)*((int *)&Dimensions)[1])/2 + 2*2) +\
   ((Multigrid *)grid)->shift[point.level - 1] +\
   _index(a,m)*((Multigrid *)grid)->shift[depth() + 1]])\




void macro_POINT_VARIABLES (Point point) { 
  

;  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
}

void macro_foreach_level (int l, char flags, Reduce reductions) {
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = l;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++)




   ;
    }
  }
}

void macro_foreach (char flags, Reduce reductions) {
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)




     ;
      }
  }
}

#define is_active(cell) (true)
#define is_leaf(cell) (point.level == depth())
#define is_local(cell) (true)
#define leaf 2
#define refine_cell(...) do {\
  fprintf (stderr, "grid depths do not match. Aborting.\n");\
  if (!(0)) qassert ("/home/jacqhugo/basilisk/src/grid/multigrid.h", 0, "0");\
} while (0)\



#define tree ((Multigrid *)grid)



void macro_foreach_cell_root (Point root)
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};



    struct { int l, i, j, stage; } stack[20];




    int _s = -1;
    { _s++; stack[_s].l = root.level; stack[_s].i = root.i; stack[_s].j = root.j; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; point.j = stack[_s].j; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {

 ;

 if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; };
 }
 break;
      }



      case 1: { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 2; };
 { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; }; break;
      case 2: { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 3; };
 { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; }; break;
      case 3: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; }; break;

      }
    }
  }
}

void macro_foreach_cell()
{
  {



    Point root = {2,2,0};

{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};



    struct { int l, i, j, stage; } stack[20];




    int _s = -1;
    { _s++; stack[_s].l = root.level; stack[_s].i = root.i; stack[_s].j = root.j; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; point.j = stack[_s].j; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
      

{ 
  

;  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

;} 

if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; };
 }
 break;
      }



      case 1: { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 2; };
 { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; }; break;
      case 2: { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 3; };
 { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; }; break;
      case 3: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; }; break;

      }
    }
  }
}
  

}
}

void macro_foreach_cell_all() {
  {
    Point root = {0};
    for (root.i = 2*Period.x; root.i <= 2*(2 - Period.x); root.i++)

      for (root.j = 2*Period.y; root.j <= 2*(2 - Period.y); root.j++) 

{


{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};



    struct { int l, i, j, stage; } stack[20];




    int _s = -1;
    { _s++; stack[_s].l = root.level; stack[_s].i = root.i; stack[_s].j = root.j; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; point.j = stack[_s].j; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
     

{ 
  

;  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

;} 

if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; };
 }
 break;
      }



      case 1: { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 2; };
 { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; }; break;
      case 2: { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 3; };
 { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; }; break;
      case 3: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; }; break;

      }
    }
  }
}

}
  

}
}

void macro_foreach_cell_post_root (bool condition, Point root)
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};



    struct { int l, i, j, stage; } stack[20];




    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].j = root.j; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; point.j = stack[_s].j; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
 if (point.level == grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 8; };
 }
 else {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 1; };
   if (condition)
     { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; };
 }
 break;
      }







      case 1:
 { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 2; };
 if (condition)
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; };
 break;
      case 2:
 { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 3; };
 if (condition)
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; };
 break;
      case 3:
 { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 4; };
 if (condition)
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; };
 break;

      default:
 ;

      }
    }
  }
}

void macro_foreach_cell_post (bool condition)
{
  {



    Point root = {2,2,0};

{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};



    struct { int l, i, j, stage; } stack[20];




    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].j = root.j; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; point.j = stack[_s].j; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
 if (point.level == grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 8; };
 }
 else {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 1; };
   if (condition)
     { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; };
 }
 break;
      }







      case 1:
 { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 2; };
 if (condition)
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; };
 break;
      case 2:
 { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 3; };
 if (condition)
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; };
 break;
      case 3:
 { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 4; };
 if (condition)
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; };
 break;

      default:
      

{ 
  

;  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

;}      

}
    }
  }
}
  

}
}

void macro_foreach_cell_post_all (bool condition)
{
  {
    Point root = {0};
    for (root.i = 0; root.i <= 2*2; root.i++)

      for (root.j = 0; root.j <= 2*2; root.j++) 

{


{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};



    struct { int l, i, j, stage; } stack[20];




    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].j = root.j; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; point.j = stack[_s].j; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
 if (point.level == grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 8; };
 }
 else {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 1; };
   if (condition)
     { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; };
 }
 break;
      }







      case 1:
 { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 2; };
 if (condition)
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; };
 break;
      case 2:
 { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 3; };
 if (condition)
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; };
 break;
      case 3:
 { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 4; };
 if (condition)
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; };
 break;

      default:
     

{ 
  

;  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

;}      

}
    }
  }
}

}
  

}
}

void macro_foreach_leaf()
{

{
  {



    Point root = {2,2,0};

{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};



    struct { int l, i, j, stage; } stack[20];




    int _s = -1;
    { _s++; stack[_s].l = root.level; stack[_s].i = root.i; stack[_s].j = root.j; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; point.j = stack[_s].j; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
    

{ 
  

;  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

if (is_leaf (cell)) {
      if (is_active(cell) && is_local(cell))
 ;
      continue;
    }} 

if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; };
 }
 break;
      }



      case 1: { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 2; };
 { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; }; break;
      case 2: { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 3; };
 { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; }; break;
      case 3: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; }; break;

      }
    }
  }
}
  

}
}


}

void macro_foreach_cell_restore (ivec d, int rootlevel)
{
  if (!d.x) d.x = 1;
  if (!d.y) d.y = 1;
  for (int ox = 0; ox < d.x; ox++)
    for (int oy = 0; oy < d.y; oy++) {
      Point root = {2 + ox, 2 + oy, rootlevel};

{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};



    struct { int l, i, j, stage; } stack[20];




    int _s = -1;
    { _s++; stack[_s].l = root.level; stack[_s].i = root.i; stack[_s].j = root.j; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; point.j = stack[_s].j; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
 

{ 
  

;  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

;} 

if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; };
 }
 break;
      }



      case 1: { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 2; };
 { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; }; break;
      case 2: { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 3; };
 { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; }; break;
      case 3: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; }; break;

      }
    }
  }
}
    

}
}


void macro_foreach_face_generic (char flags, Reduce reductions,
        const char * order)
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)




     ;
      }
  }
}

#define is_coarse() (point.level < depth())

void macro_is_face_x (Point p) {
  if (p.j < p.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);
    ;
  }
}

void macro_is_face_y (Point p) {
  if (p.i < p.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);
    ;
  }
}

void macro_foreach_child (Point point)
{
  {
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
  
 

;  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
 

;
      }
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }
}

#if TRASH
# undef trash
# define trash(list) reset(list, undefined)
#endif




void macro_foreach_neighbor (int _s,
    Point point) {
  {
    const int _nn = _s;
    const int _i = point.i, _j = point.j;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;
      for (int _l = - _nn; _l <= _nn; _l++) {
 point.j = _j + _l; 
  
 

;  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2; 

;
      }
    }
    point.i = _i; point.j = _j;
  }
}


void reset (void * alist, double val)
{
  scalar * list = (scalar *) alist;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!is_constant(s))
      for (int b = 0; b < _attribute[s.i].block; b++) {
 real * data = (real *) ((Multigrid *)grid)->d;
 data += (s.i + b)*((Multigrid *)grid)->shift[depth() + 1];
 for (size_t i = 0; i < ((Multigrid *)grid)->shift[depth() + 1]; i++, data++)
   *data = val;
      }}}
}

void macro_foreach_boundary_dir (int l, int d, Reduce reductions)
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = l < 0 ? depth() : l;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int * _i = &point.j, _n = point.n.y;
    if (d == left) {
      point.i = 2;
      ig = -1;
    }
    else if (d == right) {
      point.i = point.n.x + 2 - 1;
      ig = 1;
    }
    else if (d == bottom) {
      point.j = 2;
      _i = &point.i, _n = point.n.x;
      jg = -1;
    }
    else if (d == top) {
      point.j = point.n.y + 2 - 1;
      _i = &point.i, _n = point.n.x;
      jg = 1;
    }
    int _l;
    OMP(omp for schedule(static))
      for (_l = 0; _l < _n + 2*2; _l++) {
 *_i = _l;
 ;
      }
  }
}

#define neighbor(o,p,q)\
  ((Point){point.i+o, point.j+p, point.level, point.n _BLOCK_INDEX})\



#define is_boundary(point) (point.i < 2 || point.i >= point.n.x + 2 ||\
    point.j < 2 || point.j >= point.n.y + 2)\




extern double (* default_scalar_bc[]) (Point, Point, scalar, bool *);
static double periodic_bc (Point point, Point neighbor, scalar s, bool * data);

void macro_foreach_boundary (int b, Reduce reductions)
{
  if (default_scalar_bc[b] != periodic_bc) 

{


{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = (

depth()

) < 0 ? depth() : (

depth()

);
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int * _i = &point.j, _n = point.n.y;
    if (b == left) {
      point.i = 2;
      ig = -1;
    }
    else if (b == right) {
      point.i = point.n.x + 2 - 1;
      ig = 1;
    }
    else if (b == bottom) {
      point.j = 2;
      _i = &point.i, _n = point.n.x;
      jg = -1;
    }
    else if (b == top) {
      point.j = point.n.y + 2 - 1;
      _i = &point.i, _n = point.n.x;
      jg = 1;
    }
    int _l;
    OMP(omp for schedule(static))
      for (_l = 0; _l < _n + 2*2; _l++) {
 *_i = _l;
      

{  

;  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

if (!is_boundary(point))
 ;}      

}
  }
}

}


}

#define neighborp(k,l,o) neighbor(k,l,o)

static void box_boundary_level (const Boundary * b, scalar * scalars, int l)
{
  disable_fpe (FE_DIVBYZERO|FE_INVALID);
  for (int d = 0; d < 2*2; d++)
    if (default_scalar_bc[d] == periodic_bc)
      {scalar*_i=(scalar*)( scalars);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
 if (!is_constant(s) && _attribute[s.i].block > 0) {
   if (is_vertex_scalar (s))
     _attribute[s.i].boundary[d] = _attribute[s.i].boundary_homogeneous[d] = NULL;
   else if (_attribute[s.i].face && _attribute[s.i].v.x.i >= 0) {
     vector v = _attribute[s.i].v;
     _attribute[v.x.i].boundary[d] = _attribute[v.x.i].boundary_homogeneous[d] = NULL;
   }
 }}}
  for (int bghost = 1; bghost <= 2; bghost++)
    for (int d = 0; d < 2*2; d++) {

      scalar * list = NULL, * listb = NULL;
      {scalar*_i=(scalar*)( scalars);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
 if (!is_constant(s) && _attribute[s.i].block > 0) {
   scalar sb = s;

   if (_attribute[s.i].v.x.i >= 0) {

     int j = 0;
     while ((&_attribute[s.i].v.x)[j].i != s.i) j++;
     sb = (&_attribute[s.i].v.x)[(j - d/2 + 2) % 2];
   }

   if (sb.i >= 0 && _attribute[sb.i].boundary[d] && _attribute[sb.i].boundary[d] != periodic_bc) {
     list = list_append (list, s);
     listb = list_append (listb, sb);
   }
 }}}

      if (list) {

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = l < 0 ? depth() : l;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int * _i = &point.j, _n = point.n.y;
    if (d == left) {
      point.i = 2;
      ig = -1;
    }
    else if (d == right) {
      point.i = point.n.x + 2 - 1;
      ig = 1;
    }
    else if (d == bottom) {
      point.j = 2;
      _i = &point.i, _n = point.n.x;
      jg = -1;
    }
    else if (d == top) {
      point.j = point.n.y + 2 - 1;
      _i = &point.i, _n = point.n.x;
      jg = 1;
    }
    int _l;
    OMP(omp for schedule(static))
      for (_l = 0; _l < _n + 2*2; _l++) {
 *_i = _l; 

{  

;  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
   scalar s, sb;
   {scalar*_i0=listb;scalar*_i1= list;if(_i0)for(sb=*_i0,s=*_i1;_i0->i>= 0;sb=*++_i0,s=*++_i1){ {
     if ((_attribute[s.i].face && sb.i == _attribute[s.i].v.x.i) || is_vertex_scalar (s)) {

       if (bghost == 1)   

{
  for (point.l = 0; point.l < nl; point.l++)
    

val(s,(ig + 1)/2,(jg + 1)/2,(kg + 1)/2) =
    _attribute[sb.i].boundary[d] (point, neighborp(ig,jg,kg), s, NULL);  

point.l = 0;
}
     

}
     else        

{
  for (point.l = 0; point.l < nl; point.l++)
  

val(s,bghost*ig,bghost*jg,bghost*kg) =
  _attribute[sb.i].boundary[d] (neighborp((1 - bghost)*ig,
       (1 - bghost)*jg,
       (1 - bghost)*kg),
    neighborp(bghost*ig,bghost*jg,bghost*kg),
    s, NULL);  

point.l = 0;
}
   

}}}
 }}      

}
  }
}
 

pfree (list,__func__,__FILE__,0);
 pfree (listb,__func__,__FILE__,0);
      }
    }
  enable_fpe (FE_DIVBYZERO|FE_INVALID);
}

#define VT _attribute[s.i].v.y


static void periodic_boundary_level_x (const Boundary * b, scalar * list, int l)
{
  scalar * list1 = NULL;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!is_constant(s) && _attribute[s.i].block > 0) {
      if (_attribute[s.i].face) {
 scalar vt = VT;
 if (vt.i >= 0 && _attribute[vt.i].boundary[right] == periodic_bc)
   list1 = list_add (list1, s);
      }
      else if (_attribute[s.i].boundary[right] == periodic_bc)
 list1 = list_add (list1, s);
    }}}
  if (!list1)
    return;

  if (l == 0) { 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = 0;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++)
      

{  

;  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{scalar*_i=(scalar*)( list1);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
 for (int b = 0; b < _attribute[s.i].block; b++) {
   scalar sb = {s.i + b};
   real v = val(sb,0,0,0);   

{
    const int _nn = 2;
    const int _i = point.i, _j = point.j;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;
      for (int _l = - _nn; _l <= _nn; _l++) {
 point.j = _j + _l; 
  
 

;  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
     

val(sb,0,0,0) = v;      

}
    }
    point.i = _i; point.j = _j;
  }
 

}}}}    

}
  }
}
    

pfree (list1,__func__,__FILE__,0);
    return;
  }

  OMP_PARALLEL() {
    Point point = {0};
    point.level = l < 0 ? depth() : l;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;

    int j;
    OMP(omp for schedule(static))
      for (j = 0; j < point.n.y + 2*2; j++) {
 for (int i = 0; i < 2; i++)
   {scalar*_i=(scalar*)( list1);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
     for (int b = 0; b < _attribute[s.i].block; b++) {
       scalar sb = {s.i + b};
       val(sb,i,j,0) = val(sb,i + point.n.x,j,0);
     }}}
 for (int i = point.n.x + 2; i < point.n.x + 2*2; i++)
   {scalar*_i=(scalar*)( list1);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
     for (int b = 0; b < _attribute[s.i].block; b++) {
       scalar sb = {s.i + b};
       val(sb,i,j,0) = val(sb,i - point.n.x,j,0);
     }}}
      }

  }
  pfree (list1,__func__,__FILE__,0);
}

static void periodic_boundary_level_y (const Boundary * b, scalar * list, int l)
{
  scalar * list1 = NULL;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!is_constant(s) && _attribute[s.i].block > 0) {
      if (_attribute[s.i].face) {
 scalar vt = VT;
 if (vt.i >= 0 && _attribute[vt.i].boundary[top] == periodic_bc)
   list1 = list_add (list1, s);
      }
      else if (_attribute[s.i].boundary[top] == periodic_bc)
 list1 = list_add (list1, s);
    }}}
  if (!list1)
    return;

  if (l == 0) { 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = 0;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++)
      

{  

;  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{scalar*_i=(scalar*)( list1);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
 for (int b = 0; b < _attribute[s.i].block; b++) {
   scalar sb = {s.i + b};
   real v = val(sb,0,0,0);   

{
    const int _nn = 2;
    const int _i = point.i, _j = point.j;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;
      for (int _l = - _nn; _l <= _nn; _l++) {
 point.j = _j + _l; 
  
 

;  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
     

val(sb,0,0,0) = v;      

}
    }
    point.i = _i; point.j = _j;
  }
 

}}}}    

}
  }
}
    

pfree (list1,__func__,__FILE__,0);
    return;
  }

  OMP_PARALLEL() {
    Point point = {0};
    point.level = l < 0 ? depth() : l;
    point.n.y = (1 << point.level)*Dimensions.y, point.n.x = (1 << point.level)*Dimensions.x;

    int j;
    OMP(omp for schedule(static))
      for (j = 0; j < point.n.x + 2*2; j++) {
 for (int i = 0; i < 2; i++)
   {scalar*_i=(scalar*)( list1);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
     for (int b = 0; b < _attribute[s.i].block; b++) {
       scalar sb = {s.i + b};
       val(sb,j,i,0) = val(sb,j,i + point.n.y,0);
     }}}
 for (int i = point.n.y + 2; i < point.n.y + 2*2; i++)
   {scalar*_i=(scalar*)( list1);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
     for (int b = 0; b < _attribute[s.i].block; b++) {
       scalar sb = {s.i + b};
       val(sb,j,i,0) = val(sb,j,i - point.n.y,0);
     }}}
      }

  }
  pfree (list1,__func__,__FILE__,0);
}

#undef VT





void free_grid (void)
{
  if (!grid)
    return;
  free_boundaries();
  Multigrid * m = ((Multigrid *)grid);
  pfree (m->d,__func__,__FILE__,0);
  pfree (m->shift,__func__,__FILE__,0);
  pfree (m,__func__,__FILE__,0);
  grid = NULL;
}

int log_base2 (int n) {
  int m = n, r = 0;
  while (m > 1)
    m /= 2, r++;
  return (1 << r) < n ? r + 1 : r;
}

void init_grid (int n)
{
  free_grid();
  Multigrid * m = ((Multigrid *) pmalloc ((1)*sizeof(Multigrid),__func__,__FILE__,0));
  grid = (Grid *) m;
  grid->depth = grid->maxdepth = log_base2(n/Dimensions.x);
  N = (1 << grid->depth)*Dimensions.x;


  grid->n = 1 << 2*depth();
  
    grid->n *= Dimensions.x;    grid->n *= Dimensions.y;
  grid->tn = grid->n;


  Boundary * b = ((Boundary *) pcalloc (1, sizeof(Boundary),__func__,__FILE__,0));
  b->level = box_boundary_level;
  add_boundary (b);





   {
    Boundary * b = ((Boundary *) pcalloc (1, sizeof(Boundary),__func__,__FILE__,0));
    b->level = periodic_boundary_level_x;
    add_boundary (b);
  } 

{
    Boundary * b = ((Boundary *) pcalloc (1, sizeof(Boundary),__func__,__FILE__,0));
    b->level = periodic_boundary_level_y;
    add_boundary (b);
  }


  m->shift = ((size_t *) pmalloc ((depth() + 2)*sizeof(size_t),__func__,__FILE__,0));
  size_t totalsize = 0;
  for (int l = 0; l <= depth() + 1; l++) {
    m->shift[l] = totalsize;
    struct _Point point = { .level = l };
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    size_t size = 1;
    
      size *= point.n.x + 2*2;      size *= point.n.y + 2*2;
    totalsize += size;
  }
  m->d = (char *) pmalloc(m->shift[depth() + 1]*datasize,__func__,__FILE__,0);
  reset (all, 0.);
}

void realloc_scalar (int size)
{
  Multigrid * p = ((Multigrid *)grid);
  datasize += size;
  p->d = (char *) prealloc (p->d, (p->shift[depth() + 1]*datasize)*sizeof(char),__func__,__FILE__,0);
}

Point locate (double xp, double yp, double zp)
{
  Point point = {0};
  point.level = depth();
  point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
  point.level = -1;

  point.i = (xp - X0)/L0*point.n.x + 2;
  if (point.i < 2 || point.i >= point.n.x + 2)
    return point;

  point.j = (yp - Y0)/L0*point.n.x + 2;
  if (point.j < 2 || point.j >= point.n.y + 2)
    return point;







  point.level = depth();
  return point;
}










void macro3_VARIABLES (Point point, int _ig, int _jg, int _kg)
{
  double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((_ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((_jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
}





typedef struct _Event Event;
typedef int (* Expr) (int *, double *, Event *);

struct _Event {
  int last, nexpr;
  int (* action) (const int, const double, Event *);
  Expr expr[3];
  int * arrayi;
  double * arrayt;
  char * file;
  int line;
  char * name;
  double t;
  int i, a;
  void * data;
  Event * next;
};

static Event * Events = NULL;

int iter = 0, inext = 0;
double t = 0, tnext = 0;
void init_events (void);
void event_register (Event event);
static void _init_solver (void);





static int END_EVENT = 1234567890;
static double TEND_EVENT = 1234567890;
static double TEPS = 1e-9;

static void event_error (Event * ev, const char * s)
{
  fprintf (ferr, "%s:%d: error: %s\n", ev->file, ev->line, s);
  exit (1);
}

static void init_event (Event * ev)
{
  if (ev->arrayi || ev->arrayt) {
    ev->i = -1; ev->t = - TEND_EVENT;
    if (ev->arrayi)
      ev->i = ev->arrayi[0];
    else
      ev->t = ev->arrayt[0];
    ev->a = 1;
    ev->expr[1] = NULL;
  }
  else {
    if (ev->nexpr > 0) {
      Expr init = NULL, cond = NULL, inc = NULL;
      for (int j = 0; j < ev->nexpr; j++) {
 int i = -123456; double t = - TEND_EVENT;
 (* ev->expr[j]) (&i, &t, ev);
 if (i == -123456 && t == - TEND_EVENT) {

   if (cond)
     event_error (ev, "events can only use a single condition");
   cond = ev->expr[j];
 }
 else {

   int i1 = i; double t1 = t;
   (* ev->expr[j]) (&i1, &t1, ev);
   if (i1 == i && t1 == t) {


     if (init)
       event_error (ev, "events can only use a single initialisation");
     init = ev->expr[j];
   }
   else {

     if (inc)
       event_error (ev, "events can only use a single increment");
     inc = ev->expr[j];
   }
 }
      }
      ev->expr[0] = init;
      ev->expr[1] = cond;
      ev->expr[2] = inc;
      ev->nexpr = 0;
    }
    ev->i = -1; ev->t = - TEND_EVENT;
    if (ev->expr[0]) {
      (* ev->expr[0]) (&ev->i, &ev->t, ev);
      if (ev->i == END_EVENT || ev->t == TEND_EVENT) {
 ev->i = END_EVENT; ev->t = - TEND_EVENT;
      }
    }
    else if (ev->expr[2]) {
      (* ev->expr[2]) (&ev->i, &ev->t, ev);
      if (ev->i != -1)
 ev->i = 0;
      if (ev->t != - TEND_EVENT)
 ev->t = 0;
    }
  }
}

enum { event_done, event_alive, event_stop };

static int event_finished (Event * ev)
{
  ev->i = -1; ev->t = - TEND_EVENT;
  return event_done;
}

void event_register (Event event) {
  if (!(Events)) qassert ("/home/jacqhugo/basilisk/src/grid/events.h", 0, "Events");
  if (!(!event.last)) qassert ("/home/jacqhugo/basilisk/src/grid/events.h", 0, "!event.last");
  int n = 0, parent = -1;
  for (Event * ev = Events; !ev->last; ev++) {
    if (!strcmp (event.name, ev->name)) {
      if (!(parent < 0)) qassert ("/home/jacqhugo/basilisk/src/grid/events.h", 0, "parent < 0");
      parent = n;
    }
    n++;
  }
  if (parent < 0) {
    Events = (Event *) prealloc (Events, (n + 2)*sizeof(Event),__func__,__FILE__,0);
    Events[n] = event;
    Events[n].next = NULL;
    Events[n + 1].last = true;
    init_event (&Events[n]);
  }
  else {
    Event * ev = ((Event *) pcalloc (1, sizeof(Event),__func__,__FILE__,0));
    *ev = Events[parent];
    Events[parent] = event;
    Events[parent].next = ev;
    init_event (&Events[parent]);
  }
}

static int event_cond (Event * ev, int i, double t)
{
  if (!ev->expr[1])
    return true;
  return (* ev->expr[1]) (&i, &t, ev);
}

static bool overload_event() { return true; }

static int event_do (Event * ev, bool action)
{
  if ((iter > ev->i && t > ev->t) || !event_cond (ev, iter, t))
    return event_finished (ev);
  if (!overload_event() || iter == ev->i || fabs (t - ev->t) <= TEPS*t) {
    if (action) {
      bool finished = false;
      for (Event * e = ev; e; e = e->next) {



 if ((* e->action) (iter, t, e))
   finished = true;
      }
      if (finished) {
 event_finished (ev);
 return event_stop;
      }
    }
    if (ev->arrayi) {
      ev->i = ev->arrayi[ev->a++];
      if (ev->i < 0)
 return event_finished (ev);
    }
    if (ev->arrayt) {
      ev->t = ev->arrayt[ev->a++];
      if (ev->t < 0)
 return event_finished (ev);
    }
    else if (ev->expr[2]) {
      int i0 = ev->i;
      (* ev->expr[2]) (&ev->i, &ev->t, ev);
      if (i0 == -1 && ev->i != i0)
 ev->i += iter + 1;
      if (!event_cond (ev, iter + 1, ev->t))
 return event_finished (ev);
    }
    else if (ev->expr[0] && !ev->expr[1])
      return event_finished (ev);
  }
  return event_alive;
}

static void end_event_do (bool action)
{




  for (Event * ev = Events; !ev->last; ev++)
    if (ev->i == END_EVENT && action)
      for (Event * e = ev; e; e = e->next) {



 e->action (iter, t, e);
      }
}

int events (bool action)
{





  if (iter == 0)
    for (Event * ev = Events; !ev->last; ev++)
      init_event (ev);

  int cond = 0, cond1 = 0;
  inext = END_EVENT; tnext = 1e30f;
  for (Event * ev = Events; !ev->last && !cond; ev++)
    if (ev->i != END_EVENT &&
 (ev->expr[1] || (ev->expr[0] && !ev->expr[1] && !ev->expr[2]) || ev->arrayi || ev->arrayt))
      cond = 1;
  for (Event * ev = Events; !ev->last; ev++) {
    int status = event_do (ev, action);
    if (status == event_stop) {
      end_event_do (action);
      return 0;
    }
    if (status == event_alive && ev->i != END_EVENT &&
 (ev->expr[1] || (ev->expr[0] && !ev->expr[1] && !ev->expr[2]) || ev->arrayi || ev->arrayt))
      cond1 = 1;
    if (ev->t > t && ev->t < tnext)
      tnext = ev->t;
    if (ev->i > iter && ev->i < inext)
      inext = ev->i;
  }
  if (overload_event() && (!cond || cond1) && (tnext != 1e30f || inext != END_EVENT)) {
    inext = iter + 1;
    return 1;
  }
  end_event_do (action);
  return 0;
}

void event (const char * name)
{
  for (Event * ev = Events; !ev->last; ev++)
    if (!strcmp (ev->name, name))
      for (Event * e = ev; e; e = e->next) {



 (* e->action) (0, 0, e);
      }
}

double dtnext (double dt)
{
  if (tnext != 1e30f && tnext > t) {
    if (!(dt > 0.)) qassert ("/home/jacqhugo/basilisk/src/grid/events.h", 0, "dt > 0.");
    unsigned int n = (tnext - t)/dt;
    if (!(n < INT_MAX)) qassert ("/home/jacqhugo/basilisk/src/grid/events.h", 0, "n < INT_MAX");
    if (n == 0)
      dt = tnext - t;
    else {
      double dt1 = (tnext - t)/n;
      if (dt1 > dt*(1. + TEPS))
 dt = (tnext - t)/(n + 1);
      else if (dt1 < dt)
 dt = dt1;
      tnext = t + dt;
    }
  }
  else
    tnext = t + dt;
  return dt;
}

void init_solver()
{
  Events = pmalloc (sizeof (Event),__func__,__FILE__,0);
  Events[0].last = 1;
  _attribute = pcalloc (datasize/sizeof(real), sizeof (_Attributes),__func__,__FILE__,0);
  int n = datasize/sizeof(real);
  all = (scalar *) pmalloc (sizeof (scalar)*(n + 1),__func__,__FILE__,0);
  baseblock = (scalar *) pmalloc (sizeof (scalar)*(n + 1),__func__,__FILE__,0);
  for (int i = 0; i < n; i++)
    baseblock[i].i = all[i].i = i;
  baseblock[n].i = all[n].i = -1;

}


void (* debug) (Point);

#define _val_constant(a,k,l,m) ((const double) _constant[a.i -_NVARMAX])
#define val_diagonal(a,k,l,m) ((k) == 0 && (l) == 0 && (m) == 0)





#include <signal.h>
#include <unistd.h>

static int gdb()
{
  if (last_point.level >= 0) {
    debug (last_point);
    fputc ('\n', ferr);
    fflush (ferr);
  }
  char command[80];
  sprintf (command, "exec xterm -e 'gdb -p %d' & xterm -e 'gnuplot plot -'",
    getpid());
  return system (command);
}

static void caught_abort (int sig)
{
  fprintf (ferr, "Caught signal %d (Aborted)\n", sig);
  gdb();
}

static void caught_fpe (int sig)
{
  fprintf (ferr, "Caught signal %d (Floating Point Exception)\n", sig);
  gdb();
  exit (1);
}

static void caught_segfault (int sig)
{
  fprintf (ferr, "Caught signal %d (Segmentation Fault)\n", sig);
  gdb();
  exit (2);
}

void catch_fpe (void)
{
  struct sigaction act;
  act.sa_handler = caught_fpe;
  sigemptyset (&act.sa_mask);
  act.sa_flags = 0;
  last_point.level = -1;
  sigaction (8, &act, NULL);
  act.sa_handler = caught_segfault;
  sigaction (11, &act, NULL);
  act.sa_handler = caught_abort;
  act.sa_flags = SA_RESETHAND;
  sigaction (6, &act, NULL);
}




enum {
  s_centered = 1 << 0,
  s_face = 1 << 1,
  s_restriction = 1 << 2,

  s_input = 1 << 3,
  s_output = 1 << 4,
  s_nowarning = 1 << 5
} StencilFlags;







static void set_dirty_stencil (scalar s)
{
  _attribute[s.i].stencil.bc = 0;
}

typedef struct _External External;

struct _External {
  char * name;
  void * pointer;
  int type;
  int nd;
  char reduct;
  char global;
  char constant;
  void * data;
  scalar s;
  External * externals, * next;
  int used;
};

typedef struct {
  const char * fname;
  int line;
  int first;
  int face;
  bool vertex;
  int parallel;
  scalar * listc;
  vectorl listf;
  scalar * dirty;
  void * data;
} ForeachData;







static inline bool scalar_is_dirty (scalar s)
{
  if (!(_attribute[s.i].stencil.bc & s_centered))
    return true;
  scalar * depends = _attribute[s.i].depends;
  {scalar*_i=(scalar*)( depends);if(_i)for(scalar d=*_i;(&d)->i>=0;d=*++_i){
    if (!(_attribute[d.i].stencil.bc & s_centered))
      return true;}}
  return false;
}




static inline bool scalar_depends_from (scalar a, scalar b)
{
  scalar * depends = _attribute[a.i].depends;
  {scalar*_i=(scalar*)( depends);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (s.i == b.i)
      return true;}}
  return false;
}







void boundary_internal (scalar * list, const char * fname, int line);
void (* boundary_face) (vectorl);







void check_stencil (ForeachData * loop)
{
  loop->listf = (vectorl){NULL};




  {scalar*_i=(scalar*)( baseblock);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
    bool write = (_attribute[s.i].stencil.io & s_output), read = (_attribute[s.i].stencil.io & s_input);


    if (_layer == 0 || _attribute[s.i].block == 1)

    {





      if (read && scalar_is_dirty (s)) {





 if (_attribute[s.i].face) {
   if (_attribute[s.i].stencil.width > 0)
     loop->listc = list_append (loop->listc, s);
   else if (!write) {
     scalar sn = _attribute[s.i].v.x.i >= 0 ? _attribute[s.i].v.x : s;
     
       if (_attribute[s.i].v.x.i == s.i) {




  if (_attribute[sn.i].boundary[left] || _attribute[sn.i].boundary[right])
    loop->listc = list_append (loop->listc, s);
  else if (!(_attribute[s.i].stencil.bc & s_face))
    loop->listf.x = list_append (loop->listf.x, s);
       }       

if (_attribute[s.i].v.y.i == s.i) {




  if (_attribute[sn.i].boundary[bottom] || _attribute[sn.i].boundary[top])
    loop->listc = list_append (loop->listc, s);
  else if (!(_attribute[s.i].stencil.bc & s_face))
    loop->listf.y = list_append (loop->listf.y, s);
       }
   }
 }





 else if (_attribute[s.i].stencil.width > 0)
   loop->listc = list_append (loop->listc, s);
      }





      if (write) {
 if (2 > 1 && !loop->vertex && loop->first && !(_attribute[s.i].stencil.io & s_nowarning)) {
   bool vertex = true;
   
     if (_attribute[s.i].d.x != -1)
       vertex = false;     

if (_attribute[s.i].d.y != -1)
       vertex = false;
   if (vertex)
     fprintf (ferr,
       "%s:%d: warning: vertex scalar '%s' should be assigned with"
       " a foreach_vertex() loop\n",
       loop->fname, loop->line, _attribute[s.i].name);
 }
 if (_attribute[s.i].face) {
   if (loop->face == 0 && loop->first && !(_attribute[s.i].stencil.io & s_nowarning))
     fprintf (ferr,
       "%s:%d: warning: face vector '%s' should be assigned with"
       " a foreach_face() loop\n",
       loop->fname, loop->line, _attribute[s.i].name);
 }
 else if (loop->face) {
   if (_attribute[s.i].v.x.i < 0) {
     int d = 1, i = 0;
      {
       if (loop->face == d) {
  _attribute[s.i].face = 2, _attribute[s.i].v.x.i = s.i;
  _attribute[s.i].boundary[left] = _attribute[s.i].boundary[right] = NULL;





       }
       d *= 2, i++;
     } 

{
       if (loop->face == d) {
  _attribute[s.i].face = 2, _attribute[s.i].v.y.i = s.i;
  _attribute[s.i].boundary[bottom] = _attribute[s.i].boundary[top] = NULL;





       }
       d *= 2, i++;
     }
     if (!_attribute[s.i].face && loop->first && !(_attribute[s.i].stencil.io & s_nowarning))
       fprintf (ferr,
         "%s:%d: warning: scalar '%s' should be assigned with "
         "a foreach_face(x|y|z) loop\n",
         loop->fname, loop->line, _attribute[s.i].name);
   }
   else {
     char * name = NULL;
     if (_attribute[s.i].name) {
       name = pstrdup (_attribute[s.i].name,__func__,__FILE__,0);
       char * s = name + strlen(name) - 1;
       while (s != name && *s != '.') s--;
       if (s != name) *s = '\0';
     }
     struct { bool x, y, z; } input, output;
     vector v = _attribute[s.i].v;

     
       input.x = (_attribute[v.x.i].stencil.io & s_input), output.x = (_attribute[v.x.i].stencil.io & s_output);       input.y = (_attribute[v.y.i].stencil.io & s_input), output.y = (_attribute[v.y.i].stencil.io & s_output);

     init_face_vector (v, name);

      {
              if (input.x) _attribute[v.x.i].stencil.io |= s_input;
              else _attribute[v.x.i].stencil.io &= ~s_input;
              if (output.x) _attribute[v.x.i].stencil.io |= s_output;
              else _attribute[v.x.i].stencil.io &= ~s_output;
            } 

{
              if (input.y) _attribute[v.y.i].stencil.io |= s_input;
              else _attribute[v.y.i].stencil.io &= ~s_input;
              if (output.y) _attribute[v.y.i].stencil.io |= s_output;
              else _attribute[v.y.i].stencil.io &= ~s_output;
            }





     pfree (name,__func__,__FILE__,0);
   }
 }
 else if (loop->vertex) {
   bool vertex = true;
   
     if (_attribute[s.i].d.x != -1)
       vertex = false;     

if (_attribute[s.i].d.y != -1)
       vertex = false;
   if (!vertex) {
     char * name = NULL;
     if (_attribute[s.i].name) name = pstrdup (_attribute[s.i].name,__func__,__FILE__,0);
     init_vertex_scalar (s, name);
     
       _attribute[s.i].v.x.i = -1;       _attribute[s.i].v.y.i = -1;




     pfree (name,__func__,__FILE__,0);
   }
 }





        if (!list_lookup (loop->dirty, s))
          loop->dirty = list_append (loop->dirty, s);
 {scalar*_i=(scalar*)( baseblock);if(_i)for(scalar d=*_i;(&d)->i>=0;d=*++_i){
   if (scalar_depends_from (d, s) && !list_lookup (loop->dirty, d))
     loop->dirty = list_append (loop->dirty, d);}}
      }
    }
  }}}
}




void boundary_stencil (ForeachData * loop)
{
  bool flux = false;
  
    if (loop->listf.x)
      flux = true;    

if (loop->listf.y)
      flux = true;
  if (flux) {

    boundary_face (loop->listf);
    
      pfree (loop->listf.x,__func__,__FILE__,0), loop->listf.x = NULL;      pfree (loop->listf.y,__func__,__FILE__,0), loop->listf.y = NULL;
  }




  if (loop->listc) {






    boundary_internal (loop->listc, loop->fname, loop->line);
    pfree (loop->listc,__func__,__FILE__,0), loop->listc = NULL;
  }





  if (loop->dirty) {






    {scalar*_i=(scalar*)( loop->dirty);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      set_dirty_stencil (s);}}
    pfree (loop->dirty,__func__,__FILE__,0), loop->dirty = NULL;
  }
}

void macro_foreach_stencil (char flags, Reduce reductions)
{
  {
    static int _first = 1.;
    ForeachData _loop = {
      .fname = __FILE__, .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

    ;

    check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }
}

void macro_foreach_vertex_stencil (char flags, Reduce reductions) {  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/grid/stencils.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{
    _loop.vertex = true;
    ;
  }    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }







}

void macro_foreach_face_stencil (char flags, Reduce reductions, const char * order) {  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/grid/stencils.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    

;    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }


}

void macro_foreach_level_stencil (int l, char flags, Reduce reductions) {
  if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    ;
  }
}

void macro_foreach_coarse_level_stencil (int l, char flags, Reduce reductions) {  

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    





;  

}





}

void macro_foreach_level_or_leaf_stencil (int l, char flags, Reduce reductions) {  

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    

;  

}










}

void macro_foreach_point_stencil (double xp, double yp, double zp, char flags, Reduce reductions)
{  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/grid/stencils.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    

;    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }


}

void macro_foreach_region_stencil (coord p, coord box[2], coord n, char flags, Reduce reductions)
{  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/grid/stencils.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    

;    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }


}

void macro__stencil_is_face_x (ForeachData l) { l.face |= (1 << 0); ; }
void macro__stencil_is_face_y (ForeachData l) { l.face |= (1 << 1); ; }
void macro__stencil_is_face_z (ForeachData l) { l.face |= (1 << 2); ; }

void stencil_val (Point p, scalar s, int i, int j, int k,
    const char * file, int line, bool overflow);
void stencil_val_a (Point p, scalar s, int i, int j, int k, bool input,
      const char * file, int line);

#define _stencil_val(a,_i,_j,_k)\
  stencil_val (point, a, _i, _j, _k, __FILE__, 0, false)\



#define _stencil_val_o(a,_i,_j,_k)\
  stencil_val (point, a, _i, _j, _k, __FILE__, 0, true)\



#define _stencil_val_a(a,_i,_j,_k)\
  stencil_val_a (point, a, _i, _j, _k, false, __FILE__, 0)\



#define _stencil_val_r(a,_i,_j,_k)\
  stencil_val_a (point, a, _i, _j, _k, true, __FILE__, 0)\




#define _stencil_fine(a,_i,_j,_k) _stencil_val(a,_i,_j,_k)
#define _stencil_fine(a,_i,_j,_k) _stencil_val(a,_i,_j,_k)
#define _stencil_fine_a(a,_i,_j,_k) _stencil_val_a(a,_i,_j,_k)
#define _stencil_fine_r(a,_i,_j,_k) _stencil_val_r(a,_i,_j,_k)

#define _stencil_coarse(a,_i,_j,_k) _stencil_val(a,_i,_j,_k)
#define _stencil_coarse_a(a,_i,_j,_k) _stencil_val_a(a,_i,_j,_k)
#define _stencil_coarse_r(a,_i,_j,_k) _stencil_val_r(a,_i,_j,_k)

#define r_assign(x)
#define _assign(x)

#define _stencil_neighbor(i,j,k)
#define _stencil_child(i,j,k)
#define _stencil_aparent(i,j,k)
#define _stencil_aparent_a(i,j,k)
#define _stencil_aparent_r(i,j,k)

#define _stencil_allocated(i,j,k) true

#define _stencil_neighborp(i,j,k) neighborp(i,j,k)

int _stencil_nop;
#define _stencil_val_higher_dimension (_stencil_nop = 1)
#define _stencil__val_constant(a,_i,_j,_k) (_stencil_nop = 1)
#define _stencil_val_diagonal(a,_i,_j,_k) (_stencil_nop = 1)

typedef void _stencil_undefined;

#define o_stencil -3


void macro_foreach_point (double _x, double _y, double _z,
        char flags, Reduce reductions)
{
  {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    coord _p = { _x, _y, _z };
    Point point = locate (_p.x, _p.y, _p.z);
    if (point.level >= 0)
      ;
  }
}

void macro_foreach_region (coord p, coord box[2], coord n,
         char flags, Reduce reductions)
{
  {
    if (n.x < 1) n.x = 1;
    if (n.y < 1) n.y = 1;
    if (n.z < 1) n.z = 1;

    for (int _i = 0; _i < (int) n.x; _i++) {
      p.x = box[0].x + (box[1].x - box[0].x)/n.x*(_i + 0.5);
      for (int _j = 0; _j < (int) n.y; _j++) {
 p.y = box[0].y + (box[1].y - box[0].y)/n.y*(_j + 0.5);
 for (int _k = 0; _k < (int) n.z; _k++) {
   p.z = box[0].z + (box[1].z - box[0].z)/n.z*(_k + 0.5);
   Point point = locate (p.x, p.y, p.z);
   if (point.level >= 0) {
     int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
     ;
   }
 }
      }
    }
  }
}




static inline
double dirichlet (double expr, Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

return 2.*expr - val(s,0,0,0);
}

static inline
double dirichlet_homogeneous (double expr, Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

return - val(s,0,0,0);
}

static inline
double dirichlet_face (double expr)
{
  return expr;
}

static inline
double dirichlet_face_homogeneous (double expr)
{
  return 0.;
}

static inline
double neumann (double expr, Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

return Delta*expr + val(s,0,0,0);
}

static inline
double neumann_homogeneous (double expr, Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

return val(s,0,0,0);
}




static inline
double navier (double expr, double lambda, Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

return (Delta*expr + val(s,0,0,0)*(lambda - Delta/2.))/(lambda + Delta/2.);
}

static inline
double navier_homogeneous (double expr, double lambda, Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

return val(s,0,0,0)*(lambda - Delta/2.)/(lambda + Delta/2.);
}

static void init_block_scalar (scalar sb, const char * name, const char * ext,
          int n, int block)
{
  char bname[strlen(name) + strlen(ext) + 10];
  if (n == 0) {
    strcat (strcpy (bname, name), ext);
    _attribute[sb.i].block = block;
    baseblock = list_append (baseblock, sb);
  }
  else {
    sprintf (bname, "%s%d%s", name, n, ext);
    _attribute[sb.i].block = - n;
  }
  _attribute[sb.i].name = pstrdup (bname,__func__,__FILE__,0);
  all = list_append (all, sb);
}

#define interpreter_set_int(...)
#define interpreter_reset_scalar(...)

scalar alloc_block_scalar (const char * name, const char * ext, int block)
{
  interpreter_set_int (&block);
  int nvar = datasize/sizeof(real);

  scalar s = {0};
  while (s.i < nvar) {
    int n = 0;
    scalar sb = s;
    while (sb.i < nvar && n < block && _attribute[sb.i].freed)
      n++, sb.i++;
    if (n >= block) {
      memset (&_attribute[s.i], 0, block*sizeof (_Attributes));
      for (sb.i = s.i, n = 0; n < block; n++, sb.i++) {
 init_block_scalar (sb, name, ext, n, block);
 interpreter_reset_scalar (sb);
      }
      trash (((scalar []){s, {-1}}));
      return s;
    }
    s.i = sb.i + 1;
  }


  s = (scalar){nvar};
  if (!(nvar + block <= _NVARMAX)) qassert ("/home/jacqhugo/basilisk/src/grid/cartesian-common.h", 0, "nvar + block <= _NVARMAX");

  if (_attribute == NULL)
    _attribute = (_Attributes *) pcalloc (nvar + block + 1, sizeof (_Attributes),__func__,__FILE__,0);
  else
    _attribute = (_Attributes *)
      prealloc (_attribute, (nvar + block + 1)*sizeof (_Attributes),__func__,__FILE__,0);
  memset (&_attribute[nvar], 0, block*sizeof (_Attributes));
  for (int n = 0; n < block; n++, nvar++) {
    scalar sb = (scalar){nvar};
    init_block_scalar (sb, name, ext, n, block);
  }

  realloc_scalar (block*sizeof(real));
  trash (((scalar []){s, {-1}}));
  return s;
}

scalar new_block_scalar (const char * name, const char * ext, int block)
{
  scalar s = alloc_block_scalar (name, ext, block), sb;
  int n = 0;
  for (sb.i = s.i, n = 0; n < block; n++, sb.i++)
    init_scalar (sb, NULL);
  return s;
}

scalar new_scalar (const char * name)
{
  return init_scalar (alloc_block_scalar (name, "", 1), NULL);
}

scalar new_block_vertex_scalar (const char * name, int block)
{
  scalar s = alloc_block_scalar (name, "", block), sb;
  int n = 0;
  for (sb.i = s.i, n = 0; n < block; n++, sb.i++)
    init_vertex_scalar (sb, NULL);
  return s;
}

scalar new_vertex_scalar (const char * name)
{
  return init_vertex_scalar (alloc_block_scalar (name, "", 1), NULL);
}

static vector alloc_block_vector (const char * name, int block)
{
  vector v;
  struct { char * x, * y, * z; } ext = {".x", ".y", ".z"};
  
    v.x = alloc_block_scalar (name, ext.x, block);    v.y = alloc_block_scalar (name, ext.y, block);
  return v;
}

vector new_vector (const char * name)
{
  vector v = alloc_block_vector (name, 1);
  init_vector (v, NULL);
  return v;
}

vector new_face_vector (const char * name)
{
  vector v = alloc_block_vector (name, 1);
  init_face_vector (v, NULL);
  return v;
}

vector new_block_vector (const char * name, int block)
{
  vector v = alloc_block_vector (name, block);
  for (int i = 0; i < block; i++) {
    vector vb;
    
      vb.x.i = v.x.i + i;      vb.y.i = v.y.i + i;
    init_vector (vb, NULL);
    
      _attribute[vb.x.i].block = - i;      _attribute[vb.y.i].block = - i;
  }
  
    _attribute[v.x.i].block = block;    _attribute[v.y.i].block = block;
  return v;
}

vector new_block_face_vector (const char * name, int block)
{
  vector v = alloc_block_vector (name, block);
  for (int i = 0; i < block; i++) {
    vector vb;
    
      vb.x.i = v.x.i + i;      vb.y.i = v.y.i + i;
    init_face_vector (vb, NULL);
    
      _attribute[vb.x.i].block = - i;      _attribute[vb.y.i].block = - i;
  }
  
    _attribute[v.x.i].block = block;    _attribute[v.y.i].block = block;
  return v;
}

tensor new_tensor (const char * name)
{
  char cname[strlen(name) + 3];
  struct { char * x, * y, * z; } ext = {".x", ".y", ".z"};
  tensor t;
   {
    strcat (strcpy (cname, name), ext.x);
    t.x = alloc_block_vector (cname, 1);
  } 

{
    strcat (strcpy (cname, name), ext.y);
    t.y = alloc_block_vector (cname, 1);
  }
  init_tensor (t, NULL);
  return t;
}

tensor new_symmetric_tensor (const char * name)
{
  struct { char * x, * y, * z; } ext = {".x.x", ".y.y", ".z.z"};
  tensor t;
  
    t.x.x = alloc_block_scalar (name, ext.x, 1);    t.y.y = alloc_block_scalar (name, ext.y, 1);

    t.x.y = alloc_block_scalar (name, ".x.y", 1);
    t.y.x = t.x.y;

  init_tensor (t, NULL);
  return t;
}

static int nconst = 0;

void init_const_scalar (scalar s, const char * name, double val)
{
  if (s.i - _NVARMAX >= nconst) {
    _constant = (double *) prealloc (_constant, (s.i - _NVARMAX + 1)*sizeof(double),__func__,__FILE__,0);
    for (int i = nconst; i < s.i - _NVARMAX; i++)
      _constant[i] = 0.;
    nconst = s.i - _NVARMAX + 1;
  }
  _constant[s.i - _NVARMAX] = val;
}

scalar new_const_scalar (const char * name, int i, double val)
{
  scalar s = (scalar){i + _NVARMAX};
  init_const_scalar (s, name, val);
  return s;
}

void init_const_vector (vector v, const char * name, double * val)
{
  
    init_const_scalar (v.x, name, *val++);    init_const_scalar (v.y, name, *val++);
}

vector new_const_vector (const char * name, int i, double * val)
{
  vector v;
  
    v.x.i = _NVARMAX + i++;    v.y.i = _NVARMAX + i++;
  init_const_vector (v, name, val);
  return v;
}

static void cartesian_scalar_clone (scalar clone, scalar src)
{
  char * cname = _attribute[clone.i].name;
  BoundaryFunc * boundary = _attribute[clone.i].boundary;
  BoundaryFunc * boundary_homogeneous = _attribute[clone.i].boundary_homogeneous;
  BoundaryStencilFunc * boundary_stencil = _attribute[clone.i].boundary_stencil;
  if (!(_attribute[src.i].block > 0 && _attribute[clone.i].block == _attribute[src.i].block)) qassert ("/home/jacqhugo/basilisk/src/grid/cartesian-common.h", 0, "src.block > 0 && clone.block == src.block");
  pfree (_attribute[clone.i].depends,__func__,__FILE__,0);
  _attribute[clone.i] = _attribute[src.i];
  _attribute[clone.i].name = cname;
  _attribute[clone.i].boundary = boundary;
  _attribute[clone.i].boundary_homogeneous = boundary_homogeneous;
  _attribute[clone.i].boundary_stencil = boundary_stencil;
  for (int i = 0; i < nboundary; i++) {
    _attribute[clone.i].boundary[i] = _attribute[src.i].boundary[i];
    _attribute[clone.i].boundary_homogeneous[i] = _attribute[src.i].boundary_homogeneous[i];
    _attribute[clone.i].boundary_stencil[i] = _attribute[src.i].boundary_stencil[i];
  }
  _attribute[clone.i].depends = list_copy (_attribute[src.i].depends);
}

scalar * list_clone (scalar * l)
{
  scalar * list = NULL;
  int nvar = datasize/sizeof(real), map[nvar];
  for (int i = 0; i < nvar; i++)
    map[i] = -1;
  {scalar*_i=(scalar*)( l);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
    scalar c = _attribute[s.i].block > 1 ? new_block_scalar("c", "", _attribute[s.i].block) : new_scalar("c");
    scalar_clone (c, s);
    map[s.i] = c.i;
    list = list_append (list, c);
  }}}
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    {
      if (_attribute[s.i].v.x.i >= 0 && map[_attribute[s.i].v.x.i] >= 0)
 _attribute[s.i].v.x.i = map[_attribute[s.i].v.x.i];      

if (_attribute[s.i].v.y.i >= 0 && map[_attribute[s.i].v.y.i] >= 0)
 _attribute[s.i].v.y.i = map[_attribute[s.i].v.y.i];}}}
  return list;
}

void delete (scalar * list)
{
  if (all == NULL)
    return;

  {scalar*_i=(scalar*)( list);if(_i)for(scalar f=*_i;(&f)->i>=0;f=*++_i){ {
    for (int i = 0; i < _attribute[f.i].block; i++) {
      scalar fb = {f.i + i};
      if (_attribute[f.i].delete)
 _attribute[f.i].delete (fb);
      pfree (_attribute[fb.i].name,__func__,__FILE__,0); _attribute[fb.i].name = NULL;
      pfree (_attribute[fb.i].boundary,__func__,__FILE__,0); _attribute[fb.i].boundary = NULL;
      pfree (_attribute[fb.i].boundary_homogeneous,__func__,__FILE__,0); _attribute[fb.i].boundary_homogeneous = NULL;
      pfree (_attribute[fb.i].boundary_stencil,__func__,__FILE__,0); _attribute[fb.i].boundary_stencil = NULL;
      pfree (_attribute[fb.i].depends,__func__,__FILE__,0); _attribute[fb.i].depends = NULL;
      _attribute[fb.i].freed = true;
    }
  }}}

  if (list == all) {
    all[0].i = -1;
    baseblock[0].i = -1;
    return;
  }

  trash (list);
  {scalar*_i=(scalar*)( list);if(_i)for(scalar f=*_i;(&f)->i>=0;f=*++_i){ {
    if (_attribute[f.i].block > 0) {
      scalar * s;
      for (s = all; s->i >= 0 && s->i != f.i; s++);
      if (s->i == f.i) {
 for (; s[_attribute[f.i].block].i >= 0; s++)
   s[0] = s[_attribute[f.i].block];
 s->i = -1;
      }
      for (s = baseblock; s->i >= 0 && s->i != f.i; s++);
      if (s->i == f.i) {
 for (; s[1].i >= 0; s++)
   s[0] = s[1];
 s->i = -1;
      }
    }
  }}}
}

void free_solver()
{
  if (!(_val_higher_dimension == 0.)) qassert ("/home/jacqhugo/basilisk/src/grid/cartesian-common.h", 0, "_val_higher_dimension == 0.");

  if (free_solver_funcs) {
    free_solver_func * a = (free_solver_func *) free_solver_funcs->p;
    for (int i = 0; i < free_solver_funcs->len/sizeof(free_solver_func); i++)
      a[i] ();
    array_free (free_solver_funcs);
  }

  delete (all);
  pfree (all,__func__,__FILE__,0); all = NULL;
  pfree (baseblock,__func__,__FILE__,0); baseblock = NULL;
  for (Event * ev = Events; !ev->last; ev++) {
    Event * e = ev->next;
    while (e) {
      Event * next = e->next;
      pfree (e,__func__,__FILE__,0);
      e = next;
    }
  }

  pfree (Events,__func__,__FILE__,0); Events = NULL;
  pfree (_attribute,__func__,__FILE__,0); _attribute = NULL;
  pfree (_constant,__func__,__FILE__,0); _constant = NULL;




  free_grid();
  qpclose_all();
#if TRACE
  trace_off();
#endif
#if MTRACE
  pmuntrace();
#endif
#if _CADNA
  cadna_end();
#endif
}



void (* boundary_level) (scalar *, int l);
void (* boundary_face) (vectorl);




void boundary_flux (vector * list) __attribute__ ((deprecated));

void boundary_flux (vector * list)
{
  vectorl list1 = {NULL};
  {vector*_i=(vector*)( list);if(_i)for(vector v=*_i;(&v)->x.i>=0;v=*++_i){
    {
      list1.x = list_append (list1.x, v.x);      list1.y = list_append (list1.y, v.y);}}}
  boundary_face (list1);
  
    pfree (list1.x,__func__,__FILE__,0);    pfree (list1.y,__func__,__FILE__,0);
}

static scalar * list_add_depends (scalar * list, scalar s)
{
  {scalar*_i=(scalar*)( list);if(_i)for(scalar t=*_i;(&t)->i>=0;t=*++_i){
    if (t.i == s.i)
      return list;}}
  scalar * list1 = list;
  {scalar*_i=(scalar*)( _attribute[s.i].depends);if(_i)for(scalar d=*_i;(&d)->i>=0;d=*++_i){
    if (!(_attribute[d.i].stencil.bc & s_centered))
      list1 = list_add_depends (list1, d);}}
  return list_append (list1, s);
}

     
void boundary_internal (scalar * list, const char * fname, int line)
{tracing("boundary_internal","/home/jacqhugo/basilisk/src/grid/cartesian-common.h",0);
  if (list == NULL)
    {end_tracing("boundary_internal","/home/jacqhugo/basilisk/src/grid/cartesian-common.h",0);return;}
  scalar * listc = NULL;
  vectorl listf = {NULL};
  bool flux = false;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!is_constant(s) && _attribute[s.i].block > 0) {
      if (scalar_is_dirty (s)) {
 if (_attribute[s.i].face && !(_attribute[s.i].stencil.bc & s_face))
   {
     if (_attribute[s.i].v.x.i == s.i)
       listf.x = list_add (listf.x, s), flux = true;     

if (_attribute[s.i].v.y.i == s.i)
       listf.y = list_add (listf.y, s), flux = true;}
 if (!is_constant(cm) && !(_attribute[cm.i].stencil.bc & s_centered))
   listc = list_add_depends (listc, cm);
 if (_attribute[s.i].face != 2)
   listc = list_add_depends (listc, s);
      }




    }}}
  if (flux) {

    boundary_face (listf);
    
      pfree (listf.x,__func__,__FILE__,0);      pfree (listf.y,__func__,__FILE__,0);
  }
  if (listc) {






    boundary_level (listc, -1);
    {scalar*_i=(scalar*)( listc);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      _attribute[s.i].stencil.bc |= s_centered;}}
    pfree (listc,__func__,__FILE__,0);
  }
end_tracing("boundary_internal","/home/jacqhugo/basilisk/src/grid/cartesian-common.h",0);}

void cartesian_boundary_level (scalar * list, int l)
{
  { Boundary ** _i = boundaries, * _b; while (_i && (_b = *_i++)) if (_b->level) _b->level (_b, list, l); };
}

void cartesian_boundary_face (vectorl vl)
{
  scalar * listc = NULL;
  
    {scalar*_i=(scalar*)( vl.x);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
      _attribute[s.i].stencil.bc |= s_face;
      _attribute[s.i].stencil.bc &= ~s_centered;
      listc = list_add_depends (listc, s);
    }}}    

{scalar*_i=(scalar*)( vl.y);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
      _attribute[s.i].stencil.bc |= s_face;
      _attribute[s.i].stencil.bc &= ~s_centered;
      listc = list_add_depends (listc, s);
    }}}
  boundary_level (listc, -1);
  pfree (listc,__func__,__FILE__,0);
}

static double symmetry (Point point, Point neighbor, scalar s, bool * data)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  

return val(s,0,0,0);
}

static double antisymmetry (Point point, Point neighbor, scalar s, bool * data)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  

return -val(s,0,0,0);
}

BoundaryFunc default_scalar_bc[] = {
  symmetry, symmetry, symmetry, symmetry, symmetry, symmetry
};

scalar cartesian_init_scalar (scalar s, const char * name)
{

  char * pname;
  if (name) {
    pfree (_attribute[s.i].name,__func__,__FILE__,0);
    pname = pstrdup (name,__func__,__FILE__,0);
  }
  else
    pname = _attribute[s.i].name;
  int block = _attribute[s.i].block;
  BoundaryFunc * boundary = _attribute[s.i].boundary;
  BoundaryFunc * boundary_homogeneous = _attribute[s.i].boundary_homogeneous;
  BoundaryStencilFunc * boundary_stencil = _attribute[s.i].boundary_stencil;
  _attribute[s.i].name = pname;
  if (block < 0)
    _attribute[s.i].block = block;
  else
    _attribute[s.i].block = block > 0 ? block : 1;

  _attribute[s.i].boundary = boundary ? boundary : (BoundaryFunc *) pmalloc (nboundary*sizeof (BoundaryFunc),__func__,__FILE__,0);
  _attribute[s.i].boundary_homogeneous = boundary_homogeneous ? boundary_homogeneous :
    (BoundaryFunc *) pmalloc (nboundary*sizeof (BoundaryFunc),__func__,__FILE__,0);
  _attribute[s.i].boundary_stencil = boundary_stencil ? boundary_stencil :
    (BoundaryStencilFunc *) pmalloc (nboundary*sizeof (BoundaryStencilFunc),__func__,__FILE__,0);
  for (int b = 0; b < nboundary; b++) {
    _attribute[s.i].boundary[b] = _attribute[s.i].boundary_homogeneous[b] =
      b < 2*2 ? default_scalar_bc[b] : symmetry;
    _attribute[s.i].boundary_stencil[b] = NULL;
  }
  _attribute[s.i].gradient = NULL;
   {
    _attribute[s.i].d.x = 0;
    _attribute[s.i].v.x.i = -1;
  } 

{
    _attribute[s.i].d.y = 0;
    _attribute[s.i].v.y.i = -1;
  }
  _attribute[s.i].face = false;
  return s;
}

scalar cartesian_init_vertex_scalar (scalar s, const char * name)
{
  cartesian_init_scalar (s, name);
  
    _attribute[s.i].d.x = -1;    _attribute[s.i].d.y = -1;
  for (int d = 0; d < nboundary; d++)
    _attribute[s.i].boundary[d] = _attribute[s.i].boundary_homogeneous[d] = NULL, _attribute[s.i].boundary_stencil[d] = NULL;
  return s;
}

BoundaryFunc default_vector_bc[] = {
  antisymmetry, antisymmetry,
  antisymmetry, antisymmetry,
  antisymmetry, antisymmetry
};

vector cartesian_init_vector (vector v, const char * name)
{
  struct { char * x, * y, * z; } ext = {".x", ".y", ".z"};
   {
    if (name) {
      char cname[strlen(name) + 3];
      strcat (strcpy (cname, name), ext.x);
      cartesian_init_scalar (v.x, cname);
    }
    else
      cartesian_init_scalar (v.x, NULL);
    _attribute[v.x.i].v = v;
  } 

{
    if (name) {
      char cname[strlen(name) + 3];
      strcat (strcpy (cname, name), ext.y);
      cartesian_init_scalar (v.y, cname);
    }
    else
      cartesian_init_scalar (v.y, NULL);
    _attribute[v.y.i].v = v;
  }

  for (int d = 0; d < nboundary; d++) {
    _attribute[v.x.i].boundary[d] = _attribute[v.x.i].boundary_homogeneous[d] =
      d < 2*2 ? default_vector_bc[d] : antisymmetry;
    _attribute[v.x.i].boundary_stencil[d] = NULL;
  }
  return v;
}

vector cartesian_init_face_vector (vector v, const char * name)
{
  v = cartesian_init_vector (v, name);
   {
    _attribute[v.x.i].d.x = -1;
    _attribute[v.x.i].face = true;
  } 

{
    _attribute[v.y.i].d.y = -1;
    _attribute[v.y.i].face = true;
  }
  for (int d = 0; d < nboundary; d++)
    _attribute[v.x.i].boundary[d] = _attribute[v.x.i].boundary_homogeneous[d] = NULL, _attribute[v.x.i].boundary_stencil[d] = NULL;
  return v;
}

tensor cartesian_init_tensor (tensor t, const char * name)
{
  struct { char * x, * y, * z; } ext = {".x", ".y", ".z"};
   {
    if (name) {
      char cname[strlen(name) + 3];
      strcat (strcpy (cname, name), ext.x);
      cartesian_init_vector (t.x, cname);
    }
    else
      cartesian_init_vector (t.x, NULL);
  } 

{
    if (name) {
      char cname[strlen(name) + 3];
      strcat (strcpy (cname, name), ext.y);
      cartesian_init_vector (t.y, cname);
    }
    else
      cartesian_init_vector (t.y, NULL);
  }

    for (int b = 0; b < nboundary; b++) {
      _attribute[t.x.x.i].boundary[b] = _attribute[t.y.x.i].boundary[b] =
 _attribute[t.x.x.i].boundary_homogeneous[b] = _attribute[t.y.y.i].boundary_homogeneous[b] =
 b < 2*2 ? default_scalar_bc[b] : symmetry;
      _attribute[t.x.y.i].boundary[b] = _attribute[t.y.y.i].boundary[b] =
 _attribute[t.x.y.i].boundary_homogeneous[b] = _attribute[t.y.x.i].boundary_homogeneous[b] =
 b < 2*2 ? default_vector_bc[b] : antisymmetry;
      _attribute[t.x.x.i].boundary_stencil[b] = _attribute[t.y.y.i].boundary_stencil[b] =
        _attribute[t.x.y.i].boundary_stencil[b] = _attribute[t.y.x.i].boundary_stencil[b] = NULL;
    }



  return t;
}

void output_cells (FILE * fp, coord c, double size)
{ 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    bool inside = true;
    coord o = {x,y,z};
    
      if (inside && size > 0. &&
   (o.x > c.x + size || o.x < c.x - size))
 inside = false;      

if (inside && size > 0. &&
   (o.y > c.y + size || o.y < c.y - size))
 inside = false;
    if (inside) {
      Delta /= 2.;



      fprintf (fp, "%g %g\n%g %g\n%g %g\n%g %g\n%g %g\n\n",
        x - Delta, y - Delta,
        x - Delta, y + Delta,
        x + Delta, y + Delta,
        x + Delta, y - Delta,
        x - Delta, y - Delta);

    }
  }}      

}
  }
}
  

fflush (fp);
}

static char * replace_ (const char * vname)
{
  char * name = pstrdup (vname,__func__,__FILE__,0), * c = name;
  while (*c != '\0') {
    if (*c == '.')
      *c = '_';
    c++;
  }
  return name;
}

static void debug_plot (FILE * fp, const char * name, const char * cells,
   const char * stencil)
{
  char * vname = replace_ (name);
  fprintf (fp,
    "  load 'debug.plot'\n"
    "  v=%s\n"




    "  plot '%s' w l lc 0, "
    "'%s' u 1+3*v:2+3*v:3+3*v w labels tc lt 1 title columnhead(3+3*v)",





    vname, cells, stencil);
  pfree (vname,__func__,__FILE__,0);
}

void cartesian_debug (Point point)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  

char name[80] = "cells";
  if (pid() > 0)
    sprintf (name, "cells-%d", pid());
  FILE * fp = fopen (name, "w");
  output_cells (fp, (coord){x,y,z}, 4.*Delta);
  fclose (fp);

  char stencil[80] = "stencil";
  if (pid() > 0)
    sprintf (stencil, "stencil-%d", pid());
  fp = fopen (stencil, "w");
  {scalar*_i=(scalar*)( all);if(_i)for(scalar v=*_i;(&v)->i>=0;v=*++_i){



    fprintf (fp, "x y %s ", _attribute[v.i].name);}}



  fputc ('\n', fp);

    for (int k = -2; k <= 2; k++)
      for (int l = -2; l <= 2; l++) {
 {scalar*_i=(scalar*)( all);if(_i)for(scalar v=*_i;(&v)->i>=0;v=*++_i){ {
   fprintf (fp, "%g %g ",
     x + k*Delta + _attribute[v.i].d.x*Delta/2.,
     y + l*Delta + _attribute[v.i].d.y*Delta/2.);
   if (allocated(k,l,0))
     fprintf (fp, "%g ", val(v,k,l,0));
   else
     fputs ("n/a ", fp);
 }}}
 fputc ('\n', fp);
      }

  fclose (fp);

  fp = fopen ("debug.plot", "w");
  fprintf (fp,
    "set term x11\n"
    "set size ratio -1\n"
    "set key outside\n");
  {scalar*_i=(scalar*)( all);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
    char * name = replace_ (_attribute[s.i].name);
    fprintf (fp, "%s = %d\n", name, s.i);
    pfree (name,__func__,__FILE__,0);
  }}}
  fclose (fp);

  fprintf (ferr, "Last point stencils can be displayed using (in gnuplot)\n");
  debug_plot (ferr, _attribute[0].name, name, stencil);
  fflush (ferr);

  fp = fopen ("plot", "w");
  debug_plot (fp, _attribute[0].name, name, stencil);
  fclose (fp);
}

void cartesian_methods()
{
  init_scalar = cartesian_init_scalar;
  init_vertex_scalar = cartesian_init_vertex_scalar;
  init_vector = cartesian_init_vector;
  init_face_vector = cartesian_init_face_vector;
  init_tensor = cartesian_init_tensor;
  boundary_level = cartesian_boundary_level;
  boundary_face = cartesian_boundary_face;
  scalar_clone = cartesian_scalar_clone;
  debug = cartesian_debug;
}

tensor init_symmetric_tensor (tensor t, const char * name)
{
  return init_tensor (t, name);
}

static double interpolate_linear (Point point, scalar v,
      double xp, double yp, double zp)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;







  

x = (xp - x)/Delta - _attribute[v.i].d.x/2.;
  y = (yp - y)/Delta - _attribute[v.i].d.y/2.;
  int i = ( (int)(x > 0 ? 1 : -1)), j = ( (int)(y > 0 ? 1 : -1));
  x = fabs(x); y = fabs(y);

  return ((val(v,0,0,0)*(1. - x) + val(v,i,0,0)*x)*(1. - y) +
   (val(v,0,j,0)*(1. - x) + val(v,i,j,0)*x)*y);

}

static void _stencil_interpolate_linear (Point point, scalar v,
_stencil_undefined * xp,_stencil_undefined * yp,_stencil_undefined * zp)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;                    







        
        
  
       

_stencil_val(v,0,0,0);_stencil_val(v, o_stencil,0,0);
_stencil_val(v,0,o_stencil,0); _stencil_val(v,o_stencil,o_stencil,0);  

return         
    ;

}

     
double interpolate (scalar v, double xp, double yp, double zp,
      bool linear)
{tracing("interpolate","/home/jacqhugo/basilisk/src/grid/cartesian-common.h",0);
  double val = 1e30f;  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/grid/cartesian-common.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    

{ _stencil_interpolate_linear (point, v, NULL, NULL, NULL); _stencil_val(v,0,0,0);    }    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    coord _p = { xp, yp, zp };
    Point point = locate (_p.x, _p.y, _p.z);
    if (point.level >= 0)
    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val = linear ? interpolate_linear (point, v, xp, yp, zp) : val(v,0,0,0);}  

}
}

{mpi_all_reduce_array(&val,MPI_DOUBLE,MPI_MIN,1);}
  {end_tracing("interpolate","/home/jacqhugo/basilisk/src/grid/cartesian-common.h",0);return val;}
end_tracing("interpolate","/home/jacqhugo/basilisk/src/grid/cartesian-common.h",0);}

     
void interpolate_array (scalar * list, coord * a, int n, double * v,
   bool linear)
{tracing("interpolate_array","/home/jacqhugo/basilisk/src/grid/cartesian-common.h",0);
  int len = 0; NOT_UNUSED(len);
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    len++;}}
  for (int i = 0; i < n; i++) {
    double * w = v;

    {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      *(w++) = 1e30f;}}    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/grid/cartesian-common.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{   
      
      {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
 { _stencil_val(s,0,0,0); _stencil_interpolate_linear (point, s, NULL, NULL, NULL);    }}}
    }    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    coord _p = { (

a[i].x

), (

a[i].y

), (

a[i].z

) };
    Point point = locate (_p.x, _p.y, _p.z);
    if (point.level >= 0) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
      int j = 0;
      {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
 v[j++] = !linear ? val(s,0,0,0) : interpolate_linear (point, s, a[i].x, a[i].y, a[i].z);}}
    }}  

}
}

{mpi_all_reduce_array(v,MPI_DOUBLE,MPI_MIN,len);}

    v = w;
  }
end_tracing("interpolate_array","/home/jacqhugo/basilisk/src/grid/cartesian-common.h",0);}



typedef int bid;

bid new_bid()
{
  int b = nboundary++;
  {scalar*_i=(scalar*)( all);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
    _attribute[s.i].boundary = (BoundaryFunc *) prealloc (_attribute[s.i].boundary, nboundary*sizeof (BoundaryFunc),__func__,__FILE__,0);
    _attribute[s.i].boundary_homogeneous = (BoundaryFunc *)
      prealloc (_attribute[s.i].boundary_homogeneous, nboundary*sizeof (BoundaryFunc),__func__,__FILE__,0);
  }}}
  {scalar*_i=(scalar*)( all);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
    if (_attribute[s.i].v.x.i < 0)
      _attribute[s.i].boundary[b] = _attribute[s.i].boundary_homogeneous[b] = symmetry;
    else if (_attribute[s.i].v.x.i == s.i) {
      vector v = _attribute[s.i].v;
      
 _attribute[v.y.i].boundary[b] = _attribute[v.y.i].boundary_homogeneous[b] = symmetry; _attribute[v.x.i].boundary[b] = _attribute[v.x.i].boundary_homogeneous[b] = symmetry;
      _attribute[v.x.i].boundary[b] = _attribute[v.x.i].boundary_homogeneous[b] =
 _attribute[v.x.i].face ? NULL : antisymmetry;
    }
  }}}
  return b;
}



static double periodic_bc (Point point, Point neighbor, scalar s, bool * data)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  

return val(s,0,0,0);
}

static void periodic_boundary (int d)
{

  {scalar*_i=(scalar*)( all);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
    if (is_vertex_scalar (s))
      _attribute[s.i].boundary[d] = _attribute[s.i].boundary_homogeneous[d] = NULL;
    else
      _attribute[s.i].boundary[d] = _attribute[s.i].boundary_homogeneous[d] = periodic_bc;
    _attribute[s.i].boundary_stencil[d] = NULL;
  }}}

  {scalar*_i=(scalar*)( all);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (_attribute[s.i].face) {
      vector v = _attribute[s.i].v;
      _attribute[v.x.i].boundary[d] = _attribute[v.x.i].boundary_homogeneous[d] = NULL;
    }}}

  default_scalar_bc[d] = periodic_bc;
  default_vector_bc[d] = periodic_bc;
}

void periodic (int dir)
{



    if (!(dir <= bottom)) qassert ("/home/jacqhugo/basilisk/src/grid/cartesian-common.h", 0, "dir <= bottom");




  int c = dir/2;
  periodic_boundary (2*c);
  periodic_boundary (2*c + 1);
  (&Period.x)[c] = true;
}


double getvalue (Point point, scalar s, int i, int j, int k)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  

return val(s,i,j,k);
}

void default_stencil (Point p, scalar * list)
{
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
    if (_attribute[s.i].v.x.i != -1) {
      vector v = _attribute[s.i].v;
      {scalar*_i=(scalar*)(((vector[]) {v,{{-1},{-1}}}));if(_i)for(scalar c=*_i;(&c)->i>=0;c=*++_i){
        _attribute[c.i].stencil.io |= s_input|s_output|s_nowarning, _attribute[c.i].stencil.width = 2;}}
    }
    else
      _attribute[s.i].stencil.io |= s_input|s_output|s_nowarning, _attribute[s.i].stencil.width = 2;
  }}}
}




static void write_stencil_index (int * index)
{
  fprintf (qstderr(), "[%d", index[0]);
  for (int d = 1; d < 2; d++)
    fprintf (qstderr(), ",%d", index[d]);
  fputs ("]", qstderr());
}

void stencil_val (Point p, scalar s, int i, int j, int k,
    const char * file, int line, bool overflow)
{
  if (is_constant(s) || s.i < 0)
    return;
  if (_attribute[s.i].block < 0)
    s.i += _attribute[s.i].block;
  if (!_attribute[s.i].name) {
    fprintf (ferr, "%s:%d: error: trying to access a deleted field\n",
      file, line);
    exit (1);
  }
  int index[] = {i, j, k};
  for (int d = 0; d < 2; d++) {
    if (index[d] == o_stencil)
      index[d] = 2;
    else
      index[d] += (&p.i)[d];
  }
  bool central = true;
  for (int d = 0; d < 2; d++) {
    if (!overflow && (index[d] > 2 || index[d] < - 2)) {
      fprintf (qstderr(), "%s:%d: error: stencil overflow: %s",
        file, line, _attribute[s.i].name);
      write_stencil_index (index);
      fprintf (qstderr(), "\n");
      fflush (qstderr());
      abort();
    }
    if (index[d] != 0)
      central = false;
  }
  if (central) {
    if (!(_attribute[s.i].stencil.io & s_output))
      _attribute[s.i].stencil.io |= s_input;
  }
  else {
    _attribute[s.i].stencil.io |= s_input;
    int d = 0;
     {
      if ((!_attribute[s.i].face || _attribute[s.i].v.x.i != s.i) && abs(index[d]) > _attribute[s.i].stencil.width)
 _attribute[s.i].stencil.width = abs(index[d]);
      d++;
    } 

{
      if ((!_attribute[s.i].face || _attribute[s.i].v.y.i != s.i) && abs(index[d]) > _attribute[s.i].stencil.width)
 _attribute[s.i].stencil.width = abs(index[d]);
      d++;
    }
  }
}

void stencil_val_a (Point p, scalar s, int i, int j, int k, bool input,
      const char * file, int line)
{
  if (is_constant(s) || s.i < 0) {
    fprintf (ferr, "%s:%d: error: trying to modify a%s field\n",
      file, line, s.i < 0 ? "n undefined" : " constant");
    exit (1);
  }
  if (_attribute[s.i].block < 0)
    s.i += _attribute[s.i].block;
  if (!_attribute[s.i].name) {
    fprintf (ferr, "%s:%d: error: trying to access a deleted field\n",
      file, line);
    exit (1);
  }
  int index[] = {i, j, k};
  for (int d = 0; d < 2; d++)
    index[d] += (&p.i)[d];
  for (int d = 0; d < 2; d++)
    if (index[d] != 0) {
      fprintf (qstderr(), "%s:%d: error: illegal write: %s",
        file, line, _attribute[s.i].name);
      write_stencil_index (index);
      fprintf (qstderr(), "\n");
      fflush (qstderr());
      abort();
    }
  if (input && !(_attribute[s.i].stencil.io & s_output))
    _attribute[s.i].stencil.io |= s_input;
  _attribute[s.i].stencil.io |= s_output;
} 


void macro_foreach_level_or_leaf (int l, char flags, Reduce reductions)
{ 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = l;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++)    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

;}
    

}
  }
}

} 

void macro_foreach_coarse_level (int l, char flags, Reduce reductions)
{ 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = l;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++)    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

;}
    

}
  }
}

}








void set_prolongation (scalar s, void (* prolongation) (Point, scalar))
{
  _attribute[s.i].prolongation = prolongation;
  set_dirty_stencil (s);
}

void set_restriction (scalar s, void (* restriction) (Point, scalar))
{
  _attribute[s.i].restriction = restriction;
  set_dirty_stencil (s);
}



void (* restriction) (scalar *);

static inline void restriction_average (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

for (point.l = 0; point.l < _attribute[s.i].block; point.l++) 

{
    double sum = 0.;
  
    

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;      

sum += val(s,0,0,0);
      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }    

val(s,0,0,0) = sum/(1 << 2);
  }  

point.l = 0;


}

static void _stencil_restriction_average (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

for (point.l = 0; point.l < _attribute[s.i].block; point.l++) 

{
     
    
    

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;      

{ _stencil_val(s,0,0,0); }
      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }    

_stencil_val_a(s,0,0,0);    
  }  

point.l = 0;


}

static inline void restriction_volume_average (Point point, scalar s)
{if(!is_constant(cm)){{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

for (point.l = 0; point.l < _attribute[s.i].block; point.l++) 

{
    double sum = 0.;
  
    

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;      

sum += val(cm,0,0,0)*val(s,0,0,0);
      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }    

val(s,0,0,0) = sum/(1 << 2)/(val(cm,0,0,0) + 1e-30);
  }  

point.l = 0;


}}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);

{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

for (point.l = 0; point.l < _attribute[s.i].block; point.l++) 

{
    double sum = 0.;
  
    

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;      

sum += _const_cm*val(s,0,0,0);
      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }    

val(s,0,0,0) = sum/(1 << 2)/(_const_cm + 1e-30);
  }  

point.l = 0;


}}}

static inline void face_average (Point point, vector v)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;     

{
  for (point.l = 0; point.l < _attribute[(

v.x

).i].block; point.l++) 

{




      val(v.x,0,0,0) = (fine(v.x,0,0,0) + fine(v.x,0,1,0))/2.;
      val(v.x,1,0,0) = (fine(v.x,2,0,0) + fine(v.x,2,1,0))/2.;






  }  

point.l = 0;
}     

{
  for (point.l = 0; point.l < _attribute[(

v.y

).i].block; point.l++) 

{




      val(v.y,0,0,0) = (fine(v.y,0,0,0) + fine(v.y,1,0,0))/2.;
      val(v.y,0,1,0) = (fine(v.y,0,2,0) + fine(v.y,1,2,0))/2.;






  }  

point.l = 0;
}


}

static inline void restriction_face (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

face_average (point, _attribute[s.i].v);
}

static inline void restriction_vertex (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

for (point.l = 0; point.l < _attribute[s.i].block; point.l++)
    

for (int i = 0; i <= 1; i++) {
      val(s,i,0,0) = fine(s,2*i,0,0);

      val(s,i,1,0) = fine(s,2*i,2,0);





    }  

point.l = 0;


}

static inline void no_restriction (Point point, scalar s) {}

static inline void no_data (Point point, scalar s) {int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
  

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;     

{
  for (point.l = 0; point.l < _attribute[s.i].block; point.l++)
      

val(s,0,0,0) = 1e30f;  

point.l = 0;
}
      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }

}

void wavelet (scalar s, scalar w)
{
  restriction (((scalar[]){s,{-1}}));
  for (int l = grid->maxdepth - 1; l >= 0; l--) {
  
  
    

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{
  
      

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;        

{ _stencil_val(s,0,0,0);_stencil_val_a(w,0,0,0); }
      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }

default_stencil (      point,((scalar[]){ s,{-1}}));
  
      

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2; 

{  
         _stencil_val(s,0,0,0); 
_stencil_val(w,0,0,0);        _stencil_val_a(s,0,0,0); 

        _stencil_val_r(w,0,0,0);  
      }
      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }    

}
  

}

{ 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = l;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
  
      

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;        

val(w,0,0,0) = val(s,0,0,0);
      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }      

_attribute[s.i].prolongation (point, s);
  
      

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2; 

{
        double sp = val(s,0,0,0);
        val(s,0,0,0) = val(w,0,0,0);

        val(w,0,0,0) -= sp;
      }
      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }    

}}
    

}
  }
}

}
    

boundary_level (((scalar[]){w,{-1}}), l + 1);
  }
  

  

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    

{ _stencil_val(s,0,0,0);_stencil_val_a(w,0,0,0); }
  

} 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = 0;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++)    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(w,0,0,0) = val(s,0,0,0);}
    

}
  }
}  

boundary_level (((scalar[]){w,{-1}}), 0);
}

void inverse_wavelet (scalar s, scalar w)
{
  
  

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    

{ _stencil_val(w,0,0,0);_stencil_val_a(s,0,0,0); }
  

} 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = 0;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++)    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(s,0,0,0) = val(w,0,0,0);}
    

}
  }
}  

boundary_level (((scalar[]){s,{-1}}), 0);
  for (int l = 0; l <= grid->maxdepth - 1; l++) {
  
  
    

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{
default_stencil (      point,((scalar[]){ s,{-1}}));
  
      

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;        

{ _stencil_val(w,0,0,0);_stencil_val_r(s,0,0,0); }
      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }    

}
  

}

{ 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = l;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
      _attribute[s.i].prolongation (point, s);
  
      

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;        

val(s,0,0,0) += val(w,0,0,0);
      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }    

}}
    

}
  }
}

}
    

boundary_level (((scalar[]){s,{-1}}), l + 1);
  }
}

static inline double bilinear (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;    

return (9.*coarse(s,0,0,0) +
     3.*(coarse(s,child.x,0,0) + coarse(s,0,child.y,0)) +
     coarse(s,child.x,child.y,0))/16.;

}

static void _stencil_bilinear (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

_stencil_coarse(s,0,0,0);
_stencil_coarse(s,o_stencil,0,0); _stencil_coarse(s,0,o_stencil,0);
     _stencil_coarse(s,o_stencil,o_stencil,0);    

return 
        
;

}

static inline void refine_bilinear (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
  

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;     

{
  for (point.l = 0; point.l < _attribute[s.i].block; point.l++)
      

val(s,0,0,0) = bilinear (point, s);  

point.l = 0;
}
      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }

}

static inline double quadratic (double a, double b, double c)
{
  return (30.*a + 5.*b - 3.*c)/32.;
}

static inline double biquadratic (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

return
    quadratic (quadratic (coarse(s,0,0,0),
     coarse(s,child.x,0,0),
     coarse(s,-child.x,0,0)),
        quadratic (coarse(s,0,child.y,0),
     coarse(s,child.x,child.y,0),
     coarse(s,-child.x,child.y,0)),
        quadratic (coarse(s,0,-child.y,0),
     coarse(s,child.x,-child.y,0),
     coarse(s,-child.x,-child.y,0)));




}

static inline double biquadratic_vertex (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;



  

return (36.*val(s,0,0,0) + 18.*(val(s,-1,0,0) + val(s,0,-1,0)) - 6.*(val(s,1,0,0) + val(s,0,1,0)) +
   9.*val(s,-1,-1,0) - 3.*(val(s,1,-1,0) + val(s,-1,1,0)) + val(s,1,1,0))/64.;




}

static inline void refine_biquadratic (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
  

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;     

{
  for (point.l = 0; point.l < _attribute[s.i].block; point.l++)
      

val(s,0,0,0) = biquadratic (point, s);  

point.l = 0;
}
      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }

}

static inline void refine_linear_single (Point point, scalar s)
{if(!is_constant(cm)){{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  

coord g;
  if (_attribute[s.i].gradient)
    {
      g.x = _attribute[s.i].gradient (val(s,-1,0,0), val(s,0,0,0), val(s,1,0,0));      g.y = _attribute[s.i].gradient (val(s,0,-1,0), val(s,0,0,0), val(s,0,1,0));}
  else
    {
      g.x = (val(s,1,0,0) - val(s,-1,0,0))/2.;      g.y = (val(s,0,1,0) - val(s,0,-1,0))/2.;}

  double sc = val(s,0,0,0), cmc = 4.*val(cm,0,0,0), sum = val(cm,0,0,0)*(1 << 2);
  
  

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2; 

{
    val(s,0,0,0) = sc;
    
      val(s,0,0,0) += child.x*g.x*val(cm,-child.x,0,0)/cmc;      val(s,0,0,0) += child.y*g.y*val(cm,0,-child.y,0)/cmc;
    sum -= val(cm,0,0,0);
  }
      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }  

if (!(fabs(sum) < 1e-10)) qassert ("/home/jacqhugo/basilisk/src/grid/multigrid-common.h", 0, "fabs(sum) < 1e-10");
}}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);

{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  

coord g;
  if (_attribute[s.i].gradient)
    {
      g.x = _attribute[s.i].gradient (val(s,-1,0,0), val(s,0,0,0), val(s,1,0,0));      g.y = _attribute[s.i].gradient (val(s,0,-1,0), val(s,0,0,0), val(s,0,1,0));}
  else
    {
      g.x = (val(s,1,0,0) - val(s,-1,0,0))/2.;      g.y = (val(s,0,1,0) - val(s,0,-1,0))/2.;}

  double sc = val(s,0,0,0), cmc = 4.*_const_cm, sum = _const_cm*(1 << 2);
  
  

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2; 

{
    val(s,0,0,0) = sc;
    
      val(s,0,0,0) += child.x*g.x*_const_cm/cmc;      val(s,0,0,0) += child.y*g.y*_const_cm/cmc;
    sum -= _const_cm;
  }
      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }  

if (!(fabs(sum) < 1e-10)) qassert ("/home/jacqhugo/basilisk/src/grid/multigrid-common.h", 0, "fabs(sum) < 1e-10");
}}}

static inline void refine_linear (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

for (point.l = 0; point.l < _attribute[s.i].block; point.l++)
    

refine_linear_single (point, s);  

point.l = 0;


}

static inline void refine_reset (Point point, scalar v)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
  

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;     

{
  for (point.l = 0; point.l < _attribute[v.i].block; point.l++)
      

val(v,0,0,0) = 0.;  

point.l = 0;
}
      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }

}

static inline void refine_injection (Point point, scalar v)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  

double val = val(v,0,0,0);
  
  

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;     

{
  for (point.l = 0; point.l < _attribute[v.i].block; point.l++)
      

val(v,0,0,0) = val;  

point.l = 0;
}
      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }

}

static scalar multigrid_init_scalar (scalar s, const char * name)
{
  s = cartesian_init_scalar (s, name);
  _attribute[s.i].prolongation = refine_bilinear;
  _attribute[s.i].restriction = restriction_average;
  return s;
}

static scalar multigrid_init_vertex_scalar (scalar s, const char * name)
{
  s = cartesian_init_vertex_scalar (s, name);
  _attribute[s.i].restriction = restriction_vertex;
  return s;
}

static void multigrid_setup_vector (vector v)
{
   {
    _attribute[v.x.i].prolongation = refine_bilinear;
    _attribute[v.x.i].restriction = restriction_average;
  } 

{
    _attribute[v.y.i].prolongation = refine_bilinear;
    _attribute[v.y.i].restriction = restriction_average;
  }
}

static vector multigrid_init_vector (vector v, const char * name)
{
  v = cartesian_init_vector (v, name);
  multigrid_setup_vector (v);
  return v;
}

static vector multigrid_init_face_vector (vector v, const char * name)
{
  v = cartesian_init_face_vector (v, name);
  
    _attribute[v.y.i].restriction = no_restriction;    _attribute[v.x.i].restriction = no_restriction;
  _attribute[v.x.i].restriction = restriction_face;
  return v;
}

static tensor multigrid_init_tensor (tensor t, const char * name)
{
  t = cartesian_init_tensor (t, name);
  
    multigrid_setup_vector (t.x);    multigrid_setup_vector (t.y);
  return t;
}

void multigrid_debug (Point point)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  

cartesian_debug (point);

  FILE * plot = fopen ("plot", "a");
  if (point.level > 0) {
    char name[80] = "coarse";
    if (pid() > 0)
      sprintf (name, "coarse-%d", pid());
    FILE * fp = fopen (name, "w");

      double xc = x - child.x*Delta/2., yc = y - child.y*Delta/2.;
      for (int k = 0; k <= 1; k++)
 for (int l = 0; l <= 1; l++) {
   {scalar*_i=(scalar*)( all);if(_i)for(scalar v=*_i;(&v)->i>=0;v=*++_i){
     fprintf (fp, "%g %g %g ",
       xc + k*child.x*Delta*2. + _attribute[v.i].d.x*Delta,
       yc + l*child.y*Delta*2. + _attribute[v.i].d.y*Delta,
       coarse(v,k*child.x,l*child.y,0));}}
   fputc ('\n', fp);
 }
      fprintf (ferr, ", '%s' u 1+3*v:2+3*v:3+3*v w labels tc lt 3 t ''", name);
      fprintf (plot, ", '%s' u 1+3*v:2+3*v:3+3*v w labels tc lt 3 t ''", name);

    fclose (fp);
  }

  if (is_coarse()) {
    char name[80] = "fine";
    if (pid() > 0)
      sprintf (name, "fine-%d", pid());
    FILE * fp = fopen (name, "w");

      double xf = x - Delta/4., yf = y - Delta/4.;
      for (int k = -2; k <= 3; k++)
 for (int l = -2; l <= 3; l++) {
   {scalar*_i=(scalar*)( all);if(_i)for(scalar v=*_i;(&v)->i>=0;v=*++_i){ {
     fprintf (fp, "%g %g ",
       xf + k*Delta/2. + _attribute[v.i].d.x*Delta/4.,
       yf + l*Delta/2. + _attribute[v.i].d.y*Delta/4.);
     if (allocated_child(k,l,0))
       fprintf (fp, "%g ", fine(v,k,l,0));
     else
       fputs ("n/a ", fp);
   }}}
   fputc ('\n', fp);
 }
      fprintf (ferr, ", '%s' u 1+3*v:2+3*v:3+3*v w labels tc lt 2 t ''", name);
      fprintf (plot, ", '%s' u 1+3*v:2+3*v:3+3*v w labels tc lt 2 t ''", name);

    fclose (fp);
  }
  fflush (ferr);
  fclose (plot);
}

     
static void multigrid_restriction (scalar * list)
{tracing("multigrid_restriction","/home/jacqhugo/basilisk/src/grid/multigrid-common.h",0);
  scalar * listdef = NULL, * listc = NULL, * list2 = NULL;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!is_constant (s) && _attribute[s.i].block > 0 && !(_attribute[s.i].stencil.bc & s_restriction)) {
      if (_attribute[s.i].restriction == restriction_average) {
 listdef = list_add (listdef, s);
 list2 = list_add (list2, s);
      }
      else if (_attribute[s.i].restriction != no_restriction) {
 listc = list_add (listc, s);
 if (_attribute[s.i].face)
   {
     list2 = list_add (list2, _attribute[s.i].v.x);     list2 = list_add (list2, _attribute[s.i].v.y);}
 else
   list2 = list_add (list2, s);
      }
    }}}

  if (listdef || listc) {
    for (int l = depth() - 1; l >= 0; l--) {      

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{
 {scalar*_i=(scalar*)( listdef);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
   _stencil_restriction_average (point, s);}}
 {scalar*_i=(scalar*)( listc);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
default_stencil (   point,((scalar[]){ s,{-1}}));}}
      }  

}

{ 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = l;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
 {scalar*_i=(scalar*)( listdef);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
   restriction_average (point, s);}}
 {scalar*_i=(scalar*)( listc);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
   _attribute[s.i].restriction (point, s);}}
      }}    

}
  }
}

}
      

{ Boundary ** _i = boundaries, * _b; while (_i && (_b = *_i++)) if (_b->level) _b->level (_b, list2, l); };
    }
    pfree (listdef,__func__,__FILE__,0);
    pfree (listc,__func__,__FILE__,0);
    {scalar*_i=(scalar*)( list2);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      _attribute[s.i].stencil.bc |= s_restriction;}}
    pfree (list2,__func__,__FILE__,0);
  }
end_tracing("multigrid_restriction","/home/jacqhugo/basilisk/src/grid/multigrid-common.h",0);}

void multigrid_methods()
{
  cartesian_methods();
  init_scalar = multigrid_init_scalar;
  init_vertex_scalar = multigrid_init_vertex_scalar;
  init_vector = multigrid_init_vector;
  init_face_vector = multigrid_init_face_vector;
  init_tensor = multigrid_init_tensor;
  restriction = multigrid_restriction;
  debug = multigrid_debug;
}







void subtree_size (scalar size, bool leaves)
{  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/grid/multigrid-common.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    

{_stencil_val_a(size,0,0,0);  }    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)
    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(size,0,0,0) = 1;}      

}
  }
}





  

{ Boundary ** _i = boundaries, * _b; while (_i && (_b = *_i++)) if (_b->restriction) _b->restriction (_b,((scalar[]) {size,{-1}}), depth()); };
  for (int l = depth() - 1; l >= 0; l--) {    

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{      

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
 

{ _stencil_val(size,0,0,0); }      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }
      

_stencil_val_a(size,0,0,0);  
    }  

}

{ 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = l;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
      double sum = !leaves;      

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
 

sum += val(size,0,0,0);      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }
      

val(size,0,0,0) = sum;
    }}    

}
  }
}

}
    

{ Boundary ** _i = boundaries, * _b; while (_i && (_b = *_i++)) if (_b->restriction) _b->restriction (_b,((scalar[]) {size,{-1}}), l); };
  }
}



void macro_foreach_vertex (char flags, Reduce reductions) {

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    int ig = -1; NOT_UNUSED(ig);

    int jg = -1; NOT_UNUSED(jg);




    ;
  }}      

}
  }
}


}

ivec dimensions (int nx, int ny, int nz)
{
  if (nx != 0 || ny != 0 || nz != 0) {
    Dimensions.x = Dimensions_scale = ( nx > 1 ? nx : 1);

    Dimensions.y = ( ny > 1 ? ny : 1);




  }
  return Dimensions;
}








double Radius = 1.;

void macro4_VARIABLES (Point point, int _ig, int _jg, int _kg)
{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((_ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((_jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
}

static int metric_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i = 0)!=0;*ip=i;*tp=t;return ret;}

      static int metric(const int i,const double t,Event *_ev){tracing("metric","/home/jacqhugo/basilisk/src/spherical.h",0); {





  if (is_constant(cm)) {
    scalar * l = list_copy (all);
    cm = new_scalar("cm");
    pfree (all,__func__,__FILE__,0);
    all = list_concat (((scalar[]){cm,{-1}}), l);
    pfree (l,__func__,__FILE__,0);
  }
  scalar cmv = cm;
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/spherical.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{      
    
    _stencil_val_a(cmv,0,0,0);        
  }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double phi = y*3.14159265358979/180., dphi = Delta/(2.*Radius);
    val(cmv,0,0,0) = (sin(phi + dphi) - sin(phi - dphi))/(2.*dphi);
  }}
      

}
  }
}  

if (is_constant(fm.x)) {
    scalar * l = list_copy (all);
    fm = new_face_vector("fm");
    pfree (all,__func__,__FILE__,0);
    all = list_concat ((scalar *)((vector[]){fm,{{-1},{-1}}}), l);
    pfree (l,__func__,__FILE__,0);
  }
  vector fmv = fm;
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/spherical.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{ _loop.face |= (1 << 0);    

{_stencil_val_a(fmv.x,0,0,0);  } 

}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++) 

{
  if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(fmv.x,0,0,0) = 1.;}
  

}
}      

}
  }
}
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/spherical.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{ _loop.face |= (1 << 1);    

{_stencil_val_a(fmv.y,0,0,0);  } 

}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++) 

{
  if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(fmv.y,0,0,0) = cos(y*3.14159265358979/180.);}
  

}
}      

}
  }
}

}{end_tracing("metric","/home/jacqhugo/basilisk/src/spherical.h",0);return 0;}end_tracing("metric","/home/jacqhugo/basilisk/src/spherical.h",0);}













double DT = 1e30f, CFL = 0.5;




struct {

  long nc;

  long tnc;

  double t, tp;

  double speed;

  double ispeed;

  timer gt;
} perf = {0};





void update_perf() {
  perf.nc += grid->n;
  perf.tnc += grid->tn;
  perf.t = timer_elapsed (perf.gt);
  perf.speed = perf.tnc/perf.t;
  perf.ispeed = grid->tn/(perf.t - perf.tp);
  perf.tp = perf.t;
}






typedef struct {
  double cpu;
  double real;
  double speed;
  double min;
  double avg;
  double max;
  size_t tnc;
  long mem;
} timing;






timing timer_timing (timer t, int i, size_t tnc, double * mpi)
{
  timing s;



  clock_t end = clock();
  s.cpu = ((double) (end - t.c))/CLOCKS_PER_SEC;
  s.real = timer_elapsed (t);
  if (tnc == 0) {
    double n = 0;
mpi_sum_reduce_init(mpi_n,&n,MPI_DOUBLE,MPI_SUM,1); 

{
  OMP_PARALLEL (reduction(+:n)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

n++;}
      

}
  }
}

{mpi_sum_reduce_array(mpi_n,&n,MPI_DOUBLE,MPI_SUM,1);}
    s.tnc = n;
    tnc = n*i;
  }
  else
    s.tnc = tnc;





  s.mem = 0;

  s.min = s.max = s.avg = 0.;

  s.speed = s.real > 0. ? tnc/s.real : -1.;
  return s;
}




void timer_print (timer t, int i, size_t tnc)
{



  timing s = timer_timing (t, i, tnc, NULL);
  fprintf (fout,
    "\n# " "Multigrid"
    ", %d steps, %g CPU, %.4g real, %.3g points.step/s, %d var\n",
    i, s.cpu, s.real, s.speed, (int) (datasize/sizeof(real)));

  fflush (fout);
}







typedef struct {
  double avg, rms, max, volume;
} norm;

norm normf (scalar f)
{
  double avg = 0., rms = 0., max = 0., volume = 0.;
  if(!is_constant(cm)){
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/utils.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    

{_stencil_val(f,0,0,0);_stencil_val(cm,0,0,0); {   
      _stencil_val(f,0,0,0);   
         
_stencil_val(cm,0,0,0); 
        _stencil_val(cm,0,0,0); 
        _stencil_val(cm,0,0,0);    
}        }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

mpi_sum_reduce_init(mpi_volume,&volume,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_rms,&rms,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_avg,&avg,MPI_DOUBLE,MPI_SUM,1); 

{
  OMP_PARALLEL (reduction(max:max) reduction(+:avg)   reduction(+:rms) reduction(+:volume)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

if (val(f,0,0,0) != 1e30f && (( Delta*Delta)*val(cm,0,0,0)) > 0.) {
      double v = fabs(val(f,0,0,0));
      if (v > max) max = v;
      volume += (( Delta*Delta)*val(cm,0,0,0));
      avg += (( Delta*Delta)*val(cm,0,0,0))*v;
      rms += (( Delta*Delta)*val(cm,0,0,0))*( v*v);
    }}
      

}
  }
}

{mpi_sum_reduce_array(mpi_volume,&volume,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_rms,&rms,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_avg,&avg,MPI_DOUBLE,MPI_SUM,1);mpi_all_reduce_array(&max,MPI_DOUBLE,MPI_MAX,1);}}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/utils.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    

{_stencil_val(f,0,0,0);; {   
      _stencil_val(f,0,0,0);

;
;
;    
}        }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

mpi_sum_reduce_init(mpi_volume,&volume,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_rms,&rms,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_avg,&avg,MPI_DOUBLE,MPI_SUM,1); 

{
  OMP_PARALLEL (reduction(max:max) reduction(+:avg)   reduction(+:rms) reduction(+:volume)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

if (val(f,0,0,0) != 1e30f && (( Delta*Delta)*_const_cm) > 0.) {
      double v = fabs(val(f,0,0,0));
      if (v > max) max = v;
      volume += (( Delta*Delta)*_const_cm);
      avg += (( Delta*Delta)*_const_cm)*v;
      rms += (( Delta*Delta)*_const_cm)*( v*v);
    }}
      

}
  }
}

{mpi_sum_reduce_array(mpi_volume,&volume,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_rms,&rms,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_avg,&avg,MPI_DOUBLE,MPI_SUM,1);mpi_all_reduce_array(&max,MPI_DOUBLE,MPI_MAX,1);}}
  norm n;
  n.avg = volume ? avg/volume : 0.;
  n.rms = volume ? sqrt(rms/volume) : 0.;
  n.max = max;
  n.volume = volume;
  return n;
}





typedef struct {
  double min, max, sum, stddev, volume;
} stats;

stats statsf (scalar f)
{
  double min = 1e100, max = -1e100, sum = 0., sum2 = 0., volume = 0.;
  if(!is_constant(cm)){
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/utils.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    

{_stencil_val(cm,0,0,0); _stencil_val(f,0,0,0); {
_stencil_val(cm,0,0,0); 
        _stencil_val(cm,0,0,0);_stencil_val(f,0,0,0); 
        _stencil_val(cm,0,0,0);_stencil_val(f,0,0,0);_stencil_val(f,0,0,0); 
         _stencil_val(f,0,0,0); { _stencil_val(f,0,0,0); }
_stencil_val(f,0,0,0); { _stencil_val(f,0,0,0); }    
}       }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

mpi_sum_reduce_init(mpi_volume,&volume,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_sum2,&sum2,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_sum,&sum,MPI_DOUBLE,MPI_SUM,1); 

{
  OMP_PARALLEL (reduction(+:sum) reduction(+:sum2) reduction(+:volume)   reduction(max:max) reduction(min:min)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

if ((( Delta*Delta)*val(cm,0,0,0)) > 0. && val(f,0,0,0) != 1e30f) {
      volume += (( Delta*Delta)*val(cm,0,0,0));
      sum += (( Delta*Delta)*val(cm,0,0,0))*val(f,0,0,0);
      sum2 += (( Delta*Delta)*val(cm,0,0,0))*( (val(f,0,0,0))*(val(f,0,0,0)));
      if (val(f,0,0,0) > max) max = val(f,0,0,0);
      if (val(f,0,0,0) < min) min = val(f,0,0,0);
    }}
      

}
  }
}

{mpi_all_reduce_array(&min,MPI_DOUBLE,MPI_MIN,1);mpi_all_reduce_array(&max,MPI_DOUBLE,MPI_MAX,1);mpi_sum_reduce_array(mpi_volume,&volume,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_sum2,&sum2,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_sum,&sum,MPI_DOUBLE,MPI_SUM,1);}}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/utils.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    

{; _stencil_val(f,0,0,0); {
;
;_stencil_val(f,0,0,0);
;_stencil_val(f,0,0,0);_stencil_val(f,0,0,0); 
         _stencil_val(f,0,0,0); { _stencil_val(f,0,0,0); }
_stencil_val(f,0,0,0); { _stencil_val(f,0,0,0); }    
}       }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

mpi_sum_reduce_init(mpi_volume,&volume,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_sum2,&sum2,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_sum,&sum,MPI_DOUBLE,MPI_SUM,1); 

{
  OMP_PARALLEL (reduction(+:sum) reduction(+:sum2) reduction(+:volume)   reduction(max:max) reduction(min:min)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

if ((( Delta*Delta)*_const_cm) > 0. && val(f,0,0,0) != 1e30f) {
      volume += (( Delta*Delta)*_const_cm);
      sum += (( Delta*Delta)*_const_cm)*val(f,0,0,0);
      sum2 += (( Delta*Delta)*_const_cm)*( (val(f,0,0,0))*(val(f,0,0,0)));
      if (val(f,0,0,0) > max) max = val(f,0,0,0);
      if (val(f,0,0,0) < min) min = val(f,0,0,0);
    }}
      

}
  }
}

{mpi_all_reduce_array(&min,MPI_DOUBLE,MPI_MIN,1);mpi_all_reduce_array(&max,MPI_DOUBLE,MPI_MAX,1);mpi_sum_reduce_array(mpi_volume,&volume,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_sum2,&sum2,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_sum,&sum,MPI_DOUBLE,MPI_SUM,1);}}
  stats s;
  s.min = min, s.max = max, s.sum = sum, s.volume = volume;
  if (volume > 0.)
    sum2 -= sum*sum/volume;
  s.stddev = sum2 > 0. ? sqrt(sum2/volume) : 0.;
  return s;
}

static double generic_limiter (double r, double beta)
{
  double v1 = ( r < beta ? r : beta), v2 = ( (beta*r) < 1. ? (beta*r) : 1.);
  v1 = ( 0. > v1 ? 0. : v1);
  return ( v1 > v2 ? v1 : v2);
}

double minmod (double s0, double s1, double s2) {
  return s1 == s0 ? 0. : generic_limiter ((s2 - s1)/(s1 - s0), 1.)*(s1 - s0);
}

double superbee (double s0, double s1, double s2) {
  return s1 == s0 ? 0. : generic_limiter ((s2 - s1)/(s1 - s0), 2.)*(s1 - s0);
}

double sweby (double s0, double s1, double s2) {
  return s1 == s0 ? 0. : generic_limiter ((s2 - s1)/(s1 - s0), 1.5)*(s1 - s0);
}

double theta = 1.3;

double minmod2 (double s0, double s1, double s2)
{
  if (s0 < s1 && s1 < s2) {
    double d1 = theta*(s1 - s0), d2 = (s2 - s0)/2., d3 = theta*(s2 - s1);
    if (d2 < d1) d1 = d2;
    return ( d1 < d3 ? d1 : d3);
  }
  if (s0 > s1 && s1 > s2) {
    double d1 = theta*(s1 - s0), d2 = (s2 - s0)/2., d3 = theta*(s2 - s1);
    if (d2 > d1) d1 = d2;
    return ( d1 > d3 ? d1 : d3);
  }
  return 0.;
}

void gradients (scalar * f, vector * g)
{
  if (!(list_len(f) == vectors_len(g))) qassert ("/home/jacqhugo/basilisk/src/utils.h", 0, "list_len(f) == vectors_len(g)");
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/utils.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{
    scalar s; vector v;
    {vector*_i0=g;scalar*_i1= f;if(_i0)for(v=*_i0,s=*_i1;_i0->x.i>= 0;v=*++_i0,s=*++_i1){ {
      if (_attribute[s.i].gradient)
 { {





_stencil_val(s,-1,0,0); _stencil_val(s,0,0,0); _stencil_val(s,1,0,0);     _stencil_val_a(v.x,0,0,0);   
 } 

{





_stencil_val(s,0,-1,0); _stencil_val(s,0,0,0); _stencil_val(s,0,1,0);     _stencil_val_a(v.y,0,0,0);   
 }}
      else
 { {





_stencil_val(s,1,0,0); _stencil_val(s,-1,0,0);     _stencil_val_a(v.x,0,0,0);   
 } 

{





_stencil_val(s,0,1,0); _stencil_val(s,0,-1,0);     _stencil_val_a(v.y,0,0,0);   
 }}
    }}}
  }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    scalar s; vector v;
    {vector*_i0=g;scalar*_i1= f;if(_i0)for(v=*_i0,s=*_i1;_i0->x.i>= 0;v=*++_i0,s=*++_i1){ {
      if (_attribute[s.i].gradient)
 { {





     val(v.x,0,0,0) = _attribute[s.i].gradient (val(s,-1,0,0), val(s,0,0,0), val(s,1,0,0))/Delta;
 } 

{





     val(v.y,0,0,0) = _attribute[s.i].gradient (val(s,0,-1,0), val(s,0,0,0), val(s,0,1,0))/Delta;
 }}
      else
 { {





     val(v.x,0,0,0) = (val(s,1,0,0) - val(s,-1,0,0))/(2.*Delta);
 } 

{





     val(v.y,0,0,0) = (val(s,0,1,0) - val(s,0,-1,0))/(2.*Delta);
 }}
    }}}
  }}
      

}
  }
}

}

void vorticity (const vector u, scalar omega)
{
  if(!is_constant(fm.x) && !is_constant(cm)){
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/utils.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    

{_stencil_val(fm.x,1,0,0); _stencil_val(fm.x,0,0,0);_stencil_val(u.y,0,0,0);
        _stencil_val(fm.x,1,0,0);_stencil_val(u.y,1,0,0); _stencil_val(fm.x,0,0,0);_stencil_val(u.y,-1,0,0);
_stencil_val(fm.y,0,1,0); _stencil_val(fm.y,0,0,0);_stencil_val(u.x,0,0,0);
        _stencil_val(fm.y,0,0,0);_stencil_val(u.x,0,-1,0); _stencil_val(fm.y,0,1,0);_stencil_val(u.x,0,1,0);_stencil_val(cm,0,0,0);

_stencil_val_a(omega,0,0,0);      
             

}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)
    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(omega,0,0,0) = ((val(fm.x,1,0,0) - val(fm.x,0,0,0))*val(u.y,0,0,0) +
        val(fm.x,1,0,0)*val(u.y,1,0,0) - val(fm.x,0,0,0)*val(u.y,-1,0,0) -
        (val(fm.y,0,1,0) - val(fm.y,0,0,0))*val(u.x,0,0,0) +
        val(fm.y,0,0,0)*val(u.x,0,-1,0) - val(fm.y,0,1,0)*val(u.x,0,1,0))/(2.*(val(cm,0,0,0) + 0.)*Delta);}      

}
  }
}

}else if(is_constant(fm.x) && !is_constant(cm)){_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/utils.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    

{;;_stencil_val(u.y,0,0,0);
;_stencil_val(u.y,1,0,0);;_stencil_val(u.y,-1,0,0);
;;_stencil_val(u.x,0,0,0);
;_stencil_val(u.x,0,-1,0);;_stencil_val(u.x,0,1,0);_stencil_val(cm,0,0,0);

_stencil_val_a(omega,0,0,0);      
             

}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)
    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(omega,0,0,0) = ((_const_fm.x - _const_fm.x)*val(u.y,0,0,0) +
        _const_fm.x*val(u.y,1,0,0) - _const_fm.x*val(u.y,-1,0,0) -
        (_const_fm.y - _const_fm.y)*val(u.x,0,0,0) +
        _const_fm.y*val(u.x,0,-1,0) - _const_fm.y*val(u.x,0,1,0))/(2.*(val(cm,0,0,0) + 0.)*Delta);}      

}
  }
}

}else if(!is_constant(fm.x) && is_constant(cm)){double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/utils.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    

{_stencil_val(fm.x,1,0,0); _stencil_val(fm.x,0,0,0);_stencil_val(u.y,0,0,0);
        _stencil_val(fm.x,1,0,0);_stencil_val(u.y,1,0,0); _stencil_val(fm.x,0,0,0);_stencil_val(u.y,-1,0,0);
_stencil_val(fm.y,0,1,0); _stencil_val(fm.y,0,0,0);_stencil_val(u.x,0,0,0);
        _stencil_val(fm.y,0,0,0);_stencil_val(u.x,0,-1,0); _stencil_val(fm.y,0,1,0);_stencil_val(u.x,0,1,0);;

_stencil_val_a(omega,0,0,0);      
             

}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)
    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(omega,0,0,0) = ((val(fm.x,1,0,0) - val(fm.x,0,0,0))*val(u.y,0,0,0) +
        val(fm.x,1,0,0)*val(u.y,1,0,0) - val(fm.x,0,0,0)*val(u.y,-1,0,0) -
        (val(fm.y,0,1,0) - val(fm.y,0,0,0))*val(u.x,0,0,0) +
        val(fm.y,0,0,0)*val(u.x,0,-1,0) - val(fm.y,0,1,0)*val(u.x,0,1,0))/(2.*(_const_cm + 0.)*Delta);}      

}
  }
}

}else {_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/utils.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    

{;;_stencil_val(u.y,0,0,0);
;_stencil_val(u.y,1,0,0);;_stencil_val(u.y,-1,0,0);
;;_stencil_val(u.x,0,0,0);
;_stencil_val(u.x,0,-1,0);;_stencil_val(u.x,0,1,0);;

_stencil_val_a(omega,0,0,0);      
             

}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)
    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(omega,0,0,0) = ((_const_fm.x - _const_fm.x)*val(u.y,0,0,0) +
        _const_fm.x*val(u.y,1,0,0) - _const_fm.x*val(u.y,-1,0,0) -
        (_const_fm.y - _const_fm.y)*val(u.x,0,0,0) +
        _const_fm.y*val(u.x,0,-1,0) - _const_fm.y*val(u.x,0,1,0))/(2.*(_const_cm + 0.)*Delta);}      

}
  }
}

}
}





double change (scalar s, scalar sn)
{
  double max = 0.;
  if(!is_constant(cm)){
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/utils.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{
_stencil_val(cm,0,0,0); {     
       _stencil_val(sn,0,0,0);_stencil_val(s,0,0,0);   
       
  
    } 
_stencil_val(s,0,0,0);    _stencil_val_a(sn,0,0,0); 
  }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL (reduction(max:max)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    if ((( Delta*Delta)*val(cm,0,0,0)) > 0.) {
      double ds = fabs (val(s,0,0,0) - val(sn,0,0,0));
      if (ds > max)
 max = ds;
    }
    val(sn,0,0,0) = val(s,0,0,0);
  }}      

}
  }
}

{mpi_all_reduce_array(&max,MPI_DOUBLE,MPI_MAX,1);}}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/utils.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{
; {     
       _stencil_val(sn,0,0,0);_stencil_val(s,0,0,0);   
       
  
    } 
_stencil_val(s,0,0,0);    _stencil_val_a(sn,0,0,0); 
  }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL (reduction(max:max)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    if ((( Delta*Delta)*_const_cm) > 0.) {
      double ds = fabs (val(s,0,0,0) - val(sn,0,0,0));
      if (ds > max)
 max = ds;
    }
    val(sn,0,0,0) = val(s,0,0,0);
  }}      

}
  }
}

{mpi_all_reduce_array(&max,MPI_DOUBLE,MPI_MAX,1);}}
  return max;
}





scalar lookup_field (const char * name)
{
  if (name)
    {scalar*_i=(scalar*)( all);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      if (!strcmp (_attribute[s.i].name, name))
 return s;}}
  return (scalar){-1};
}

vector lookup_vector (const char * name)
{
  if (name) {
    char component[strlen(name) + 3];
    strcpy (component, name);
    strcat (component, ".x");
    {scalar*_i=(scalar*)( all);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      if (!strcmp (_attribute[s.i].name, component))
 return _attribute[s.i].v;}}
  }
  return (vector){{-1}};
}







void macro_foreach_segment (coord S[2], coord p[2], Reduce reductions)
{
  double norm = sqrt(( (S[1].x - S[0].x)*(S[1].x - S[0].x)) + ( (S[1].y - S[0].y)*(S[1].y - S[0].y)));
  if (norm > 0.) {
    coord t = {(S[1].x - S[0].x)/norm + 1e-6, (S[1].y - S[0].y)/norm - 1.5e-6};
    double alpha = S[0].x*t.y - S[0].y*t.x; 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)
      

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

if (fabs(t.y*x - t.x*y - alpha) < 0.708*Delta_x) {
 coord _o = {x,y}, p[2];
 int _n = 0;
 
   if (t.x)
     for (int _i = -1; _i <= 1 && _n < 2; _i += 2) {
       p[_n].x = _o.x + _i*Delta_x/2.;
       double a = (p[_n].x - S[0].x)/t.x;
       p[_n].y = S[0].y + a*t.y;
       if (fabs(p[_n].y - _o.y) <= Delta_x/2.) {
  a = ( a < 0. ? 0. : a > norm ? norm : a);
  p[_n].x = S[0].x + a*t.x, p[_n].y = S[0].y + a*t.y;
  if (fabs(p[_n].x - _o.x) <= Delta_x/2. &&
      fabs(p[_n].y - _o.y) <= Delta_x/2.)
    _n++;
       }
     }   

if (t.y)
     for (int _i = -1; _i <= 1 && _n < 2; _i += 2) {
       p[_n].y = _o.y + _i*Delta_y/2.;
       double a = (p[_n].y - S[0].y)/t.y;
       p[_n].x = S[0].x + a*t.x;
       if (fabs(p[_n].x - _o.x) <= Delta_y/2.) {
  a = ( a < 0. ? 0. : a > norm ? norm : a);
  p[_n].y = S[0].y + a*t.y, p[_n].x = S[0].x + a*t.x;
  if (fabs(p[_n].y - _o.y) <= Delta_y/2. &&
      fabs(p[_n].x - _o.x) <= Delta_y/2.)
    _n++;
       }
     }
 if (_n == 2)
   ;
      }}      

}
  }
}
  

}
}




void fields_stats (scalar * list)
{
  fprintf (ferr, "# t = %g, fields = {", t);
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    fprintf (ferr, " %s", _attribute[s.i].name);}}
  fputs (" }\n", ferr);
  fprintf (ferr, "# %12s: %12s %12s %12s %12s\n",
    "name", "min", "avg", "stddev", "max");
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
    stats ss = statsf (s);
    fprintf (ferr, "# %12s: %12g %12g %12g %12g\n",
      _attribute[s.i].name, ss.min, ss.sum/ss.volume, ss.stddev, ss.max);
  }}}
}




     
void output_field (scalar * list,
     FILE * fp,
     int n,
     bool linear,
     coord box[2])
{tracing("output_field","/home/jacqhugo/basilisk/src/output.h",0);
  n++;
  int len = list_len (list);
  double Delta = 0.999999*(box[1].x - box[0].x)/(n - 1);
  int ny = (box[1].y - box[0].y)/Delta + 1;
  double ** field = (double **) matrix_new (n, ny, len*sizeof(double)), * v = field[0];
  for (int i = 0; i < n*ny*len; i++, v++)
    *v = 1e30f;
  coord box1[2] = {{box[0].x - Delta/2., box[0].y - Delta/2.},
     {box[0].x + (n - 0.5)*Delta, box[0].y + (ny - 0.5)*Delta}};
  coord cn = {n, ny}, p;
  
  




  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/output.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);  

{                     
    
    
    
    
    {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      { _stencil_interpolate_linear (point, s, NULL, NULL, NULL); _stencil_val(s,0,0,0);      }}}
  }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  {
    if (cn.x < 1) cn.x = 1;
    if (cn.y < 1) cn.y = 1;
    if (cn.z < 1) cn.z = 1;

    for (int _i = 0; _i < (int) cn.x; _i++) {
      p.x = box1[0].x + (box1[1].x - box1[0].x)/cn.x*(_i + 0.5);
      for (int _j = 0; _j < (int) cn.y; _j++) {
 p.y = box1[0].y + (box1[1].y - box1[0].y)/cn.y*(_j + 0.5);
 for (int _k = 0; _k < (int) cn.z; _k++) {
   p.z = box1[0].z + (box1[1].z - box1[0].z)/cn.z*(_k + 0.5);
   Point point = locate (p.x, p.y, p.z);
   if (point.level >= 0) {
     int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);

  

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ** alias = field;
    int i = (p.x - box1[0].x)/(box1[1].x - box1[0].x)*cn.x;
    int j = (p.y - box1[0].y)/(box1[1].y - box1[0].y)*cn.y;
    int k = 0;
    {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      alias[i][len*j + k++] = linear ? interpolate_linear (point, s, p.x, p.y, p.z) : val(s,0,0,0);}}
  }}   

}
 }
      }
    }
  }
}

  

if (pid() == 0) {
    fprintf (fp, "# 1:x 2:y");
    int i = 3;
    {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      fprintf (fp, " %d:%s", i++, _attribute[s.i].name);}}
    fputc('\n', fp);
    for (int i = 0; i < n; i++) {
      double x = Delta*i + box[0].x;
      for (int j = 0; j < ny; j++) {
 double y = Delta*j + box[0].y;

 fprintf (fp, "%g %g", x, y);
 int k = 0;
 {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
   fprintf (fp, " %g", field[i][len*j + k++]);}}
 fputc ('\n', fp);
      }
      fputc ('\n', fp);
    }
    fflush (fp);
  }

  matrix_free (field);
end_tracing("output_field","/home/jacqhugo/basilisk/src/output.h",0);}

     
void output_matrix (scalar f,
      FILE * fp,
      int n,
      bool linear,
      const char * file,
      coord box[2])
{tracing("output_matrix","/home/jacqhugo/basilisk/src/output.h",0);
  coord cn = {n}, p;
  double delta = (box[1].x - box[0].x)/n;
  cn.y = (int)((box[1].y - box[0].y)/delta);

  double ** ppm = (double **) matrix_new (cn.x, cn.y, sizeof(double));
  double * ppm0 = &ppm[0][0];
  unsigned int len = cn.x*cn.y;
  for (int i = 0; i < len; i++)
    ppm0[i] = - 1e30f;
  
  




  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/output.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);  

{                  
    
    
     
_stencil_interpolate_linear (point, f, NULL, NULL, NULL); _stencil_val(f,0,0,0);  
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  {
    if (cn.x < 1) cn.x = 1;
    if (cn.y < 1) cn.y = 1;
    if (cn.z < 1) cn.z = 1;

    for (int _i = 0; _i < (int) cn.x; _i++) {
      p.x = box[0].x + (box[1].x - box[0].x)/cn.x*(_i + 0.5);
      for (int _j = 0; _j < (int) cn.y; _j++) {
 p.y = box[0].y + (box[1].y - box[0].y)/cn.y*(_j + 0.5);
 for (int _k = 0; _k < (int) cn.z; _k++) {
   p.z = box[0].z + (box[1].z - box[0].z)/cn.z*(_k + 0.5);
   Point point = locate (p.x, p.y, p.z);
   if (point.level >= 0) {
     int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);

  

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    int i = (p.x - box[0].x)/(box[1].x - box[0].x)*cn.x;
    int j = (p.y - box[0].y)/(box[1].y - box[0].y)*cn.y;
    double ** alias = ppm;
    alias[i][j] = linear ? interpolate_linear (point, f, p.x, p.y, p.z) : val(f,0,0,0);
  }}   

}
 }
      }
    }
  }
}

  

if (pid() == 0) {
    if (file) {
      fp = fopen (file, "wb");
      if (!fp) {
 perror (file);
 exit (1);
      }
    }
    float fn = cn.y;
    fwrite (&fn, sizeof(float), 1, fp);
    coord delta = {(box[1].x - box[0].x)/cn.x, (box[1].y - box[0].y)/cn.y};
    for (int j = 0; j < cn.y; j++) {
      float yp = box[0].y + delta.y*(j + 0.5);
      fwrite (&yp, sizeof(float), 1, fp);
    }
    for (int i = 0; i < cn.x; i++) {
      float xp = box[0].x + delta.x*(i + 0.5);
      fwrite (&xp, sizeof(float), 1, fp);
      for (int j = 0; j < cn.y; j++) {
 float z = ppm[i][j];
 fwrite (&z, sizeof(float), 1, fp);
      }
    }
    if (file)
      fclose (fp);
    else
      fflush (fp);
  }

  matrix_free (ppm);
end_tracing("output_matrix","/home/jacqhugo/basilisk/src/output.h",0);}

typedef void (* Colormap) (double cmap[127][3]);

void jet (double cmap[127][3])
{
  for (int i = 0; i < 127; i++) {
    cmap[i][0] =
      i <= 46 ? 0. :
      i >= 111 ? -0.03125*(i - 111) + 1. :
      i >= 78 ? 1. :
      0.03125*(i - 46);
    cmap[i][1] =
      i <= 14 || i >= 111 ? 0. :
      i >= 79 ? -0.03125*(i - 111) :
      i <= 46 ? 0.03125*(i - 14) :
      1.;
    cmap[i][2] =
      i >= 79 ? 0. :
      i >= 47 ? -0.03125*(i - 79) :
      i <= 14 ? 0.03125*(i - 14) + 1.:
      1.;
  }
}

void cool_warm (double cmap[127][3])
{






  static double basemap[33][3] = {
    {0.2298057, 0.298717966, 0.753683153},
    {0.26623388, 0.353094838, 0.801466763},
    {0.30386891, 0.406535296, 0.84495867},
    {0.342804478, 0.458757618, 0.883725899},
    {0.38301334, 0.50941904, 0.917387822},
    {0.424369608, 0.558148092, 0.945619588},
    {0.46666708, 0.604562568, 0.968154911},
    {0.509635204, 0.648280772, 0.98478814},
    {0.552953156, 0.688929332, 0.995375608},
    {0.596262162, 0.726149107, 0.999836203},
    {0.639176211, 0.759599947, 0.998151185},
    {0.681291281, 0.788964712, 0.990363227},
    {0.722193294, 0.813952739, 0.976574709},
    {0.761464949, 0.834302879, 0.956945269},
    {0.798691636, 0.849786142, 0.931688648},
    {0.833466556, 0.860207984, 0.901068838},
    {0.865395197, 0.86541021, 0.865395561},
    {0.897787179, 0.848937047, 0.820880546},
    {0.924127593, 0.827384882, 0.774508472},
    {0.944468518, 0.800927443, 0.726736146},
    {0.958852946, 0.769767752, 0.678007945},
    {0.96732803, 0.734132809, 0.628751763},
    {0.969954137, 0.694266682, 0.579375448},
    {0.966811177, 0.650421156, 0.530263762},
    {0.958003065, 0.602842431, 0.481775914},
    {0.943660866, 0.551750968, 0.434243684},
    {0.923944917, 0.49730856, 0.387970225},
    {0.89904617, 0.439559467, 0.343229596},
    {0.869186849, 0.378313092, 0.300267182},
    {0.834620542, 0.312874446, 0.259301199},
    {0.795631745, 0.24128379, 0.220525627},
    {0.752534934, 0.157246067, 0.184115123},
    {0.705673158, 0.01555616, 0.150232812}
  };

  for (int i = 0; i < 127; i++) {
    double x = i*(32 - 1e-10)/(127 - 1);
    int j = x; x -= j;
    for (int k = 0; k < 3; k++)
      cmap[i][k] = (1. - x)*basemap[j][k] + x*basemap[j+1][k];
  }
}

void gray (double cmap[127][3])
{
  for (int i = 0; i < 127; i++)
    for (int k = 0; k < 3; k++)
      cmap[i][k] = i/(127 - 1.);
}

void randomap (double cmap[127][3])
{
  srand(0);
  for (int i = 0; i < 127; i++)
    for (int k = 0; k < 3; k++)
      cmap[i][k] = (noise() + 1.)/2.;
}

void blue_white_red (double cmap[127][3])
{
  for (int i = 0; i < (127 + 1)/2; i++) {
    cmap[i][0] = i/((127 - 1)/2.);
    cmap[i][1] = i/((127 - 1)/2.);
    cmap[i][2] = 1.;
  }
  for (int i = 0; i < (127 - 1)/2; i++) {
    cmap[i + (127 + 1)/2][0] = 1.;
    cmap[i + (127 + 1)/2][1] = cmap[(127 - 3)/2 - i][1];
    cmap[i + (127 + 1)/2][2] = cmap[(127 - 3)/2 - i][1];
  }
}





typedef struct {
  unsigned char r, g, b;
} Color;

Color colormap_color (double cmap[127][3],
        double val, double min, double max)
{
  Color c;
  if (val == 1e30f) {
    c.r = c.g = c.b = 0;
    return c;
  }
  int i;
  double coef;
  if (max != min)
    val = (val - min)/(max - min);
  else
    val = 0.;
  if (val <= 0.) i = 0, coef = 0.;
  else if (val >= 1.) i = 127 - 2, coef = 1.;
  else {
    i = val*(127 - 1);
    coef = val*(127 - 1) - i;
  }
  if (i < 0 || i >= 127 - 1)
    return (Color){99,55,43};
  unsigned char * c1 = (unsigned char *) &c;
  for (int j = 0; j < 3; j++)
    c1[j] = 255*(cmap[i][j]*(1. - coef) + cmap[i + 1][j]*coef);
  return c;
}

static const char * extension (const char * file, const char * ext) {
  int len = strlen(file);
  return len > 4 && !strcmp (file + len - 4, ext) ? file + len - 4 : NULL;
}

static const char * is_animation (const char * file) {
  const char * ext;
  if ((ext = extension (file, ".mp4")) ||
      (ext = extension (file, ".ogv")) ||
      (ext = extension (file, ".gif")))
    return ext;
  return NULL;
}

static struct {
  FILE ** fp;
  char ** names;
  int n;
} open_image_data = {NULL, NULL, 0};

static void open_image_cleanup()
{
  for (int i = 0; i < open_image_data.n; i++) {
    qpclose (open_image_data.fp[i]);
    pfree (open_image_data.names[i],__func__,__FILE__,0);
  }
  pfree (open_image_data.fp,__func__,__FILE__,0);
  pfree (open_image_data.names,__func__,__FILE__,0);
  open_image_data.fp = NULL;
  open_image_data.names = NULL;
  open_image_data.n = 0;
}

static FILE * open_image_lookup (const char * file)
{
  for (int i = 0; i < open_image_data.n; i++)
    if (!strcmp (file, open_image_data.names[i]))
      return open_image_data.fp[i];
  return NULL;
}

static bool which (const char * command)
{
  char * s = getenv ("PATH");
  if (!s)
    return false;
  char path[strlen(s) + 1];
  strcpy (path, s);
  s = strtok (path, ":");
  while (s) {
    char f[strlen(s) + strlen(command) + 2];
    strcpy (f, s);
    strcat (f, "/");
    strcat (f, command);
    FILE * fp = fopen (f, "r");
    if (fp) {
      fclose (fp);
      return true;
    }
    s = strtok (NULL, ":");
  }
  return false;
}

static FILE * ppm_fallback (const char * file, const char * mode)
{
  char filename[strlen(file) + 5];
  strcpy (filename, file);
  strcat (filename, ".ppm");
  FILE * fp = fopen (filename, mode);
  if (!fp) {
    perror (file);



    exit (1);
  }
  return fp;
}

FILE * open_image (const char * file, const char * options)
{
#if __EMSCRIPTEN__
  return ppm_fallback (file, "w");
#else
  if (!(pid() == 0)) qassert ("/home/jacqhugo/basilisk/src/output.h", 0, "pid() == 0");
  const char * ext;
  if ((ext = is_animation (file))) {
    FILE * fp = open_image_lookup (file);
    if (fp)
      return fp;

    int len = strlen ("ppm2???    ") + strlen (file) +
      (options ? strlen (options) : 0);
    char command[len + 1];
    strcpy (command, "ppm2"); strcat (command, ext + 1);

    static int has_ffmpeg = -1;
    if (has_ffmpeg < 0) {
      if (which (command) && (which ("ffmpeg") || which ("avconv")))
 has_ffmpeg = true;
      else {
 fprintf (ferr,
   "src/output.h:%d: warning: cannot find '%s' or 'ffmpeg'/'avconv'\n"
   "src/output.h:%d: warning: falling back to raw PPM outputs\n",
   0, command, 0);
 has_ffmpeg = false;
      }
    }
    if (!has_ffmpeg)
      return ppm_fallback (file, "a");

    static bool added = false;
    if (!added) {
      free_solver_func_add (open_image_cleanup);
      added = true;
    }
    open_image_data.n++;
    open_image_data.names = (char * *) prealloc (open_image_data.names, (open_image_data.n)*sizeof(char *),__func__,__FILE__,0);
    open_image_data.names[open_image_data.n - 1] = pstrdup (file,__func__,__FILE__,0);

    if (options) {
      strcat (command, " ");
      strcat (command, options);
    }
    strcat (command, !strcmp (ext, ".mp4") ? " " : " > ");
    strcat (command, file);
    open_image_data.fp = (FILE * *) prealloc (open_image_data.fp, (open_image_data.n)*sizeof(FILE *),__func__,__FILE__,0);
    return open_image_data.fp[open_image_data.n - 1] = qpopen (command, "w");
  }
  else {
    static int has_convert = -1;
    if (has_convert < 0) {
      if (which ("convert"))
 has_convert = true;
      else {
 fprintf (ferr,
   "src/output.h:%d: warning: cannot find 'convert'\n"
   "src/output.h:%d: warning: falling back to raw PPM outputs\n",
   0, 0);
 has_convert = false;
      }
    }
    if (!has_convert)
      return ppm_fallback (file, "w");

    int len = strlen ("convert ppm:-   ") + strlen (file) +
      (options ? strlen (options) : 0);
    char command[len];
    strcpy (command, "convert ppm:- ");
    if (options) {
      strcat (command, options);
      strcat (command, " ");
    }
    strcat (command, file);
    return qpopen (command, "w");
  }
#endif
}

void close_image (const char * file, FILE * fp)
{
  if (!(pid() == 0)) qassert ("/home/jacqhugo/basilisk/src/output.h", 0, "pid() == 0");
  if (is_animation (file)) {
    if (!open_image_lookup (file))
      fclose (fp);
  }
#if !__EMSCRIPTEN__
  else if (which ("convert"))
    qpclose (fp);
#endif
  else
    fclose (fp);
}

     
void output_ppm (scalar f,
   FILE * fp,
   int n,
   char * file,
   double min, double max, double spread,
   double z,
   bool linear,
   coord box[2],
   scalar mask,
   Colormap map,
   char * opt,
   int fps,
   FILE * checksum)
{tracing("output_ppm","/home/jacqhugo/basilisk/src/output.h",0);

  if (!min && !max) {
    stats s = statsf (f);
    if (spread < 0.)
      min = s.min, max = s.max;
    else {
      double avg = s.sum/s.volume;
      min = avg - spread*s.stddev; max = avg + spread*s.stddev;
    }
  }
  box[0].z = z, box[1].z = z;

  coord cn = {n}, p;
  double delta = (box[1].x - box[0].x)/n;
  cn.y = (int)((box[1].y - box[0].y)/delta);
  if (((int)cn.y) % 2) cn.y++;

  Color ** ppm = (Color **) matrix_new (cn.y, cn.x, sizeof(Color));
  unsigned char * ppm0 = &ppm[0][0].r;
  int len = 3*cn.x*cn.y;
  memset (ppm0, 0, len*sizeof (unsigned char));
  double cmap[127][3];
  (* map) (cmap);  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/output.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

  

{ 
    
    if (mask.i >= 0) {
      if (linear) {  
  _stencil_interpolate_linear (point, mask, NULL, NULL, NULL);
{ 
    
   
{ _stencil_interpolate_linear (point, f, NULL, NULL, NULL); }}      
}
      else {
_stencil_val(mask,0,0,0);{
     
   
{ _stencil_val(f,0,0,0); }}      
}
    }
    else if (linear)
      { _stencil_interpolate_linear (point, f, NULL, NULL, NULL); }
    else
      { _stencil_val(f,0,0,0); }                  
    
    
         
         
  }    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  {
    if (cn.x < 1) cn.x = 1;
    if (cn.y < 1) cn.y = 1;
    if (cn.z < 1) cn.z = 1;

    for (int _i = 0; _i < (int) cn.x; _i++) {
      p.x = box[0].x + (box[1].x - box[0].x)/cn.x*(_i + 0.5);
      for (int _j = 0; _j < (int) cn.y; _j++) {
 p.y = box[0].y + (box[1].y - box[0].y)/cn.y*(_j + 0.5);
 for (int _k = 0; _k < (int) cn.z; _k++) {
   p.z = box[0].z + (box[1].z - box[0].z)/cn.z*(_k + 0.5);
   Point point = locate (p.x, p.y, p.z);
   if (point.level >= 0) {
     int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);

  

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double v;
    if (mask.i >= 0) {
      if (linear) {
 double m = interpolate_linear (point, mask, p.x, p.y, p.z);
 if (m < 0.)
   v = 1e30f;
 else
   v = interpolate_linear (point, f, p.x, p.y, p.z);
      }
      else {
 if (val(mask,0,0,0) < 0.)
   v = 1e30f;
 else
   v = val(f,0,0,0);
      }
    }
    else if (linear)
      v = interpolate_linear (point, f, p.x, p.y, p.z);
    else
      v = val(f,0,0,0);
    int i = (p.x - box[0].x)/(box[1].x - box[0].x)*cn.x;
    int j = (p.y - box[0].y)/(box[1].y - box[0].y)*cn.y;
    Color ** alias = ppm;
    alias[(int)cn.y - 1 - j][i] = colormap_color (cmap, v, min, max);
  }}   

}
 }
      }
    }
  }
}

  

if (pid() == 0) {
    if (file)
      fp = open_image (file, opt);

    fprintf (fp, "P6\n%g %g 255\n", cn.x, cn.y);
    fwrite (ppm0, sizeof(unsigned char), 3*cn.x*cn.y, fp);

    if (file)
      close_image (file, fp);
    else
      fflush (fp);

    if (checksum) {
      Adler32Hash hash;
      a32_hash_init (&hash);
      a32_hash_add (&hash, ppm0, sizeof(unsigned char)*3*cn.x*cn.y);
      fputs ("# ", checksum);
      if (file)
 fprintf (checksum, "%s: ", file);
      fprintf (checksum, "checksum: %08lx\n", (unsigned long) a32_hash (&hash));
    }
  }

  matrix_free (ppm);
end_tracing("output_ppm","/home/jacqhugo/basilisk/src/output.h",0);}

     
void output_grd (scalar f,
   FILE * fp,
   double Delta,
   bool linear,
   coord box[2],
   scalar mask)
{tracing("output_grd","/home/jacqhugo/basilisk/src/output.h",0);
  int nx = (box[1].x - box[0].x)/Delta;
  int ny = (box[1].y - box[0].y)/Delta;


  fprintf (fp, "ncols          %d\n", nx);
  fprintf (fp, "nrows          %d\n", ny);
  fprintf (fp, "xllcorner      %g\n", box[0].x);
  fprintf (fp, "yllcorner      %g\n", box[0].y);
  fprintf (fp, "cellsize       %g\n", Delta);
  fprintf (fp, "nodata_value   -9999\n");


  for (int j = ny-1; j >= 0; j--) {
    double yp = Delta*j + box[0].y + Delta/2.;
    for (int i = 0; i < nx; i++) {
      double xp = Delta*i + box[0].x + Delta/2., v;
      if (mask.i >= 0) {
 double m = interpolate (mask, xp, yp

, 0.

, linear);
 if (m < 0.)
   v = 1e30f;
 else
   v = interpolate (f, xp, yp

, 0.

, linear);
      }
      else
 v = interpolate (f, xp, yp

, 0.

, linear);
      if (v == 1e30f)
 fprintf (fp, "-9999 ");
      else
 fprintf (fp, "%f ", v);
    }
    fprintf (fp, "\n");
  }

  fflush (fp);
end_tracing("output_grd","/home/jacqhugo/basilisk/src/output.h",0);}

static char * replace (const char * input, int target, int with,
         bool translate)
{
  if (translate) {
    if (!strcmp (input, "u.x"))
      return pstrdup ("U",__func__,__FILE__,0);
    if (!strcmp (input, "u.y"))
      return pstrdup ("V",__func__,__FILE__,0);
    if (!strcmp (input, "u.z"))
      return pstrdup ("W",__func__,__FILE__,0);
  }
  char * name = pstrdup (input,__func__,__FILE__,0), * i = name;
  while (*i != '\0') {
    if (*i == target)
      *i = with;
    i++;
  }
  return name;
}

     
void output_gfs (FILE * fp,
   scalar * list,
   char * file,
   bool translate)
{tracing("output_gfs","/home/jacqhugo/basilisk/src/output.h",0);
  char * fname = file;

  bool opened = false;
  if (fp == NULL) {
    if (fname == NULL)
      fp = fout;
    else if (!(fp = fopen (fname, "w"))) {
      perror (fname);
      exit (1);
    }
    else
      opened = true;
  }

  scalar * slist = list ? list : list_copy (all);

  restriction (slist);
  fprintf (fp,
    "1 0 GfsSimulation GfsBox GfsGEdge { binary = 1"
    " x = %g y = %g ",
    0.5 + X0/L0, 0.5 + Y0/L0);




  if (slist != NULL && slist[0].i != -1) {
    scalar s = slist[0];
    char * name = replace (_attribute[s.i].name, '.', '_', translate);
    fprintf (fp, "variables = %s", name);
    pfree (name,__func__,__FILE__,0);
    for (int i = 1; i < list_len(slist); i++) {
      scalar s = slist[i];
      if (_attribute[s.i].name) {
 char * name = replace (_attribute[s.i].name, '.', '_', translate);
 fprintf (fp, ",%s", name);
 pfree (name,__func__,__FILE__,0);
      }
    }
    fprintf (fp, " ");
  }
  fprintf (fp, "} {\n");
  fprintf (fp, "  Time { t = %g }\n", t);
  if (L0 != 1.)
    fprintf (fp, "  PhysicalParams { L = %g }\n", L0);
  fprintf (fp, "  VariableTracerVOF f\n");
  fprintf (fp, "}\nGfsBox { x = 0 y = 0 z = 0 } {\n");

{
  if (!Dimensions.x) Dimensions.x = 1;
  if (!Dimensions.y) Dimensions.y = 1;
  for (int ox = 0; ox < Dimensions.x; ox++)
    for (int oy = 0; oy < Dimensions.y; oy++) {
      Point root = {2 + ox, 2 + oy, 0};

{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};



    struct { int l, i, j, stage; } stack[20];




    int _s = -1;
    { _s++; stack[_s].l = root.level; stack[_s].i = root.i; stack[_s].j = root.j; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; point.j = stack[_s].j; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{



    {






      unsigned flags =
 level == 0 ? 0 :



      child.x == -1 && child.y == -1 ? 0 :
 child.x == -1 && child.y == 1 ? 1 :
 child.x == 1 && child.y == -1 ? 2 :
 3;

      if (is_leaf(cell))
 flags |= (1 << 4);
      fwrite (&flags, sizeof (unsigned), 1, fp);
      double a = -1;
      fwrite (&a, sizeof (double), 1, fp);
      {scalar*_i=(scalar*)( slist);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
 if (_attribute[s.i].name) {
   if (_attribute[s.i].v.x.i >= 0) {




     if (_attribute[s.i].v.x.i == s.i) {
       s = _attribute[s.i].v.y;
       a = is_local(cell) && val(s,0,0,0) != 1e30f ? val(s,0,0,0) : (double) DBL_MAX;
     }
     else if (_attribute[s.i].v.y.i == s.i) {
       s = _attribute[s.i].v.x;
       a = is_local(cell) && val(s,0,0,0) != 1e30f ? - val(s,0,0,0) : (double) DBL_MAX;
     }





   }
   else
     a = is_local(cell) && val(s,0,0,0) != 1e30f ? val(s,0,0,0) : (double) DBL_MAX;
   fwrite (&a, sizeof (double), 1, fp);
 }}}
    }
    if (is_leaf(cell))
      continue;
  }} 

if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; };
 }
 break;
      }



      case 1: { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 2; };
 { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; }; break;
      case 2: { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 3; };
 { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; }; break;
      case 3: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; }; break;

      }
    }
  }
}
    

}
}

    fputs ("}\n", fp);
  fflush (fp);

  if (!list)
    pfree (slist,__func__,__FILE__,0);
  if (opened)
    fclose (fp);

end_tracing("output_gfs","/home/jacqhugo/basilisk/src/output.h",0);}

struct DumpHeader {
  double t;
  long len;
  int i, depth, npe, version;
  coord n;
};

static const int dump_version =

  170901;

static scalar * dump_list (scalar * lista, bool zero)
{
  scalar * list = is_constant(cm) ? NULL : list_concat (((scalar[]){cm,{-1}}), NULL);




  scalar * listb = list_copy (lista);

  {scalar*_i=(scalar*)( listb);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!_attribute[s.i].face && !_attribute[s.i].nodump && s.i != cm.i) {
      if (zero)
 list = list_add (list, s);
      else {
 stats ss = statsf (s);
 if (ss.min != 0. || ss.max != 0.)
   list = list_add (list, s);
      }
    }}}
  pfree (listb,__func__,__FILE__,0);
  return list;
}

static void dump_header (FILE * fp, struct DumpHeader * header, scalar * list)
{
  if (fwrite (header, sizeof(struct DumpHeader), 1, fp) < 1) {
    perror ("dump(): error while writing header");
    exit (1);
  }
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
    unsigned len = strlen(_attribute[s.i].name);
    if (fwrite (&len, sizeof(unsigned), 1, fp) < 1) {
      perror ("dump(): error while writing len");
      exit (1);
    }
    if (fwrite (_attribute[s.i].name, sizeof(char), len, fp) < len) {
      perror ("dump(): error while writing s.name");
      exit (1);
    }
  }}}
  double o[4] = {X0,Y0,Z0,L0};
  if (fwrite (o, sizeof(double), 4, fp) < 4) {
    perror ("dump(): error while writing coordinates");
    exit (1);
  }
}


     
void dump (const char * file,
    scalar * list,
    FILE * fp,
    bool unbuffered,
    bool zero)
{tracing("dump","/home/jacqhugo/basilisk/src/output.h",0);
  char * name = NULL;
  if (!fp) {
    name = (char *) pmalloc (strlen(file) + 2,__func__,__FILE__,0);
    strcpy (name, file);
    if (!unbuffered)
      strcat (name, "~");
    if ((fp = fopen (name, "w")) == NULL) {
      perror (name);
      exit (1);
    }
  }
  if (!(fp)) qassert ("/home/jacqhugo/basilisk/src/output.h", 0, "fp");

  scalar * dlist = dump_list (list, zero);
  scalar  size=new_scalar("size");
  scalar * slist = list_concat (((scalar[]){size,{-1}}), dlist); pfree (dlist,__func__,__FILE__,0);
  struct DumpHeader header = { t, list_len(slist), iter, depth(), npe(),
          dump_version };
  int npe = 1;
   {
    header.n.x = Dimensions.x;
    npe *= header.n.x;
  } 

{
    header.n.y = Dimensions.y;
    npe *= header.n.y;
  }
  header.npe = npe;
  dump_header (fp, &header, slist);

  subtree_size (size, false);

{
  if (!Dimensions.x) Dimensions.x = 1;
  if (!Dimensions.y) Dimensions.y = 1;
  for (int ox = 0; ox < Dimensions.x; ox++)
    for (int oy = 0; oy < Dimensions.y; oy++) {
      Point root = {2 + ox, 2 + oy, 0};

{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};



    struct { int l, i, j, stage; } stack[20];




    int _s = -1;
    { _s++; stack[_s].l = root.level; stack[_s].i = root.i; stack[_s].j = root.j; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; point.j = stack[_s].j; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    unsigned flags = is_leaf(cell) ? leaf : 0;
    if (fwrite (&flags, sizeof(unsigned), 1, fp) < 1) {
      perror ("dump(): error while writing flags");
      exit (1);
    }
    {scalar*_i=(scalar*)( slist);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
      double val = val(s,0,0,0);
      if (fwrite (&val, sizeof(double), 1, fp) < 1) {
 perror ("dump(): error while writing scalars");
 exit (1);
      }
    }}}
    if (is_leaf(cell))
      continue;
  }} 

if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; };
 }
 break;
      }



      case 1: { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 2; };
 { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; }; break;
      case 2: { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 3; };
 { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; }; break;
      case 3: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; }; break;

      }
    }
  }
}
    

}
}

  

pfree (slist,__func__,__FILE__,0);
  if (file) {
    fclose (fp);
    if (!unbuffered)
      rename (name, file);
    pfree (name,__func__,__FILE__,0);
  }delete((scalar*)((scalar[]){size,{-1}}));
end_tracing("dump","/home/jacqhugo/basilisk/src/output.h",0);}

     
bool restore (const char * file,
       scalar * list,
       FILE * fp)
{tracing("restore","/home/jacqhugo/basilisk/src/output.h",0);
  if (!fp && (fp = fopen (file, "r")) == NULL)
    {end_tracing("restore","/home/jacqhugo/basilisk/src/output.h",0);return false;}
  if (!(fp)) qassert ("/home/jacqhugo/basilisk/src/output.h", 0, "fp");

  struct DumpHeader header = {0};
  if (fread (&header, sizeof(header), 1, fp) < 1) {
    fprintf (ferr, "restore(): error: expecting header\n");
    exit (1);
  }

  dimensions (header.n.x, header.n.y, header.n.z);
  double n = header.n.x;
  int depth = header.depth;
  while (n > 1)
    depth++, n /= 2;
  init_grid (1 << depth);


  bool restore_all = (list == all);
  scalar * slist = dump_list (list ? list : all, true);
  if (header.version == 161020) {
    if (header.len - 1 != list_len (slist)) {
      fprintf (ferr,
        "restore(): error: the list lengths don't match: "
        "%ld (file) != %d (code)\n",
        header.len - 1, list_len (slist));
      exit (1);
    }
  }
  else {
    if (header.version != dump_version) {
      fprintf (ferr,
        "restore(): error: file version mismatch: "
        "%d (file) != %d (code)\n",
        header.version, dump_version);
      exit (1);
    }

    scalar * input = NULL;
    for (int i = 0; i < header.len; i++) {
      unsigned len;
      if (fread (&len, sizeof(unsigned), 1, fp) < 1) {
 fprintf (ferr, "restore(): error: expecting len\n");
 exit (1);
      }
      char name[len + 1];
      if (fread (name, sizeof(char), len, fp) < 1) {
 fprintf (ferr, "restore(): error: expecting s.name\n");
 exit (1);
      }
      name[len] = '\0';

      if (i > 0) {
 bool found = false;
 {scalar*_i=(scalar*)( slist);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
   if (!strcmp (_attribute[s.i].name, name)) {
     input = list_append (input, s);
     found = true; break;
   }}}
 if (!found) {
   if (restore_all) {
     scalar s = new_scalar("s");
     pfree (_attribute[s.i].name,__func__,__FILE__,0);
     _attribute[s.i].name = pstrdup (name,__func__,__FILE__,0);
     input = list_append (input, s);
   }
   else
     input = list_append (input, (scalar){INT_MAX});
 }
      }
    }
    pfree (slist,__func__,__FILE__,0);
    slist = input;

    double o[4];
    if (fread (o, sizeof(double), 4, fp) < 4) {
      fprintf (ferr, "restore(): error: expecting coordinates\n");
      exit (1);
    }
    origin (o[0], o[1], o[2]);
    size (o[3]);
  }

  scalar * listm = is_constant(cm) ? NULL : (scalar *)((vector[]){fm,{{-1},{-1}}});




  int rootlevel = 0;

{
  if (!(

header.n

).x) (

header.n

).x = 1;
  if (!(

header.n

).y) (

header.n

).y = 1;
  for (int ox = 0; ox < (

header.n

).x; ox++)
    for (int oy = 0; oy < (

header.n

).y; oy++) {
      Point root = {2 + ox, 2 + oy, rootlevel};

{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};



    struct { int l, i, j, stage; } stack[20];




    int _s = -1;
    { _s++; stack[_s].l = root.level; stack[_s].i = root.i; stack[_s].j = root.j; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; point.j = stack[_s].j; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{

    unsigned flags;
    if (fread (&flags, sizeof(unsigned), 1, fp) != 1) {
      fprintf (ferr, "restore(): error: expecting 'flags'\n");
      exit (1);
    }

    fseek (fp, sizeof(double), SEEK_CUR);
    {scalar*_i=(scalar*)( slist);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
      double val;
      if (fread (&val, sizeof(double), 1, fp) != 1) {
 fprintf (ferr, "restore(): error: expecting a scalar\n");
 exit (1);
      }
      if (s.i != INT_MAX)
 val(s,0,0,0) = isfinite(val) ? val : 1e30f;
    }}}
    if (!(flags & leaf) && is_leaf(cell))
      refine_cell (point, listm, 0, NULL);
    if (is_leaf(cell))
      continue;
  }} 

if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; };
 }
 break;
      }



      case 1: { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 2; };
 { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; }; break;
      case 2: { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 3; };
 { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; }; break;
      case 3: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; }; break;

      }
    }
  }
}
    

}
}





  

{scalar*_i=(scalar*)( all);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    set_dirty_stencil (s);}}


  scalar * other = NULL;
  {scalar*_i=(scalar*)( all);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!list_lookup (slist, s) && !list_lookup (listm, s))
      other = list_append (other, s);}}
  reset (other, 0.);
  pfree (other,__func__,__FILE__,0);

  pfree (slist,__func__,__FILE__,0);
  if (file)
    fclose (fp);


  while (iter < header.i && events (false))
    iter = inext;
  events (false);
  while (t < header.t && events (false))
    t = tnext;
  t = header.t;
  events (false);

  {end_tracing("restore","/home/jacqhugo/basilisk/src/output.h",0);return true;}
end_tracing("restore","/home/jacqhugo/basilisk/src/output.h",0);}



scalar  zb={0}, eta, h;
vector u;
double G = 1., CFL_H = 1e40;



double dry = 1e-12;

double (* gradient) (double, double, double) = minmod2;

scalar * tracers = NULL, eta_r;
bool linearised = false;

static int defaults0_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i = 0)!=0;*ip=i;*tp=t;return ret;}

      static int defaults0(const int i,const double t,Event *_ev){tracing("defaults0","/home/jacqhugo/basilisk/src/layered/hydro.h",0);
{
  if (!(nl > 0)) qassert ("/home/jacqhugo/basilisk/src/layered/hydro.h", 0, "nl > 0");
  h = new_block_scalar("h","",nl);
  _attribute[h.i].gradient = gradient;





  eta_r = eta = new_scalar("eta");
  reset (((scalar[]){h, zb,{-1}}), 0.);




  _attribute[zb.i].gradient = gradient;
  _attribute[eta.i].gradient = gradient;

}{end_tracing("defaults0","/home/jacqhugo/basilisk/src/layered/hydro.h",0);return 0;}end_tracing("defaults0","/home/jacqhugo/basilisk/src/layered/hydro.h",0);}




double dt = 1.;




     
void run (void)
{tracing("run","/home/jacqhugo/basilisk/src/run.h",0);
  iter = 0, t = 0., dt = 1.;
  init_grid (N);

  perf.nc = perf.tnc = 0;
  perf.gt = timer_start();
  while (events (true)) {





    update_perf();
    iter = inext, t = tnext;
  }




  timer_print (perf.gt, iter, perf.tnc);

  free_grid();
end_tracing("run","/home/jacqhugo/basilisk/src/run.h",0);}




static int defaults_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i = 0)!=0;*ip=i;*tp=t;return ret;}      static int defaults(const int i,const double t,Event *_ev){tracing("defaults","/home/jacqhugo/basilisk/src/run.h",0); {
  display ("box();"

, false

);
}{end_tracing("defaults","/home/jacqhugo/basilisk/src/run.h",0);return 0;}end_tracing("defaults","/home/jacqhugo/basilisk/src/run.h",0);}





static int cleanup_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(t = TEND_EVENT)!=0;*ip=i;*tp=t;return ret;}      static int cleanup(const int i,const double t,Event *_ev){tracing("cleanup","/home/jacqhugo/basilisk/src/run.h",0); {
  display ("", true);
}{end_tracing("cleanup","/home/jacqhugo/basilisk/src/run.h",0);return 0;}end_tracing("cleanup","/home/jacqhugo/basilisk/src/run.h",0);}

static int defaults_0_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i = 0)!=0;*ip=i;*tp=t;return ret;}






      static int defaults_0(const int i,const double t,Event *_ev){tracing("defaults_0","/home/jacqhugo/basilisk/src/layered/hydro.h",0);
{






  CFL = 1./(2.*2);
  if (CFL_H == 1e40)
    CFL_H = 0.5;

  u = new_block_vector("u",nl);
  reset (((vector[]){u,{{-1},{-1}}}), 0.);

  if (!linearised)
    {
      tracers = list_append (tracers, u.x);      tracers = list_append (tracers, u.y);}





  {scalar*_i=(scalar*)( tracers);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
    _attribute[s.i].gradient = gradient;





  }}}




  display ("squares (color = 'eta > zb ? eta : nodata', spread = -1);"

, false

);
}{end_tracing("defaults_0","/home/jacqhugo/basilisk/src/layered/hydro.h",0);return 0;}end_tracing("defaults_0","/home/jacqhugo/basilisk/src/layered/hydro.h",0);}




static int init_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i = 0)!=0;*ip=i;*tp=t;return ret;}      static int init(const int i,const double t,Event *_ev){tracing("init","/home/jacqhugo/basilisk/src/layered/hydro.h",0);
{
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/hydro.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{ 
_stencil_val(zb,0,0,0);    _stencil_val_a(eta,0,0,0);    

for (point.l = 0; point.l < nl; point.l++)
      

{ _stencil_val(h,0,0,0);_stencil_val_r(eta,0,0,0); }  

point.l = 0;

_stencil_val(h,0,0,0);  
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    val(eta,0,0,0) = val(zb,0,0,0);    

for (point.l = 0; point.l < nl; point.l++)
      

val(eta,0,0,0) += val(h,0,0,0);  

point.l = 0;
    

dimensional (val(h,0,0,0) == Delta);
  }}
      

}
  }
}

}{end_tracing("init","/home/jacqhugo/basilisk/src/layered/hydro.h",0);return 0;}end_tracing("init","/home/jacqhugo/basilisk/src/layered/hydro.h",0);}





double dtmax;
static int set_dtmax_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}      static int set_dtmax(const int i,const double t,Event *_ev){tracing("set_dtmax","/home/jacqhugo/basilisk/src/layered/hydro.h",0);{dtmax = DT; }{end_tracing("set_dtmax","/home/jacqhugo/basilisk/src/layered/hydro.h",0);return 0;}end_tracing("set_dtmax","/home/jacqhugo/basilisk/src/layered/hydro.h",0);}

static bool hydrostatic = true;
vector hu, hf, ha;

static int face_fields_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}      static int face_fields(const int i,const double t,Event *_ev){tracing("face_fields","/home/jacqhugo/basilisk/src/layered/hydro.h",0);
{
  hu = new_block_face_vector("hu",nl);
  hf = new_block_face_vector("hf",nl);
  ha = new_block_face_vector("ha",nl);







  static double pdt = 0.;
if(!is_constant(fm.x) && !is_constant(cm)){
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/hydro.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0 -1,0,0); _stencil_val(cm,0 -1,0,0);_stencil_val(cm,0,0,0);_stencil_val(fm.x,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{ 
_stencil_val(h,0,0,0); _stencil_val(h,-1,0,0);       





_stencil_val(h,-1,0,0); _stencil_val(h,-1,0,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);
_stencil_val(u.x,-1,0,0);_stencil_val(u.x,0,0,0);      _stencil_val_a(hu.x,0,0,0);                 






      
{
 {_stencil_val(zb,0,0,0); _stencil_val(zb,-1,0,0); _stencil_val(h,0,0,0);        }
{
 {_stencil_val(zb,-1,0,0); _stencil_val(zb,0,0,0); _stencil_val(h,-1,0,0);        } 
{             





 _stencil_val(hu.x,0,0,0);        
         
 
 _stencil_val(h, o_stencil,0,0);_stencil_val(h,o_stencil,0,0);

_stencil_val(h, o_stencil,0,0);_stencil_val(h, o_stencil,0,0);_stencil_val(h,o_stencil,0,0);

_stencil_val(h, o_stencil,0,0);      
}}}       
_stencil_val(fm.x,0,0,0);      _stencil_val_a(hf.x,0,0,0);





_stencil_val(hu.x,0,0,0);
 {_stencil_val(hu.x,0,0,0);  } 

_stencil_val(hf.x,0,0,0);      _stencil_val_r(hu.x,0,0,0); 
_stencil_val(hf.x,0,0,0);      _stencil_val_a(ha.x,0,0,0);  

       
    }  

point.l = 0; 

{         
       
{          
 _stencil_val(fm.x,0,0,0);_stencil_val(cm,-1,0,0);_stencil_val(cm,0,0,0);_stencil_val(cm,-1,0,0);_stencil_val(cm,0,0,0);   
  
    
      }    
}  
} 

_loop.face |= (1 << 1); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0,0 -1,0); _stencil_val(cm,0,0 -1,0);_stencil_val(cm,0,0,0);_stencil_val(fm.y,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{ 
_stencil_val(h,0,0,0); _stencil_val(h,0,-1,0);       





_stencil_val(h,0,-1,0); _stencil_val(h,0,-1,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);
_stencil_val(u.y,0,-1,0);_stencil_val(u.y,0,0,0);      _stencil_val_a(hu.y,0,0,0);                 






      
{
 {_stencil_val(zb,0,0,0); _stencil_val(zb,0,-1,0); _stencil_val(h,0,0,0);        }
{
 {_stencil_val(zb,0,-1,0); _stencil_val(zb,0,0,0); _stencil_val(h,0,-1,0);        } 
{             





 _stencil_val(hu.y,0,0,0);        
         
 
 _stencil_val(h,0, o_stencil,0);_stencil_val(h,0,o_stencil,0);

_stencil_val(h,0, o_stencil,0);_stencil_val(h,0, o_stencil,0);_stencil_val(h,0,o_stencil,0);

_stencil_val(h,0, o_stencil,0);      
}}}       
_stencil_val(fm.y,0,0,0);      _stencil_val_a(hf.y,0,0,0);





_stencil_val(hu.y,0,0,0);
 {_stencil_val(hu.y,0,0,0);  } 

_stencil_val(hf.y,0,0,0);      _stencil_val_r(hu.y,0,0,0); 
_stencil_val(hf.y,0,0,0);      _stencil_val_a(ha.y,0,0,0);  

       
    }  

point.l = 0; 

{         
       
{          
 _stencil_val(fm.y,0,0,0);_stencil_val(cm,0,-1,0);_stencil_val(cm,0,0,0);_stencil_val(cm,0,-1,0);_stencil_val(cm,0,0,0);   
  
    
      }    
}  
}}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL (reduction (min:dtmax)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = (G*(2.*val(fm.x,0,0,0)/(val(cm,0,0,0) + val(cm,0 -1,0,0)))*(val(eta_r,0 -1,0,0) - val(eta_r,0,0,0))/Delta);
    double H = 0., um = 0.;
    double Hr = 0., Hl = 0.;    

for (point.l = 0; point.l < nl; point.l++) 

{
      Hr += val(h,0,0,0), Hl += val(h,-1,0,0);





      double hl = val(h,-1,0,0) > dry ? val(h,-1,0,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      val(hu.x,0,0,0) = hl > 0. || hr > 0. ? (hl*val(u.x,-1,0,0) + hr*val(u.x,0,0,0))/(hl + hr) : 0.;






      double hff;
      if (Hl <= dry)
 hff = fmax (fmin (val(zb,0,0,0) + Hr - val(zb,-1,0,0), val(h,0,0,0)), 0.);
      else if (Hr <= dry)
 hff = fmax (fmin (val(zb,-1,0,0) + Hl - val(zb,0,0,0), val(h,-1,0,0)), 0.);
      else {





 double un = pdt*val(hu.x,0,0,0)/Delta, a = ( (int)(un > 0 ? 1 : -1));
 int i = - (a + 1.)/2.;
 double g = _attribute[h.i].gradient ? _attribute[h.i].gradient (val(h,i-1,0,0), val(h,i,0,0), val(h,i+1,0,0))/Delta :
   (val(h,i+1,0,0) - val(h,i-1,0,0))/(2.*Delta);
 hff = val(h,i,0,0) + a*(1. - a*un)*g*Delta/2.;
      }
      val(hf.x,0,0,0) = val(fm.x,0,0,0)*hff;





      if (fabs(val(hu.x,0,0,0)) > um)
 um = fabs(val(hu.x,0,0,0));

      val(hu.x,0,0,0) *= val(hf.x,0,0,0);
      val(ha.x,0,0,0) = val(hf.x,0,0,0)*ax;

      H += hff;
    }  

point.l = 0;






    

if (H > dry) {
      double c = um/CFL + sqrt(G*(hydrostatic ? H : Delta*tanh(H/Delta)))/CFL_H;
      if (c > 0.) {
 double dt = ( (val(cm,0,0,0)) < (val(cm,-1,0,0)) ? (val(cm,0,0,0)) : (val(cm,-1,0,0)))*Delta/(c*val(fm.x,0,0,0));
 if (dt < dtmax)
   dtmax = dt;
      }
    }
  }}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = (G*(2.*val(fm.y,0,0,0)/(val(cm,0,0,0) + val(cm,0,0 -1,0)))*(val(eta_r,0,0 -1,0) - val(eta_r,0,0,0))/Delta);
    double H = 0., um = 0.;
    double Hr = 0., Hl = 0.;    

for (point.l = 0; point.l < nl; point.l++) 

{
      Hr += val(h,0,0,0), Hl += val(h,0,-1,0);





      double hl = val(h,0,-1,0) > dry ? val(h,0,-1,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      val(hu.y,0,0,0) = hl > 0. || hr > 0. ? (hl*val(u.y,0,-1,0) + hr*val(u.y,0,0,0))/(hl + hr) : 0.;






      double hff;
      if (Hl <= dry)
 hff = fmax (fmin (val(zb,0,0,0) + Hr - val(zb,0,-1,0), val(h,0,0,0)), 0.);
      else if (Hr <= dry)
 hff = fmax (fmin (val(zb,0,-1,0) + Hl - val(zb,0,0,0), val(h,0,-1,0)), 0.);
      else {





 double un = pdt*val(hu.y,0,0,0)/Delta, a = ( (int)(un > 0 ? 1 : -1));
 int i = - (a + 1.)/2.;
 double g = _attribute[h.i].gradient ? _attribute[h.i].gradient (val(h,0,i-1,0), val(h,0,i,0), val(h,0,i+1,0))/Delta :
   (val(h,0,i+1,0) - val(h,0,i-1,0))/(2.*Delta);
 hff = val(h,0,i,0) + a*(1. - a*un)*g*Delta/2.;
      }
      val(hf.y,0,0,0) = val(fm.y,0,0,0)*hff;





      if (fabs(val(hu.y,0,0,0)) > um)
 um = fabs(val(hu.y,0,0,0));

      val(hu.y,0,0,0) *= val(hf.y,0,0,0);
      val(ha.y,0,0,0) = val(hf.y,0,0,0)*ax;

      H += hff;
    }  

point.l = 0;






    

if (H > dry) {
      double c = um/CFL + sqrt(G*(hydrostatic ? H : Delta*tanh(H/Delta)))/CFL_H;
      if (c > 0.) {
 double dt = ( (val(cm,0,0,0)) < (val(cm,0,-1,0)) ? (val(cm,0,0,0)) : (val(cm,0,-1,0)))*Delta/(c*val(fm.y,0,0,0));
 if (dt < dtmax)
   dtmax = dt;
      }
    }
  }}
  

}

}
      

}
  }
}

{mpi_all_reduce_array(&dtmax,MPI_DOUBLE,MPI_MIN,1);}}else if(is_constant(fm.x) && !is_constant(cm)){_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/hydro.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0 -1,0,0); _stencil_val(cm,0 -1,0,0);_stencil_val(cm,0,0,0);;    

for (point.l = 0; point.l < nl; point.l++) 

{ 
_stencil_val(h,0,0,0); _stencil_val(h,-1,0,0);       





_stencil_val(h,-1,0,0); _stencil_val(h,-1,0,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);
_stencil_val(u.x,-1,0,0);_stencil_val(u.x,0,0,0);      _stencil_val_a(hu.x,0,0,0);                 






      
{
 {_stencil_val(zb,0,0,0); _stencil_val(zb,-1,0,0); _stencil_val(h,0,0,0);        }
{
 {_stencil_val(zb,-1,0,0); _stencil_val(zb,0,0,0); _stencil_val(h,-1,0,0);        } 
{             





 _stencil_val(hu.x,0,0,0);        
         
 
 _stencil_val(h, o_stencil,0,0);_stencil_val(h,o_stencil,0,0);

_stencil_val(h, o_stencil,0,0);_stencil_val(h, o_stencil,0,0);_stencil_val(h,o_stencil,0,0);

_stencil_val(h, o_stencil,0,0);      
}}}
;      _stencil_val_a(hf.x,0,0,0);





_stencil_val(hu.x,0,0,0);
 {_stencil_val(hu.x,0,0,0);  } 

_stencil_val(hf.x,0,0,0);      _stencil_val_r(hu.x,0,0,0); 
_stencil_val(hf.x,0,0,0);      _stencil_val_a(ha.x,0,0,0);  

       
    }  

point.l = 0; 

{         
       
{
;_stencil_val(cm,-1,0,0);_stencil_val(cm,0,0,0);_stencil_val(cm,-1,0,0);_stencil_val(cm,0,0,0);   
  
    
      }    
}  
} 

_loop.face |= (1 << 1); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0,0 -1,0); _stencil_val(cm,0,0 -1,0);_stencil_val(cm,0,0,0);;    

for (point.l = 0; point.l < nl; point.l++) 

{ 
_stencil_val(h,0,0,0); _stencil_val(h,0,-1,0);       





_stencil_val(h,0,-1,0); _stencil_val(h,0,-1,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);
_stencil_val(u.y,0,-1,0);_stencil_val(u.y,0,0,0);      _stencil_val_a(hu.y,0,0,0);                 






      
{
 {_stencil_val(zb,0,0,0); _stencil_val(zb,0,-1,0); _stencil_val(h,0,0,0);        }
{
 {_stencil_val(zb,0,-1,0); _stencil_val(zb,0,0,0); _stencil_val(h,0,-1,0);        } 
{             





 _stencil_val(hu.y,0,0,0);        
         
 
 _stencil_val(h,0, o_stencil,0);_stencil_val(h,0,o_stencil,0);

_stencil_val(h,0, o_stencil,0);_stencil_val(h,0, o_stencil,0);_stencil_val(h,0,o_stencil,0);

_stencil_val(h,0, o_stencil,0);      
}}}
;      _stencil_val_a(hf.y,0,0,0);





_stencil_val(hu.y,0,0,0);
 {_stencil_val(hu.y,0,0,0);  } 

_stencil_val(hf.y,0,0,0);      _stencil_val_r(hu.y,0,0,0); 
_stencil_val(hf.y,0,0,0);      _stencil_val_a(ha.y,0,0,0);  

       
    }  

point.l = 0; 

{         
       
{
;_stencil_val(cm,0,-1,0);_stencil_val(cm,0,0,0);_stencil_val(cm,0,-1,0);_stencil_val(cm,0,0,0);   
  
    
      }    
}  
}}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL (reduction (min:dtmax)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = (G*(2.*_const_fm.x/(val(cm,0,0,0) + val(cm,0 -1,0,0)))*(val(eta_r,0 -1,0,0) - val(eta_r,0,0,0))/Delta);
    double H = 0., um = 0.;
    double Hr = 0., Hl = 0.;    

for (point.l = 0; point.l < nl; point.l++) 

{
      Hr += val(h,0,0,0), Hl += val(h,-1,0,0);





      double hl = val(h,-1,0,0) > dry ? val(h,-1,0,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      val(hu.x,0,0,0) = hl > 0. || hr > 0. ? (hl*val(u.x,-1,0,0) + hr*val(u.x,0,0,0))/(hl + hr) : 0.;






      double hff;
      if (Hl <= dry)
 hff = fmax (fmin (val(zb,0,0,0) + Hr - val(zb,-1,0,0), val(h,0,0,0)), 0.);
      else if (Hr <= dry)
 hff = fmax (fmin (val(zb,-1,0,0) + Hl - val(zb,0,0,0), val(h,-1,0,0)), 0.);
      else {





 double un = pdt*val(hu.x,0,0,0)/Delta, a = ( (int)(un > 0 ? 1 : -1));
 int i = - (a + 1.)/2.;
 double g = _attribute[h.i].gradient ? _attribute[h.i].gradient (val(h,i-1,0,0), val(h,i,0,0), val(h,i+1,0,0))/Delta :
   (val(h,i+1,0,0) - val(h,i-1,0,0))/(2.*Delta);
 hff = val(h,i,0,0) + a*(1. - a*un)*g*Delta/2.;
      }
      val(hf.x,0,0,0) = _const_fm.x*hff;





      if (fabs(val(hu.x,0,0,0)) > um)
 um = fabs(val(hu.x,0,0,0));

      val(hu.x,0,0,0) *= val(hf.x,0,0,0);
      val(ha.x,0,0,0) = val(hf.x,0,0,0)*ax;

      H += hff;
    }  

point.l = 0;






    

if (H > dry) {
      double c = um/CFL + sqrt(G*(hydrostatic ? H : Delta*tanh(H/Delta)))/CFL_H;
      if (c > 0.) {
 double dt = ( (val(cm,0,0,0)) < (val(cm,-1,0,0)) ? (val(cm,0,0,0)) : (val(cm,-1,0,0)))*Delta/(c*_const_fm.x);
 if (dt < dtmax)
   dtmax = dt;
      }
    }
  }}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = (G*(2.*_const_fm.y/(val(cm,0,0,0) + val(cm,0,0 -1,0)))*(val(eta_r,0,0 -1,0) - val(eta_r,0,0,0))/Delta);
    double H = 0., um = 0.;
    double Hr = 0., Hl = 0.;    

for (point.l = 0; point.l < nl; point.l++) 

{
      Hr += val(h,0,0,0), Hl += val(h,0,-1,0);





      double hl = val(h,0,-1,0) > dry ? val(h,0,-1,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      val(hu.y,0,0,0) = hl > 0. || hr > 0. ? (hl*val(u.y,0,-1,0) + hr*val(u.y,0,0,0))/(hl + hr) : 0.;






      double hff;
      if (Hl <= dry)
 hff = fmax (fmin (val(zb,0,0,0) + Hr - val(zb,0,-1,0), val(h,0,0,0)), 0.);
      else if (Hr <= dry)
 hff = fmax (fmin (val(zb,0,-1,0) + Hl - val(zb,0,0,0), val(h,0,-1,0)), 0.);
      else {





 double un = pdt*val(hu.y,0,0,0)/Delta, a = ( (int)(un > 0 ? 1 : -1));
 int i = - (a + 1.)/2.;
 double g = _attribute[h.i].gradient ? _attribute[h.i].gradient (val(h,0,i-1,0), val(h,0,i,0), val(h,0,i+1,0))/Delta :
   (val(h,0,i+1,0) - val(h,0,i-1,0))/(2.*Delta);
 hff = val(h,0,i,0) + a*(1. - a*un)*g*Delta/2.;
      }
      val(hf.y,0,0,0) = _const_fm.y*hff;





      if (fabs(val(hu.y,0,0,0)) > um)
 um = fabs(val(hu.y,0,0,0));

      val(hu.y,0,0,0) *= val(hf.y,0,0,0);
      val(ha.y,0,0,0) = val(hf.y,0,0,0)*ax;

      H += hff;
    }  

point.l = 0;






    

if (H > dry) {
      double c = um/CFL + sqrt(G*(hydrostatic ? H : Delta*tanh(H/Delta)))/CFL_H;
      if (c > 0.) {
 double dt = ( (val(cm,0,0,0)) < (val(cm,0,-1,0)) ? (val(cm,0,0,0)) : (val(cm,0,-1,0)))*Delta/(c*_const_fm.y);
 if (dt < dtmax)
   dtmax = dt;
      }
    }
  }}
  

}

}
      

}
  }
}

{mpi_all_reduce_array(&dtmax,MPI_DOUBLE,MPI_MIN,1);}}else if(!is_constant(fm.x) && is_constant(cm)){double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/hydro.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0 -1,0,0);;;_stencil_val(fm.x,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{ 
_stencil_val(h,0,0,0); _stencil_val(h,-1,0,0);       





_stencil_val(h,-1,0,0); _stencil_val(h,-1,0,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);
_stencil_val(u.x,-1,0,0);_stencil_val(u.x,0,0,0);      _stencil_val_a(hu.x,0,0,0);                 






      
{
 {_stencil_val(zb,0,0,0); _stencil_val(zb,-1,0,0); _stencil_val(h,0,0,0);        }
{
 {_stencil_val(zb,-1,0,0); _stencil_val(zb,0,0,0); _stencil_val(h,-1,0,0);        } 
{             





 _stencil_val(hu.x,0,0,0);        
         
 
 _stencil_val(h, o_stencil,0,0);_stencil_val(h,o_stencil,0,0);

_stencil_val(h, o_stencil,0,0);_stencil_val(h, o_stencil,0,0);_stencil_val(h,o_stencil,0,0);

_stencil_val(h, o_stencil,0,0);      
}}}       
_stencil_val(fm.x,0,0,0);      _stencil_val_a(hf.x,0,0,0);





_stencil_val(hu.x,0,0,0);
 {_stencil_val(hu.x,0,0,0);  } 

_stencil_val(hf.x,0,0,0);      _stencil_val_r(hu.x,0,0,0); 
_stencil_val(hf.x,0,0,0);      _stencil_val_a(ha.x,0,0,0);  

       
    }  

point.l = 0; 

{         
       
{          
 _stencil_val(fm.x,0,0,0);;;;;   
  
    
      }    
}  
} 

_loop.face |= (1 << 1); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0,0 -1,0);;;_stencil_val(fm.y,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{ 
_stencil_val(h,0,0,0); _stencil_val(h,0,-1,0);       





_stencil_val(h,0,-1,0); _stencil_val(h,0,-1,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);
_stencil_val(u.y,0,-1,0);_stencil_val(u.y,0,0,0);      _stencil_val_a(hu.y,0,0,0);                 






      
{
 {_stencil_val(zb,0,0,0); _stencil_val(zb,0,-1,0); _stencil_val(h,0,0,0);        }
{
 {_stencil_val(zb,0,-1,0); _stencil_val(zb,0,0,0); _stencil_val(h,0,-1,0);        } 
{             





 _stencil_val(hu.y,0,0,0);        
         
 
 _stencil_val(h,0, o_stencil,0);_stencil_val(h,0,o_stencil,0);

_stencil_val(h,0, o_stencil,0);_stencil_val(h,0, o_stencil,0);_stencil_val(h,0,o_stencil,0);

_stencil_val(h,0, o_stencil,0);      
}}}       
_stencil_val(fm.y,0,0,0);      _stencil_val_a(hf.y,0,0,0);





_stencil_val(hu.y,0,0,0);
 {_stencil_val(hu.y,0,0,0);  } 

_stencil_val(hf.y,0,0,0);      _stencil_val_r(hu.y,0,0,0); 
_stencil_val(hf.y,0,0,0);      _stencil_val_a(ha.y,0,0,0);  

       
    }  

point.l = 0; 

{         
       
{          
 _stencil_val(fm.y,0,0,0);;;;;   
  
    
      }    
}  
}}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL (reduction (min:dtmax)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = (G*(2.*val(fm.x,0,0,0)/(_const_cm + _const_cm))*(val(eta_r,0 -1,0,0) - val(eta_r,0,0,0))/Delta);
    double H = 0., um = 0.;
    double Hr = 0., Hl = 0.;    

for (point.l = 0; point.l < nl; point.l++) 

{
      Hr += val(h,0,0,0), Hl += val(h,-1,0,0);





      double hl = val(h,-1,0,0) > dry ? val(h,-1,0,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      val(hu.x,0,0,0) = hl > 0. || hr > 0. ? (hl*val(u.x,-1,0,0) + hr*val(u.x,0,0,0))/(hl + hr) : 0.;






      double hff;
      if (Hl <= dry)
 hff = fmax (fmin (val(zb,0,0,0) + Hr - val(zb,-1,0,0), val(h,0,0,0)), 0.);
      else if (Hr <= dry)
 hff = fmax (fmin (val(zb,-1,0,0) + Hl - val(zb,0,0,0), val(h,-1,0,0)), 0.);
      else {





 double un = pdt*val(hu.x,0,0,0)/Delta, a = ( (int)(un > 0 ? 1 : -1));
 int i = - (a + 1.)/2.;
 double g = _attribute[h.i].gradient ? _attribute[h.i].gradient (val(h,i-1,0,0), val(h,i,0,0), val(h,i+1,0,0))/Delta :
   (val(h,i+1,0,0) - val(h,i-1,0,0))/(2.*Delta);
 hff = val(h,i,0,0) + a*(1. - a*un)*g*Delta/2.;
      }
      val(hf.x,0,0,0) = val(fm.x,0,0,0)*hff;





      if (fabs(val(hu.x,0,0,0)) > um)
 um = fabs(val(hu.x,0,0,0));

      val(hu.x,0,0,0) *= val(hf.x,0,0,0);
      val(ha.x,0,0,0) = val(hf.x,0,0,0)*ax;

      H += hff;
    }  

point.l = 0;






    

if (H > dry) {
      double c = um/CFL + sqrt(G*(hydrostatic ? H : Delta*tanh(H/Delta)))/CFL_H;
      if (c > 0.) {
 double dt = ( (_const_cm) < (_const_cm) ? (_const_cm) : (_const_cm))*Delta/(c*val(fm.x,0,0,0));
 if (dt < dtmax)
   dtmax = dt;
      }
    }
  }}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = (G*(2.*val(fm.y,0,0,0)/(_const_cm + _const_cm))*(val(eta_r,0,0 -1,0) - val(eta_r,0,0,0))/Delta);
    double H = 0., um = 0.;
    double Hr = 0., Hl = 0.;    

for (point.l = 0; point.l < nl; point.l++) 

{
      Hr += val(h,0,0,0), Hl += val(h,0,-1,0);





      double hl = val(h,0,-1,0) > dry ? val(h,0,-1,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      val(hu.y,0,0,0) = hl > 0. || hr > 0. ? (hl*val(u.y,0,-1,0) + hr*val(u.y,0,0,0))/(hl + hr) : 0.;






      double hff;
      if (Hl <= dry)
 hff = fmax (fmin (val(zb,0,0,0) + Hr - val(zb,0,-1,0), val(h,0,0,0)), 0.);
      else if (Hr <= dry)
 hff = fmax (fmin (val(zb,0,-1,0) + Hl - val(zb,0,0,0), val(h,0,-1,0)), 0.);
      else {





 double un = pdt*val(hu.y,0,0,0)/Delta, a = ( (int)(un > 0 ? 1 : -1));
 int i = - (a + 1.)/2.;
 double g = _attribute[h.i].gradient ? _attribute[h.i].gradient (val(h,0,i-1,0), val(h,0,i,0), val(h,0,i+1,0))/Delta :
   (val(h,0,i+1,0) - val(h,0,i-1,0))/(2.*Delta);
 hff = val(h,0,i,0) + a*(1. - a*un)*g*Delta/2.;
      }
      val(hf.y,0,0,0) = val(fm.y,0,0,0)*hff;





      if (fabs(val(hu.y,0,0,0)) > um)
 um = fabs(val(hu.y,0,0,0));

      val(hu.y,0,0,0) *= val(hf.y,0,0,0);
      val(ha.y,0,0,0) = val(hf.y,0,0,0)*ax;

      H += hff;
    }  

point.l = 0;






    

if (H > dry) {
      double c = um/CFL + sqrt(G*(hydrostatic ? H : Delta*tanh(H/Delta)))/CFL_H;
      if (c > 0.) {
 double dt = ( (_const_cm) < (_const_cm) ? (_const_cm) : (_const_cm))*Delta/(c*val(fm.y,0,0,0));
 if (dt < dtmax)
   dtmax = dt;
      }
    }
  }}
  

}

}
      

}
  }
}

{mpi_all_reduce_array(&dtmax,MPI_DOUBLE,MPI_MIN,1);}}else {_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/hydro.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0 -1,0,0);;;;    

for (point.l = 0; point.l < nl; point.l++) 

{ 
_stencil_val(h,0,0,0); _stencil_val(h,-1,0,0);       





_stencil_val(h,-1,0,0); _stencil_val(h,-1,0,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);
_stencil_val(u.x,-1,0,0);_stencil_val(u.x,0,0,0);      _stencil_val_a(hu.x,0,0,0);                 






      
{
 {_stencil_val(zb,0,0,0); _stencil_val(zb,-1,0,0); _stencil_val(h,0,0,0);        }
{
 {_stencil_val(zb,-1,0,0); _stencil_val(zb,0,0,0); _stencil_val(h,-1,0,0);        } 
{             





 _stencil_val(hu.x,0,0,0);        
         
 
 _stencil_val(h, o_stencil,0,0);_stencil_val(h,o_stencil,0,0);

_stencil_val(h, o_stencil,0,0);_stencil_val(h, o_stencil,0,0);_stencil_val(h,o_stencil,0,0);

_stencil_val(h, o_stencil,0,0);      
}}}
;      _stencil_val_a(hf.x,0,0,0);





_stencil_val(hu.x,0,0,0);
 {_stencil_val(hu.x,0,0,0);  } 

_stencil_val(hf.x,0,0,0);      _stencil_val_r(hu.x,0,0,0); 
_stencil_val(hf.x,0,0,0);      _stencil_val_a(ha.x,0,0,0);  

       
    }  

point.l = 0; 

{         
       
{
;;;;;   
  
    
      }    
}  
} 

_loop.face |= (1 << 1); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0,0 -1,0);;;;    

for (point.l = 0; point.l < nl; point.l++) 

{ 
_stencil_val(h,0,0,0); _stencil_val(h,0,-1,0);       





_stencil_val(h,0,-1,0); _stencil_val(h,0,-1,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);
_stencil_val(u.y,0,-1,0);_stencil_val(u.y,0,0,0);      _stencil_val_a(hu.y,0,0,0);                 






      
{
 {_stencil_val(zb,0,0,0); _stencil_val(zb,0,-1,0); _stencil_val(h,0,0,0);        }
{
 {_stencil_val(zb,0,-1,0); _stencil_val(zb,0,0,0); _stencil_val(h,0,-1,0);        } 
{             





 _stencil_val(hu.y,0,0,0);        
         
 
 _stencil_val(h,0, o_stencil,0);_stencil_val(h,0,o_stencil,0);

_stencil_val(h,0, o_stencil,0);_stencil_val(h,0, o_stencil,0);_stencil_val(h,0,o_stencil,0);

_stencil_val(h,0, o_stencil,0);      
}}}
;      _stencil_val_a(hf.y,0,0,0);





_stencil_val(hu.y,0,0,0);
 {_stencil_val(hu.y,0,0,0);  } 

_stencil_val(hf.y,0,0,0);      _stencil_val_r(hu.y,0,0,0); 
_stencil_val(hf.y,0,0,0);      _stencil_val_a(ha.y,0,0,0);  

       
    }  

point.l = 0; 

{         
       
{
;;;;;   
  
    
      }    
}  
}}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL (reduction (min:dtmax)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = (G*(2.*_const_fm.x/(_const_cm + _const_cm))*(val(eta_r,0 -1,0,0) - val(eta_r,0,0,0))/Delta);
    double H = 0., um = 0.;
    double Hr = 0., Hl = 0.;    

for (point.l = 0; point.l < nl; point.l++) 

{
      Hr += val(h,0,0,0), Hl += val(h,-1,0,0);





      double hl = val(h,-1,0,0) > dry ? val(h,-1,0,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      val(hu.x,0,0,0) = hl > 0. || hr > 0. ? (hl*val(u.x,-1,0,0) + hr*val(u.x,0,0,0))/(hl + hr) : 0.;






      double hff;
      if (Hl <= dry)
 hff = fmax (fmin (val(zb,0,0,0) + Hr - val(zb,-1,0,0), val(h,0,0,0)), 0.);
      else if (Hr <= dry)
 hff = fmax (fmin (val(zb,-1,0,0) + Hl - val(zb,0,0,0), val(h,-1,0,0)), 0.);
      else {





 double un = pdt*val(hu.x,0,0,0)/Delta, a = ( (int)(un > 0 ? 1 : -1));
 int i = - (a + 1.)/2.;
 double g = _attribute[h.i].gradient ? _attribute[h.i].gradient (val(h,i-1,0,0), val(h,i,0,0), val(h,i+1,0,0))/Delta :
   (val(h,i+1,0,0) - val(h,i-1,0,0))/(2.*Delta);
 hff = val(h,i,0,0) + a*(1. - a*un)*g*Delta/2.;
      }
      val(hf.x,0,0,0) = _const_fm.x*hff;





      if (fabs(val(hu.x,0,0,0)) > um)
 um = fabs(val(hu.x,0,0,0));

      val(hu.x,0,0,0) *= val(hf.x,0,0,0);
      val(ha.x,0,0,0) = val(hf.x,0,0,0)*ax;

      H += hff;
    }  

point.l = 0;






    

if (H > dry) {
      double c = um/CFL + sqrt(G*(hydrostatic ? H : Delta*tanh(H/Delta)))/CFL_H;
      if (c > 0.) {
 double dt = ( (_const_cm) < (_const_cm) ? (_const_cm) : (_const_cm))*Delta/(c*_const_fm.x);
 if (dt < dtmax)
   dtmax = dt;
      }
    }
  }}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = (G*(2.*_const_fm.y/(_const_cm + _const_cm))*(val(eta_r,0,0 -1,0) - val(eta_r,0,0,0))/Delta);
    double H = 0., um = 0.;
    double Hr = 0., Hl = 0.;    

for (point.l = 0; point.l < nl; point.l++) 

{
      Hr += val(h,0,0,0), Hl += val(h,0,-1,0);





      double hl = val(h,0,-1,0) > dry ? val(h,0,-1,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      val(hu.y,0,0,0) = hl > 0. || hr > 0. ? (hl*val(u.y,0,-1,0) + hr*val(u.y,0,0,0))/(hl + hr) : 0.;






      double hff;
      if (Hl <= dry)
 hff = fmax (fmin (val(zb,0,0,0) + Hr - val(zb,0,-1,0), val(h,0,0,0)), 0.);
      else if (Hr <= dry)
 hff = fmax (fmin (val(zb,0,-1,0) + Hl - val(zb,0,0,0), val(h,0,-1,0)), 0.);
      else {





 double un = pdt*val(hu.y,0,0,0)/Delta, a = ( (int)(un > 0 ? 1 : -1));
 int i = - (a + 1.)/2.;
 double g = _attribute[h.i].gradient ? _attribute[h.i].gradient (val(h,0,i-1,0), val(h,0,i,0), val(h,0,i+1,0))/Delta :
   (val(h,0,i+1,0) - val(h,0,i-1,0))/(2.*Delta);
 hff = val(h,0,i,0) + a*(1. - a*un)*g*Delta/2.;
      }
      val(hf.y,0,0,0) = _const_fm.y*hff;





      if (fabs(val(hu.y,0,0,0)) > um)
 um = fabs(val(hu.y,0,0,0));

      val(hu.y,0,0,0) *= val(hf.y,0,0,0);
      val(ha.y,0,0,0) = val(hf.y,0,0,0)*ax;

      H += hff;
    }  

point.l = 0;






    

if (H > dry) {
      double c = um/CFL + sqrt(G*(hydrostatic ? H : Delta*tanh(H/Delta)))/CFL_H;
      if (c > 0.) {
 double dt = ( (_const_cm) < (_const_cm) ? (_const_cm) : (_const_cm))*Delta/(c*_const_fm.y);
 if (dt < dtmax)
   dtmax = dt;
      }
    }
  }}
  

}

}
      

}
  }
}

{mpi_all_reduce_array(&dtmax,MPI_DOUBLE,MPI_MIN,1);}}





  pdt = dt = dtnext (dtmax);
}{end_tracing("face_fields","/home/jacqhugo/basilisk/src/layered/hydro.h",0);return 0;}end_tracing("face_fields","/home/jacqhugo/basilisk/src/layered/hydro.h",0);}







     
void advect (scalar * tracers, vector hu, vector hf, double dt)
{tracing("advect","/home/jacqhugo/basilisk/src/layered/hydro.h",0);







if(!is_constant(cm)){
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/hydro.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0);     

{
  for (point.l = 0; point.l < nl; point.l++) 

{  
       _stencil_val(hu.x,0,0,0);
_stencil_val(cm,-1,0,0);_stencil_val(h,-1,0,0);{
 {_stencil_val(h,-1,0,0);_stencil_val(cm,-1,0,0);  } 
{_stencil_val(cm,0,0,0);_stencil_val(h,0,0,0);
 {_stencil_val(h,0,0,0);_stencil_val(cm,0,0,0);   }    }} 








_stencil_val(hu.x,0,0,0); {
 if (point.l < nl - 1)
   { _stencil_val(hu.x,0,0,0);_stencil_val_r(hu.x,0,0,1);   }

           
   

 
_stencil_val_a(hu.x,0,0,0);  
      }
         
      

        
    








}  

point.l = 0;
} 

_loop.face |= (1 << 1);     

{
  for (point.l = 0; point.l < nl; point.l++) 

{  
       _stencil_val(hu.y,0,0,0);
_stencil_val(cm,0,-1,0);_stencil_val(h,0,-1,0);{
 {_stencil_val(h,0,-1,0);_stencil_val(cm,0,-1,0);  } 
{_stencil_val(cm,0,0,0);_stencil_val(h,0,0,0);
 {_stencil_val(h,0,0,0);_stencil_val(cm,0,0,0);   }    }} 








_stencil_val(hu.y,0,0,0); {
 if (point.l < nl - 1)
   { _stencil_val(hu.y,0,0,0);_stencil_val_r(hu.y,0,0,1);   }

           
   

 
_stencil_val_a(hu.y,0,0,0);  
      }
         
      

        
    








}  

point.l = 0;
}}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);     

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
  for (point.l = 0; point.l < nl; point.l++) 

{
      double hul = val(hu.x,0,0,0);
      if (hul*dt/(Delta*val(cm,-1,0,0)) > CFL*val(h,-1,0,0))
 hul = CFL*val(h,-1,0,0)*Delta*val(cm,-1,0,0)/dt;
      else if (- hul*dt/(Delta*val(cm,0,0,0)) > CFL*val(h,0,0,0))
 hul = - CFL*val(h,0,0,0)*Delta*val(cm,0,0,0)/dt;

      if (hul != val(hu.x,0,0,0)) {
 if (point.l < nl - 1)
   val(hu.x,0,0,1) += val(hu.x,0,0,0) - hul;

 else if (nl > 1)
   fprintf (ferr, "src/layered/hydro.h:%d: warning: could not conserve barotropic flux "
     "at %g,%g,%d\n", 0, x, y, point.l);

 val(hu.x,0,0,0) = hul;
      }
    }  

point.l = 0;
}}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);     

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
  for (point.l = 0; point.l < nl; point.l++) 

{
      double hul = val(hu.y,0,0,0);
      if (hul*dt/(Delta*val(cm,0,-1,0)) > CFL*val(h,0,-1,0))
 hul = CFL*val(h,0,-1,0)*Delta*val(cm,0,-1,0)/dt;
      else if (- hul*dt/(Delta*val(cm,0,0,0)) > CFL*val(h,0,0,0))
 hul = - CFL*val(h,0,0,0)*Delta*val(cm,0,0,0)/dt;

      if (hul != val(hu.y,0,0,0)) {
 if (point.l < nl - 1)
   val(hu.y,0,0,1) += val(hu.y,0,0,0) - hul;

 else if (nl > 1)
   fprintf (ferr, "src/layered/hydro.h:%d: warning: could not conserve barotropic flux "
     "at %g,%g,%d\n", 0, x, y, point.l);

 val(hu.y,0,0,0) = hul;
      }
    }  

point.l = 0;
}}
  

}

}
      

}
  }
}

}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/hydro.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0);     

{
  for (point.l = 0; point.l < nl; point.l++) 

{  
       _stencil_val(hu.x,0,0,0);
;_stencil_val(h,-1,0,0);{
 {_stencil_val(h,-1,0,0);;  } 
{;_stencil_val(h,0,0,0);
 {_stencil_val(h,0,0,0);;   }    }} 








_stencil_val(hu.x,0,0,0); {
 if (point.l < nl - 1)
   { _stencil_val(hu.x,0,0,0);_stencil_val_r(hu.x,0,0,1);   }

           
   

 
_stencil_val_a(hu.x,0,0,0);  
      }
         
      

        
    








}  

point.l = 0;
} 

_loop.face |= (1 << 1);     

{
  for (point.l = 0; point.l < nl; point.l++) 

{  
       _stencil_val(hu.y,0,0,0);
;_stencil_val(h,0,-1,0);{
 {_stencil_val(h,0,-1,0);;  } 
{;_stencil_val(h,0,0,0);
 {_stencil_val(h,0,0,0);;   }    }} 








_stencil_val(hu.y,0,0,0); {
 if (point.l < nl - 1)
   { _stencil_val(hu.y,0,0,0);_stencil_val_r(hu.y,0,0,1);   }

           
   

 
_stencil_val_a(hu.y,0,0,0);  
      }
         
      

        
    








}  

point.l = 0;
}}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);     

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
  for (point.l = 0; point.l < nl; point.l++) 

{
      double hul = val(hu.x,0,0,0);
      if (hul*dt/(Delta*_const_cm) > CFL*val(h,-1,0,0))
 hul = CFL*val(h,-1,0,0)*Delta*_const_cm/dt;
      else if (- hul*dt/(Delta*_const_cm) > CFL*val(h,0,0,0))
 hul = - CFL*val(h,0,0,0)*Delta*_const_cm/dt;

      if (hul != val(hu.x,0,0,0)) {
 if (point.l < nl - 1)
   val(hu.x,0,0,1) += val(hu.x,0,0,0) - hul;

 else if (nl > 1)
   fprintf (ferr, "src/layered/hydro.h:%d: warning: could not conserve barotropic flux "
     "at %g,%g,%d\n", 0, x, y, point.l);

 val(hu.x,0,0,0) = hul;
      }
    }  

point.l = 0;
}}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);     

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
  for (point.l = 0; point.l < nl; point.l++) 

{
      double hul = val(hu.y,0,0,0);
      if (hul*dt/(Delta*_const_cm) > CFL*val(h,0,-1,0))
 hul = CFL*val(h,0,-1,0)*Delta*_const_cm/dt;
      else if (- hul*dt/(Delta*_const_cm) > CFL*val(h,0,0,0))
 hul = - CFL*val(h,0,0,0)*Delta*_const_cm/dt;

      if (hul != val(hu.y,0,0,0)) {
 if (point.l < nl - 1)
   val(hu.y,0,0,1) += val(hu.y,0,0,0) - hul;

 else if (nl > 1)
   fprintf (ferr, "src/layered/hydro.h:%d: warning: could not conserve barotropic flux "
     "at %g,%g,%d\n", 0, x, y, point.l);

 val(hu.y,0,0,0) = hul;
      }
    }  

point.l = 0;
}}
  

}

}
      

}
  }
}

}

  

vector  flux=new_face_vector("flux");  

for (_layer = 0; _layer < nl; _layer++) 

{





    {scalar*_i=(scalar*)( tracers);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/hydro.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0); 

{               
 _stencil_val(hf.x,0,0,0);_stencil_val(hu.x,0,0,0);   
       
        
 
 _stencil_val(s, o_stencil,0,0);_stencil_val(s,o_stencil,0,0);

_stencil_val(s, o_stencil,0,0);_stencil_val(s, o_stencil,0,0);_stencil_val(s,o_stencil,0,0);      
 
_stencil_val(s, o_stencil,0,0);


_stencil_val(hf.y,o_stencil,0,0); _stencil_val(hf.y,o_stencil,1,0); {     
    _stencil_val(hf.y,o_stencil,1,0);_stencil_val(hf.y,o_stencil,0,0); _stencil_val(hu.y,o_stencil,1,0);_stencil_val(hu.y,o_stencil,0,0);           
     
    _stencil_val(s,o_stencil,-1,0);_stencil_val(s, o_stencil,0,0);_stencil_val(s, o_stencil,0,0); _stencil_val(s,o_stencil,1,0); 

_stencil_val(s,o_stencil,1,0);_stencil_val(s, o_stencil,0,0);_stencil_val(s,o_stencil,-1,0);
     
 
}


_stencil_val(hu.x,0,0,0); _stencil_val_a(flux.x,0,0,0);  
      } 

_loop.face |= (1 << 1); 

{               
 _stencil_val(hf.y,0,0,0);_stencil_val(hu.y,0,0,0);   
       
        
 
 _stencil_val(s,0, o_stencil,0);_stencil_val(s,0,o_stencil,0);

_stencil_val(s,0, o_stencil,0);_stencil_val(s,0, o_stencil,0);_stencil_val(s,0,o_stencil,0);      
 
_stencil_val(s,0, o_stencil,0);


_stencil_val(hf.x,0,o_stencil,0); _stencil_val(hf.x,1,o_stencil,0); {     
    _stencil_val(hf.x,1,o_stencil,0);_stencil_val(hf.x,0,o_stencil,0); _stencil_val(hu.x,1,o_stencil,0);_stencil_val(hu.x,0,o_stencil,0);           
     
    _stencil_val(s,-1,o_stencil,0);_stencil_val(s,0, o_stencil,0);_stencil_val(s,0, o_stencil,0); _stencil_val(s,1,o_stencil,0); 

_stencil_val(s,1,o_stencil,0);_stencil_val(s,0, o_stencil,0);_stencil_val(s,-1,o_stencil,0);
     
 
}


_stencil_val(hu.y,0,0,0); _stencil_val_a(flux.y,0,0,0);  
      }}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
 double un = dt*val(hu.x,0,0,0)/((val(hf.x,0,0,0) + dry)*Delta), a = ( (int)(un > 0 ? 1 : -1));
 int i = -(a + 1.)/2.;
 double g = _attribute[s.i].gradient ?
   _attribute[s.i].gradient (val(s,i-1,0,0), val(s,i,0,0), val(s,i+1,0,0))/Delta :
   (val(s,i+1,0,0) - val(s,i-1,0,0))/(2.*Delta);
 double s2 = val(s,i,0,0) + a*(1. - a*un)*g*Delta/2.;


 if (val(hf.y,i,0,0) + val(hf.y,i,1,0) > dry) {
   double vn = (val(hu.y,i,0,0) + val(hu.y,i,1,0))/(val(hf.y,i,0,0) + val(hf.y,i,1,0));
   double syy = (_attribute[s.i].gradient ? _attribute[s.i].gradient (val(s,i,-1,0), val(s,i,0,0), val(s,i,1,0)) :
   vn < 0. ? val(s,i,1,0) - val(s,i,0,0) : val(s,i,0,0) - val(s,i,-1,0));
   s2 -= dt*vn*syy/(2.*Delta);
 }


 val(flux.x,0,0,0) = s2*val(hu.x,0,0,0);
      }}  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
 double un = dt*val(hu.y,0,0,0)/((val(hf.y,0,0,0) + dry)*Delta), a = ( (int)(un > 0 ? 1 : -1));
 int i = -(a + 1.)/2.;
 double g = _attribute[s.i].gradient ?
   _attribute[s.i].gradient (val(s,0,i-1,0), val(s,0,i,0), val(s,0,i+1,0))/Delta :
   (val(s,0,i+1,0) - val(s,0,i-1,0))/(2.*Delta);
 double s2 = val(s,0,i,0) + a*(1. - a*un)*g*Delta/2.;


 if (val(hf.x,0,i,0) + val(hf.x,1,i,0) > dry) {
   double vn = (val(hu.x,0,i,0) + val(hu.x,1,i,0))/(val(hf.x,0,i,0) + val(hf.x,1,i,0));
   double syy = (_attribute[s.i].gradient ? _attribute[s.i].gradient (val(s,-1,i,0), val(s,0,i,0), val(s,1,i,0)) :
   vn < 0. ? val(s,1,i,0) - val(s,0,i,0) : val(s,0,i,0) - val(s,-1,i,0));
   s2 -= dt*vn*syy/(2.*Delta);
 }


 val(flux.y,0,0,0) = s2*val(hu.y,0,0,0);
      }}
  

}

}      

}
  }
}





      

if(!is_constant(cm)){      

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/hydro.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{ 
_stencil_val(h,0,0,0); _stencil_val_r(s,0,0,0); 
 
   {_stencil_val(flux.x,0,0,0); _stencil_val(flux.x,1,0,0);_stencil_val(cm,0,0,0);_stencil_val_r(s,0,0,0);   }   {_stencil_val(flux.y,0,0,0); _stencil_val(flux.y,0,1,0);_stencil_val(cm,0,0,0);_stencil_val_r(s,0,0,0);   }
      }    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
 val(s,0,0,0) *= val(h,0,0,0);
 
   val(s,0,0,0) += dt*(val(flux.x,0,0,0) - val(flux.x,1,0,0))/(Delta*val(cm,0,0,0));   val(s,0,0,0) += dt*(val(flux.y,0,0,0) - val(flux.y,0,1,0))/(Delta*val(cm,0,0,0));
      }}      

}
  }
}

}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);      

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/hydro.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{ 
_stencil_val(h,0,0,0); _stencil_val_r(s,0,0,0); 
 
   {_stencil_val(flux.x,0,0,0); _stencil_val(flux.x,1,0,0);;_stencil_val_r(s,0,0,0);   }   {_stencil_val(flux.y,0,0,0); _stencil_val(flux.y,0,1,0);;_stencil_val_r(s,0,0,0);   }
      }    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
 val(s,0,0,0) *= val(h,0,0,0);
 
   val(s,0,0,0) += dt*(val(flux.x,0,0,0) - val(flux.x,1,0,0))/(Delta*_const_cm);   val(s,0,0,0) += dt*(val(flux.y,0,0,0) - val(flux.y,0,1,0))/(Delta*_const_cm);
      }}      

}
  }
}

}
    }}}

    if(!is_constant(cm)){
  

    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/hydro.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{  
       _stencil_val(h,0,0,0);
      
 {_stencil_val(hu.x,0,0,0); _stencil_val(hu.x,1,0,0);_stencil_val(cm,0,0,0);   } {_stencil_val(hu.y,0,0,0); _stencil_val(hu.y,0,1,0);_stencil_val(cm,0,0,0);   }    

           
     
 

      _stencil_val_a(h,0,0,0);
{ {
 {scalar*_i=(scalar*)( tracers);if(_i)for(scalar f=*_i;(&f)->i>=0;f=*++_i){
   {_stencil_val_a(f,0,0,0);  }}}
      }
 
{scalar*_i=(scalar*)( tracers);if(_i)for(scalar f=*_i;(&f)->i>=0;f=*++_i){
   {_stencil_val_r(f,0,0,0);  }}}}    
}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
      double h1 = val(h,0,0,0);
      
 h1 += dt*(val(hu.x,0,0,0) - val(hu.x,1,0,0))/(Delta*val(cm,0,0,0)); h1 += dt*(val(hu.y,0,0,0) - val(hu.y,0,1,0))/(Delta*val(cm,0,0,0));

      if (h1 < - dry)
 fprintf (ferr, "src/layered/hydro.h:%d: warning: h1 = %g < - 1e-12 at %g,%g,%d,%g\n",
   0, h1, x, y, _layer, t);

      val(h,0,0,0) = ( h1 > 0. ? h1 : 0.);
      if (h1 < dry) {
 {scalar*_i=(scalar*)( tracers);if(_i)for(scalar f=*_i;(&f)->i>=0;f=*++_i){
   val(f,0,0,0) = 0.;}}
      }
      else
 {scalar*_i=(scalar*)( tracers);if(_i)for(scalar f=*_i;(&f)->i>=0;f=*++_i){
   val(f,0,0,0) /= h1;}}
    }}      

}
  }
}

}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  

    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/hydro.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{  
       _stencil_val(h,0,0,0);
      
 {_stencil_val(hu.x,0,0,0); _stencil_val(hu.x,1,0,0);;   } {_stencil_val(hu.y,0,0,0); _stencil_val(hu.y,0,1,0);;   }    

           
     
 

      _stencil_val_a(h,0,0,0);
{ {
 {scalar*_i=(scalar*)( tracers);if(_i)for(scalar f=*_i;(&f)->i>=0;f=*++_i){
   {_stencil_val_a(f,0,0,0);  }}}
      }
 
{scalar*_i=(scalar*)( tracers);if(_i)for(scalar f=*_i;(&f)->i>=0;f=*++_i){
   {_stencil_val_r(f,0,0,0);  }}}}    
}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
      double h1 = val(h,0,0,0);
      
 h1 += dt*(val(hu.x,0,0,0) - val(hu.x,1,0,0))/(Delta*_const_cm); h1 += dt*(val(hu.y,0,0,0) - val(hu.y,0,1,0))/(Delta*_const_cm);

      if (h1 < - dry)
 fprintf (ferr, "src/layered/hydro.h:%d: warning: h1 = %g < - 1e-12 at %g,%g,%d,%g\n",
   0, h1, x, y, _layer, t);

      val(h,0,0,0) = ( h1 > 0. ? h1 : 0.);
      if (h1 < dry) {
 {scalar*_i=(scalar*)( tracers);if(_i)for(scalar f=*_i;(&f)->i>=0;f=*++_i){
   val(f,0,0,0) = 0.;}}
      }
      else
 {scalar*_i=(scalar*)( tracers);if(_i)for(scalar f=*_i;(&f)->i>=0;f=*++_i){
   val(f,0,0,0) /= h1;}}
    }}      

}
  }
}

}
  }  

_layer = 0;delete((scalar*)((vector[]){flux,{{-1},{-1}}}));
end_tracing("advect","/home/jacqhugo/basilisk/src/layered/hydro.h",0);

}






static int half_advection_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}static int half_advection(const int i,const double t,Event *_ev){;return 0;}







void vertical_diffusion (Point point, scalar h, scalar s, double dt, double D,
    double dst, double s_b, double lambda_b)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

double a[nl], b[nl], c[nl], rhs[nl];  

for (point.l = 0; point.l < nl; point.l++)
    

rhs[point.l] = val(s,0,0,0)*val(h,0,0,0);  

point.l = 0;

  for (int l = 1; l < nl - 1; l++) {
    a[l] = - 2.*D*dt/(val(h,0,0,l-1) + val(h,0,0,l));
    c[l] = - 2.*D*dt/(val(h,0,0,l) + val(h,0,0,l+1));
    b[l] = val(h,0,0,l) - a[l] - c[l];
  }

  a[nl-1] = - 2.*D*dt/(val(h,0,0,nl-2) + val(h,0,0,nl-1));
  b[nl-1] = val(h,0,0,nl-1) - a[nl-1];
  rhs[nl-1] += D*dt*dst;

  double den = val(h,0,0,0)*( (val(h,0,0,0) + val(h,0,0,1))*(val(h,0,0,0) + val(h,0,0,1)))
    + 2.*lambda_b*(3.*val(h,0,0,0)*val(h,0,0,1) + 2.*( (val(h,0,0,0))*(val(h,0,0,0))) + ( (val(h,0,0,1))*(val(h,0,0,1))));
  b[0] = val(h,0,0,0) + 2.*dt*D*(1./(val(h,0,0,0) + val(h,0,0,1)) +
     (( (val(h,0,0,1))*(val(h,0,0,1))) + 3.*val(h,0,0,0)*val(h,0,0,1) + 3.*( (val(h,0,0,0))*(val(h,0,0,0))))/den);
  c[0] = - 2.*dt*D*(1./(val(h,0,0,0) + val(h,0,0,1)) + ( (val(h,0,0,0))*(val(h,0,0,0)))/den);
  rhs[0] += 2.*dt*D*s_b*(( (val(h,0,0,1))*(val(h,0,0,1))) + 3.*val(h,0,0,0)*val(h,0,0,1) + 2.*( (val(h,0,0,0))*(val(h,0,0,0))))/den;

  if (nl == 1) {
    b[0] += c[0];
    rhs[0] += (- c[0]*val(h,0,0,0) - D*dt) * dst;
  }





  for (int l = 1; l < nl; l++) {
    b[l] -= a[l]*c[l-1]/b[l-1];
    rhs[l] -= a[l]*rhs[l-1]/b[l-1];
  }
  a[nl-1] = rhs[nl-1]/b[nl-1];
  val(s,0,0,nl-1) = a[nl-1];
  for (int l = nl - 2; l >= 0; l--)
    val(s,0,0,l) = a[l] = (rhs[l] - c[l]*a[l+1])/b[l];
}







static void _stencil_vertical_diffusion (Point point, scalar h, scalar s,_stencil_undefined * dt,_stencil_undefined * D,
_stencil_undefined * dst,_stencil_undefined * s_b,_stencil_undefined * lambda_b)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

for (point.l = 0; point.l < nl; point.l++)
    

{ _stencil_val(s,0,0,0);_stencil_val(h,0,0,0); }  

point.l = 0;

  for (int l = 1; l < nl - 1; l++) {
_stencil_val(h,0,0,l-1); _stencil_val(h,0,0,l); 
       _stencil_val(h,0,0,l); _stencil_val(h,0,0,l+1); 
        _stencil_val(h,0,0,l);  
}

_stencil_val(h,0,0,nl-2); _stencil_val(h,0,0,nl-1);

       
_stencil_val(h,0,0,nl-1);     
           
     
    

  
_stencil_val(h,0,0,1);_stencil_val(h,0,0,1);_stencil_val(h,0,0,0);_stencil_val(h,0,0,0);_stencil_val(h,0,0,1);_stencil_val(h,0,0,0); 

_stencil_val(h,0,0,1);_stencil_val(h,0,0,0); _stencil_val(h,0,0,1);_stencil_val(h,0,0,0); _stencil_val(h,0,0,0); 

_stencil_val(h,0,0,0);_stencil_val(h,0,0,0); _stencil_val(h,0,0,1);
_stencil_val(h,0,0,1);_stencil_val(h,0,0,1);_stencil_val(h,0,0,0);_stencil_val(h,0,0,1);_stencil_val(h,0,0,0);_stencil_val(h,0,0,0);     
_stencil_val(h,0,0,0); _stencil_val(h,0,0,1);_stencil_val(h,0,0,0);_stencil_val(h,0,0,0);
         _stencil_val(h,0,0,1);_stencil_val(h,0,0,1);_stencil_val(h,0,0,0);_stencil_val(h,0,0,1);_stencil_val(h,0,0,0);_stencil_val(h,0,0,0);  

if (nl == 1) {
      
_stencil_val(h,0,0,0);  
}     





     
      
      
   
    
  _stencil_val_a(s,0,0,nl-1);  
  for (int l = nl - 2; l >= 0; l--)
    {_stencil_val_a(s,0,0,l);      }
}

double nu = 0.;
        vector lambda_b = {{_NVARMAX+12},{_NVARMAX+13}}, dut = {{_NVARMAX+14},{_NVARMAX+15}}, u_b = {{_NVARMAX+16},{_NVARMAX+17}};









static int viscous_term_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}

      static int viscous_term(const int i,const double t,Event *_ev){tracing("viscous_term","/home/jacqhugo/basilisk/src/layered/diffusion.h",0);
{
  if (nu > 0.) {
    if(!is_constant(dut.x) && !is_constant(u_b.x) && !is_constant(lambda_b.x)){
  
    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{      

for (point.l = 0; point.l < nl; point.l++)
 

{
   {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      }   {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }}  

point.l = 0;
      
 

{
       _stencil_val(dut.x,0,0,0); _stencil_val(u_b.x,0,0,0); _stencil_val(lambda_b.x,0,0,0);

_stencil_vertical_diffusion (point, h, u.x, NULL, NULL,
NULL,NULL,NULL);} 

{
       _stencil_val(dut.y,0,0,0); _stencil_val(u_b.y,0,0,0); _stencil_val(lambda_b.y,0,0,0);

_stencil_vertical_diffusion (point, h, u.y, NULL, NULL,
NULL,NULL,NULL);}      

for (point.l = 0; point.l < nl; point.l++)
 

{
   {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      }   {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }}  

point.l = 0;
    

}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{      

for (point.l = 0; point.l < nl; point.l++)
 

{
   val(u.x,0,0,0) += dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry);   val(u.y,0,0,0) += dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);}  

point.l = 0;
      
 

vertical_diffusion (point, h, u.x, dt, nu,
       val(dut.x,0,0,0), val(u_b.x,0,0,0), val(lambda_b.x,0,0,0)); 

vertical_diffusion (point, h, u.y, dt, nu,
       val(dut.y,0,0,0), val(u_b.y,0,0,0), val(lambda_b.y,0,0,0));      

for (point.l = 0; point.l < nl; point.l++)
 

{
   val(u.x,0,0,0) -= dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry);   val(u.y,0,0,0) -= dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);}  

point.l = 0;
    

}}
      

}
  }
}

}else if(is_constant(dut.x) && !is_constant(u_b.x) && !is_constant(lambda_b.x)){_coord _const_dut={_constant[dut.x.i-_NVARMAX],_constant[dut.y.i-_NVARMAX]};NOT_UNUSED(_const_dut);
  
    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{      

for (point.l = 0; point.l < nl; point.l++)
 

{
   {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      }   {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }}  

point.l = 0;
      
 

{
; _stencil_val(u_b.x,0,0,0); _stencil_val(lambda_b.x,0,0,0);

_stencil_vertical_diffusion (point, h, u.x, NULL, NULL,
NULL,NULL,NULL);} 

{
; _stencil_val(u_b.y,0,0,0); _stencil_val(lambda_b.y,0,0,0);

_stencil_vertical_diffusion (point, h, u.y, NULL, NULL,
NULL,NULL,NULL);}      

for (point.l = 0; point.l < nl; point.l++)
 

{
   {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      }   {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }}  

point.l = 0;
    

}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{      

for (point.l = 0; point.l < nl; point.l++)
 

{
   val(u.x,0,0,0) += dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry);   val(u.y,0,0,0) += dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);}  

point.l = 0;
      
 

vertical_diffusion (point, h, u.x, dt, nu,
       _const_dut.x, val(u_b.x,0,0,0), val(lambda_b.x,0,0,0)); 

vertical_diffusion (point, h, u.y, dt, nu,
       _const_dut.y, val(u_b.y,0,0,0), val(lambda_b.y,0,0,0));      

for (point.l = 0; point.l < nl; point.l++)
 

{
   val(u.x,0,0,0) -= dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry);   val(u.y,0,0,0) -= dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);}  

point.l = 0;
    

}}
      

}
  }
}

}else if(!is_constant(dut.x) && is_constant(u_b.x) && !is_constant(lambda_b.x)){_coord _const_u_b={_constant[u_b.x.i-_NVARMAX],_constant[u_b.y.i-_NVARMAX]};NOT_UNUSED(_const_u_b);
  
    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{      

for (point.l = 0; point.l < nl; point.l++)
 

{
   {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      }   {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }}  

point.l = 0;
      
 

{
       _stencil_val(dut.x,0,0,0);; _stencil_val(lambda_b.x,0,0,0);

_stencil_vertical_diffusion (point, h, u.x, NULL, NULL,
NULL,NULL,NULL);} 

{
       _stencil_val(dut.y,0,0,0);; _stencil_val(lambda_b.y,0,0,0);

_stencil_vertical_diffusion (point, h, u.y, NULL, NULL,
NULL,NULL,NULL);}      

for (point.l = 0; point.l < nl; point.l++)
 

{
   {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      }   {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }}  

point.l = 0;
    

}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{      

for (point.l = 0; point.l < nl; point.l++)
 

{
   val(u.x,0,0,0) += dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry);   val(u.y,0,0,0) += dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);}  

point.l = 0;
      
 

vertical_diffusion (point, h, u.x, dt, nu,
       val(dut.x,0,0,0), _const_u_b.x, val(lambda_b.x,0,0,0)); 

vertical_diffusion (point, h, u.y, dt, nu,
       val(dut.y,0,0,0), _const_u_b.y, val(lambda_b.y,0,0,0));      

for (point.l = 0; point.l < nl; point.l++)
 

{
   val(u.x,0,0,0) -= dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry);   val(u.y,0,0,0) -= dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);}  

point.l = 0;
    

}}
      

}
  }
}

}else if(is_constant(dut.x) && is_constant(u_b.x) && !is_constant(lambda_b.x)){_coord _const_dut={_constant[dut.x.i-_NVARMAX],_constant[dut.y.i-_NVARMAX]};NOT_UNUSED(_const_dut);_coord _const_u_b={_constant[u_b.x.i-_NVARMAX],_constant[u_b.y.i-_NVARMAX]};NOT_UNUSED(_const_u_b);
  
    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{      

for (point.l = 0; point.l < nl; point.l++)
 

{
   {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      }   {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }}  

point.l = 0;
      
 

{
;; _stencil_val(lambda_b.x,0,0,0);

_stencil_vertical_diffusion (point, h, u.x, NULL, NULL,
NULL,NULL,NULL);} 

{
;; _stencil_val(lambda_b.y,0,0,0);

_stencil_vertical_diffusion (point, h, u.y, NULL, NULL,
NULL,NULL,NULL);}      

for (point.l = 0; point.l < nl; point.l++)
 

{
   {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      }   {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }}  

point.l = 0;
    

}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{      

for (point.l = 0; point.l < nl; point.l++)
 

{
   val(u.x,0,0,0) += dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry);   val(u.y,0,0,0) += dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);}  

point.l = 0;
      
 

vertical_diffusion (point, h, u.x, dt, nu,
       _const_dut.x, _const_u_b.x, val(lambda_b.x,0,0,0)); 

vertical_diffusion (point, h, u.y, dt, nu,
       _const_dut.y, _const_u_b.y, val(lambda_b.y,0,0,0));      

for (point.l = 0; point.l < nl; point.l++)
 

{
   val(u.x,0,0,0) -= dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry);   val(u.y,0,0,0) -= dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);}  

point.l = 0;
    

}}
      

}
  }
}

}else if(!is_constant(dut.x) && !is_constant(u_b.x) && is_constant(lambda_b.x)){_coord _const_lambda_b={_constant[lambda_b.x.i-_NVARMAX],_constant[lambda_b.y.i-_NVARMAX]};NOT_UNUSED(_const_lambda_b);
  
    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{      

for (point.l = 0; point.l < nl; point.l++)
 

{
   {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      }   {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }}  

point.l = 0;
      
 

{
       _stencil_val(dut.x,0,0,0); _stencil_val(u_b.x,0,0,0);;

_stencil_vertical_diffusion (point, h, u.x, NULL, NULL,
NULL,NULL,NULL);} 

{
       _stencil_val(dut.y,0,0,0); _stencil_val(u_b.y,0,0,0);;

_stencil_vertical_diffusion (point, h, u.y, NULL, NULL,
NULL,NULL,NULL);}      

for (point.l = 0; point.l < nl; point.l++)
 

{
   {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      }   {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }}  

point.l = 0;
    

}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{      

for (point.l = 0; point.l < nl; point.l++)
 

{
   val(u.x,0,0,0) += dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry);   val(u.y,0,0,0) += dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);}  

point.l = 0;
      
 

vertical_diffusion (point, h, u.x, dt, nu,
       val(dut.x,0,0,0), val(u_b.x,0,0,0), _const_lambda_b.x); 

vertical_diffusion (point, h, u.y, dt, nu,
       val(dut.y,0,0,0), val(u_b.y,0,0,0), _const_lambda_b.y);      

for (point.l = 0; point.l < nl; point.l++)
 

{
   val(u.x,0,0,0) -= dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry);   val(u.y,0,0,0) -= dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);}  

point.l = 0;
    

}}
      

}
  }
}

}else if(is_constant(dut.x) && !is_constant(u_b.x) && is_constant(lambda_b.x)){_coord _const_dut={_constant[dut.x.i-_NVARMAX],_constant[dut.y.i-_NVARMAX]};NOT_UNUSED(_const_dut);_coord _const_lambda_b={_constant[lambda_b.x.i-_NVARMAX],_constant[lambda_b.y.i-_NVARMAX]};NOT_UNUSED(_const_lambda_b);
  
    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{      

for (point.l = 0; point.l < nl; point.l++)
 

{
   {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      }   {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }}  

point.l = 0;
      
 

{
; _stencil_val(u_b.x,0,0,0);;

_stencil_vertical_diffusion (point, h, u.x, NULL, NULL,
NULL,NULL,NULL);} 

{
; _stencil_val(u_b.y,0,0,0);;

_stencil_vertical_diffusion (point, h, u.y, NULL, NULL,
NULL,NULL,NULL);}      

for (point.l = 0; point.l < nl; point.l++)
 

{
   {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      }   {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }}  

point.l = 0;
    

}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{      

for (point.l = 0; point.l < nl; point.l++)
 

{
   val(u.x,0,0,0) += dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry);   val(u.y,0,0,0) += dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);}  

point.l = 0;
      
 

vertical_diffusion (point, h, u.x, dt, nu,
       _const_dut.x, val(u_b.x,0,0,0), _const_lambda_b.x); 

vertical_diffusion (point, h, u.y, dt, nu,
       _const_dut.y, val(u_b.y,0,0,0), _const_lambda_b.y);      

for (point.l = 0; point.l < nl; point.l++)
 

{
   val(u.x,0,0,0) -= dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry);   val(u.y,0,0,0) -= dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);}  

point.l = 0;
    

}}
      

}
  }
}

}else if(!is_constant(dut.x) && is_constant(u_b.x) && is_constant(lambda_b.x)){_coord _const_u_b={_constant[u_b.x.i-_NVARMAX],_constant[u_b.y.i-_NVARMAX]};NOT_UNUSED(_const_u_b);_coord _const_lambda_b={_constant[lambda_b.x.i-_NVARMAX],_constant[lambda_b.y.i-_NVARMAX]};NOT_UNUSED(_const_lambda_b);
  
    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{      

for (point.l = 0; point.l < nl; point.l++)
 

{
   {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      }   {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }}  

point.l = 0;
      
 

{
       _stencil_val(dut.x,0,0,0);;;

_stencil_vertical_diffusion (point, h, u.x, NULL, NULL,
NULL,NULL,NULL);} 

{
       _stencil_val(dut.y,0,0,0);;;

_stencil_vertical_diffusion (point, h, u.y, NULL, NULL,
NULL,NULL,NULL);}      

for (point.l = 0; point.l < nl; point.l++)
 

{
   {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      }   {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }}  

point.l = 0;
    

}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{      

for (point.l = 0; point.l < nl; point.l++)
 

{
   val(u.x,0,0,0) += dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry);   val(u.y,0,0,0) += dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);}  

point.l = 0;
      
 

vertical_diffusion (point, h, u.x, dt, nu,
       val(dut.x,0,0,0), _const_u_b.x, _const_lambda_b.x); 

vertical_diffusion (point, h, u.y, dt, nu,
       val(dut.y,0,0,0), _const_u_b.y, _const_lambda_b.y);      

for (point.l = 0; point.l < nl; point.l++)
 

{
   val(u.x,0,0,0) -= dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry);   val(u.y,0,0,0) -= dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);}  

point.l = 0;
    

}}
      

}
  }
}

}else {_coord _const_dut={_constant[dut.x.i-_NVARMAX],_constant[dut.y.i-_NVARMAX]};NOT_UNUSED(_const_dut);_coord _const_u_b={_constant[u_b.x.i-_NVARMAX],_constant[u_b.y.i-_NVARMAX]};NOT_UNUSED(_const_u_b);_coord _const_lambda_b={_constant[lambda_b.x.i-_NVARMAX],_constant[lambda_b.y.i-_NVARMAX]};NOT_UNUSED(_const_lambda_b);
  
    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{      

for (point.l = 0; point.l < nl; point.l++)
 

{
   {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      }   {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }}  

point.l = 0;
      
 

{
;;;

_stencil_vertical_diffusion (point, h, u.x, NULL, NULL,
NULL,NULL,NULL);} 

{
;;;

_stencil_vertical_diffusion (point, h, u.y, NULL, NULL,
NULL,NULL,NULL);}      

for (point.l = 0; point.l < nl; point.l++)
 

{
   {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      }   {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }}  

point.l = 0;
    

}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{      

for (point.l = 0; point.l < nl; point.l++)
 

{
   val(u.x,0,0,0) += dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry);   val(u.y,0,0,0) += dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);}  

point.l = 0;
      
 

vertical_diffusion (point, h, u.x, dt, nu,
       _const_dut.x, _const_u_b.x, _const_lambda_b.x); 

vertical_diffusion (point, h, u.y, dt, nu,
       _const_dut.y, _const_u_b.y, _const_lambda_b.y);      

for (point.l = 0; point.l < nl; point.l++)
 

{
   val(u.x,0,0,0) -= dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry);   val(u.y,0,0,0) -= dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);}  

point.l = 0;
    

}}
      

}
  }
}

}
  }
}{end_tracing("viscous_term","/home/jacqhugo/basilisk/src/layered/diffusion.h",0);return 0;}end_tracing("viscous_term","/home/jacqhugo/basilisk/src/layered/diffusion.h",0);}

void horizontal_diffusion (scalar * list, double D, double dt)
{
  if (D > 0.) {
    scalar * d2sl = list_clone (list);    

for (_layer = 0; _layer < nl; _layer++) 

{
      if(!is_constant(fm.x) && !is_constant(cm)){
  
      

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{
 scalar s, d2s;
 {scalar*_i0=d2sl;scalar*_i1= list;if(_i0)for(d2s=*_i0,s=*_i1;_i0->i>= 0;d2s=*++_i0,s=*++_i1){ {   
   
   
     {_stencil_val(hf.x,0,0,0);_stencil_val(fm.x,0,0,0);_stencil_val(cm,-1,0,0); _stencil_val(cm,0,0,0);_stencil_val(s,-1,0,0); _stencil_val(s,0,0,0);
    _stencil_val(hf.x,1,0,0);_stencil_val(fm.x,1,0,0);_stencil_val(cm,1,0,0); _stencil_val(cm,0,0,0);_stencil_val(s,1,0,0); _stencil_val(s,0,0,0);       }     

{_stencil_val(hf.y,0,0,0);_stencil_val(fm.y,0,0,0);_stencil_val(cm,0,-1,0); _stencil_val(cm,0,0,0);_stencil_val(s,0,-1,0); _stencil_val(s,0,0,0);
    _stencil_val(hf.y,0,1,0);_stencil_val(fm.y,0,1,0);_stencil_val(cm,0,1,0); _stencil_val(cm,0,0,0);_stencil_val(s,0,1,0); _stencil_val(s,0,0,0);       }
_stencil_val(cm,0,0,0);   _stencil_val_a(d2s,0,0,0);   
        }}}
      }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
 scalar s, d2s;
 {scalar*_i0=d2sl;scalar*_i1= list;if(_i0)for(d2s=*_i0,s=*_i1;_i0->i>= 0;d2s=*++_i0,s=*++_i1){ {
   double a = 0.;
   
     a += (val(hf.x,0,0,0)*val(fm.x,0,0,0)/(val(cm,-1,0,0) + val(cm,0,0,0))*(val(s,-1,0,0) - val(s,0,0,0)) +
    val(hf.x,1,0,0)*val(fm.x,1,0,0)/(val(cm,1,0,0) + val(cm,0,0,0))*(val(s,1,0,0) - val(s,0,0,0)));     

a += (val(hf.y,0,0,0)*val(fm.y,0,0,0)/(val(cm,0,-1,0) + val(cm,0,0,0))*(val(s,0,-1,0) - val(s,0,0,0)) +
    val(hf.y,0,1,0)*val(fm.y,0,1,0)/(val(cm,0,1,0) + val(cm,0,0,0))*(val(s,0,1,0) - val(s,0,0,0)));
   val(d2s,0,0,0) = 2.*a/(val(cm,0,0,0)*( Delta*Delta));
        }}}
      }}
      

}
  }
}

}else if(is_constant(fm.x) && !is_constant(cm)){_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);
  
      

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{
 scalar s, d2s;
 {scalar*_i0=d2sl;scalar*_i1= list;if(_i0)for(d2s=*_i0,s=*_i1;_i0->i>= 0;d2s=*++_i0,s=*++_i1){ {   
   
   
     {_stencil_val(hf.x,0,0,0);;_stencil_val(cm,-1,0,0); _stencil_val(cm,0,0,0);_stencil_val(s,-1,0,0); _stencil_val(s,0,0,0);
    _stencil_val(hf.x,1,0,0);;_stencil_val(cm,1,0,0); _stencil_val(cm,0,0,0);_stencil_val(s,1,0,0); _stencil_val(s,0,0,0);       }     

{_stencil_val(hf.y,0,0,0);;_stencil_val(cm,0,-1,0); _stencil_val(cm,0,0,0);_stencil_val(s,0,-1,0); _stencil_val(s,0,0,0);
    _stencil_val(hf.y,0,1,0);;_stencil_val(cm,0,1,0); _stencil_val(cm,0,0,0);_stencil_val(s,0,1,0); _stencil_val(s,0,0,0);       }
_stencil_val(cm,0,0,0);   _stencil_val_a(d2s,0,0,0);   
        }}}
      }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
 scalar s, d2s;
 {scalar*_i0=d2sl;scalar*_i1= list;if(_i0)for(d2s=*_i0,s=*_i1;_i0->i>= 0;d2s=*++_i0,s=*++_i1){ {
   double a = 0.;
   
     a += (val(hf.x,0,0,0)*_const_fm.x/(val(cm,-1,0,0) + val(cm,0,0,0))*(val(s,-1,0,0) - val(s,0,0,0)) +
    val(hf.x,1,0,0)*_const_fm.x/(val(cm,1,0,0) + val(cm,0,0,0))*(val(s,1,0,0) - val(s,0,0,0)));     

a += (val(hf.y,0,0,0)*_const_fm.y/(val(cm,0,-1,0) + val(cm,0,0,0))*(val(s,0,-1,0) - val(s,0,0,0)) +
    val(hf.y,0,1,0)*_const_fm.y/(val(cm,0,1,0) + val(cm,0,0,0))*(val(s,0,1,0) - val(s,0,0,0)));
   val(d2s,0,0,0) = 2.*a/(val(cm,0,0,0)*( Delta*Delta));
        }}}
      }}
      

}
  }
}

}else if(!is_constant(fm.x) && is_constant(cm)){double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
      

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{
 scalar s, d2s;
 {scalar*_i0=d2sl;scalar*_i1= list;if(_i0)for(d2s=*_i0,s=*_i1;_i0->i>= 0;d2s=*++_i0,s=*++_i1){ {   
   
   
     {_stencil_val(hf.x,0,0,0);_stencil_val(fm.x,0,0,0);;;_stencil_val(s,-1,0,0); _stencil_val(s,0,0,0);
    _stencil_val(hf.x,1,0,0);_stencil_val(fm.x,1,0,0);;;_stencil_val(s,1,0,0); _stencil_val(s,0,0,0);       }     

{_stencil_val(hf.y,0,0,0);_stencil_val(fm.y,0,0,0);;;_stencil_val(s,0,-1,0); _stencil_val(s,0,0,0);
    _stencil_val(hf.y,0,1,0);_stencil_val(fm.y,0,1,0);;;_stencil_val(s,0,1,0); _stencil_val(s,0,0,0);       }
;   _stencil_val_a(d2s,0,0,0);   
        }}}
      }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
 scalar s, d2s;
 {scalar*_i0=d2sl;scalar*_i1= list;if(_i0)for(d2s=*_i0,s=*_i1;_i0->i>= 0;d2s=*++_i0,s=*++_i1){ {
   double a = 0.;
   
     a += (val(hf.x,0,0,0)*val(fm.x,0,0,0)/(_const_cm + _const_cm)*(val(s,-1,0,0) - val(s,0,0,0)) +
    val(hf.x,1,0,0)*val(fm.x,1,0,0)/(_const_cm + _const_cm)*(val(s,1,0,0) - val(s,0,0,0)));     

a += (val(hf.y,0,0,0)*val(fm.y,0,0,0)/(_const_cm + _const_cm)*(val(s,0,-1,0) - val(s,0,0,0)) +
    val(hf.y,0,1,0)*val(fm.y,0,1,0)/(_const_cm + _const_cm)*(val(s,0,1,0) - val(s,0,0,0)));
   val(d2s,0,0,0) = 2.*a/(_const_cm*( Delta*Delta));
        }}}
      }}
      

}
  }
}

}else {_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
      

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{
 scalar s, d2s;
 {scalar*_i0=d2sl;scalar*_i1= list;if(_i0)for(d2s=*_i0,s=*_i1;_i0->i>= 0;d2s=*++_i0,s=*++_i1){ {   
   
   
     {_stencil_val(hf.x,0,0,0);;;;_stencil_val(s,-1,0,0); _stencil_val(s,0,0,0);
    _stencil_val(hf.x,1,0,0);;;;_stencil_val(s,1,0,0); _stencil_val(s,0,0,0);       }     

{_stencil_val(hf.y,0,0,0);;;;_stencil_val(s,0,-1,0); _stencil_val(s,0,0,0);
    _stencil_val(hf.y,0,1,0);;;;_stencil_val(s,0,1,0); _stencil_val(s,0,0,0);       }
;   _stencil_val_a(d2s,0,0,0);   
        }}}
      }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
 scalar s, d2s;
 {scalar*_i0=d2sl;scalar*_i1= list;if(_i0)for(d2s=*_i0,s=*_i1;_i0->i>= 0;d2s=*++_i0,s=*++_i1){ {
   double a = 0.;
   
     a += (val(hf.x,0,0,0)*_const_fm.x/(_const_cm + _const_cm)*(val(s,-1,0,0) - val(s,0,0,0)) +
    val(hf.x,1,0,0)*_const_fm.x/(_const_cm + _const_cm)*(val(s,1,0,0) - val(s,0,0,0)));     

a += (val(hf.y,0,0,0)*_const_fm.y/(_const_cm + _const_cm)*(val(s,0,-1,0) - val(s,0,0,0)) +
    val(hf.y,0,1,0)*_const_fm.y/(_const_cm + _const_cm)*(val(s,0,1,0) - val(s,0,0,0)));
   val(d2s,0,0,0) = 2.*a/(_const_cm*( Delta*Delta));
        }}}
      }}
      

}
  }
}

}
  
      

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{_stencil_val(h,0,0,0); {
   scalar s, d2s;
   {scalar*_i0=d2sl;scalar*_i1= list;if(_i0)for(d2s=*_i0,s=*_i1;_i0->i>= 0;d2s=*++_i0,s=*++_i1){
     {_stencil_val(d2s,0,0,0);_stencil_val(h,0,0,0);_stencil_val_r(s,0,0,0);  }}}
 }   }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

if (val(h,0,0,0) > dry) {
   scalar s, d2s;
   {scalar*_i0=d2sl;scalar*_i1= list;if(_i0)for(d2s=*_i0,s=*_i1;_i0->i>= 0;d2s=*++_i0,s=*++_i1){
     val(s,0,0,0) += dt*D*val(d2s,0,0,0)/val(h,0,0,0);}}
 }}
      

}
  }
}    

}  

_layer = 0;
    

delete (d2sl);
    pfree (d2sl,__func__,__FILE__,0);
  }
}




     
void mg_cycle (scalar * a, scalar * res, scalar * da,
        void (* relax) (scalar * da, scalar * res,
          int depth, void * data),
        void * data,
        int nrelax, int minlevel, int maxlevel)
{tracing("mg_cycle","/home/jacqhugo/basilisk/src/poisson.h",0);




  restriction (res);





  minlevel = ( minlevel < maxlevel ? minlevel : maxlevel);
  for (int l = minlevel; l <= maxlevel; l++) {




    if (l == minlevel)
      {
  
  
      

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{scalar*_i=(scalar*)( da);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){    

{
  for (point.l = 0; point.l < _attribute[s.i].block; point.l++)
     

{_stencil_val_a(s,0,0,0);  }  

point.l = 0;
}}}
  

}

{ 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = l;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{scalar*_i=(scalar*)( da);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){    

{
  for (point.l = 0; point.l < _attribute[s.i].block; point.l++)
     

val(s,0,0,0) = 0.;  

point.l = 0;
}}}}
    

}
  }
}

}

}





    

else {
      boundary_level (da, l - 1);
  
      

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{scalar*_i=(scalar*)( da);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){    

{
  for (point.l = 0; point.l < _attribute[s.i].block; point.l++)
     

{ _stencil_bilinear (point, s);_stencil_val_a(s,0,0,0); }  

point.l = 0;
}}}
  

} 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = l;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{scalar*_i=(scalar*)( da);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){    

{
  for (point.l = 0; point.l < _attribute[s.i].block; point.l++)
     

val(s,0,0,0) = bilinear (point, s);  

point.l = 0;
}}}}
    

}
  }
}    

}





    for (int i = 0; i < nrelax; i++) {
      boundary_level (da, l);
      relax (da, res, l, data);
    }
  }
  




  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/poisson.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{
    scalar s, ds;
    {scalar*_i0= da;scalar*_i1= a;if(_i0)for(ds=*_i0,s=*_i1;_i0->i>= 0;ds=*++_i0,s=*++_i1){       

{
  for (point.l = 0; point.l < _attribute[s.i].block; point.l++)
 

{ _stencil_val(ds,0,0,0);_stencil_val_r(s,0,0,0); }  

point.l = 0;
}}}
  

}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    scalar s, ds;
    {scalar*_i0= da;scalar*_i1= a;if(_i0)for(ds=*_i0,s=*_i1;_i0->i>= 0;ds=*++_i0,s=*++_i1){       

{
  for (point.l = 0; point.l < _attribute[s.i].block; point.l++)
 

val(s,0,0,0) += val(ds,0,0,0);  

point.l = 0;
}}}
  

}}
      

}
  }
}
end_tracing("mg_cycle","/home/jacqhugo/basilisk/src/poisson.h",0);

}

int NITERMAX = 100, NITERMIN = 1;
double TOLERANCE = 1e-3;




typedef struct {
  int i;
  double resb, resa;
  double sum;
  int nrelax;
  int minlevel;
} mgstats;

     
mgstats mg_solve (scalar * a, scalar * b,
    double (* residual) (scalar * a, scalar * b, scalar * res,
           void * data),
    void (* relax) (scalar * da, scalar * res, int depth,
      void * data),
    void * data,
    int nrelax,
    scalar * res,
    int minlevel,
    double tolerance)
{tracing("mg_solve","/home/jacqhugo/basilisk/src/poisson.h",0);





  scalar * da = list_clone (a), * pres = res;
  if (!res)
    res = list_clone (b);






  for (int b = 0; b < nboundary; b++)
    {scalar*_i=(scalar*)( da);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      _attribute[s.i].boundary[b] = _attribute[s.i].boundary_homogeneous[b];}}




  mgstats s = {0};
  double sum = 0.;
  scalar rhs = b[0];
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/poisson.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    

{ _stencil_val(rhs,0,0,0); }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

mpi_sum_reduce_init(mpi_sum,&sum,MPI_DOUBLE,MPI_SUM,1); 

{
  OMP_PARALLEL (reduction(+:sum)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

sum += val(rhs,0,0,0);}
      

}
  }
}

{mpi_sum_reduce_array(mpi_sum,&sum,MPI_DOUBLE,MPI_SUM,1);}
  s.sum = sum;
  s.nrelax = nrelax > 0 ? nrelax : 4;




  double resb;
  resb = s.resb = s.resa = (* residual) (a, b, res, data);






  for (s.i = 0;
       s.i < NITERMAX && (s.i < NITERMIN || s.resa > tolerance);
       s.i++) {
    mg_cycle (a, res, da, relax, data,
       s.nrelax,
       minlevel,
       grid->maxdepth);
    s.resa = (* residual) (a, b, res, data);

    if (s.resa > tolerance) {
      if (resb/s.resa < 1.2 && s.nrelax < 100)
 s.nrelax++;
      else if (resb/s.resa > 10 && s.nrelax > 2)
 s.nrelax--;
    }







    resb = s.resa;
  }
  s.minlevel = minlevel;




  if (s.resa > tolerance) {
    scalar v = a[0];
    fprintf (ferr,
      "src/poisson.h:%d: warning: convergence for %s not reached after %d iterations\n"
      "  res: %g sum: %g nrelax: %d tolerance: %g\n", 0, _attribute[v.i].name,
      s.i, s.resa, s.sum, s.nrelax, tolerance), fflush (ferr);
  }




  if (!pres)
    delete (res), pfree (res,__func__,__FILE__,0);
  delete (da), pfree (da,__func__,__FILE__,0);

  {end_tracing("mg_solve","/home/jacqhugo/basilisk/src/poisson.h",0);return s;}
end_tracing("mg_solve","/home/jacqhugo/basilisk/src/poisson.h",0);}

struct Poisson {
  scalar a, b;
          vector alpha;
          scalar lambda;
  double tolerance;
  int nrelax, minlevel;
  scalar * res;



};





static void relax (scalar * al, scalar * bl, int l, void * data)
{
  scalar a = al[0], b = bl[0];
  struct Poisson * p = (struct Poisson *) data;
          vector alpha = p->alpha;
          scalar lambda = p->lambda;

  scalar c = a;

  if(!is_constant(lambda) && !is_constant(alpha.x)){
  
  

  

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);  

{         





     _stencil_val(lambda,0,0,0);_stencil_val(b,0,0,0);
     { 
_stencil_val(alpha.x,1,0,0);_stencil_val(a,1,0,0); _stencil_val(alpha.x,0,0,0);_stencil_val(a,-1,0,0);
         _stencil_val(alpha.x,1,0,0); _stencil_val(alpha.x,0,0,0);    
} 

{ 
_stencil_val(alpha.y,0,1,0);_stencil_val(a,0,1,0); _stencil_val(alpha.y,0,0,0);_stencil_val(a,0,-1,0);
         _stencil_val(alpha.y,0,1,0); _stencil_val(alpha.y,0,0,0);    
}

      _stencil_val_a(c,0,0,0);  
  }
  

}

{ 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = l;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++)

  

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{





    double n = - ( Delta*Delta)*val(b,0,0,0), d = - val(lambda,0,0,0)*( Delta*Delta);
     {
      n += val(alpha.x,1,0,0)*val(a,1,0,0) + val(alpha.x,0,0,0)*val(a,-1,0,0);
      d += val(alpha.x,1,0,0) + val(alpha.x,0,0,0);
    } 

{
      n += val(alpha.y,0,1,0)*val(a,0,1,0) + val(alpha.y,0,0,0)*val(a,0,-1,0);
      d += val(alpha.y,0,1,0) + val(alpha.y,0,0,0);
    }

      val(c,0,0,0) = n/d;
  }}    

}
  }
}

}

}else if(is_constant(lambda) && !is_constant(alpha.x)){double _const_lambda=_constant[lambda.i-_NVARMAX];NOT_UNUSED(_const_lambda);
  
  

  

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);  

{





;_stencil_val(b,0,0,0);
     { 
_stencil_val(alpha.x,1,0,0);_stencil_val(a,1,0,0); _stencil_val(alpha.x,0,0,0);_stencil_val(a,-1,0,0);
         _stencil_val(alpha.x,1,0,0); _stencil_val(alpha.x,0,0,0);    
} 

{ 
_stencil_val(alpha.y,0,1,0);_stencil_val(a,0,1,0); _stencil_val(alpha.y,0,0,0);_stencil_val(a,0,-1,0);
         _stencil_val(alpha.y,0,1,0); _stencil_val(alpha.y,0,0,0);    
}

      _stencil_val_a(c,0,0,0);  
  }
  

}

{ 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = l;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++)

  

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{





    double n = - ( Delta*Delta)*val(b,0,0,0), d = - _const_lambda*( Delta*Delta);
     {
      n += val(alpha.x,1,0,0)*val(a,1,0,0) + val(alpha.x,0,0,0)*val(a,-1,0,0);
      d += val(alpha.x,1,0,0) + val(alpha.x,0,0,0);
    } 

{
      n += val(alpha.y,0,1,0)*val(a,0,1,0) + val(alpha.y,0,0,0)*val(a,0,-1,0);
      d += val(alpha.y,0,1,0) + val(alpha.y,0,0,0);
    }

      val(c,0,0,0) = n/d;
  }}    

}
  }
}

}

}else if(!is_constant(lambda) && is_constant(alpha.x)){_coord _const_alpha={_constant[alpha.x.i-_NVARMAX],_constant[alpha.y.i-_NVARMAX]};NOT_UNUSED(_const_alpha);
  
  

  

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);  

{         





     _stencil_val(lambda,0,0,0);_stencil_val(b,0,0,0);
     {
;_stencil_val(a,1,0,0);;_stencil_val(a,-1,0,0);
;;    
} 

{
;_stencil_val(a,0,1,0);;_stencil_val(a,0,-1,0);
;;    
}

      _stencil_val_a(c,0,0,0);  
  }
  

}

{ 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = l;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++)

  

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{





    double n = - ( Delta*Delta)*val(b,0,0,0), d = - val(lambda,0,0,0)*( Delta*Delta);
     {
      n += _const_alpha.x*val(a,1,0,0) + _const_alpha.x*val(a,-1,0,0);
      d += _const_alpha.x + _const_alpha.x;
    } 

{
      n += _const_alpha.y*val(a,0,1,0) + _const_alpha.y*val(a,0,-1,0);
      d += _const_alpha.y + _const_alpha.y;
    }

      val(c,0,0,0) = n/d;
  }}    

}
  }
}

}

}else {double _const_lambda=_constant[lambda.i-_NVARMAX];NOT_UNUSED(_const_lambda);_coord _const_alpha={_constant[alpha.x.i-_NVARMAX],_constant[alpha.y.i-_NVARMAX]};NOT_UNUSED(_const_alpha);
  
  

  

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);  

{





;_stencil_val(b,0,0,0);
     {
;_stencil_val(a,1,0,0);;_stencil_val(a,-1,0,0);
;;    
} 

{
;_stencil_val(a,0,1,0);;_stencil_val(a,0,-1,0);
;;    
}

      _stencil_val_a(c,0,0,0);  
  }
  

}

{ 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = l;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++)

  

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{





    double n = - ( Delta*Delta)*val(b,0,0,0), d = - _const_lambda*( Delta*Delta);
     {
      n += _const_alpha.x*val(a,1,0,0) + _const_alpha.x*val(a,-1,0,0);
      d += _const_alpha.x + _const_alpha.x;
    } 

{
      n += _const_alpha.y*val(a,0,1,0) + _const_alpha.y*val(a,0,-1,0);
      d += _const_alpha.y + _const_alpha.y;
    }

      val(c,0,0,0) = n/d;
  }}    

}
  }
}

}

}

}






static double residual (scalar * al, scalar * bl, scalar * resl, void * data)
{
  scalar a = al[0], b = bl[0], res = resl[0];
  struct Poisson * p = (struct Poisson *) data;
          vector alpha = p->alpha;
          scalar lambda = p->lambda;
  double maxres = 0.;

  if(!is_constant(lambda) && !is_constant(alpha.x)){
  

  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/poisson.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{ 
_stencil_val(b,0,0,0); _stencil_val(lambda,0,0,0);_stencil_val(a,0,0,0);    _stencil_val_a(res,0,0,0);  
    
      {_stencil_val(alpha.x,0,0,0);_stencil_val(a,0,0,0); _stencil_val(a,0 -1,0,0);
  _stencil_val(alpha.x,1,0,0);_stencil_val(a,1,0,0); _stencil_val(a,1 -1,0,0);

_stencil_val_r(res,0,0,0);     
}      

{_stencil_val(alpha.y,0,0,0);_stencil_val(a,0,0,0); _stencil_val(a,0,0 -1,0);
  _stencil_val(alpha.y,0,1,0);_stencil_val(a,0,1,0); _stencil_val(a,0,1 -1,0);

_stencil_val_r(res,0,0,0);     
}






_stencil_val(res,0,0,0);
      {_stencil_val(res,0,0,0);   }  
}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL (reduction(max:maxres)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    val(res,0,0,0) = val(b,0,0,0) - val(lambda,0,0,0)*val(a,0,0,0);
    
      val(res,0,0,0) += (val(alpha.x,0,0,0)*((val(a,0,0,0) - val(a,0 -1,0,0))/Delta) -
  val(alpha.x,1,0,0)*((val(a,1,0,0) - val(a,1 -1,0,0))/Delta))/Delta;      

val(res,0,0,0) += (val(alpha.y,0,0,0)*((val(a,0,0,0) - val(a,0,0 -1,0))/Delta) -
  val(alpha.y,0,1,0)*((val(a,0,1,0) - val(a,0,1 -1,0))/Delta))/Delta;






    if (fabs (val(res,0,0,0)) > maxres)
      maxres = fabs (val(res,0,0,0));
  }}      

}
  }
}

{mpi_all_reduce_array(&maxres,MPI_DOUBLE,MPI_MAX,1);}}else if(is_constant(lambda) && !is_constant(alpha.x)){double _const_lambda=_constant[lambda.i-_NVARMAX];NOT_UNUSED(_const_lambda);
  

  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/poisson.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{ 
_stencil_val(b,0,0,0);;_stencil_val(a,0,0,0);    _stencil_val_a(res,0,0,0);  
    
      {_stencil_val(alpha.x,0,0,0);_stencil_val(a,0,0,0); _stencil_val(a,0 -1,0,0);
  _stencil_val(alpha.x,1,0,0);_stencil_val(a,1,0,0); _stencil_val(a,1 -1,0,0);

_stencil_val_r(res,0,0,0);     
}      

{_stencil_val(alpha.y,0,0,0);_stencil_val(a,0,0,0); _stencil_val(a,0,0 -1,0);
  _stencil_val(alpha.y,0,1,0);_stencil_val(a,0,1,0); _stencil_val(a,0,1 -1,0);

_stencil_val_r(res,0,0,0);     
}






_stencil_val(res,0,0,0);
      {_stencil_val(res,0,0,0);   }  
}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL (reduction(max:maxres)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    val(res,0,0,0) = val(b,0,0,0) - _const_lambda*val(a,0,0,0);
    
      val(res,0,0,0) += (val(alpha.x,0,0,0)*((val(a,0,0,0) - val(a,0 -1,0,0))/Delta) -
  val(alpha.x,1,0,0)*((val(a,1,0,0) - val(a,1 -1,0,0))/Delta))/Delta;      

val(res,0,0,0) += (val(alpha.y,0,0,0)*((val(a,0,0,0) - val(a,0,0 -1,0))/Delta) -
  val(alpha.y,0,1,0)*((val(a,0,1,0) - val(a,0,1 -1,0))/Delta))/Delta;






    if (fabs (val(res,0,0,0)) > maxres)
      maxres = fabs (val(res,0,0,0));
  }}      

}
  }
}

{mpi_all_reduce_array(&maxres,MPI_DOUBLE,MPI_MAX,1);}}else if(!is_constant(lambda) && is_constant(alpha.x)){_coord _const_alpha={_constant[alpha.x.i-_NVARMAX],_constant[alpha.y.i-_NVARMAX]};NOT_UNUSED(_const_alpha);
  

  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/poisson.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{ 
_stencil_val(b,0,0,0); _stencil_val(lambda,0,0,0);_stencil_val(a,0,0,0);    _stencil_val_a(res,0,0,0);  
    
      {;_stencil_val(a,0,0,0); _stencil_val(a,0 -1,0,0);
;_stencil_val(a,1,0,0); _stencil_val(a,1 -1,0,0);

_stencil_val_r(res,0,0,0);     
}      

{;_stencil_val(a,0,0,0); _stencil_val(a,0,0 -1,0);
;_stencil_val(a,0,1,0); _stencil_val(a,0,1 -1,0);

_stencil_val_r(res,0,0,0);     
}






_stencil_val(res,0,0,0);
      {_stencil_val(res,0,0,0);   }  
}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL (reduction(max:maxres)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    val(res,0,0,0) = val(b,0,0,0) - val(lambda,0,0,0)*val(a,0,0,0);
    
      val(res,0,0,0) += (_const_alpha.x*((val(a,0,0,0) - val(a,0 -1,0,0))/Delta) -
  _const_alpha.x*((val(a,1,0,0) - val(a,1 -1,0,0))/Delta))/Delta;      

val(res,0,0,0) += (_const_alpha.y*((val(a,0,0,0) - val(a,0,0 -1,0))/Delta) -
  _const_alpha.y*((val(a,0,1,0) - val(a,0,1 -1,0))/Delta))/Delta;






    if (fabs (val(res,0,0,0)) > maxres)
      maxres = fabs (val(res,0,0,0));
  }}      

}
  }
}

{mpi_all_reduce_array(&maxres,MPI_DOUBLE,MPI_MAX,1);}}else {double _const_lambda=_constant[lambda.i-_NVARMAX];NOT_UNUSED(_const_lambda);_coord _const_alpha={_constant[alpha.x.i-_NVARMAX],_constant[alpha.y.i-_NVARMAX]};NOT_UNUSED(_const_alpha);
  

  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/poisson.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{ 
_stencil_val(b,0,0,0);;_stencil_val(a,0,0,0);    _stencil_val_a(res,0,0,0);  
    
      {;_stencil_val(a,0,0,0); _stencil_val(a,0 -1,0,0);
;_stencil_val(a,1,0,0); _stencil_val(a,1 -1,0,0);

_stencil_val_r(res,0,0,0);     
}      

{;_stencil_val(a,0,0,0); _stencil_val(a,0,0 -1,0);
;_stencil_val(a,0,1,0); _stencil_val(a,0,1 -1,0);

_stencil_val_r(res,0,0,0);     
}






_stencil_val(res,0,0,0);
      {_stencil_val(res,0,0,0);   }  
}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL (reduction(max:maxres)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    val(res,0,0,0) = val(b,0,0,0) - _const_lambda*val(a,0,0,0);
    
      val(res,0,0,0) += (_const_alpha.x*((val(a,0,0,0) - val(a,0 -1,0,0))/Delta) -
  _const_alpha.x*((val(a,1,0,0) - val(a,1 -1,0,0))/Delta))/Delta;      

val(res,0,0,0) += (_const_alpha.y*((val(a,0,0,0) - val(a,0,0 -1,0))/Delta) -
  _const_alpha.y*((val(a,0,1,0) - val(a,0,1 -1,0))/Delta))/Delta;






    if (fabs (val(res,0,0,0)) > maxres)
      maxres = fabs (val(res,0,0,0));
  }}      

}
  }
}

{mpi_all_reduce_array(&maxres,MPI_DOUBLE,MPI_MAX,1);}}

  return maxres;
}

     
mgstats poisson (scalar a, scalar b,
           vector alpha,
           scalar lambda,
   double tolerance,
   int nrelax,
   int minlevel,
   scalar * res,
   double (* flux) (Point, scalar, vector, double *))
{tracing("poisson","/home/jacqhugo/basilisk/src/poisson.h",0);






  if (alpha.x.i < 0)
    alpha = new_const_vector("alpha",0,(double[]) {1.,1.,1.});
  if (lambda.i < 0)
    lambda = new_const_scalar("lambda",2, 0.);






  restriction (((scalar[]){alpha.x,alpha.y,lambda,{-1}}));





  double defaultol = TOLERANCE;
  if (tolerance)
    TOLERANCE = tolerance;

  struct Poisson p = {a, b, alpha, lambda, tolerance, nrelax, minlevel, res };






  mgstats s = mg_solve ((

scalar *

)((scalar[]){a,{-1}}),( 

scalar *

)((scalar[]) {b,{-1}}), residual, relax, &p
,   nrelax, res, ( 1 > minlevel ? 1 : minlevel)

, 
TOLERANCE

);




  if (tolerance)
    TOLERANCE = defaultol;

  {end_tracing("poisson","/home/jacqhugo/basilisk/src/poisson.h",0);return s;}
end_tracing("poisson","/home/jacqhugo/basilisk/src/poisson.h",0);}

     
mgstats project (vector uf, scalar p,
           vector alpha,
   double dt,
   int nrelax)
{tracing("project","/home/jacqhugo/basilisk/src/poisson.h",0);






  scalar  div=new_scalar("div");  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/poisson.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{
    _stencil_val_a(div,0,0,0);  
    
      { _stencil_val(uf.x,1,0,0); _stencil_val(uf.x,0,0,0);_stencil_val_r(div,0,0,0);  }      { _stencil_val(uf.y,0,1,0); _stencil_val(uf.y,0,0,0);_stencil_val_r(div,0,0,0);  }
    _stencil_val_r(div,0,0,0);  
  }    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    val(div,0,0,0) = 0.;
    
      val(div,0,0,0) += val(uf.x,1,0,0) - val(uf.x,0,0,0);      val(div,0,0,0) += val(uf.y,0,1,0) - val(uf.y,0,0,0);
    val(div,0,0,0) /= dt*Delta;
  }}      

}
  }
}

  mgstats mgp = poisson (p, div, alpha

,
( scalar) {-1}

, TOLERANCE/( dt*dt), nrelax

, 
0, 
NULL, 
NULL

);




if(!is_constant(alpha.x)){  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/poisson.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0);
    

{_stencil_val(alpha.x,0,0,0);_stencil_val(p,0,0,0); _stencil_val(p,0 -1,0,0);_stencil_val_r(uf.x,0,0,0);   } 

_loop.face |= (1 << 1);
    

{_stencil_val(alpha.y,0,0,0);_stencil_val(p,0,0,0); _stencil_val(p,0,0 -1,0);_stencil_val_r(uf.y,0,0,0);   }}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);
    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(uf.x,0,0,0) -= dt*val(alpha.x,0,0,0)*((val(p,0,0,0) - val(p,0 -1,0,0))/Delta);}  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);
    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(uf.y,0,0,0) -= dt*val(alpha.y,0,0,0)*((val(p,0,0,0) - val(p,0,0 -1,0))/Delta);}  

}

}      

}
  }
}

}else {_coord _const_alpha={_constant[alpha.x.i-_NVARMAX],_constant[alpha.y.i-_NVARMAX]};NOT_UNUSED(_const_alpha);  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/poisson.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0);
    

{;_stencil_val(p,0,0,0); _stencil_val(p,0 -1,0,0);_stencil_val_r(uf.x,0,0,0);   } 

_loop.face |= (1 << 1);
    

{;_stencil_val(p,0,0,0); _stencil_val(p,0,0 -1,0);_stencil_val_r(uf.y,0,0,0);   }}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);
    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(uf.x,0,0,0) -= dt*_const_alpha.x*((val(p,0,0,0) - val(p,0 -1,0,0))/Delta);}  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);
    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(uf.y,0,0,0) -= dt*_const_alpha.y*((val(p,0,0,0) - val(p,0,0 -1,0))/Delta);}  

}

}      

}
  }
}

}

  {delete((scalar*)((scalar[]){div,{-1}}));{end_tracing("project","/home/jacqhugo/basilisk/src/poisson.h",0);return mgp;}}delete((scalar*)((scalar[]){div,{-1}}));
end_tracing("project","/home/jacqhugo/basilisk/src/poisson.h",0);}


     
mgstats implicit_horizontal_diffusion (scalar * list, double D, double dt)
{tracing("implicit_horizontal_diffusion","/home/jacqhugo/basilisk/src/layered/diffusion.h",0);
  mgstats mg = {0};
  if (D > 0.) {
    scalar  b=new_scalar("b"),  lambda=new_scalar("lambda");
    vector  alpha=new_face_vector("alpha");    

for (_layer = 0; _layer < nl; _layer++) 

{
if(!is_constant(fm.x) && !is_constant(cm)){
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0); 

{_stencil_val(hf.x,0,0,0);_stencil_val(fm.x,0,0,0);_stencil_val(cm,-1,0,0); _stencil_val(cm,0,0,0);_stencil_val_a(alpha.x,0,0,0);   } 

_loop.face |= (1 << 1); 

{_stencil_val(hf.y,0,0,0);_stencil_val(fm.y,0,0,0);_stencil_val(cm,0,-1,0); _stencil_val(cm,0,0,0);_stencil_val_a(alpha.y,0,0,0);   }}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(alpha.x,0,0,0) = 2.*dt*D*val(hf.x,0,0,0)*val(fm.x,0,0,0)/(val(cm,-1,0,0) + val(cm,0,0,0));}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(alpha.y,0,0,0) = 2.*dt*D*val(hf.y,0,0,0)*val(fm.y,0,0,0)/(val(cm,0,-1,0) + val(cm,0,0,0));}
  

}

}
      

}
  }
}

}else if(is_constant(fm.x) && !is_constant(cm)){_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0); 

{_stencil_val(hf.x,0,0,0);;_stencil_val(cm,-1,0,0); _stencil_val(cm,0,0,0);_stencil_val_a(alpha.x,0,0,0);   } 

_loop.face |= (1 << 1); 

{_stencil_val(hf.y,0,0,0);;_stencil_val(cm,0,-1,0); _stencil_val(cm,0,0,0);_stencil_val_a(alpha.y,0,0,0);   }}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(alpha.x,0,0,0) = 2.*dt*D*val(hf.x,0,0,0)*_const_fm.x/(val(cm,-1,0,0) + val(cm,0,0,0));}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(alpha.y,0,0,0) = 2.*dt*D*val(hf.y,0,0,0)*_const_fm.y/(val(cm,0,-1,0) + val(cm,0,0,0));}
  

}

}
      

}
  }
}

}else if(!is_constant(fm.x) && is_constant(cm)){double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0); 

{_stencil_val(hf.x,0,0,0);_stencil_val(fm.x,0,0,0);;;_stencil_val_a(alpha.x,0,0,0);   } 

_loop.face |= (1 << 1); 

{_stencil_val(hf.y,0,0,0);_stencil_val(fm.y,0,0,0);;;_stencil_val_a(alpha.y,0,0,0);   }}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(alpha.x,0,0,0) = 2.*dt*D*val(hf.x,0,0,0)*val(fm.x,0,0,0)/(_const_cm + _const_cm);}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(alpha.y,0,0,0) = 2.*dt*D*val(hf.y,0,0,0)*val(fm.y,0,0,0)/(_const_cm + _const_cm);}
  

}

}
      

}
  }
}

}else {_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0); 

{_stencil_val(hf.x,0,0,0);;;;_stencil_val_a(alpha.x,0,0,0);   } 

_loop.face |= (1 << 1); 

{_stencil_val(hf.y,0,0,0);;;;_stencil_val_a(alpha.y,0,0,0);   }}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(alpha.x,0,0,0) = 2.*dt*D*val(hf.x,0,0,0)*_const_fm.x/(_const_cm + _const_cm);}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(alpha.y,0,0,0) = 2.*dt*D*val(hf.y,0,0,0)*_const_fm.y/(_const_cm + _const_cm);}
  

}

}
      

}
  }
}

}
      if(!is_constant(cm)){
  
      

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{ _stencil_val(cm,0,0,0);_stencil_val(h,0,0,0);_stencil_val_a(lambda,0,0,0);  }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(lambda,0,0,0) = - val(cm,0,0,0)*val(h,0,0,0);}
      

}
  }
}

}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
      

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{;_stencil_val(h,0,0,0);_stencil_val_a(lambda,0,0,0);  }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(lambda,0,0,0) = - _const_cm*val(h,0,0,0);}
      

}
  }
}

}
      {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
  
 

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/diffusion.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);   

{ _stencil_val(lambda,0,0,0);_stencil_val(s,0,0,0);_stencil_val_a(b,0,0,0); }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)   

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(b,0,0,0) = val(lambda,0,0,0)*val(s,0,0,0);}
      

}
  }
} 

mg = poisson (s, b, alpha, lambda

, 
0., 
4, 
0, 
NULL, 
NULL

);
      }}}
    }  

_layer = 0;delete((scalar*)((scalar[]){alpha.x,alpha.y,lambda,b,{-1}}));
  

}
  {end_tracing("implicit_horizontal_diffusion","/home/jacqhugo/basilisk/src/layered/diffusion.h",0);return mg;}
end_tracing("implicit_horizontal_diffusion","/home/jacqhugo/basilisk/src/layered/diffusion.h",0);}

static int acceleration_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}


static int acceleration(const int i,const double t,Event *_ev){;return 0;}

static int pressure_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}      static int pressure(const int i,const double t,Event *_ev){tracing("pressure","/home/jacqhugo/basilisk/src/layered/hydro.h",0);
{  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/hydro.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0);     

{
  for (point.l = 0; point.l < nl; point.l++)
      

{_stencil_val(ha.x,0,0,0);_stencil_val_r(hu.x,0,0,0);  }  

point.l = 0;
} 

_loop.face |= (1 << 1);     

{
  for (point.l = 0; point.l < nl; point.l++)
      

{_stencil_val(ha.y,0,0,0);_stencil_val_r(hu.y,0,0,0);  }  

point.l = 0;
}}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);     

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
  for (point.l = 0; point.l < nl; point.l++)
      

val(hu.x,0,0,0) += dt*val(ha.x,0,0,0);  

point.l = 0;
}}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);     

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
  for (point.l = 0; point.l < nl; point.l++)
      

val(hu.y,0,0,0) += dt*val(ha.y,0,0,0);  

point.l = 0;
}}
  

}

}
      

}
  }
}




  

if(!is_constant(fm.x) && !is_constant(cm)){  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/hydro.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);     

{
  for (point.l = 0; point.l < nl; point.l++) 

{
      
 {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      } {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }    


      _stencil_val(cm,0,0,0); _stencil_val(fm.x,0,0,0);_stencil_val(fm.x,1,0,0);    
      _stencil_val(cm,0,0,0); _stencil_val(fm.y,0,0,0);_stencil_val(fm.y,0,1,0);    
       _stencil_val(u.y,0,0,0); _stencil_val(u.x,0,0,0);     
      
      _stencil_val_r(u.x,0,0,0);  
      _stencil_val_r(u.y,0,0,0);  

    }  

point.l = 0;
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)     

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
  for (point.l = 0; point.l < nl; point.l++) 

{
      
 val(u.x,0,0,0) += dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry); val(u.y,0,0,0) += dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);


      double dmdl = (val(fm.x,1,0,0) - val(fm.x,0,0,0))/(val(cm,0,0,0)*Delta);
      double dmdt = (val(fm.y,0,1,0) - val(fm.y,0,0,0))/(val(cm,0,0,0)*Delta);
      double ux = val(u.x,0,0,0), uy = val(u.y,0,0,0);
      double fG = uy*dmdl - ux*dmdt;
      val(u.x,0,0,0) += dt*fG*uy;
      val(u.y,0,0,0) -= dt*fG*ux;

    }  

point.l = 0;
}}
      

}
  }
}

}else if(is_constant(fm.x) && !is_constant(cm)){_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);
  




  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/hydro.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);     

{
  for (point.l = 0; point.l < nl; point.l++) 

{
      
 {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      } {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }    


      _stencil_val(cm,0,0,0);;;    
      _stencil_val(cm,0,0,0);;;    
       _stencil_val(u.y,0,0,0); _stencil_val(u.x,0,0,0);     
      
      _stencil_val_r(u.x,0,0,0);  
      _stencil_val_r(u.y,0,0,0);  

    }  

point.l = 0;
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)     

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
  for (point.l = 0; point.l < nl; point.l++) 

{
      
 val(u.x,0,0,0) += dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry); val(u.y,0,0,0) += dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);


      double dmdl = (_const_fm.x - _const_fm.x)/(val(cm,0,0,0)*Delta);
      double dmdt = (_const_fm.y - _const_fm.y)/(val(cm,0,0,0)*Delta);
      double ux = val(u.x,0,0,0), uy = val(u.y,0,0,0);
      double fG = uy*dmdl - ux*dmdt;
      val(u.x,0,0,0) += dt*fG*uy;
      val(u.y,0,0,0) -= dt*fG*ux;

    }  

point.l = 0;
}}
      

}
  }
}

}else if(!is_constant(fm.x) && is_constant(cm)){double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  




  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/hydro.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);     

{
  for (point.l = 0; point.l < nl; point.l++) 

{
      
 {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      } {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }


; _stencil_val(fm.x,0,0,0);_stencil_val(fm.x,1,0,0);
; _stencil_val(fm.y,0,0,0);_stencil_val(fm.y,0,1,0);    
       _stencil_val(u.y,0,0,0); _stencil_val(u.x,0,0,0);     
      
      _stencil_val_r(u.x,0,0,0);  
      _stencil_val_r(u.y,0,0,0);  

    }  

point.l = 0;
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)     

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
  for (point.l = 0; point.l < nl; point.l++) 

{
      
 val(u.x,0,0,0) += dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry); val(u.y,0,0,0) += dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);


      double dmdl = (val(fm.x,1,0,0) - val(fm.x,0,0,0))/(_const_cm*Delta);
      double dmdt = (val(fm.y,0,1,0) - val(fm.y,0,0,0))/(_const_cm*Delta);
      double ux = val(u.x,0,0,0), uy = val(u.y,0,0,0);
      double fG = uy*dmdl - ux*dmdt;
      val(u.x,0,0,0) += dt*fG*uy;
      val(u.y,0,0,0) -= dt*fG*ux;

    }  

point.l = 0;
}}
      

}
  }
}

}else {_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  




  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/hydro.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);     

{
  for (point.l = 0; point.l < nl; point.l++) 

{
      
 {_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0);_stencil_val_r(u.x,0,0,0);      } {_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0);_stencil_val_r(u.y,0,0,0);      }


;;;
;;;    
       _stencil_val(u.y,0,0,0); _stencil_val(u.x,0,0,0);     
      
      _stencil_val_r(u.x,0,0,0);  
      _stencil_val_r(u.y,0,0,0);  

    }  

point.l = 0;
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)     

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
  for (point.l = 0; point.l < nl; point.l++) 

{
      
 val(u.x,0,0,0) += dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry); val(u.y,0,0,0) += dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);


      double dmdl = (_const_fm.x - _const_fm.x)/(_const_cm*Delta);
      double dmdt = (_const_fm.y - _const_fm.y)/(_const_cm*Delta);
      double ux = val(u.x,0,0,0), uy = val(u.y,0,0,0);
      double fG = uy*dmdl - ux*dmdt;
      val(u.x,0,0,0) += dt*fG*uy;
      val(u.y,0,0,0) -= dt*fG*ux;

    }  

point.l = 0;
}}
      

}
  }
}

}
  

delete ((scalar *)((vector[]){ha,{{-1},{-1}}}));





  advect (tracers, hu, hf, dt);
}{end_tracing("pressure","/home/jacqhugo/basilisk/src/layered/hydro.h",0);return 0;}end_tracing("pressure","/home/jacqhugo/basilisk/src/layered/hydro.h",0);}




static int update_eta_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}      static int update_eta(const int i,const double t,Event *_ev){tracing("update_eta","/home/jacqhugo/basilisk/src/layered/hydro.h",0);
{
  delete ((scalar *)((vector[]){hu, hf,{{-1},{-1}}}));  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/hydro.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{  
     _stencil_val(zb,0,0,0);    

for (point.l = 0; point.l < nl; point.l++)
      

{ _stencil_val(h,0,0,0); }  

point.l = 0;
    

_stencil_val_a(eta,0,0,0);  
  }    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double etap = val(zb,0,0,0);    

for (point.l = 0; point.l < nl; point.l++)
      

etap += val(h,0,0,0);  

point.l = 0;
    

val(eta,0,0,0) = etap;
  }}      

}
  }
}


}{end_tracing("update_eta","/home/jacqhugo/basilisk/src/layered/hydro.h",0);return 0;}end_tracing("update_eta","/home/jacqhugo/basilisk/src/layered/hydro.h",0);}






static int remap_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}static int remap(const int i,const double t,Event *_ev){;return 0;}

static int cleanup_0_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(t = TEND_EVENT)!=0;*ip=i;*tp=t;return ret;}

      static int cleanup_0(const int i,const double t,Event *_ev){tracing("cleanup_0","/home/jacqhugo/basilisk/src/layered/hydro.h",0);
{
  delete (((scalar[]){eta, eta_r, h, u.x, u.y,{-1}}));
  pfree (tracers,__func__,__FILE__,0), tracers = NULL;
}{end_tracing("cleanup_0","/home/jacqhugo/basilisk/src/layered/hydro.h",0);return 0;}end_tracing("cleanup_0","/home/jacqhugo/basilisk/src/layered/hydro.h",0);}

double max_slope = 0.577350269189626;

void vertical_velocity (scalar w, vector hu, vector hf)
{  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/hydro.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{   
     _stencil_val(zb,-1,0,0); _stencil_val(zb,1,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{
_stencil_val(hu.x,0,0,0); _stencil_val(hu.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0); 
_stencil_val(h,1,0,0); _stencil_val(h,-1,0,0);      

_stencil_val_a(w,0,0,0);          
 
      if (point.l > 0)
 {
   {_stencil_val(hu.x,0,0,-1); _stencil_val(hu.x,1,0,-1);
_stencil_val(hf.x,0,0,-1); _stencil_val(hf.x,1,0,-1);

_stencil_val_r(w,0,0,0);   
      }   

{_stencil_val(hu.y,0,0,-1); _stencil_val(hu.y,0,1,-1);
_stencil_val(hf.y,0,0,-1); _stencil_val(hf.y,0,1,-1);

_stencil_val_r(w,0,0,0);   
      }}
      
 {_stencil_val(hu.x,1,0,0); _stencil_val(hu.x,0,0,0);_stencil_val_r(w,0,0,0);   } {_stencil_val(hu.y,0,1,0); _stencil_val(hu.y,0,0,0);_stencil_val_r(w,0,0,0);   } 
_stencil_val(h,1,0,0); _stencil_val(h,-1,0,0); _stencil_val(w,0,0,0);    
}  

point.l = 0;
  

}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double dz = val(zb,1,0,0) - val(zb,-1,0,0);
    double wm = 0.;    

for (point.l = 0; point.l < nl; point.l++) 

{
      val(w,0,0,0) = wm + (val(hu.x,0,0,0) + val(hu.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry)*
 (dz + val(h,1,0,0) - val(h,-1,0,0))/(2.*Delta);
      if (point.l > 0)
 {
   val(w,0,0,0) -= (val(hu.x,0,0,-1) + val(hu.x,1,0,-1))
   /(val(hf.x,0,0,-1) + val(hf.x,1,0,-1) + dry)*dz/(2.*Delta);   

val(w,0,0,0) -= (val(hu.y,0,0,-1) + val(hu.y,0,1,-1))
   /(val(hf.y,0,0,-1) + val(hf.y,0,1,-1) + dry)*dz/(2.*Delta);}
      
 val(w,0,0,0) -= (val(hu.x,1,0,0) - val(hu.x,0,0,0))/Delta; val(w,0,0,0) -= (val(hu.y,0,1,0) - val(hu.y,0,0,0))/Delta;
      dz += val(h,1,0,0) - val(h,-1,0,0), wm = val(w,0,0,0);
    }  

point.l = 0;
  

}}      

}
  }
}


}

double _radiation (Point point, double ref, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  

double H = 0.;  

for (point.l = 0; point.l < nl; point.l++)
    

H += val(h,0,0,0);  

point.l = 0;



  

return sqrt (G*( H > 0. ? H : 0.)) - sqrt(G*( (ref - val(zb,0,0,0)) > 0. ? (ref - val(zb,0,0,0)) : 0.));

}




void conserve_elevation (void) {}





typedef struct {
  char * name;
  double x, y;
  char * desc;
  FILE * fp;
} Gauge;

     
void output_gauges (Gauge * gauges, scalar * list)
{tracing("output_gauges","/home/jacqhugo/basilisk/src/gauges.h",0);
  int n = 0;
  for (Gauge * g = gauges; g->name; g++, n++);
  coord a[n];
  n = 0;
  for (Gauge * g = gauges; g->name; g++, n++) {
    double xp = g->x, yp = g->y;
    unmap (&xp, &yp);
    a[n].x = xp, a[n].y = yp;
  }
  int len = list_len(list);
  double v[n*len];
  interpolate_array (list, a, n, v, false);

  if (pid() == 0) {
    n = 0;
    for (Gauge * g = gauges; g->name; g++) {
      if (!g->fp) {
 g->fp = fopen (g->name, "w");
 if (g->desc)
   fprintf (g->fp, "%s\n", g->desc);
      }
      if (v[n] != 1e30f) {
 fprintf (g->fp, "%g", t);
 {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
   fprintf (g->fp, " %g", v[n++]);}}
 fputc ('\n', g->fp);
 fflush (g->fp);
      }
      else
 n += len;
    }
  }
end_tracing("output_gauges","/home/jacqhugo/basilisk/src/gauges.h",0);}


double segment_flux (coord segment[2], double * flux, scalar h, vector u)
{
  coord m = {segment[0].y - segment[1].y, segment[1].x - segment[0].x};
  normalize (&m);
  for (int l = 0; l < nl; l++)
    flux[l] = 0.;  

double norm = sqrt(( (segment[1].x - segment[0].x)*(segment[1].x - segment[0].x)) + ( (segment[1].y - segment[0].y)*(segment[1].y - segment[0].y)));
  if (norm > 0.) {
    coord t = {(segment[1].x - segment[0].x)/norm + 1e-6, (segment[1].y - segment[0].y)/norm - 1.5e-6};
    double alpha = segment[0].x*t.y - segment[0].y*t.x;
    if(!is_constant(fm.x)){    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/utils.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{       
 
 
  
                 
           
          
       
                 
           
    
           
       
       
            
            
       

{   
    
     {      
       _stencil_val(fm.y,0,1,0);_stencil_val(fm.y,0,0,0); 
        
    } 

{      
       _stencil_val(fm.x,1,0,0);_stencil_val(fm.x,0,0,0); 
        
    }
       
    for (int i = 0; i < 2; i++) {      

for (point.l = 0; point.l < nl; point.l++)
 

{
 _stencil_interpolate_linear (point, h,NULL,NULL, NULL);
_stencil_interpolate_linear (point, u.x,NULL,NULL, NULL);
_stencil_interpolate_linear (point, u.y,NULL,NULL, NULL); }  

point.l = 0;
    

}
  }      

}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

mpi_sum_reduce_init(mpi_flux,flux,MPI_DOUBLE,MPI_SUM,nl); 

{
  OMP_PARALLEL (reduction(+:flux[:nl])) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)
      

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

if (fabs(t.y*x - t.x*y - alpha) < 0.708*Delta_x) {
 coord _o = {x,y}, p[2];
 int _n = 0;
 
   if (t.x)
     for (int _i = -1; _i <= 1 && _n < 2; _i += 2) {
       p[_n].x = _o.x + _i*Delta_x/2.;
       double a = (p[_n].x - segment[0].x)/t.x;
       p[_n].y = segment[0].y + a*t.y;
       if (fabs(p[_n].y - _o.y) <= Delta_x/2.) {
  a = ( a < 0. ? 0. : a > norm ? norm : a);
  p[_n].x = segment[0].x + a*t.x, p[_n].y = segment[0].y + a*t.y;
  if (fabs(p[_n].x - _o.x) <= Delta_x/2. &&
      fabs(p[_n].y - _o.y) <= Delta_x/2.)
    _n++;
       }
     }   

if (t.y)
     for (int _i = -1; _i <= 1 && _n < 2; _i += 2) {
       p[_n].y = _o.y + _i*Delta_y/2.;
       double a = (p[_n].y - segment[0].y)/t.y;
       p[_n].x = segment[0].x + a*t.x;
       if (fabs(p[_n].x - _o.x) <= Delta_y/2.) {
  a = ( a < 0. ? 0. : a > norm ? norm : a);
  p[_n].y = segment[0].y + a*t.y, p[_n].x = segment[0].x + a*t.x;
  if (fabs(p[_n].y - _o.y) <= Delta_y/2. &&
      fabs(p[_n].x - _o.x) <= Delta_y/2.)
    _n++;
       }
     }
 if (_n == 2) 

{
    double dl = 0.;
     {
      double dp = (p[1].x - p[0].x)*Delta/Delta_x*(val(fm.y,0,0,0) + val(fm.y,0,1,0))/2.;
      dl += ( dp*dp);
    } 

{
      double dp = (p[1].y - p[0].y)*Delta/Delta_y*(val(fm.x,0,0,0) + val(fm.x,1,0,0))/2.;
      dl += ( dp*dp);
    }
    dl = sqrt (dl);
    for (int i = 0; i < 2; i++) {
      coord a = p[i];      

for (point.l = 0; point.l < nl; point.l++)
 

flux[point.l] += dl/2.*
 interpolate_linear (point, h, a.x, a.y, 0.)*
 (m.x*interpolate_linear (point, u.x, a.x, a.y, 0.) +
  m.y*interpolate_linear (point, u.y, a.x, a.y, 0.));  

point.l = 0;
    

}
  }      

}}      

}
  }
}

{mpi_sum_reduce_array(mpi_flux,flux,MPI_DOUBLE,MPI_SUM,nl);}}else {_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/utils.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{       
 
 
  
                 
           
          
       
                 
           
    
           
       
       
            
            
       

{   
    
     {
;; 
        
    } 

{
;; 
        
    }
       
    for (int i = 0; i < 2; i++) {      

for (point.l = 0; point.l < nl; point.l++)
 

{
 _stencil_interpolate_linear (point, h,NULL,NULL, NULL);
_stencil_interpolate_linear (point, u.x,NULL,NULL, NULL);
_stencil_interpolate_linear (point, u.y,NULL,NULL, NULL); }  

point.l = 0;
    

}
  }      

}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

mpi_sum_reduce_init(mpi_flux,flux,MPI_DOUBLE,MPI_SUM,nl); 

{
  OMP_PARALLEL (reduction(+:flux[:nl])) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)
      

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

if (fabs(t.y*x - t.x*y - alpha) < 0.708*Delta_x) {
 coord _o = {x,y}, p[2];
 int _n = 0;
 
   if (t.x)
     for (int _i = -1; _i <= 1 && _n < 2; _i += 2) {
       p[_n].x = _o.x + _i*Delta_x/2.;
       double a = (p[_n].x - segment[0].x)/t.x;
       p[_n].y = segment[0].y + a*t.y;
       if (fabs(p[_n].y - _o.y) <= Delta_x/2.) {
  a = ( a < 0. ? 0. : a > norm ? norm : a);
  p[_n].x = segment[0].x + a*t.x, p[_n].y = segment[0].y + a*t.y;
  if (fabs(p[_n].x - _o.x) <= Delta_x/2. &&
      fabs(p[_n].y - _o.y) <= Delta_x/2.)
    _n++;
       }
     }   

if (t.y)
     for (int _i = -1; _i <= 1 && _n < 2; _i += 2) {
       p[_n].y = _o.y + _i*Delta_y/2.;
       double a = (p[_n].y - segment[0].y)/t.y;
       p[_n].x = segment[0].x + a*t.x;
       if (fabs(p[_n].x - _o.x) <= Delta_y/2.) {
  a = ( a < 0. ? 0. : a > norm ? norm : a);
  p[_n].y = segment[0].y + a*t.y, p[_n].x = segment[0].x + a*t.x;
  if (fabs(p[_n].y - _o.y) <= Delta_y/2. &&
      fabs(p[_n].x - _o.x) <= Delta_y/2.)
    _n++;
       }
     }
 if (_n == 2) 

{
    double dl = 0.;
     {
      double dp = (p[1].x - p[0].x)*Delta/Delta_x*(_const_fm.y + _const_fm.y)/2.;
      dl += ( dp*dp);
    } 

{
      double dp = (p[1].y - p[0].y)*Delta/Delta_y*(_const_fm.x + _const_fm.x)/2.;
      dl += ( dp*dp);
    }
    dl = sqrt (dl);
    for (int i = 0; i < 2; i++) {
      coord a = p[i];      

for (point.l = 0; point.l < nl; point.l++)
 

flux[point.l] += dl/2.*
 interpolate_linear (point, h, a.x, a.y, 0.)*
 (m.x*interpolate_linear (point, u.x, a.x, a.y, 0.) +
  m.y*interpolate_linear (point, u.y, a.x, a.y, 0.));  

point.l = 0;
    

}
  }      

}}      

}
  }
}

{mpi_sum_reduce_array(mpi_flux,flux,MPI_DOUBLE,MPI_SUM,nl);}}
  }
  

double tot = 0.;
  for (int l = 0; l < nl; l++)
    tot += flux[l];
  return tot;
}

typedef struct {
  char * name;
  coord s[2];
  char * desc;
  FILE * fp;
} Flux;

void output_fluxes (Flux * fluxes, scalar h, vector u)
{
  for (Flux * f = fluxes; f->name; f++) {
    double flux[nl];
    double tot = segment_flux (f->s, flux, h, u);
    if (pid() == 0) {
      if (!f->fp) {
 f->fp = fopen (f->name, "w");
 if (f->desc)
   fprintf (f->fp, "%s\n", f->desc);
      }
      fprintf (f->fp, "%g %g", t, tot);
      for (int i = 0; i < nl; i++)
 fprintf (f->fp, " %g", flux[i]);
      fputc ('\n', f->fp);
      fflush (f->fp);
    }
  }
}




mgstats mgH = { .minlevel = 1 };
double theta_H = 0.5;








static int defaults0_0_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i = 0)!=0;*ip=i;*tp=t;return ret;}

      static int defaults0_0(const int i,const double t,Event *_ev){tracing("defaults0_0","/home/jacqhugo/basilisk/src/layered/implicit.h",0);
{
  if (CFL_H == 1e40)
    CFL_H = 1e30f;
  mgH.nrelax = 4;
}{end_tracing("defaults0_0","/home/jacqhugo/basilisk/src/layered/implicit.h",0);return 0;}end_tracing("defaults0_0","/home/jacqhugo/basilisk/src/layered/implicit.h",0);}





bool rigid = false;

static int defaults_1_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i = 0)!=0;*ip=i;*tp=t;return ret;}

      static int defaults_1(const int i,const double t,Event *_ev){tracing("defaults_1","/home/jacqhugo/basilisk/src/layered/implicit.h",0);
{
  if (rigid)
    eta_r = new_scalar("eta_r");
}{end_tracing("defaults_1","/home/jacqhugo/basilisk/src/layered/implicit.h",0);return 0;}end_tracing("defaults_1","/home/jacqhugo/basilisk/src/layered/implicit.h",0);}

     
static void relax_hydro (scalar * ql, scalar * rhsl, int lev, void * data)
{tracing("relax_hydro","/home/jacqhugo/basilisk/src/layered/implicit.h",0);
  scalar eta = ql[0], rhs_eta = rhsl[0];
  vector alpha = *((vector *)data);





  if(!is_constant(cm) && !is_constant(fm.x)){
  
  





  

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);  

{       
     _stencil_val(cm,0,0,0);   
    _stencil_val(rhs_eta,0,0,0); _stencil_val(cm,0,0,0);
    _stencil_val_a(eta,0,0,0);  
     { 
_stencil_val(alpha.x,0,0,0);_stencil_val(fm.x,0,0,0);_stencil_val(cm,0,0,0); _stencil_val(cm,0 -1,0,0);_stencil_val(eta,0 -1,0,0); _stencil_val(eta,0,0,0); _stencil_val(alpha.x,1,0,0);_stencil_val(fm.x,1,0,0);_stencil_val(cm,1,0,0); _stencil_val(cm,1 -1,0,0);_stencil_val(eta,1 -1,0,0); _stencil_val(eta,1,0,0);      

{ _stencil_val(alpha.x,0,0,0);_stencil_val(fm.x,0,0,0);_stencil_val(cm,0,0,0); _stencil_val(cm,0 -1,0,0);_stencil_val_diagonal(eta,0 -1,0,0); _stencil_val_diagonal(eta,0,0,0); _stencil_val(alpha.x,1,0,0);_stencil_val(fm.x,1,0,0);_stencil_val(cm,1,0,0); _stencil_val(cm,1 -1,0,0);_stencil_val_diagonal(eta,1 -1,0,0); _stencil_val_diagonal(eta,1,0,0);      }
    } 

{ 
_stencil_val(alpha.y,0,0,0);_stencil_val(fm.y,0,0,0);_stencil_val(cm,0,0,0); _stencil_val(cm,0,0 -1,0);_stencil_val(eta,0,0 -1,0); _stencil_val(eta,0,0,0); _stencil_val(alpha.y,0,1,0);_stencil_val(fm.y,0,1,0);_stencil_val(cm,0,1,0); _stencil_val(cm,0,1 -1,0);_stencil_val(eta,0,1 -1,0); _stencil_val(eta,0,1,0);      

{ _stencil_val(alpha.y,0,0,0);_stencil_val(fm.y,0,0,0);_stencil_val(cm,0,0,0); _stencil_val(cm,0,0 -1,0);_stencil_val_diagonal(eta,0,0 -1,0); _stencil_val_diagonal(eta,0,0,0); _stencil_val(alpha.y,0,1,0);_stencil_val(fm.y,0,1,0);_stencil_val(cm,0,1,0); _stencil_val(cm,0,1 -1,0);_stencil_val_diagonal(eta,0,1 -1,0); _stencil_val_diagonal(eta,0,1,0);      }
    }
    _stencil_val_a(eta,0,0,0);      
  }
  

}

{ 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = lev;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++)  

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double d = rigid ? 0. : - val(cm,0,0,0)*Delta;
    double n = - val(cm,0,0,0)*Delta*val(rhs_eta,0,0,0);
    val(eta,0,0,0) = 0.;
     {
      n += val(alpha.x,0,0,0)*(G*(2.*val(fm.x,0,0,0)/(val(cm,0,0,0) + val(cm,0 -1,0,0)))*(val(eta,0 -1,0,0) - val(eta,0,0,0))/Delta) - val(alpha.x,1,0,0)*(G*(2.*val(fm.x,1,0,0)/(val(cm,1,0,0) + val(cm,1 -1,0,0)))*(val(eta,1 -1,0,0) - val(eta,1,0,0))/Delta);
 
      d -= val(alpha.x,0,0,0)*(G*(2.*val(fm.x,0,0,0)/(val(cm,0,0,0) + val(cm,0 -1,0,0)))*(val_diagonal(eta,0 -1,0,0) - val_diagonal(eta,0,0,0))/Delta) - val(alpha.x,1,0,0)*(G*(2.*val(fm.x,1,0,0)/(val(cm,1,0,0) + val(cm,1 -1,0,0)))*(val_diagonal(eta,1 -1,0,0) - val_diagonal(eta,1,0,0))/Delta);
    } 

{
      n += val(alpha.y,0,0,0)*(G*(2.*val(fm.y,0,0,0)/(val(cm,0,0,0) + val(cm,0,0 -1,0)))*(val(eta,0,0 -1,0) - val(eta,0,0,0))/Delta) - val(alpha.y,0,1,0)*(G*(2.*val(fm.y,0,1,0)/(val(cm,0,1,0) + val(cm,0,1 -1,0)))*(val(eta,0,1 -1,0) - val(eta,0,1,0))/Delta);
 
      d -= val(alpha.y,0,0,0)*(G*(2.*val(fm.y,0,0,0)/(val(cm,0,0,0) + val(cm,0,0 -1,0)))*(val_diagonal(eta,0,0 -1,0) - val_diagonal(eta,0,0,0))/Delta) - val(alpha.y,0,1,0)*(G*(2.*val(fm.y,0,1,0)/(val(cm,0,1,0) + val(cm,0,1 -1,0)))*(val_diagonal(eta,0,1 -1,0) - val_diagonal(eta,0,1,0))/Delta);
    }
    val(eta,0,0,0) = d ? n/d : 0;
  }}
    

}
  }
}

}

}else if(is_constant(cm) && !is_constant(fm.x)){double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  





  

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);  

{
;   
    _stencil_val(rhs_eta,0,0,0);;
    _stencil_val_a(eta,0,0,0);  
     { 
_stencil_val(alpha.x,0,0,0);_stencil_val(fm.x,0,0,0);;;_stencil_val(eta,0 -1,0,0); _stencil_val(eta,0,0,0); _stencil_val(alpha.x,1,0,0);_stencil_val(fm.x,1,0,0);;;_stencil_val(eta,1 -1,0,0); _stencil_val(eta,1,0,0);      

{ _stencil_val(alpha.x,0,0,0);_stencil_val(fm.x,0,0,0);;;_stencil_val_diagonal(eta,0 -1,0,0); _stencil_val_diagonal(eta,0,0,0); _stencil_val(alpha.x,1,0,0);_stencil_val(fm.x,1,0,0);;;_stencil_val_diagonal(eta,1 -1,0,0); _stencil_val_diagonal(eta,1,0,0);      }
    } 

{ 
_stencil_val(alpha.y,0,0,0);_stencil_val(fm.y,0,0,0);;;_stencil_val(eta,0,0 -1,0); _stencil_val(eta,0,0,0); _stencil_val(alpha.y,0,1,0);_stencil_val(fm.y,0,1,0);;;_stencil_val(eta,0,1 -1,0); _stencil_val(eta,0,1,0);      

{ _stencil_val(alpha.y,0,0,0);_stencil_val(fm.y,0,0,0);;;_stencil_val_diagonal(eta,0,0 -1,0); _stencil_val_diagonal(eta,0,0,0); _stencil_val(alpha.y,0,1,0);_stencil_val(fm.y,0,1,0);;;_stencil_val_diagonal(eta,0,1 -1,0); _stencil_val_diagonal(eta,0,1,0);      }
    }
    _stencil_val_a(eta,0,0,0);      
  }
  

}

{ 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = lev;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++)  

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double d = rigid ? 0. : - _const_cm*Delta;
    double n = - _const_cm*Delta*val(rhs_eta,0,0,0);
    val(eta,0,0,0) = 0.;
     {
      n += val(alpha.x,0,0,0)*(G*(2.*val(fm.x,0,0,0)/(_const_cm + _const_cm))*(val(eta,0 -1,0,0) - val(eta,0,0,0))/Delta) - val(alpha.x,1,0,0)*(G*(2.*val(fm.x,1,0,0)/(_const_cm + _const_cm))*(val(eta,1 -1,0,0) - val(eta,1,0,0))/Delta);
 
      d -= val(alpha.x,0,0,0)*(G*(2.*val(fm.x,0,0,0)/(_const_cm + _const_cm))*(val_diagonal(eta,0 -1,0,0) - val_diagonal(eta,0,0,0))/Delta) - val(alpha.x,1,0,0)*(G*(2.*val(fm.x,1,0,0)/(_const_cm + _const_cm))*(val_diagonal(eta,1 -1,0,0) - val_diagonal(eta,1,0,0))/Delta);
    } 

{
      n += val(alpha.y,0,0,0)*(G*(2.*val(fm.y,0,0,0)/(_const_cm + _const_cm))*(val(eta,0,0 -1,0) - val(eta,0,0,0))/Delta) - val(alpha.y,0,1,0)*(G*(2.*val(fm.y,0,1,0)/(_const_cm + _const_cm))*(val(eta,0,1 -1,0) - val(eta,0,1,0))/Delta);
 
      d -= val(alpha.y,0,0,0)*(G*(2.*val(fm.y,0,0,0)/(_const_cm + _const_cm))*(val_diagonal(eta,0,0 -1,0) - val_diagonal(eta,0,0,0))/Delta) - val(alpha.y,0,1,0)*(G*(2.*val(fm.y,0,1,0)/(_const_cm + _const_cm))*(val_diagonal(eta,0,1 -1,0) - val_diagonal(eta,0,1,0))/Delta);
    }
    val(eta,0,0,0) = d ? n/d : 0;
  }}
    

}
  }
}

}

}else if(!is_constant(cm) && is_constant(fm.x)){_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);
  
  





  

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);  

{       
     _stencil_val(cm,0,0,0);   
    _stencil_val(rhs_eta,0,0,0); _stencil_val(cm,0,0,0);
    _stencil_val_a(eta,0,0,0);  
     { 
_stencil_val(alpha.x,0,0,0);;_stencil_val(cm,0,0,0); _stencil_val(cm,0 -1,0,0);_stencil_val(eta,0 -1,0,0); _stencil_val(eta,0,0,0); _stencil_val(alpha.x,1,0,0);;_stencil_val(cm,1,0,0); _stencil_val(cm,1 -1,0,0);_stencil_val(eta,1 -1,0,0); _stencil_val(eta,1,0,0);      

{ _stencil_val(alpha.x,0,0,0);;_stencil_val(cm,0,0,0); _stencil_val(cm,0 -1,0,0);_stencil_val_diagonal(eta,0 -1,0,0); _stencil_val_diagonal(eta,0,0,0); _stencil_val(alpha.x,1,0,0);;_stencil_val(cm,1,0,0); _stencil_val(cm,1 -1,0,0);_stencil_val_diagonal(eta,1 -1,0,0); _stencil_val_diagonal(eta,1,0,0);      }
    } 

{ 
_stencil_val(alpha.y,0,0,0);;_stencil_val(cm,0,0,0); _stencil_val(cm,0,0 -1,0);_stencil_val(eta,0,0 -1,0); _stencil_val(eta,0,0,0); _stencil_val(alpha.y,0,1,0);;_stencil_val(cm,0,1,0); _stencil_val(cm,0,1 -1,0);_stencil_val(eta,0,1 -1,0); _stencil_val(eta,0,1,0);      

{ _stencil_val(alpha.y,0,0,0);;_stencil_val(cm,0,0,0); _stencil_val(cm,0,0 -1,0);_stencil_val_diagonal(eta,0,0 -1,0); _stencil_val_diagonal(eta,0,0,0); _stencil_val(alpha.y,0,1,0);;_stencil_val(cm,0,1,0); _stencil_val(cm,0,1 -1,0);_stencil_val_diagonal(eta,0,1 -1,0); _stencil_val_diagonal(eta,0,1,0);      }
    }
    _stencil_val_a(eta,0,0,0);      
  }
  

}

{ 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = lev;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++)  

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double d = rigid ? 0. : - val(cm,0,0,0)*Delta;
    double n = - val(cm,0,0,0)*Delta*val(rhs_eta,0,0,0);
    val(eta,0,0,0) = 0.;
     {
      n += val(alpha.x,0,0,0)*(G*(2.*_const_fm.x/(val(cm,0,0,0) + val(cm,0 -1,0,0)))*(val(eta,0 -1,0,0) - val(eta,0,0,0))/Delta) - val(alpha.x,1,0,0)*(G*(2.*_const_fm.x/(val(cm,1,0,0) + val(cm,1 -1,0,0)))*(val(eta,1 -1,0,0) - val(eta,1,0,0))/Delta);
 
      d -= val(alpha.x,0,0,0)*(G*(2.*_const_fm.x/(val(cm,0,0,0) + val(cm,0 -1,0,0)))*(val_diagonal(eta,0 -1,0,0) - val_diagonal(eta,0,0,0))/Delta) - val(alpha.x,1,0,0)*(G*(2.*_const_fm.x/(val(cm,1,0,0) + val(cm,1 -1,0,0)))*(val_diagonal(eta,1 -1,0,0) - val_diagonal(eta,1,0,0))/Delta);
    } 

{
      n += val(alpha.y,0,0,0)*(G*(2.*_const_fm.y/(val(cm,0,0,0) + val(cm,0,0 -1,0)))*(val(eta,0,0 -1,0) - val(eta,0,0,0))/Delta) - val(alpha.y,0,1,0)*(G*(2.*_const_fm.y/(val(cm,0,1,0) + val(cm,0,1 -1,0)))*(val(eta,0,1 -1,0) - val(eta,0,1,0))/Delta);
 
      d -= val(alpha.y,0,0,0)*(G*(2.*_const_fm.y/(val(cm,0,0,0) + val(cm,0,0 -1,0)))*(val_diagonal(eta,0,0 -1,0) - val_diagonal(eta,0,0,0))/Delta) - val(alpha.y,0,1,0)*(G*(2.*_const_fm.y/(val(cm,0,1,0) + val(cm,0,1 -1,0)))*(val_diagonal(eta,0,1 -1,0) - val_diagonal(eta,0,1,0))/Delta);
    }
    val(eta,0,0,0) = d ? n/d : 0;
  }}
    

}
  }
}

}

}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);
  
  





  

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);  

{
;   
    _stencil_val(rhs_eta,0,0,0);;
    _stencil_val_a(eta,0,0,0);  
     { 
_stencil_val(alpha.x,0,0,0);;;;_stencil_val(eta,0 -1,0,0); _stencil_val(eta,0,0,0); _stencil_val(alpha.x,1,0,0);;;;_stencil_val(eta,1 -1,0,0); _stencil_val(eta,1,0,0);      

{ _stencil_val(alpha.x,0,0,0);;;;_stencil_val_diagonal(eta,0 -1,0,0); _stencil_val_diagonal(eta,0,0,0); _stencil_val(alpha.x,1,0,0);;;;_stencil_val_diagonal(eta,1 -1,0,0); _stencil_val_diagonal(eta,1,0,0);      }
    } 

{ 
_stencil_val(alpha.y,0,0,0);;;;_stencil_val(eta,0,0 -1,0); _stencil_val(eta,0,0,0); _stencil_val(alpha.y,0,1,0);;;;_stencil_val(eta,0,1 -1,0); _stencil_val(eta,0,1,0);      

{ _stencil_val(alpha.y,0,0,0);;;;_stencil_val_diagonal(eta,0,0 -1,0); _stencil_val_diagonal(eta,0,0,0); _stencil_val(alpha.y,0,1,0);;;;_stencil_val_diagonal(eta,0,1 -1,0); _stencil_val_diagonal(eta,0,1,0);      }
    }
    _stencil_val_a(eta,0,0,0);      
  }
  

}

{ 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = lev;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++)  

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double d = rigid ? 0. : - _const_cm*Delta;
    double n = - _const_cm*Delta*val(rhs_eta,0,0,0);
    val(eta,0,0,0) = 0.;
     {
      n += val(alpha.x,0,0,0)*(G*(2.*_const_fm.x/(_const_cm + _const_cm))*(val(eta,0 -1,0,0) - val(eta,0,0,0))/Delta) - val(alpha.x,1,0,0)*(G*(2.*_const_fm.x/(_const_cm + _const_cm))*(val(eta,1 -1,0,0) - val(eta,1,0,0))/Delta);
 
      d -= val(alpha.x,0,0,0)*(G*(2.*_const_fm.x/(_const_cm + _const_cm))*(val_diagonal(eta,0 -1,0,0) - val_diagonal(eta,0,0,0))/Delta) - val(alpha.x,1,0,0)*(G*(2.*_const_fm.x/(_const_cm + _const_cm))*(val_diagonal(eta,1 -1,0,0) - val_diagonal(eta,1,0,0))/Delta);
    } 

{
      n += val(alpha.y,0,0,0)*(G*(2.*_const_fm.y/(_const_cm + _const_cm))*(val(eta,0,0 -1,0) - val(eta,0,0,0))/Delta) - val(alpha.y,0,1,0)*(G*(2.*_const_fm.y/(_const_cm + _const_cm))*(val(eta,0,1 -1,0) - val(eta,0,1,0))/Delta);
 
      d -= val(alpha.y,0,0,0)*(G*(2.*_const_fm.y/(_const_cm + _const_cm))*(val_diagonal(eta,0,0 -1,0) - val_diagonal(eta,0,0,0))/Delta) - val(alpha.y,0,1,0)*(G*(2.*_const_fm.y/(_const_cm + _const_cm))*(val_diagonal(eta,0,1 -1,0) - val_diagonal(eta,0,1,0))/Delta);
    }
    val(eta,0,0,0) = d ? n/d : 0;
  }}
    

}
  }
}

}

}
end_tracing("relax_hydro","/home/jacqhugo/basilisk/src/layered/implicit.h",0);}

     
static double residual_hydro (scalar * ql, scalar * rhsl,
         scalar * resl, void * data)
{tracing("residual_hydro","/home/jacqhugo/basilisk/src/layered/implicit.h",0);
  scalar eta = ql[0], rhs_eta = rhsl[0], res_eta = resl[0];
  vector alpha = *((vector *)data);
  double maxres = 0.;
  vector  g=new_face_vector("g");
if(!is_constant(fm.x) && !is_constant(cm)){
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/implicit.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0);    

{ _stencil_val(alpha.x,0,0,0);_stencil_val(fm.x,0,0,0);_stencil_val(cm,0,0,0); _stencil_val(cm,0 -1,0,0);_stencil_val(eta,0 -1,0,0); _stencil_val(eta,0,0,0);_stencil_val_a(g.x,0,0,0);   } 

_loop.face |= (1 << 1);    

{ _stencil_val(alpha.y,0,0,0);_stencil_val(fm.y,0,0,0);_stencil_val(cm,0,0,0); _stencil_val(cm,0,0 -1,0);_stencil_val(eta,0,0 -1,0); _stencil_val(eta,0,0,0);_stencil_val_a(g.y,0,0,0);   }}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(g.x,0,0,0) = val(alpha.x,0,0,0)*(G*(2.*val(fm.x,0,0,0)/(val(cm,0,0,0) + val(cm,0 -1,0,0)))*(val(eta,0 -1,0,0) - val(eta,0,0,0))/Delta);}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(g.y,0,0,0) = val(alpha.y,0,0,0)*(G*(2.*val(fm.y,0,0,0)/(val(cm,0,0,0) + val(cm,0,0 -1,0)))*(val(eta,0,0 -1,0) - val(eta,0,0,0))/Delta);}
  

}

}
      

}
  }
}

}else if(is_constant(fm.x) && !is_constant(cm)){_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/implicit.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0);    

{ _stencil_val(alpha.x,0,0,0);;_stencil_val(cm,0,0,0); _stencil_val(cm,0 -1,0,0);_stencil_val(eta,0 -1,0,0); _stencil_val(eta,0,0,0);_stencil_val_a(g.x,0,0,0);   } 

_loop.face |= (1 << 1);    

{ _stencil_val(alpha.y,0,0,0);;_stencil_val(cm,0,0,0); _stencil_val(cm,0,0 -1,0);_stencil_val(eta,0,0 -1,0); _stencil_val(eta,0,0,0);_stencil_val_a(g.y,0,0,0);   }}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(g.x,0,0,0) = val(alpha.x,0,0,0)*(G*(2.*_const_fm.x/(val(cm,0,0,0) + val(cm,0 -1,0,0)))*(val(eta,0 -1,0,0) - val(eta,0,0,0))/Delta);}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(g.y,0,0,0) = val(alpha.y,0,0,0)*(G*(2.*_const_fm.y/(val(cm,0,0,0) + val(cm,0,0 -1,0)))*(val(eta,0,0 -1,0) - val(eta,0,0,0))/Delta);}
  

}

}
      

}
  }
}

}else if(!is_constant(fm.x) && is_constant(cm)){double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/implicit.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0);    

{ _stencil_val(alpha.x,0,0,0);_stencil_val(fm.x,0,0,0);;;_stencil_val(eta,0 -1,0,0); _stencil_val(eta,0,0,0);_stencil_val_a(g.x,0,0,0);   } 

_loop.face |= (1 << 1);    

{ _stencil_val(alpha.y,0,0,0);_stencil_val(fm.y,0,0,0);;;_stencil_val(eta,0,0 -1,0); _stencil_val(eta,0,0,0);_stencil_val_a(g.y,0,0,0);   }}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(g.x,0,0,0) = val(alpha.x,0,0,0)*(G*(2.*val(fm.x,0,0,0)/(_const_cm + _const_cm))*(val(eta,0 -1,0,0) - val(eta,0,0,0))/Delta);}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(g.y,0,0,0) = val(alpha.y,0,0,0)*(G*(2.*val(fm.y,0,0,0)/(_const_cm + _const_cm))*(val(eta,0,0 -1,0) - val(eta,0,0,0))/Delta);}
  

}

}
      

}
  }
}

}else {_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/implicit.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0);    

{ _stencil_val(alpha.x,0,0,0);;;;_stencil_val(eta,0 -1,0,0); _stencil_val(eta,0,0,0);_stencil_val_a(g.x,0,0,0);   } 

_loop.face |= (1 << 1);    

{ _stencil_val(alpha.y,0,0,0);;;;_stencil_val(eta,0,0 -1,0); _stencil_val(eta,0,0,0);_stencil_val_a(g.y,0,0,0);   }}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(g.x,0,0,0) = val(alpha.x,0,0,0)*(G*(2.*_const_fm.x/(_const_cm + _const_cm))*(val(eta,0 -1,0,0) - val(eta,0,0,0))/Delta);}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(g.y,0,0,0) = val(alpha.y,0,0,0)*(G*(2.*_const_fm.y/(_const_cm + _const_cm))*(val(eta,0,0 -1,0) - val(eta,0,0,0))/Delta);}
  

}

}
      

}
  }
}

}

  if(!is_constant(cm)){
  

  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/implicit.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{ 
_stencil_val(rhs_eta,0,0,0); _stencil_val(eta,0,0,0);    _stencil_val_a(res_eta,0,0,0);      
    
      {_stencil_val(g.x,1,0,0); _stencil_val(g.x,0,0,0);_stencil_val(cm,0,0,0);_stencil_val_r(res_eta,0,0,0);   }      {_stencil_val(g.y,0,1,0); _stencil_val(g.y,0,0,0);_stencil_val(cm,0,0,0);_stencil_val_r(res_eta,0,0,0);   }
_stencil_val(res_eta,0,0,0);
      {_stencil_val(res_eta,0,0,0);  }  
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL (reduction(max:maxres)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    val(res_eta,0,0,0) = val(rhs_eta,0,0,0) - (rigid ? 0. : val(eta,0,0,0));
    
      val(res_eta,0,0,0) += (val(g.x,1,0,0) - val(g.x,0,0,0))/(Delta*val(cm,0,0,0));      val(res_eta,0,0,0) += (val(g.y,0,1,0) - val(g.y,0,0,0))/(Delta*val(cm,0,0,0));
    if (fabs(val(res_eta,0,0,0)) > maxres)
      maxres = fabs(val(res_eta,0,0,0));
  }}
      

}
  }
}

{mpi_all_reduce_array(&maxres,MPI_DOUBLE,MPI_MAX,1);}}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  

  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/implicit.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{ 
_stencil_val(rhs_eta,0,0,0); _stencil_val(eta,0,0,0);    _stencil_val_a(res_eta,0,0,0);      
    
      {_stencil_val(g.x,1,0,0); _stencil_val(g.x,0,0,0);;_stencil_val_r(res_eta,0,0,0);   }      {_stencil_val(g.y,0,1,0); _stencil_val(g.y,0,0,0);;_stencil_val_r(res_eta,0,0,0);   }
_stencil_val(res_eta,0,0,0);
      {_stencil_val(res_eta,0,0,0);  }  
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL (reduction(max:maxres)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    val(res_eta,0,0,0) = val(rhs_eta,0,0,0) - (rigid ? 0. : val(eta,0,0,0));
    
      val(res_eta,0,0,0) += (val(g.x,1,0,0) - val(g.x,0,0,0))/(Delta*_const_cm);      val(res_eta,0,0,0) += (val(g.y,0,1,0) - val(g.y,0,0,0))/(Delta*_const_cm);
    if (fabs(val(res_eta,0,0,0)) > maxres)
      maxres = fabs(val(res_eta,0,0,0));
  }}
      

}
  }
}

{mpi_all_reduce_array(&maxres,MPI_DOUBLE,MPI_MAX,1);}}

  {delete((scalar*)((vector[]){g,{{-1},{-1}}}));{end_tracing("residual_hydro","/home/jacqhugo/basilisk/src/layered/implicit.h",0);return maxres;}}delete((scalar*)((vector[]){g,{{-1},{-1}}}));
end_tracing("residual_hydro","/home/jacqhugo/basilisk/src/layered/implicit.h",0);}




scalar res_eta = {-1};

scalar rhs_eta;
vector alpha_eta;

static int half_advection_0_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}

      static int half_advection_0(const int i,const double t,Event *_ev){tracing("half_advection_0","/home/jacqhugo/basilisk/src/layered/implicit.h",0); {
  if (theta_H < 1.)
    advect (tracers, hu, hf, (1. - theta_H)*dt);
}{end_tracing("half_advection_0","/home/jacqhugo/basilisk/src/layered/implicit.h",0);return 0;}end_tracing("half_advection_0","/home/jacqhugo/basilisk/src/layered/implicit.h",0);}





static int acceleration_0_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}      static int acceleration_0(const int i,const double t,Event *_ev){tracing("acceleration_0","/home/jacqhugo/basilisk/src/layered/implicit.h",0);
{
  vector  su=new_face_vector("su");
  alpha_eta = new_face_vector("alpha_eta");
  double C = - ( (theta_H*dt)*(theta_H*dt));
if(!is_constant(fm.x) && !is_constant(cm)){
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/implicit.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0 -1,0,0); _stencil_val(cm,0 -1,0,0);_stencil_val(cm,0,0,0);_stencil_val(fm.x,0,0,0);
    _stencil_val_a(su.x,0,0,0); _stencil_val_a(alpha_eta.x,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{       
       _stencil_val(h,-1,0,0); _stencil_val(h,-1,0,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);                 
      _stencil_val(u.x,0,0,0);_stencil_val(u.x,-1,0,0);
_stencil_val(hu.x,0,0,0);_stencil_val(hf.x,0,0,0);_stencil_val(hf.x,0,0,0);      _stencil_val_a(hu.x,0,0,0);
_stencil_val(ha.x,0,0,0); _stencil_val(hf.x,0,0,0);      _stencil_val_r(hu.x,0,0,0); 
_stencil_val(hf.x,0,0,0);      _stencil_val_r(ha.x,0,0,0); 
_stencil_val(hu.x,0,0,0);      _stencil_val_r(su.x,0,0,0); 
_stencil_val(hf.x,0,0,0);      _stencil_val_r(alpha_eta.x,0,0,0); 
    }  

point.l = 0;
    

_stencil_val_r(alpha_eta.x,0,0,0);  
  } 

_loop.face |= (1 << 1); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0,0 -1,0); _stencil_val(cm,0,0 -1,0);_stencil_val(cm,0,0,0);_stencil_val(fm.y,0,0,0);
    _stencil_val_a(su.y,0,0,0); _stencil_val_a(alpha_eta.y,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{       
       _stencil_val(h,0,-1,0); _stencil_val(h,0,-1,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);                 
      _stencil_val(u.y,0,0,0);_stencil_val(u.y,0,-1,0);
_stencil_val(hu.y,0,0,0);_stencil_val(hf.y,0,0,0);_stencil_val(hf.y,0,0,0);      _stencil_val_a(hu.y,0,0,0);
_stencil_val(ha.y,0,0,0); _stencil_val(hf.y,0,0,0);      _stencil_val_r(hu.y,0,0,0); 
_stencil_val(hf.y,0,0,0);      _stencil_val_r(ha.y,0,0,0); 
_stencil_val(hu.y,0,0,0);      _stencil_val_r(su.y,0,0,0); 
_stencil_val(hf.y,0,0,0);      _stencil_val_r(alpha_eta.y,0,0,0); 
    }  

point.l = 0;
    

_stencil_val_r(alpha_eta.y,0,0,0);  
  }}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = theta_H*(G*(2.*val(fm.x,0,0,0)/(val(cm,0,0,0) + val(cm,0 -1,0,0)))*(val(eta_r,0 -1,0,0) - val(eta_r,0,0,0))/Delta);
    val(su.x,0,0,0) = 0., val(alpha_eta.x,0,0,0) = 0.;    

for (point.l = 0; point.l < nl; point.l++) 

{
      double hl = val(h,-1,0,0) > dry ? val(h,-1,0,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      double uf = hl > 0. || hr > 0. ? (hl*val(u.x,-1,0,0) + hr*val(u.x,0,0,0))/(hl + hr) : 0.;
      val(hu.x,0,0,0) = (1. - theta_H)*(val(hu.x,0,0,0) + dt*val(hf.x,0,0,0)*ax) + theta_H*val(hf.x,0,0,0)*uf;
      val(hu.x,0,0,0) += dt*(theta_H*val(ha.x,0,0,0) - val(hf.x,0,0,0)*ax);
      val(ha.x,0,0,0) -= val(hf.x,0,0,0)*ax;
      val(su.x,0,0,0) += val(hu.x,0,0,0);
      val(alpha_eta.x,0,0,0) += val(hf.x,0,0,0);
    }  

point.l = 0;
    

val(alpha_eta.x,0,0,0) *= C;
  }}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = theta_H*(G*(2.*val(fm.y,0,0,0)/(val(cm,0,0,0) + val(cm,0,0 -1,0)))*(val(eta_r,0,0 -1,0) - val(eta_r,0,0,0))/Delta);
    val(su.y,0,0,0) = 0., val(alpha_eta.y,0,0,0) = 0.;    

for (point.l = 0; point.l < nl; point.l++) 

{
      double hl = val(h,0,-1,0) > dry ? val(h,0,-1,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      double uf = hl > 0. || hr > 0. ? (hl*val(u.y,0,-1,0) + hr*val(u.y,0,0,0))/(hl + hr) : 0.;
      val(hu.y,0,0,0) = (1. - theta_H)*(val(hu.y,0,0,0) + dt*val(hf.y,0,0,0)*ax) + theta_H*val(hf.y,0,0,0)*uf;
      val(hu.y,0,0,0) += dt*(theta_H*val(ha.y,0,0,0) - val(hf.y,0,0,0)*ax);
      val(ha.y,0,0,0) -= val(hf.y,0,0,0)*ax;
      val(su.y,0,0,0) += val(hu.y,0,0,0);
      val(alpha_eta.y,0,0,0) += val(hf.y,0,0,0);
    }  

point.l = 0;
    

val(alpha_eta.y,0,0,0) *= C;
  }}
  

}

}
      

}
  }
}

}else if(is_constant(fm.x) && !is_constant(cm)){_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/implicit.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0 -1,0,0); _stencil_val(cm,0 -1,0,0);_stencil_val(cm,0,0,0);;
    _stencil_val_a(su.x,0,0,0); _stencil_val_a(alpha_eta.x,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{       
       _stencil_val(h,-1,0,0); _stencil_val(h,-1,0,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);                 
      _stencil_val(u.x,0,0,0);_stencil_val(u.x,-1,0,0);
_stencil_val(hu.x,0,0,0);_stencil_val(hf.x,0,0,0);_stencil_val(hf.x,0,0,0);      _stencil_val_a(hu.x,0,0,0);
_stencil_val(ha.x,0,0,0); _stencil_val(hf.x,0,0,0);      _stencil_val_r(hu.x,0,0,0); 
_stencil_val(hf.x,0,0,0);      _stencil_val_r(ha.x,0,0,0); 
_stencil_val(hu.x,0,0,0);      _stencil_val_r(su.x,0,0,0); 
_stencil_val(hf.x,0,0,0);      _stencil_val_r(alpha_eta.x,0,0,0); 
    }  

point.l = 0;
    

_stencil_val_r(alpha_eta.x,0,0,0);  
  } 

_loop.face |= (1 << 1); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0,0 -1,0); _stencil_val(cm,0,0 -1,0);_stencil_val(cm,0,0,0);;
    _stencil_val_a(su.y,0,0,0); _stencil_val_a(alpha_eta.y,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{       
       _stencil_val(h,0,-1,0); _stencil_val(h,0,-1,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);                 
      _stencil_val(u.y,0,0,0);_stencil_val(u.y,0,-1,0);
_stencil_val(hu.y,0,0,0);_stencil_val(hf.y,0,0,0);_stencil_val(hf.y,0,0,0);      _stencil_val_a(hu.y,0,0,0);
_stencil_val(ha.y,0,0,0); _stencil_val(hf.y,0,0,0);      _stencil_val_r(hu.y,0,0,0); 
_stencil_val(hf.y,0,0,0);      _stencil_val_r(ha.y,0,0,0); 
_stencil_val(hu.y,0,0,0);      _stencil_val_r(su.y,0,0,0); 
_stencil_val(hf.y,0,0,0);      _stencil_val_r(alpha_eta.y,0,0,0); 
    }  

point.l = 0;
    

_stencil_val_r(alpha_eta.y,0,0,0);  
  }}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = theta_H*(G*(2.*_const_fm.x/(val(cm,0,0,0) + val(cm,0 -1,0,0)))*(val(eta_r,0 -1,0,0) - val(eta_r,0,0,0))/Delta);
    val(su.x,0,0,0) = 0., val(alpha_eta.x,0,0,0) = 0.;    

for (point.l = 0; point.l < nl; point.l++) 

{
      double hl = val(h,-1,0,0) > dry ? val(h,-1,0,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      double uf = hl > 0. || hr > 0. ? (hl*val(u.x,-1,0,0) + hr*val(u.x,0,0,0))/(hl + hr) : 0.;
      val(hu.x,0,0,0) = (1. - theta_H)*(val(hu.x,0,0,0) + dt*val(hf.x,0,0,0)*ax) + theta_H*val(hf.x,0,0,0)*uf;
      val(hu.x,0,0,0) += dt*(theta_H*val(ha.x,0,0,0) - val(hf.x,0,0,0)*ax);
      val(ha.x,0,0,0) -= val(hf.x,0,0,0)*ax;
      val(su.x,0,0,0) += val(hu.x,0,0,0);
      val(alpha_eta.x,0,0,0) += val(hf.x,0,0,0);
    }  

point.l = 0;
    

val(alpha_eta.x,0,0,0) *= C;
  }}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = theta_H*(G*(2.*_const_fm.y/(val(cm,0,0,0) + val(cm,0,0 -1,0)))*(val(eta_r,0,0 -1,0) - val(eta_r,0,0,0))/Delta);
    val(su.y,0,0,0) = 0., val(alpha_eta.y,0,0,0) = 0.;    

for (point.l = 0; point.l < nl; point.l++) 

{
      double hl = val(h,0,-1,0) > dry ? val(h,0,-1,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      double uf = hl > 0. || hr > 0. ? (hl*val(u.y,0,-1,0) + hr*val(u.y,0,0,0))/(hl + hr) : 0.;
      val(hu.y,0,0,0) = (1. - theta_H)*(val(hu.y,0,0,0) + dt*val(hf.y,0,0,0)*ax) + theta_H*val(hf.y,0,0,0)*uf;
      val(hu.y,0,0,0) += dt*(theta_H*val(ha.y,0,0,0) - val(hf.y,0,0,0)*ax);
      val(ha.y,0,0,0) -= val(hf.y,0,0,0)*ax;
      val(su.y,0,0,0) += val(hu.y,0,0,0);
      val(alpha_eta.y,0,0,0) += val(hf.y,0,0,0);
    }  

point.l = 0;
    

val(alpha_eta.y,0,0,0) *= C;
  }}
  

}

}
      

}
  }
}

}else if(!is_constant(fm.x) && is_constant(cm)){double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/implicit.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0 -1,0,0);;;_stencil_val(fm.x,0,0,0);
    _stencil_val_a(su.x,0,0,0); _stencil_val_a(alpha_eta.x,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{       
       _stencil_val(h,-1,0,0); _stencil_val(h,-1,0,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);                 
      _stencil_val(u.x,0,0,0);_stencil_val(u.x,-1,0,0);
_stencil_val(hu.x,0,0,0);_stencil_val(hf.x,0,0,0);_stencil_val(hf.x,0,0,0);      _stencil_val_a(hu.x,0,0,0);
_stencil_val(ha.x,0,0,0); _stencil_val(hf.x,0,0,0);      _stencil_val_r(hu.x,0,0,0); 
_stencil_val(hf.x,0,0,0);      _stencil_val_r(ha.x,0,0,0); 
_stencil_val(hu.x,0,0,0);      _stencil_val_r(su.x,0,0,0); 
_stencil_val(hf.x,0,0,0);      _stencil_val_r(alpha_eta.x,0,0,0); 
    }  

point.l = 0;
    

_stencil_val_r(alpha_eta.x,0,0,0);  
  } 

_loop.face |= (1 << 1); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0,0 -1,0);;;_stencil_val(fm.y,0,0,0);
    _stencil_val_a(su.y,0,0,0); _stencil_val_a(alpha_eta.y,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{       
       _stencil_val(h,0,-1,0); _stencil_val(h,0,-1,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);                 
      _stencil_val(u.y,0,0,0);_stencil_val(u.y,0,-1,0);
_stencil_val(hu.y,0,0,0);_stencil_val(hf.y,0,0,0);_stencil_val(hf.y,0,0,0);      _stencil_val_a(hu.y,0,0,0);
_stencil_val(ha.y,0,0,0); _stencil_val(hf.y,0,0,0);      _stencil_val_r(hu.y,0,0,0); 
_stencil_val(hf.y,0,0,0);      _stencil_val_r(ha.y,0,0,0); 
_stencil_val(hu.y,0,0,0);      _stencil_val_r(su.y,0,0,0); 
_stencil_val(hf.y,0,0,0);      _stencil_val_r(alpha_eta.y,0,0,0); 
    }  

point.l = 0;
    

_stencil_val_r(alpha_eta.y,0,0,0);  
  }}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = theta_H*(G*(2.*val(fm.x,0,0,0)/(_const_cm + _const_cm))*(val(eta_r,0 -1,0,0) - val(eta_r,0,0,0))/Delta);
    val(su.x,0,0,0) = 0., val(alpha_eta.x,0,0,0) = 0.;    

for (point.l = 0; point.l < nl; point.l++) 

{
      double hl = val(h,-1,0,0) > dry ? val(h,-1,0,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      double uf = hl > 0. || hr > 0. ? (hl*val(u.x,-1,0,0) + hr*val(u.x,0,0,0))/(hl + hr) : 0.;
      val(hu.x,0,0,0) = (1. - theta_H)*(val(hu.x,0,0,0) + dt*val(hf.x,0,0,0)*ax) + theta_H*val(hf.x,0,0,0)*uf;
      val(hu.x,0,0,0) += dt*(theta_H*val(ha.x,0,0,0) - val(hf.x,0,0,0)*ax);
      val(ha.x,0,0,0) -= val(hf.x,0,0,0)*ax;
      val(su.x,0,0,0) += val(hu.x,0,0,0);
      val(alpha_eta.x,0,0,0) += val(hf.x,0,0,0);
    }  

point.l = 0;
    

val(alpha_eta.x,0,0,0) *= C;
  }}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = theta_H*(G*(2.*val(fm.y,0,0,0)/(_const_cm + _const_cm))*(val(eta_r,0,0 -1,0) - val(eta_r,0,0,0))/Delta);
    val(su.y,0,0,0) = 0., val(alpha_eta.y,0,0,0) = 0.;    

for (point.l = 0; point.l < nl; point.l++) 

{
      double hl = val(h,0,-1,0) > dry ? val(h,0,-1,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      double uf = hl > 0. || hr > 0. ? (hl*val(u.y,0,-1,0) + hr*val(u.y,0,0,0))/(hl + hr) : 0.;
      val(hu.y,0,0,0) = (1. - theta_H)*(val(hu.y,0,0,0) + dt*val(hf.y,0,0,0)*ax) + theta_H*val(hf.y,0,0,0)*uf;
      val(hu.y,0,0,0) += dt*(theta_H*val(ha.y,0,0,0) - val(hf.y,0,0,0)*ax);
      val(ha.y,0,0,0) -= val(hf.y,0,0,0)*ax;
      val(su.y,0,0,0) += val(hu.y,0,0,0);
      val(alpha_eta.y,0,0,0) += val(hf.y,0,0,0);
    }  

point.l = 0;
    

val(alpha_eta.y,0,0,0) *= C;
  }}
  

}

}
      

}
  }
}

}else {_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/implicit.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0 -1,0,0);;;;
    _stencil_val_a(su.x,0,0,0); _stencil_val_a(alpha_eta.x,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{       
       _stencil_val(h,-1,0,0); _stencil_val(h,-1,0,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);                 
      _stencil_val(u.x,0,0,0);_stencil_val(u.x,-1,0,0);
_stencil_val(hu.x,0,0,0);_stencil_val(hf.x,0,0,0);_stencil_val(hf.x,0,0,0);      _stencil_val_a(hu.x,0,0,0);
_stencil_val(ha.x,0,0,0); _stencil_val(hf.x,0,0,0);      _stencil_val_r(hu.x,0,0,0); 
_stencil_val(hf.x,0,0,0);      _stencil_val_r(ha.x,0,0,0); 
_stencil_val(hu.x,0,0,0);      _stencil_val_r(su.x,0,0,0); 
_stencil_val(hf.x,0,0,0);      _stencil_val_r(alpha_eta.x,0,0,0); 
    }  

point.l = 0;
    

_stencil_val_r(alpha_eta.x,0,0,0);  
  } 

_loop.face |= (1 << 1); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0,0 -1,0);;;;
    _stencil_val_a(su.y,0,0,0); _stencil_val_a(alpha_eta.y,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{       
       _stencil_val(h,0,-1,0); _stencil_val(h,0,-1,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);                 
      _stencil_val(u.y,0,0,0);_stencil_val(u.y,0,-1,0);
_stencil_val(hu.y,0,0,0);_stencil_val(hf.y,0,0,0);_stencil_val(hf.y,0,0,0);      _stencil_val_a(hu.y,0,0,0);
_stencil_val(ha.y,0,0,0); _stencil_val(hf.y,0,0,0);      _stencil_val_r(hu.y,0,0,0); 
_stencil_val(hf.y,0,0,0);      _stencil_val_r(ha.y,0,0,0); 
_stencil_val(hu.y,0,0,0);      _stencil_val_r(su.y,0,0,0); 
_stencil_val(hf.y,0,0,0);      _stencil_val_r(alpha_eta.y,0,0,0); 
    }  

point.l = 0;
    

_stencil_val_r(alpha_eta.y,0,0,0);  
  }}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = theta_H*(G*(2.*_const_fm.x/(_const_cm + _const_cm))*(val(eta_r,0 -1,0,0) - val(eta_r,0,0,0))/Delta);
    val(su.x,0,0,0) = 0., val(alpha_eta.x,0,0,0) = 0.;    

for (point.l = 0; point.l < nl; point.l++) 

{
      double hl = val(h,-1,0,0) > dry ? val(h,-1,0,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      double uf = hl > 0. || hr > 0. ? (hl*val(u.x,-1,0,0) + hr*val(u.x,0,0,0))/(hl + hr) : 0.;
      val(hu.x,0,0,0) = (1. - theta_H)*(val(hu.x,0,0,0) + dt*val(hf.x,0,0,0)*ax) + theta_H*val(hf.x,0,0,0)*uf;
      val(hu.x,0,0,0) += dt*(theta_H*val(ha.x,0,0,0) - val(hf.x,0,0,0)*ax);
      val(ha.x,0,0,0) -= val(hf.x,0,0,0)*ax;
      val(su.x,0,0,0) += val(hu.x,0,0,0);
      val(alpha_eta.x,0,0,0) += val(hf.x,0,0,0);
    }  

point.l = 0;
    

val(alpha_eta.x,0,0,0) *= C;
  }}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = theta_H*(G*(2.*_const_fm.y/(_const_cm + _const_cm))*(val(eta_r,0,0 -1,0) - val(eta_r,0,0,0))/Delta);
    val(su.y,0,0,0) = 0., val(alpha_eta.y,0,0,0) = 0.;    

for (point.l = 0; point.l < nl; point.l++) 

{
      double hl = val(h,0,-1,0) > dry ? val(h,0,-1,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      double uf = hl > 0. || hr > 0. ? (hl*val(u.y,0,-1,0) + hr*val(u.y,0,0,0))/(hl + hr) : 0.;
      val(hu.y,0,0,0) = (1. - theta_H)*(val(hu.y,0,0,0) + dt*val(hf.y,0,0,0)*ax) + theta_H*val(hf.y,0,0,0)*uf;
      val(hu.y,0,0,0) += dt*(theta_H*val(ha.y,0,0,0) - val(hf.y,0,0,0)*ax);
      val(ha.y,0,0,0) -= val(hf.y,0,0,0)*ax;
      val(su.y,0,0,0) += val(hu.y,0,0,0);
      val(alpha_eta.y,0,0,0) += val(hf.y,0,0,0);
    }  

point.l = 0;
    

val(alpha_eta.y,0,0,0) *= C;
  }}
  

}

}
      

}
  }
}

}

  rhs_eta = new_scalar("rhs_eta");
  if(!is_constant(cm)){
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/implicit.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{ 
_stencil_val(eta,0,0,0);    _stencil_val_a(rhs_eta,0,0,0);     
    
      {_stencil_val(su.x,1,0,0); _stencil_val(su.x,0,0,0);_stencil_val(cm,0,0,0);_stencil_val_r(rhs_eta,0,0,0);   }      {_stencil_val(su.y,0,1,0); _stencil_val(su.y,0,0,0);_stencil_val(cm,0,0,0);_stencil_val_r(rhs_eta,0,0,0);   }
  }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    val(rhs_eta,0,0,0) = rigid ? 0. : val(eta,0,0,0);
    
      val(rhs_eta,0,0,0) -= dt*(val(su.x,1,0,0) - val(su.x,0,0,0))/(Delta*val(cm,0,0,0));      val(rhs_eta,0,0,0) -= dt*(val(su.y,0,1,0) - val(su.y,0,0,0))/(Delta*val(cm,0,0,0));
  }}
      

}
  }
}

}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/implicit.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{ 
_stencil_val(eta,0,0,0);    _stencil_val_a(rhs_eta,0,0,0);     
    
      {_stencil_val(su.x,1,0,0); _stencil_val(su.x,0,0,0);;_stencil_val_r(rhs_eta,0,0,0);   }      {_stencil_val(su.y,0,1,0); _stencil_val(su.y,0,0,0);;_stencil_val_r(rhs_eta,0,0,0);   }
  }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    val(rhs_eta,0,0,0) = rigid ? 0. : val(eta,0,0,0);
    
      val(rhs_eta,0,0,0) -= dt*(val(su.x,1,0,0) - val(su.x,0,0,0))/(Delta*_const_cm);      val(rhs_eta,0,0,0) -= dt*(val(su.y,0,1,0) - val(su.y,0,0,0))/(Delta*_const_cm);
  }}
      

}
  }
}

}





  restriction (((scalar[]){cm, fm.x, fm.y, alpha_eta.x, alpha_eta.y,{-1}}));delete((scalar*)((vector[]){su,{{-1},{-1}}}));

}{end_tracing("acceleration_0","/home/jacqhugo/basilisk/src/layered/implicit.h",0);return 0;}end_tracing("acceleration_0","/home/jacqhugo/basilisk/src/layered/implicit.h",0);}







static int pressure_0_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}      static int pressure_0(const int i,const double t,Event *_ev){tracing("pressure_0","/home/jacqhugo/basilisk/src/layered/implicit.h",0);
{
  mgH = mg_solve (

(

scalar *

)

((scalar[]){eta_r,{-1}}),

( 

scalar *

)

((scalar[]) {rhs_eta,{-1}}), residual_hydro, relax_hydro, &alpha_eta

, 4

, res_eta.i >= 0 ? (scalar *)((scalar[]){res_eta,{-1}}) : NULL
, mgH.minlevel
, TOLERANCE);
  delete (((scalar[]){rhs_eta, alpha_eta.x, alpha_eta.y,{-1}}));

if(!is_constant(fm.x) && !is_constant(cm)){
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/implicit.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0 -1,0,0); _stencil_val(cm,0 -1,0,0);_stencil_val(cm,0,0,0);_stencil_val(fm.x,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{ 
_stencil_val(hf.x,0,0,0);      _stencil_val_r(ha.x,0,0,0);        
       _stencil_val(h,-1,0,0); _stencil_val(h,-1,0,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);                 
      _stencil_val(u.x,0,0,0);_stencil_val(u.x,-1,0,0);
_stencil_val(hf.x,0,0,0);_stencil_val(ha.x,0,0,0);_stencil_val(ha.x,0,0,0);      _stencil_val_a(hu.x,0,0,0);      
    }  

point.l = 0;
  

} 

_loop.face |= (1 << 1); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0,0 -1,0); _stencil_val(cm,0,0 -1,0);_stencil_val(cm,0,0,0);_stencil_val(fm.y,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{ 
_stencil_val(hf.y,0,0,0);      _stencil_val_r(ha.y,0,0,0);        
       _stencil_val(h,0,-1,0); _stencil_val(h,0,-1,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);                 
      _stencil_val(u.y,0,0,0);_stencil_val(u.y,0,-1,0);
_stencil_val(hf.y,0,0,0);_stencil_val(ha.y,0,0,0);_stencil_val(ha.y,0,0,0);      _stencil_val_a(hu.y,0,0,0);      
    }  

point.l = 0;
  

}}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = theta_H*(G*(2.*val(fm.x,0,0,0)/(val(cm,0,0,0) + val(cm,0 -1,0,0)))*(val(eta_r,0 -1,0,0) - val(eta_r,0,0,0))/Delta);    

for (point.l = 0; point.l < nl; point.l++) 

{
      val(ha.x,0,0,0) += val(hf.x,0,0,0)*ax;
      double hl = val(h,-1,0,0) > dry ? val(h,-1,0,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      double uf = hl > 0. || hr > 0. ? (hl*val(u.x,-1,0,0) + hr*val(u.x,0,0,0))/(hl + hr) : 0.;
      val(hu.x,0,0,0) = theta_H*(val(hf.x,0,0,0)*uf + dt*val(ha.x,0,0,0)) - dt*val(ha.x,0,0,0);
    }  

point.l = 0;
  

}}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = theta_H*(G*(2.*val(fm.y,0,0,0)/(val(cm,0,0,0) + val(cm,0,0 -1,0)))*(val(eta_r,0,0 -1,0) - val(eta_r,0,0,0))/Delta);    

for (point.l = 0; point.l < nl; point.l++) 

{
      val(ha.y,0,0,0) += val(hf.y,0,0,0)*ax;
      double hl = val(h,0,-1,0) > dry ? val(h,0,-1,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      double uf = hl > 0. || hr > 0. ? (hl*val(u.y,0,-1,0) + hr*val(u.y,0,0,0))/(hl + hr) : 0.;
      val(hu.y,0,0,0) = theta_H*(val(hf.y,0,0,0)*uf + dt*val(ha.y,0,0,0)) - dt*val(ha.y,0,0,0);
    }  

point.l = 0;
  

}}
  

}

}
      

}
  }
}

}else if(is_constant(fm.x) && !is_constant(cm)){_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/implicit.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0 -1,0,0); _stencil_val(cm,0 -1,0,0);_stencil_val(cm,0,0,0);;    

for (point.l = 0; point.l < nl; point.l++) 

{ 
_stencil_val(hf.x,0,0,0);      _stencil_val_r(ha.x,0,0,0);        
       _stencil_val(h,-1,0,0); _stencil_val(h,-1,0,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);                 
      _stencil_val(u.x,0,0,0);_stencil_val(u.x,-1,0,0);
_stencil_val(hf.x,0,0,0);_stencil_val(ha.x,0,0,0);_stencil_val(ha.x,0,0,0);      _stencil_val_a(hu.x,0,0,0);      
    }  

point.l = 0;
  

} 

_loop.face |= (1 << 1); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0,0 -1,0); _stencil_val(cm,0,0 -1,0);_stencil_val(cm,0,0,0);;    

for (point.l = 0; point.l < nl; point.l++) 

{ 
_stencil_val(hf.y,0,0,0);      _stencil_val_r(ha.y,0,0,0);        
       _stencil_val(h,0,-1,0); _stencil_val(h,0,-1,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);                 
      _stencil_val(u.y,0,0,0);_stencil_val(u.y,0,-1,0);
_stencil_val(hf.y,0,0,0);_stencil_val(ha.y,0,0,0);_stencil_val(ha.y,0,0,0);      _stencil_val_a(hu.y,0,0,0);      
    }  

point.l = 0;
  

}}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = theta_H*(G*(2.*_const_fm.x/(val(cm,0,0,0) + val(cm,0 -1,0,0)))*(val(eta_r,0 -1,0,0) - val(eta_r,0,0,0))/Delta);    

for (point.l = 0; point.l < nl; point.l++) 

{
      val(ha.x,0,0,0) += val(hf.x,0,0,0)*ax;
      double hl = val(h,-1,0,0) > dry ? val(h,-1,0,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      double uf = hl > 0. || hr > 0. ? (hl*val(u.x,-1,0,0) + hr*val(u.x,0,0,0))/(hl + hr) : 0.;
      val(hu.x,0,0,0) = theta_H*(val(hf.x,0,0,0)*uf + dt*val(ha.x,0,0,0)) - dt*val(ha.x,0,0,0);
    }  

point.l = 0;
  

}}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = theta_H*(G*(2.*_const_fm.y/(val(cm,0,0,0) + val(cm,0,0 -1,0)))*(val(eta_r,0,0 -1,0) - val(eta_r,0,0,0))/Delta);    

for (point.l = 0; point.l < nl; point.l++) 

{
      val(ha.y,0,0,0) += val(hf.y,0,0,0)*ax;
      double hl = val(h,0,-1,0) > dry ? val(h,0,-1,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      double uf = hl > 0. || hr > 0. ? (hl*val(u.y,0,-1,0) + hr*val(u.y,0,0,0))/(hl + hr) : 0.;
      val(hu.y,0,0,0) = theta_H*(val(hf.y,0,0,0)*uf + dt*val(ha.y,0,0,0)) - dt*val(ha.y,0,0,0);
    }  

point.l = 0;
  

}}
  

}

}
      

}
  }
}

}else if(!is_constant(fm.x) && is_constant(cm)){double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/implicit.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0 -1,0,0);;;_stencil_val(fm.x,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{ 
_stencil_val(hf.x,0,0,0);      _stencil_val_r(ha.x,0,0,0);        
       _stencil_val(h,-1,0,0); _stencil_val(h,-1,0,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);                 
      _stencil_val(u.x,0,0,0);_stencil_val(u.x,-1,0,0);
_stencil_val(hf.x,0,0,0);_stencil_val(ha.x,0,0,0);_stencil_val(ha.x,0,0,0);      _stencil_val_a(hu.x,0,0,0);      
    }  

point.l = 0;
  

} 

_loop.face |= (1 << 1); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0,0 -1,0);;;_stencil_val(fm.y,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{ 
_stencil_val(hf.y,0,0,0);      _stencil_val_r(ha.y,0,0,0);        
       _stencil_val(h,0,-1,0); _stencil_val(h,0,-1,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);                 
      _stencil_val(u.y,0,0,0);_stencil_val(u.y,0,-1,0);
_stencil_val(hf.y,0,0,0);_stencil_val(ha.y,0,0,0);_stencil_val(ha.y,0,0,0);      _stencil_val_a(hu.y,0,0,0);      
    }  

point.l = 0;
  

}}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = theta_H*(G*(2.*val(fm.x,0,0,0)/(_const_cm + _const_cm))*(val(eta_r,0 -1,0,0) - val(eta_r,0,0,0))/Delta);    

for (point.l = 0; point.l < nl; point.l++) 

{
      val(ha.x,0,0,0) += val(hf.x,0,0,0)*ax;
      double hl = val(h,-1,0,0) > dry ? val(h,-1,0,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      double uf = hl > 0. || hr > 0. ? (hl*val(u.x,-1,0,0) + hr*val(u.x,0,0,0))/(hl + hr) : 0.;
      val(hu.x,0,0,0) = theta_H*(val(hf.x,0,0,0)*uf + dt*val(ha.x,0,0,0)) - dt*val(ha.x,0,0,0);
    }  

point.l = 0;
  

}}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = theta_H*(G*(2.*val(fm.y,0,0,0)/(_const_cm + _const_cm))*(val(eta_r,0,0 -1,0) - val(eta_r,0,0,0))/Delta);    

for (point.l = 0; point.l < nl; point.l++) 

{
      val(ha.y,0,0,0) += val(hf.y,0,0,0)*ax;
      double hl = val(h,0,-1,0) > dry ? val(h,0,-1,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      double uf = hl > 0. || hr > 0. ? (hl*val(u.y,0,-1,0) + hr*val(u.y,0,0,0))/(hl + hr) : 0.;
      val(hu.y,0,0,0) = theta_H*(val(hf.y,0,0,0)*uf + dt*val(ha.y,0,0,0)) - dt*val(ha.y,0,0,0);
    }  

point.l = 0;
  

}}
  

}

}
      

}
  }
}

}else {_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/implicit.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0 -1,0,0);;;;    

for (point.l = 0; point.l < nl; point.l++) 

{ 
_stencil_val(hf.x,0,0,0);      _stencil_val_r(ha.x,0,0,0);        
       _stencil_val(h,-1,0,0); _stencil_val(h,-1,0,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);                 
      _stencil_val(u.x,0,0,0);_stencil_val(u.x,-1,0,0);
_stencil_val(hf.x,0,0,0);_stencil_val(ha.x,0,0,0);_stencil_val(ha.x,0,0,0);      _stencil_val_a(hu.x,0,0,0);      
    }  

point.l = 0;
  

} 

_loop.face |= (1 << 1); 

{     
     _stencil_val(eta_r,0,0,0);_stencil_val(eta_r,0,0 -1,0);;;;    

for (point.l = 0; point.l < nl; point.l++) 

{ 
_stencil_val(hf.y,0,0,0);      _stencil_val_r(ha.y,0,0,0);        
       _stencil_val(h,0,-1,0); _stencil_val(h,0,-1,0);       
       _stencil_val(h,0,0,0); _stencil_val(h,0,0,0);                 
      _stencil_val(u.y,0,0,0);_stencil_val(u.y,0,-1,0);
_stencil_val(hf.y,0,0,0);_stencil_val(ha.y,0,0,0);_stencil_val(ha.y,0,0,0);      _stencil_val_a(hu.y,0,0,0);      
    }  

point.l = 0;
  

}}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = theta_H*(G*(2.*_const_fm.x/(_const_cm + _const_cm))*(val(eta_r,0 -1,0,0) - val(eta_r,0,0,0))/Delta);    

for (point.l = 0; point.l < nl; point.l++) 

{
      val(ha.x,0,0,0) += val(hf.x,0,0,0)*ax;
      double hl = val(h,-1,0,0) > dry ? val(h,-1,0,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      double uf = hl > 0. || hr > 0. ? (hl*val(u.x,-1,0,0) + hr*val(u.x,0,0,0))/(hl + hr) : 0.;
      val(hu.x,0,0,0) = theta_H*(val(hf.x,0,0,0)*uf + dt*val(ha.x,0,0,0)) - dt*val(ha.x,0,0,0);
    }  

point.l = 0;
  

}}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ax = theta_H*(G*(2.*_const_fm.y/(_const_cm + _const_cm))*(val(eta_r,0,0 -1,0) - val(eta_r,0,0,0))/Delta);    

for (point.l = 0; point.l < nl; point.l++) 

{
      val(ha.y,0,0,0) += val(hf.y,0,0,0)*ax;
      double hl = val(h,0,-1,0) > dry ? val(h,0,-1,0) : 0.;
      double hr = val(h,0,0,0) > dry ? val(h,0,0,0) : 0.;
      double uf = hl > 0. || hr > 0. ? (hl*val(u.y,0,-1,0) + hr*val(u.y,0,0,0))/(hl + hr) : 0.;
      val(hu.y,0,0,0) = theta_H*(val(hf.y,0,0,0)*uf + dt*val(ha.y,0,0,0)) - dt*val(ha.y,0,0,0);
    }  

point.l = 0;
  

}}
  

}

}
      

}
  }
}

}
}{end_tracing("pressure_0","/home/jacqhugo/basilisk/src/layered/implicit.h",0);return 0;}end_tracing("pressure_0","/home/jacqhugo/basilisk/src/layered/implicit.h",0);}










const double Omega = 7.292205e-5;

const double Cb = 2e-3;
scalar  zbs={1};

static int acceleration_1_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}




      static int acceleration_1(const int i,const double t,Event *_ev){tracing("acceleration_1","/home/jacqhugo/basilisk/src/layered/coriolis.h",0);
{
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/coriolis.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);     

{
  for (point.l = 0; point.l < nl; point.l++)
      

{_stencil_val(h,0,0,0); {                                                    
 _stencil_val(h,0,0,0);_stencil_val(u.y,0,0,0);_stencil_val(u.y,0,0,0);_stencil_val(u.x,0,0,0);_stencil_val(u.x,0,0,0);_stencil_val(zbs,0,0,0);_stencil_val(zb,0,0,0);_stencil_val(zbs,0,0,0);_stencil_val(zb,0,0,0);_stencil_val(zbs,0,0,0);_stencil_val(zb,0,0,0); _stencil_val(h,0,0,0); _stencil_val(h,0,0,-1);_stencil_val(h,0,0,0);_stencil_val(u.y,0,0,0);_stencil_val(u.y,0,0,0);_stencil_val(u.x,0,0,0);_stencil_val(u.x,0,0,0);_stencil_val(zbs,0,0,0);_stencil_val(zb,0,0,0);_stencil_val(zbs,0,0,0);_stencil_val(zb,0,0,0);_stencil_val(zbs,0,0,0);_stencil_val(zb,0,0,0); _stencil_val(h,0,0,0); _stencil_val(h,0,0,-1);                         
 
 
 
        
  {
_stencil_val(ha.x,0,0,0); _stencil_val(ha.x,1,0,0);_stencil_val(hf.x,0,0,0); _stencil_val(hf.x,1,0,0); 
         _stencil_val(u.x,0,0,0);_stencil_val(u.x,0,0,0);_stencil_val(u.y,0,0,0); 
} 

{
_stencil_val(ha.y,0,0,0); _stencil_val(ha.y,0,1,0);_stencil_val(hf.y,0,0,0); _stencil_val(hf.y,0,1,0); 
         _stencil_val(u.y,0,0,0);_stencil_val(u.y,0,0,0);_stencil_val(u.x,0,0,0); 
}
 
   {_stencil_val_a(u.x,0,0,0);      }   {_stencil_val_a(u.y,0,0,0);      }
      }   }  

point.l = 0;
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)     

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
  for (point.l = 0; point.l < nl; point.l++)
      

if (val(h,0,0,0) > dry) {
 coord b0 = { - (point.l > 0 && val(h,0,0,-1) > dry ? 0. : val(h,0,0,0) < dry ? 1e30f : Cb*( (val(zb,0,0,0)/val(zbs,0,0,0))*(val(zb,0,0,0)/val(zbs,0,0,0))*(val(zb,0,0,0)/val(zbs,0,0,0)))*(sqrt(( (val(u.x,0,0,0))*(val(u.x,0,0,0))) + ( (val(u.y,0,0,0))*(val(u.y,0,0,0)))))/val(h,0,0,0)), - (point.l > 0 && val(h,0,0,-1) > dry ? 0. : val(h,0,0,0) < dry ? 1e30f : Cb*( (val(zb,0,0,0)/val(zbs,0,0,0))*(val(zb,0,0,0)/val(zbs,0,0,0))*(val(zb,0,0,0)/val(zbs,0,0,0)))*(sqrt(( (val(u.x,0,0,0))*(val(u.x,0,0,0))) + ( (val(u.y,0,0,0))*(val(u.y,0,0,0)))))/val(h,0,0,0)) }, b1 = { (2.*Omega*sin(y*3.14159265358979/180.)), -(2.*Omega*sin(y*3.14159265358979/180.)) };
 coord m0 = { 1. - 1.*dt*b0.x, 1. - 1.*dt*b0.y };
 coord m1 = { - 1.*dt*b1.x, - 1.*dt*b1.y };
 double det = m0.x*m0.y - m1.x*m1.y;
        coord r, a;
  {
   a.x = dt*(val(ha.x,0,0,0) + val(ha.x,1,0,0))/(val(hf.x,0,0,0) + val(hf.x,1,0,0) + dry);
   r.x = val(u.x,0,0,0) + (1. - 1.)*dt*(b0.x*val(u.x,0,0,0) + b1.x*val(u.y,0,0,0)) + a.x;
 } 

{
   a.y = dt*(val(ha.y,0,0,0) + val(ha.y,0,1,0))/(val(hf.y,0,0,0) + val(hf.y,0,1,0) + dry);
   r.y = val(u.y,0,0,0) + (1. - 1.)*dt*(b0.y*val(u.y,0,0,0) + b1.y*val(u.x,0,0,0)) + a.y;
 }
 
   val(u.x,0,0,0) = (m0.y*r.x - m1.x*r.y)/det - a.x;   val(u.y,0,0,0) = (m0.x*r.y - m1.y*r.x)/det - a.y;
      }  

point.l = 0;
}}
      

}
  }
}

}{end_tracing("acceleration_1","/home/jacqhugo/basilisk/src/layered/coriolis.h",0);return 0;}end_tracing("acceleration_1","/home/jacqhugo/basilisk/src/layered/coriolis.h",0);}






coord geostrophic_velocity (Point point)
{if(!is_constant(fm.x) && !is_constant(cm)){{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

coord ug;
  static const coord a = {-1., 1.};
   {
    double hl = val(h,0,0,0) > dry && val(h,-1,0,0) > dry, hr = val(h,0,0,0) > dry && val(h,1,0,0) > dry;
    ug.y = a.y*G*(hl*(2.*val(fm.x,0,0,0)/(val(cm,0,0,0) + val(cm,0 -1,0,0)))*(val(eta,0,0,0) - val(eta,-1,0,0)) +
    hr*(2.*val(fm.x,1,0,0)/(val(cm,1,0,0) + val(cm,1 -1,0,0)))*(val(eta,1,0,0) - val(eta,0,0,0)))
    /(Delta*(2.*Omega*sin(y*3.14159265358979/180.))*(hl + hr + 1e-12));
  } 

{
    double hl = val(h,0,0,0) > dry && val(h,0,-1,0) > dry, hr = val(h,0,0,0) > dry && val(h,0,1,0) > dry;
    ug.x = a.x*G*(hl*(2.*val(fm.y,0,0,0)/(val(cm,0,0,0) + val(cm,0,0 -1,0)))*(val(eta,0,0,0) - val(eta,0,-1,0)) +
    hr*(2.*val(fm.y,0,1,0)/(val(cm,0,1,0) + val(cm,0,1 -1,0)))*(val(eta,0,1,0) - val(eta,0,0,0)))
    /(Delta*(2.*Omega*sin(y*3.14159265358979/180.))*(hl + hr + 1e-12));
  }
  return ug;
}}else if(is_constant(fm.x) && !is_constant(cm)){_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);

{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

coord ug;
  static const coord a = {-1., 1.};
   {
    double hl = val(h,0,0,0) > dry && val(h,-1,0,0) > dry, hr = val(h,0,0,0) > dry && val(h,1,0,0) > dry;
    ug.y = a.y*G*(hl*(2.*_const_fm.x/(val(cm,0,0,0) + val(cm,0 -1,0,0)))*(val(eta,0,0,0) - val(eta,-1,0,0)) +
    hr*(2.*_const_fm.x/(val(cm,1,0,0) + val(cm,1 -1,0,0)))*(val(eta,1,0,0) - val(eta,0,0,0)))
    /(Delta*(2.*Omega*sin(y*3.14159265358979/180.))*(hl + hr + 1e-12));
  } 

{
    double hl = val(h,0,0,0) > dry && val(h,0,-1,0) > dry, hr = val(h,0,0,0) > dry && val(h,0,1,0) > dry;
    ug.x = a.x*G*(hl*(2.*_const_fm.y/(val(cm,0,0,0) + val(cm,0,0 -1,0)))*(val(eta,0,0,0) - val(eta,0,-1,0)) +
    hr*(2.*_const_fm.y/(val(cm,0,1,0) + val(cm,0,1 -1,0)))*(val(eta,0,1,0) - val(eta,0,0,0)))
    /(Delta*(2.*Omega*sin(y*3.14159265358979/180.))*(hl + hr + 1e-12));
  }
  return ug;
}}else if(!is_constant(fm.x) && is_constant(cm)){double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);

{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

coord ug;
  static const coord a = {-1., 1.};
   {
    double hl = val(h,0,0,0) > dry && val(h,-1,0,0) > dry, hr = val(h,0,0,0) > dry && val(h,1,0,0) > dry;
    ug.y = a.y*G*(hl*(2.*val(fm.x,0,0,0)/(_const_cm + _const_cm))*(val(eta,0,0,0) - val(eta,-1,0,0)) +
    hr*(2.*val(fm.x,1,0,0)/(_const_cm + _const_cm))*(val(eta,1,0,0) - val(eta,0,0,0)))
    /(Delta*(2.*Omega*sin(y*3.14159265358979/180.))*(hl + hr + 1e-12));
  } 

{
    double hl = val(h,0,0,0) > dry && val(h,0,-1,0) > dry, hr = val(h,0,0,0) > dry && val(h,0,1,0) > dry;
    ug.x = a.x*G*(hl*(2.*val(fm.y,0,0,0)/(_const_cm + _const_cm))*(val(eta,0,0,0) - val(eta,0,-1,0)) +
    hr*(2.*val(fm.y,0,1,0)/(_const_cm + _const_cm))*(val(eta,0,1,0) - val(eta,0,0,0)))
    /(Delta*(2.*Omega*sin(y*3.14159265358979/180.))*(hl + hr + 1e-12));
  }
  return ug;
}}else {_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);

{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

coord ug;
  static const coord a = {-1., 1.};
   {
    double hl = val(h,0,0,0) > dry && val(h,-1,0,0) > dry, hr = val(h,0,0,0) > dry && val(h,1,0,0) > dry;
    ug.y = a.y*G*(hl*(2.*_const_fm.x/(_const_cm + _const_cm))*(val(eta,0,0,0) - val(eta,-1,0,0)) +
    hr*(2.*_const_fm.x/(_const_cm + _const_cm))*(val(eta,1,0,0) - val(eta,0,0,0)))
    /(Delta*(2.*Omega*sin(y*3.14159265358979/180.))*(hl + hr + 1e-12));
  } 

{
    double hl = val(h,0,0,0) > dry && val(h,0,-1,0) > dry, hr = val(h,0,0,0) > dry && val(h,0,1,0) > dry;
    ug.x = a.x*G*(hl*(2.*_const_fm.y/(_const_cm + _const_cm))*(val(eta,0,0,0) - val(eta,0,-1,0)) +
    hr*(2.*_const_fm.y/(_const_cm + _const_cm))*(val(eta,0,1,0) - val(eta,0,0,0)))
    /(Delta*(2.*Omega*sin(y*3.14159265358979/180.))*(hl + hr + 1e-12));
  }
  return ug;
}}}

static void _stencil_geostrophic_velocity (Point point)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;   

{              
     _stencil_val(h,1,0,0); _stencil_val(h,0,0,0); _stencil_val(h,-1,0,0); _stencil_val(h,0,0,0);
_stencil_val(fm.x,0,0,0);_stencil_val(cm,0,0,0); _stencil_val(cm,0 -1,0,0);_stencil_val(eta,0,0,0); _stencil_val(eta,-1,0,0);
_stencil_val(fm.x,1,0,0);_stencil_val(cm,1,0,0); _stencil_val(cm,1 -1,0,0);_stencil_val(eta,1,0,0); _stencil_val(eta,0,0,0);  

} 

{              
     _stencil_val(h,0,1,0); _stencil_val(h,0,0,0); _stencil_val(h,0,-1,0); _stencil_val(h,0,0,0);
_stencil_val(fm.y,0,0,0);_stencil_val(cm,0,0,0); _stencil_val(cm,0,0 -1,0);_stencil_val(eta,0,0,0); _stencil_val(eta,0,-1,0);
_stencil_val(fm.y,0,1,0);_stencil_val(cm,0,1,0); _stencil_val(cm,0,1 -1,0);_stencil_val(eta,0,1,0); _stencil_val(eta,0,0,0);  

}
  return ;
}











extern double * drho;

static int acceleration_2_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}      static int acceleration_2(const int i,const double t,Event *_ev){tracing("acceleration_2","/home/jacqhugo/basilisk/src/layered/isopycnal.h",0);
{
  scalar q = new_block_scalar("q","",nl);
  

  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/isopycnal.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{   
    
    for (point.l = nl - 1; point.l >= 0; point.l--) {   
      _stencil_val(h,0,0,0); 
       
      _stencil_val_a(q,0,0,0);  
    }
  }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double ph = 0.;
    for (point.l = nl - 1; point.l >= 0; point.l--) {
      double dp = G*drho[point.l]*val(h,0,0,0);
      ph += dp;
      val(q,0,0,0) = ph;
    }
  }}
      

}
  }
}

if(!is_constant(fm.x) && !is_constant(cm)){
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/isopycnal.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0);    

do {     _stencil_val(zb,0 -1,0,0); _stencil_val(zb,0,0,0);   

for (point.l = 0; point.l < nl; point.l++) 

{    _stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0); {                 _stencil_val(h,0 -1,0,0);_stencil_val(q,0 -1,0,0);_stencil_val(h,0,0,0);_stencil_val(q,0,0,0);          if (point.l < nl - 1) {                        _stencil_val(h,0 -1,0,0); _stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0); _stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0); _stencil_val(h,0,0,0);_stencil_val(h,0 -1,0,0);_stencil_val(q,0 -1,0,1);_stencil_val(h,0,0,0);_stencil_val(q,0,0,1);          }_stencil_val(fm.x,0,0,0);_stencil_val(cm,0,0,0); _stencil_val(cm,0 -1,0,0);_stencil_val(hf.x,0,0,0);_stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0);      }      _stencil_val_r(ha.x,0,0,0); _stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0);      }
  

point.l = 0; 

} while (0)
               ; 

_loop.face |= (1 << 1);    

do {     _stencil_val(zb,0,0 -1,0); _stencil_val(zb,0,0,0);   

for (point.l = 0; point.l < nl; point.l++) 

{    _stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0); {                 _stencil_val(h,0,0 -1,0);_stencil_val(q,0,0 -1,0);_stencil_val(h,0,0,0);_stencil_val(q,0,0,0);          if (point.l < nl - 1) {                        _stencil_val(h,0,0 -1,0); _stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0); _stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0); _stencil_val(h,0,0,0);_stencil_val(h,0,0 -1,0);_stencil_val(q,0,0 -1,1);_stencil_val(h,0,0,0);_stencil_val(q,0,0,1);          }_stencil_val(fm.y,0,0,0);_stencil_val(cm,0,0,0); _stencil_val(cm,0,0 -1,0);_stencil_val(hf.y,0,0,0);_stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0);      }      _stencil_val_r(ha.y,0,0,0); _stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0);      }
  

point.l = 0; 

} while (0)
               ;}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

do { double dz = val(zb,0,0,0) - val(zb,0 -1,0,0);   

for (point.l = 0; point.l < nl; point.l++) 

{ double pg = 0.; if (val(h,0,0,0) + val(h,0 -1,0,0) > dry) { double s = Delta*(fabs(dz/Delta) < max_slope ? (dz/Delta) : ((dz/Delta) > 0. ? max_slope : - max_slope)); pg = (val(h,0 -1,0,0) - s)*val(q,0 -1,0,0) - (val(h,0,0,0) + s)*val(q,0,0,0); if (point.l < nl - 1) { double s = Delta*(fabs((dz + val(h,0,0,0) - val(h,0 -1,0,0))/Delta) < max_slope ? ((dz + val(h,0,0,0) - val(h,0 -1,0,0))/Delta) : (((dz + val(h,0,0,0) - val(h,0 -1,0,0))/Delta) > 0. ? max_slope : - max_slope)); pg += (val(h,0 -1,0,0) + s)*val(q,0 -1,0,1) - (val(h,0,0,0) - s)*val(q,0,0,1); } pg *= (2.*val(fm.x,0,0,0)/(val(cm,0,0,0) + val(cm,0 -1,0,0)))*val(hf.x,0,0,0)/(Delta*(val(h,0,0,0) + val(h,0 -1,0,0))); } val(ha.x,0,0,0) += pg; dz += val(h,0,0,0) - val(h,0 -1,0,0); }
  

point.l = 0; 

} while (0)
               ;}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

do { double dz = val(zb,0,0,0) - val(zb,0,0 -1,0);   

for (point.l = 0; point.l < nl; point.l++) 

{ double pg = 0.; if (val(h,0,0,0) + val(h,0,0 -1,0) > dry) { double s = Delta*(fabs(dz/Delta) < max_slope ? (dz/Delta) : ((dz/Delta) > 0. ? max_slope : - max_slope)); pg = (val(h,0,0 -1,0) - s)*val(q,0,0 -1,0) - (val(h,0,0,0) + s)*val(q,0,0,0); if (point.l < nl - 1) { double s = Delta*(fabs((dz + val(h,0,0,0) - val(h,0,0 -1,0))/Delta) < max_slope ? ((dz + val(h,0,0,0) - val(h,0,0 -1,0))/Delta) : (((dz + val(h,0,0,0) - val(h,0,0 -1,0))/Delta) > 0. ? max_slope : - max_slope)); pg += (val(h,0,0 -1,0) + s)*val(q,0,0 -1,1) - (val(h,0,0,0) - s)*val(q,0,0,1); } pg *= (2.*val(fm.y,0,0,0)/(val(cm,0,0,0) + val(cm,0,0 -1,0)))*val(hf.y,0,0,0)/(Delta*(val(h,0,0,0) + val(h,0,0 -1,0))); } val(ha.y,0,0,0) += pg; dz += val(h,0,0,0) - val(h,0,0 -1,0); }
  

point.l = 0; 

} while (0)
               ;}
  

}

}
      

}
  }
}

}else if(is_constant(fm.x) && !is_constant(cm)){_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/isopycnal.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0);    

do {     _stencil_val(zb,0 -1,0,0); _stencil_val(zb,0,0,0);   

for (point.l = 0; point.l < nl; point.l++) 

{    _stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0); {                 _stencil_val(h,0 -1,0,0);_stencil_val(q,0 -1,0,0);_stencil_val(h,0,0,0);_stencil_val(q,0,0,0);          if (point.l < nl - 1) {                        _stencil_val(h,0 -1,0,0); _stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0); _stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0); _stencil_val(h,0,0,0);_stencil_val(h,0 -1,0,0);_stencil_val(q,0 -1,0,1);_stencil_val(h,0,0,0);_stencil_val(q,0,0,1);          };_stencil_val(cm,0,0,0); _stencil_val(cm,0 -1,0,0);_stencil_val(hf.x,0,0,0);_stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0);      }      _stencil_val_r(ha.x,0,0,0); _stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0);      }
  

point.l = 0; 

} while (0)
               ; 

_loop.face |= (1 << 1);    

do {     _stencil_val(zb,0,0 -1,0); _stencil_val(zb,0,0,0);   

for (point.l = 0; point.l < nl; point.l++) 

{    _stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0); {                 _stencil_val(h,0,0 -1,0);_stencil_val(q,0,0 -1,0);_stencil_val(h,0,0,0);_stencil_val(q,0,0,0);          if (point.l < nl - 1) {                        _stencil_val(h,0,0 -1,0); _stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0); _stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0); _stencil_val(h,0,0,0);_stencil_val(h,0,0 -1,0);_stencil_val(q,0,0 -1,1);_stencil_val(h,0,0,0);_stencil_val(q,0,0,1);          };_stencil_val(cm,0,0,0); _stencil_val(cm,0,0 -1,0);_stencil_val(hf.y,0,0,0);_stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0);      }      _stencil_val_r(ha.y,0,0,0); _stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0);      }
  

point.l = 0; 

} while (0)
               ;}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

do { double dz = val(zb,0,0,0) - val(zb,0 -1,0,0);   

for (point.l = 0; point.l < nl; point.l++) 

{ double pg = 0.; if (val(h,0,0,0) + val(h,0 -1,0,0) > dry) { double s = Delta*(fabs(dz/Delta) < max_slope ? (dz/Delta) : ((dz/Delta) > 0. ? max_slope : - max_slope)); pg = (val(h,0 -1,0,0) - s)*val(q,0 -1,0,0) - (val(h,0,0,0) + s)*val(q,0,0,0); if (point.l < nl - 1) { double s = Delta*(fabs((dz + val(h,0,0,0) - val(h,0 -1,0,0))/Delta) < max_slope ? ((dz + val(h,0,0,0) - val(h,0 -1,0,0))/Delta) : (((dz + val(h,0,0,0) - val(h,0 -1,0,0))/Delta) > 0. ? max_slope : - max_slope)); pg += (val(h,0 -1,0,0) + s)*val(q,0 -1,0,1) - (val(h,0,0,0) - s)*val(q,0,0,1); } pg *= (2.*_const_fm.x/(val(cm,0,0,0) + val(cm,0 -1,0,0)))*val(hf.x,0,0,0)/(Delta*(val(h,0,0,0) + val(h,0 -1,0,0))); } val(ha.x,0,0,0) += pg; dz += val(h,0,0,0) - val(h,0 -1,0,0); }
  

point.l = 0; 

} while (0)
               ;}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

do { double dz = val(zb,0,0,0) - val(zb,0,0 -1,0);   

for (point.l = 0; point.l < nl; point.l++) 

{ double pg = 0.; if (val(h,0,0,0) + val(h,0,0 -1,0) > dry) { double s = Delta*(fabs(dz/Delta) < max_slope ? (dz/Delta) : ((dz/Delta) > 0. ? max_slope : - max_slope)); pg = (val(h,0,0 -1,0) - s)*val(q,0,0 -1,0) - (val(h,0,0,0) + s)*val(q,0,0,0); if (point.l < nl - 1) { double s = Delta*(fabs((dz + val(h,0,0,0) - val(h,0,0 -1,0))/Delta) < max_slope ? ((dz + val(h,0,0,0) - val(h,0,0 -1,0))/Delta) : (((dz + val(h,0,0,0) - val(h,0,0 -1,0))/Delta) > 0. ? max_slope : - max_slope)); pg += (val(h,0,0 -1,0) + s)*val(q,0,0 -1,1) - (val(h,0,0,0) - s)*val(q,0,0,1); } pg *= (2.*_const_fm.y/(val(cm,0,0,0) + val(cm,0,0 -1,0)))*val(hf.y,0,0,0)/(Delta*(val(h,0,0,0) + val(h,0,0 -1,0))); } val(ha.y,0,0,0) += pg; dz += val(h,0,0,0) - val(h,0,0 -1,0); }
  

point.l = 0; 

} while (0)
               ;}
  

}

}
      

}
  }
}

}else if(!is_constant(fm.x) && is_constant(cm)){double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/isopycnal.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0);    

do {     _stencil_val(zb,0 -1,0,0); _stencil_val(zb,0,0,0);   

for (point.l = 0; point.l < nl; point.l++) 

{    _stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0); {                 _stencil_val(h,0 -1,0,0);_stencil_val(q,0 -1,0,0);_stencil_val(h,0,0,0);_stencil_val(q,0,0,0);          if (point.l < nl - 1) {                        _stencil_val(h,0 -1,0,0); _stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0); _stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0); _stencil_val(h,0,0,0);_stencil_val(h,0 -1,0,0);_stencil_val(q,0 -1,0,1);_stencil_val(h,0,0,0);_stencil_val(q,0,0,1);          }_stencil_val(fm.x,0,0,0);;;_stencil_val(hf.x,0,0,0);_stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0);      }      _stencil_val_r(ha.x,0,0,0); _stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0);      }
  

point.l = 0; 

} while (0)
               ; 

_loop.face |= (1 << 1);    

do {     _stencil_val(zb,0,0 -1,0); _stencil_val(zb,0,0,0);   

for (point.l = 0; point.l < nl; point.l++) 

{    _stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0); {                 _stencil_val(h,0,0 -1,0);_stencil_val(q,0,0 -1,0);_stencil_val(h,0,0,0);_stencil_val(q,0,0,0);          if (point.l < nl - 1) {                        _stencil_val(h,0,0 -1,0); _stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0); _stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0); _stencil_val(h,0,0,0);_stencil_val(h,0,0 -1,0);_stencil_val(q,0,0 -1,1);_stencil_val(h,0,0,0);_stencil_val(q,0,0,1);          }_stencil_val(fm.y,0,0,0);;;_stencil_val(hf.y,0,0,0);_stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0);      }      _stencil_val_r(ha.y,0,0,0); _stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0);      }
  

point.l = 0; 

} while (0)
               ;}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

do { double dz = val(zb,0,0,0) - val(zb,0 -1,0,0);   

for (point.l = 0; point.l < nl; point.l++) 

{ double pg = 0.; if (val(h,0,0,0) + val(h,0 -1,0,0) > dry) { double s = Delta*(fabs(dz/Delta) < max_slope ? (dz/Delta) : ((dz/Delta) > 0. ? max_slope : - max_slope)); pg = (val(h,0 -1,0,0) - s)*val(q,0 -1,0,0) - (val(h,0,0,0) + s)*val(q,0,0,0); if (point.l < nl - 1) { double s = Delta*(fabs((dz + val(h,0,0,0) - val(h,0 -1,0,0))/Delta) < max_slope ? ((dz + val(h,0,0,0) - val(h,0 -1,0,0))/Delta) : (((dz + val(h,0,0,0) - val(h,0 -1,0,0))/Delta) > 0. ? max_slope : - max_slope)); pg += (val(h,0 -1,0,0) + s)*val(q,0 -1,0,1) - (val(h,0,0,0) - s)*val(q,0,0,1); } pg *= (2.*val(fm.x,0,0,0)/(_const_cm + _const_cm))*val(hf.x,0,0,0)/(Delta*(val(h,0,0,0) + val(h,0 -1,0,0))); } val(ha.x,0,0,0) += pg; dz += val(h,0,0,0) - val(h,0 -1,0,0); }
  

point.l = 0; 

} while (0)
               ;}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

do { double dz = val(zb,0,0,0) - val(zb,0,0 -1,0);   

for (point.l = 0; point.l < nl; point.l++) 

{ double pg = 0.; if (val(h,0,0,0) + val(h,0,0 -1,0) > dry) { double s = Delta*(fabs(dz/Delta) < max_slope ? (dz/Delta) : ((dz/Delta) > 0. ? max_slope : - max_slope)); pg = (val(h,0,0 -1,0) - s)*val(q,0,0 -1,0) - (val(h,0,0,0) + s)*val(q,0,0,0); if (point.l < nl - 1) { double s = Delta*(fabs((dz + val(h,0,0,0) - val(h,0,0 -1,0))/Delta) < max_slope ? ((dz + val(h,0,0,0) - val(h,0,0 -1,0))/Delta) : (((dz + val(h,0,0,0) - val(h,0,0 -1,0))/Delta) > 0. ? max_slope : - max_slope)); pg += (val(h,0,0 -1,0) + s)*val(q,0,0 -1,1) - (val(h,0,0,0) - s)*val(q,0,0,1); } pg *= (2.*val(fm.y,0,0,0)/(_const_cm + _const_cm))*val(hf.y,0,0,0)/(Delta*(val(h,0,0,0) + val(h,0,0 -1,0))); } val(ha.y,0,0,0) += pg; dz += val(h,0,0,0) - val(h,0,0 -1,0); }
  

point.l = 0; 

} while (0)
               ;}
  

}

}
      

}
  }
}

}else {_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/isopycnal.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0);    

do {     _stencil_val(zb,0 -1,0,0); _stencil_val(zb,0,0,0);   

for (point.l = 0; point.l < nl; point.l++) 

{    _stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0); {                 _stencil_val(h,0 -1,0,0);_stencil_val(q,0 -1,0,0);_stencil_val(h,0,0,0);_stencil_val(q,0,0,0);          if (point.l < nl - 1) {                        _stencil_val(h,0 -1,0,0); _stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0); _stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0); _stencil_val(h,0,0,0);_stencil_val(h,0 -1,0,0);_stencil_val(q,0 -1,0,1);_stencil_val(h,0,0,0);_stencil_val(q,0,0,1);          };;;_stencil_val(hf.x,0,0,0);_stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0);      }      _stencil_val_r(ha.x,0,0,0); _stencil_val(h,0,0,0); _stencil_val(h,0 -1,0,0);      }
  

point.l = 0; 

} while (0)
               ; 

_loop.face |= (1 << 1);    

do {     _stencil_val(zb,0,0 -1,0); _stencil_val(zb,0,0,0);   

for (point.l = 0; point.l < nl; point.l++) 

{    _stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0); {                 _stencil_val(h,0,0 -1,0);_stencil_val(q,0,0 -1,0);_stencil_val(h,0,0,0);_stencil_val(q,0,0,0);          if (point.l < nl - 1) {                        _stencil_val(h,0,0 -1,0); _stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0); _stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0); _stencil_val(h,0,0,0);_stencil_val(h,0,0 -1,0);_stencil_val(q,0,0 -1,1);_stencil_val(h,0,0,0);_stencil_val(q,0,0,1);          };;;_stencil_val(hf.y,0,0,0);_stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0);      }      _stencil_val_r(ha.y,0,0,0); _stencil_val(h,0,0,0); _stencil_val(h,0,0 -1,0);      }
  

point.l = 0; 

} while (0)
               ;}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

do { double dz = val(zb,0,0,0) - val(zb,0 -1,0,0);   

for (point.l = 0; point.l < nl; point.l++) 

{ double pg = 0.; if (val(h,0,0,0) + val(h,0 -1,0,0) > dry) { double s = Delta*(fabs(dz/Delta) < max_slope ? (dz/Delta) : ((dz/Delta) > 0. ? max_slope : - max_slope)); pg = (val(h,0 -1,0,0) - s)*val(q,0 -1,0,0) - (val(h,0,0,0) + s)*val(q,0,0,0); if (point.l < nl - 1) { double s = Delta*(fabs((dz + val(h,0,0,0) - val(h,0 -1,0,0))/Delta) < max_slope ? ((dz + val(h,0,0,0) - val(h,0 -1,0,0))/Delta) : (((dz + val(h,0,0,0) - val(h,0 -1,0,0))/Delta) > 0. ? max_slope : - max_slope)); pg += (val(h,0 -1,0,0) + s)*val(q,0 -1,0,1) - (val(h,0,0,0) - s)*val(q,0,0,1); } pg *= (2.*_const_fm.x/(_const_cm + _const_cm))*val(hf.x,0,0,0)/(Delta*(val(h,0,0,0) + val(h,0 -1,0,0))); } val(ha.x,0,0,0) += pg; dz += val(h,0,0,0) - val(h,0 -1,0,0); }
  

point.l = 0; 

} while (0)
               ;}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

do { double dz = val(zb,0,0,0) - val(zb,0,0 -1,0);   

for (point.l = 0; point.l < nl; point.l++) 

{ double pg = 0.; if (val(h,0,0,0) + val(h,0,0 -1,0) > dry) { double s = Delta*(fabs(dz/Delta) < max_slope ? (dz/Delta) : ((dz/Delta) > 0. ? max_slope : - max_slope)); pg = (val(h,0,0 -1,0) - s)*val(q,0,0 -1,0) - (val(h,0,0,0) + s)*val(q,0,0,0); if (point.l < nl - 1) { double s = Delta*(fabs((dz + val(h,0,0,0) - val(h,0,0 -1,0))/Delta) < max_slope ? ((dz + val(h,0,0,0) - val(h,0,0 -1,0))/Delta) : (((dz + val(h,0,0,0) - val(h,0,0 -1,0))/Delta) > 0. ? max_slope : - max_slope)); pg += (val(h,0,0 -1,0) + s)*val(q,0,0 -1,1) - (val(h,0,0,0) - s)*val(q,0,0,1); } pg *= (2.*_const_fm.y/(_const_cm + _const_cm))*val(hf.y,0,0,0)/(Delta*(val(h,0,0,0) + val(h,0,0 -1,0))); } val(ha.y,0,0,0) += pg; dz += val(h,0,0,0) - val(h,0,0 -1,0); }
  

point.l = 0; 

} while (0)
               ;}
  

}

}
      

}
  }
}

}

  delete (((scalar[]){q,{-1}}));
}{end_tracing("acceleration_2","/home/jacqhugo/basilisk/src/layered/isopycnal.h",0);return 0;}end_tracing("acceleration_2","/home/jacqhugo/basilisk/src/layered/isopycnal.h",0);}


extern double * dh, * drho;




extern double omr, Cm;







extern double * hmin, * hmax;






extern double dt, dry;

static int viscous_term_0_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}      static int viscous_term_0(const int i,const double t,Event *_ev){tracing("viscous_term_0","/home/jacqhugo/basilisk/src/layered/entrainment.h",0);
{





  if (omr <= 0.)
    {end_tracing("viscous_term_0","/home/jacqhugo/basilisk/src/layered/entrainment.h",0);return 0;}





  double oma[nl], wa[nl];
  for (int l = 0; l < nl; l++)
    oma[l] = 0., wa[l] = 0.;  

for (_layer = 0; _layer < nl; _layer++) 

{
    double o = 0., w = 0.;
    if (_layer > 0)
      {if(!is_constant(cm)){
  
      

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/entrainment.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{                           
 _stencil_val(h,0,0,0);_stencil_val(h,0,0,0);_stencil_val(h,0,0,0);_stencil_val(h,0,0,0);_stencil_val(h,0,0,0);_stencil_val(h,0,0,0);
_stencil_val(h,0,0,0); _stencil_val(h,0,0,-1);
   {_stencil_val(cm,0,0,0);_stencil_val(cm,0,0,0);       }      
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

mpi_sum_reduce_init(mpi_w,&w,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_o,&o,MPI_DOUBLE,MPI_SUM,1); 

{
  OMP_PARALLEL (reduction(+:o) reduction(+:w)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
 double om = omr*(((val(h,0,0,0)) >= hmin[_layer] ? 0. : ( ((hmin[_layer] - (val(h,0,0,0)))/hmin[_layer])*((hmin[_layer] - (val(h,0,0,0)))/hmin[_layer]))) - ((val(h,0,0,0)) <= hmax[_layer] ? 0. : ( (((val(h,0,0,0)) - hmax[_layer])/hmax[_layer])*(((val(h,0,0,0)) - hmax[_layer])/hmax[_layer]))));
 if (val(h,0,0,0) + dt*om > dry && val(h,0,0,-1) - dt*om > dry)
   o += (( Delta*Delta)*val(cm,0,0,0))*om, w += (( Delta*Delta)*val(cm,0,0,0));
      }}
      

}
  }
}

{mpi_sum_reduce_array(mpi_w,&w,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_o,&o,MPI_DOUBLE,MPI_SUM,1);}}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
      

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/entrainment.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{                           
 _stencil_val(h,0,0,0);_stencil_val(h,0,0,0);_stencil_val(h,0,0,0);_stencil_val(h,0,0,0);_stencil_val(h,0,0,0);_stencil_val(h,0,0,0);
_stencil_val(h,0,0,0); _stencil_val(h,0,0,-1);
   {;;       }      
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

mpi_sum_reduce_init(mpi_w,&w,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_o,&o,MPI_DOUBLE,MPI_SUM,1); 

{
  OMP_PARALLEL (reduction(+:o) reduction(+:w)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
 double om = omr*(((val(h,0,0,0)) >= hmin[_layer] ? 0. : ( ((hmin[_layer] - (val(h,0,0,0)))/hmin[_layer])*((hmin[_layer] - (val(h,0,0,0)))/hmin[_layer]))) - ((val(h,0,0,0)) <= hmax[_layer] ? 0. : ( (((val(h,0,0,0)) - hmax[_layer])/hmax[_layer])*(((val(h,0,0,0)) - hmax[_layer])/hmax[_layer]))));
 if (val(h,0,0,0) + dt*om > dry && val(h,0,0,-1) - dt*om > dry)
   o += (( Delta*Delta)*_const_cm)*om, w += (( Delta*Delta)*_const_cm);
      }}
      

}
  }
}

{mpi_sum_reduce_array(mpi_w,&w,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_o,&o,MPI_DOUBLE,MPI_SUM,1);}}}
    oma[_layer] = o, wa[_layer] = w;
  }  

_layer = 0;
  






  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/entrainment.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{    

for (point.l = 0; point.l < nl; point.l++) 

{ 
_stencil_val(h,0,0,0); 

{ _stencil_val(h,0,0,0);_stencil_val(u.x,0,0,0); } { _stencil_val(h,0,0,0);_stencil_val(u.y,0,0,0); }
    }  

point.l = 0;
    

for (int l = nl - 1; l >= 1; l--) {                           
      _stencil_val(h,0,0,l);_stencil_val(h,0,0,l);_stencil_val(h,0,0,l);_stencil_val(h,0,0,l);_stencil_val(h,0,0,l);_stencil_val(h,0,0,l);
_stencil_val(h,0,0,l); _stencil_val(h,0,0,l-1); {             
   
   
   





 
  {       
   _stencil_val(u.x,0,0,l);_stencil_val(u.x,0,0,o_stencil);  
     
     
 } 

{       
   _stencil_val(u.y,0,0,l);_stencil_val(u.y,0,0,o_stencil);  
     
     
 }
      }    
}    

for (point.l = 0; point.l < nl; point.l++) 

{
      _stencil_val_a(h,0,0,0);  
      
 { _stencil_val(h,0,0,0);_stencil_val(h,0,0,0);_stencil_val_a(u.x,0,0,0);       } { _stencil_val(h,0,0,0);_stencil_val(h,0,0,0);_stencil_val_a(u.y,0,0,0);       }
    }  

point.l = 0;
  

}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double hn[nl];
    coord un[nl];    

for (point.l = 0; point.l < nl; point.l++) 

{
      hn[point.l] = val(h,0,0,0);
      
 un[point.l].x = val(h,0,0,0)*val(u.x,0,0,0); un[point.l].y = val(h,0,0,0)*val(u.y,0,0,0);
    }  

point.l = 0;
    

for (int l = nl - 1; l >= 1; l--) {
      double om = omr*(((val(h,0,0,l)) >= hmin[l] ? 0. : ( ((hmin[l] - (val(h,0,0,l)))/hmin[l])*((hmin[l] - (val(h,0,0,l)))/hmin[l]))) - ((val(h,0,0,l)) <= hmax[l] ? 0. : ( (((val(h,0,0,l)) - hmax[l])/hmax[l])*(((val(h,0,0,l)) - hmax[l])/hmax[l]))));
      if (val(h,0,0,l) + dt*om > dry && val(h,0,0,l-1) - dt*om > dry) {
 om -= oma[l]/wa[l];
 hn[l] += dt*om;
 hn[l - 1] -= dt*om;





 int lum = om >= 0 ? l - 1 : l;
  {
   double flux = dt*om*(val(u.x,0,0,lum)*(1. + Cm) - Cm*val(u.x,0,0,l));
   un[l].x += flux;
   un[l - 1].x -= flux;
 } 

{
   double flux = dt*om*(val(u.y,0,0,lum)*(1. + Cm) - Cm*val(u.y,0,0,l));
   un[l].y += flux;
   un[l - 1].y -= flux;
 }
      }
    }    

for (point.l = 0; point.l < nl; point.l++) 

{
      val(h,0,0,0) = hn[point.l];
      
 val(u.x,0,0,0) = val(h,0,0,0) > dry ? un[point.l].x/val(h,0,0,0) : 0.; val(u.y,0,0,0) = val(h,0,0,0) > dry ? un[point.l].y/val(h,0,0,0) : 0.;
    }  

point.l = 0;
  

}}
      

}
  }
}

}{end_tracing("viscous_term_0","/home/jacqhugo/basilisk/src/layered/entrainment.h",0);return 0;}end_tracing("viscous_term_0","/home/jacqhugo/basilisk/src/layered/entrainment.h",0);}

extern double * hmin, * hmax, omr, Cm;










extern double * hmin;









static void restriction_tag (Point point, scalar t)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

double min = 1e30f;
  
  

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;    

if (val(t,0,0,0) < min)
      min = val(t,0,0,0);
      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }  

val(t,0,0,0) = min;
}







static long lookup_tag (Array * a, double tag)
{
  long len = a->len/sizeof(double);
  double * p = (double *) a->p;
  if (tag == p[0])
    return 0;
  if (tag == p[len - 1])
    return len - 1;

  long s = 0, e = len - 1;
  while (s < e - 1) {
    long m = (s + e)/2;
    if (p[m] <= tag)
      s = m;
    else
      e = m;
  }
  return s;
}

     
int tag (scalar t)
{tracing("tag","/home/jacqhugo/basilisk/src/tag.h",0);




  _attribute[t.i].restriction = restriction_tag;

  long i = 1;
  #undef OMP
  #define OMP(x)
  

;

{
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/tag.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    

{_stencil_val(t,0,0,0);_stencil_val_a(t,0,0,0);    }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(t,0,0,0) = (val(t,0,0,0) != 0)*i++;}
      

}
  }
}

}
  #undef OMP
#define OMP(x) _Pragma(#x)
  

;






  

bool changed;
  do {






    restriction (((scalar[]){t,{-1}}));





    changed = false;
    for (int l = 1; l <= grid->maxdepth; l++) {
  






      

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{_stencil_coarse(t,0,0,0);
   { _stencil_coarse(t,0,0,0);_stencil_val_a(t,0,0,0); } }
  

} 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = l;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

if (coarse(t,0,0,0))
   val(t,0,0,0) = coarse(t,0,0,0);}
    

}
  }
}      

boundary_level (((scalar[]){t,{-1}}), l);
  







      

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);        

{_stencil_val(t,0,0,0); {  
    _stencil_val(t,0,0,0);   

{
    const int _nn = 1;
    const int _i = point.i, _j = point.j;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;
      for (int _l = - _nn; _l <= _nn; _l++) {
 point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;     

{_stencil_val(t,0,0,0); _stencil_val(t,0,0,0);
       { _stencil_val(t,0,0,0); }    }      

}
    }
    point.i = _i; point.j = _j;
  }

_stencil_val(t,0,0,0); { 
      
     _stencil_val_a(t,0,0,0);  
   }

      
 


} }
  

} 

{
  OMP_PARALLEL (reduction(||:changed)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = l;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++)        

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

if (val(t,0,0,0)) {
   double min = val(t,0,0,0);   

{
    const int _nn = 1;
    const int _i = point.i, _j = point.j;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;
      for (int _l = - _nn; _l <= _nn; _l++) {
 point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;     

if (val(t,0,0,0) && val(t,0,0,0) < min)
       min = val(t,0,0,0);      

}
    }
    point.i = _i; point.j = _j;
  }

   if (val(t,0,0,0) != min) {
     changed = true;
     val(t,0,0,0) = min;
   }
 }}
    

}
  }
}

{mpi_all_reduce_array(&changed,MPI_C_BOOL,MPI_LOR,1);}
      boundary_level (((scalar[]){t,{-1}}), l);
    }
    _attribute[t.i].stencil.bc &= ~s_restriction;
  } while (changed);

  Array * a = array_new();
  #undef OMP
  #define OMP(x)
  

;

{
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/tag.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    

{_stencil_val(t,0,0,0); {        







       _stencil_val(t,0,0,0);   
           
      
     
   
       
  
    
               
          
                






      
  
    
       
         
    





}   }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

if (val(t,0,0,0) > 0) {







      double tag = val(t,0,0,0), * ap = (double *) a->p;
      long s = -1;
      if (a->len == 0 || tag > ap[a->len/sizeof(double) - 1])
 s = a->len/sizeof(double);
      else if (tag < ap[0])
 s = 0;
      else {






 s = lookup_tag (a, tag) + 1;
 if (tag == ap[s - 1] || tag == ap[s])
   s = -1;
      }
      if (s >= 0) {





 array_append (a, &tag, sizeof(double)), ap = (double *) a->p;
 for (int i = a->len/sizeof(double) - 1; i > s; i--)
   ap[i] = ap[i-1];
 ap[s] = tag;
      }
    }}
      

}
  }
}

}
  #undef OMP
#define OMP(x) _Pragma(#x)
  

;
  

  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/tag.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    

{_stencil_val(t,0,0,0);
      { _stencil_val(t,0,0,0);_stencil_val_a(t,0,0,0);     }   }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

if (val(t,0,0,0) > 0)
      val(t,0,0,0) = lookup_tag (a, val(t,0,0,0)) + 1;}
      

}
  }
}  

int n = a->len/sizeof(double);
  array_free (a);
  {end_tracing("tag","/home/jacqhugo/basilisk/src/tag.h",0);return n;}
end_tracing("tag","/home/jacqhugo/basilisk/src/tag.h",0);}

static int sort_long (const void * a, const void * b)
{
  return *(const long *)a < *(const long *)b;
}

void remove_droplets (scalar f,
        int minsize,
        double threshold,
        bool bubbles)
{
  if (minsize == 0)
    return;
  scalar  d=new_scalar("d");
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/tag.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    

{ _stencil_val(f,0,0,0); _stencil_val(f,0,0,0);_stencil_val_a(d,0,0,0);        }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)
    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(d,0,0,0) = (bubbles ? 1. - val(f,0,0,0) : val(f,0,0,0)) > threshold;}      

}
  }
}
  

int n = tag (d);
  long size[n];
  for (int i = 0; i < n; i++)
    size[i] = 0;
  #undef OMP
  #define OMP(x)
  

;

{
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/tag.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    

{_stencil_val(d,0,0,0);
      { _stencil_val(d,0,0,0);  }   }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)
    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

if (val(d,0,0,0) > 0)
      size[((int) val(d,0,0,0)) - 1]++;}      

}
  }
}

}
  #undef OMP
#define OMP(x) _Pragma(#x)
  

;



  

if (minsize > 0)
    minsize = pow (minsize, 2);
  else {
    if (- minsize >= n)
      {delete((scalar*)((scalar[]){d,{-1}}));return;}
    long size1[n];
    memcpy (size1, size, n*sizeof(long));
    qsort (size1, n, sizeof (long), sort_long);
    minsize = size1[- minsize - 1];
  }
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/tag.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    

{_stencil_val(d,0,0,0); _stencil_val(d,0,0,0);
      {_stencil_val_a(f,0,0,0);  }         }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)
    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

if (val(d,0,0,0) > 0 && size[((int) val(d,0,0,0)) - 1] < minsize)
      val(f,0,0,0) = bubbles;}      

}
  }
}

delete((scalar*)((scalar[]){d,{-1}}));
}





static struct {
  double * sum;
} Conservation = {0};

static int init_0_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i = 0)!=0;*ip=i;*tp=t;return ret;}      static int init_0(const int i,const double t,Event *_ev){tracing("init_0","/home/jacqhugo/basilisk/src/layered/conservation.h",0);
{







  scalar  d=new_scalar("d");
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/conservation.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{    

for (point.l = 0; point.l < nl; point.l++)
      

{ _stencil_val(h,0,0,0); }  

point.l = 0;
    

_stencil_val_a(d,0,0,0);    
  }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    double H = 0.;    

for (point.l = 0; point.l < nl; point.l++)
      

H += val(h,0,0,0);  

point.l = 0;
    

val(d,0,0,0) = H > dry;
  }}
      

}
  }
}
  





  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/conservation.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    

{_stencil_val(d,0,0,0);_stencil_val(d,0,-1,0);
_stencil_val(d,-1,-1,0);_stencil_val(d,-1,0,0);_stencil_val(d,1,-1,0);_stencil_val(d,1,0,0);
      {_stencil_val_a(d,0,0,0);  } }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

if ((val(d,0,0,0) && !val(d,0,-1,0)) &&
 ((val(d,-1,-1,0) && !val(d,-1,0,0)) || (val(d,1,-1,0) && !val(d,1,0,0))))
      val(d,0,0,0) = 0.;}
      

}
  }
}  

remove_droplets (d, -1

, 
1e-4, 
false

);
  




  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/conservation.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    

{_stencil_val(d,0,0,0); {      

for (point.l = 0; point.l < nl; point.l++)
 

{_stencil_val_a(h,0,0,0);  }  

point.l = 0;
      

_stencil_val_a(zb,0,0,0);  
    } }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)    

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

if (!val(d,0,0,0)) {      

for (point.l = 0; point.l < nl; point.l++)
 

val(h,0,0,0) = 0.;  

point.l = 0;
      

val(zb,0,0,0) = 1e30f;
    }}
      

}
  }
}  

Conservation.sum = pmalloc (nl*sizeof (double),__func__,__FILE__,0);  

for (_layer = 0; _layer < nl; _layer++)
    

Conservation.sum[_layer] = statsf (h).sum;  

_layer = 0;delete((scalar*)((scalar[]){d,{-1}}));


}{end_tracing("init_0","/home/jacqhugo/basilisk/src/layered/conservation.h",0);return 0;}end_tracing("init_0","/home/jacqhugo/basilisk/src/layered/conservation.h",0);}




static int viscous_term_1_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}      static int viscous_term_1(const int i,const double t,Event *_ev){tracing("viscous_term_1","/home/jacqhugo/basilisk/src/layered/conservation.h",0);
{  

for (_layer = 0; _layer < nl; _layer++) 

{





    double area = 0., volume = 0.;
    if(!is_constant(cm)){
  
    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/conservation.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{
_stencil_val(h,0,0,0);
 {_stencil_val(cm,0,0,0);   } 
_stencil_val(h,0,0,0);_stencil_val(cm,0,0,0);    
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

mpi_sum_reduce_init(mpi_volume,&volume,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_area,&area,MPI_DOUBLE,MPI_SUM,1); 

{
  OMP_PARALLEL (reduction(+:area) reduction(+:volume)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
      if (val(h,0,0,0) > hmin[_layer]/10.)
 area += (( Delta*Delta)*val(cm,0,0,0));
      volume += val(h,0,0,0)*(( Delta*Delta)*val(cm,0,0,0));
    }}
      

}
  }
}

{mpi_sum_reduce_array(mpi_volume,&volume,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_area,&area,MPI_DOUBLE,MPI_SUM,1);}}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/conservation.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{
_stencil_val(h,0,0,0);
 {;   } 
_stencil_val(h,0,0,0);;    
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

mpi_sum_reduce_init(mpi_volume,&volume,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_area,&area,MPI_DOUBLE,MPI_SUM,1); 

{
  OMP_PARALLEL (reduction(+:area) reduction(+:volume)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
      if (val(h,0,0,0) > hmin[_layer]/10.)
 area += (( Delta*Delta)*_const_cm);
      volume += val(h,0,0,0)*(( Delta*Delta)*_const_cm);
    }}
      

}
  }
}

{mpi_sum_reduce_array(mpi_volume,&volume,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_area,&area,MPI_DOUBLE,MPI_SUM,1);}}





    if (!(area > 0.)) qassert ("/home/jacqhugo/basilisk/src/layered/conservation.h", 0, "area > 0.");
    double dh = (Conservation.sum[_layer] - volume)/area;
    if (!(dh > - hmin[_layer]/10.)) qassert ("/home/jacqhugo/basilisk/src/layered/conservation.h", 0, "dh > - hmin[_layer]/10.");
  
    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/layered/conservation.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);      

{_stencil_val(h,0,0,0);
 {_stencil_val_r(h,0,0,0);  }   }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)      

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

if (val(h,0,0,0) > hmin[_layer]/10.)
 val(h,0,0,0) += dh;}
      

}
  }
}  

}  

_layer = 0;


}{end_tracing("viscous_term_1","/home/jacqhugo/basilisk/src/layered/conservation.h",0);return 0;}end_tracing("viscous_term_1","/home/jacqhugo/basilisk/src/layered/conservation.h",0);}




static int cleanup_1_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(t = TEND_EVENT)!=0;*ip=i;*tp=t;return ret;}      static int cleanup_1(const int i,const double t,Event *_ev){tracing("cleanup_1","/home/jacqhugo/basilisk/src/layered/conservation.h",0);
{
  pfree (Conservation.sum,__func__,__FILE__,0);
}{end_tracing("cleanup_1","/home/jacqhugo/basilisk/src/layered/conservation.h",0);return 0;}end_tracing("cleanup_1","/home/jacqhugo/basilisk/src/layered/conservation.h",0);}








#include <stdarg.h>



FILE * kdt_tmpfile (void);

typedef struct {
  double x, y, z;
} KdtPoint;

typedef struct {
  float l, h;
} KdtInterval;

typedef KdtInterval KdtRect[2];

typedef struct {
  KdtPoint * p;
  long start, len, i, end, buflen, current;
  FILE * fp;
  void * buf;
} KdtHeap;

void kdt_heap_create (KdtHeap * h, FILE * fp, long start, long len, long buflen);
void kdt_heap_resize (KdtHeap * h, long len);
int kdt_heap_get (KdtHeap * h, KdtPoint * p);
void kdt_heap_split (KdtHeap * h1, long len1, KdtHeap * h2);
void kdt_heap_put (KdtHeap * h, KdtPoint * p);
void kdt_heap_flush (KdtHeap * h);
void kdt_heap_free (KdtHeap * h);
void kdt_heap_rewind (KdtHeap * h);

typedef struct {





  double m01, m02, m03;
  double m11, m13;
  double m22, m23, m33;
  double m44, m55, m66, m77;
  double m67, m76;
  double H0, H1, H2, H3, H4;
  double H5, H6;
  float Hmin, Hmax;
  float coverage;
  int n;

} KdtSumCore;

typedef struct {





  double m01, m02, m03;
  double m11, m13;
  double m22, m23, m33;
  double m44, m55, m66, m77;
  double m67, m76;
  double H0, H1, H2, H3, H4;
  double H5, H6;
  float Hmin, Hmax;
  float coverage;
  int n;

  double w;
} KdtSum;

typedef struct _Kdt Kdt;
typedef int (* KdtCheck) (const KdtRect rect, void * data);

int kdt_intersects (const KdtRect rect, const KdtRect query);
int kdt_includes (const KdtRect rect, const KdtRect query);

Kdt * kdt_new (void);
int kdt_create (Kdt * kdt,
       const char * name,
       int blksize,
       KdtHeap * h,
       void (* progress) (float complete, void * data),
       void * data);
int kdt_open (Kdt * kdt, const char * name);
void kdt_destroy (Kdt * kdt);
long kdt_query (const Kdt * kdt, const KdtRect rect);
long kdt_query_sum (const Kdt * kdt,
       KdtCheck includes, KdtCheck intersects, void * data,
       const KdtRect query, KdtSum * sum);
void kdt_sum_init (KdtSum * s);








static int includes_point (KdtRect rect, Point point)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

Delta_x /= 2.; Delta_y /= 2.;
  return (rect[0].l >= x - Delta_x && rect[0].h <= x + Delta_x &&
   rect[1].l >= y - Delta_y && rect[1].h <= y + Delta_y);
}

static int includes (KdtRect rect, Point * p)
{
  return includes_point (rect, *p);
}

static int intersects_point (KdtRect rect, Point point)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

Delta_x /= 2.; Delta_y /= 2.;
  return (rect[0].l <= x + Delta_x && rect[0].h >= x - Delta_x &&
   rect[1].l <= y + Delta_y && rect[1].h >= y - Delta_y);
}

static int intersects (KdtRect rect, Point * p)
{
  return intersects_point (rect, *p);
}


static void reconstruct_terrain (Point point, scalar zb)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

KdtSum s;
  kdt_sum_init (&s);
  Delta_x /= 2.; Delta_y /= 2.;
  KdtRect rect = {{x - Delta_x, x + Delta_x},
    {y - Delta_y, y + Delta_y}};
  for (Kdt ** kdt = (Kdt **) _attribute[zb.i].kdt[tid()]; *kdt; kdt++)
    kdt_query_sum (*kdt,
     (KdtCheck) includes,
     (KdtCheck) intersects, &point,
     rect, &s);
  scalar n = _attribute[zb.i].nt, dmin = _attribute[zb.i].dmin, dmax = _attribute[zb.i].dmax;
  val(n,0,0,0) = s.n;
  if (s.w > 0.) {
    val(zb,0,0,0) = s.H0/s.w;
    val(dmin,0,0,0) = s.Hmin;
    val(dmax,0,0,0) = s.Hmax;
  }
  else {


    if (level > 0)
      val(zb,0,0,0) = (9.*coarse(zb,0,0,0) +
       3.*(coarse(zb,child.x,0,0) + coarse(zb,0,child.y,0)) +
       coarse(zb,child.x,child.y,0))/16.;
    else
      val(zb,0,0,0) = 0.;
    val(dmin,0,0,0) = 1e30f;
    val(dmax,0,0,0) = 1e30f;
  }
}

static void _stencil_reconstruct_terrain (Point point, scalar zb)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  

scalar n = _attribute[zb.i].nt, dmin = _attribute[zb.i].dmin, dmax = _attribute[zb.i].dmax;
  _stencil_val_a(n,0,0,0);
{ {
    _stencil_val_a(zb,0,0,0);  
    _stencil_val_a(dmin,0,0,0);  
    _stencil_val_a(dmax,0,0,0);  
  } 
{


{
      {_stencil_coarse(zb,0,0,0);
_stencil_coarse(zb,o_stencil,0,0); _stencil_coarse(zb,0,o_stencil,0);
       _stencil_coarse(zb,o_stencil,o_stencil,0);

_stencil_val_a(zb,0,0,0);  
          
}
      
{_stencil_val_a(zb,0,0,0);  }}    
_stencil_val_a(dmin,0,0,0);  
    _stencil_val_a(dmax,0,0,0);  
  }}
}

void refine_terrain (Point point, scalar zb)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
  

{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;    

reconstruct_terrain (point, zb);
      

}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }

}


void delete_terrain (scalar zb)
{
  if (!_attribute[zb.i].kdt)
    return;
  for (int i = 0; i < omp_get_max_threads(); i++) {
    for (Kdt ** kdt = (Kdt **) _attribute[zb.i].kdt[i]; *kdt; kdt++)
      kdt_destroy (*kdt);
    pfree (_attribute[zb.i].kdt[i],__func__,__FILE__,0);
  }
  pfree (_attribute[zb.i].kdt,__func__,__FILE__,0);
  _attribute[zb.i].kdt = NULL;
}

#define CHARP char *

     
void terrain (scalar zb, ...)
{tracing("terrain","/home/jacqhugo/basilisk/src/terrain.h",0);
  _attribute[zb.i].kdt = ((void * *) pcalloc (omp_get_max_threads(), sizeof(void *),__func__,__FILE__,0));
  _attribute[zb.i].delete = delete_terrain;

  int nt = 0;
  va_list ap;
  va_start (ap, zb);
  char * name;
  while ((name = va_arg (ap, CHARP))) {
    for (int i = 0; i < omp_get_max_threads(); i++) {
      Kdt ** kdt = (Kdt **) _attribute[zb.i].kdt[i];
      _attribute[zb.i].kdt[i] = kdt = (Kdt * *) prealloc (kdt, (nt + 2)*sizeof(Kdt *),__func__,__FILE__,0);
      kdt[nt] = kdt_new();
      kdt[nt + 1] = NULL;
      char * fname = name;
      if (name[0] == '~') {
 char * home = getenv ("HOME");
 if (home != NULL) {
   fname = pmalloc(sizeof(char)*(strlen(home) + strlen(name)),__func__,__FILE__,0);
   strcpy (fname, home);
   strcat (fname, name + 1);
 }
      }
      if (kdt_open (kdt[nt], fname)) {
 fprintf (ferr, "terrain: could not open terrain database '%s'\n",
   fname);
 exit (1);
      }
      if (fname != name)
 pfree (fname,__func__,__FILE__,0);
    }
    nt++;
  }
  va_end (ap);

  scalar n = new_scalar("n");
  scalar dmin = new_scalar("dmin");
  scalar dmax = new_scalar("dmax");
  _attribute[zb.i].nt = n;
  _attribute[zb.i].dmin = dmin;
  _attribute[zb.i].dmax = dmax;

  trash (((scalar[]){zb,{-1}}));

  for (int l = 0; l <= depth(); l++) {
  
    

if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);      

_stencil_reconstruct_terrain (point, zb);
  

} 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = l;
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
    for (_k = 2; _k < point.n.x + 2; _k++) {
      point.i = _k;

      for (point.j = 2; point.j < point.n.y + 2; point.j++)      

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

reconstruct_terrain (point, zb);}
    

}
  }
}    

boundary_level (((scalar[]){zb,{-1}}), l);
  }

  delete_terrain (zb);

end_tracing("terrain","/home/jacqhugo/basilisk/src/terrain.h",0);}







void input_pgm (scalar s, FILE * fp,
  double ox, double oy, double width)
{
  char line[81];
  if (!fgets (line, 81, fp)) {
    fprintf (ferr, "input_pgm: could not read magic number\n");
    exit (1);
  }
  if (strcmp (line, "P2\n") && strcmp (line, "P5\n")) {
    fprintf (ferr, "input_pgm: magic number '%s' does not match PGM\n",
      line);
    exit (1);
  }
  int binary = !strcmp (line, "P5\n");
  if (!fgets (line, 81, fp)) {
    fprintf (ferr, "input_pgm: could not read width and height\n");
    exit (1);
  }
  int W, H;
  while (line[0] == '#' && fgets (line, 81, fp));
  if (line[0] == '#' || sscanf (line, "%d %d", &W, &H) != 2) {
    fprintf (ferr, "input_pgm: could not read width and height\n");
    exit (1);
  }
  if (!fgets (line, 81, fp)) {
    fprintf (ferr, "input_pgm: could not read maxval\n");
    exit (1);
  }
  int maxval;
  if (sscanf (line, "%d", &maxval) != 1) {
    fprintf (ferr, "input_pgm: could not read maxval\n");
    exit (1);
  }
  if (maxval < 256) {
    unsigned char * a = ((unsigned char *) pmalloc ((W*H)*sizeof(unsigned char),__func__,__FILE__,0));
    size_t n = 0;
    if (binary)
      n = fread (a, 1, W*H, fp);
    else {
      int v;
      while (n < W*H && fscanf (fp, "%d ", &v) == 1)
 a[n++] = v;
    }
    if (n != W*H) {
      fprintf (ferr, "input_pgm: read only %ld values\n", n);
      exit (1);
    }
  
    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/input.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{          
      
{
 {_stencil_val_a(s,0,0,0);          }
 
{_stencil_val_a(s,0,0,0);  }}    
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
      int i = (x - ox)*W/width, j = (y - oy)*W/width;
      if (i >= 0 && i < W && j >= 0 && j < H)
 val(s,0,0,0) = 1. - a[(H - 1 - j)*W + i]/(double)maxval;
      else
 val(s,0,0,0) = 0.;
    }}
      

}
  }
}    

pfree (a,__func__,__FILE__,0);
  }
  else {
    unsigned short * a = ((unsigned short *) pmalloc ((W*H)*sizeof(unsigned short),__func__,__FILE__,0));
    size_t n = 0;
    if (binary)
      n = fread (a, 2, W*H, fp);
    else {
      int v;
      while (n < W*H && fscanf (fp, "%d ", &v) == 1)
 a[n++] = v;
    }
    if (n != W*H) {
      fprintf (ferr, "input_pgm: read only %ld values\n", n);
      exit (1);
    }
  
    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/input.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{          
      
{
 {_stencil_val_a(s,0,0,0);          }
 
{_stencil_val_a(s,0,0,0);  }}    
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
      int i = (x - ox)*W/width, j = (y - oy)*W/width;
      if (i >= 0 && i < W && j >= 0 && j < H)
 val(s,0,0,0) = 1. - a[(H - 1 - j)*W + i]/(double)maxval;
      else
 val(s,0,0,0) = 0.;
    }}
      

}
  }
}    

pfree (a,__func__,__FILE__,0);
  }
}

static void next_char (FILE * fp, int target)
{
  int c = fgetc(fp), para = 0;
  while (c != EOF && (c != target || para > 0)) {
    if (c == '{') para++;
    if (c == '}') para--;
    c = fgetc(fp);
  }
  if (c != target) {
    fprintf (ferr, "input_gfs(): error: expecting '%c'\n", target);
    exit (1);
  }
}

static int next_string (FILE * fp, const char * target)
{
  int slen = strlen (target), para = 0;
  char s[slen + 1];
  s[slen] = '\0';
  int len = 0, c = fgetc (fp);
  while (c != EOF && len < slen) {
    if (c == '{') para++;
    if (c == '}') para--;
    s[len++] = c;
    c = fgetc (fp);
  }
  while (c != EOF && para >= 0) {
    if (!strcmp (s, target) && para == 0)
      break;
    if (c == '{') para++;
    if (c == '}') para--;
    for (int i = 0; i < slen - 1; i++)
      s[i] = s[i+1];
    s[slen - 1] = c;
    c = fgetc (fp);
  }
  if (strcmp (s, target))
    c = -1;
  return c;
}

     
void input_gfs (FILE * fp,
  scalar * list,
  char * file)
{tracing("input_gfs","/home/jacqhugo/basilisk/src/input.h",0);
  not_mpi_compatible();

  if (file && !(fp = fopen (file, "r"))) {
    perror (file);
    exit (1);
  }

  bool input_all = (list == all);
  if (!list) list = all;





  next_char (fp, '{');

  char * s = ((char *) pmalloc ((1)*sizeof(char),__func__,__FILE__,0));
  int len = 0;
  int c = fgetc(fp);
  while (c != EOF && c != '}') {
    s[len++] = c;
    s = (char *) prealloc (s, (len + 1)*sizeof(char),__func__,__FILE__,0);
    s[len] = '\0';
    c = fgetc(fp);
  }
  if (c != '}') {
    fprintf (ferr, "input_gfs(): error: expecting '}'\n");
    exit (1);
  }

  char * s1 = strstr (s, "variables");
  if (!s1) {
    fprintf (ferr, "input_gfs(): error: expecting 'variables'\n");
    exit (1);
  }

  s1 = strstr (s1, "=");
  if (!s1) {
    fprintf (ferr, "input_gfs(): error: expecting '='\n");
    exit (1);
  }
  s1++;

  while (strchr (" \t", *s1))
    s1++;

  scalar * input = NULL;
  s1 = strtok (s1, ", \t");
  while (s1) {
    char * name = replace (s1, '_', '.', false);
    bool found = false;
    {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      if (!is_constant(s) && _attribute[s.i].name && !strcmp (_attribute[s.i].name, name)) {
 input = list_append (input, s);
 found = true; break;
      }}}
    if (!found) {
      if (input_all) {
 scalar s = new_scalar("s");
 pfree (_attribute[s.i].name,__func__,__FILE__,0);
 _attribute[s.i].name = pstrdup (name,__func__,__FILE__,0);
 input = list_append (input, s);
      }
      else
 input = list_append (input, (scalar){INT_MAX});
    }
    pfree (name,__func__,__FILE__,0);
    s1 = strtok (NULL, ", \t");
  }
  pfree (s,__func__,__FILE__,0);

  next_char (fp, '{');
  double t1 = 0.;
  if (next_string (fp, "Time") >= 0) {
    next_char (fp, '{');
    next_char (fp, 't');
    next_char (fp, '=');
    if (fscanf (fp, "%lf", &t1) != 1) {
      fprintf (ferr, "input_gfs(): error: expecting 't'\n");
      exit (1);
    }
    next_char (fp, '}');
    next_char (fp, '}');
  }

  if (next_string (fp, "Box") < 0) {
    fprintf (ferr, "input_gfs(): error: expecting 'GfsBox'\n");
    exit (1);
  }

  next_char (fp, '{');
  next_char (fp, '{');
  next_char (fp, '\n');

  scalar * listm =((scalar[]) {cm,fm.x,fm.y,{-1}});
  scalar * listr = !is_constant(cm) ? listm : NULL;
  NOT_UNUSED (listr);


{
  if (!Dimensions.x) Dimensions.x = 1;
  if (!Dimensions.y) Dimensions.y = 1;
  for (int ox = 0; ox < Dimensions.x; ox++)
    for (int oy = 0; oy < Dimensions.y; oy++) {
      Point root = {2 + ox, 2 + oy, 0};

{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};



    struct { int l, i, j, stage; } stack[20];




    int _s = -1;
    { _s++; stack[_s].l = root.level; stack[_s].i = root.i; stack[_s].j = root.j; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; point.j = stack[_s].j; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    unsigned flags;
    if (fread (&flags, sizeof (unsigned), 1, fp) != 1) {
      fprintf (ferr, "input_gfs(): error: expecting 'flags'\n");
      exit (1);
    }
    if (!(flags & (1 << 4)) && is_leaf(cell))
      refine_cell (point, listr, 0, NULL);
    double a;
    if (fread (&a, sizeof (double), 1, fp) != 1 || a != -1) {
      fprintf (ferr, "input_gfs(): error: expecting '-1'\n");
      exit (1);
    }
    {scalar*_i=(scalar*)( input);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
      if (fread (&a, sizeof (double), 1, fp) != 1) {
 fprintf (ferr, "input_gfs(): error: expecting a scalar\n");
 exit (1);
      }
      if (s.i != INT_MAX) {
 if (_attribute[s.i].v.x.i >= 0) {



   if (_attribute[s.i].v.x.i == s.i) {
     s = _attribute[s.i].v.y;
     val(s,0,0,0) = a;
   }
   else if (_attribute[s.i].v.y.i == s.i) {
     s = _attribute[s.i].v.x;
     val(s,0,0,0) = - a;
   }





 }
 else
   val(s,0,0,0) = a;
      }
    }}}
    if (is_leaf(cell))
      continue;
  }} 

if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; };
 }
 break;
      }



      case 1: { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 2; };
 { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; }; break;
      case 2: { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].j = point.j; stack[_s].stage = 3; };
 { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = (2*point.j - 2); stack[_s].stage = 0; }; break;
      case 3: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].j = ((2*point.j - 2) + 1); stack[_s].stage = 0; }; break;

      }
    }
  }
}
    

}
}  

{scalar*_i=(scalar*)( listm);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!is_constant(s))
      set_dirty_stencil (s);}}
  {scalar*_i=(scalar*)( input);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (s.i != INT_MAX && !is_constant(s))
      set_dirty_stencil (s);}}

  pfree (input,__func__,__FILE__,0);
  if (file)
    fclose (fp);


  while (t < t1 && events (false))
    t = tnext;
  events (false);
end_tracing("input_gfs","/home/jacqhugo/basilisk/src/input.h",0);}



static void bc_grd (double * v, int nx, int ny, bool periodic[2])
{
  if (periodic[0])
    for (int i = 0; i < ny; i++) {
      ((v)[(-1) + 1 + ((i) + 1)*(nx + 2)]) = ((v)[(nx - 1) + 1 + ((i) + 1)*(nx + 2)]);
      ((v)[(nx) + 1 + ((i) + 1)*(nx + 2)]) = ((v)[(0) + 1 + ((i) + 1)*(nx + 2)]);
    }
  else
    for (int i = 0; i < ny; i++) {
      ((v)[(-1) + 1 + ((i) + 1)*(nx + 2)]) = ((v)[(0) + 1 + ((i) + 1)*(nx + 2)]);
      ((v)[(nx) + 1 + ((i) + 1)*(nx + 2)]) = ((v)[(nx - 1) + 1 + ((i) + 1)*(nx + 2)]);
    }
  if (periodic[1])
    for (int j = -1; j <= nx; j++) {
      ((v)[(j) + 1 + ((-1) + 1)*(nx + 2)]) = ((v)[(j) + 1 + ((ny - 1) + 1)*(nx + 2)]);
      ((v)[(j) + 1 + ((ny) + 1)*(nx + 2)]) = ((v)[(j) + 1 + ((0) + 1)*(nx + 2)]);
    }
  else
    for (int j = -1; j <= nx; j++) {
      ((v)[(j) + 1 + ((-1) + 1)*(nx + 2)]) = ((v)[(j) + 1 + ((0) + 1)*(nx + 2)]);
      ((v)[(j) + 1 + ((ny) + 1)*(nx + 2)]) = ((v)[(j) + 1 + ((ny - 1) + 1)*(nx + 2)]);
    }
}

void input_grd (scalar s,
  FILE * fp, const char * file,
  double nodatavalue,
  bool linear,
  bool periodic[2],
  int smooth)
{
  scalar input = s;

  if (file && !(fp = fopen (file, "r"))) {
    perror (file);
    exit (1);
  }


  double DeltaGRD;
  int nx, ny;
  double XG0, YG0, ndv;


  char waste[100];
  if (fscanf (fp, "%s %d", waste, &nx) != 2) {
    fprintf (ferr, "input_grd(): error reading 'nx'\n");
    if (file) fclose (fp);
    return;
  }
  if (fscanf (fp, "%s %d", waste, &ny) != 2) {
    fprintf (ferr, "input_grd(): error reading 'ny'\n");
    if (file) fclose (fp);
    return;
  }
  if (fscanf (fp, "%s %lf", waste, &XG0) != 2) {
    fprintf (ferr, "input_grd(): error reading 'XG0'\n");
    if (file) fclose (fp);
    return;
  }
  if (fscanf (fp, "%s %lf", waste, &YG0) != 2) {
    fprintf (ferr, "input_grd(): error reading 'YG0'\n");
    if (file) fclose (fp);
    return;
  }
  if (fscanf (fp, "%s %lf", waste, &DeltaGRD) != 2) {
    fprintf (ferr, "input_grd(): error reading 'DeltaGRD'\n");
    if (file) fclose (fp);
    return;
  }
  if (fscanf (fp, "%s %lf", waste, &ndv) != 2) {
    fprintf (ferr, "input_grd(): error reading 'ndv'\n");
    if (file) fclose (fp);
    return;
  }


  if (nodatavalue == 0.12345678)
    nodatavalue = ndv;


  double * value = ((double *) pmalloc (((nx + 2)*(ny + 2))*sizeof(double),__func__,__FILE__,0));
  for (int i = ny - 1; i >= 0; i--)
    for (int j = 0 ; j < nx; j++) {
      if (fscanf (fp, "%lf ", &((value)[(j) + 1 + ((i) + 1)*(nx + 2)])) != 1) {
 fprintf (ferr, "input_grd(): error reading value %d,%d\n", i, j);
 if (file) fclose (fp);
 pfree (value,__func__,__FILE__,0);
 return;
      }
    }
  bc_grd (value, nx, ny, periodic);


  if (smooth > 0) {
    double * smoothed = ((double *) pmalloc (((nx + 2)*(ny + 2))*sizeof(double),__func__,__FILE__,0));
    for (int s = 0; s < smooth; s++) {
      for (int i = 0; i < ny; i++)
 for (int j = 0 ; j < nx; j++) {
   int n = 0;
   ((smoothed)[(j) + 1 + ((i) + 1)*(nx + 2)]) = 0.;
   for (int k = -1; k <= 1; k++)
     for (int l = -1; l <= 1; l++)
       if ((l != 0 || k != 0) &&
    ((value)[(j + l) + 1 + ((i + k) + 1)*(nx + 2)]) != ndv)
  ((smoothed)[(j) + 1 + ((i) + 1)*(nx + 2)]) += ((value)[(j + l) + 1 + ((i + k) + 1)*(nx + 2)]), n++;
   if (n == 0)
     ((smoothed)[(j) + 1 + ((i) + 1)*(nx + 2)]) = ndv;
   else
     ((smoothed)[(j) + 1 + ((i) + 1)*(nx + 2)]) /= n;
 }
      do { double * _tmp_ = value; value = smoothed; smoothed = _tmp_; } while(false);
      bc_grd (value, nx, ny, periodic);
    }
    pfree (smoothed,__func__,__FILE__,0);
  }

  bool warning = false;
  #undef OMP
  #define OMP(x)
  

;

{  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/jacqhugo/basilisk/src/input.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{            
    
            
              
     
    
            
              
     

    
    
{ {
{ 

{              

 
 
 _stencil_val_a(input,0,0,0); 
                           
                            
                          
                          
                
      }
 
{_stencil_val_a(input,0,0,0);          }}    
} 
{
      _stencil_val_a(input,0,0,0);    
      
    }}  
}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    if (periodic[0]) {
      while (x < XG0) x += nx*DeltaGRD;
      while (x > XG0 + nx*DeltaGRD) x -= nx*DeltaGRD;
    }
    if (periodic[1]) {
      while (y < YG0) y += ny*DeltaGRD;
      while (y > YG0 + ny*DeltaGRD) y -= ny*DeltaGRD;
    }

    int j1 = (x - XG0)/DeltaGRD;
    int i1 = (y - YG0)/DeltaGRD;
    if (i1 >= -1 && i1 < ny && j1 >= -1 && j1 < nx) {
      if (linear &&
   ((value)[(j1) + 1 + ((i1) + 1)*(nx + 2)]) != ndv && ((value)[(j1 + 1) + 1 + ((i1) + 1)*(nx + 2)]) != ndv &&
   ((value)[(j1) + 1 + ((i1 + 1) + 1)*(nx + 2)]) != ndv && ((value)[(j1 + 1) + 1 + ((i1 + 1) + 1)*(nx + 2)]) != ndv) {

 double dx = x - (j1*DeltaGRD + XG0);
 double dy = y - (i1*DeltaGRD + YG0);
 val(input,0,0,0) = (((value)[(j1) + 1 + ((i1) + 1)*(nx + 2)]) +
     dx*(((value)[(j1 + 1) + 1 + ((i1) + 1)*(nx + 2)]) - ((value)[(j1) + 1 + ((i1) + 1)*(nx + 2)]))/DeltaGRD +
     dy*(((value)[(j1) + 1 + ((i1 + 1) + 1)*(nx + 2)]) - ((value)[(j1) + 1 + ((i1) + 1)*(nx + 2)]))/DeltaGRD +
     dx*dy*(((value)[(j1) + 1 + ((i1) + 1)*(nx + 2)]) + ((value)[(j1 + 1) + 1 + ((i1 + 1) + 1)*(nx + 2)]) -
     ((value)[(j1) + 1 + ((i1 + 1) + 1)*(nx + 2)]) - ((value)[(j1 + 1) + 1 + ((i1) + 1)*(nx + 2)]))
     /( DeltaGRD*DeltaGRD));
      }
      else
 val(input,0,0,0) = ((value)[(j1) + 1 + ((i1) + 1)*(nx + 2)]);
    }
    else {
      val(input,0,0,0) = nodatavalue;
      warning = true;
    }
  }}      

}
  }
}

}
  #undef OMP
#define OMP(x) _Pragma(#x)
  

;
  

pfree (value,__func__,__FILE__,0);

  if (warning)
    fprintf (ferr,
      "%s:%d: warning: raster data is not covering all the simulation area\n",
      "/home/jacqhugo/basilisk/src/input.h", 0);

  if (file)
    fclose (fp);
}

static int perfs_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i += 1)!=0;*ip=i;*tp=t;return ret;}









      static int perfs(const int i,const double t,Event *_ev){tracing("perfs","/home/jacqhugo/basilisk/src/layered/perfs.h",0); {
  static FILE * fp =NULL;if(!fp||i==0)fp=pid()>0?fopen("/dev/null","w"): fopen ("perfs", "w");
  if (i == 0)
    fprintf (fp,
      "t dt mgp.i mgp.nrelax grid->tn perf.t perf.speed npe perf.ispeed\n");
  static double start = 0.;
  if (i > 10 && perf.t - start < 1.) {end_tracing("perfs","/home/jacqhugo/basilisk/src/layered/perfs.h",0);return 0;}
  fprintf (fp, "%g %g %d %d %ld %g %g %d %g\n",
    t, dt,



    mgH.i, mgH.nrelax,



    grid->tn*nl, perf.t, perf.speed*nl, npe(), perf.ispeed*nl);
  fflush (fp);
  start = perf.t;
}{end_tracing("perfs","/home/jacqhugo/basilisk/src/layered/perfs.h",0);return 0;}end_tracing("perfs","/home/jacqhugo/basilisk/src/layered/perfs.h",0);}






static int perf_plot_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i = 10)!=0;*ip=i;*tp=t;return ret;}      static int perf_plot(const int i,const double t,Event *_ev){tracing("perf_plot","/home/jacqhugo/basilisk/src/layered/perfs.h",0); {
  if (getenv ("DISPLAY"))
    qpopen ("gnuplot -e 'set term x11 noraise title perfs' "
    "$BASILISK/layered/perfs.plot 2> /dev/null "
    "& read dummy; kill $! 2> /dev/null", "w");
}{end_tracing("perf_plot","/home/jacqhugo/basilisk/src/layered/perfs.h",0);return 0;}end_tracing("perf_plot","/home/jacqhugo/basilisk/src/layered/perfs.h",0);}





const double hour = 3600., day = 86400., month = 30.*day, year = 365.*day;

vector ua, ud;
scalar Ha,  etam={2},  eta2={3};
vector  uga={{4},{5}},  ugd={{6},{7}};




double maxlat = 90;





double tspinup = 5.*year;

void laplacian_smoothing()
{
  for (int i = 0; i < 2; i++) {
  
    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./ocean.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{
_stencil_val(zb,0,0,0);{
 {_stencil_val(zb,1,0,0); _stencil_val(zb,-1,0,0); _stencil_val(zb,0,1,0); _stencil_val(zb,0,-1,0);
   _stencil_val(zb,1,1,0); _stencil_val(zb,-1,-1,0); _stencil_val(zb,-1,1,0); _stencil_val(zb,1,-1,0);

_stencil_val_a(zbs,0,0,0);         
}
 
{ _stencil_val(zb,0,0,0);_stencil_val_a(zbs,0,0,0); }}    
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
      if (val(zb,0,0,0) < 0.)
 val(zbs,0,0,0) = (val(zb,1,0,0) + val(zb,-1,0,0) + val(zb,0,1,0) + val(zb,0,-1,0) +
   val(zb,1,1,0) + val(zb,-1,-1,0) + val(zb,-1,1,0) + val(zb,1,-1,0))/8.;
      else
 val(zbs,0,0,0) = val(zb,0,0,0);
    }}
      

}
  }
}
  
    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./ocean.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);      

{ _stencil_val(zbs,0,0,0);_stencil_val_a(zb,0,0,0); }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)      

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

val(zb,0,0,0) = val(zbs,0,0,0);}
      

}
  }
}  

}
}

static double _boundary0(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{return( dirichlet(0

, point, _s

));}}}static double _boundary0_homogeneous(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{return( dirichlet_homogeneous(0

, point, _s

));}}}static void _stencil_boundary0(Point point,Point neighbor,scalar _s,_stencil_undefined *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));      
  

  





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
      
  Delta *= Radius*3.14159265358979/180.;
   
               
   
   
  

Point parent = point; 
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{return ;}}}
static double _boundary1(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{return( dirichlet(0

, point, _s

));}}}static double _boundary1_homogeneous(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{return( dirichlet_homogeneous(0

, point, _s

));}}}static void _stencil_boundary1(Point point,Point neighbor,scalar _s,_stencil_undefined *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));      
  

  





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
      
  Delta *= Radius*3.14159265358979/180.;
   
               
   
   
  

Point parent = point; 
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{return ;}}}
static double _boundary2(Point point,Point neighbor,scalar _s,bool *data){{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{return( 1000);}}}static void _stencil_boundary2(Point point,Point neighbor,scalar _s,_stencil_undefined *data){{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{return ;}}}
static double _boundary3(Point point,Point neighbor,scalar _s,bool *data){{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{return( 1000);}}}static void _stencil_boundary3(Point point,Point neighbor,scalar _s,_stencil_undefined *data){{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{return ;}}}
static double _boundary4(Point point,Point neighbor,scalar _s,bool *data){{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{return( 0);}}}static void _stencil_boundary4(Point point,Point neighbor,scalar _s,_stencil_undefined *data){{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{return ;}}}
static double _boundary5(Point point,Point neighbor,scalar _s,bool *data){{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;NOT_UNUSED(jg);  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{return( 0);}}}static void _stencil_boundary5(Point point,Point neighbor,scalar _s,_stencil_undefined *data){{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{return ;}}}

static int init_1_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i = 0)!=0;*ip=i;*tp=t;return ret;}      static int init_1(const int i,const double t,Event *_ev){tracing("init_1","./ocean.h",0);
{
  if (restore ("restart"

, 
NULL, 
NULL

))
    event ("metric");
  else {







    terrain (zb, "~/terrain/etopo2", NULL);
    laplacian_smoothing();
  

    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./ocean.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{    
      
_stencil_val(zb,0,0,0);{
 {_stencil_val_a(zb,0,0,0);  }
 
{_stencil_val(zb,0,0,0);_stencil_val_a(zb,0,0,0);      }}    
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
      double zbmin = - 6500.;
      if (val(zb,0,0,0) > - 200 || fabs(y) > maxlat)
 val(zb,0,0,0) = 1000.;
      else
 val(zb,0,0,0) = zbmin + 0.82*(val(zb,0,0,0) - zbmin);
    }}
      

}
  }
}
  





    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./ocean.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{   
      
      for (point.l = nl - 1; point.l >= 0; point.l--) { 
_stencil_val(zb,0,0,0);{
   {_stencil_val_a(h,0,0,0);  }
   
{ _stencil_val(zb,0,0,0); _stencil_val(zb,0,0,0);_stencil_val_a(h,0,0,0);           }} 
_stencil_val(h,0,0,0);      
}
    }

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
      double z = 0.;
      for (point.l = nl - 1; point.l >= 0; point.l--) {
 if (point.l > 0 && z - dh[point.l] > val(zb,0,0,0))
   val(h,0,0,0) = dh[point.l];
 else
   val(h,0,0,0) = ( (z - val(zb,0,0,0)) > 0. ? (z - val(zb,0,0,0)) : 0.);
 z -= val(h,0,0,0);
      }
    }}
      

}
  }
}    

reset (((scalar[]){etam, eta2, ua.x, ua.y, ud.x, ud.y, Ha, uga.x, uga.y, ugd.x, ugd.y,{-1}}), 0.);
  }

  
    if (!Period.x) {
set_dirty_stencil(u.y),_attribute[u.y.i].boundary[right]=_boundary0,_attribute[u.y.i].boundary_homogeneous[right]=_boundary0_homogeneous,_attribute[u.y.i].boundary_stencil[right]=_stencil_boundary0;
set_dirty_stencil(u.y),_attribute[u.y.i].boundary[left]=_boundary1,_attribute[u.y.i].boundary_homogeneous[left]=_boundary1_homogeneous,_attribute[u.y.i].boundary_stencil[left]=_stencil_boundary1;
set_dirty_stencil(zb),_attribute[zb.i].boundary[right]=_boundary2,_attribute[zb.i].boundary_homogeneous[right]=_boundary2,_attribute[zb.i].boundary_stencil[right]=_stencil_boundary2;
set_dirty_stencil(zb),_attribute[zb.i].boundary[left]=_boundary3,_attribute[zb.i].boundary_homogeneous[left]=_boundary3,_attribute[zb.i].boundary_stencil[left]=_stencil_boundary3;
set_dirty_stencil(h),_attribute[h.i].boundary[right]=_boundary4,_attribute[h.i].boundary_homogeneous[right]=_boundary4,_attribute[h.i].boundary_stencil[right]=_stencil_boundary4;
set_dirty_stencil(h),_attribute[h.i].boundary[left]=_boundary5,_attribute[h.i].boundary_homogeneous[left]=_boundary5,_attribute[h.i].boundary_stencil[left]=_stencil_boundary5;
    }    

if (!Period.y) {
set_dirty_stencil(u.y),_attribute[u.y.i].boundary[top]=_boundary0,_attribute[u.y.i].boundary_homogeneous[top]=_boundary0_homogeneous,_attribute[u.y.i].boundary_stencil[top]=_stencil_boundary0;
set_dirty_stencil(u.y),_attribute[u.y.i].boundary[bottom]=_boundary1,_attribute[u.y.i].boundary_homogeneous[bottom]=_boundary1_homogeneous,_attribute[u.y.i].boundary_stencil[bottom]=_stencil_boundary1;
set_dirty_stencil(zb),_attribute[zb.i].boundary[top]=_boundary2,_attribute[zb.i].boundary_homogeneous[top]=_boundary2,_attribute[zb.i].boundary_stencil[top]=_stencil_boundary2;
set_dirty_stencil(zb),_attribute[zb.i].boundary[bottom]=_boundary3,_attribute[zb.i].boundary_homogeneous[bottom]=_boundary3,_attribute[zb.i].boundary_stencil[bottom]=_stencil_boundary3;
set_dirty_stencil(h),_attribute[h.i].boundary[top]=_boundary4,_attribute[h.i].boundary_homogeneous[top]=_boundary4,_attribute[h.i].boundary_stencil[top]=_stencil_boundary4;
set_dirty_stencil(h),_attribute[h.i].boundary[bottom]=_boundary5,_attribute[h.i].boundary_homogeneous[bottom]=_boundary5,_attribute[h.i].boundary_stencil[bottom]=_stencil_boundary5;
    }
}{end_tracing("init_1","./ocean.h",0);return 0;}end_tracing("init_1","./ocean.h",0);}

double Cw = 1.5e-3, rho_air = 1.2;





void load_wind (vector wind, int index)
{
  char name[80];






  sprintf (name, "wind/hr-%d-x.asc", index + 1);
  input_grd (wind.x

, 
stdin

, name, 0., true,

(  bool[2]) 

{true, false}
, 1);
  sprintf (name, "wind/hr-%d-y.asc", index + 1);
  input_grd (wind.y

, 
stdin

, name, 0., true,

(  bool[2]) 

{true, false}
, 1);

}

static int init_2_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i = 0)!=0;*ip=i;*tp=t;return ret;}

      static int init_2(const int i,const double t,Event *_ev){tracing("init_2","./ocean.h",0);
{

  system ("if ! test -f wind/hr-1-x.asc; then "
   " mkdir wind; cd wind; "
   " wget https://iridl.ldeo.columbia.edu/SOURCES/.HELLERMAN/.taux/data.nc -O data.nc; "
   "  for i in `seq 1 1 12`; do "
   "    gdal_translate -of AAIGrid -ot float32 -b $i -sds -q "
   "    data.nc hr-$i-x.asc; "
   "  done; "
   " wget https://iridl.ldeo.columbia.edu/SOURCES/.HELLERMAN/.tauy/data.nc -O data.nc; "
   "  for i in `seq 1 1 12`; do "
   "    gdal_translate -of AAIGrid -ot float32 -b $i -sds -q "
   "    data.nc hr-$i-y.asc; "
   "  done; "
   "fi "
   );

}{end_tracing("init_2","./ocean.h",0);return 0;}end_tracing("init_2","./ocean.h",0);}





vector  wind1={{8},{9}},  wind2={{10},{11}};

static int acceleration_3_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}      static int acceleration_3(const int i,const double t,Event *_ev){tracing("acceleration_3","./ocean.h",0);
{
  int i = t/month;
  double deltaw = (t - i*month - month/2.)/month;
  while (i > 11) i -= 12;
  int i1 = deltaw > 0 ? i : i - 1;
  int i2 = deltaw > 0 ? i + 1: i;
  if (deltaw < 0.) deltaw += 1.;
  if (i1 < 0) i1 = 11;
  if (i2 > 11) i2 = 0;
  static int t1 = -1, t2 = -1;
  if (i1 != t1)
    load_wind (wind1, i1), t1 = i1;
  if (i2 != t2)
    load_wind (wind2, i2), t2 = i2;
  
  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./ocean.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

{ 

_loop.face |= (1 << 0); 

{
    point.l = nl - 1;
_stencil_val(hf.x,0,0,0); {      
         
       _stencil_val(wind2.x,-1,0,0);_stencil_val(wind2.x,0,0,0); 

_stencil_val(wind1.x,-1,0,0);_stencil_val(wind1.x,0,0,0);    



      

      
_stencil_val_r(ha.x,0,0,0);  
    }  
} 

_loop.face |= (1 << 1); 

{
    point.l = nl - 1;
_stencil_val(hf.y,0,0,0); {      
         
       _stencil_val(wind2.y,0,-1,0);_stencil_val(wind2.y,0,0,0); 

_stencil_val(wind1.y,0,-1,0);_stencil_val(wind1.y,0,0,0);    



      

      
_stencil_val_r(ha.y,0,0,0);  
    }  
}}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)

{
  

if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    point.l = nl - 1;
    if (val(hf.x,0,0,0) > 10.) {
      double tauw = ((1. - deltaw)*(val(wind1.x,0,0,0) + val(wind1.x,-1,0,0)) +
       deltaw*(val(wind2.x,0,0,0) + val(wind2.x,-1,0,0)))/2.;



      double n = 0.1;

      val(ha.x,0,0,0) += n*tauw/1000.;
    }
  }}
  

}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_y = Delta;

  double Delta_x = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_y);

  NOT_UNUSED(Delta_x);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_y = Delta_x = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    point.l = nl - 1;
    if (val(hf.y,0,0,0) > 10.) {
      double tauw = ((1. - deltaw)*(val(wind1.y,0,0,0) + val(wind1.y,0,-1,0)) +
       deltaw*(val(wind2.y,0,0,0) + val(wind2.y,0,-1,0)))/2.;



      double n = 0.1;

      val(ha.y,0,0,0) += n*tauw/1000.;
    }
  }}
  

}

}      

}
  }
}


}{end_tracing("acceleration_3","./ocean.h",0);return 0;}end_tracing("acceleration_3","./ocean.h",0);}

double nu_H = 10;

static int viscous_term_2_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}      static int viscous_term_2(const int i,const double t,Event *_ev){tracing("viscous_term_2","./ocean.h",0);
{
  if (nu_H > 0.) {
    vector  d2u=new_vector("d2u");    

for (_layer = 0; _layer < nl; _layer++) 

{
      double dry = 1.;
      if(!is_constant(fm.x) && !is_constant(cm)){      

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./ocean.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
 

{
 {_stencil_val(fm.x,1,0,0);_stencil_val(fm.x,1,0,0);_stencil_val(cm,1,0,0); _stencil_val(cm,0,0,0);_stencil_val(u.x,1,0,0);_stencil_val(h,1,0,0);
_stencil_val(fm.x,0,0,0);_stencil_val(fm.x,0,0,0);_stencil_val(cm,-1,0,0); _stencil_val(cm,0,0,0);_stencil_val(u.x,-1,0,0);_stencil_val(h,-1,0,0);
_stencil_val(fm.y,0,1,0);_stencil_val(fm.y,0,1,0);_stencil_val(cm,0,1,0); _stencil_val(cm,0,0,0);_stencil_val(u.x,0,1,0);_stencil_val(h,0,1,0);
_stencil_val(fm.y,0,-1,0);_stencil_val(fm.y,0,-1,0);_stencil_val(cm,0,-1,0); _stencil_val(cm,0,0,0);_stencil_val(u.x,0,-1,0);_stencil_val(h,0,-1,0);
_stencil_val(cm,0,0,0);

_stencil_val_a(d2u.x,0,0,0);        
             
             
           
  } 

{_stencil_val(fm.y,0,1,0);_stencil_val(fm.y,0,1,0);_stencil_val(cm,0,1,0); _stencil_val(cm,0,0,0);_stencil_val(u.y,0,1,0);_stencil_val(h,0,1,0);
_stencil_val(fm.y,0,0,0);_stencil_val(fm.y,0,0,0);_stencil_val(cm,0,-1,0); _stencil_val(cm,0,0,0);_stencil_val(u.y,0,-1,0);_stencil_val(h,0,-1,0);
_stencil_val(fm.x,1,0,0);_stencil_val(fm.x,1,0,0);_stencil_val(cm,1,0,0); _stencil_val(cm,0,0,0);_stencil_val(u.y,1,0,0);_stencil_val(h,1,0,0);
_stencil_val(fm.x,-1,0,0);_stencil_val(fm.x,-1,0,0);_stencil_val(cm,-1,0,0); _stencil_val(cm,0,0,0);_stencil_val(u.y,-1,0,0);_stencil_val(h,-1,0,0);
_stencil_val(cm,0,0,0);

_stencil_val_a(d2u.y,0,0,0);        
             
             
           
  }}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)
 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
 val(d2u.x,0,0,0) = 2.*(( (val(fm.x,1,0,0))*(val(fm.x,1,0,0)))/(val(cm,1,0,0) + val(cm,0,0,0))*val(u.x,1,0,0)*(val(h,1,0,0) > dry) +
        ( (val(fm.x,0,0,0))*(val(fm.x,0,0,0)))/(val(cm,-1,0,0) + val(cm,0,0,0))*val(u.x,-1,0,0)*(val(h,-1,0,0) > dry) +
        ( (val(fm.y,0,1,0))*(val(fm.y,0,1,0)))/(val(cm,0,1,0) + val(cm,0,0,0))*val(u.x,0,1,0)*(val(h,0,1,0) > dry) +
        ( (val(fm.y,0,-1,0))*(val(fm.y,0,-1,0)))/(val(cm,0,-1,0) + val(cm,0,0,0))*val(u.x,0,-1,0)*(val(h,0,-1,0) > dry))
 /(( Delta*Delta)*val(cm,0,0,0)); 

val(d2u.y,0,0,0) = 2.*(( (val(fm.y,0,1,0))*(val(fm.y,0,1,0)))/(val(cm,0,1,0) + val(cm,0,0,0))*val(u.y,0,1,0)*(val(h,0,1,0) > dry) +
        ( (val(fm.y,0,0,0))*(val(fm.y,0,0,0)))/(val(cm,0,-1,0) + val(cm,0,0,0))*val(u.y,0,-1,0)*(val(h,0,-1,0) > dry) +
        ( (val(fm.x,1,0,0))*(val(fm.x,1,0,0)))/(val(cm,1,0,0) + val(cm,0,0,0))*val(u.y,1,0,0)*(val(h,1,0,0) > dry) +
        ( (val(fm.x,-1,0,0))*(val(fm.x,-1,0,0)))/(val(cm,-1,0,0) + val(cm,0,0,0))*val(u.y,-1,0,0)*(val(h,-1,0,0) > dry))
 /(( Delta*Delta)*val(cm,0,0,0));}}      

}
  }
}

}else if(is_constant(fm.x) && !is_constant(cm)){_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);      

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./ocean.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
 

{
 {;;_stencil_val(cm,1,0,0); _stencil_val(cm,0,0,0);_stencil_val(u.x,1,0,0);_stencil_val(h,1,0,0);
;;_stencil_val(cm,-1,0,0); _stencil_val(cm,0,0,0);_stencil_val(u.x,-1,0,0);_stencil_val(h,-1,0,0);
;;_stencil_val(cm,0,1,0); _stencil_val(cm,0,0,0);_stencil_val(u.x,0,1,0);_stencil_val(h,0,1,0);
;;_stencil_val(cm,0,-1,0); _stencil_val(cm,0,0,0);_stencil_val(u.x,0,-1,0);_stencil_val(h,0,-1,0);
_stencil_val(cm,0,0,0);

_stencil_val_a(d2u.x,0,0,0);        
             
             
           
  } 

{;;_stencil_val(cm,0,1,0); _stencil_val(cm,0,0,0);_stencil_val(u.y,0,1,0);_stencil_val(h,0,1,0);
;;_stencil_val(cm,0,-1,0); _stencil_val(cm,0,0,0);_stencil_val(u.y,0,-1,0);_stencil_val(h,0,-1,0);
;;_stencil_val(cm,1,0,0); _stencil_val(cm,0,0,0);_stencil_val(u.y,1,0,0);_stencil_val(h,1,0,0);
;;_stencil_val(cm,-1,0,0); _stencil_val(cm,0,0,0);_stencil_val(u.y,-1,0,0);_stencil_val(h,-1,0,0);
_stencil_val(cm,0,0,0);

_stencil_val_a(d2u.y,0,0,0);        
             
             
           
  }}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)
 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
 val(d2u.x,0,0,0) = 2.*(( (_const_fm.x)*(_const_fm.x))/(val(cm,1,0,0) + val(cm,0,0,0))*val(u.x,1,0,0)*(val(h,1,0,0) > dry) +
        ( (_const_fm.x)*(_const_fm.x))/(val(cm,-1,0,0) + val(cm,0,0,0))*val(u.x,-1,0,0)*(val(h,-1,0,0) > dry) +
        ( (_const_fm.y)*(_const_fm.y))/(val(cm,0,1,0) + val(cm,0,0,0))*val(u.x,0,1,0)*(val(h,0,1,0) > dry) +
        ( (_const_fm.y)*(_const_fm.y))/(val(cm,0,-1,0) + val(cm,0,0,0))*val(u.x,0,-1,0)*(val(h,0,-1,0) > dry))
 /(( Delta*Delta)*val(cm,0,0,0)); 

val(d2u.y,0,0,0) = 2.*(( (_const_fm.y)*(_const_fm.y))/(val(cm,0,1,0) + val(cm,0,0,0))*val(u.y,0,1,0)*(val(h,0,1,0) > dry) +
        ( (_const_fm.y)*(_const_fm.y))/(val(cm,0,-1,0) + val(cm,0,0,0))*val(u.y,0,-1,0)*(val(h,0,-1,0) > dry) +
        ( (_const_fm.x)*(_const_fm.x))/(val(cm,1,0,0) + val(cm,0,0,0))*val(u.y,1,0,0)*(val(h,1,0,0) > dry) +
        ( (_const_fm.x)*(_const_fm.x))/(val(cm,-1,0,0) + val(cm,0,0,0))*val(u.y,-1,0,0)*(val(h,-1,0,0) > dry))
 /(( Delta*Delta)*val(cm,0,0,0));}}      

}
  }
}

}else if(!is_constant(fm.x) && is_constant(cm)){double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);      

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./ocean.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
 

{
 {_stencil_val(fm.x,1,0,0);_stencil_val(fm.x,1,0,0);;;_stencil_val(u.x,1,0,0);_stencil_val(h,1,0,0);
_stencil_val(fm.x,0,0,0);_stencil_val(fm.x,0,0,0);;;_stencil_val(u.x,-1,0,0);_stencil_val(h,-1,0,0);
_stencil_val(fm.y,0,1,0);_stencil_val(fm.y,0,1,0);;;_stencil_val(u.x,0,1,0);_stencil_val(h,0,1,0);
_stencil_val(fm.y,0,-1,0);_stencil_val(fm.y,0,-1,0);;;_stencil_val(u.x,0,-1,0);_stencil_val(h,0,-1,0);
;

_stencil_val_a(d2u.x,0,0,0);        
             
             
           
  } 

{_stencil_val(fm.y,0,1,0);_stencil_val(fm.y,0,1,0);;;_stencil_val(u.y,0,1,0);_stencil_val(h,0,1,0);
_stencil_val(fm.y,0,0,0);_stencil_val(fm.y,0,0,0);;;_stencil_val(u.y,0,-1,0);_stencil_val(h,0,-1,0);
_stencil_val(fm.x,1,0,0);_stencil_val(fm.x,1,0,0);;;_stencil_val(u.y,1,0,0);_stencil_val(h,1,0,0);
_stencil_val(fm.x,-1,0,0);_stencil_val(fm.x,-1,0,0);;;_stencil_val(u.y,-1,0,0);_stencil_val(h,-1,0,0);
;

_stencil_val_a(d2u.y,0,0,0);        
             
             
           
  }}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)
 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
 val(d2u.x,0,0,0) = 2.*(( (val(fm.x,1,0,0))*(val(fm.x,1,0,0)))/(_const_cm + _const_cm)*val(u.x,1,0,0)*(val(h,1,0,0) > dry) +
        ( (val(fm.x,0,0,0))*(val(fm.x,0,0,0)))/(_const_cm + _const_cm)*val(u.x,-1,0,0)*(val(h,-1,0,0) > dry) +
        ( (val(fm.y,0,1,0))*(val(fm.y,0,1,0)))/(_const_cm + _const_cm)*val(u.x,0,1,0)*(val(h,0,1,0) > dry) +
        ( (val(fm.y,0,-1,0))*(val(fm.y,0,-1,0)))/(_const_cm + _const_cm)*val(u.x,0,-1,0)*(val(h,0,-1,0) > dry))
 /(( Delta*Delta)*_const_cm); 

val(d2u.y,0,0,0) = 2.*(( (val(fm.y,0,1,0))*(val(fm.y,0,1,0)))/(_const_cm + _const_cm)*val(u.y,0,1,0)*(val(h,0,1,0) > dry) +
        ( (val(fm.y,0,0,0))*(val(fm.y,0,0,0)))/(_const_cm + _const_cm)*val(u.y,0,-1,0)*(val(h,0,-1,0) > dry) +
        ( (val(fm.x,1,0,0))*(val(fm.x,1,0,0)))/(_const_cm + _const_cm)*val(u.y,1,0,0)*(val(h,1,0,0) > dry) +
        ( (val(fm.x,-1,0,0))*(val(fm.x,-1,0,0)))/(_const_cm + _const_cm)*val(u.y,-1,0,0)*(val(h,-1,0,0) > dry))
 /(( Delta*Delta)*_const_cm);}}      

}
  }
}

}else {_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);      

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./ocean.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
 

{
 {;;;;_stencil_val(u.x,1,0,0);_stencil_val(h,1,0,0);
;;;;_stencil_val(u.x,-1,0,0);_stencil_val(h,-1,0,0);
;;;;_stencil_val(u.x,0,1,0);_stencil_val(h,0,1,0);
;;;;_stencil_val(u.x,0,-1,0);_stencil_val(h,0,-1,0);
;

_stencil_val_a(d2u.x,0,0,0);        
             
             
           
  } 

{;;;;_stencil_val(u.y,0,1,0);_stencil_val(h,0,1,0);
;;;;_stencil_val(u.y,0,-1,0);_stencil_val(h,0,-1,0);
;;;;_stencil_val(u.y,1,0,0);_stencil_val(h,1,0,0);
;;;;_stencil_val(u.y,-1,0,0);_stencil_val(h,-1,0,0);
;

_stencil_val_a(d2u.y,0,0,0);        
             
             
           
  }}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)
 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
 val(d2u.x,0,0,0) = 2.*(( (_const_fm.x)*(_const_fm.x))/(_const_cm + _const_cm)*val(u.x,1,0,0)*(val(h,1,0,0) > dry) +
        ( (_const_fm.x)*(_const_fm.x))/(_const_cm + _const_cm)*val(u.x,-1,0,0)*(val(h,-1,0,0) > dry) +
        ( (_const_fm.y)*(_const_fm.y))/(_const_cm + _const_cm)*val(u.x,0,1,0)*(val(h,0,1,0) > dry) +
        ( (_const_fm.y)*(_const_fm.y))/(_const_cm + _const_cm)*val(u.x,0,-1,0)*(val(h,0,-1,0) > dry))
 /(( Delta*Delta)*_const_cm); 

val(d2u.y,0,0,0) = 2.*(( (_const_fm.y)*(_const_fm.y))/(_const_cm + _const_cm)*val(u.y,0,1,0)*(val(h,0,1,0) > dry) +
        ( (_const_fm.y)*(_const_fm.y))/(_const_cm + _const_cm)*val(u.y,0,-1,0)*(val(h,0,-1,0) > dry) +
        ( (_const_fm.x)*(_const_fm.x))/(_const_cm + _const_cm)*val(u.y,1,0,0)*(val(h,1,0,0) > dry) +
        ( (_const_fm.x)*(_const_fm.x))/(_const_cm + _const_cm)*val(u.y,-1,0,0)*(val(h,-1,0,0) > dry))
 /(( Delta*Delta)*_const_cm);}}      

}
  }
}

}
      if(!is_constant(fm.x) && !is_constant(cm)){      

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./ocean.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
 

{ {           
                
                
              
    
 _stencil_val(cm,0,0,0);

_stencil_val(h,0,-1,0); _stencil_val(cm,0,0,0);_stencil_val(cm,0,-1,0);_stencil_val(fm.y,0,-1,0);_stencil_val(fm.y,0,-1,0);

_stencil_val(h,0,1,0); _stencil_val(cm,0,0,0);_stencil_val(cm,0,1,0);_stencil_val(fm.y,0,1,0);_stencil_val(fm.y,0,1,0);

_stencil_val(h,-1,0,0); _stencil_val(cm,0,0,0);_stencil_val(cm,-1,0,0);_stencil_val(fm.x,0,0,0);_stencil_val(fm.x,0,0,0);

_stencil_val(h,1,0,0); _stencil_val(cm,0,0,0);_stencil_val(cm,1,0,0);_stencil_val(fm.x,1,0,0);_stencil_val(fm.x,1,0,0);




_stencil_val(u.x,0,0,0);_stencil_val(d2u.x,0,0,0); _stencil_val_a(u.x,0,0,0);      
      } 

{           
                
                
              
    
 _stencil_val(cm,0,0,0);

_stencil_val(h,-1,0,0); _stencil_val(cm,0,0,0);_stencil_val(cm,-1,0,0);_stencil_val(fm.x,-1,0,0);_stencil_val(fm.x,-1,0,0);

_stencil_val(h,1,0,0); _stencil_val(cm,0,0,0);_stencil_val(cm,1,0,0);_stencil_val(fm.x,1,0,0);_stencil_val(fm.x,1,0,0);

_stencil_val(h,0,-1,0); _stencil_val(cm,0,0,0);_stencil_val(cm,0,-1,0);_stencil_val(fm.y,0,0,0);_stencil_val(fm.y,0,0,0);

_stencil_val(h,0,1,0); _stencil_val(cm,0,0,0);_stencil_val(cm,0,1,0);_stencil_val(fm.y,0,1,0);_stencil_val(fm.y,0,1,0);




_stencil_val(u.y,0,0,0);_stencil_val(d2u.y,0,0,0); _stencil_val_a(u.y,0,0,0);      
      }}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)
 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{ {
 double n = 2.*(( (val(fm.x,1,0,0))*(val(fm.x,1,0,0)))/(val(cm,1,0,0) + val(cm,0,0,0))*(1. + (val(h,1,0,0) <= dry)) +
         ( (val(fm.x,0,0,0))*(val(fm.x,0,0,0)))/(val(cm,-1,0,0) + val(cm,0,0,0))*(1. + (val(h,-1,0,0) <= dry)) +
         ( (val(fm.y,0,1,0))*(val(fm.y,0,1,0)))/(val(cm,0,1,0) + val(cm,0,0,0))*(1. + (val(h,0,1,0) <= dry)) +
         ( (val(fm.y,0,-1,0))*(val(fm.y,0,-1,0)))/(val(cm,0,-1,0) + val(cm,0,0,0))*(1. + (val(h,0,-1,0) <= dry)))
   /(( Delta*Delta)*val(cm,0,0,0));
 val(u.x,0,0,0) = (val(u.x,0,0,0) + dt*nu_H*val(d2u.x,0,0,0))/(1. + dt*nu_H*n);
      } 

{
 double n = 2.*(( (val(fm.y,0,1,0))*(val(fm.y,0,1,0)))/(val(cm,0,1,0) + val(cm,0,0,0))*(1. + (val(h,0,1,0) <= dry)) +
         ( (val(fm.y,0,0,0))*(val(fm.y,0,0,0)))/(val(cm,0,-1,0) + val(cm,0,0,0))*(1. + (val(h,0,-1,0) <= dry)) +
         ( (val(fm.x,1,0,0))*(val(fm.x,1,0,0)))/(val(cm,1,0,0) + val(cm,0,0,0))*(1. + (val(h,1,0,0) <= dry)) +
         ( (val(fm.x,-1,0,0))*(val(fm.x,-1,0,0)))/(val(cm,-1,0,0) + val(cm,0,0,0))*(1. + (val(h,-1,0,0) <= dry)))
   /(( Delta*Delta)*val(cm,0,0,0));
 val(u.y,0,0,0) = (val(u.y,0,0,0) + dt*nu_H*val(d2u.y,0,0,0))/(1. + dt*nu_H*n);
      }}}      

}
  }
}

}else if(is_constant(fm.x) && !is_constant(cm)){_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);      

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./ocean.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
 

{ {           
                
                
              
    
 _stencil_val(cm,0,0,0);

_stencil_val(h,0,-1,0); _stencil_val(cm,0,0,0);_stencil_val(cm,0,-1,0);;;

_stencil_val(h,0,1,0); _stencil_val(cm,0,0,0);_stencil_val(cm,0,1,0);;;

_stencil_val(h,-1,0,0); _stencil_val(cm,0,0,0);_stencil_val(cm,-1,0,0);;;

_stencil_val(h,1,0,0); _stencil_val(cm,0,0,0);_stencil_val(cm,1,0,0);;;




_stencil_val(u.x,0,0,0);_stencil_val(d2u.x,0,0,0); _stencil_val_a(u.x,0,0,0);      
      } 

{           
                
                
              
    
 _stencil_val(cm,0,0,0);

_stencil_val(h,-1,0,0); _stencil_val(cm,0,0,0);_stencil_val(cm,-1,0,0);;;

_stencil_val(h,1,0,0); _stencil_val(cm,0,0,0);_stencil_val(cm,1,0,0);;;

_stencil_val(h,0,-1,0); _stencil_val(cm,0,0,0);_stencil_val(cm,0,-1,0);;;

_stencil_val(h,0,1,0); _stencil_val(cm,0,0,0);_stencil_val(cm,0,1,0);;;




_stencil_val(u.y,0,0,0);_stencil_val(d2u.y,0,0,0); _stencil_val_a(u.y,0,0,0);      
      }}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)
 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{ {
 double n = 2.*(( (_const_fm.x)*(_const_fm.x))/(val(cm,1,0,0) + val(cm,0,0,0))*(1. + (val(h,1,0,0) <= dry)) +
         ( (_const_fm.x)*(_const_fm.x))/(val(cm,-1,0,0) + val(cm,0,0,0))*(1. + (val(h,-1,0,0) <= dry)) +
         ( (_const_fm.y)*(_const_fm.y))/(val(cm,0,1,0) + val(cm,0,0,0))*(1. + (val(h,0,1,0) <= dry)) +
         ( (_const_fm.y)*(_const_fm.y))/(val(cm,0,-1,0) + val(cm,0,0,0))*(1. + (val(h,0,-1,0) <= dry)))
   /(( Delta*Delta)*val(cm,0,0,0));
 val(u.x,0,0,0) = (val(u.x,0,0,0) + dt*nu_H*val(d2u.x,0,0,0))/(1. + dt*nu_H*n);
      } 

{
 double n = 2.*(( (_const_fm.y)*(_const_fm.y))/(val(cm,0,1,0) + val(cm,0,0,0))*(1. + (val(h,0,1,0) <= dry)) +
         ( (_const_fm.y)*(_const_fm.y))/(val(cm,0,-1,0) + val(cm,0,0,0))*(1. + (val(h,0,-1,0) <= dry)) +
         ( (_const_fm.x)*(_const_fm.x))/(val(cm,1,0,0) + val(cm,0,0,0))*(1. + (val(h,1,0,0) <= dry)) +
         ( (_const_fm.x)*(_const_fm.x))/(val(cm,-1,0,0) + val(cm,0,0,0))*(1. + (val(h,-1,0,0) <= dry)))
   /(( Delta*Delta)*val(cm,0,0,0));
 val(u.y,0,0,0) = (val(u.y,0,0,0) + dt*nu_H*val(d2u.y,0,0,0))/(1. + dt*nu_H*n);
      }}}      

}
  }
}

}else if(!is_constant(fm.x) && is_constant(cm)){double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);      

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./ocean.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
 

{ {




;

_stencil_val(h,0,-1,0);;;_stencil_val(fm.y,0,-1,0);_stencil_val(fm.y,0,-1,0);

_stencil_val(h,0,1,0);;;_stencil_val(fm.y,0,1,0);_stencil_val(fm.y,0,1,0);

_stencil_val(h,-1,0,0);;;_stencil_val(fm.x,0,0,0);_stencil_val(fm.x,0,0,0);

_stencil_val(h,1,0,0);;;_stencil_val(fm.x,1,0,0);_stencil_val(fm.x,1,0,0);




_stencil_val(u.x,0,0,0);_stencil_val(d2u.x,0,0,0); _stencil_val_a(u.x,0,0,0);      
      } 

{




;

_stencil_val(h,-1,0,0);;;_stencil_val(fm.x,-1,0,0);_stencil_val(fm.x,-1,0,0);

_stencil_val(h,1,0,0);;;_stencil_val(fm.x,1,0,0);_stencil_val(fm.x,1,0,0);

_stencil_val(h,0,-1,0);;;_stencil_val(fm.y,0,0,0);_stencil_val(fm.y,0,0,0);

_stencil_val(h,0,1,0);;;_stencil_val(fm.y,0,1,0);_stencil_val(fm.y,0,1,0);




_stencil_val(u.y,0,0,0);_stencil_val(d2u.y,0,0,0); _stencil_val_a(u.y,0,0,0);      
      }}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)
 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{ {
 double n = 2.*(( (val(fm.x,1,0,0))*(val(fm.x,1,0,0)))/(_const_cm + _const_cm)*(1. + (val(h,1,0,0) <= dry)) +
         ( (val(fm.x,0,0,0))*(val(fm.x,0,0,0)))/(_const_cm + _const_cm)*(1. + (val(h,-1,0,0) <= dry)) +
         ( (val(fm.y,0,1,0))*(val(fm.y,0,1,0)))/(_const_cm + _const_cm)*(1. + (val(h,0,1,0) <= dry)) +
         ( (val(fm.y,0,-1,0))*(val(fm.y,0,-1,0)))/(_const_cm + _const_cm)*(1. + (val(h,0,-1,0) <= dry)))
   /(( Delta*Delta)*_const_cm);
 val(u.x,0,0,0) = (val(u.x,0,0,0) + dt*nu_H*val(d2u.x,0,0,0))/(1. + dt*nu_H*n);
      } 

{
 double n = 2.*(( (val(fm.y,0,1,0))*(val(fm.y,0,1,0)))/(_const_cm + _const_cm)*(1. + (val(h,0,1,0) <= dry)) +
         ( (val(fm.y,0,0,0))*(val(fm.y,0,0,0)))/(_const_cm + _const_cm)*(1. + (val(h,0,-1,0) <= dry)) +
         ( (val(fm.x,1,0,0))*(val(fm.x,1,0,0)))/(_const_cm + _const_cm)*(1. + (val(h,1,0,0) <= dry)) +
         ( (val(fm.x,-1,0,0))*(val(fm.x,-1,0,0)))/(_const_cm + _const_cm)*(1. + (val(h,-1,0,0) <= dry)))
   /(( Delta*Delta)*_const_cm);
 val(u.y,0,0,0) = (val(u.y,0,0,0) + dt*nu_H*val(d2u.y,0,0,0))/(1. + dt*nu_H*n);
      }}}      

}
  }
}

}else {_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);      

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./ocean.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
 

{ {




;

_stencil_val(h,0,-1,0);;;;;

_stencil_val(h,0,1,0);;;;;

_stencil_val(h,-1,0,0);;;;;

_stencil_val(h,1,0,0);;;;;




_stencil_val(u.x,0,0,0);_stencil_val(d2u.x,0,0,0); _stencil_val_a(u.x,0,0,0);      
      } 

{




;

_stencil_val(h,-1,0,0);;;;;

_stencil_val(h,1,0,0);;;;;

_stencil_val(h,0,-1,0);;;;;

_stencil_val(h,0,1,0);;;;;




_stencil_val(u.y,0,0,0);_stencil_val(d2u.y,0,0,0); _stencil_val_a(u.y,0,0,0);      
      }}    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)
 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{ {
 double n = 2.*(( (_const_fm.x)*(_const_fm.x))/(_const_cm + _const_cm)*(1. + (val(h,1,0,0) <= dry)) +
         ( (_const_fm.x)*(_const_fm.x))/(_const_cm + _const_cm)*(1. + (val(h,-1,0,0) <= dry)) +
         ( (_const_fm.y)*(_const_fm.y))/(_const_cm + _const_cm)*(1. + (val(h,0,1,0) <= dry)) +
         ( (_const_fm.y)*(_const_fm.y))/(_const_cm + _const_cm)*(1. + (val(h,0,-1,0) <= dry)))
   /(( Delta*Delta)*_const_cm);
 val(u.x,0,0,0) = (val(u.x,0,0,0) + dt*nu_H*val(d2u.x,0,0,0))/(1. + dt*nu_H*n);
      } 

{
 double n = 2.*(( (_const_fm.y)*(_const_fm.y))/(_const_cm + _const_cm)*(1. + (val(h,0,1,0) <= dry)) +
         ( (_const_fm.y)*(_const_fm.y))/(_const_cm + _const_cm)*(1. + (val(h,0,-1,0) <= dry)) +
         ( (_const_fm.x)*(_const_fm.x))/(_const_cm + _const_cm)*(1. + (val(h,1,0,0) <= dry)) +
         ( (_const_fm.x)*(_const_fm.x))/(_const_cm + _const_cm)*(1. + (val(h,-1,0,0) <= dry)))
   /(( Delta*Delta)*_const_cm);
 val(u.y,0,0,0) = (val(u.y,0,0,0) + dt*nu_H*val(d2u.y,0,0,0))/(1. + dt*nu_H*n);
      }}}      

}
  }
}

}
    }  

_layer = 0;delete((scalar*)((vector[]){d2u,{{-1},{-1}}}));
  

}
}{end_tracing("viscous_term_2","./ocean.h",0);return 0;}end_tracing("viscous_term_2","./ocean.h",0);}






static int outputs_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(t += day)!=0;*ip=i;*tp=t;return ret;}      static int outputs(const int i,const double t,Event *_ev){tracing("outputs","./ocean.h",0);
{
  double ke = 0., keb = 0., vol = 0., volb = 0.;
  scalar  etad=new_scalar("etad"),  m=new_scalar("m"),  nu=new_scalar("nu");

  if(!is_constant(cm)){  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./ocean.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{
    point.l = 0;
_stencil_val(cm,0,0,0);_stencil_val(h,0,0,0);_stencil_val(u.x,0,0,0);_stencil_val(u.x,0,0,0);_stencil_val(u.y,0,0,0);_stencil_val(u.y,0,0,0); 
          _stencil_val(cm,0,0,0);_stencil_val(h,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{
_stencil_val(cm,0,0,0);_stencil_val(h,0,0,0);_stencil_val(u.x,0,0,0);_stencil_val(u.x,0,0,0);_stencil_val(u.y,0,0,0);_stencil_val(u.y,0,0,0); 
            _stencil_val(cm,0,0,0);_stencil_val(h,0,0,0);    
}  

point.l = 0;
    

point.l = nl - 1; 
_stencil_val(h,0,0,0); _stencil_val(eta,0,0,0);    _stencil_val_a(etad,0,0,0); 
_stencil_val(h,0,0,0);_stencil_val(u.x,0,0,0);_stencil_val(u.x,0,0,0);_stencil_val(u.y,0,0,0);_stencil_val(u.y,0,0,0);    _stencil_val_a(nu,0,0,0); 
_stencil_val(etad,0,0,0); _stencil_val(zbs,0,0,0);    _stencil_val_a(m,0,0,0);  
  }    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

mpi_sum_reduce_init(mpi_volb,&volb,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_keb,&keb,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_vol,&vol,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_ke,&ke,MPI_DOUBLE,MPI_SUM,1); 

{
  OMP_PARALLEL (reduction(+:ke) reduction(+:vol) reduction(+:keb) reduction(+:volb)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    point.l = 0;
    keb += (( Delta*Delta)*val(cm,0,0,0))*val(h,0,0,0)*(( (val(u.x,0,0,0))*(val(u.x,0,0,0))) + ( (val(u.y,0,0,0))*(val(u.y,0,0,0))));
    volb += (( Delta*Delta)*val(cm,0,0,0))*val(h,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{
      ke += (( Delta*Delta)*val(cm,0,0,0))*val(h,0,0,0)*(( (val(u.x,0,0,0))*(val(u.x,0,0,0))) + ( (val(u.y,0,0,0))*(val(u.y,0,0,0))));
      vol += (( Delta*Delta)*val(cm,0,0,0))*val(h,0,0,0);
    }  

point.l = 0;
    

point.l = nl - 1;
    val(etad,0,0,0) = val(h,0,0,0) > dry ? val(eta,0,0,0) : 0.;
    val(nu,0,0,0) = val(h,0,0,0) > dry ? (sqrt(( (val(u.x,0,0,0))*(val(u.x,0,0,0))) + ( (val(u.y,0,0,0))*(val(u.y,0,0,0))))) : 0.;
    val(m,0,0,0) = val(etad,0,0,0) - val(zbs,0,0,0);
  }}      

}
  }
}

{mpi_sum_reduce_array(mpi_volb,&volb,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_keb,&keb,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_vol,&vol,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_ke,&ke,MPI_DOUBLE,MPI_SUM,1);}}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./ocean.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{
    point.l = 0;
;_stencil_val(h,0,0,0);_stencil_val(u.x,0,0,0);_stencil_val(u.x,0,0,0);_stencil_val(u.y,0,0,0);_stencil_val(u.y,0,0,0);
;_stencil_val(h,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{
;_stencil_val(h,0,0,0);_stencil_val(u.x,0,0,0);_stencil_val(u.x,0,0,0);_stencil_val(u.y,0,0,0);_stencil_val(u.y,0,0,0);
;_stencil_val(h,0,0,0);    
}  

point.l = 0;
    

point.l = nl - 1; 
_stencil_val(h,0,0,0); _stencil_val(eta,0,0,0);    _stencil_val_a(etad,0,0,0); 
_stencil_val(h,0,0,0);_stencil_val(u.x,0,0,0);_stencil_val(u.x,0,0,0);_stencil_val(u.y,0,0,0);_stencil_val(u.y,0,0,0);    _stencil_val_a(nu,0,0,0); 
_stencil_val(etad,0,0,0); _stencil_val(zbs,0,0,0);    _stencil_val_a(m,0,0,0);  
  }    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

mpi_sum_reduce_init(mpi_volb,&volb,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_keb,&keb,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_vol,&vol,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_ke,&ke,MPI_DOUBLE,MPI_SUM,1); 

{
  OMP_PARALLEL (reduction(+:ke) reduction(+:vol) reduction(+:keb) reduction(+:volb)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    point.l = 0;
    keb += (( Delta*Delta)*_const_cm)*val(h,0,0,0)*(( (val(u.x,0,0,0))*(val(u.x,0,0,0))) + ( (val(u.y,0,0,0))*(val(u.y,0,0,0))));
    volb += (( Delta*Delta)*_const_cm)*val(h,0,0,0);    

for (point.l = 0; point.l < nl; point.l++) 

{
      ke += (( Delta*Delta)*_const_cm)*val(h,0,0,0)*(( (val(u.x,0,0,0))*(val(u.x,0,0,0))) + ( (val(u.y,0,0,0))*(val(u.y,0,0,0))));
      vol += (( Delta*Delta)*_const_cm)*val(h,0,0,0);
    }  

point.l = 0;
    

point.l = nl - 1;
    val(etad,0,0,0) = val(h,0,0,0) > dry ? val(eta,0,0,0) : 0.;
    val(nu,0,0,0) = val(h,0,0,0) > dry ? (sqrt(( (val(u.x,0,0,0))*(val(u.x,0,0,0))) + ( (val(u.y,0,0,0))*(val(u.y,0,0,0))))) : 0.;
    val(m,0,0,0) = val(etad,0,0,0) - val(zbs,0,0,0);
  }}      

}
  }
}

{mpi_sum_reduce_array(mpi_volb,&volb,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_keb,&keb,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_vol,&vol,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_ke,&ke,MPI_DOUBLE,MPI_SUM,1);}}




  if (i == 0) {
    fprintf (ferr, "t ke/vol keb/vol dt "
      "mgH.i mgH.nrelax etad.stddev nu.stddev");
    for (int l = 0; l < nl; l++)
      fprintf (ferr, " d%s%d.sum/dt", _attribute[h.i].name, l);
    fputc ('\n', ferr);
  }
  else
    fprintf (ferr, "%g %g %g %g %d %d %g %g", t/day, ke/vol/2., keb/volb/2., dt,
      mgH.i, mgH.nrelax,
      statsf (etad).stddev, statsf(nu).stddev);





  static double s0[5] = {0}, t0 = 0.;  

for (_layer = 0; _layer < nl; _layer++) 

{
    double s = statsf(h).sum;
    if (t0 == 0.)
      fprintf (ferr, " 0");
    else
      fprintf (ferr, " %g", (s - s0[_layer])/(t - t0));
    s0[_layer] = s;
  }  

_layer = 0;
  

fputc ('\n', ferr);
  t0 = t;






  output_ppm (etad

, 
fout

, ( N < 1024 ? 1024 : N > 2048 ? 2048 : N), "eta.mp4"
, -0.8, 0.6

, 5, 
0, 
false

,

(   coord[2]) 

{{X0, ( Y0 > (- maxlat) ? Y0 : (- maxlat))}, {X0 + L0, ( (Y0 + L0/dimensions( 

0, 0, 0

).x) < maxlat ? (Y0 + L0/dimensions( 

0, 0, 0

).x) : maxlat)}}

, m
, jet

, 
NULL, 
0, 
NULL

);
  output_ppm (nu

, 
fout

, ( N < 1024 ? 1024 : N > 2048 ? 2048 : N), "nu.mp4"
, 0, 1.5

, 5, 
0, 
false

,

(   coord[2]) 

{{X0, ( Y0 > (- maxlat) ? Y0 : (- maxlat))}, {X0 + L0, ( (Y0 + L0/dimensions( 

0, 0, 0

).x) < maxlat ? (Y0 + L0/dimensions( 

0, 0, 0

).x) : maxlat)}}

, m
, cool_warm

, 
NULL, 
0, 
NULL

);

  char name[80];
  sprintf (name, "u%d", nl - 1);
  vector utop = lookup_vector (name);
  if (utop.x.i >= 0) {
    vorticity (utop, nu);
    output_ppm (nu

, 
fout

, ( N < 1024 ? 1024 : N > 2048 ? 2048 : N), "omega.mp4"


, -0.5e-4, 0.5e-4

, 5, 
0

, false

,

(   coord[2]) 

{{X0, ( Y0 > (- maxlat) ? Y0 : (- maxlat))}, {X0 + L0, ( (Y0 + L0/dimensions( 

0, 0, 0

).x) < maxlat ? (Y0 + L0/dimensions( 

0, 0, 0

).x) : maxlat)}}

, m


, blue_white_red

, 
NULL, 
0, 
NULL

);
  }delete((scalar*)((scalar[]){nu,m,etad,{-1}}));
}{end_tracing("outputs","./ocean.h",0);return 0;}end_tracing("outputs","./ocean.h",0);}

Flux fluxes[] = {
  { "florida", {{- 80.25, 27.}, {- 78.75, 27.}},
    "Florida Straits at 27N" },
  { "abaco", {{- 77.2, 26.5}, {- 74.13, 26.5}},
    "East of Abaco Island at 26.5N" },
  { "hatteras", {{- 76.15, 34.25}, {- 74.5, 34.25}},
    "Gulf Stream at Cape Hatteras" },
  { "38N", {{- 74.2, 38}, {- 72.8, 38}},
    "Western boundary current at 38N" },
  { "NACwest", {{- 52.5, 44}, {- 53.9, 43}},
    "N. Atlantic Current, west of Grand Banks" },
  { "NACeast", {{- 49, 44}, {- 46, 44}},
    "N. Atlantic Current, east of Grand Banks at 44N" },
  { "south", {{- 50, 42.8}, {- 50, 36}},
    "S. of Grand Banks to 36N" },
  { "68W", {{- 68, 38.34}, {- 68, 33.48}},
    "Gulf Stream at 68W" },
  {NULL}
};

static int fluxes1_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(t += day)!=0;*ip=i;*tp=t;return ret;}      static int fluxes1(const int i,const double t,Event *_ev){tracing("fluxes1","./ocean.h",0);
{output_fluxes (fluxes, h, u);  }{end_tracing("fluxes1","./ocean.h",0);return 0;}end_tracing("fluxes1","./ocean.h",0);}







static int snapshots_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(t += month)!=0;*ip=i;*tp=t;return ret;}      static int snapshots(const int i,const double t,Event *_ev){tracing("snapshots","./ocean.h",0);
{
  scalar  omega=new_scalar("omega");
  char name[80];
  sprintf (name, "u%d", nl - 1);
  vector utop = lookup_vector (name);
  if (utop.x.i >= 0)
    vorticity (utop, omega);
  else
    reset (((scalar[]){omega,{-1}}), 0);
  dump ( 

"dump", 
all, 
NULL, 
false

, false);delete((scalar*)((scalar[]){omega,{-1}}));
}{end_tracing("snapshots","./ocean.h",0);return 0;}end_tracing("snapshots","./ocean.h",0);}







static int init_3_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i = 0)!=0;*ip=i;*tp=t;return ret;}      static int init_3(const int i,const double t,Event *_ev){tracing("init_3","./ocean.h",0);
{
  ua = new_block_vector("ua",nl);
  ud = new_block_vector("ud",nl);
  Ha = new_block_scalar("Ha","",nl);
}{end_tracing("init_3","./ocean.h",0);return 0;}end_tracing("init_3","./ocean.h",0);}

static int average_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=( i++)!=0;*ip=i;*tp=t;return ret;}static int average_expr1(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=( t <= 60.*year)!=0;*ip=i;*tp=t;return ret;}static int average_expr2(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(t = tspinup)!=0;*ip=i;*tp=t;return ret;}      static int average(const int i,const double t,Event *_ev){tracing("average","./ocean.h",0);
{
  double Dt = t - tspinup;  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./ocean.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{    

for (point.l = 0; point.l < nl; point.l++) 

{
_stencil_val(Ha,0,0,0);_stencil_val(h,0,0,0);      _stencil_val_a(Ha,0,0,0);      
       {
_stencil_val(ua.x,0,0,0);_stencil_val(u.x,0,0,0);        _stencil_val_a(ua.x,0,0,0);
_stencil_val(ud.x,0,0,0);_stencil_val(u.x,0,0,0);_stencil_val(u.x,0,0,0); _stencil_val_a(ud.x,0,0,0);       
      } 

{
_stencil_val(ua.y,0,0,0);_stencil_val(u.y,0,0,0);        _stencil_val_a(ua.y,0,0,0);
_stencil_val(ud.y,0,0,0);_stencil_val(u.y,0,0,0);_stencil_val(u.y,0,0,0); _stencil_val_a(ud.y,0,0,0);       
      }
    }  

point.l = 0;  

     

_stencil_geostrophic_velocity (point);
     {
_stencil_val(uga.x,0,0,0);      _stencil_val_a(uga.x,0,0,0);
_stencil_val(ugd.x,0,0,0);      _stencil_val_a(ugd.x,0,0,0);       
    } 

{
_stencil_val(uga.y,0,0,0);      _stencil_val_a(uga.y,0,0,0);
_stencil_val(ugd.y,0,0,0);      _stencil_val_a(ugd.y,0,0,0);       
    }

_stencil_val(etam,0,0,0);_stencil_val(eta,0,0,0);    _stencil_val_a(etam,0,0,0);
_stencil_val(eta2,0,0,0);_stencil_val(eta,0,0,0);_stencil_val(eta,0,0,0);    _stencil_val_a(eta2,0,0,0);       
  }    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{    

for (point.l = 0; point.l < nl; point.l++) 

{
      val(Ha,0,0,0) = (Dt*val(Ha,0,0,0) + dt*val(h,0,0,0))/(Dt + dt);
       {
        val(ua.x,0,0,0) = (Dt*val(ua.x,0,0,0) + dt*val(u.x,0,0,0))/(Dt + dt);
 val(ud.x,0,0,0) = (Dt*val(ud.x,0,0,0) + dt*( (val(u.x,0,0,0))*(val(u.x,0,0,0))))/(Dt + dt);
      } 

{
        val(ua.y,0,0,0) = (Dt*val(ua.y,0,0,0) + dt*val(u.y,0,0,0))/(Dt + dt);
 val(ud.y,0,0,0) = (Dt*val(ud.y,0,0,0) + dt*( (val(u.y,0,0,0))*(val(u.y,0,0,0))))/(Dt + dt);
      }
    }  

point.l = 0;

    

coord ug = geostrophic_velocity (point);
     {
      val(uga.x,0,0,0) = (Dt*val(uga.x,0,0,0) + dt*ug.x)/(Dt + dt);
      val(ugd.x,0,0,0) = (Dt*val(ugd.x,0,0,0) + dt*( (ug.x)*(ug.x)))/(Dt + dt);
    } 

{
      val(uga.y,0,0,0) = (Dt*val(uga.y,0,0,0) + dt*ug.y)/(Dt + dt);
      val(ugd.y,0,0,0) = (Dt*val(ugd.y,0,0,0) + dt*( (ug.y)*(ug.y)))/(Dt + dt);
    }

    val(etam,0,0,0) = (Dt*val(etam,0,0,0) + dt*val(eta,0,0,0))/(Dt + dt);
    val(eta2,0,0,0) = (Dt*val(eta2,0,0,0) + dt*( (val(eta,0,0,0))*(val(eta,0,0,0))))/(Dt + dt);
  }}      

}
  }
}


}{end_tracing("average","./ocean.h",0);return 0;}end_tracing("average","./ocean.h",0);}




static int average_outputs_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=( t += 30*day)!=0;*ip=i;*tp=t;return ret;}static int average_outputs_expr1(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(t = tspinup)!=0;*ip=i;*tp=t;return ret;}      static int average_outputs(const int i,const double t,Event *_ev){tracing("average_outputs","./ocean.h",0);
{
  scalar  etad=new_scalar("etad"),  m=new_scalar("m");  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./ocean.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{
    point.l = nl - 1; 
_stencil_val(eta2,0,0,0);_stencil_val(etam,0,0,0);_stencil_val(etam,0,0,0);_stencil_val(eta2,0,0,0);_stencil_val(etam,0,0,0);_stencil_val(etam,0,0,0);    _stencil_val_a(etad,0,0,0);
_stencil_val(h,0,0,0); _stencil_val(eta,0,0,0); _stencil_val(zbs,0,0,0);    _stencil_val_a(m,0,0,0);        
  }    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
    point.l = nl - 1;
    val(etad,0,0,0) = val(eta2,0,0,0) - ( (val(etam,0,0,0))*(val(etam,0,0,0))) > 0. ? sqrt(val(eta2,0,0,0) - ( (val(etam,0,0,0))*(val(etam,0,0,0)))) : 0.;
    val(m,0,0,0) = (val(h,0,0,0) > dry ? val(eta,0,0,0) : 0.) - val(zbs,0,0,0);
  }}      

}
  }
}
  

output_ppm (etad

, 
fout

, ( N < 1024 ? 1024 : N > 2048 ? 2048 : N), "etad.mp4"

, 0, 0.4

, 5, 
0

, false
,

(   coord[2]) 

{{X0, ( Y0 > (- maxlat) ? Y0 : (- maxlat))}, {X0 + L0, ( (Y0 + L0/dimensions( 

0, 0, 0

).x) < maxlat ? (Y0 + L0/dimensions( 

0, 0, 0

).x) : maxlat)}}

, m

, jet

, 
NULL, 
0, 
NULL

);
  output_ppm (etam

, 
fout

, ( N < 1024 ? 1024 : N > 2048 ? 2048 : N), "etam.mp4"

, -0.6, 0.6

, 5, 
0

, false
,

(   coord[2]) 

{{X0, ( Y0 > (- maxlat) ? Y0 : (- maxlat))}, {X0 + L0, ( (Y0 + L0/dimensions( 

0, 0, 0

).x) < maxlat ? (Y0 + L0/dimensions( 

0, 0, 0

).x) : maxlat)}}

, m

, jet

, 
NULL, 
0, 
NULL

);delete((scalar*)((scalar[]){m,etad,{-1}}));
}{end_tracing("average_outputs","./ocean.h",0);return 0;}end_tracing("average_outputs","./ocean.h",0);}


double * dh = (double [5]){ 0., 250, 250, 250, 250 };
double * drho = (double [5]){ 2.13/1000., 1.72/1000., 1.41/1000., 1.01/1000., 0. };

double * hmin = (double [5]){ 40, 40, 40, 40, 50 };
double * hmax = (double [5]){ 1e30f, 1e30f, 1e30f, 1e30f, 1e30f };
double omr = 0.07e-2, Cm = 0.;

static int viscous_term_3_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}




      static int viscous_term_3(const int i,const double t,Event *_ev){tracing("viscous_term_3","./bflux.h",0);
{

  static const double AMOC = 1e6;
  static const double southern[] = {
    - 13e6,
    0.,
    2e6*0.9,
    4.5e6*0.9,
    6.5e6*0.9
  };
  static const double northern[] = {
    + AMOC - southern[0],
    - AMOC/3. - southern[1],
    - AMOC/3. - southern[2],
    - AMOC/3. - southern[3],
    - southern[4]
  };
  if (!(nl == 5)) qassert ("./bflux.h", 0, "nl == 5");





  double sht[nl], shb[nl];  

for (_layer = 0; _layer < nl; _layer++) 

{
    double t = 0., b = 0.;
    if(!is_constant(cm)){
  
    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./bflux.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{ 
_stencil_val(zbs,0,0,0);_stencil_val(h,0,0,0);_stencil_val(cm,0,0,0); 
                          _stencil_val(zbs,0,0,0);_stencil_val(h,0,0,0);_stencil_val(cm,0,0,0);    
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

mpi_sum_reduce_init(mpi_b,&b,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_t,&t,MPI_DOUBLE,MPI_SUM,1); 

{
  OMP_PARALLEL (reduction(+:t) reduction(+:b)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
      t += (x > -50 && x < - 40 && y > 50.5 && val(zbs,0,0,0) < -4000)*fmax(val(h,0,0,0) - hmin[_layer]/10., 0.)*(( Delta*Delta)*val(cm,0,0,0));
      b += (x > -60 && x < - 50 && y < 9.5 && val(zbs,0,0,0) < - 4000)*fmax(val(h,0,0,0) - hmin[_layer]/10., 0.)*(( Delta*Delta)*val(cm,0,0,0));
    }}
      

}
  }
}

{mpi_sum_reduce_array(mpi_b,&b,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_t,&t,MPI_DOUBLE,MPI_SUM,1);}}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
  
    

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./bflux.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 

{ 
_stencil_val(zbs,0,0,0);_stencil_val(h,0,0,0);; 
                          _stencil_val(zbs,0,0,0);_stencil_val(h,0,0,0);;    
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

mpi_sum_reduce_init(mpi_b,&b,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_t,&t,MPI_DOUBLE,MPI_SUM,1); 

{
  OMP_PARALLEL (reduction(+:t) reduction(+:b)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++) 

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
      t += (x > -50 && x < - 40 && y > 50.5 && val(zbs,0,0,0) < -4000)*fmax(val(h,0,0,0) - hmin[_layer]/10., 0.)*(( Delta*Delta)*_const_cm);
      b += (x > -60 && x < - 50 && y < 9.5 && val(zbs,0,0,0) < - 4000)*fmax(val(h,0,0,0) - hmin[_layer]/10., 0.)*(( Delta*Delta)*_const_cm);
    }}
      

}
  }
}

{mpi_sum_reduce_array(mpi_b,&b,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_t,&t,MPI_DOUBLE,MPI_SUM,1);}}
    if (!(t > 0. && b > 0.)) qassert ("./bflux.h", 0, "t > 0. && b > 0.");
    sht[_layer] = northern[_layer]/t, shb[_layer] = southern[_layer]/b;
  }  

_layer = 0;
  

  

{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "./bflux.h", .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);     

{
  for (point.l = 0; point.l < nl; point.l++) 

{





_stencil_val(h,0,0,0); {  
  _stencil_val(h,0,0,0); 
_stencil_val(zbs,0,0,0);
   {_stencil_val(h,0,0,0);    } 
_stencil_val(zbs,0,0,0);
   {_stencil_val(h,0,0,0);    } 
_stencil_val_a(h,0,0,0);   
      }    
}  

point.l = 0;
}

    

check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 

{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k < point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j < point.n.y + 2; point.j++)     

{  

double Delta = L0*(1./((1 << point.level)*Dimensions_scale));
  double Delta_x = Delta;

  double Delta_y = Delta;





  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);

  double y = ((jg + 1)/2. + (point.j - 2))*Delta + Y0;



  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);

  NOT_UNUSED(Delta_y);





  ;  

x = x < -180. ? x + 360. : x > 180. ? x - 360. : x;
  Delta_x = Delta_y = Delta;
  Delta *= Radius*3.14159265358979/180.;
  

int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;

{
  for (point.l = 0; point.l < nl; point.l++) 

{





      if (val(h,0,0,0) > hmin[point.l]/10.) {
 double hn = val(h,0,0,0);
 if ((x > -50 && x < - 40 && y > 50.5 && val(zbs,0,0,0) < -4000))
   hn += dt*(val(h,0,0,0) - hmin[point.l]/10.)*sht[point.l];
 if ((x > -60 && x < - 50 && y < 9.5 && val(zbs,0,0,0) < - 4000))
   hn += dt*(val(h,0,0,0) - hmin[point.l]/10.)*shb[point.l];
 val(h,0,0,0) = fmax(hn, 0.);
      }
    }  

point.l = 0;
}}
      

}
  }
}

}{end_tracing("viscous_term_3","./bflux.h",0);return 0;}end_tracing("viscous_term_3","./bflux.h",0);}


int main (int argc, char * argv[])
{

_init_solver();  

dimensions (2, 1

, 0

);





  size (84);




  Radius = 6371220;




  origin (-98, 9

, 0.

);




  G = 9.8;





  if (argc > 1)
    N = atoi(argv[1]);
  else
    N = 512;






  DT = 600;
  if (argc > 2)
    DT = atof(argv[2]);




  if (argc > 3)
    tspinup = atof(argv[3]);




  nl = 5;

  theta_H = 0.55;

  run();
free_solver();}


static void _init_solver (void)
{
  void init_solver();
datasize=12*sizeof(real);  init_solver();
  {

multigrid_methods();

    

    

{
      
      
    
      {  

event_register((Event){0,1,metric,{metric_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/spherical.h",0,"metric"});  

event_register((Event){0,1,defaults0,{defaults0_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/hydro.h",0,"defaults0"});  

event_register((Event){0,1,defaults,{defaults_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/run.h",0,"defaults"});  

event_register((Event){0,1,defaults_0,{defaults_0_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/hydro.h",0,"defaults"});  

event_register((Event){0,1,init,{init_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/hydro.h",0,"init"});  

event_register((Event){0,1,defaults0_0,{defaults0_0_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/implicit.h",0,"defaults0"});  

event_register((Event){0,1,defaults_1,{defaults_1_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/implicit.h",0,"defaults"});  

event_register((Event){0,1,init_0,{init_0_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/conservation.h",0,"init"});  

event_register((Event){0,1,perfs,{perfs_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/perfs.h",0,"perfs"});  

event_register((Event){0,1,perf_plot,{perf_plot_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/perfs.h",0,"perf_plot"});  

event_register((Event){0,1,init_1,{init_1_expr0},((int *)0),((double *)0),"./ocean.h",0,"init"});  

event_register((Event){0,1,init_2,{init_2_expr0},((int *)0),((double *)0),"./ocean.h",0,"init"});  

event_register((Event){0,1,outputs,{outputs_expr0},((int *)0),((double *)0),"./ocean.h",0,"outputs"});  

event_register((Event){0,1,fluxes1,{fluxes1_expr0},((int *)0),((double *)0),"./ocean.h",0,"fluxes1"});  








event_register((Event){0,1,snapshots,{snapshots_expr0},((int *)0),((double *)0),"./ocean.h",0,"snapshots"});  

event_register((Event){0,1,init_3,{init_3_expr0},((int *)0),((double *)0),"./ocean.h",0,"init"});  






event_register((Event){0,3,average,{average_expr0,average_expr1,average_expr2},((int *)0),((double *)0),"./ocean.h",0,"average"});  

event_register((Event){0,2,average_outputs,{average_outputs_expr0,average_outputs_expr1},((int *)0),((double *)0),"./ocean.h",0,"average_outputs"});
	
	
	
      

}

init_const_vector((vector){{_NVARMAX+3},{_NVARMAX+4}},"zerof",(double[]){0.,0.,0.});
init_const_vector((vector){{_NVARMAX+5},{_NVARMAX+6}},"unityf",(double[]){1.,1.,1.});
init_const_scalar((scalar){_NVARMAX+7},"unity", 1.);
init_const_scalar((scalar){_NVARMAX+8},"zeroc", 0.);



init_const_vector((vector){{_NVARMAX+9},{_NVARMAX+10}},"fm",(double[]){1.,1.,1.});
init_const_scalar((scalar){_NVARMAX+11},"cm", 1.);  init_scalar((scalar){0},"zb");

init_const_vector((vector){{_NVARMAX+12},{_NVARMAX+13}},"lambda_b",(double[]){0,0,0});init_const_vector((vector){{_NVARMAX+14},{_NVARMAX+15}},"dut",(double[]){0,0,0});init_const_vector((vector){{_NVARMAX+16},{_NVARMAX+17}},"u_b",(double[]){0,0,0});  init_scalar((scalar){1},"zbs");  init_scalar((scalar){2},"etam");  init_scalar((scalar){3},"eta2");  init_vector((vector){{4},{5}},"uga");  init_vector((vector){{6},{7}},"ugd");  init_vector((vector){{8},{9}},"wind1");  init_vector((vector){{10},{11}},"wind2");    

}  

event_register((Event){0,1,cleanup,{cleanup_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/run.h",0,"cleanup"});  

event_register((Event){0,1,set_dtmax,{set_dtmax_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/hydro.h",0,"set_dtmax"});  

event_register((Event){0,1,face_fields,{face_fields_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/hydro.h",0,"face_fields"});  

event_register((Event){0,1,half_advection,{half_advection_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/hydro.h",0,"half_advection"});  

event_register((Event){0,1,viscous_term,{viscous_term_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/diffusion.h",0,"viscous_term"});  

event_register((Event){0,1,acceleration,{acceleration_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/hydro.h",0,"acceleration"});  

event_register((Event){0,1,pressure,{pressure_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/hydro.h",0,"pressure"});  

event_register((Event){0,1,update_eta,{update_eta_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/hydro.h",0,"update_eta"});  

event_register((Event){0,1,remap,{remap_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/hydro.h",0,"remap"});  

event_register((Event){0,1,cleanup_0,{cleanup_0_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/hydro.h",0,"cleanup"});  

event_register((Event){0,1,half_advection_0,{half_advection_0_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/implicit.h",0,"half_advection"});  








event_register((Event){0,1,acceleration_0,{acceleration_0_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/implicit.h",0,"acceleration"});  

event_register((Event){0,1,pressure_0,{pressure_0_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/implicit.h",0,"pressure"});  

event_register((Event){0,1,acceleration_1,{acceleration_1_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/coriolis.h",0,"acceleration"});  

event_register((Event){0,1,acceleration_2,{acceleration_2_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/isopycnal.h",0,"acceleration"});  

event_register((Event){0,1,viscous_term_0,{viscous_term_0_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/entrainment.h",0,"viscous_term"});  

event_register((Event){0,1,viscous_term_1,{viscous_term_1_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/conservation.h",0,"viscous_term"});  

event_register((Event){0,1,cleanup_1,{cleanup_1_expr0},((int *)0),((double *)0),"/home/jacqhugo/basilisk/src/layered/conservation.h",0,"cleanup"});  

event_register((Event){0,1,acceleration_3,{acceleration_3_expr0},((int *)0),((double *)0),"./ocean.h",0,"acceleration"});  

event_register((Event){0,1,viscous_term_2,{viscous_term_2_expr0},((int *)0),((double *)0),"./ocean.h",0,"viscous_term"});  

event_register((Event){0,1,viscous_term_3,{viscous_term_3_expr0},((int *)0),((double *)0),"./bflux.h",0,"viscous_term"});  

}
  set_fpe();
}
