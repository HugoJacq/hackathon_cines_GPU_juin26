#line 1 "turbulence-cpp.c"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/.qcc5PGbyG//"
#line 1 "<built-in>"
#line 1 "<command-line>"
#line 1 "/usr/include/stdc-predef.h"
#line 1 "<command-line>"
#line 1 "turbulence-cpp.c"
#define _GPU 1
#if 700 < 700
  #undef 700
  #define 700 700
#endif
#if _GNU_SOURCE
#include <stdint.h>
#include <string.h>
#include <fenv.h>
#endif


#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h"
typedef double number; 






number macro_min (number a, number b) { return a < b ? a : b; } 
number macro_sq (number x) { return x*x; } 
number macro_cube (number x) { return x*x*x; } 
int macro_sign (number x) { return (int)(x > 0 ? 1 : -1); } 
int macro_sign2 (number x) { return (int)(x > 0 ? 1 : x < 0 ? -1 : 0); } 
number macro_clamp (number x, number a, number b) {
  return x < a ? a : x > b ? b : x;
} 




#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/ast/std/stdlib.h"
#include <stdlib.h>
#line 2 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/ast/std/stdio.h"
#include <stdio.h>
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/ast/std/stddef.h"
#include <stddef.h>
#line 4 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/ast/std/stdint.h"
#include <stdint.h>
#line 5 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/ast/std/stdbool.h"
#include <stdbool.h>
#line 6 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/ast/std/stdarg.h"
#include <stdarg.h>
#line 7 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/ast/std/string.h"
#include <string.h>
#line 8 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/ast/std/float.h"
#include <float.h>
#line 9 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/ast/std/limits.h"
#include <limits.h>
#line 10 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/ast/std/math.h"
#include <math.h>
#line 11 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/ast/std/time.h"
#include <time.h>
#line 12 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/ast/std/sys/time.h"
#include <sys/time.h>
#line 13 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/ast/std/sys/resource.h"
#include <sys/resource.h>
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"




#define unmap(x,y)
#define trash(x)


void macro1_BEGIN_FOREACH() {;}
#line 52 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
# define OMP(x)
void macro_OMP_SERIAL() {;}
#line 69 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
#define _NVARMAX 65536
#define is_constant(v) ((v).i >= _NVARMAX)
#define constant(v) (is_constant(v) ? _constant[(v).i - _NVARMAX] : 1e30f)

#define systderr stderr
#define systdout stdout
#line 89 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
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






#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/array.h"


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
#line 129 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
#line 222 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
typedef struct {
  char * func, * file;
  int line, calls;
  double total, self;



} TraceIndex;

struct {
  Array stack, index;
  double t0;
} Trace = {
  {NULL, 0, 0}, {NULL, 0, 0},
  -1
};

static void trace_add (const char * func, const char * file, int line,
         double total, double self)
{
  TraceIndex * t = (TraceIndex *) Trace.index.p;
  int i, len = Trace.index.len/sizeof(TraceIndex);
  for (i = 0; i < len; i++, t++)
    if (t->line == line && !strcmp (func, t->func) && !strcmp (file, t->file))
      break;
  if (i == len) {
    TraceIndex t = {pstrdup(func,__func__,__FILE__,0), pstrdup(file,__func__,__FILE__,0), line, 1, total, self};
    array_append (&Trace.index, &t, sizeof(TraceIndex));
  }
  else
    t->calls++, t->total += total, t->self += self;
}

static void tracing (const char * func, const char * file, int line)
{
  struct timeval tv;
  gettimeofday (&tv, NULL);
  if (Trace.t0 < 0)
    Trace.t0 = tv.tv_sec + tv.tv_usec/1e6;
  double t[2] = {(tv.tv_sec - Trace.t0) + tv.tv_usec/1e6, 0.};
  array_append (&Trace.stack, t, 2*sizeof(double));







}

static void end_tracing (const char * func, const char * file, int line)
{
  struct timeval tv;
  gettimeofday (&tv, NULL);
  double te = (tv.tv_sec - Trace.t0) + tv.tv_usec/1e6;
  double * t = (double *) Trace.stack.p;
  if (!(Trace.stack.len >= 2*sizeof(double))) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h", 0, "Trace.stack.len >= 2*sizeof(double)");
  t += Trace.stack.len/sizeof(double) - 2;
  Trace.stack.len -= 2*sizeof(double);
  double dt = te - t[0];




  trace_add (func, file, line, dt, dt - t[1]);
  if (Trace.stack.len >= 2*sizeof(double)) {
    t -= 2;
    t[1] += dt;
  }



}

static int compar_self (const void * p1, const void * p2)
{
  const TraceIndex * t1 = p1, * t2 = p2;
  return t1->self < t2->self;
}
#line 312 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
void trace_print (FILE * fp, double threshold)
{
  int i, len = Trace.index.len/sizeof(TraceIndex);
  double total = 0.;
  TraceIndex * t;
  Array * index = array_new();
  for (i = 0, t = (TraceIndex *) Trace.index.p; i < len; i++, t++)
    array_append (index, t, sizeof(TraceIndex)), total += t->self;
#line 336 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
  qsort (index->p, len, sizeof(TraceIndex), compar_self);
  fprintf (fp, "   calls    total     self   %% total   function\n");
  for (i = 0, t = (TraceIndex *) index->p; i < len; i++, t++)
    if (t->self*100./total > threshold) {
      fprintf (fp, "%8d   %6.2f   %6.2f     %4.1f%%",
        t->calls, t->total, t->self, t->self*100./total);



      fprintf (fp, "   %s():%s:%d\n", t->func, t->file, t->line);
    }
  fflush (fp);
  array_free (index);
  for (i = 0, t = (TraceIndex *) Trace.index.p; i < len; i++, t++)
    t->calls = t->total = t->self = 0.;
}

static void trace_off()
{
  trace_print (fout, 0.);

  int i, len = Trace.index.len/sizeof(TraceIndex);
  TraceIndex * t;
  for (i = 0, t = (TraceIndex *) Trace.index.p; i < len; i++, t++)
    pfree (t->func,__func__,__FILE__,0), pfree (t->file,__func__,__FILE__,0);

  pfree (Trace.index.p,__func__,__FILE__,0);
  Trace.index.p = NULL;
  Trace.index.len = Trace.index.max = 0;

  pfree (Trace.stack.p,__func__,__FILE__,0);
  Trace.stack.p = NULL;
  Trace.stack.len = Trace.stack.max = 0;
}
#line 566 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
#define tid() 0
#define pid() 0
#define npe() 1
#define mpi_all_reduce(v,type,op)
#define mpi_all_reduce_array(v,type,op,elem)
#define mpi_sum_reduce_init(s,v,type,op,elem)
#define mpi_sum_reduce_array(s,v,type,op,elem)



void macro_OMP_PARALLEL() {;}
#define OMP_PARALLEL(...) OMP(omp parallel __VA_ARGS__)

#define NOT_UNUSED(x) (void)(x)

void macro1_VARIABLES() { ; }
#define _index(a,m) (a.i)
#define val(a,k,l,m) data(k,l,m)[_index(a,m)]

double _val_higher_dimension = 0.;
#line 594 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
#if (_GNU_SOURCE || __APPLE__) && !_OPENMP && !_CADNA
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
  if (!(sizeof (int64_t) == sizeof (double))) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h", 0, "sizeof (int64_t) == sizeof (double)");
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

#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/../ast/symbols.h"

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
#line 677 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"

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
#line 21 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h"

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
#line 97 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h"
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

#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/boundaries.h"


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
#line 47 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/boundaries.h"
typedef struct {
  Boundary parent;
  int d;
} BoxBoundary;
#line 135 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h"



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
#line 27 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
struct {
    int bc, io, width;
  } stencil;  
#line 21 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
void (* prolongation) (Point, scalar);
  void (* restriction) (Point, scalar);
  
#line 1266 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
double (* boundary_left) (Point, Point, scalar, bool *);
  double (* boundary_right) (Point, Point, scalar, bool *);
  double (* boundary_top) (Point, Point, scalar, bool *);
  double (* boundary_bottom) (Point, Point, scalar, bool *);
  
#line 1281
struct {
    int stored, index;
  } gpu;
#line 162 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h"
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
#line 271
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
      if (!(s->i >= 0)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h", 0, "s->i >= 0");
      v.x = *s++;
    } 
#line 293
{
      if (!(s->i >= 0)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h", 0, "s->i >= 0");
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
      if (!(v->x.i >= 0)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h", 0, "v->x.i >= 0");
      t.x = *v++;
    } 
#line 324
{
      if (!(v->y.i >= 0)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h", 0, "v->x.i >= 0");
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
#line 336
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
#line 361 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h"
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
#line 410 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h"
void matrix_inverse3 (double m[3][3])
{
  double det = (m[0][0]*(m[1][1]*m[2][2] - m[2][1]*m[1][2]) -
  m[0][1]*(m[1][0]*m[2][2] - m[2][0]*m[1][2]) +
  m[0][2]*(m[1][0]*m[2][1] - m[2][0]*m[1][1]));
  if (!(det)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h", 0, "det");
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
#line 572 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h"
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

#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/a32.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/ast/std/stdint.h"
#include <stdint.h>
#line 2 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/a32.h"

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
#line 589 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h"
#line 14 "turbulence-cpp.c"
#line 1 "grid/hip/multigrid.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/multigrid.h"



#line 1 "grid/hip/../gpu-multigrid.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu-multigrid.h"
#line 28 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu-multigrid.h"
static bool _gpu_done_ = false;

#line 1 "grid/hip/../multigrid.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"

typedef float real;
#line 16 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
# define BGHOSTS 1
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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







  #define _BLOCK_INDEX

};
static Point last_point;
#line 78 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
#undef val
#define val(a,k,l,m) (((real *)((Multigrid *)grid)->d)[point.j + (l) +\
       (point.i + (k))*(((size_t)(1 << point.level)*((int *)&Dimensions)[1]) + 2*2) +\
       ((Multigrid *)grid)->shift[point.level] +\
       _index(a,m)*((Multigrid *)grid)->shift[depth() + 1]])\

#line 83

#line 109 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
#define allocated(k,l,m) (point.i+(k) >= 0 && point.i+(k) < ((size_t)(1 << point.level)*((int *)&Dimensions)[0]) + 2*2 &&\
         point.j+(l) >= 0 && point.j+(l) < ((size_t)(1 << point.level)*((int *)&Dimensions)[1]) + 2*2)\

#line 111


#define allocated_child(k,l,m) (level < depth() &&\
         point.i > 0 && point.i <= ((size_t)(1 << point.level)*((int *)&Dimensions)[0]) + 2 &&\
         point.j > 0 && point.j <= ((size_t)(1 << point.level)*((int *)&Dimensions)[1]) + 2)\

#line 116

#line 137 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
#define depth() (grid->depth)
#line 161 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
#define fine(a,k,l,m)\
(((real *)((Multigrid *)grid)->d)[2*point.j - 2 + (l) +\
   (2*point.i - 2 + (k))*(((size_t)(1 << point.level)*((int *)&Dimensions)[1])*2 + 2*2) +\
   ((Multigrid *)grid)->shift[point.level + 1] +\
   _index(a,m)*((Multigrid *)grid)->shift[depth() + 1]])\

#line 166

#define coarse(a,k,l,m)\
(((real *)((Multigrid *)grid)->d)[(point.j + 2)/2 + (l) +\
   ((point.i + 2)/2 + (k))*(((size_t)(1 << point.level)*((int *)&Dimensions)[1])/2 + 2*2) +\
   ((Multigrid *)grid)->shift[point.level - 1] +\
   _index(a,m)*((Multigrid *)grid)->shift[depth() + 1]])\

#line 172


void macro_POINT_VARIABLES (Point point) { 
  
#line 581 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
;  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
}
#line 244 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
  if (!(0)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h", 0, "0");\
} while (0)\

#line 294

#define tree ((Multigrid *)grid)
#line 1 "grid/hip/../foreach_cell.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
#line 66 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
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
#line 120 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
      }
    }
  }
}

void macro_foreach_cell()
{
  {



    Point root = {2,2,0};  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 67 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
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
      
#line 136
{ 
  
#line 581 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
;  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 136 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
;} 
#line 91
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
#line 120 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
      }
    }
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
  
#line 137 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
}
}

void macro_foreach_cell_all() {
  {
    Point root = {0};
    for (root.i = 2*Period.x; root.i <= 2*(2 - Period.x); root.i++)

      for (root.j = 2*Period.y; root.j <= 2*(2 - Period.y); root.j++)
#line 13 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
{
  if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 67 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
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
     
#line 151
{ 
  
#line 581 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
;  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 151 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
;} 
#line 91
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
#line 120 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
      }
    }
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
}
  
#line 152 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
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
#line 246 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
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
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 156 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
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
#line 246 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
      default:
      
#line 265
{ 
  
#line 581 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
;  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
;}      
#line 249
}
    }
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
  
#line 266 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
}
}

void macro_foreach_cell_post_all (bool condition)
{
  {
    Point root = {0};
    for (root.i = 0; root.i <= 2*2; root.i++)

      for (root.j = 0; root.j <= 2*2; root.j++)
#line 13 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
{
  if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 156 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
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
#line 246 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
      default:
     
#line 281
{ 
  
#line 581 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
;  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 281 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
;}      
#line 249
}
    }
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
}
  
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
}
}

void macro_foreach_leaf()
{  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 126 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
{
  {



    Point root = {2,2,0};  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 67 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
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
    
#line 288
{ 
  
#line 581 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
;  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 288 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
if (is_leaf (cell)) {
      if (is_active(cell) && is_local(cell))
 ;
      continue;
    }} 
#line 91
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
#line 120 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
      }
    }
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
  
#line 137 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
}
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }

#line 293 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
}
#line 306 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
void macro_foreach_cell_restore (ivec d, int rootlevel)
{
  if (!d.x) d.x = 1;
  if (!d.y) d.y = 1;
  for (int ox = 0; ox < d.x; ox++)
    for (int oy = 0; oy < d.y; oy++) {
      Point root = {2 + ox, 2 + oy, rootlevel};  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 67 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
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
 
#line 314
{ 
  
#line 581 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
;  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 314 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
;} 
#line 91
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
#line 120 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
      }
    }
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
    
#line 315 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
}
}
#line 297 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"

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
#line 352 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
  
 
#line 581 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
;  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
 
#line 376
;
      }
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }
}
#line 430 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
#if TRASH
# undef trash
# define trash(list) reset(list, undefined)
#endif

#line 1 "grid/hip/../neighbors.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../neighbors.h"
#line 16 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../neighbors.h"
void macro_foreach_neighbor (int _s,
    Point point) {
  {
    const int _nn = _s;
    const int _i = point.i, _j = point.j;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;
      for (int _l = - _nn; _l <= _nn; _l++) {
 point.j = _j + _l; 
  
 
#line 581 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
;  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2; 
#line 26 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../neighbors.h"
;
      }
    }
    point.i = _i; point.j = _j;
  }
}
#line 436 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"

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
#line 476 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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

#line 513

#define is_boundary(point) (point.i < 2 || point.i >= point.n.x + 2 ||\
    point.j < 2 || point.j >= point.n.y + 2)\

#line 516

#line 579 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
extern double (* default_scalar_bc[]) (Point, Point, scalar, bool *);
static double periodic_bc (Point point, Point neighbor, scalar s, bool * data);

void macro_foreach_boundary (int b, Reduce reductions)
{
  if (default_scalar_bc[b] != periodic_bc)
#line 13 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
{
  if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 477 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = (
#line 585
depth()
#line 481
) < 0 ? depth() : (
#line 585
depth()
#line 481
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
      
#line 586
{  
#line 581 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
;  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 586
if (!is_boundary(point))
 ;}      
#line 507
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
}

#line 588 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
  for (int bghost = 1; bghost <= BGHOSTS; bghost++)
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
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 477 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 628
{  
#line 581 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
;  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 628
{
   scalar s, sb;
   {scalar*_i0=listb;scalar*_i1= list;if(_i0)for(sb=*_i0,s=*_i1;_i0->i>= 0;sb=*++_i0,s=*++_i1){ {
     if ((_attribute[s.i].face && sb.i == _attribute[s.i].v.x.i) || is_vertex_scalar (s)) {

       if (bghost == 1)
 
    val(s,(ig + 1)/2,(jg + 1)/2,(kg + 1)/2) =
    _attribute[sb.i].boundary[d] (point, neighborp(ig,jg,kg), s, NULL);
     }
     else

      
  val(s,bghost*ig,bghost*jg,bghost*kg) =
  _attribute[sb.i].boundary[d] (neighborp((1 - bghost)*ig,
       (1 - bghost)*jg,
       (1 - bghost)*kg),
    neighborp(bghost*ig,bghost*jg,bghost*kg),
    s, NULL);
   }}}
 }}      
#line 507
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
 
#line 649 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
pfree (list,__func__,__FILE__,0);
 pfree (listb,__func__,__FILE__,0);
      }
    }
  enable_fpe (FE_DIVBYZERO|FE_INVALID);
}
#line 704 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 244 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
      
#line 725
{  
#line 581 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
;  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 725
{scalar*_i=(scalar*)( list1);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
 for (int b = 0; b < _attribute[s.i].block; b++) {
   scalar sb = {s.i + b};
   real v = val(sb,0,0,0);   
#line 18 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../neighbors.h"
{
    const int _nn = 2;
    const int _i = point.i, _j = point.j;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;
      for (int _l = - _nn; _l <= _nn; _l++) {
 point.j = _j + _l; 
  
 
#line 581 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
;  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
     
#line 730
val(sb,0,0,0) = v;      
#line 27 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../neighbors.h"
}
    }
    point.i = _i; point.j = _j;
  }
 
#line 731 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}}}}    
#line 261
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
    
#line 732 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 776 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
  }
  pfree (list1,__func__,__FILE__,0);
}
#line 707
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
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 244 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
      
#line 725
{  
#line 581 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
;  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 725
{scalar*_i=(scalar*)( list1);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
 for (int b = 0; b < _attribute[s.i].block; b++) {
   scalar sb = {s.i + b};
   real v = val(sb,0,0,0);   
#line 18 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../neighbors.h"
{
    const int _nn = 2;
    const int _i = point.i, _j = point.j;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;
      for (int _l = - _nn; _l <= _nn; _l++) {
 point.j = _j + _l; 
  
 
#line 581 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h"
;  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
     
#line 730
val(sb,0,0,0) = v;      
#line 27 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../neighbors.h"
}
    }
    point.i = _i; point.j = _j;
  }
 
#line 731 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}}}}    
#line 261
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
    
#line 732 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 776 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 828
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
#line 867 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
Point locate (double xp, double yp, double zp)
{
  Point point = {0};
  point.level = depth();
  point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
  point.level = -1;
#line 888 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
  point.i = (xp - X0)/L0*point.n.x + 2;
  if (point.i < 2 || point.i >= point.n.x + 2)
    return point;

  point.j = (yp - Y0)/L0*point.n.x + 2;
  if (point.j < 2 || point.j >= point.n.y + 2)
    return point;







  point.level = depth();
  return point;
}


#line 1 "grid/hip/../variables.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
void macro2_VARIABLES (Point point, int _ig, int _jg, int _kg)
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
#line 908 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"




void macro_foreach_vertex (char flags, Reduce reductions) {  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 300 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 913
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 913
{
    int ig = -1; NOT_UNUSED(ig);

    int jg = -1; NOT_UNUSED(jg);




    ;
  }}      
#line 317
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }

#line 923 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
#line 936 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
ivec dimensions (int nx, int ny, int nz)
{
  if (nx != 0 || ny != 0 || nz != 0) {
    Dimensions.x = Dimensions_scale = ( nx > 1 ? nx : 1);

    Dimensions.y = ( ny > 1 ? ny : 1);




  }
  return Dimensions;
}
#line 31 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu-multigrid.h"
#line 1 "grid/hip/../stencils.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
#line 16 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
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
  const char * func;
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
#line 142
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
#line 171
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
#line 189
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
#line 223
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
#line 240
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
#line 277
if (loop->listf.y)
      flux = true;
  if (flux) {
#line 292 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
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

void macro1_foreach_stencil (char flags, Reduce reductions)
{
  {
    static int _first = 1.;
    ForeachData _loop = {
      .fname = __FILE__, .func = __func__, .line = 0, .first = _first
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

void macro1_foreach_vertex_stencil (char flags, Reduce reductions) {  
#line 330
{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h", .func = __func__, .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 
#line 352
{
    _loop.vertex = true;
    ;
  }    
#line 345
check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }







}

void macro1_foreach_face_stencil (char flags, Reduce reductions, const char * order) {  
#line 330
{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h", .func = __func__, .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    
#line 360
;    
#line 345
check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

#line 361
}

void macro1_foreach_level_stencil (int l, char flags, Reduce reductions) {
  if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    ;
  }
}

void macro1_foreach_coarse_level_stencil (int l, char flags, Reduce reductions) {  
#line 364
if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    





;  
#line 369
}





}

void macro1_foreach_level_or_leaf_stencil (int l, char flags, Reduce reductions) {  
#line 364
if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    
#line 379
;  
#line 369
}










}

void macro1_foreach_point_stencil (double xp, double yp, double zp, char flags, Reduce reductions)
{  
#line 330
{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h", .func = __func__, .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    
#line 385
;    
#line 345
check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

#line 386
}

void macro1_foreach_region_stencil (coord p, coord box[2], coord n, char flags, Reduce reductions)
{  
#line 330
{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h", .func = __func__, .line = 0, .first = _first
    };
    if (baseblock)
      for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
        _attribute[s.i].stencil.io = 0;
 _attribute[s.i].stencil.width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    
#line 391
;    
#line 345
check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

#line 392
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

#line 529

#define _stencil_val_o(a,_i,_j,_k)\
  stencil_val (point, a, _i, _j, _k, __FILE__, 0, true)\

#line 532

#define _stencil_val_a(a,_i,_j,_k)\
  stencil_val_a (point, a, _i, _j, _k, false, __FILE__, 0)\

#line 535

#define _stencil_val_r(a,_i,_j,_k)\
  stencil_val_a (point, a, _i, _j, _k, true, __FILE__, 0)\

#line 538


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
#line 32 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu-multigrid.h"
#line 1 "grid/hip/../gpu/gpu.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
char * gpu_errors (const char * errors, const char * source, char * fout,
                   const char * lang);
#line 12 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
void macro2_BEGIN_FOREACH()
{
  if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;
    ;
    ;
  }
}

typedef struct {
  coord p, * box, n;
  int level;
} RegionParameters;

bool gpu_end_stencil (ForeachData * loop, const RegionParameters * region,
        External * externals, const char * kernel);

void macro_foreach_stencil_generic (char flags, Reduce reductions,
    int _parallel, External * _externals, const char * _kernel)
{
  ;
  static ForeachData _loop = { .fname = __FILE__, .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = _parallel;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};

  ;
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, _externals, _kernel);
  _loop.first = 0;
  ;
}

void macro2_foreach_stencil (char flags, Reduce reductions,
   int _parallel, External * _externals, const char * _kernel)
{  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = _parallel;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
    
#line 74
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 74 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, _externals, _kernel);
  _loop.first = 0;
  ;
}    
#line 19
;
  }

#line 75
}

void macro2_foreach_level_stencil (int _level, char flags, Reduce reductions,
         int _parallel, External * _externals, const char * _kernel)
{  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = _parallel;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 80
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 80 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
{
    _region.level = _level + 1;
    ;
  }}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, _externals, _kernel);
  _loop.first = 0;
  ;
}    
#line 19
;
  }

#line 84
}

void macro2_foreach_point_stencil (double _xp, double _yp, double _zp,
         char flags, Reduce reductions,
         int _parallel, External * _externals, const char * _kernel)
{  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = _parallel;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 90
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 90 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
{
    _region.p = (coord){ _xp, _yp, _zp };
    _region.n = (coord){ 1, 1 };
    ;
  }}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, _externals, _kernel);
  _loop.first = 0;
  ;
}    
#line 19
;
  }

#line 95
}

void macro2_foreach_region_stencil (coord _p, coord _box[2], coord _n,
          char flags, Reduce reductions,
          int _parallel, External * _externals, const char * _kernel)
{  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = _parallel;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 101
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 101 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
{
    _region.p = _p, _region.box = _box, _region.n = _n;
    ;
  }}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, _externals, _kernel);
  _loop.first = 0;
  ;
}    
#line 19
;
  }

#line 105
}

void macro2_foreach_vertex_stencil (char flags, Reduce reductions,
      int _parallel, External * _externals,
      const char * _kernel)
{  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = _parallel;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 111
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 111 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
{
    _loop.vertex = true;
    ;
  }}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, _externals, _kernel);
  _loop.first = 0;
  ;
}    
#line 19
;
  }

#line 115
}

void macro2_foreach_face_stencil (char flags, Reduce reductions, const char * _order,
        int _parallel, External * _externals,
        const char * _kernel)
{  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = _parallel;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
    
#line 122
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 122 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, _externals, _kernel);
  _loop.first = 0;
  ;
}    
#line 19
;
  }

#line 123
}

void macro2_foreach_coarse_level_stencil (int _level, char flags, Reduce reductions,
         int _parallel, External * _externals,
         const char * _kernel)
{  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = _parallel;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 80
{
    _region.level = _level + 1;
    
#line 130
;  
#line 83
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, _externals, _kernel);
  _loop.first = 0;
  ;
}    
#line 19
;
  }

#line 131
}

void macro2_foreach_level_or_leaf_stencil (int _level, char flags, Reduce reductions,
          int _parallel, External * _externals,
          const char * _kernel)
{  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = _parallel;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 80
{
    _region.level = _level + 1;
    
#line 138
;  
#line 83
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, _externals, _kernel);
  _loop.first = 0;
  ;
}    
#line 19
;
  }

#line 139
}

void realloc_scalar_gpu (int size)
{
  realloc_scalar (size);
  void realloc_ssbo (size_t);
  realloc_ssbo ((((Multigrid *)grid)->shift[depth() + 1]));
}

void gpu_boundary_level (scalar * list, int l)
{
  scalar * list1 = NULL;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (_attribute[s.i].gpu.stored > 0)
      list1 = list_prepend (list1, s);}}
  if (list1) {
    void cartesian_boundary_level (scalar * list, int l);
    cartesian_boundary_level (list1, l);
    pfree (list1,__func__,__FILE__,0);
  }
}
#line 33 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu-multigrid.h"
#line 1 "grid/hip/../multigrid-common.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"



#line 1 "grid/hip/../cartesian-common.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
#line 1 "grid/hip/../events.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../events.h"
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
  if (!(Events)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../events.h", 0, "Events");
  if (!(!event.last)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../events.h", 0, "!event.last");
  int n = 0, parent = -1;
  for (Event * ev = Events; !ev->last; ev++) {
    if (!strcmp (event.name, ev->name)) {
      if (!(parent < 0)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../events.h", 0, "parent < 0");
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
#line 162 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../events.h"
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
    if (!(dt > 0.)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../events.h", 0, "dt > 0.");
    unsigned int n = (tnext - t)/dt;
    if (!(n < INT_MAX)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../events.h", 0, "n < INT_MAX");
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
#line 317 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../events.h"
}
#line 2 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"

void (* debug) (Point);

#define _val_constant(a,k,l,m) ((const double) _constant[a.i -_NVARMAX])
#define val_diagonal(a,k,l,m) ((k) == 0 && (l) == 0 && (m) == 0)

#line 1 "grid/hip/../fpe.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../fpe.h"


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
#line 9 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"


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
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  
#line 54 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
return 2.*expr - val(s,0,0,0);
}

static inline
double dirichlet_homogeneous (double expr, Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  
#line 60 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
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
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  
#line 78 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
return Delta*expr + val(s,0,0,0);
}

static inline
double neumann_homogeneous (double expr, Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  
#line 84 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
return val(s,0,0,0);
}




static inline
double navier (double expr, double lambda, Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  
#line 93 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
return (Delta*expr + val(s,0,0,0)*(lambda - Delta/2.))/(lambda + Delta/2.);
}

static inline
double navier_homogeneous (double expr, double lambda, Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  
#line 99 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
return val(s,0,0,0)*(lambda - Delta/2.)/(lambda + Delta/2.);
}





#line 1 "./khash.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/khash.h"
#line 128 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/khash.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/ast/std/stdlib.h"
#include <stdlib.h>
#line 129 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/khash.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/ast/std/string.h"
#include <string.h>
#line 130 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/khash.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/ast/std/stdint.h"
#include <stdint.h>
#line 131 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/khash.h"

typedef uint32_t khint32_t;
typedef uint64_t khint64_t;
#line 151 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/khash.h"
typedef khint32_t khint_t;
typedef khint_t khiter_t;
#line 181 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/khash.h"
static const double __ac_HASH_UPPER = 0.77;
#line 384 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/khash.h"
static inline khint_t __ac_X31_hash_string(const char *s)
{
 khint_t h = (khint_t)*s;
 if (h) for (++s ; *s; ++s) h = (h << 5) - h + (khint_t)*s;
 return h;
}
#line 401 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/khash.h"
static inline khint_t __ac_Wang_hash(khint_t key)
{
    key += ~(key << 15);
    key ^= (key >> 10);
    key += (key << 3);
    key ^= (key >> 6);
    key += ~(key << 11);
    key ^= (key >> 16);
    return key;
}
#line 600 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/khash.h"
typedef const char *kh_cstr_t;
#line 107 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
typedef struct kh_PTR_s { khint_t n_buckets, size, n_occupied, upper_bound; khint32_t *flags; khint64_t *keys; External *vals; } kh_PTR_t; static inline __attribute__ ((__unused__)) kh_PTR_t *kh_init_PTR(void) { return (kh_PTR_t*)pcalloc(1,sizeof(kh_PTR_t),__func__,__FILE__,0); } static inline __attribute__ ((__unused__)) void kh_destroy_PTR(kh_PTR_t *h) { if (h) { pfree((void *)h->keys,__func__,__FILE__,0); pfree(h->flags,__func__,__FILE__,0); pfree((void *)h->vals,__func__,__FILE__,0); pfree(h,__func__,__FILE__,0); } } static inline __attribute__ ((__unused__)) void kh_clear_PTR(kh_PTR_t *h) { if (h && h->flags) { memset(h->flags, 0xaa, ((h->n_buckets) < 16? 1 : (h->n_buckets)>>4) * sizeof(khint32_t)); h->size = h->n_occupied = 0; } } static inline __attribute__ ((__unused__)) khint_t kh_get_PTR(const kh_PTR_t *h, khint64_t key) { if (h->n_buckets) { khint_t k, i, last, mask, step = 0; mask = h->n_buckets - 1; k = (khint32_t)((key)>>33^(key)^(key)<<11); i = k & mask; last = i; while (!((h->flags[i>>4]>>((i&0xfU)<<1))&2) && (((h->flags[i>>4]>>((i&0xfU)<<1))&1) || !((h->keys[i]) == (key)))) { i = (i + (++step)) & mask; if (i == last) return h->n_buckets; } return ((h->flags[i>>4]>>((i&0xfU)<<1))&3)? h->n_buckets : i; } else return 0; } static inline __attribute__ ((__unused__)) int kh_resize_PTR(kh_PTR_t *h, khint_t new_n_buckets) { khint32_t *new_flags = 0; khint_t j = 1; { (--(new_n_buckets), (new_n_buckets)|=(new_n_buckets)>>1, (new_n_buckets)|=(new_n_buckets)>>2, (new_n_buckets)|=(new_n_buckets)>>4, (new_n_buckets)|=(new_n_buckets)>>8, (new_n_buckets)|=(new_n_buckets)>>16, ++(new_n_buckets)); if (new_n_buckets < 4) new_n_buckets = 4; if (h->size >= (khint_t)(new_n_buckets * __ac_HASH_UPPER + 0.5)) j = 0; else { new_flags = (khint32_t*)pmalloc(((new_n_buckets) < 16? 1 : (new_n_buckets)>>4) * sizeof(khint32_t),__func__,__FILE__,0); if (!new_flags) return -1; memset(new_flags, 0xaa, ((new_n_buckets) < 16? 1 : (new_n_buckets)>>4) * sizeof(khint32_t)); if (h->n_buckets < new_n_buckets) { khint64_t *new_keys = (khint64_t*)prealloc((void *)h->keys,new_n_buckets * sizeof(khint64_t),__func__,__FILE__,0); if (!new_keys) { pfree(new_flags,__func__,__FILE__,0); return -1; } h->keys = new_keys; if (1) { External *new_vals = (External*)prealloc((void *)h->vals,new_n_buckets * sizeof(External),__func__,__FILE__,0); if (!new_vals) { pfree(new_flags,__func__,__FILE__,0); return -1; } h->vals = new_vals; } } } } if (j) { for (j = 0; j != h->n_buckets; ++j) { if (((h->flags[j>>4]>>((j&0xfU)<<1))&3) == 0) { khint64_t key = h->keys[j]; External val; khint_t new_mask; new_mask = new_n_buckets - 1; if (1) val = h->vals[j]; (h->flags[j>>4]|=1ul<<((j&0xfU)<<1)); while (1) { khint_t k, i, step = 0; k = (khint32_t)((key)>>33^(key)^(key)<<11); i = k & new_mask; while (!((new_flags[i>>4]>>((i&0xfU)<<1))&2)) i = (i + (++step)) & new_mask; (new_flags[i>>4]&=~(2ul<<((i&0xfU)<<1))); if (i < h->n_buckets && ((h->flags[i>>4]>>((i&0xfU)<<1))&3) == 0) { { khint64_t tmp = h->keys[i]; h->keys[i] = key; key = tmp; } if (1) { External tmp = h->vals[i]; h->vals[i] = val; val = tmp; } (h->flags[i>>4]|=1ul<<((i&0xfU)<<1)); } else { h->keys[i] = key; if (1) h->vals[i] = val; break; } } } } if (h->n_buckets > new_n_buckets) { h->keys = (khint64_t*)prealloc((void *)h->keys,new_n_buckets * sizeof(khint64_t),__func__,__FILE__,0); if (1) h->vals = (External*)prealloc((void *)h->vals,new_n_buckets * sizeof(External),__func__,__FILE__,0); } pfree(h->flags,__func__,__FILE__,0); h->flags = new_flags; h->n_buckets = new_n_buckets; h->n_occupied = h->size; h->upper_bound = (khint_t)(h->n_buckets * __ac_HASH_UPPER + 0.5); } return 0; } static inline __attribute__ ((__unused__)) khint_t kh_put_PTR(kh_PTR_t *h, khint64_t key, int *ret) { khint_t x; if (h->n_occupied >= h->upper_bound) { if (h->n_buckets > (h->size<<1)) { if (kh_resize_PTR(h, h->n_buckets - 1) < 0) { *ret = -1; return h->n_buckets; } } else if (kh_resize_PTR(h, h->n_buckets + 1) < 0) { *ret = -1; return h->n_buckets; } } { khint_t k, i, site, last, mask = h->n_buckets - 1, step = 0; x = site = h->n_buckets; k = (khint32_t)((key)>>33^(key)^(key)<<11); i = k & mask; if (((h->flags[i>>4]>>((i&0xfU)<<1))&2)) x = i; else { last = i; while (!((h->flags[i>>4]>>((i&0xfU)<<1))&2) && (((h->flags[i>>4]>>((i&0xfU)<<1))&1) || !((h->keys[i]) == (key)))) { if (((h->flags[i>>4]>>((i&0xfU)<<1))&1)) site = i; i = (i + (++step)) & mask; if (i == last) { x = site; break; } } if (x == h->n_buckets) { if (((h->flags[i>>4]>>((i&0xfU)<<1))&2) && site != h->n_buckets) x = site; else x = i; } } } if (((h->flags[x>>4]>>((x&0xfU)<<1))&2)) { h->keys[x] = key; (h->flags[x>>4]&=~(3ul<<((x&0xfU)<<1))); ++h->size; ++h->n_occupied; *ret = 1; } else if (((h->flags[x>>4]>>((x&0xfU)<<1))&1)) { h->keys[x] = key; (h->flags[x>>4]&=~(3ul<<((x&0xfU)<<1))); ++h->size; *ret = 2; } else *ret = 0; return x; } static inline __attribute__ ((__unused__)) void kh_del_PTR(kh_PTR_t *h, khint_t x) { if (x != h->n_buckets && !((h->flags[x>>4]>>((x&0xfU)<<1))&3)) { (h->flags[x>>4]|=1ul<<((x&0xfU)<<1)); --h->size; } }

static kh_PTR_t * _functions = NULL;

static External * _get_function (long ptr)
{
  if (!_functions)
    return NULL;
  khiter_t k = kh_get_PTR(_functions, ptr);
  if (k == ((_functions)->n_buckets))
    return NULL;
  return &((_functions)->vals[k]);
}

static void register_function (void (* ptr) (void), const char * name,
          const char * kernel, const void * externals)
{
  static int index = 1;
  if (!_functions)
    _functions = kh_init_PTR(), index = 1;
  int m = 0;
  for (const External * i = externals; i && i->name; i++, m++);
  External * copy = NULL;
  if (m > 0) {
    copy = pmalloc ((m + 1)*sizeof (External),__func__,__FILE__,0);
    memcpy (copy, externals, (m + 1)*sizeof (External));
  }
  int ret;
  khiter_t k = kh_put_PTR(_functions, (long) ptr, &ret);
  External p = {
    .name = (char *) name,
    .type = sym_function_definition,
    .pointer = (void *)(long) ptr, .nd = index++,
    .data = (void *) kernel, .externals = copy
  };
  ((_functions)->vals[k]) = p;
}
#line 160 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
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
  if (!(nvar + block <= _NVARMAX)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h", 0, "nvar + block <= _NVARMAX");

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

  realloc_scalar_gpu (block*sizeof(real));
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
#line 311
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
#line 338 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
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
  if (!(_attribute[src.i].block > 0 && _attribute[clone.i].block == _attribute[src.i].block)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h", 0, "src.block > 0 && clone.block == src.block");
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
#line 412
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
  if (!(_val_higher_dimension == 0.)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h", 0, "_val_higher_dimension == 0.");

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

  do { for (khiter_t k = (khint_t)(0); k != ((_functions)->n_buckets); ++k) if ((!(((_functions)->flags[(k)>>4]>>(((k)&0xfU)<<1))&3))) { External * f = &((_functions)->vals[k]); pfree ((void *) f->externals,__func__,__FILE__,0); } } while(0);
  kh_destroy_PTR(_functions); _functions = NULL;

  free_grid();
  qpclose_all();
#if 2
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
{tracing("boundary_internal","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h",0);
  if (list == NULL)
    {end_tracing("boundary_internal","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h",0);return;}
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
#line 551
if (_attribute[s.i].v.y.i == s.i)
       listf.y = list_add (listf.y, s), flux = true;}
 if (!is_constant(cm) && !(_attribute[cm.i].stencil.bc & s_centered))
   listc = list_add_depends (listc, cm);
 if (_attribute[s.i].face != 2)
   listc = list_add_depends (listc, s);
      }




    }}}
  if (flux) {
#line 575 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
    boundary_face (listf);
    
      pfree (listf.x,__func__,__FILE__,0);      pfree (listf.y,__func__,__FILE__,0);
  }
  if (listc) {






    boundary_level (listc, -1);
    {scalar*_i=(scalar*)( listc);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      _attribute[s.i].stencil.bc |= s_centered;}}
    pfree (listc,__func__,__FILE__,0);
  }
end_tracing("boundary_internal","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h",0);}

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
#line 602
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
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
#line 613 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
return val(s,0,0,0);
}

static double antisymmetry (Point point, Point neighbor, scalar s, bool * data)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
#line 618 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
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
#line 656
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
#line 683
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
#line 705
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
#line 717
{
    if (name) {
      char cname[strlen(name) + 3];
      strcat (strcpy (cname, name), ext.y);
      cartesian_init_vector (t.y, cname);
    }
    else
      cartesian_init_vector (t.y, NULL);
  }
#line 734 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
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
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 752 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 752 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
{
    bool inside = true;
    coord o = {x,y,z};
    
      if (inside && size > 0. &&
   (o.x > c.x + size || o.x < c.x - size))
 inside = false;      
#line 756
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
#line 784 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
    }
  }}      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
  
#line 786 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
fflush (fp);
}
#line 796 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
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
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
#line 831 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
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
#line 863 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
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
#line 893 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
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
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;







  
#line 944 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
x = (xp - x)/Delta - _attribute[v.i].d.x/2.;
  y = (yp - y)/Delta - _attribute[v.i].d.y/2.;
  int i = ( (int)(x > 0 ? 1 : -1)), j = ( (int)(y > 0 ? 1 : -1));
  x = fabs(x); y = fabs(y);

  return ((val(v,0,0,0)*(1. - x) + val(v,i,0,0)*x)*(1. - y) +
   (val(v,0,j,0)*(1. - x) + val(v,i,j,0)*x)*y);
#line 963 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
}
#line 934
static void _stencil_interpolate_linear (Point point, scalar v,
_stencil_undefined * xp,_stencil_undefined * yp,_stencil_undefined * zp)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;                    







        
        
  
       
#line 949 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
_stencil_val(v,0,0,0);_stencil_val(v, o_stencil,0,0);
_stencil_val(v,0,o_stencil,0); _stencil_val(v,o_stencil,o_stencil,0);  
#line 949
return         
    ;
#line 963 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
}

     
double interpolate (scalar v, double xp, double yp, double zp,
      bool linear)
{tracing("interpolate","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h",0);
  double val = 1e30f;  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 90
{
    _region.p = (coord){ xp, yp, zp };
    _region.n = (coord){ 1, 1 };
    
#line 971 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
{ _stencil_interpolate_linear (point, v, NULL, NULL, NULL); _stencil_val(v,0,0,0);    }  
#line 94 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 90
(
#line 970 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
(External[]){{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{.name="xp",.type=49,.pointer=(void *)&xp},{.name="yp",.type=49,.pointer=(void *)&yp},{.name="zp",.type=49,.pointer=(void *)&zp},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="_val",.type=49,.pointer=(void *)&val,.reduct='m'},{.name="linear",.type=sym_BOOL,.pointer=(void *)&linear},{.name="interpolate_linear",.type=sym_function_definition,.pointer=(void *)(long)interpolate_linear},{.name="v",.type=sym_SCALAR,.pointer=(void *)&v},{0}}
#line 90 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\n_val = linear ? interpolate_linear (point, v, xp, yp, zp) : val(v,0,0,0);}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;
#line 13 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
{
  {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    coord _p = { xp, yp, zp };
    Point point = locate (_p.x, _p.y, _p.z);
    if (point.level >= 0)
    
#line 971
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 971 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
val = linear ? interpolate_linear (point, v, xp, yp, zp) : val(v,0,0,0);}  
#line 20
}
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 971 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
{mpi_all_reduce_array(&val,MPI_DOUBLE,MPI_MIN,1);}
  {end_tracing("interpolate","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h",0);return val;}
end_tracing("interpolate","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h",0);}

     
void interpolate_array (scalar * list, coord * a, int n, double * v,
   bool linear)
{tracing("interpolate_array","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h",0);
  int len = 0; NOT_UNUSED(len);
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    len++;}}
  for (int i = 0; i < n; i++) {
    double * w = v;

    coord p = a[i];
    {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
      double value = 1e30f;      
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 90
{
    _region.p = (coord){ (
#line 988 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
p.x
#line 91 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
), (
#line 988 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
p.y
#line 91 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
), (
#line 988 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
p.z
#line 91 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
) };
    _region.n = (coord){ 1, 1 };
 
#line 989 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
{ _stencil_val(s,0,0,0); _stencil_interpolate_linear (point, s, NULL, NULL, NULL);    }  
#line 94 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 90
(
#line 988 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
(External[]){{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{.name="p",.type=sym_COORD,.pointer=(void *)&p},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="value",.type=49,.pointer=(void *)&value,.reduct='m'},{.name="linear",.type=sym_BOOL,.pointer=(void *)&linear},{.name="s",.type=sym_SCALAR,.pointer=(void *)&s},{.name="interpolate_linear",.type=sym_function_definition,.pointer=(void *)(long)interpolate_linear},{0}}
#line 90 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\nvalue = !linear ? val(s,0,0,0) : interpolate_linear (point, s, p.x, p.y, 0.f);}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;
#line 13 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
{
  {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    coord _p = { (
#line 988
p.x
#line 16
), (
#line 988
p.y
#line 16
), (
#line 988
p.z
#line 16
) };
    Point point = locate (_p.x, _p.y, _p.z);
    if (point.level >= 0)
 
#line 989
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 989 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
value = !linear ? val(s,0,0,0) : interpolate_linear (point, s, p.x, p.y, 0.);}  
#line 20
}
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 989 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
{mpi_all_reduce_array(&value,MPI_DOUBLE,MPI_MIN,1);}
      *(w++) = value;
    }}}
#line 1001 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
    v = w;
  }
end_tracing("interpolate_array","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h",0);}



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
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
#line 1035 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
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



    if (!(dir <= bottom)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h", 0, "dir <= bottom");




  int c = dir/2;
  periodic_boundary (2*c);
  periodic_boundary (2*c + 1);
  (&Period.x)[c] = true;
}


double getvalue (Point point, scalar s, int i, int j, int k)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
#line 1078 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
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
#line 1144
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
#line 5 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"

void macro_foreach_level_or_leaf (int l, char flags, Reduce reductions)
{
  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 244 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 9 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 9 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
;}
    
#line 261 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 10 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
} 

void macro_foreach_coarse_level (int l, char flags, Reduce reductions)
{
  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 244 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 15 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 15 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
;}
    
#line 261 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 16 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
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
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  
#line 43 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
    double sum = 0.;
  
    
#line 368 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;      
#line 46 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
sum += val(s,0,0,0);
      
#line 377 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }    
#line 47 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
val(s,0,0,0) = sum/(1 << 2);
  }
}
#line 41
static void _stencil_restriction_average (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  
#line 43 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
     
    
    
#line 368 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;      
#line 46 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{ _stencil_val(s,0,0,0); }
      
#line 377 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }    
#line 47 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
_stencil_val_a(s,0,0,0);    
  }
}

static inline void restriction_volume_average (Point point, scalar s)
{if(!is_constant(cm)){{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  
#line 53 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
    double sum = 0.;
  
    
#line 368 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;      
#line 56 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
sum += val(cm,0,0,0)*val(s,0,0,0);
      
#line 377 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }    
#line 57 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
val(s,0,0,0) = sum/(1 << 2)/(val(cm,0,0,0) + 1e-30);
  }
}}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
#line 52
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  
#line 53 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
    double sum = 0.;
  
    
#line 368 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;      
#line 56 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
sum += _const_cm*val(s,0,0,0);
      
#line 377 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }    
#line 57 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
val(s,0,0,0) = sum/(1 << 2)/(_const_cm + 1e-30);
  }
}}}

static inline void face_average (Point point, vector v)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;    
#line 64 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{




      val(v.x,0,0,0) = (fine(v.x,0,0,0) + fine(v.x,0,1,0))/2.;
      val(v.x,1,0,0) = (fine(v.x,2,0,0) + fine(v.x,2,1,0))/2.;






  }    
#line 64
{




      val(v.y,0,0,0) = (fine(v.y,0,0,0) + fine(v.y,1,0,0))/2.;
      val(v.y,0,1,0) = (fine(v.y,0,2,0) + fine(v.y,1,2,0))/2.;






  }
}

static inline void restriction_face (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  
#line 82 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
face_average (point, _attribute[s.i].v);
}

static inline void restriction_vertex (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;    
#line 88 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
for (int i = 0; i <= 1; i++) {
      val(s,i,0,0) = fine(s,2*i,0,0);

      val(s,i,1,0) = fine(s,2*i,2,0);





    }
}

static inline void no_restriction (Point point, scalar s) {}

static inline void no_data (Point point, scalar s) {int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
  
#line 368
{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;      
#line 105 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
val(s,0,0,0) = 1e30f;
      
#line 377 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }
#line 106 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
}

void wavelet (scalar s, scalar w)
{
  restriction (((scalar[]){s,{-1}}));
  for (int l = grid->maxdepth - 1; l >= 0; l--) {    
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 80
{
    _region.level = l + 1; 
#line 112 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
  
      
#line 368 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;        
#line 114 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{ _stencil_val(s,0,0,0);_stencil_val_a(w,0,0,0); }
      
#line 377 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }
#line 115 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
default_stencil (      point,((scalar[]){ s,{-1}}));
  
      
#line 368 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2; 
#line 116 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{  
         _stencil_val(s,0,0,0); 
_stencil_val(w,0,0,0);        _stencil_val_a(s,0,0,0); 

        _stencil_val_r(w,0,0,0);  
      }
      
#line 377 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }    
#line 122 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
}  
#line 83 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 80
(
#line 129
(
#line 112 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
(External[]){{.name=".prolongation",.type=sym_function_declaration,.nd=attroffset(prolongation)},{.name="l",.type=44,.pointer=(void *)&l},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="w",.type=sym_SCALAR,.pointer=(void *)&w},{.name="s",.type=sym_SCALAR,.pointer=(void *)&s},{0}}
#line 129 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 80
)
#line 65
), " \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n{\n  \n      \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n{\n    int _i = 2*point.i - 2, _j = 2*point.j - 2;\n    point.level++;\n    point.n.x *= 2, point.n.y *= 2;\n    for (int _k = 0; _k < 2; _k++)\n      for (int _l = 0; _l < 2; _l++) {\n point.i = _i + _k; point.j = _j + _l; \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;        \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\nval_out_(w,0,0,0) = val(s,0,0,0);\n      \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n    point.i = (_i + 2)/2; point.j = (_j + 2)/2;\n    point.level--;\n    point.n.x /= 2, point.n.y /= 2;\n  }\n      _attr_prolongation(\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\ns, (point, s));\n  \n      \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n{\n    int _i = 2*point.i - 2, _j = 2*point.j - 2;\n    point.level++;\n    point.n.x *= 2, point.n.y *= 2;\n    for (int _k = 0; _k < 2; _k++)\n      for (int _l = 0; _l < 2; _l++) {\n point.i = _i + _k; point.j = _j + _l; \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2; \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n{\n        real sp = val(s,0,0,0);\n        val_out_(s,0,0,0) = val(w,0,0,0);\n\n        val_out_(w,0,0,0) -= sp;\n      }\n      \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n    point.i = (_i + 2)/2; point.j = (_j + 2)/2;\n    point.level--;\n    point.n.x /= 2, point.n.y /= 2;\n  }    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n}}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;
#line 13 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 244 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 112 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 112 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
  
      
#line 368 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;        
#line 114 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
val(w,0,0,0) = val(s,0,0,0);
      
#line 377 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }      
#line 115 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
_attribute[s.i].prolongation (point, s);
  
      
#line 368 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2; 
#line 116 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
        double sp = val(s,0,0,0);
        val(s,0,0,0) = val(w,0,0,0);

        val(w,0,0,0) -= sp;
      }
      
#line 377 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }    
#line 122 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
}}
    
#line 261 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 16 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
}
    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
    
#line 123 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
boundary_level (((scalar[]){w,{-1}}), l + 1);
  }  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 80
{
    _region.level = 0 + 1;
    
#line 127 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{ _stencil_val(s,0,0,0);_stencil_val_a(w,0,0,0); }  
#line 83 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 80
(
#line 126 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="w",.type=sym_SCALAR,.pointer=(void *)&w},{.name="s",.type=sym_SCALAR,.pointer=(void *)&s},{0}}
#line 80 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\nval_out_(w,0,0,0) = val(s,0,0,0);}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 244 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 127 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 127 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
val(w,0,0,0) = val(s,0,0,0);}
    
#line 261 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
  
#line 128 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
boundary_level (((scalar[]){w,{-1}}), 0);
}

void inverse_wavelet (scalar s, scalar w)
{  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 80
{
    _region.level = 0 + 1;
    
#line 134 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{ _stencil_val(w,0,0,0);_stencil_val_a(s,0,0,0); }  
#line 83 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 80
(
#line 133 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="s",.type=sym_SCALAR,.pointer=(void *)&s},{.name="w",.type=sym_SCALAR,.pointer=(void *)&w},{0}}
#line 80 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\nval_out_(s,0,0,0) = val(w,0,0,0);}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 244 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 134 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 134 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
val(s,0,0,0) = val(w,0,0,0);}
    
#line 261 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
  
#line 135 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
boundary_level (((scalar[]){s,{-1}}), 0);
  for (int l = 0; l <= grid->maxdepth - 1; l++) {    
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 80
{
    _region.level = l + 1; 
#line 137 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
default_stencil (      point,((scalar[]){ s,{-1}}));
  
      
#line 368 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;        
#line 140 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{ _stencil_val(w,0,0,0);_stencil_val_r(s,0,0,0); }
      
#line 377 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }    
#line 141 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
}  
#line 83 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 80
(
#line 129
(
#line 137 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
(External[]){{.name=".prolongation",.type=sym_function_declaration,.nd=attroffset(prolongation)},{.name="l",.type=44,.pointer=(void *)&l},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="s",.type=sym_SCALAR,.pointer=(void *)&s},{.name="w",.type=sym_SCALAR,.pointer=(void *)&w},{0}}
#line 129 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 80
)
#line 65
), " \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n{\n      _attr_prolongation(s, (point, s));\n  \n      \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n{\n    int _i = 2*point.i - 2, _j = 2*point.j - 2;\n    point.level++;\n    point.n.x *= 2, point.n.y *= 2;\n    for (int _k = 0; _k < 2; _k++)\n      for (int _l = 0; _l < 2; _l++) {\n point.i = _i + _k; point.j = _j + _l; \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;        \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\nval_out_(s,0,0,0) += val(w,0,0,0);\n      \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n    point.i = (_i + 2)/2; point.j = (_j + 2)/2;\n    point.level--;\n    point.n.x /= 2, point.n.y /= 2;\n  }    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n}}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;
#line 13 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 244 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 137 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 137 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
      _attribute[s.i].prolongation (point, s);
  
      
#line 368 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;        
#line 140 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
val(s,0,0,0) += val(w,0,0,0);
      
#line 377 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }    
#line 141 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
}}
    
#line 261 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 16 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
}
    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
    
#line 142 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
boundary_level (((scalar[]){s,{-1}}), l + 1);
  }
}

static inline double bilinear (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;    
#line 151 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
return (9.*coarse(s,0,0,0) +
     3.*(coarse(s,child.x,0,0) + coarse(s,0,child.y,0)) +
     coarse(s,child.x,child.y,0))/16.;
#line 162 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
}
#line 146
static void _stencil_bilinear (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 151 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
_stencil_coarse(s,0,0,0);
_stencil_coarse(s,o_stencil,0,0); _stencil_coarse(s,0,o_stencil,0);
     _stencil_coarse(s,o_stencil,o_stencil,0);    
#line 151
return 
        
;
#line 162 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
}

static inline void refine_bilinear (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
  
#line 368
{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;      
#line 168 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
val(s,0,0,0) = bilinear (point, s);
      
#line 377 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }
#line 169 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
}

static inline double quadratic (double a, double b, double c)
{
  return (30.*a + 5.*b - 3.*c)/32.;
}

static inline double biquadratic (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  
#line 181 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
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
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;



  
#line 202 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
return (36.*val(s,0,0,0) + 18.*(val(s,-1,0,0) + val(s,0,-1,0)) - 6.*(val(s,1,0,0) + val(s,0,1,0)) +
   9.*val(s,-1,-1,0) - 3.*(val(s,1,-1,0) + val(s,-1,1,0)) + val(s,1,1,0))/64.;




}

static inline void refine_biquadratic (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
  
#line 368
{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
   
      
#line 214 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
val(s,0,0,0) = biquadratic (point, s);
      
#line 377 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }
#line 215 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
}

static inline void refine_linear_single (Point point, scalar s)
{if(!is_constant(cm)){{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
#line 219 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
coord g;
  if (_attribute[s.i].gradient)
    {
      g.x = _attribute[s.i].gradient (val(s,-1,0,0), val(s,0,0,0), val(s,1,0,0));      g.y = _attribute[s.i].gradient (val(s,0,-1,0), val(s,0,0,0), val(s,0,1,0));}
  else
    {
      g.x = (val(s,1,0,0) - val(s,-1,0,0))/2.;      g.y = (val(s,0,1,0) - val(s,0,-1,0))/2.;}

  double sc = val(s,0,0,0), cmc = 4.*val(cm,0,0,0), sum = val(cm,0,0,0)*(1 << 2);
  
  
#line 368 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2; 
#line 228 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
    val(s,0,0,0) = sc;
    
      val(s,0,0,0) += child.x*g.x*val(cm,-child.x,0,0)/cmc;      val(s,0,0,0) += child.y*g.y*val(cm,0,-child.y,0)/cmc;
    sum -= val(cm,0,0,0);
  }
      
#line 377 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }  
#line 234 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
if (!(fabs(sum) < 1e-10)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h", 0, "fabs(sum) < 1e-10");
}}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
#line 218
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
#line 219 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
coord g;
  if (_attribute[s.i].gradient)
    {
      g.x = _attribute[s.i].gradient (val(s,-1,0,0), val(s,0,0,0), val(s,1,0,0));      g.y = _attribute[s.i].gradient (val(s,0,-1,0), val(s,0,0,0), val(s,0,1,0));}
  else
    {
      g.x = (val(s,1,0,0) - val(s,-1,0,0))/2.;      g.y = (val(s,0,1,0) - val(s,0,-1,0))/2.;}

  double sc = val(s,0,0,0), cmc = 4.*_const_cm, sum = _const_cm*(1 << 2);
  
  
#line 368 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2; 
#line 228 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
    val(s,0,0,0) = sc;
    
      val(s,0,0,0) += child.x*g.x*_const_cm/cmc;      val(s,0,0,0) += child.y*g.y*_const_cm/cmc;
    sum -= _const_cm;
  }
      
#line 377 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }  
#line 234 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
if (!(fabs(sum) < 1e-10)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h", 0, "fabs(sum) < 1e-10");
}}}

static inline void refine_linear (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
 
    
#line 240 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
refine_linear_single (point, s);
}

static inline void refine_reset (Point point, scalar v)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
  
#line 368
{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
   
      
#line 247 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
val(v,0,0,0) = 0.;
      
#line 377 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }
#line 248 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
}

static inline void refine_injection (Point point, scalar v)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
#line 252 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
double val = val(v,0,0,0);
  
  
#line 368 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
   
      
#line 255 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
val(v,0,0,0) = val;
      
#line 377 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }
#line 256 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
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
#line 275
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
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
#line 307 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
cartesian_debug (point);

  FILE * plot = fopen ("plot", "a");
  if (point.level > 0) {
    char name[80] = "coarse";
    if (pid() > 0)
      sprintf (name, "coarse-%d", pid());
    FILE * fp = fopen (name, "w");
#line 326 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
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
#line 357 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
    fclose (fp);
  }

  if (is_coarse()) {
    char name[80] = "fine";
    if (pid() > 0)
      sprintf (name, "fine-%d", pid());
    FILE * fp = fopen (name, "w");
#line 379 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
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
#line 417 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
    fclose (fp);
  }
  fflush (ferr);
  fclose (plot);
}

     
static void multigrid_restriction (scalar * list)
{tracing("multigrid_restriction","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h",0);
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
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 80
{
    _region.level = l + 1; 
#line 445 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
 {scalar*_i=(scalar*)( listdef);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
   _stencil_restriction_average (point, s);}}
 {scalar*_i=(scalar*)( listc);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
default_stencil (   point,((scalar[]){ s,{-1}}));}}
      }  
#line 83 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 80
(
#line 129
(
#line 445 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
(External[]){{.name=".restriction",.type=sym_function_declaration,.nd=attroffset(restriction)},{.name="l",.type=44,.pointer=(void *)&l},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="listdef",.type=sym_SCALAR,.pointer=(void *)listdef,.nd=1},{.name="restriction_average",.type=sym_function_definition,.pointer=(void *)(long)restriction_average},{.name="listc",.type=sym_SCALAR,.pointer=(void *)listc,.nd=1},{0}}
#line 129 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 80
)
#line 65
), " \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n{\n {forin (scalar, s , listdef)\n   restriction_average (point, s); endforin()}\n {forin (scalar, s , listc)\n   _attr_restriction(s, (point, s)); endforin()}\n      }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;
#line 13 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 244 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 445 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 445 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
 {scalar*_i=(scalar*)( listdef);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
   restriction_average (point, s);}}
 {scalar*_i=(scalar*)( listc);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
   _attribute[s.i].restriction (point, s);}}
      }}    
#line 261 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 16 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
}
    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
      
#line 451 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{ Boundary ** _i = boundaries, * _b; while (_i && (_b = *_i++)) if (_b->level) _b->level (_b, list2, l); };
    }
    pfree (listdef,__func__,__FILE__,0);
    pfree (listc,__func__,__FILE__,0);
    {scalar*_i=(scalar*)( list2);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      _attribute[s.i].stencil.bc |= s_restriction;}}
    pfree (list2,__func__,__FILE__,0);
  }
end_tracing("multigrid_restriction","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h",0);}

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
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
    
#line 486 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{_stencil_val_a(size,0,0,0);  }
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 485 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="size",.type=sym_SCALAR,.pointer=(void *)&size},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\nval_out_(size,0,0,0) = 1;}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
    
#line 486 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 486 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
val(size,0,0,0) = 1;}      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }





  
#line 492 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{ Boundary ** _i = boundaries, * _b; while (_i && (_b = *_i++)) if (_b->restriction) _b->restriction (_b,((scalar[]) {size,{-1}}), depth()); };
  for (int l = depth() - 1; l >= 0; l--) {    
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 80
{
    _region.level = l + 1; 
#line 494 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{      
#line 368 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
 
#line 497 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{ _stencil_val(size,0,0,0); }      
#line 377 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }
      
#line 498 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
_stencil_val_a(size,0,0,0);  
    }  
#line 83 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 80
(
#line 129
(
#line 494 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
(External[]){{.name="l",.type=44,.pointer=(void *)&l},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="leaves",.type=sym_BOOL,.pointer=(void *)&leaves},{.name="size",.type=sym_SCALAR,.pointer=(void *)&size},{0}}
#line 129 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 80
)
#line 65
), " \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n{\n      real sum =int( !leaves);      \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n{\n    int _i = 2*point.i - 2, _j = 2*point.j - 2;\n    point.level++;\n    point.n.x *= 2, point.n.y *= 2;\n    for (int _k = 0; _k < 2; _k++)\n      for (int _l = 0; _l < 2; _l++) {\n point.i = _i + _k; point.j = _j + _l; \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\nsum += val(size,0,0,0);      \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n    point.i = (_i + 2)/2; point.j = (_j + 2)/2;\n    point.level--;\n    point.n.x /= 2, point.n.y /= 2;\n  }\n      \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\nval_out_(size,0,0,0) = sum;\n    }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;
#line 13 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 244 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 494 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 494 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
      double sum = !leaves;      
#line 368 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
{
    int _i = 2*point.i - 2, _j = 2*point.j - 2;
    point.level++;
    point.n.x *= 2, point.n.y *= 2;
    for (int _k = 0; _k < 2; _k++)
      for (int _l = 0; _l < 2; _l++) {
 point.i = _i + _k; point.j = _j + _l; 
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
 
#line 497 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
sum += val(size,0,0,0);      
#line 377 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
    point.i = (_i + 2)/2; point.j = (_j + 2)/2;
    point.level--;
    point.n.x /= 2, point.n.y /= 2;
  }
      
#line 498 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
val(size,0,0,0) = sum;
    }}    
#line 261 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 16 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
}
    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
    
#line 500 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{ Boundary ** _i = boundaries, * _b; while (_i && (_b = *_i++)) if (_b->restriction) _b->restriction (_b,((scalar[]) {size,{-1}}), l); };
  }
}
#line 34 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu-multigrid.h"
#line 1 "grid/hip/../gpu/backend.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/backend.h"




static char * str_append_array (char * dst, const char * list[])
{
  int empty = (dst == NULL);
  int len = empty ? 0 : strlen (dst);
  for (const char ** s = list; *s != NULL; s++)
    len += strlen (*s);
  dst = (char *) sysrealloc (dst, len + 1);
  if (empty) dst[0] = '\0';
  for (const char ** s = list; *s != NULL; s++)
    strcat (dst, *s);
  return dst;
}







typedef struct _Shader Shader;
typedef struct _GPUData GPUData;

typedef struct kh_INT_s { khint_t n_buckets, size, n_occupied, upper_bound; khint32_t *flags; khint32_t *keys; Shader * *vals; } kh_INT_t; static inline __attribute__ ((__unused__)) kh_INT_t *kh_init_INT(void) { return (kh_INT_t*)pcalloc(1,sizeof(kh_INT_t),__func__,__FILE__,0); } static inline __attribute__ ((__unused__)) void kh_destroy_INT(kh_INT_t *h) { if (h) { pfree((void *)h->keys,__func__,__FILE__,0); pfree(h->flags,__func__,__FILE__,0); pfree((void *)h->vals,__func__,__FILE__,0); pfree(h,__func__,__FILE__,0); } } static inline __attribute__ ((__unused__)) void kh_clear_INT(kh_INT_t *h) { if (h && h->flags) { memset(h->flags, 0xaa, ((h->n_buckets) < 16? 1 : (h->n_buckets)>>4) * sizeof(khint32_t)); h->size = h->n_occupied = 0; } } static inline __attribute__ ((__unused__)) khint_t kh_get_INT(const kh_INT_t *h, khint32_t key) { if (h->n_buckets) { khint_t k, i, last, mask, step = 0; mask = h->n_buckets - 1; k = (khint32_t)(key); i = k & mask; last = i; while (!((h->flags[i>>4]>>((i&0xfU)<<1))&2) && (((h->flags[i>>4]>>((i&0xfU)<<1))&1) || !((h->keys[i]) == (key)))) { i = (i + (++step)) & mask; if (i == last) return h->n_buckets; } return ((h->flags[i>>4]>>((i&0xfU)<<1))&3)? h->n_buckets : i; } else return 0; } static inline __attribute__ ((__unused__)) int kh_resize_INT(kh_INT_t *h, khint_t new_n_buckets) { khint32_t *new_flags = 0; khint_t j = 1; { (--(new_n_buckets), (new_n_buckets)|=(new_n_buckets)>>1, (new_n_buckets)|=(new_n_buckets)>>2, (new_n_buckets)|=(new_n_buckets)>>4, (new_n_buckets)|=(new_n_buckets)>>8, (new_n_buckets)|=(new_n_buckets)>>16, ++(new_n_buckets)); if (new_n_buckets < 4) new_n_buckets = 4; if (h->size >= (khint_t)(new_n_buckets * __ac_HASH_UPPER + 0.5)) j = 0; else { new_flags = (khint32_t*)pmalloc(((new_n_buckets) < 16? 1 : (new_n_buckets)>>4) * sizeof(khint32_t),__func__,__FILE__,0); if (!new_flags) return -1; memset(new_flags, 0xaa, ((new_n_buckets) < 16? 1 : (new_n_buckets)>>4) * sizeof(khint32_t)); if (h->n_buckets < new_n_buckets) { khint32_t *new_keys = (khint32_t*)prealloc((void *)h->keys,new_n_buckets * sizeof(khint32_t),__func__,__FILE__,0); if (!new_keys) { pfree(new_flags,__func__,__FILE__,0); return -1; } h->keys = new_keys; if (1) { Shader * *new_vals = (Shader **)prealloc((void *)h->vals,new_n_buckets * sizeof(Shader *),__func__,__FILE__,0); if (!new_vals) { pfree(new_flags,__func__,__FILE__,0); return -1; } h->vals = new_vals; } } } } if (j) { for (j = 0; j != h->n_buckets; ++j) { if (((h->flags[j>>4]>>((j&0xfU)<<1))&3) == 0) { khint32_t key = h->keys[j]; Shader * val; khint_t new_mask; new_mask = new_n_buckets - 1; if (1) val = h->vals[j]; (h->flags[j>>4]|=1ul<<((j&0xfU)<<1)); while (1) { khint_t k, i, step = 0; k = (khint32_t)(key); i = k & new_mask; while (!((new_flags[i>>4]>>((i&0xfU)<<1))&2)) i = (i + (++step)) & new_mask; (new_flags[i>>4]&=~(2ul<<((i&0xfU)<<1))); if (i < h->n_buckets && ((h->flags[i>>4]>>((i&0xfU)<<1))&3) == 0) { { khint32_t tmp = h->keys[i]; h->keys[i] = key; key = tmp; } if (1) { Shader * tmp = h->vals[i]; h->vals[i] = val; val = tmp; } (h->flags[i>>4]|=1ul<<((i&0xfU)<<1)); } else { h->keys[i] = key; if (1) h->vals[i] = val; break; } } } } if (h->n_buckets > new_n_buckets) { h->keys = (khint32_t*)prealloc((void *)h->keys,new_n_buckets * sizeof(khint32_t),__func__,__FILE__,0); if (1) h->vals = (Shader **)prealloc((void *)h->vals,new_n_buckets * sizeof(Shader *),__func__,__FILE__,0); } pfree(h->flags,__func__,__FILE__,0); h->flags = new_flags; h->n_buckets = new_n_buckets; h->n_occupied = h->size; h->upper_bound = (khint_t)(h->n_buckets * __ac_HASH_UPPER + 0.5); } return 0; } static inline __attribute__ ((__unused__)) khint_t kh_put_INT(kh_INT_t *h, khint32_t key, int *ret) { khint_t x; if (h->n_occupied >= h->upper_bound) { if (h->n_buckets > (h->size<<1)) { if (kh_resize_INT(h, h->n_buckets - 1) < 0) { *ret = -1; return h->n_buckets; } } else if (kh_resize_INT(h, h->n_buckets + 1) < 0) { *ret = -1; return h->n_buckets; } } { khint_t k, i, site, last, mask = h->n_buckets - 1, step = 0; x = site = h->n_buckets; k = (khint32_t)(key); i = k & mask; if (((h->flags[i>>4]>>((i&0xfU)<<1))&2)) x = i; else { last = i; while (!((h->flags[i>>4]>>((i&0xfU)<<1))&2) && (((h->flags[i>>4]>>((i&0xfU)<<1))&1) || !((h->keys[i]) == (key)))) { if (((h->flags[i>>4]>>((i&0xfU)<<1))&1)) site = i; i = (i + (++step)) & mask; if (i == last) { x = site; break; } } if (x == h->n_buckets) { if (((h->flags[i>>4]>>((i&0xfU)<<1))&2) && site != h->n_buckets) x = site; else x = i; } } } if (((h->flags[x>>4]>>((x&0xfU)<<1))&2)) { h->keys[x] = key; (h->flags[x>>4]&=~(3ul<<((x&0xfU)<<1))); ++h->size; ++h->n_occupied; *ret = 1; } else if (((h->flags[x>>4]>>((x&0xfU)<<1))&1)) { h->keys[x] = key; (h->flags[x>>4]&=~(3ul<<((x&0xfU)<<1))); ++h->size; *ret = 2; } else *ret = 0; return x; } static inline __attribute__ ((__unused__)) void kh_del_INT(kh_INT_t *h, khint_t x) { if (x != h->n_buckets && !((h->flags[x>>4]>>((x&0xfU)<<1))&3)) { (h->flags[x>>4]|=1ul<<((x&0xfU)<<1)); --h->size; } }

void gpu_free_solver (void);
void free_shader (Shader * s);
Shader * load_normal_shader (const char * fs, const char * func, const char * file, int line);
void gpu_free_context (GPUData * data);
bool gpu_init_context (GPUData ** data);
void realloc_ssbo (size_t field_size);
void gpu_synchronize();

typedef enum {
  GPU_READ, GPU_WRITE
} SyncMode;

void gpu_cpu_sync_scalar (int i, int block, char * data, size_t field_size, SyncMode mode);
void reset_scalar (int i, int block, size_t field_size, double val);

void finalize_shader (Shader * s, External * externals, External * merged,
                      unsigned ng[2], unsigned nwg[2]);
void post_setup_shader (Shader * shader, External * externals);
int run_shader (const Shader * shader, const RegionParameters * region);
double gpu_reduction (size_t offset, const char op, const RegionParameters * region,
                      GPUData * data, size_t nb);
char * gpu_errors (const char * errors, const char * source, char * fout,
                   const char * lang);

void printWorkGroupsCapabilities();
void gpu_limits (FILE * fp);

typedef struct {
  bool fragment_shader;
  int current_shader, nssbo;
  size_t max_ssbo_size, current_size;
} GPUContext_t;

extern GPUContext_t GPUContext;
#line 35 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu-multigrid.h"

typedef struct {
  Multigrid parent;
  kh_INT_t * shaders;
  GPUData * data;
} GridGPU;

#ifndef tracing
#define tracing(func, file, line) do {\
    gpu_synchronize();\
    tracing(func, file, line);\
  } while(0) 
#line 45

#define end_tracing(func, file, line) do {\
    gpu_synchronize();\
    end_tracing(func, file, line);\
  } while(0) 
#line 49

#endif

#line 1 "grid/hip/../gpu/grid.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
#line 376 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
bool on_cpu = false;



GPUContext_t GPUContext = {
  .current_shader = -1,
};
#line 434 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
const char glsl_preproc[] =
  
"// #line " "0" " " "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h" "\n"
  "#define uniform __constant__\n" "struct ivec2 { int x, y; };\n" "typedef unsigned int uint;\n" "__host__ __device__ inline int clamp(int x, int a, int b) { return max(a, min(x, b)); }\n" "struct vec2 { float x, y; };\n" "struct vec3 { float x, y, z; };\n" "#define forin(type,s,list) for (int _i = 0; _i < sizeof(list)/sizeof(type) - 1; _i++) { type s = list[_i];\n" "#define forin2(a,b,c,d) for (int _i = 0; _i < sizeof(c)/sizeof(a) - 1; _i++)" "  { a = c[_i]; b = d[_i];\n" "#define forin3(a,b,e,c,d,f) for (int _i = 0; _i < sizeof(c)/sizeof(a) - 1; _i++)" "  { a = c[_i]; b = d[_i]; e = f[_i];\n" "#define layout(x)\n" "#define make_ivec2(a,b) ivec2{a,b}\n"


  "#define neighborp(_i,_j,_k) Point{point.i+_i,point.j+_j,point.level,point.n"



  "}\n"







  "#define dimensional(x)\n"
  "#define fmin(a,b) min(a,b)\n"
  "#define fmax(a,b) max(a,b)\n"




  "#define real float\n"
  "#define coord vec3\n"

  "#define ivec ivec2\n"
  "struct scalar { int i, index; };\n"


  "#define _coord vec2\n"







  "struct vector { scalar x, y; };\n"
  "struct tensor { vector x, y; };\n"

  "#define GHOSTS " "2" "\n"

  "struct Point { int i, j, level;"

  " ivec2 n;"






  "};\n"
  "#define field_size() _field_size\n"
  "#define ast_pointer(x) (x)\n"
  "#define valt(s,k,l,m)" "  _data_val(_index(s,m), point.j + (l) + " " (point.i + (k))*(point.n.y + 2*GHOSTS) + _shift[point.level])\n" "#define val_red_(s) _data_val((s).i, point.j - GHOSTS +" "  (point.i - GHOSTS)*NY + _shift[point.level])\n" "#define fine(a,k,l,m)" "  _data_val(_index(a,m), 2*point.j - GHOSTS + (l) +" "        (2*point.i - GHOSTS + (k))*(point.n.y*2 + 2*GHOSTS) +" "        _shift[point.level + 1])\n" "#define coarse(a,k,l,m)" "  _data_val(_index(a,m), (point.j + GHOSTS)/2 + (l) +" "        ((point.i + GHOSTS)/2 + (k))*(point.n.y/2 + 2*GHOSTS) +" "        _shift[point.level - 1])\n"
  "#define _NVARMAX 65536\n"
  "#define is_constant(v) ((v).i >= _NVARMAX)\n"
  "#define NULL 0\n"
  "#define val(s,k,l,m) ((s).i < _NVARMAX ? valt(s,k,l,m)"
  " : _constant[clamp((s).i -_NVARMAX,0,_nconst-1)])\n"
  "#define val_out_(s,i,j,k) valt(s,i,j,k)\n"
  "#define diagonalize(a)\n"
  "#define val_diagonal(s,i,j,k) real((i) == 0 && (j) == 0 && (k) == 0)\n"
  "#define _attr(s,member) (_attr[(s).index].member)\n"
  "#define endforin() }\n"



  "#define _index(a,m) ((a).i)\n"

  "#define endforin2() }\n"
  "#define endforin3() }\n"
  "#define NOT_UNUSED(x)\n"
  "#define pi 3.14159265359f\n"
  "#define nodata (1e30f)\n"
  "#define fabs(x) abs(x)\n"
  "const real z = 0.;\n"
  "const int ig = 0, jg = 0;\n"



  "__device__ ivec2 csOrigin = {0,0};\n"
  "__device__ vec2 vsOrigin = {0.f,0.f};\n"
  "__device__ vec2 vsScale = {1.f,1.f};\n"
#line 532 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
  ;

static inline int list_size (const External * i)
{
  int size = 0;
  if (i->type == sym_SCALAR) {
    size = 1;
    if (i->nd == 1)
      {scalar*_i=(scalar*)( i->pointer);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ size++;}}
  }
  else if (i->type == sym_VECTOR) {
    size = 1;
    if (i->nd == 1)
      {vector*_i=(vector*)( i->pointer);if(_i)for(vector v=*_i;(&v)->x.i>=0;v=*++_i){ size++;}}
  }
  else if (i->type == sym_TENSOR) {
    size = 1;
    if (i->nd == 1)
      {tensor*_i=(tensor*)( i->pointer);if(_i)for(tensor t=*_i;(&t)->x.x.i>=0;t=*++_i){ size++;}}
  }
  else
    return 0;
  return size;
}

static char * write_scalar (char * fs, scalar s)
{
  char i[20], index[20];
  snprintf (i, 19, "%d", s.i);
  if (s.i < 0 || is_constant(s))
    strcpy (index, "0");
  else {
    if (_attribute[s.i].block < 0)
      s.i += _attribute[s.i].block;
    snprintf (index, 19, "%d", _attribute[s.i].gpu.index - 1);
  }
  return str_append_array (fs, (const char *[]){"{", i, ",", index, "}", NULL});
}

static char * write_vector (char * fs, vector v)
{
  fs = str_append_array (fs, (const char *[]){"{", NULL});
  fs = write_scalar (fs, v.x);
  fs = str_append_array (fs, (const char *[]){",", NULL});
  fs = write_scalar (fs, v.y);
  fs = str_append_array (fs, (const char *[]){"}", NULL});
  return fs;
}

static char * write_tensor (char * fs, tensor t)
{
  fs = str_append_array (fs, (const char *[]){"{", NULL});
  fs = write_vector (fs, t.x);
  fs = str_append_array (fs, (const char *[]){",", NULL});
  fs = write_vector (fs, t.y);
  fs = str_append_array (fs, (const char *[]){"}", NULL});
  return fs;
}

static scalar * apply_bc_list;

static int bc_period_x = -1, bc_period_y = -1;

static void boundary_top (Point point, int i)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
#line 597 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
bool data = false;
  {scalar*_i=(scalar*)( apply_bc_list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!_attribute[s.i].face || s.i != _attribute[s.i].v.y.i) {
      scalar b = (_attribute[s.i].v.x.i < 0 ? s : s.i == _attribute[s.i].v.y.i ? _attribute[s.i].v.x : _attribute[s.i].v.y);
     
 val(s,i,-bc_period_y,0) = _attribute[b.i].boundary_top (neighborp(i,0,0), neighborp(i,-bc_period_y,0), s, &data);
    }}}
}

static void boundary_bottom (Point point, int i)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
#line 608 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
bool data = false;
  {scalar*_i=(scalar*)( apply_bc_list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!_attribute[s.i].face || s.i != _attribute[s.i].v.y.i) {
      scalar b = (_attribute[s.i].v.x.i < 0 ? s : s.i == _attribute[s.i].v.y.i ? _attribute[s.i].v.x : _attribute[s.i].v.y);
     
 val(s,i,bc_period_y,0) = _attribute[b.i].boundary_bottom (neighborp(i,0,0), neighborp(i,bc_period_y,0), s, &data);
    }}}
}

static
void apply_bc (Point point)
{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
  
#line 620 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
bool data = false;

  if (point.i == 2)
    {scalar*_i=(scalar*)( apply_bc_list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      if (_attribute[s.i].face && s.i == _attribute[s.i].v.x.i && _attribute[s.i].boundary_left)

   val(s,0,0,0) = _attribute[s.i].boundary_left (point, neighborp(bc_period_x,0,0), s, &data);}}
  if (point.i == N*Dimensions.x + 2)
    {scalar*_i=(scalar*)( apply_bc_list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      if (_attribute[s.i].face && s.i == _attribute[s.i].v.x.i && _attribute[s.i].boundary_right)

   val(s,0,0,0) = _attribute[s.i].boundary_right (neighborp(bc_period_x,0,0), point, s, &data);}}
  if (point.j == 2)
    {scalar*_i=(scalar*)( apply_bc_list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      if (_attribute[s.i].face && s.i == _attribute[s.i].v.y.i) {
 scalar b = _attribute[s.i].v.x;
 if (_attribute[b.i].boundary_bottom)
  
     val(s,0,0,0) = _attribute[b.i].boundary_bottom (point, neighborp(0,bc_period_y,0), s, &data);
      }}}
  if (point.j == N*Dimensions.y + 2)
    {scalar*_i=(scalar*)( apply_bc_list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      if (_attribute[s.i].face && s.i == _attribute[s.i].v.y.i) {
 scalar b = _attribute[s.i].v.x;
 if (_attribute[b.i].boundary_top)
  
     val(s,0,0,0) = _attribute[b.i].boundary_top (neighborp(0,bc_period_y,0), point, s, &data);
      }}}

  if (point.i == 2) {
    {scalar*_i=(scalar*)( apply_bc_list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      if (!_attribute[s.i].face || s.i != _attribute[s.i].v.x.i)

   val(s,bc_period_x,0,0) = _attribute[s.i].boundary_left (point, neighborp(bc_period_x,0,0), s, &data);}}
    if (point.j == 2)
      boundary_bottom (point, bc_period_x);
    if (point.j == N*Dimensions.y + 2 - 1)
      boundary_top (point, bc_period_x);
  }
  if (point.i == N*Dimensions.x + 2 - 1) {
    {scalar*_i=(scalar*)( apply_bc_list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      if (!_attribute[s.i].face || s.i != _attribute[s.i].v.x.i)

   val(s,- bc_period_x,0,0) = _attribute[s.i].boundary_right (point, neighborp(- bc_period_x,0,0), s, &data);}}
    if (point.j == 2)
      boundary_bottom (point, - bc_period_x);
    if (point.j == N*Dimensions.y + 2 - 1)
      boundary_top (point, - bc_period_x);
  }
  if (point.j == 2)
    boundary_bottom (point, 0);
  if (point.j == N*Dimensions.y + 2 - 1)
    boundary_top (point, 0);
}

static bool is_boundary_attribute (const External * g)
{
  return (g->name[0] == '.' &&
   (!strcmp (g->name, ".boundary_left") ||
    !strcmp (g->name, ".boundary_right") ||
    !strcmp (g->name, ".boundary_bottom") ||
    !strcmp (g->name, ".boundary_top")));
}

static
void hash_external (Adler32Hash * hash, const External * g, const ForeachData * loop, int indent)
{
  if (g->type == sym_function_declaration || g->type == sym_function_definition) {
    bool boundary = is_boundary_attribute (g);
    {scalar*_i=(scalar*)( baseblock);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      if (g->name[0] != '.' || (!boundary && _attribute[s.i].gpu.index) ||
          (boundary && (_attribute[s.i].stencil.io & s_output))) {
 void * ptr = g->name[0] != '.' ? g->pointer :
   *((void **)(((char *) &_attribute[s.i]) + g->nd));
 if (ptr) {
   External * p = _get_function ((long) ptr);
   if (p && !p->used) {
     p->used = true;
     a32_hash_add (hash, &ptr, sizeof (void *));
     for (const External * e = p->externals; e && e->name; e++)
       hash_external (hash, e, loop, indent + 2);
   }
 }
 if (g->name[0] != '.')
     break;
      }}}
  }
  else if (g->name[0] == '.') {
    int size = 0;
    switch (g->type) {
    case sym_INT: size = sizeof (int); break;
    case sym_BOOL: size = sizeof (bool); break;
    case sym_FLOAT: size = sizeof (float); break;
    case sym_DOUBLE: size = sizeof (double); break;
    case sym_IVEC: size = sizeof (ivec); break;
    case sym_SCALAR: size = sizeof (scalar); break;
    case sym_VECTOR: size = sizeof (vector); break;
    case sym_TENSOR: size = sizeof (tensor); break;
    default: return;
    }
    {scalar*_i=(scalar*)( baseblock);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      if (_attribute[s.i].gpu.index) {
 char * data = (char *) &_attribute[s.i];
 a32_hash_add (hash, data + g->nd, size);
      }}}
  }
  else if (g->type == sym_SCALAR || g->type == sym_VECTOR || g->type == sym_TENSOR) {
    if (!(g->nd == 0 || g->nd == 1)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h", 0, "g->nd == 0 || g->nd == 1");
    void * pointer = g->pointer;
    int size;
    if (g->nd == 1) {
      size = 0;
      {scalar*_i=(scalar*)( pointer);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
 size += sizeof (scalar);}}
    }
    else if (g->type == sym_SCALAR)
      size = sizeof (scalar);
    else if (g->type == sym_VECTOR)
      size = sizeof (vector);
    else
      size = sizeof (tensor);
    a32_hash_add (hash, pointer, size);
  }
  else if (((g)->constant && (g)->type == sym_INT && !(g)->data))
    a32_hash_add (hash, g->pointer, sizeof(int));
}

static
uint32_t hash_shader (const External * externals,
        const ForeachData * loop,
        const RegionParameters * region, const char * kernel)
{
  Adler32Hash hash;
  a32_hash_init (&hash);
  a32_hash_add (&hash, &region->level, sizeof (region->level));
  a32_hash_add (&hash, &N, sizeof (N));



  a32_hash_add (&hash, &Dimensions, sizeof (Dimensions));
  a32_hash_add (&hash, &Period, sizeof (Period));
  a32_hash_add (&hash, kernel, strlen (kernel));
  a32_hash_add (&hash, &nconst, sizeof (nconst));
  a32_hash_add (&hash, _constant, sizeof (*_constant)*nconst);
  static External ext[] = {
    { .name = ".boundary_left", .type = sym_function_declaration,
      .nd = attroffset (boundary_left) },
    { .name = ".boundary_right", .type = sym_function_declaration,
      .nd = attroffset (boundary_right) },
    { .name = ".boundary_top", .type = sym_function_declaration,
      .nd = attroffset (boundary_top) },
    { .name = ".boundary_bottom", .type = sym_function_declaration,
      .nd = attroffset (boundary_bottom) },



    { .name = NULL }
  };
  do { for (khiter_t k = (khint_t)(0); k != ((_functions)->n_buckets); ++k) if ((!(((_functions)->flags[(k)>>4]>>(((k)&0xfU)<<1))&3))) { External * f = &((_functions)->vals[k]); f->used = false; } } while(0);
  for (const External * g = loop->dirty ? ext : ext + 4; g->name; g++)
    hash_external (&hash, g, loop, 2);
  int imax = 1;
  if (GPUContext.nssbo > 1)
    {scalar*_i=(scalar*)( baseblock);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      if (_attribute[s.i].gpu.index && s.i + _attribute[s.i].block > imax)
 imax = s.i + _attribute[s.i].block;}}
  for (const External * g = externals; g && g->name; g++) {
    if (g->reduct) {
      a32_hash_add (&hash, &g->s, sizeof (scalar));
      if (GPUContext.nssbo > 1) {
 scalar s = g->s;
 if (s.i + _attribute[s.i].block > imax)
   imax = s.i + _attribute[s.i].block;
      }
    }
    hash_external (&hash, g, loop, 2);
  }
  a32_hash_add (&hash, &imax, sizeof (imax));
  return a32_hash (&hash);
}

static
bool is_void_function (char * code)
{
  while (*code != '/') code++; code++;
  while (*code != '/') code++; code++;
  while (*code != '\n') code++; code++;
  while (strchr ("\n\r\t ", *code)) code++;
  return !strncmp (code, "void ", 5);
}

static char * type_string (const External * g)
{
  switch (g->type) {
  case sym_DOUBLE:



  case sym_FLOAT: return "float";
  case sym_function_declaration: case sym_enumeration_constant:
  case sym_INT: case sym_LONG: return "int";
  case sym_BOOL: return "bool";
  case sym_SCALAR: return "scalar";
  case sym_VECTOR: return "vector";
  case sym_TENSOR: return "tensor";
  case sym_COORD: return "coord";
  case sym__COORD: return "_coord";
  case sym_VEC4: return "vec4";
  case sym_IVEC: return "ivec";
  }
  return "unknown_type";
}

     
char * build_shader (External * externals, const ForeachData * loop,
       const RegionParameters * region, const unsigned nwg[2])
{tracing("build_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);
  int Nl = region->level > 0 ? 1 << (region->level - 1) : N/Dimensions.x;
  char s[30];
  snprintf (s, 19, "%d", nconst > 0 ? nconst : 1);
  char a[20];
  snprintf (a, 19, "%g", nconst > 0 ? _constant[0] : 0);
  char * fs = str_append_array (NULL, (const char *[]){glsl_preproc, "const int _nconst = ", s, ";\n" "const real _constant[_nconst] = {", a, NULL})





                                            ;
  for (int i = 1; i < nconst; i++) {
    snprintf (a, 19, "%g", _constant[i]);
    fs = str_append_array (fs, (const char *[]){",", a, NULL});
  }
  fs = str_append_array (fs, (const char *[]){"};\n" "__device__ real * _data_ptr;\n", NULL})
#line 865 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
                    ;
  if (GPUContext.nssbo > 1) {
    snprintf (a, 19, "%d", GPUContext.nssbo);
    snprintf (s, 29, "%ld", GPUContext.max_ssbo_size/sizeof(real));
    fs = str_append_array (fs, (const char *[]){"[", a, "];\n" "#define _data_val(field,index) _data[_offset[(field)].i+(_offset[(field)].j+(index))/", s, "].f[(_offset[(field)].j+(index))%", s, "]\n", NULL})

                                                     ;
  }
  else

    fs = str_append_array (fs, (const char *[]){"#define _data_val(field,index) _data_ptr[(field)*field_size() + (index)]\n", NULL})
                                                                                    ;
#line 885 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
  char * attributes = NULL;
  for (const External * g = externals; g; g = g->next)
    if (g->name[0] == '.') {
      attributes = str_append_array (attributes, (const char *[]){"  ", type_string (g), " ", g->name + 1, NULL});
      for (int * d = g->data; d && *d > 0; d++) {
 char s[20]; snprintf (s, 19, "%d", *d);
 attributes = str_append_array (attributes, (const char *[]){"[", s, "]", NULL});
      }
      attributes = str_append_array (attributes, (const char *[]){";\n", NULL});
    }

  if (attributes) {
    fs = str_append_array (fs, (const char *[]){"struct _Attributes {\n", attributes, "};\n", NULL});
    sysfree (attributes);
    int nindex = 0;
    {scalar*_i=(scalar*)( baseblock);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      if (_attribute[s.i].gpu.index)
 nindex++;}}
    if (!(nindex > 0)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h", 0, "nindex > 0");
    char s[20]; snprintf (s, 19, "%d", nindex);
    fs = str_append_array (fs, (const char *[]){"const _Attributes _attr[", s, "]={", NULL});
    nindex = 0;
    {scalar*_i=(scalar*)( baseblock);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      if (_attribute[s.i].gpu.index) {
 fs = str_append_array (fs, (const char *[]){nindex ? ",{" : "{", NULL}); nindex++;
 bool first = true;
 char * data = (char *) &_attribute[s.i];
 for (const External * g = externals; g; g = g->next)
   if (g->name[0] == '.') {
     if (!first) fs = str_append_array (fs, (const char *[]){",", NULL});
     first = false;
     if (g->type == sym_INT) {
       char s[20]; snprintf (s, 19, "%d", *((int *)(data + g->nd)));
       fs = str_append_array (fs, (const char *[]){s, NULL});
     }
     else if (g->type == sym_BOOL)
       fs = str_append_array (fs, (const char *[]){*((bool *)(data + g->nd)) ? "true" : "false", NULL});
     else if (g->type == sym_FLOAT) {
       char s[20]; snprintf (s, 19, "%g", *((float *)(data + g->nd)));
       fs = str_append_array (fs, (const char *[]){s, NULL});
     }
     else if (g->type == sym_DOUBLE) {
       char s[20]; snprintf (s, 19, "%g", *((double *)(data + g->nd)));
       fs = str_append_array (fs, (const char *[]){s, NULL});
     }
     else if (g->type == sym_IVEC) {
       ivec * v = (ivec *)(data + g->nd);
       char s[20]; snprintf (s, 19, "{%d,%d}", v->x, v->y);
       fs = str_append_array (fs, (const char *[]){s, NULL});
     }
     else if (g->type == sym_function_declaration) {
       void * func = *((void **)(data + g->nd));
       if (!func)
  fs = str_append_array (fs, (const char *[]){"0", NULL});
       else {
  External * ptr = _get_function ((long) func);
  char s[20]; snprintf (s, 19, "%d", ptr->nd);
  fs = str_append_array (fs, (const char *[]){s, NULL});
       }
     }
     else if (g->type == sym_SCALAR)
       fs = write_scalar (fs, *((scalar *)(data + g->nd)));
     else if (g->type == sym_VECTOR)
       fs = write_vector (fs, *((vector *)(data + g->nd)));
     else if (g->type == sym_TENSOR)
       fs = write_tensor (fs, *((tensor *)(data + g->nd)));
     else
       fs = str_append_array (fs, (const char *[]){"not implemented", NULL});
   }
 fs = str_append_array (fs, (const char *[]){"}", NULL});
      }}}
    fs = str_append_array (fs, (const char *[]){"};\n", NULL});
  }




  if (GPUContext.nssbo > 1) {
    int imax = 1;
    {scalar*_i=(scalar*)( baseblock);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      if (_attribute[s.i].gpu.index && s.i + _attribute[s.i].block > imax)
 imax = s.i + _attribute[s.i].block;}}
    for (External * g = externals; g; g = g->next)
      if (g->reduct) {
 scalar s = g->s;
 if (s.i + _attribute[s.i].block > imax)
   imax = s.i + _attribute[s.i].block;
      }
    char string[100]; snprintf (string, 19, "%d", imax);
    fs = str_append_array (fs, (const char *[]){"const struct { uint i, j; } _offset[", string, "]={", NULL});
    for (int s = 0; s < imax; s++) {
      fs = str_append_array (fs, (const char *[]){s ? ",{" : "{", NULL});
      size_t offset = s*(((Multigrid *)grid)->shift[depth() + 1]), size = GPUContext.max_ssbo_size/sizeof(real);
      size_t i = offset/size, j = offset%size;
      snprintf (string, 99, "%ld,%ld", i, j);
      fs = str_append_array (fs, (const char *[]){string, "}", NULL});

      if (j + (((Multigrid *)grid)->shift[depth() + 1]) > 1L << 32) {
 fprintf (ferr, "%s:%d: error: resolution is too high for 32-bits indexing\n",
   "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h", 0);
 exit (1);
      }
    }
    fs = str_append_array (fs, (const char *[]){"};\n", NULL});
  }




  for (External * g = externals; g; g = g->next) {
    if (g->name[0] == '.') {
      if (g->type == sym_function_declaration) {
 bool boundary = is_boundary_attribute (g);
 fs = str_append_array (fs, (const char *[]){"#define _attr_", g->name + 1, "(s,args) (", NULL});
 do { for (khiter_t k = (khint_t)(0); k != ((_functions)->n_buckets); ++k) if ((!(((_functions)->flags[(k)>>4]>>(((k)&0xfU)<<1))&3))) { External * f = &((_functions)->vals[k]); f->used = false; } } while(0);
 char * expr = NULL;
 {scalar*_i=(scalar*)( baseblock);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
   if (_attribute[s.i].gpu.index) {
     char * data = (char *) &_attribute[s.i];
     void * func = *((void **)(data + g->nd));
     if (func) {
       External * f = _get_function ((long) func);
       if (!f->used && (!boundary || (_attribute[s.i].stencil.io & s_output))) {
  f->used = true;
  char * args = is_void_function (f->data) ? " args,0" : " args";
  if (!expr)
    expr = str_append_array (NULL, (const char *[]){"(", f->name, args, ")", NULL});
  else {
    char index[20];
    snprintf (index, 19, "%d", f->nd);
    char * s = str_append_array (NULL, (const char *[]){"_attr(s,", g->name + 1, ")==", index, "?(", f->name, args, "):", expr, NULL})
                                      ;
    sysfree (expr);
    expr = s;
  }
       }
     }
   }}}
 if (expr) {
   fs = str_append_array (fs, (const char *[]){expr, ")\n", NULL});
   sysfree (expr);
 }
 else
   fs = str_append_array (fs, (const char *[]){"0)\n", NULL});
      }
    }
    else if (g->type == sym_function_definition) {
      External * f = _get_function ((long) g->pointer);

      fs = str_append_array (fs, (const char *[]){"\n__device__ ", f->data, "\n", NULL});



      char s[20]; snprintf (s, 19, "%d", f->nd);
      fs = str_append_array (fs, (const char *[]){"const int _p", g->name, " = ", s, ";\n", NULL});
    }
    else if (g->type == sym_function_declaration) {
      External * f = _get_function ((long) g->pointer);
      char s[20]; snprintf (s, 19, "%d", f->nd);
      fs = str_append_array (fs, (const char *[]){"const int ", g->name, " = ", s, ";\n", "#define _f", g->name, "(args) (", f->name, " args)\n", NULL})
                                                                ;
    }
    else if (g->type != sym_SCALAR &&
      g->type != sym_VECTOR &&
      g->type != sym_TENSOR) {
      if (g->type == sym_INT && !strcmp (g->name, "N")) {
 int level = region->level > 0 ? region->level - 1 : depth();
 char s[20], d[20], l[20];
 snprintf (s, 19, "%d", Nl);
 snprintf (d, 19, "%d", depth());
 snprintf (l, 19, "%d", level);
 fs = str_append_array (fs, (const char *[]){"const uint N = ", s, ", _depth = ", d, ";\n", NULL})
                                                  ;
 if (GPUContext.nssbo <= 1) {
   char size[30];
   snprintf (size, 29, "%ld", (size_t) (((Multigrid *)grid)->shift[depth() + 1]));
   fs = str_append_array (fs, (const char *[]){"const uint _field_size = ", size, ";\n", NULL})
                                               ;
 }

 fs = str_append_array (fs, (const char *[]){"const uint _shift[_depth + 1] = {", NULL})
                                        ;
 for (int d = 0; d <= depth(); d++) {
   snprintf (s, 19, "%ld", (((Multigrid *)grid)->shift[d]));
   fs = str_append_array (fs, (const char *[]){d > 0 ? "," : "", s, NULL});
 }
 fs = str_append_array (fs, (const char *[]){"};\n", NULL});

        snprintf (s, 19, "%d", Dimensions.x);
        snprintf (d, 19, "%d", Dimensions.y);
 fs = str_append_array (fs, (const char *[]){"const ivec2 Dimensions = {", s, ",", d, "};\n" "const uint NY = N*", d, loop->face > 1 || loop->vertex ? "+1" : "", ";\n", NULL})



                                                                           ;
#line 1104 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
      }
      else if (g->type == sym_INT && !strcmp (g->name, "nl")) {




 char nl[20];
 snprintf (nl, 19, "%d", *((int *)g->pointer));
 fs = str_append_array (fs, (const char *[]){"const int nl = ", nl, ";\n", NULL});
      }
      else if (g->type == sym_INT && !strcmp (g->name, "bc_period_x"))
 fs = str_append_array (fs, (const char *[]){"const int bc_period_x = ", Period.x ? "int(N*Dimensions.x)" : "-1", ";\n", NULL})
                                        ;
      else if (g->type == sym_INT && !strcmp (g->name, "bc_period_y"))
 fs = str_append_array (fs, (const char *[]){"const int bc_period_y = ", Period.y ? "int(N*Dimensions.y)" : "-1", ";\n", NULL})
                                        ;
      else if (GPUContext.fragment_shader && (region->n.x > 1 || region->n.y > 1) &&
        g->type == sym_COORD && !strcmp (g->name, "p")) {





 fs = str_append_array (fs, (const char *[]){"coord p = vec3((vsPoint*vsScale + vsOrigin)*L0 + vec2(X0, Y0),0);\n", NULL});
      }
      else if (((g)->constant && (g)->type == sym_INT && !(g)->data)) {

 char value[20];
 if (!(g->pointer)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h", 0, "g->pointer");
 snprintf (value, 19, "%d", *((int *)g->pointer));
 fs = str_append_array (fs, (const char *[]){"const ", type_string (g), " ", (g)->global == 2 ? "_loc_" : "", (g)->name, (g)->reduct ? "_in_" : "", "=", value, ";\n", NULL});
      }
      else if (strcmp (g->name, "Dimensions")) {
 char * type = type_string (g);


 fs = str_append_array (fs, (const char *[]){"__device__ ", type, " ", (g)->global == 2 ? "_loc_" : "", (g)->name, (g)->reduct ? "_in_" : "", NULL});
 for (int * d = g->data; d && *d > 0; d++) {
   char s[20]; snprintf (s, 19, "%d", *d);
   fs = str_append_array (fs, (const char *[]){"[", s, "]", NULL});
 }
 fs = str_append_array (fs, (const char *[]){";\n", NULL});
#line 1154 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
      }
    }
    else {
      int size = list_size (g);
      for (int j = 0; j < size; j++) {
 if (j == 0) {
   fs = str_append_array (fs, (const char *[]){"const ", type_string (g), " ", (g)->global == 2 ? "_loc_" : "", (g)->name, (g)->reduct ? "_in_" : "", NULL});
   if (g->nd == 0)
     fs = str_append_array (fs, (const char *[]){" = ", NULL});
   else {
     char s[20]; snprintf (s, 19, "%d", size);
     fs = str_append_array (fs, (const char *[]){"[", s, "] = {", NULL});
   }
 }
 if (g->nd == 0 || j < size - 1) {
   if (g->type == sym_SCALAR)
     fs = write_scalar (fs, ((scalar *)g->pointer)[j]);
   else if (g->type == sym_VECTOR)
     fs = write_vector (fs, ((vector *)g->pointer)[j]);
   else if (g->type == sym_TENSOR)
     fs = write_tensor (fs, ((tensor *)g->pointer)[j]);
   else
     if (!(false)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h", 0, "false");
 }
 else {
   if (g->type == sym_SCALAR)
     fs = str_append_array (fs, (const char *[]){"{0,0}", NULL});
   else if (g->type == sym_VECTOR)
     fs = str_append_array (fs, (const char *[]){"{{0,0},{0,0}}", NULL});
   else if (g->type == sym_TENSOR)
     fs = str_append_array (fs, (const char *[]){"{{{0,0},{0,0}},{{0,0},{0,0}}}", NULL});
   else
     if (!(false)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h", 0, "false");
 }
 if (g->nd == 0)
   fs = str_append_array (fs, (const char *[]){";\n", NULL});
 else if (j < size - 1)
   fs = str_append_array (fs, (const char *[]){",", NULL});
 else
   fs = str_append_array (fs, (const char *[]){"};\n", NULL});
      }
    }
  }

  {end_tracing("build_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);return fs;}
end_tracing("build_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);}

     
Shader * load_shader (const char * fs, uint32_t hash, const ForeachData * loop)
{tracing("load_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);
  if (!(((GridGPU *)grid)->shaders)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h", 0, "gpu_grid->shaders");
  khiter_t k = kh_get_INT(((GridGPU *)grid)->shaders, hash);
  if (k != ((((GridGPU *)grid)->shaders)->n_buckets)) {
    sysfree ((void *)fs);
    { Shader  * _ret= ((((GridGPU *)grid)->shaders)->vals[k]);end_tracing("load_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);return _ret;}
  }
#line 1218 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
  Shader * shader;
  if (loop && loop->func) {
    char func[strlen(loop->func) + 20];
    sprintf (func, "%s_%d", loop->func, loop->line);
    shader = load_normal_shader (fs, func, loop->fname, loop->line);
  }
  else
    shader = load_normal_shader (fs, __func__, "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h", 0);
  if (shader) {
    int ret;
    khiter_t k = kh_put_INT(((GridGPU *)grid)->shaders, hash, &ret);
    if (!(ret > 0)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h", 0, "ret > 0");
    ((((GridGPU *)grid)->shaders)->vals[k]) = shader;
  }
  sysfree ((void *)fs);
  {end_tracing("load_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);return shader;}
end_tracing("load_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);}

void gpu_free()
{
  if (!grid)
    return;
  free_boundaries();
  if (((GridGPU *)grid)->shaders) {
    Shader * shader;
    int nshaders = 0;
    { khint_t __i; for (__i = (khint_t)(0); __i != ((((GridGPU *)grid)->shaders)->n_buckets); ++__i) { if (!(!(((((GridGPU *)grid)->shaders)->flags[(__i)>>4]>>(((__i)&0xfU)<<1))&3))) continue; (shader) = ((((GridGPU *)grid)->shaders)->vals[__i]); free_shader (shader); nshaders++;; } }

                                   ;



    kh_destroy_INT(((GridGPU *)grid)->shaders);
    ((GridGPU *)grid)->shaders = NULL;
    gpu_free_context (((GridGPU *)grid)->data);
    ((GridGPU *)grid)->data = NULL;
  }
}

void gpu_free_grid (void)
{
  if (!grid)
    return;
  gpu_free();
  free_grid();
}


#line 1280 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"








     
void reset_gpu (void * alist, double val)
{tracing("reset_gpu","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);
  scalar * list = alist;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!is_constant(s)) {
      reset_scalar (s.i, _attribute[s.i].block, (((Multigrid *)grid)->shift[depth() + 1]), val);
      _attribute[s.i].gpu.stored = -1;
    }}}
end_tracing("reset_gpu","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);}

void gpu_init_grid (int n)
{
  if (grid && n == N)
    return;
  gpu_free_grid();
  init_grid (n);
  grid = prealloc (grid, sizeof (GridGPU),__func__,__FILE__,0);

  disable_fpe (FE_DIVBYZERO|FE_INVALID);
  if (gpu_init_context (&((GridGPU *)grid)->data)) {
    free_solver_func_add (gpu_free);
    free_solver_func_add (gpu_free_solver);
  }
  ((GridGPU *)grid)->shaders = kh_init_INT();
  realloc_ssbo ((((Multigrid *)grid)->shift[depth() + 1]));
}







static External * append_external (External * externals, External ** end, External * g)
{
  if (externals)
    (*end)->next = g;
  else
    externals = g;
  *end = g;
  (*end)->next = NULL;
  return externals;
}

static External * merge_external (External * externals, External ** end, External * g,
      const ForeachData * loop)
{
  if (g->type == sym_function_declaration || g->type == sym_function_definition) {
    bool boundary = is_boundary_attribute (g);
    {scalar*_i=(scalar*)( baseblock);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      if (g->name[0] != '.' || (!boundary && _attribute[s.i].gpu.index) ||
          (boundary && (_attribute[s.i].stencil.io & s_output))) {
 void * ptr = g->name[0] != '.' ? g->pointer :
   *((void **)(((char *) &_attribute[s.i]) + g->nd));
 if (ptr) {
   External * p = _get_function ((long) ptr);
   if (!p) {
     fprintf (ferr, "%s:%d: GLSL: error: unregistered function pointer '%s'\n",
       loop->fname, loop->line, g->name);
     return NULL;
   }
   if (!p->used) {
     p->used = true;
     for (External * i = p->externals; i && i->name; i++)
       externals = merge_external (externals, end, i, loop);
     externals = append_external (externals, end, p);
   }
 }
 if (g->name[0] != '.')
     break;
      }}}
  }
  for (External * i = externals; i; i = i->next)
    if (!strcmp (g->name, i->name)) {





      if (g->global == 0 && i->global == 1) g->global = 2;
      else if (g->global == 1 && i->global == 0) i->global = 2;
      else
 return externals;
    }
  return append_external (externals, end, g);
}

static External * merge_externals (External * externals, const ForeachData * loop)
{
  External * merged = NULL, * end = NULL;
  static External ext[] = {
    { .name = "X0", .type = sym_DOUBLE, .pointer = &X0, .global = 1 },
    { .name = "Y0", .type = sym_DOUBLE, .pointer = &Y0, .global = 1 },
    { .name = "Z0", .type = sym_DOUBLE, .pointer = &Z0, .global = 1 },
    { .name = "L0", .type = sym_DOUBLE, .pointer = &L0, .global = 1 },
    { .name = "N", .type = sym_INT, .pointer = &N, .global = 1 },





    { .name = NULL }
  };
  static External bc = {
    .name = "apply_bc", .type = sym_function_declaration, .pointer = (void *)(long)apply_bc
  };

  for (External * g = externals; g->name; g++) {
    g->used = false;
    if (g->global == 2) g->global = 0;
  }
  do { for (khiter_t k = (khint_t)(0); k != ((_functions)->n_buckets); ++k) if ((!(((_functions)->flags[(k)>>4]>>(((k)&0xfU)<<1))&3))) { External * f = &((_functions)->vals[k]); f->used = false; } } while(0);
  for (External * g = ext; g->name; g++) {
    g->used = false;
    merged = merge_external (merged, &end, g, loop);
  }
  if (loop->dirty) {
    bc.used = false;
    merged = merge_external (merged, &end, &bc, loop);
  }
  for (External * g = externals; g->name; g++)
    merged = merge_external (merged, &end, g, loop);




  if (loop->dirty)
    for (External * g = merged; g; g = g->next)
      if (g->global && !strcmp (g->name, "apply_bc_list"))
 g->pointer = loop->dirty;
  return merged;
}

static char * shader_append_func (char * s, const ForeachData * loop)
{

  char func[strlen(loop->func) + 20];
  sprintf (func, "%s_%d", loop->func, loop->line);



  return str_append_array (s, (const char *[]){"extern \"C\" __global__\n" "void ", func, "(float* /*unused*/) {\n", NULL})

                                                              ;
#line 1441 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
}

     
static Shader * compile_shader (ForeachData * loop,
    uint32_t hash,
    const RegionParameters * region,
    External * externals,
    const char * kernel)
{tracing("compile_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);
  const char * error = strstr (kernel, "@error ");
  if (error) {
    for (const char * s = error + 7; *s != '\n' && *s != '\0'; s++)
      fputc (*s, ferr);
    fputc ('\n', ferr);
    loop->data = NULL;
    {end_tracing("compile_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);return NULL;}
  }

  External * merged = merge_externals (externals, loop);
  if (!merged) {
    loop->data = NULL;
    {end_tracing("compile_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);return NULL;}
  }

  int local = false;
  for (const External * g = merged; g; g = g->next) {
    if (g->global == 2)
      local = true;
    if (g->type != sym_SCALAR && g->type != sym_VECTOR && g->type != sym_TENSOR) {
      if (g->reduct && !strchr ("+mM", g->reduct)) {
 if (loop->first)
   fprintf (ferr,
     "%s:%d: GLSL: error: unknown reduction operation '%c'\n",
     loop->fname, loop->line, g->reduct);
 {end_tracing("compile_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);return NULL;}
      }
      if (g->type == sym_COORD || g->type == sym__COORD || g->type == sym_VEC4) {
 if (g->reduct) {
   if (loop->first)
     fprintf (ferr,
       "%s:%d: GLSL: error: reductions not implemented for '%s' type\n",
       loop->fname, loop->line, type_string (g));
   {end_tracing("compile_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);return NULL;}
 }
      }
      else if (g->type != sym_FLOAT &&
        g->type != sym_DOUBLE &&
        g->type != sym_INT &&
        g->type != sym_LONG &&
        g->type != sym_BOOL &&
        g->type != sym_enumeration_constant &&
        g->type != sym_IVEC &&
        g->type != sym_function_declaration &&
        g->type != sym_function_definition) {
 if (loop->first)
   fprintf (ferr, "%s:%d: GLSL: error: unknown type %d for '%s'\n",
     loop->fname, loop->line, g->type, g->name);
 {end_tracing("compile_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);return NULL;}
      }
    }
  }




  static const int NWG[2] = {16, 16};
  unsigned ng[2], nwg[2];
  int Nl = region->level > 0 ? 1 << (region->level - 1) : N/Dimensions.x;
  int * dims = &Dimensions.x;
  if (loop->face || loop->vertex)
    for (int i = 0; i < 2; i++) {
      if (Nl*dims[1-i] > NWG[i]) {
 nwg[i] = NWG[i] + 1;
 ng[i] = Nl*dims[1-i]/NWG[i];
      }
      else {
 nwg[i] = Nl*dims[1-i] + 1;
 ng[i] = 1;
      }
      if (!(nwg[i]*ng[i] >= Nl*dims[1-i] + 1)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h", 0, "nwg[i]*ng[i] >= Nl*dims[1-i] + 1");
    }
  else
    for (int i = 0; i < 2; i++) {
      nwg[i] = Nl < NWG[i] ? Nl : NWG[i];
      ng[i] = Nl*dims[1-i]/nwg[i];
      if (!(nwg[i]*ng[i] == Nl*dims[1-i])) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h", 0, "nwg[i]*ng[i] == Nl*dims[1-i]");
    }

  char * shader = build_shader (merged, loop, region, nwg);
  if (!shader)
    {end_tracing("compile_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);return NULL;}




  if (local) {
    shader = str_append_array (shader, (const char *[]){"void _loop (", NULL});
    for (const External * g = merged; g; g = g->next)
      if (g->global == 2) {
 shader = str_append_array (shader, (const char *[]){local++ == 1 ? "" : ", ", type_string (g), " ", g->name, NULL});
 if (g->nd) {
   int size = list_size (g);
   if (size > 0) {
     char s[20]; snprintf (s, 19, "%d", size);
     shader = str_append_array (shader, (const char *[]){"[", s, "]", NULL});
   }
 }
      }
    shader = str_append_array (shader, (const char *[]){") {\n", NULL});
  }
  else
    shader = shader_append_func (shader, loop);

  if (!GPUContext.fragment_shader) {
    char d[20];
    snprintf (d, 19, "%d", region->level > 0 ? region->level - 1 : depth());
    shader = str_append_array (shader, (const char *[]){"Point point = {csOrigin.x + int(blockIdx.y * blockDim.y + threadIdx.y) + GHOSTS," "csOrigin.y + int(blockIdx.x * blockDim.x + threadIdx.x) + GHOSTS,", d, ",{(1<<",d,")*Dimensions.x,(1<<",d,")*Dimensions.y}" "};\n", NULL})
#line 1581 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
     ;
  }
  shader = str_append_array (shader, (const char *[]){"if (point.i < N*Dimensions.x + 2*GHOSTS && " "point.j < N*Dimensions.y + 2*GHOSTS) {\n", NULL})

                                                    ;
  if (loop->vertex)
    shader = str_append_array (shader, (const char *[]){"  int ig = -1, jg = -1;\n", NULL});

  for (const External * g = merged; g; g = g->next)
    if (g->reduct) {
      shader = str_append_array (shader, (const char *[]){type_string (g), " ", g->global == 2 ? "_loc_" : "", g->name, " = ", (g)->global == 2 ? "_loc_" : "", (g)->name, (g)->reduct ? "_in_" : "", ";\n", NULL})

                                                    ;
      shader = str_append_array (shader, (const char *[]){"const scalar ", g->name, "_out_ = ", NULL});
      shader = write_scalar (shader, g->s);
      shader = str_append_array (shader, (const char *[]){";\n", NULL});
    }


  shader = str_append_array (shader, (const char *[]){kernel, NULL});
  shader = str_append_array (shader, (const char *[]){"\nif (point.j - GHOSTS < NY) {", NULL});
  for (const External * g = merged; g; g = g->next)
    if (g->reduct) {
      shader = str_append_array (shader, (const char *[]){"\n  val_red_(", g->name, "_out_) = ", g->name, ";", NULL});
      scalar s = g->s;
      _attribute[s.i].gpu.stored = -1;
    }
  shader = str_append_array (shader, (const char *[]){"\n}", loop->dirty ? "apply_bc(point);" : "", "}}\n", NULL})

                ;

  if (local) {
    shader = shader_append_func (shader, loop);
    shader = str_append_array (shader, (const char *[]){"_loop(", NULL});
    local = 1;
    for (const External * g = merged; g; g = g->next)
      if (g->global == 2)
 shader = str_append_array (shader, (const char *[]){local++ == 1 ? "" : ",", (g)->global == 2 ? "_loc_" : "", (g)->name, (g)->reduct ? "_in_" : "", NULL});
    shader = str_append_array (shader, (const char *[]){");}\n", NULL});
  }

  Shader * s = load_shader (shader, hash, loop);
  loop->data = s;
  if (!s)
    {end_tracing("compile_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);return NULL;}

  finalize_shader (s, externals, merged, ng, nwg);

  {end_tracing("compile_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);return s;}
end_tracing("compile_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);}

static
void free_reduction_fields (const External * externals)
{
  for (const External * g = externals; g; g = g->next)
    if (g->reduct) {
      scalar s = g->s;
      delete (((scalar[]){s,{-1}}));
    }
}

     
static void gpu_cpu_sync (scalar * list, SyncMode mode, const char * fname, int line)
{tracing("gpu_cpu_sync","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);



  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (((_attribute[s.i].stencil.io & s_input) || (_attribute[s.i].stencil.io & s_output)) &&
        ((mode == GPU_READ && _attribute[s.i].gpu.stored < 0) ||
         (mode == GPU_WRITE && _attribute[s.i].gpu.stored > 0))) {
      if (_attribute[s.i].gpu.stored > 0 && !(_attribute[s.i].stencil.bc & s_centered))
        boundary_internal ((scalar *)((scalar[]){s,{-1}}), "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h", 0);
#line 1667 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
      gpu_cpu_sync_scalar (s.i, _attribute[s.i].block, (((Multigrid *)grid)->d), (((Multigrid *)grid)->shift[depth() + 1]), mode);

      _attribute[s.i].gpu.stored = 0;
    }}}




end_tracing("gpu_cpu_sync","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);}

     
static Shader * setup_shader (ForeachData * loop, const RegionParameters * region,
         External * externals,
         const char * kernel)
{tracing("setup_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);




  apply_bc_list = loop->dirty;
  {scalar*_i=(scalar*)( loop->dirty);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {





    for (int b = 0; b < nboundary; b++)
      if (_attribute[s.i].boundary_stencil[b])
        _attribute[s.i].boundary_stencil[b] ((Point){0}, (Point){0}, s, NULL);




    if (!(_attribute[s.i].stencil.io & s_output))
      _attribute[s.i].stencil.io |= s_output;
  }}}

  {scalar*_i=(scalar*)( baseblock);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    _attribute[s.i].gpu.index = 0;}}
  int index = 1;
  {scalar*_i=(scalar*)( baseblock);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (((_attribute[s.i].stencil.io & s_input) || (_attribute[s.i].stencil.io & s_output)) && !_attribute[s.i].gpu.index) {






      if (_attribute[s.i].v.x.i == -1)
 _attribute[s.i].gpu.index = index++;
      else {
 vector v = _attribute[s.i].v;
 {scalar*_i=(scalar*)(((vector[]) {v,{{-1},{-1}}}));if(_i)for(scalar c=*_i;(&c)->i>=0;c=*++_i){
   if (!_attribute[c.i].gpu.index)
     _attribute[c.i].gpu.index = index++;}}
      }
    }}}
  {scalar*_i=(scalar*)( loop->dirty);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {







    _attribute[s.i].boundary_left = _attribute[s.i].boundary[left];
    _attribute[s.i].boundary_right = _attribute[s.i].boundary[right];
    _attribute[s.i].boundary_top = _attribute[s.i].boundary[top];
    _attribute[s.i].boundary_bottom = _attribute[s.i].boundary[bottom];
  }}}




  for (External * g = externals; g && g->name; g++)
    if (g->reduct) {
      scalar s = new_scalar("s");
      _attribute[s.i].stencil.io |= s_output;
      g->s = s;




    }




  Shader * shader;
  uint32_t hash = hash_shader (externals, loop, region, kernel);
  if (!(((GridGPU *)grid)->shaders)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h", 0, "gpu_grid->shaders");
  khiter_t k = kh_get_INT(((GridGPU *)grid)->shaders, hash);
  if (k != ((((GridGPU *)grid)->shaders)->n_buckets))
    shader = ((((GridGPU *)grid)->shaders)->vals[k]);
  else {
    shader = compile_shader (loop, hash, region, externals, kernel);
    if (!shader) {
      free_reduction_fields (externals);
      {end_tracing("setup_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);return NULL;}
    }
  }

  gpu_cpu_sync (baseblock, GPU_WRITE, loop->fname, loop->line);







  scalar * listc = NULL;
  {scalar*_i=(scalar*)( loop->listc);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!(_attribute[s.i].stencil.bc & s_centered))
      listc = list_prepend (listc, s);}}
  scalar * listf_x = NULL, * listf_y = NULL;
  
    {scalar*_i=(scalar*)( loop->listf.x);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      if (!(_attribute[s.i].stencil.bc & s_face))
 listf_x = list_prepend (listf_x, s);}}    
#line 1783
{scalar*_i=(scalar*)( loop->listf.y);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      if (!(_attribute[s.i].stencil.bc & s_face))
 listf_y = list_prepend (listf_y, s);}}
  if (listc || listf_x || listf_y) {
#line 1796 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
    int nvar = datasize/sizeof(real);
    _Attributes backup[nvar];
    memcpy (backup, _attribute, nvar*sizeof(_Attributes));    
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 3;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 1799 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
{
      {scalar*_i=(scalar*)( listc);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
 { _stencil_val(s,0,0,0);_stencil_val_a(s,0,0,0); }}}
      
 {scalar*_i=(scalar*)( listf_x);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
   { _stencil_val(s,0,0,0);_stencil_val_a(s,0,0,0); }}} 
#line 1803
{scalar*_i=(scalar*)( listf_y);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
   { _stencil_val(s,0,0,0);_stencil_val_a(s,0,0,0); }}}
    }
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 1799 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="listc",.type=sym_SCALAR,.pointer=(void *)listc,.nd=1},{.name="listf_x",.type=sym_SCALAR,.pointer=(void *)listf_x,.nd=1},{.name="listf_y",.type=sym_SCALAR,.pointer=(void *)listf_y,.nd=1},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), " \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h\"\n{\n      {forin (scalar, s , listc)\n val_out_(s,0,0,0) = val(s,0,0,0); endforin()}\n      \n {forin (scalar, s , listf_x)\n   val_out_(s,0,0,0) = val(s,0,0,0); endforin()}\n {\n// #line 0\nforin (scalar, s , listf_y)\n   val_out_(s,0,0,0) = val(s,0,0,0); endforin()}\n    }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }
    
#line 1806 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h"
memcpy (_attribute, backup, nvar*sizeof(_Attributes));
    {scalar*_i=(scalar*)( listc);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
      _attribute[s.i].stencil.bc |= s_centered;
      _attribute[s.i].gpu.stored = -1;
    }}}
    pfree (listc,__func__,__FILE__,0);
     {
      {scalar*_i=(scalar*)( listf_x);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
        _attribute[s.i].stencil.bc |= s_face;
 _attribute[s.i].gpu.stored = -1;
      }}}
      pfree (listf_x,__func__,__FILE__,0);
    } 
#line 1812
{
      {scalar*_i=(scalar*)( listf_y);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
        _attribute[s.i].stencil.bc |= s_face;
 _attribute[s.i].gpu.stored = -1;
      }}}
      pfree (listf_y,__func__,__FILE__,0);
    }
    apply_bc_list = loop->dirty;
  }

  post_setup_shader (shader, externals);

  {end_tracing("setup_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);return shader;}
end_tracing("setup_shader","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h",0);}

static bool doloop_on_gpu (ForeachData * loop, const RegionParameters * region,
      External * externals,
      const char * kernel)
{
  Shader * shader = setup_shader (loop, region, externals, kernel);
  if (!shader)
    return false;




  int Nl = run_shader (shader, region);




  bool nreductions = false;
  for (const External * g = externals; g && g->name; g++)
    if (g->reduct) {
      nreductions = true;
      break;
    }
  if (nreductions)
    tracing ("gpu_reduction", loop->fname, loop->line);
  for (const External * g = externals; g && g->name; g++)
    if (g->reduct) {
      scalar s = g->s;
      double result = gpu_reduction (((((Multigrid *)grid)->shift[(region->level) ? (region->level) - 1 : depth()]) + (s).i*(((Multigrid *)grid)->shift[depth() + 1])), g->reduct, region,
                                     ((GridGPU *)grid)->data,
         loop->face == 1 ? (Nl*Dimensions.x + 1)*Nl*Dimensions.y :
         loop->face == 2 ? Nl*Dimensions.x*(Nl*Dimensions.y + 1) :
         loop->face == 3 || loop->vertex ?
         (Nl*Dimensions.x + 1)*(Nl*Dimensions.y + 1) :
         ( Nl*Nl)*Dimensions.x*Dimensions.y);




      if (g->type == sym_DOUBLE) *((double *)g->pointer) = result;
      else if (g->type == sym_FLOAT) *((float *)g->pointer) = result;
      else if (g->type == sym_INT) *((int *)g->pointer) = result;
      else
 if (!(false)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h", 0, "false");
      delete (((scalar[]){s,{-1}}));
    }
  if (nreductions)
    end_tracing ("gpu_reduction", loop->fname, loop->line);

  return true;
}

bool gpu_end_stencil (ForeachData * loop,
        const RegionParameters * region,
        External * externals,
        const char * kernel)
{
  bool on_gpu = ((loop->parallel == 1 && !on_cpu) || loop->parallel == 3) &&
    (loop->first || loop->data);
  if (on_gpu) {
    on_gpu = doloop_on_gpu (loop, region, externals, kernel);
    if (!on_gpu) {
      fprintf (ferr, "%s:%d: %s: foreach() done on CPU (see GLSL errors above)\n",
        loop->fname, loop->line, loop->parallel == 3 ? "error" : "warning");
      if (loop->parallel == 3)
 exit (1);
      loop->data = NULL;
    }
  }
  if (on_gpu) {

    pfree (loop->listc,__func__,__FILE__,0), loop->listc = NULL;
    
      pfree (loop->listf.x,__func__,__FILE__,0), loop->listf.x = NULL;      pfree (loop->listf.y,__func__,__FILE__,0), loop->listf.y = NULL;
    {scalar*_i=(scalar*)( loop->dirty);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      _attribute[s.i].stencil.bc = s_centered|s_face;}}
    pfree (loop->dirty,__func__,__FILE__,0), loop->dirty = NULL;
  }
  else {
    gpu_cpu_sync (baseblock, GPU_READ, loop->fname, loop->line);
    boundary_stencil (loop);
  }

  {scalar*_i=(scalar*)( baseblock);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (_attribute[s.i].stencil.io & s_output)
      _attribute[s.i].gpu.stored = on_gpu ? -1 : 1;}}

  return on_gpu && loop->parallel != 3;
}
#line 54 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu-multigrid.h"
#line 5 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/multigrid.h"







static void hip_multigrid_methods()
{
  multigrid_methods();
  boundary_level = gpu_boundary_level;
}
#line 15 "turbulence-cpp.c"
#line 1 "turbulence.c"
#line 13 "turbulence.c"
#line 1 "navier-stokes/stream.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
#line 28 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
#line 1 "./advection.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/advection.h"
#line 17 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/advection.h"
#line 1 "./run.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/run.h"
#line 9 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/run.h"
double dt = 1.;

#line 1 "./utils.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"







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
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
n++;}
      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{mpi_sum_reduce_array(mpi_n,&n,MPI_DOUBLE,MPI_SUM,1);}
    s.tnc = n;
    tnc = n*i;
  }
  else
    s.tnc = tnc;





  s.mem = 0;
#line 99 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
  s.min = s.max = s.avg = 0.;

  s.speed = s.real > 0. ? tnc/s.real : -1.;
  return s;
}




void timer_print (timer t, int i, size_t tnc)
{
  gpu_synchronize();
  timing s = timer_timing (t, i, tnc, NULL);
  fprintf (fout,
    "\n# " "Multigrid (hip)"
    ", %d steps, %g CPU, %.4g real, %.3g points.step/s, %d var\n",
    i, s.cpu, s.real, s.speed, (int) (datasize/sizeof(real)));
#line 125 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
  fflush (fout);
}







typedef struct {
  double avg, rms, max, volume;
} norm;

norm normf (scalar f)
{
  double avg = 0., rms = 0., max = 0., volume = 0.;
  if(!is_constant(cm)){  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
    
#line 143 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{_stencil_val(f,0,0,0);_stencil_val(cm,0,0,0); {   
      _stencil_val(f,0,0,0);   
         
_stencil_val(cm,0,0,0); 
        _stencil_val(cm,0,0,0); 
        _stencil_val(cm,0,0,0);    
}        }
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 141 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="f",.type=sym_SCALAR,.pointer=(void *)&f},{.name="cm",.type=sym_SCALAR,.global=1,.pointer=(void *)&cm},{.name="max",.type=49,.pointer=(void *)&max,.reduct='M'},{.name="volume",.type=49,.pointer=(void *)&volume,.reduct='+'},{.name="avg",.type=49,.pointer=(void *)&avg,.reduct='+'},{.name="rms",.type=49,.pointer=(void *)&rms,.reduct='+'},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\nif (val(f,0,0,0) != 1e30f && (( Delta*Delta)*val(cm,0,0,0)) > 0.f) {\n      real v = fabs(val(f,0,0,0));\n      if (v > max) max = v;\n      volume += (( Delta*Delta)*val(cm,0,0,0));\n      avg += (( Delta*Delta)*val(cm,0,0,0))*v;\n      rms += (( Delta*Delta)*val(cm,0,0,0))*( v*v);\n    }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }
#line 141 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
mpi_sum_reduce_init(mpi_volume,&volume,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_rms,&rms,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_avg,&avg,MPI_DOUBLE,MPI_SUM,1);  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 143 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 143 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
if (val(f,0,0,0) != 1e30f && (( Delta*Delta)*val(cm,0,0,0)) > 0.) {
      double v = fabs(val(f,0,0,0));
      if (v > max) max = v;
      volume += (( Delta*Delta)*val(cm,0,0,0));
      avg += (( Delta*Delta)*val(cm,0,0,0))*v;
      rms += (( Delta*Delta)*val(cm,0,0,0))*( v*v);
    }}
      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 149 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{mpi_sum_reduce_array(mpi_volume,&volume,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_rms,&rms,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_avg,&avg,MPI_DOUBLE,MPI_SUM,1);mpi_all_reduce_array(&max,MPI_DOUBLE,MPI_MAX,1);}}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
    
#line 143 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{_stencil_val(f,0,0,0);; {   
      _stencil_val(f,0,0,0);

;
;
;    
}        }
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 141 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="f",.type=sym_SCALAR,.pointer=(void *)&f},{.name="_const_cm",.type=49,.pointer=(void *)&_const_cm},{.name="max",.type=49,.pointer=(void *)&max,.reduct='M'},{.name="volume",.type=49,.pointer=(void *)&volume,.reduct='+'},{.name="avg",.type=49,.pointer=(void *)&avg,.reduct='+'},{.name="rms",.type=49,.pointer=(void *)&rms,.reduct='+'},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\nif (val(f,0,0,0) != 1e30f && (( Delta*Delta)*_const_cm) > 0.f) {\n      real v = fabs(val(f,0,0,0));\n      if (v > max) max = v;\n      volume += (( Delta*Delta)*_const_cm);\n      avg += (( Delta*Delta)*_const_cm)*v;\n      rms += (( Delta*Delta)*_const_cm)*( v*v);\n    }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }
#line 141 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
mpi_sum_reduce_init(mpi_volume,&volume,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_rms,&rms,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_avg,&avg,MPI_DOUBLE,MPI_SUM,1);  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 143 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 143 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
if (val(f,0,0,0) != 1e30f && (( Delta*Delta)*_const_cm) > 0.) {
      double v = fabs(val(f,0,0,0));
      if (v > max) max = v;
      volume += (( Delta*Delta)*_const_cm);
      avg += (( Delta*Delta)*_const_cm)*v;
      rms += (( Delta*Delta)*_const_cm)*( v*v);
    }}
      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 149 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
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
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
    
#line 171 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{_stencil_val(cm,0,0,0); _stencil_val(f,0,0,0); {
_stencil_val(cm,0,0,0); 
        _stencil_val(cm,0,0,0);_stencil_val(f,0,0,0); 
        _stencil_val(cm,0,0,0);_stencil_val(f,0,0,0);_stencil_val(f,0,0,0); 
         _stencil_val(f,0,0,0); { _stencil_val(f,0,0,0); }
_stencil_val(f,0,0,0); { _stencil_val(f,0,0,0); }    
}       }
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 169 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="cm",.type=sym_SCALAR,.global=1,.pointer=(void *)&cm},{.name="f",.type=sym_SCALAR,.pointer=(void *)&f},{.name="volume",.type=49,.pointer=(void *)&volume,.reduct='+'},{.name="sum",.type=49,.pointer=(void *)&sum,.reduct='+'},{.name="sum2",.type=49,.pointer=(void *)&sum2,.reduct='+'},{.name="max",.type=49,.pointer=(void *)&max,.reduct='M'},{.name="min",.type=49,.pointer=(void *)&min,.reduct='m'},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\nif ((( Delta*Delta)*val(cm,0,0,0)) > 0.f && val(f,0,0,0) != 1e30f) {\n      volume += (( Delta*Delta)*val(cm,0,0,0));\n      sum += (( Delta*Delta)*val(cm,0,0,0))*val(f,0,0,0);\n      sum2 += (( Delta*Delta)*val(cm,0,0,0))*( (val(f,0,0,0))*(val(f,0,0,0)));\n      if (val(f,0,0,0) > max) max = val(f,0,0,0);\n      if (val(f,0,0,0) < min) min = val(f,0,0,0);\n    }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }
#line 169 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
mpi_sum_reduce_init(mpi_volume,&volume,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_sum2,&sum2,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_sum,&sum,MPI_DOUBLE,MPI_SUM,1);  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 171 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 171 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
if ((( Delta*Delta)*val(cm,0,0,0)) > 0. && val(f,0,0,0) != 1e30f) {
      volume += (( Delta*Delta)*val(cm,0,0,0));
      sum += (( Delta*Delta)*val(cm,0,0,0))*val(f,0,0,0);
      sum2 += (( Delta*Delta)*val(cm,0,0,0))*( (val(f,0,0,0))*(val(f,0,0,0)));
      if (val(f,0,0,0) > max) max = val(f,0,0,0);
      if (val(f,0,0,0) < min) min = val(f,0,0,0);
    }}
      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 177 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{mpi_all_reduce_array(&min,MPI_DOUBLE,MPI_MIN,1);mpi_all_reduce_array(&max,MPI_DOUBLE,MPI_MAX,1);mpi_sum_reduce_array(mpi_volume,&volume,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_sum2,&sum2,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_sum,&sum,MPI_DOUBLE,MPI_SUM,1);}}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
    
#line 171 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{; _stencil_val(f,0,0,0); {
;
;_stencil_val(f,0,0,0);
;_stencil_val(f,0,0,0);_stencil_val(f,0,0,0); 
         _stencil_val(f,0,0,0); { _stencil_val(f,0,0,0); }
_stencil_val(f,0,0,0); { _stencil_val(f,0,0,0); }    
}       }
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 169 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="_const_cm",.type=49,.pointer=(void *)&_const_cm},{.name="f",.type=sym_SCALAR,.pointer=(void *)&f},{.name="volume",.type=49,.pointer=(void *)&volume,.reduct='+'},{.name="sum",.type=49,.pointer=(void *)&sum,.reduct='+'},{.name="sum2",.type=49,.pointer=(void *)&sum2,.reduct='+'},{.name="max",.type=49,.pointer=(void *)&max,.reduct='M'},{.name="min",.type=49,.pointer=(void *)&min,.reduct='m'},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\nif ((( Delta*Delta)*_const_cm) > 0.f && val(f,0,0,0) != 1e30f) {\n      volume += (( Delta*Delta)*_const_cm);\n      sum += (( Delta*Delta)*_const_cm)*val(f,0,0,0);\n      sum2 += (( Delta*Delta)*_const_cm)*( (val(f,0,0,0))*(val(f,0,0,0)));\n      if (val(f,0,0,0) > max) max = val(f,0,0,0);\n      if (val(f,0,0,0) < min) min = val(f,0,0,0);\n    }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }
#line 169 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
mpi_sum_reduce_init(mpi_volume,&volume,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_sum2,&sum2,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_init(mpi_sum,&sum,MPI_DOUBLE,MPI_SUM,1);  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 171 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 171 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
if ((( Delta*Delta)*_const_cm) > 0. && val(f,0,0,0) != 1e30f) {
      volume += (( Delta*Delta)*_const_cm);
      sum += (( Delta*Delta)*_const_cm)*val(f,0,0,0);
      sum2 += (( Delta*Delta)*_const_cm)*( (val(f,0,0,0))*(val(f,0,0,0)));
      if (val(f,0,0,0) > max) max = val(f,0,0,0);
      if (val(f,0,0,0) < min) min = val(f,0,0,0);
    }}
      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 177 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{mpi_all_reduce_array(&min,MPI_DOUBLE,MPI_MIN,1);mpi_all_reduce_array(&max,MPI_DOUBLE,MPI_MAX,1);mpi_sum_reduce_array(mpi_volume,&volume,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_sum2,&sum2,MPI_DOUBLE,MPI_SUM,1);mpi_sum_reduce_array(mpi_sum,&sum,MPI_DOUBLE,MPI_SUM,1);}}
  stats s;
  s.min = min, s.max = max, s.sum = sum, s.volume = volume;
  if (volume > 0.)
    sum2 -= sum*sum/volume;
  s.stddev = sum2 > 0. ? sqrt(sum2/volume) : 0.;
  return s;
}
#line 193 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
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
#line 219 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
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
#line 243 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
void gradients (scalar * f, vector * g)
{
  if (!(list_len(f) == vectors_len(g))) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h", 0, "list_len(f) == vectors_len(g)");  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 246 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{
    scalar s; vector v;
    {vector*_i0=g;scalar*_i1= f;if(_i0)for(v=*_i0,s=*_i1;_i0->x.i>= 0;v=*++_i0,s=*++_i1){ {
      if (_attribute[s.i].gradient)
 { {





_stencil_val(s,-1,0,0); _stencil_val(s,0,0,0); _stencil_val(s,1,0,0);     _stencil_val_a(v.x,0,0,0);   
 } 
#line 250
{





_stencil_val(s,0,-1,0); _stencil_val(s,0,0,0); _stencil_val(s,0,1,0);     _stencil_val_a(v.y,0,0,0);   
 }}
      else
 { {





_stencil_val(s,1,0,0); _stencil_val(s,-1,0,0);     _stencil_val_a(v.x,0,0,0);   
 } 
#line 259
{





_stencil_val(s,0,1,0); _stencil_val(s,0,-1,0);     _stencil_val_a(v.y,0,0,0);   
 }}
    }}}
  }
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 246 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
(External[]){{.name=".gradient",.type=sym_function_declaration,.nd=attroffset(gradient)},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="f",.type=sym_SCALAR,.pointer=(void *)f,.nd=1},{.name="g",.type=sym_VECTOR,.pointer=(void *)g,.nd=1},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), " \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\n{\n    scalar s; vector v;\n    {forin2 (s,v , f,g) {\n      if (bool(_attr(s,gradient)))\n { {\n\n\n\n\n\n     val_out_(v.x,0,0,0) = _attr_gradient(s, (val(s,-1,0,0), val(s,0,0,0), val(s,1,0,0)))/Delta;\n } \n// #line 0\n{\n\n\n\n\n\n     val_out_(v.y,0,0,0) = _attr_gradient(s, (val(s,0,-1,0), val(s,0,0,0), val(s,0,1,0)))/Delta;\n }}\n      else\n { {\n\n\n\n\n\n     val_out_(v.x,0,0,0) = (val(s,1,0,0) - val(s,-1,0,0))/(2.f*Delta);\n } \n// #line 0\n{\n\n\n\n\n\n     val_out_(v.y,0,0,0) = (val(s,0,1,0) - val(s,0,-1,0))/(2.f*Delta);\n }}\n    } endforin2()}\n  }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 246 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 246 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{
    scalar s; vector v;
    {vector*_i0=g;scalar*_i1= f;if(_i0)for(v=*_i0,s=*_i1;_i0->x.i>= 0;v=*++_i0,s=*++_i1){ {
      if (_attribute[s.i].gradient)
 { {





     val(v.x,0,0,0) = _attribute[s.i].gradient (val(s,-1,0,0), val(s,0,0,0), val(s,1,0,0))/Delta;
 } 
#line 250
{





     val(v.y,0,0,0) = _attribute[s.i].gradient (val(s,0,-1,0), val(s,0,0,0), val(s,0,1,0))/Delta;
 }}
      else
 { {





     val(v.x,0,0,0) = (val(s,1,0,0) - val(s,-1,0,0))/(2.*Delta);
 } 
#line 259
{





     val(v.y,0,0,0) = (val(s,0,1,0) - val(s,0,-1,0))/(2.*Delta);
 }}
    }}}
  }}
      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }

#line 269 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
}
#line 286 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
void vorticity (const vector u, scalar omega)
{
  if(!is_constant(fm.x) && !is_constant(cm)){  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
    
#line 289 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{_stencil_val(fm.x,1,0,0); _stencil_val(fm.x,0,0,0);_stencil_val(u.y,0,0,0);
        _stencil_val(fm.x,1,0,0);_stencil_val(u.y,1,0,0); _stencil_val(fm.x,0,0,0);_stencil_val(u.y,-1,0,0);
_stencil_val(fm.y,0,1,0); _stencil_val(fm.y,0,0,0);_stencil_val(u.x,0,0,0);
        _stencil_val(fm.y,0,0,0);_stencil_val(u.x,0,-1,0); _stencil_val(fm.y,0,1,0);_stencil_val(u.x,0,1,0);_stencil_val(cm,0,0,0);
#line 289
_stencil_val_a(omega,0,0,0);      
             

}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 288 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="omega",.type=sym_SCALAR,.pointer=(void *)&omega},{.name="fm",.type=sym_VECTOR,.global=1,.pointer=(void *)&fm},{.name="u",.type=sym_VECTOR,.pointer=(void *)&u},{.name="cm",.type=sym_SCALAR,.global=1,.pointer=(void *)&cm},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\nval_out_(omega,0,0,0) = ((val(fm.x,1,0,0) - val(fm.x,0,0,0))*val(u.y,0,0,0) +\n        val(fm.x,1,0,0)*val(u.y,1,0,0) - val(fm.x,0,0,0)*val(u.y,-1,0,0) -\n        (val(fm.y,0,1,0) - val(fm.y,0,0,0))*val(u.x,0,0,0) +\n        val(fm.y,0,0,0)*val(u.x,0,-1,0) - val(fm.y,0,1,0)*val(u.x,0,1,0))/(2.f*(val(cm,0,0,0) + 0.f)*Delta);}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
    
#line 289 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 289 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
val(omega,0,0,0) = ((val(fm.x,1,0,0) - val(fm.x,0,0,0))*val(u.y,0,0,0) +
        val(fm.x,1,0,0)*val(u.y,1,0,0) - val(fm.x,0,0,0)*val(u.y,-1,0,0) -
        (val(fm.y,0,1,0) - val(fm.y,0,0,0))*val(u.x,0,0,0) +
        val(fm.y,0,0,0)*val(u.x,0,-1,0) - val(fm.y,0,1,0)*val(u.x,0,1,0))/(2.*(val(cm,0,0,0) + 0.)*Delta);}      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 292 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
}else if(is_constant(fm.x) && !is_constant(cm)){_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
    
#line 289 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{;;_stencil_val(u.y,0,0,0);
;_stencil_val(u.y,1,0,0);;_stencil_val(u.y,-1,0,0);
;;_stencil_val(u.x,0,0,0);
;_stencil_val(u.x,0,-1,0);;_stencil_val(u.x,0,1,0);_stencil_val(cm,0,0,0);
#line 289
_stencil_val_a(omega,0,0,0);      
             

}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 288 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="omega",.type=sym_SCALAR,.pointer=(void *)&omega},{.name="_const_fm",.type=sym__COORD,.pointer=(void *)&_const_fm},{.name="u",.type=sym_VECTOR,.pointer=(void *)&u},{.name="cm",.type=sym_SCALAR,.global=1,.pointer=(void *)&cm},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\nval_out_(omega,0,0,0) = ((_const_fm.x - _const_fm.x)*val(u.y,0,0,0) +\n        _const_fm.x*val(u.y,1,0,0) - _const_fm.x*val(u.y,-1,0,0) -\n        (_const_fm.y - _const_fm.y)*val(u.x,0,0,0) +\n        _const_fm.y*val(u.x,0,-1,0) - _const_fm.y*val(u.x,0,1,0))/(2.f*(val(cm,0,0,0) + 0.f)*Delta);}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
    
#line 289 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 289 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
val(omega,0,0,0) = ((_const_fm.x - _const_fm.x)*val(u.y,0,0,0) +
        _const_fm.x*val(u.y,1,0,0) - _const_fm.x*val(u.y,-1,0,0) -
        (_const_fm.y - _const_fm.y)*val(u.x,0,0,0) +
        _const_fm.y*val(u.x,0,-1,0) - _const_fm.y*val(u.x,0,1,0))/(2.*(val(cm,0,0,0) + 0.)*Delta);}      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 292 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
}else if(!is_constant(fm.x) && is_constant(cm)){double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
    
#line 289 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{_stencil_val(fm.x,1,0,0); _stencil_val(fm.x,0,0,0);_stencil_val(u.y,0,0,0);
        _stencil_val(fm.x,1,0,0);_stencil_val(u.y,1,0,0); _stencil_val(fm.x,0,0,0);_stencil_val(u.y,-1,0,0);
_stencil_val(fm.y,0,1,0); _stencil_val(fm.y,0,0,0);_stencil_val(u.x,0,0,0);
        _stencil_val(fm.y,0,0,0);_stencil_val(u.x,0,-1,0); _stencil_val(fm.y,0,1,0);_stencil_val(u.x,0,1,0);;
#line 289
_stencil_val_a(omega,0,0,0);      
             

}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 288 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="omega",.type=sym_SCALAR,.pointer=(void *)&omega},{.name="fm",.type=sym_VECTOR,.global=1,.pointer=(void *)&fm},{.name="u",.type=sym_VECTOR,.pointer=(void *)&u},{.name="_const_cm",.type=49,.pointer=(void *)&_const_cm},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\nval_out_(omega,0,0,0) = ((val(fm.x,1,0,0) - val(fm.x,0,0,0))*val(u.y,0,0,0) +\n        val(fm.x,1,0,0)*val(u.y,1,0,0) - val(fm.x,0,0,0)*val(u.y,-1,0,0) -\n        (val(fm.y,0,1,0) - val(fm.y,0,0,0))*val(u.x,0,0,0) +\n        val(fm.y,0,0,0)*val(u.x,0,-1,0) - val(fm.y,0,1,0)*val(u.x,0,1,0))/(2.f*(_const_cm + 0.f)*Delta);}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
    
#line 289 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 289 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
val(omega,0,0,0) = ((val(fm.x,1,0,0) - val(fm.x,0,0,0))*val(u.y,0,0,0) +
        val(fm.x,1,0,0)*val(u.y,1,0,0) - val(fm.x,0,0,0)*val(u.y,-1,0,0) -
        (val(fm.y,0,1,0) - val(fm.y,0,0,0))*val(u.x,0,0,0) +
        val(fm.y,0,0,0)*val(u.x,0,-1,0) - val(fm.y,0,1,0)*val(u.x,0,1,0))/(2.*(_const_cm + 0.)*Delta);}      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 292 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
}else {_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
    
#line 289 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{;;_stencil_val(u.y,0,0,0);
;_stencil_val(u.y,1,0,0);;_stencil_val(u.y,-1,0,0);
;;_stencil_val(u.x,0,0,0);
;_stencil_val(u.x,0,-1,0);;_stencil_val(u.x,0,1,0);;
#line 289
_stencil_val_a(omega,0,0,0);      
             

}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 288 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="omega",.type=sym_SCALAR,.pointer=(void *)&omega},{.name="_const_fm",.type=sym__COORD,.pointer=(void *)&_const_fm},{.name="u",.type=sym_VECTOR,.pointer=(void *)&u},{.name="_const_cm",.type=49,.pointer=(void *)&_const_cm},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\nval_out_(omega,0,0,0) = ((_const_fm.x - _const_fm.x)*val(u.y,0,0,0) +\n        _const_fm.x*val(u.y,1,0,0) - _const_fm.x*val(u.y,-1,0,0) -\n        (_const_fm.y - _const_fm.y)*val(u.x,0,0,0) +\n        _const_fm.y*val(u.x,0,-1,0) - _const_fm.y*val(u.x,0,1,0))/(2.f*(_const_cm + 0.f)*Delta);}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
    
#line 289 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 289 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
val(omega,0,0,0) = ((_const_fm.x - _const_fm.x)*val(u.y,0,0,0) +
        _const_fm.x*val(u.y,1,0,0) - _const_fm.x*val(u.y,-1,0,0) -
        (_const_fm.y - _const_fm.y)*val(u.x,0,0,0) +
        _const_fm.y*val(u.x,0,-1,0) - _const_fm.y*val(u.x,0,1,0))/(2.*(_const_cm + 0.)*Delta);}      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 292 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
}
}





double change (scalar s, scalar sn)
{
  double max = 0.;
  if(!is_constant(cm)){  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 302 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{
_stencil_val(cm,0,0,0); {     
       _stencil_val(sn,0,0,0);_stencil_val(s,0,0,0);   
       
  
    } 
_stencil_val(s,0,0,0);    _stencil_val_a(sn,0,0,0); 
  }
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 302 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="cm",.type=sym_SCALAR,.global=1,.pointer=(void *)&cm},{.name="s",.type=sym_SCALAR,.pointer=(void *)&s},{.name="sn",.type=sym_SCALAR,.pointer=(void *)&sn},{.name="max",.type=49,.pointer=(void *)&max,.reduct='M'},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), " \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\n{\n    if ((( Delta*Delta)*val(cm,0,0,0)) > 0.f) {\n      real ds = fabs (val(s,0,0,0) - val(sn,0,0,0));\n      if (ds > max)\n max = ds;\n    }\n    val_out_(sn,0,0,0) = val(s,0,0,0);\n  }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 302 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 302 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{
    if ((( Delta*Delta)*val(cm,0,0,0)) > 0.) {
      double ds = fabs (val(s,0,0,0) - val(sn,0,0,0));
      if (ds > max)
 max = ds;
    }
    val(sn,0,0,0) = val(s,0,0,0);
  }}      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 309 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{mpi_all_reduce_array(&max,MPI_DOUBLE,MPI_MAX,1);}}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 302 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{
; {     
       _stencil_val(sn,0,0,0);_stencil_val(s,0,0,0);   
       
  
    } 
_stencil_val(s,0,0,0);    _stencil_val_a(sn,0,0,0); 
  }
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 302 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="_const_cm",.type=49,.pointer=(void *)&_const_cm},{.name="s",.type=sym_SCALAR,.pointer=(void *)&s},{.name="sn",.type=sym_SCALAR,.pointer=(void *)&sn},{.name="max",.type=49,.pointer=(void *)&max,.reduct='M'},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), " \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h\"\n{\n    if ((( Delta*Delta)*_const_cm) > 0.f) {\n      real ds = fabs (val(s,0,0,0) - val(sn,0,0,0));\n      if (ds > max)\n max = ds;\n    }\n    val_out_(sn,0,0,0) = val(s,0,0,0);\n  }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 302 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 302 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{
    if ((( Delta*Delta)*_const_cm) > 0.) {
      double ds = fabs (val(s,0,0,0) - val(sn,0,0,0));
      if (ds > max)
 max = ds;
    }
    val(sn,0,0,0) = val(s,0,0,0);
  }}      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 309 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
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
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
      
#line 352 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 352 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
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
#line 356
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
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
  
#line 372 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
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

#line 1 "./output.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
#line 37 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
     
void output_field (scalar * list,
     FILE * fp,
     int n,
     bool linear,
     coord box[2])
{tracing("output_field","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h",0);
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
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 2;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 101
{
    _region.p = p, _region.box = box1, _region.n = cn;  
#line 60 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
{                     
    
    
    
    
    {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      { _stencil_interpolate_linear (point, s, NULL, NULL, NULL); _stencil_val(s,0,0,0);      }}}
  }
  
#line 104 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 101
(
#line 58 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
(External[]){{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{.name="p",.type=sym_COORD,.pointer=(void *)&p},{.name="box1",.type=sym_COORD,.pointer=(void *)box1,.data=(int[]){2,0}},{.name="cn",.type=sym_COORD,.pointer=(void *)&cn},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="field",.type=49,.pointer=(void *)field,.nd=2},{.name="list",.type=sym_SCALAR,.pointer=(void *)list,.nd=1},{.name="len",.type=44,.pointer=(void *)&len},{.name="linear",.type=sym_BOOL,.pointer=(void *)&linear},{.name="interpolate_linear",.type=sym_function_definition,.pointer=(void *)(long)interpolate_linear},{0}}
#line 101 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), NULL);
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 25 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
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

  
#line 60 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 60 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
{
    double ** alias = field;
    int i = (p.x - box1[0].x)/(box1[1].x - box1[0].x)*cn.x;
    int j = (p.y - box1[0].y)/(box1[1].y - box1[0].y)*cn.y;
    int k = 0;
    {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      alias[i][len*j + k++] = linear ? interpolate_linear (point, s, p.x, p.y, p.z) : val(s,0,0,0);}}
  }}   
#line 41 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
}
 }
      }
    }
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }

  
#line 69 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
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
end_tracing("output_field","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h",0);}
#line 125 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
     
void output_matrix (scalar f,
      FILE * fp,
      int n,
      bool linear,
      const char * file,
      coord box[2])
{tracing("output_matrix","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h",0);
  coord cn = {n}, p;
  double delta = (box[1].x - box[0].x)/n;
  cn.y = (int)((box[1].y - box[0].y)/delta);

  double ** ppm = (double **) matrix_new (cn.x, cn.y, sizeof(double));
  double * ppm0 = &ppm[0][0];
  unsigned int len = cn.x*cn.y;
  for (int i = 0; i < len; i++)
    ppm0[i] = - 1e30f;  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 2;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 101
{
    _region.p = p, _region.box = box, _region.n = cn;

  
#line 148 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
{                  
    
    
     
_stencil_interpolate_linear (point, f, NULL, NULL, NULL); _stencil_val(f,0,0,0);  
}  
#line 104 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 101
(
#line 146 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
(External[]){{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{.name="p",.type=sym_COORD,.pointer=(void *)&p},{.name="box",.type=sym_COORD,.pointer=(void *)box,.data=(int[]){2,0}},{.name="cn",.type=sym_COORD,.pointer=(void *)&cn},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="ppm",.type=49,.pointer=(void *)ppm,.nd=2},{.name="linear",.type=sym_BOOL,.pointer=(void *)&linear},{.name="interpolate_linear",.type=sym_function_definition,.pointer=(void *)(long)interpolate_linear},{.name="f",.type=sym_SCALAR,.pointer=(void *)&f},{0}}
#line 101 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), NULL);
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 25 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
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

  
#line 148 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 148 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
{
    int i = (p.x - box[0].x)/(box[1].x - box[0].x)*cn.x;
    int j = (p.y - box[0].y)/(box[1].y - box[0].y)*cn.y;
    double ** alias = ppm;
    alias[i][j] = linear ? interpolate_linear (point, f, p.x, p.y, p.z) : val(f,0,0,0);
  }}   
#line 41 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
}
 }
      }
    }
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }

  
#line 155 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
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
end_tracing("output_matrix","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h",0);}
#line 194 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
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
#line 346 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
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
  if (!(pid() == 0)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h", 0, "pid() == 0");
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
  if (!(pid() == 0)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h", 0, "pid() == 0");
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
#line 594 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
     
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
{tracing("output_ppm","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h",0);

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
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 2;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 101
{
    _region.p = p, _region.box = box, _region.n = cn;

  
#line 638 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
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
#line 104 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 101
(
#line 636 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
(External[]){{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{.name="p",.type=sym_COORD,.pointer=(void *)&p},{.name="box",.type=sym_COORD,.pointer=(void *)box,.data=(int[]){2,0}},{.name="cn",.type=sym_COORD,.pointer=(void *)&cn},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="mask",.type=sym_SCALAR,.pointer=(void *)&mask},{.name="linear",.type=sym_BOOL,.pointer=(void *)&linear},{.name="interpolate_linear",.type=sym_function_definition,.pointer=(void *)(long)interpolate_linear},{.name="f",.type=sym_SCALAR,.pointer=(void *)&f},{.name="ppm",.type=sym_TYPEDEF,.pointer=(void *)ppm,.nd=2},{.name="colormap_color",.type=sym_function_definition,.pointer=(void *)(long)colormap_color},{.name="cmap",.type=49,.pointer=(void *)cmap,.data=(int[]){1273,0}},{.name="min",.type=49,.pointer=(void *)&min},{.name="max",.type=49,.pointer=(void *)&max},{0}}
#line 101 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), NULL);
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 25 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
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

  
#line 638 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 638 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
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
#line 41 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
}
 }
      }
    }
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }

  
#line 665 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
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
end_tracing("output_ppm","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h",0);}
#line 721 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
     
void output_grd (scalar f,
   FILE * fp,
   double Delta,
   bool linear,
   coord box[2],
   scalar mask)
{tracing("output_grd","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h",0);
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
#line 966 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
, 0.
#line 746 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
, linear);
 if (m < 0.)
   v = 1e30f;
 else
   v = interpolate (f, xp, yp
#line 966 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
, 0.
#line 750 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
, linear);
      }
      else
 v = interpolate (f, xp, yp
#line 966 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
, 0.
#line 753 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
, linear);
      if (v == 1e30f)
 fprintf (fp, "-9999 ");
      else
 fprintf (fp, "%f ", v);
    }
    fprintf (fp, "\n");
  }

  fflush (fp);
end_tracing("output_grd","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h",0);}
#line 790 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
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
{tracing("output_gfs","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h",0);
  char * fname = file;
#line 832 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
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
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 307 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
{
  if (!Dimensions.x) Dimensions.x = 1;
  if (!Dimensions.y) Dimensions.y = 1;
  for (int ox = 0; ox < Dimensions.x; ox++)
    for (int oy = 0; oy < Dimensions.y; oy++) {
      Point root = {2 + ox, 2 + oy, 0};  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 67 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
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
#line 893 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 893 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
{



    {






      unsigned flags =
 level == 0 ? 0 :



      child.x == -1 && child.y == -1 ? 0 :
 child.x == -1 && child.y == 1 ? 1 :
 child.x == 1 && child.y == -1 ? 2 :
 3;
#line 923 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
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
#line 91 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
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
#line 120 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
      }
    }
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
    
#line 315 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
}
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 966 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
    fputs ("}\n", fp);
  fflush (fp);

  if (!list)
    pfree (slist,__func__,__FILE__,0);
  if (opened)
    fclose (fp);
#line 991 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
end_tracing("output_gfs","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h",0);}
#line 1018 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
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
{tracing("dump","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h",0);
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
  if (!(fp)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h", 0, "fp");

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
#line 1103
{
    header.n.y = Dimensions.y;
    npe *= header.n.y;
  }
  header.npe = npe;
  dump_header (fp, &header, slist);

  subtree_size (size, false);

  {scalar*_i=(scalar*)( slist);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    _attribute[s.i].stencil.io |= s_input;}}
  gpu_cpu_sync (slist, GPU_READ, "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h", 0);  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 307 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
{
  if (!Dimensions.x) Dimensions.x = 1;
  if (!Dimensions.y) Dimensions.y = 1;
  for (int ox = 0; ox < Dimensions.x; ox++)
    for (int oy = 0; oy < Dimensions.y; oy++) {
      Point root = {2 + ox, 2 + oy, 0};  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 67 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
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
#line 1116 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 1116 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
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
#line 91 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
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
#line 120 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
      }
    }
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
    
#line 315 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
}
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }

  
#line 1133 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
pfree (slist,__func__,__FILE__,0);
  if (file) {
    fclose (fp);
    if (!unbuffered)
      rename (name, file);
    pfree (name,__func__,__FILE__,0);
  }delete((scalar*)((scalar[]){size,{-1}}));
end_tracing("dump","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h",0);}
#line 1235 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
     
bool restore (const char * file,
       scalar * list,
       FILE * fp)
{tracing("restore","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h",0);
  if (!fp && (fp = fopen (file, "r")) == NULL)
    {end_tracing("restore","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h",0);return false;}
  if (!(fp)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h", 0, "fp");

  struct DumpHeader header = {0};
  if (fread (&header, sizeof(header), 1, fp) < 1) {
    fprintf (ferr, "restore(): error: expecting header\n");
    exit (1);
  }
#line 1267 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
  dimensions (header.n.x, header.n.y, header.n.z);
  double n = header.n.x;
  int depth = header.depth;
  while (n > 1)
    depth++, n /= 2;
  gpu_init_grid(1 << depth);


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
#line 1350 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
  scalar * listm = is_constant(cm) ? NULL : (scalar *)((vector[]){fm,{{-1},{-1}}});




  int rootlevel = 0;  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 307 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
{
  if (!(
#line 1367 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
header.n
#line 308 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
).x) (
#line 1367 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
header.n
#line 308 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
).x = 1;
  if (!(
#line 1367 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
header.n
#line 309 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
).y) (
#line 1367 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
header.n
#line 309 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
).y = 1;
  for (int ox = 0; ox < (
#line 1367 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
header.n
#line 310 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
).x; ox++)
    for (int oy = 0; oy < (
#line 1367 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
header.n
#line 311 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
).y; oy++) {
      Point root = {2 + ox, 2 + oy, rootlevel};  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 67 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
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
#line 1367 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 1367 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
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
#line 91 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
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
#line 120 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
      }
    }
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
    
#line 315 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../foreach_cell.h"
}
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }

  
#line 1391 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
{scalar*_i=(scalar*)( slist);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (s.i != INT_MAX)
      _attribute[s.i].gpu.stored = 1;}}

  {scalar*_i=(scalar*)( all);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    set_dirty_stencil (s);}}


  scalar * other = NULL;
  {scalar*_i=(scalar*)( all);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!list_lookup (slist, s) && !list_lookup (listm, s))
      other = list_append (other, s);}}
  reset_gpu (other, 0.);
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

  {end_tracing("restore","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h",0);return true;}
end_tracing("restore","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h",0);}
#line 394 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/utils.h"
#line 12 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/run.h"

     
void run (void)
{tracing("run","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/run.h",0);
  iter = 0, t = 0., dt = 1.;
  gpu_init_grid(N);

  perf.nc = perf.tnc = 0;
  perf.gt = timer_start();
  while (events (true)) {





    update_perf();
    iter = inext, t = tnext;
  }




  timer_print (perf.gt, iter, perf.tnc);

  gpu_free_grid();
end_tracing("run","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/run.h",0);}




static int defaults_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i = 0)!=0;*ip=i;*tp=t;return ret;}      static int defaults(const int i,const double t,Event *_ev){tracing("defaults","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/run.h",0); {
  display ("box();"
#line 526 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h"
, false
#line 43 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/run.h"
);
}{end_tracing("defaults","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/run.h",0);return 0;}end_tracing("defaults","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/run.h",0);}





static int cleanup_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(t = TEND_EVENT)!=0;*ip=i;*tp=t;return ret;}      static int cleanup(const int i,const double t,Event *_ev){tracing("cleanup","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/run.h",0); {
  display ("", true);
}{end_tracing("cleanup","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/run.h",0);return 0;}end_tracing("cleanup","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/run.h",0);}
#line 18 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/advection.h"
#line 1 "./timestep.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"

double timestep (const vector u, double dtmax)
{
  static double previous = 0.;
  if (t == 0.) previous = 0.;
  dtmax /= CFL;
if(!is_constant(fm.x)){
  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
#line 7 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
{ 
#line 394 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
_loop.face |= (1 << 0);    
#line 8 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
{_stencil_val(u.x,0,0,0); {   
      _stencil_val(u.x,0,0,0);
_stencil_val(fm.x,0,0,0); 
_stencil_val(fm.x,0,0,0);    

}   } 
#line 395 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
_loop.face |= (1 << 1);    
#line 8 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
{_stencil_val(u.y,0,0,0); {   
      _stencil_val(u.y,0,0,0);
_stencil_val(fm.y,0,0,0); 
_stencil_val(fm.y,0,0,0);    

}   }}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 121
(
#line 7 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="u",.type=sym_VECTOR,.pointer=(void *)&u},{.name="fm",.type=sym_VECTOR,.global=1,.pointer=(void *)&fm},{.name="dtmax",.type=49,.pointer=(void *)&dtmax,.reduct='m'},{0}}
#line 121 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h\"\n{\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nif (point.j < point.n.y + 2) {\n    int ig = -1; NOT_UNUSED(ig);    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h\"\nif (val(u.x,0,0,0) != 0.f) {\n      real dt = Delta/fabs(val(u.x,0,0,0));\n      if (!bool((val(fm.x,0,0,0))));\n      dt *= val(fm.x,0,0,0);\n      if (dt < dtmax) dtmax = dt;\n    }}\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n  \n\n\nif (point.i < point.n.x + 2) {\n    int jg = -1; NOT_UNUSED(jg);    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_y = Delta;\n\n  real Delta_x = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_y);\n\n  NOT_UNUSED(Delta_x);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h\"\nif (val(u.y,0,0,0) != 0.f) {\n      real dt = Delta/fabs(val(u.y,0,0,0));\n      if (!bool((val(fm.y,0,0,0))));\n      dt *= val(fm.y,0,0,0);\n      if (dt < dtmax) dtmax = dt;\n    }}\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h\"\n}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 300 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
{
  OMP_PARALLEL (reduction(min:dtmax)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)
#line 7 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
{
  
#line 353 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);    
#line 8 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 8 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
if (val(u.x,0,0,0) != 0.) {
      double dt = Delta/fabs(val(u.x,0,0,0));
      if (!(val(fm.x,0,0,0))) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h", 0, "fm.x[]");
      dt *= val(fm.x,0,0,0);
      if (dt < dtmax) dtmax = dt;
    }}
  
#line 356 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);    
#line 8 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 8 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
if (val(u.y,0,0,0) != 0.) {
      double dt = Delta/fabs(val(u.y,0,0,0));
      if (!(val(fm.y,0,0,0))) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h", 0, "fm.x[]");
      dt *= val(fm.y,0,0,0);
      if (dt < dtmax) dtmax = dt;
    }}
  
#line 363 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
#line 13 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
}
      
#line 317 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 13 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
{mpi_all_reduce_array(&dtmax,MPI_DOUBLE,MPI_MIN,1);}}else {_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);
  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
#line 7 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
{ 
#line 394 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
_loop.face |= (1 << 0);    
#line 8 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
{_stencil_val(u.x,0,0,0); {   
      _stencil_val(u.x,0,0,0);
;
;    

}   } 
#line 395 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
_loop.face |= (1 << 1);    
#line 8 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
{_stencil_val(u.y,0,0,0); {   
      _stencil_val(u.y,0,0,0);
;
;    

}   }}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 121
(
#line 7 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="u",.type=sym_VECTOR,.pointer=(void *)&u},{.name="_const_fm",.type=sym__COORD,.pointer=(void *)&_const_fm},{.name="dtmax",.type=49,.pointer=(void *)&dtmax,.reduct='m'},{0}}
#line 121 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h\"\n{\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nif (point.j < point.n.y + 2) {\n    int ig = -1; NOT_UNUSED(ig);    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h\"\nif (val(u.x,0,0,0) != 0.f) {\n      real dt = Delta/fabs(val(u.x,0,0,0));\n      if (!bool((_const_fm.x)));\n      dt *= _const_fm.x;\n      if (dt < dtmax) dtmax = dt;\n    }}\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n  \n\n\nif (point.i < point.n.x + 2) {\n    int jg = -1; NOT_UNUSED(jg);    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_y = Delta;\n\n  real Delta_x = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_y);\n\n  NOT_UNUSED(Delta_x);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h\"\nif (val(u.y,0,0,0) != 0.f) {\n      real dt = Delta/fabs(val(u.y,0,0,0));\n      if (!bool((_const_fm.y)));\n      dt *= _const_fm.y;\n      if (dt < dtmax) dtmax = dt;\n    }}\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h\"\n}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 300 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
{
  OMP_PARALLEL (reduction(min:dtmax)) {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0};
    point.level = depth();
    point.n.x = (1 << point.level)*Dimensions.x, point.n.y = (1 << point.level)*Dimensions.y;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 2; _k <= point.n.x + 2; _k++) {
 point.i = _k;

 for (point.j = 2; point.j <= point.n.y + 2; point.j++)
#line 7 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
{
  
#line 353 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);    
#line 8 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 8 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
if (val(u.x,0,0,0) != 0.) {
      double dt = Delta/fabs(val(u.x,0,0,0));
      if (!(_const_fm.x)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h", 0, "fm.x[]");
      dt *= _const_fm.x;
      if (dt < dtmax) dtmax = dt;
    }}
  
#line 356 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);    
#line 8 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 8 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
if (val(u.y,0,0,0) != 0.) {
      double dt = Delta/fabs(val(u.y,0,0,0));
      if (!(_const_fm.y)) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h", 0, "fm.x[]");
      dt *= _const_fm.y;
      if (dt < dtmax) dtmax = dt;
    }}
  
#line 363 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
#line 13 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
}
      
#line 317 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 13 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/timestep.h"
{mpi_all_reduce_array(&dtmax,MPI_DOUBLE,MPI_MIN,1);}}
  dtmax *= CFL;
  if (dtmax > previous)
    dtmax = (previous + 0.1*dtmax)/1.1;
  previous = dtmax;
  return dtmax;
}
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/advection.h"
#line 27 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/advection.h"
vector  uf={{0},{1}};

double (* gradient) (double, double, double) = NULL;





extern scalar * tracers;

static int defaults_0_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i = 0)!=0;*ip=i;*tp=t;return ret;}      static int defaults_0(const int i,const double t,Event *_ev){tracing("defaults_0","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/advection.h",0); {
  {scalar*_i=(scalar*)( tracers);if(_i)for(scalar f=*_i;(&f)->i>=0;f=*++_i){
    _attribute[f.i].gradient = gradient;}}
}{end_tracing("defaults_0","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/advection.h",0);return 0;}end_tracing("defaults_0","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/advection.h",0);}




static int init_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i = 0)!=0;*ip=i;*tp=t;return ret;}static int init(const int i,const double t,Event *_ev){;return 0;}






static int velocity_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}      static int velocity(const int i,const double t,Event *_ev){tracing("velocity","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/advection.h",0); {
  dt = dtnext (timestep (uf, DT));
}{end_tracing("velocity","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/advection.h",0);return 0;}end_tracing("velocity","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/advection.h",0);}

#line 1 "./tracer.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/tracer.h"
#line 15 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/tracer.h"
extern scalar * tracers;
extern vector uf;
extern double dt;
#line 41 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/tracer.h"
#line 1 "./bcg.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
#line 11 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
     
void tracer_fluxes (scalar f,
      vector uf,
      vector flux,
      double dt,
              scalar src)
{tracing("tracer_fluxes","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h",0);





  vector  g=new_vector("g");
  gradients (((scalar[]){f,{-1}}),((vector[]) {g,{{-1},{-1}}}));




if(!is_constant(fm.x) && !is_constant(src)){  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{ 
#line 394 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
_loop.face |= (1 << 0); 
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{               







    _stencil_val(fm.x,0,0,0);_stencil_val(uf.x,0,0,0);              
    
    _stencil_val(g.x,o_stencil,0,0); _stencil_val(src,-1,0,0);_stencil_val(src,0,0,0);_stencil_val(f, o_stencil,0,0);





_stencil_val(fm.y,o_stencil,0,0); _stencil_val(fm.y,o_stencil,1,0); {     
       _stencil_val(fm.y,o_stencil,1,0);_stencil_val(fm.y,o_stencil,0,0); _stencil_val(uf.y,o_stencil,1,0);_stencil_val(uf.y,o_stencil,0,0);         
       _stencil_val(f,o_stencil,-1,0);_stencil_val(f, o_stencil,0,0);_stencil_val(f, o_stencil,0,0); _stencil_val(f,o_stencil,1,0);
        
    }









_stencil_val(uf.x,0,0,0);





      
#line 59 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
    _stencil_val_a(flux.x,0,0,0);  
  } 
#line 395 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
_loop.face |= (1 << 1); 
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{               







    _stencil_val(fm.y,0,0,0);_stencil_val(uf.y,0,0,0);              
    
    _stencil_val(g.y,0,o_stencil,0); _stencil_val(src,0,-1,0);_stencil_val(src,0,0,0);_stencil_val(f,0, o_stencil,0);





_stencil_val(fm.x,0,o_stencil,0); _stencil_val(fm.x,1,o_stencil,0); {     
       _stencil_val(fm.x,1,o_stencil,0);_stencil_val(fm.x,0,o_stencil,0); _stencil_val(uf.x,1,o_stencil,0);_stencil_val(uf.x,0,o_stencil,0);         
       _stencil_val(f,-1,o_stencil,0);_stencil_val(f,0, o_stencil,0);_stencil_val(f,0, o_stencil,0); _stencil_val(f,1,o_stencil,0);
        
    }









_stencil_val(uf.y,0,0,0);





      
#line 59 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
    _stencil_val_a(flux.y,0,0,0);  
  }}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 121
(
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="dt",.type=49,.pointer=(void *)&dt},{.name="uf",.type=sym_VECTOR,.pointer=(void *)&uf},{.name="fm",.type=sym_VECTOR,.global=1,.pointer=(void *)&fm},{.name="f",.type=sym_SCALAR,.pointer=(void *)&f},{.name="src",.type=sym_SCALAR,.pointer=(void *)&src},{.name="g",.type=sym_VECTOR,.pointer=(void *)&g},{.name="flux",.type=sym_VECTOR,.pointer=(void *)&flux},{0}}
#line 121 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nif (point.j < point.n.y + 2) {\n    int ig = -1; NOT_UNUSED(ig); \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{\n\n\n\n\n\n\n\n    real un = dt*val(uf.x,0,0,0)/(val(fm.x,0,0,0)*Delta + 0.f), s = (int ((un > 0 ? 1 : -1)));\n    int i =int( -(s + 1.f)/2.f);\n    real f2 = val(f,i,0,0) + (val(src,0,0,0) + val(src,-1,0,0))*dt/4.f + s*(1.f - s*un)*val(g.x,i,0,0)*Delta/2.f;\n\n\n\n\n\n    if (bool(val(fm.y,i,0,0)) &&bool( val(fm.y,i,1,0))) {\n      real vn = (val(uf.y,i,0,0) + val(uf.y,i,1,0))/(val(fm.y,i,0,0) + val(fm.y,i,1,0));\n      real fyy = vn < 0.f ? val(f,i,1,0) - val(f,i,0,0) : val(f,i,0,0) - val(f,i,-1,0);\n      f2 -= dt*vn*fyy/(2.f*Delta);\n    }\n// # 59 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n    val_out_(flux.x,0,0,0) = f2*val(uf.x,0,0,0);\n  }}\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n  \n\n\nif (point.i < point.n.x + 2) {\n    int jg = -1; NOT_UNUSED(jg); \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_y = Delta;\n\n  real Delta_x = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_y);\n\n  NOT_UNUSED(Delta_x);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{\n\n\n\n\n\n\n\n    real un = dt*val(uf.y,0,0,0)/(val(fm.y,0,0,0)*Delta + 0.f), s = (int ((un > 0 ? 1 : -1)));\n    int i =int( -(s + 1.f)/2.f);\n    real f2 = val(f,0,i,0) + (val(src,0,0,0) + val(src,0,-1,0))*dt/4.f + s*(1.f - s*un)*val(g.y,0,i,0)*Delta/2.f;\n\n\n\n\n\n    if (bool(val(fm.x,0,i,0)) &&bool( val(fm.x,1,i,0))) {\n      real vn = (val(uf.x,0,i,0) + val(uf.x,1,i,0))/(val(fm.x,0,i,0) + val(fm.x,1,i,0));\n      real fyy = vn < 0.f ? val(f,1,i,0) - val(f,0,i,0) : val(f,0,i,0) - val(f,-1,i,0);\n      f2 -= dt*vn*fyy/(2.f*Delta);\n    }\n// # 59 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n    val_out_(flux.y,0,0,0) = f2*val(uf.y,0,0,0);\n  }}\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 300 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{
  
#line 353 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{







    double un = dt*val(uf.x,0,0,0)/(val(fm.x,0,0,0)*Delta + 0.), s = ( (int)(un > 0 ? 1 : -1));
    int i = -(s + 1.)/2.;
    double f2 = val(f,i,0,0) + (val(src,0,0,0) + val(src,-1,0,0))*dt/4. + s*(1. - s*un)*val(g.x,i,0,0)*Delta/2.;





    if (val(fm.y,i,0,0) && val(fm.y,i,1,0)) {
      double vn = (val(uf.y,i,0,0) + val(uf.y,i,1,0))/(val(fm.y,i,0,0) + val(fm.y,i,1,0));
      double fyy = vn < 0. ? val(f,i,1,0) - val(f,i,0,0) : val(f,i,0,0) - val(f,i,-1,0);
      f2 -= dt*vn*fyy/(2.*Delta);
    }
#line 59 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
    val(flux.x,0,0,0) = f2*val(uf.x,0,0,0);
  }}
  
#line 356 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{







    double un = dt*val(uf.y,0,0,0)/(val(fm.y,0,0,0)*Delta + 0.), s = ( (int)(un > 0 ? 1 : -1));
    int i = -(s + 1.)/2.;
    double f2 = val(f,0,i,0) + (val(src,0,0,0) + val(src,0,-1,0))*dt/4. + s*(1. - s*un)*val(g.y,0,i,0)*Delta/2.;





    if (val(fm.x,0,i,0) && val(fm.x,1,i,0)) {
      double vn = (val(uf.x,0,i,0) + val(uf.x,1,i,0))/(val(fm.x,0,i,0) + val(fm.x,1,i,0));
      double fyy = vn < 0. ? val(f,1,i,0) - val(f,0,i,0) : val(f,0,i,0) - val(f,-1,i,0);
      f2 -= dt*vn*fyy/(2.*Delta);
    }
#line 59 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
    val(flux.y,0,0,0) = f2*val(uf.y,0,0,0);
  }}
  
#line 363 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
#line 60 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
}
      
#line 317 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 60 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
}else if(is_constant(fm.x) && !is_constant(src)){_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{ 
#line 394 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
_loop.face |= (1 << 0); 
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{







;_stencil_val(uf.x,0,0,0);              
    
    _stencil_val(g.x,o_stencil,0,0); _stencil_val(src,-1,0,0);_stencil_val(src,0,0,0);_stencil_val(f, o_stencil,0,0);





;; {
;; _stencil_val(uf.y,o_stencil,1,0);_stencil_val(uf.y,o_stencil,0,0);         
       _stencil_val(f,o_stencil,-1,0);_stencil_val(f, o_stencil,0,0);_stencil_val(f, o_stencil,0,0); _stencil_val(f,o_stencil,1,0);
        
    }









_stencil_val(uf.x,0,0,0);





      
#line 59 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
    _stencil_val_a(flux.x,0,0,0);  
  } 
#line 395 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
_loop.face |= (1 << 1); 
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{







;_stencil_val(uf.y,0,0,0);              
    
    _stencil_val(g.y,0,o_stencil,0); _stencil_val(src,0,-1,0);_stencil_val(src,0,0,0);_stencil_val(f,0, o_stencil,0);





;; {
;; _stencil_val(uf.x,1,o_stencil,0);_stencil_val(uf.x,0,o_stencil,0);         
       _stencil_val(f,-1,o_stencil,0);_stencil_val(f,0, o_stencil,0);_stencil_val(f,0, o_stencil,0); _stencil_val(f,1,o_stencil,0);
        
    }









_stencil_val(uf.y,0,0,0);





      
#line 59 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
    _stencil_val_a(flux.y,0,0,0);  
  }}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 121
(
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="dt",.type=49,.pointer=(void *)&dt},{.name="uf",.type=sym_VECTOR,.pointer=(void *)&uf},{.name="_const_fm",.type=sym__COORD,.pointer=(void *)&_const_fm},{.name="f",.type=sym_SCALAR,.pointer=(void *)&f},{.name="src",.type=sym_SCALAR,.pointer=(void *)&src},{.name="g",.type=sym_VECTOR,.pointer=(void *)&g},{.name="flux",.type=sym_VECTOR,.pointer=(void *)&flux},{0}}
#line 121 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nif (point.j < point.n.y + 2) {\n    int ig = -1; NOT_UNUSED(ig); \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{\n\n\n\n\n\n\n\n    real un = dt*val(uf.x,0,0,0)/(_const_fm.x*Delta + 0.f), s = (int ((un > 0 ? 1 : -1)));\n    int i =int( -(s + 1.f)/2.f);\n    real f2 = val(f,i,0,0) + (val(src,0,0,0) + val(src,-1,0,0))*dt/4.f + s*(1.f - s*un)*val(g.x,i,0,0)*Delta/2.f;\n\n\n\n\n\n    if (bool(_const_fm.y) &&bool( _const_fm.y)) {\n      real vn = (val(uf.y,i,0,0) + val(uf.y,i,1,0))/(_const_fm.y + _const_fm.y);\n      real fyy = vn < 0.f ? val(f,i,1,0) - val(f,i,0,0) : val(f,i,0,0) - val(f,i,-1,0);\n      f2 -= dt*vn*fyy/(2.f*Delta);\n    }\n// # 59 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n    val_out_(flux.x,0,0,0) = f2*val(uf.x,0,0,0);\n  }}\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n  \n\n\nif (point.i < point.n.x + 2) {\n    int jg = -1; NOT_UNUSED(jg); \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_y = Delta;\n\n  real Delta_x = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_y);\n\n  NOT_UNUSED(Delta_x);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{\n\n\n\n\n\n\n\n    real un = dt*val(uf.y,0,0,0)/(_const_fm.y*Delta + 0.f), s = (int ((un > 0 ? 1 : -1)));\n    int i =int( -(s + 1.f)/2.f);\n    real f2 = val(f,0,i,0) + (val(src,0,0,0) + val(src,0,-1,0))*dt/4.f + s*(1.f - s*un)*val(g.y,0,i,0)*Delta/2.f;\n\n\n\n\n\n    if (bool(_const_fm.x) &&bool( _const_fm.x)) {\n      real vn = (val(uf.x,0,i,0) + val(uf.x,1,i,0))/(_const_fm.x + _const_fm.x);\n      real fyy = vn < 0.f ? val(f,1,i,0) - val(f,0,i,0) : val(f,0,i,0) - val(f,-1,i,0);\n      f2 -= dt*vn*fyy/(2.f*Delta);\n    }\n// # 59 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n    val_out_(flux.y,0,0,0) = f2*val(uf.y,0,0,0);\n  }}\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 300 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{
  
#line 353 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{







    double un = dt*val(uf.x,0,0,0)/(_const_fm.x*Delta + 0.), s = ( (int)(un > 0 ? 1 : -1));
    int i = -(s + 1.)/2.;
    double f2 = val(f,i,0,0) + (val(src,0,0,0) + val(src,-1,0,0))*dt/4. + s*(1. - s*un)*val(g.x,i,0,0)*Delta/2.;





    if (_const_fm.y && _const_fm.y) {
      double vn = (val(uf.y,i,0,0) + val(uf.y,i,1,0))/(_const_fm.y + _const_fm.y);
      double fyy = vn < 0. ? val(f,i,1,0) - val(f,i,0,0) : val(f,i,0,0) - val(f,i,-1,0);
      f2 -= dt*vn*fyy/(2.*Delta);
    }
#line 59 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
    val(flux.x,0,0,0) = f2*val(uf.x,0,0,0);
  }}
  
#line 356 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{







    double un = dt*val(uf.y,0,0,0)/(_const_fm.y*Delta + 0.), s = ( (int)(un > 0 ? 1 : -1));
    int i = -(s + 1.)/2.;
    double f2 = val(f,0,i,0) + (val(src,0,0,0) + val(src,0,-1,0))*dt/4. + s*(1. - s*un)*val(g.y,0,i,0)*Delta/2.;





    if (_const_fm.x && _const_fm.x) {
      double vn = (val(uf.x,0,i,0) + val(uf.x,1,i,0))/(_const_fm.x + _const_fm.x);
      double fyy = vn < 0. ? val(f,1,i,0) - val(f,0,i,0) : val(f,0,i,0) - val(f,-1,i,0);
      f2 -= dt*vn*fyy/(2.*Delta);
    }
#line 59 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
    val(flux.y,0,0,0) = f2*val(uf.y,0,0,0);
  }}
  
#line 363 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
#line 60 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
}
      
#line 317 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 60 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
}else if(!is_constant(fm.x) && is_constant(src)){double _const_src=_constant[src.i-_NVARMAX];NOT_UNUSED(_const_src);  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{ 
#line 394 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
_loop.face |= (1 << 0); 
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{               







    _stencil_val(fm.x,0,0,0);_stencil_val(uf.x,0,0,0);              
    
    _stencil_val(g.x,o_stencil,0,0);;;_stencil_val(f, o_stencil,0,0);





_stencil_val(fm.y,o_stencil,0,0); _stencil_val(fm.y,o_stencil,1,0); {     
       _stencil_val(fm.y,o_stencil,1,0);_stencil_val(fm.y,o_stencil,0,0); _stencil_val(uf.y,o_stencil,1,0);_stencil_val(uf.y,o_stencil,0,0);         
       _stencil_val(f,o_stencil,-1,0);_stencil_val(f, o_stencil,0,0);_stencil_val(f, o_stencil,0,0); _stencil_val(f,o_stencil,1,0);
        
    }









_stencil_val(uf.x,0,0,0);





      
#line 59 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
    _stencil_val_a(flux.x,0,0,0);  
  } 
#line 395 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
_loop.face |= (1 << 1); 
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{               







    _stencil_val(fm.y,0,0,0);_stencil_val(uf.y,0,0,0);              
    
    _stencil_val(g.y,0,o_stencil,0);;;_stencil_val(f,0, o_stencil,0);





_stencil_val(fm.x,0,o_stencil,0); _stencil_val(fm.x,1,o_stencil,0); {     
       _stencil_val(fm.x,1,o_stencil,0);_stencil_val(fm.x,0,o_stencil,0); _stencil_val(uf.x,1,o_stencil,0);_stencil_val(uf.x,0,o_stencil,0);         
       _stencil_val(f,-1,o_stencil,0);_stencil_val(f,0, o_stencil,0);_stencil_val(f,0, o_stencil,0); _stencil_val(f,1,o_stencil,0);
        
    }









_stencil_val(uf.y,0,0,0);





      
#line 59 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
    _stencil_val_a(flux.y,0,0,0);  
  }}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 121
(
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="dt",.type=49,.pointer=(void *)&dt},{.name="uf",.type=sym_VECTOR,.pointer=(void *)&uf},{.name="fm",.type=sym_VECTOR,.global=1,.pointer=(void *)&fm},{.name="f",.type=sym_SCALAR,.pointer=(void *)&f},{.name="_const_src",.type=49,.pointer=(void *)&_const_src},{.name="g",.type=sym_VECTOR,.pointer=(void *)&g},{.name="flux",.type=sym_VECTOR,.pointer=(void *)&flux},{0}}
#line 121 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nif (point.j < point.n.y + 2) {\n    int ig = -1; NOT_UNUSED(ig); \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{\n\n\n\n\n\n\n\n    real un = dt*val(uf.x,0,0,0)/(val(fm.x,0,0,0)*Delta + 0.f), s = (int ((un > 0 ? 1 : -1)));\n    int i =int( -(s + 1.f)/2.f);\n    real f2 = val(f,i,0,0) + (_const_src + _const_src)*dt/4.f + s*(1.f - s*un)*val(g.x,i,0,0)*Delta/2.f;\n\n\n\n\n\n    if (bool(val(fm.y,i,0,0)) &&bool( val(fm.y,i,1,0))) {\n      real vn = (val(uf.y,i,0,0) + val(uf.y,i,1,0))/(val(fm.y,i,0,0) + val(fm.y,i,1,0));\n      real fyy = vn < 0.f ? val(f,i,1,0) - val(f,i,0,0) : val(f,i,0,0) - val(f,i,-1,0);\n      f2 -= dt*vn*fyy/(2.f*Delta);\n    }\n// # 59 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n    val_out_(flux.x,0,0,0) = f2*val(uf.x,0,0,0);\n  }}\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n  \n\n\nif (point.i < point.n.x + 2) {\n    int jg = -1; NOT_UNUSED(jg); \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_y = Delta;\n\n  real Delta_x = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_y);\n\n  NOT_UNUSED(Delta_x);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{\n\n\n\n\n\n\n\n    real un = dt*val(uf.y,0,0,0)/(val(fm.y,0,0,0)*Delta + 0.f), s = (int ((un > 0 ? 1 : -1)));\n    int i =int( -(s + 1.f)/2.f);\n    real f2 = val(f,0,i,0) + (_const_src + _const_src)*dt/4.f + s*(1.f - s*un)*val(g.y,0,i,0)*Delta/2.f;\n\n\n\n\n\n    if (bool(val(fm.x,0,i,0)) &&bool( val(fm.x,1,i,0))) {\n      real vn = (val(uf.x,0,i,0) + val(uf.x,1,i,0))/(val(fm.x,0,i,0) + val(fm.x,1,i,0));\n      real fyy = vn < 0.f ? val(f,1,i,0) - val(f,0,i,0) : val(f,0,i,0) - val(f,-1,i,0);\n      f2 -= dt*vn*fyy/(2.f*Delta);\n    }\n// # 59 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n    val_out_(flux.y,0,0,0) = f2*val(uf.y,0,0,0);\n  }}\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 300 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{
  
#line 353 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{







    double un = dt*val(uf.x,0,0,0)/(val(fm.x,0,0,0)*Delta + 0.), s = ( (int)(un > 0 ? 1 : -1));
    int i = -(s + 1.)/2.;
    double f2 = val(f,i,0,0) + (_const_src + _const_src)*dt/4. + s*(1. - s*un)*val(g.x,i,0,0)*Delta/2.;





    if (val(fm.y,i,0,0) && val(fm.y,i,1,0)) {
      double vn = (val(uf.y,i,0,0) + val(uf.y,i,1,0))/(val(fm.y,i,0,0) + val(fm.y,i,1,0));
      double fyy = vn < 0. ? val(f,i,1,0) - val(f,i,0,0) : val(f,i,0,0) - val(f,i,-1,0);
      f2 -= dt*vn*fyy/(2.*Delta);
    }
#line 59 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
    val(flux.x,0,0,0) = f2*val(uf.x,0,0,0);
  }}
  
#line 356 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{







    double un = dt*val(uf.y,0,0,0)/(val(fm.y,0,0,0)*Delta + 0.), s = ( (int)(un > 0 ? 1 : -1));
    int i = -(s + 1.)/2.;
    double f2 = val(f,0,i,0) + (_const_src + _const_src)*dt/4. + s*(1. - s*un)*val(g.y,0,i,0)*Delta/2.;





    if (val(fm.x,0,i,0) && val(fm.x,1,i,0)) {
      double vn = (val(uf.x,0,i,0) + val(uf.x,1,i,0))/(val(fm.x,0,i,0) + val(fm.x,1,i,0));
      double fyy = vn < 0. ? val(f,1,i,0) - val(f,0,i,0) : val(f,0,i,0) - val(f,-1,i,0);
      f2 -= dt*vn*fyy/(2.*Delta);
    }
#line 59 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
    val(flux.y,0,0,0) = f2*val(uf.y,0,0,0);
  }}
  
#line 363 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
#line 60 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
}
      
#line 317 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 60 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
}else {_coord _const_fm={_constant[fm.x.i-_NVARMAX],_constant[fm.y.i-_NVARMAX]};NOT_UNUSED(_const_fm);double _const_src=_constant[src.i-_NVARMAX];NOT_UNUSED(_const_src);  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{ 
#line 394 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
_loop.face |= (1 << 0); 
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{







;_stencil_val(uf.x,0,0,0);              
    
    _stencil_val(g.x,o_stencil,0,0);;;_stencil_val(f, o_stencil,0,0);





;; {
;; _stencil_val(uf.y,o_stencil,1,0);_stencil_val(uf.y,o_stencil,0,0);         
       _stencil_val(f,o_stencil,-1,0);_stencil_val(f, o_stencil,0,0);_stencil_val(f, o_stencil,0,0); _stencil_val(f,o_stencil,1,0);
        
    }









_stencil_val(uf.x,0,0,0);





      
#line 59 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
    _stencil_val_a(flux.x,0,0,0);  
  } 
#line 395 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
_loop.face |= (1 << 1); 
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{







;_stencil_val(uf.y,0,0,0);              
    
    _stencil_val(g.y,0,o_stencil,0);;;_stencil_val(f,0, o_stencil,0);





;; {
;; _stencil_val(uf.x,1,o_stencil,0);_stencil_val(uf.x,0,o_stencil,0);         
       _stencil_val(f,-1,o_stencil,0);_stencil_val(f,0, o_stencil,0);_stencil_val(f,0, o_stencil,0); _stencil_val(f,1,o_stencil,0);
        
    }









_stencil_val(uf.y,0,0,0);





      
#line 59 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
    _stencil_val_a(flux.y,0,0,0);  
  }}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 121
(
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="dt",.type=49,.pointer=(void *)&dt},{.name="uf",.type=sym_VECTOR,.pointer=(void *)&uf},{.name="_const_fm",.type=sym__COORD,.pointer=(void *)&_const_fm},{.name="f",.type=sym_SCALAR,.pointer=(void *)&f},{.name="_const_src",.type=49,.pointer=(void *)&_const_src},{.name="g",.type=sym_VECTOR,.pointer=(void *)&g},{.name="flux",.type=sym_VECTOR,.pointer=(void *)&flux},{0}}
#line 121 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nif (point.j < point.n.y + 2) {\n    int ig = -1; NOT_UNUSED(ig); \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{\n\n\n\n\n\n\n\n    real un = dt*val(uf.x,0,0,0)/(_const_fm.x*Delta + 0.f), s = (int ((un > 0 ? 1 : -1)));\n    int i =int( -(s + 1.f)/2.f);\n    real f2 = val(f,i,0,0) + (_const_src + _const_src)*dt/4.f + s*(1.f - s*un)*val(g.x,i,0,0)*Delta/2.f;\n\n\n\n\n\n    if (bool(_const_fm.y) &&bool( _const_fm.y)) {\n      real vn = (val(uf.y,i,0,0) + val(uf.y,i,1,0))/(_const_fm.y + _const_fm.y);\n      real fyy = vn < 0.f ? val(f,i,1,0) - val(f,i,0,0) : val(f,i,0,0) - val(f,i,-1,0);\n      f2 -= dt*vn*fyy/(2.f*Delta);\n    }\n// # 59 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n    val_out_(flux.x,0,0,0) = f2*val(uf.x,0,0,0);\n  }}\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n  \n\n\nif (point.i < point.n.x + 2) {\n    int jg = -1; NOT_UNUSED(jg); \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_y = Delta;\n\n  real Delta_x = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_y);\n\n  NOT_UNUSED(Delta_x);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{\n\n\n\n\n\n\n\n    real un = dt*val(uf.y,0,0,0)/(_const_fm.y*Delta + 0.f), s = (int ((un > 0 ? 1 : -1)));\n    int i =int( -(s + 1.f)/2.f);\n    real f2 = val(f,0,i,0) + (_const_src + _const_src)*dt/4.f + s*(1.f - s*un)*val(g.y,0,i,0)*Delta/2.f;\n\n\n\n\n\n    if (bool(_const_fm.x) &&bool( _const_fm.x)) {\n      real vn = (val(uf.x,0,i,0) + val(uf.x,1,i,0))/(_const_fm.x + _const_fm.x);\n      real fyy = vn < 0.f ? val(f,1,i,0) - val(f,0,i,0) : val(f,0,i,0) - val(f,-1,i,0);\n      f2 -= dt*vn*fyy/(2.f*Delta);\n    }\n// # 59 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n    val_out_(flux.y,0,0,0) = f2*val(uf.y,0,0,0);\n  }}\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 300 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{
  
#line 353 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig); 
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{







    double un = dt*val(uf.x,0,0,0)/(_const_fm.x*Delta + 0.), s = ( (int)(un > 0 ? 1 : -1));
    int i = -(s + 1.)/2.;
    double f2 = val(f,i,0,0) + (_const_src + _const_src)*dt/4. + s*(1. - s*un)*val(g.x,i,0,0)*Delta/2.;





    if (_const_fm.y && _const_fm.y) {
      double vn = (val(uf.y,i,0,0) + val(uf.y,i,1,0))/(_const_fm.y + _const_fm.y);
      double fyy = vn < 0. ? val(f,i,1,0) - val(f,i,0,0) : val(f,i,0,0) - val(f,i,-1,0);
      f2 -= dt*vn*fyy/(2.*Delta);
    }
#line 59 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
    val(flux.x,0,0,0) = f2*val(uf.x,0,0,0);
  }}
  
#line 356 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg); 
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{







    double un = dt*val(uf.y,0,0,0)/(_const_fm.y*Delta + 0.), s = ( (int)(un > 0 ? 1 : -1));
    int i = -(s + 1.)/2.;
    double f2 = val(f,0,i,0) + (_const_src + _const_src)*dt/4. + s*(1. - s*un)*val(g.y,0,i,0)*Delta/2.;





    if (_const_fm.x && _const_fm.x) {
      double vn = (val(uf.x,0,i,0) + val(uf.x,1,i,0))/(_const_fm.x + _const_fm.x);
      double fyy = vn < 0. ? val(f,1,i,0) - val(f,0,i,0) : val(f,0,i,0) - val(f,-1,i,0);
      f2 -= dt*vn*fyy/(2.*Delta);
    }
#line 59 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
    val(flux.y,0,0,0) = f2*val(uf.y,0,0,0);
  }}
  
#line 363 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
#line 60 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
}
      
#line 317 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 60 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
}delete((scalar*)((vector[]){g,{{-1},{-1}}}));
end_tracing("tracer_fluxes","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h",0);}






     
void advection (scalar * tracers, vector uf, double dt,
  scalar * src)
{tracing("advection","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h",0);




  scalar * psrc = src;
  if (!src)
    {scalar*_i=(scalar*)( tracers);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
      const scalar zero = new_const_scalar("zero",12, 0.);
      src = list_append (src, zero);
    }}}
  if (!(list_len (tracers) == list_len (src))) qassert ("/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h", 0, "list_len (tracers) == list_len (src)");

  scalar f, source;
  {scalar*_i0=src;scalar*_i1= tracers;if(_i0)for(source=*_i0,f=*_i1;_i0->i>= 0;source=*++_i0,f=*++_i1){ {
    vector  flux=new_face_vector("flux");
    tracer_fluxes (f, uf, flux, dt, source);

    if(!is_constant(cm)){    
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
      
#line 90 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{
        {_stencil_val(flux.x,0,0,0); _stencil_val(flux.x,1,0,0);_stencil_val(cm,0,0,0);_stencil_val_r(f,0,0,0);   }        {_stencil_val(flux.y,0,0,0); _stencil_val(flux.y,0,1,0);_stencil_val(cm,0,0,0);_stencil_val_r(f,0,0,0);   }}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 89 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="f",.type=sym_SCALAR,.pointer=(void *)&f},{.name="dt",.type=49,.pointer=(void *)&dt},{.name="flux",.type=sym_VECTOR,.pointer=(void *)&flux},{.name="cm",.type=sym_SCALAR,.global=1,.pointer=(void *)&cm},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n      \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{\n        val_out_(f,0,0,0) += dt*(val(flux.x,0,0,0) - val(flux.x,1,0,0))/(Delta*val(cm,0,0,0));        val_out_(f,0,0,0) += dt*(val(flux.y,0,0,0) - val(flux.y,0,1,0))/(Delta*val(cm,0,0,0));}}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 90 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 90 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{
        val(f,0,0,0) += dt*(val(flux.x,0,0,0) - val(flux.x,1,0,0))/(Delta*val(cm,0,0,0));        val(f,0,0,0) += dt*(val(flux.y,0,0,0) - val(flux.y,0,1,0))/(Delta*val(cm,0,0,0));}}
      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 91 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);    
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
      
#line 90 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{
        {_stencil_val(flux.x,0,0,0); _stencil_val(flux.x,1,0,0);;_stencil_val_r(f,0,0,0);   }        {_stencil_val(flux.y,0,0,0); _stencil_val(flux.y,0,1,0);;_stencil_val_r(f,0,0,0);   }}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 89 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="f",.type=sym_SCALAR,.pointer=(void *)&f},{.name="dt",.type=49,.pointer=(void *)&dt},{.name="flux",.type=sym_VECTOR,.pointer=(void *)&flux},{.name="_const_cm",.type=49,.pointer=(void *)&_const_cm},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n      \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h\"\n{\n        val_out_(f,0,0,0) += dt*(val(flux.x,0,0,0) - val(flux.x,1,0,0))/(Delta*_const_cm);        val_out_(f,0,0,0) += dt*(val(flux.y,0,0,0) - val(flux.y,0,1,0))/(Delta*_const_cm);}}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 90 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 90 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
{
        val(f,0,0,0) += dt*(val(flux.x,0,0,0) - val(flux.x,1,0,0))/(Delta*_const_cm);        val(f,0,0,0) += dt*(val(flux.y,0,0,0) - val(flux.y,0,1,0))/(Delta*_const_cm);}}
      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 91 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
}delete((scalar*)((vector[]){flux,{{-1},{-1}}}));



  }}}

  if (!psrc)
    pfree (src,__func__,__FILE__,0);
end_tracing("advection","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h",0);}
#line 43 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/tracer.h"
static int tracer_advection_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}
#line 42 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/tracer.h"

      static int tracer_advection(const int i,const double t,Event *_ev){tracing("tracer_advection","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/tracer.h",0); {
  advection (tracers, uf, dt
#line 69 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/bcg.h"
, 
NULL
#line 44 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/tracer.h"
);
}{end_tracing("tracer_advection","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/tracer.h",0);return 0;}end_tracing("tracer_advection","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/tracer.h",0);}




static int vof_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}static int vof(const int i,const double t,Event *_ev){;return 0;}




static int tracer_diffusion_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}static int tracer_diffusion(const int i,const double t,Event *_ev){;return 0;}
#line 57 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/advection.h"
#line 29 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
#line 1 "./poisson.h"
#line 1 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
#line 32 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
     
void mg_cycle (scalar * a, scalar * res, scalar * da,
        void (* relax) (scalar * da, scalar * res,
          int depth, void * data),
        void * data,
        int nrelax, int minlevel, int maxlevel)
{tracing("mg_cycle","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h",0);




  restriction (res);





  minlevel = ( minlevel < maxlevel ? minlevel : maxlevel);
  for (int l = minlevel; l <= maxlevel; l++) {




    if (l == minlevel)
      {      
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 80
{
    _region.level = l + 1; 
#line 57 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{scalar*_i=(scalar*)( da);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
  
     {_stencil_val_a(s,0,0,0);  }}}
  
#line 83 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 80
(
#line 137
(
#line 56 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
(External[]){{.name="l",.type=44,.pointer=(void *)&l},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="da",.type=sym_SCALAR,.pointer=(void *)da,.nd=1},{0}}
#line 137 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 80
)
#line 65
), "\n \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;{\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\nforin (scalar, s , da)\n  \n     val_out_(s,0,0,0) = 0.f; endforin()}}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;
#line 7 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 244 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 57 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 57 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{scalar*_i=(scalar*)( da);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
  
     val(s,0,0,0) = 0.;}}}
    
#line 261 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 10 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
}
    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 59 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
}





    else {
      boundary_level (da, l - 1);      
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 80
{
    _region.level = l + 1; 
#line 68 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{scalar*_i=(scalar*)( da);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
  
     { _stencil_bilinear (point, s);_stencil_val_a(s,0,0,0); }}}
  
#line 83 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 80
(
#line 67 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
(External[]){{.name="l",.type=44,.pointer=(void *)&l},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="da",.type=sym_SCALAR,.pointer=(void *)da,.nd=1},{.name="bilinear",.type=sym_function_definition,.pointer=(void *)(long)bilinear},{0}}
#line 80 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;{\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\nforin (scalar, s , da)\n  \n     val_out_(s,0,0,0) = bilinear (point, s); endforin()}}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 244 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 68 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 68 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{scalar*_i=(scalar*)( da);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
  
     val(s,0,0,0) = bilinear (point, s);}}}
    
#line 261 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
    
#line 71 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
}





    for (int i = 0; i < nrelax; i++) {
      boundary_level (da, l);
      relax (da, res, l, data);
    }
  }  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 86 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{
    scalar s, ds;
    {scalar*_i0= da;scalar*_i1= a;if(_i0)for(ds=*_i0,s=*_i1;_i0->i>= 0;ds=*++_i0,s=*++_i1){
     
 { _stencil_val(ds,0,0,0);_stencil_val_r(s,0,0,0); }}}
  }
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 86 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="a",.type=sym_SCALAR,.pointer=(void *)a,.nd=1},{.name="da",.type=sym_SCALAR,.pointer=(void *)da,.nd=1},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), " \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{\n    scalar s, ds;\n    {forin2 (s, ds , a, da)\n     \n val_out_(s,0,0,0) += val(ds,0,0,0); endforin2()}\n  }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 86 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 86 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{
    scalar s, ds;
    {scalar*_i0= da;scalar*_i1= a;if(_i0)for(ds=*_i0,s=*_i1;_i0->i>= 0;ds=*++_i0,s=*++_i1){
     
 val(s,0,0,0) += val(ds,0,0,0);}}
  }}
      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
end_tracing("mg_cycle","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h",0);
#line 92 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
}
#line 104 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
int NITERMAX = 100, NITERMIN = 1;
double TOLERANCE = 1e-3;




typedef struct {
  int i;
  double resb, resa;
  double sum;
  int nrelax;
  int minlevel;
} mgstats;
#line 127 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
     
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
{tracing("mg_solve","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h",0);





  scalar * da = list_clone (a), * pres = res;
  if (!res)
    res = list_clone (b);






  for (int b = 0; b < nboundary; b++)
    {scalar*_i=(scalar*)( da);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      _attribute[s.i].boundary[b] = _attribute[s.i].boundary_homogeneous[b];}}




  mgstats s = {0};
  double sum = 0.;
  scalar rhs = b[0];  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
    
#line 164 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{ _stencil_val(rhs,0,0,0); }
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 163 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="sum",.type=49,.pointer=(void *)&sum,.reduct='+'},{.name="rhs",.type=sym_SCALAR,.pointer=(void *)&rhs},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\nsum += val(rhs,0,0,0);}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }
#line 163 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
mpi_sum_reduce_init(mpi_sum,&sum,MPI_DOUBLE,MPI_SUM,1);  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 164 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 164 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
sum += val(rhs,0,0,0);}
      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 164 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
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
#line 195 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
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

  {end_tracing("mg_solve","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h",0);return s;}
end_tracing("mg_solve","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h",0);}
#line 254 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
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
#line 292 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
  scalar c = a;
#line 301 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
  for (int parity = 0; parity < 2; parity++)
    {if(!is_constant(lambda) && !is_constant(alpha.x)){    
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 80
{
    _region.level = l + 1;



  
#line 307 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{         





     _stencil_val(lambda,0,0,0);_stencil_val(b,0,0,0);
     { 
_stencil_val(alpha.x,1,0,0);_stencil_val(a,1,0,0); _stencil_val(alpha.x,0,0,0);_stencil_val(a,-1,0,0);
         _stencil_val(alpha.x,1,0,0); _stencil_val(alpha.x,0,0,0);    
} 
#line 314
{ 
_stencil_val(alpha.y,0,1,0);_stencil_val(a,0,1,0); _stencil_val(alpha.y,0,0,0);_stencil_val(a,0,-1,0);
         _stencil_val(alpha.y,0,1,0); _stencil_val(alpha.y,0,0,0);    
}
#line 328 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
      _stencil_val_a(c,0,0,0);  
  }  
#line 83 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 80
(
#line 137
(
#line 302 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
(External[]){{.name="l",.type=44,.pointer=(void *)&l},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="parity",.type=44,.pointer=(void *)&parity},{.name="b",.type=sym_SCALAR,.pointer=(void *)&b},{.name="lambda",.type=sym_SCALAR,.pointer=(void *)&lambda},{.name="alpha",.type=sym_VECTOR,.pointer=(void *)&alpha},{.name="a",.type=sym_SCALAR,.pointer=(void *)&a},{.name="c",.type=sym_SCALAR,.pointer=(void *)&c},{0}}
#line 137 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 80
)
#line 65
), "\n      \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\nif (level == 0 || ((point.i + parity) % 2) != (point.j % 2))\n\n\n\n  {\n\n\n\n\n\n    real n = - ( Delta*Delta)*val(b,0,0,0), d = - val(lambda,0,0,0)*( Delta*Delta);\n     {\n      n += val(alpha.x,1,0,0)*val(a,1,0,0) + val(alpha.x,0,0,0)*val(a,-1,0,0);\n      d += val(alpha.x,1,0,0) + val(alpha.x,0,0,0);\n    } \n// #line 0\n{\n      n += val(alpha.y,0,1,0)*val(a,0,1,0) + val(alpha.y,0,0,0)*val(a,0,-1,0);\n      d += val(alpha.y,0,1,0) + val(alpha.y,0,0,0);\n    }\n// # 328 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n      val_out_(c,0,0,0) = n/d;\n  }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;
#line 7 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 244 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
      
#line 303 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 303 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
if (level == 0 || ((point.i + parity) % 2) != (point.j % 2))



  {





    double n = - ( Delta*Delta)*val(b,0,0,0), d = - val(lambda,0,0,0)*( Delta*Delta);
     {
      n += val(alpha.x,1,0,0)*val(a,1,0,0) + val(alpha.x,0,0,0)*val(a,-1,0,0);
      d += val(alpha.x,1,0,0) + val(alpha.x,0,0,0);
    } 
#line 314
{
      n += val(alpha.y,0,1,0)*val(a,0,1,0) + val(alpha.y,0,0,0)*val(a,0,-1,0);
      d += val(alpha.y,0,1,0) + val(alpha.y,0,0,0);
    }
#line 328 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
      val(c,0,0,0) = n/d;
  }}    
#line 261 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 10 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
}
    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 329 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
}else if(is_constant(lambda) && !is_constant(alpha.x)){double _const_lambda=_constant[lambda.i-_NVARMAX];NOT_UNUSED(_const_lambda);    
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 80
{
    _region.level = l + 1;



  
#line 307 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{





;_stencil_val(b,0,0,0);
     { 
_stencil_val(alpha.x,1,0,0);_stencil_val(a,1,0,0); _stencil_val(alpha.x,0,0,0);_stencil_val(a,-1,0,0);
         _stencil_val(alpha.x,1,0,0); _stencil_val(alpha.x,0,0,0);    
} 
#line 314
{ 
_stencil_val(alpha.y,0,1,0);_stencil_val(a,0,1,0); _stencil_val(alpha.y,0,0,0);_stencil_val(a,0,-1,0);
         _stencil_val(alpha.y,0,1,0); _stencil_val(alpha.y,0,0,0);    
}
#line 328 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
      _stencil_val_a(c,0,0,0);  
  }  
#line 83 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 80
(
#line 137
(
#line 302 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
(External[]){{.name="l",.type=44,.pointer=(void *)&l},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="parity",.type=44,.pointer=(void *)&parity},{.name="b",.type=sym_SCALAR,.pointer=(void *)&b},{.name="_const_lambda",.type=49,.pointer=(void *)&_const_lambda},{.name="alpha",.type=sym_VECTOR,.pointer=(void *)&alpha},{.name="a",.type=sym_SCALAR,.pointer=(void *)&a},{.name="c",.type=sym_SCALAR,.pointer=(void *)&c},{0}}
#line 137 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 80
)
#line 65
), "\n      \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\nif (level == 0 || ((point.i + parity) % 2) != (point.j % 2))\n\n\n\n  {\n\n\n\n\n\n    real n = - ( Delta*Delta)*val(b,0,0,0), d = - _const_lambda*( Delta*Delta);\n     {\n      n += val(alpha.x,1,0,0)*val(a,1,0,0) + val(alpha.x,0,0,0)*val(a,-1,0,0);\n      d += val(alpha.x,1,0,0) + val(alpha.x,0,0,0);\n    } \n// #line 0\n{\n      n += val(alpha.y,0,1,0)*val(a,0,1,0) + val(alpha.y,0,0,0)*val(a,0,-1,0);\n      d += val(alpha.y,0,1,0) + val(alpha.y,0,0,0);\n    }\n// # 328 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n      val_out_(c,0,0,0) = n/d;\n  }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;
#line 7 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 244 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
      
#line 303 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 303 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
if (level == 0 || ((point.i + parity) % 2) != (point.j % 2))



  {





    double n = - ( Delta*Delta)*val(b,0,0,0), d = - _const_lambda*( Delta*Delta);
     {
      n += val(alpha.x,1,0,0)*val(a,1,0,0) + val(alpha.x,0,0,0)*val(a,-1,0,0);
      d += val(alpha.x,1,0,0) + val(alpha.x,0,0,0);
    } 
#line 314
{
      n += val(alpha.y,0,1,0)*val(a,0,1,0) + val(alpha.y,0,0,0)*val(a,0,-1,0);
      d += val(alpha.y,0,1,0) + val(alpha.y,0,0,0);
    }
#line 328 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
      val(c,0,0,0) = n/d;
  }}    
#line 261 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 10 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
}
    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 329 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
}else if(!is_constant(lambda) && is_constant(alpha.x)){_coord _const_alpha={_constant[alpha.x.i-_NVARMAX],_constant[alpha.y.i-_NVARMAX]};NOT_UNUSED(_const_alpha);    
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 80
{
    _region.level = l + 1;



  
#line 307 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{         





     _stencil_val(lambda,0,0,0);_stencil_val(b,0,0,0);
     {
;_stencil_val(a,1,0,0);;_stencil_val(a,-1,0,0);
;;    
} 
#line 314
{
;_stencil_val(a,0,1,0);;_stencil_val(a,0,-1,0);
;;    
}
#line 328 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
      _stencil_val_a(c,0,0,0);  
  }  
#line 83 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 80
(
#line 137
(
#line 302 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
(External[]){{.name="l",.type=44,.pointer=(void *)&l},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="parity",.type=44,.pointer=(void *)&parity},{.name="b",.type=sym_SCALAR,.pointer=(void *)&b},{.name="lambda",.type=sym_SCALAR,.pointer=(void *)&lambda},{.name="_const_alpha",.type=sym__COORD,.pointer=(void *)&_const_alpha},{.name="a",.type=sym_SCALAR,.pointer=(void *)&a},{.name="c",.type=sym_SCALAR,.pointer=(void *)&c},{0}}
#line 137 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 80
)
#line 65
), "\n      \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\nif (level == 0 || ((point.i + parity) % 2) != (point.j % 2))\n\n\n\n  {\n\n\n\n\n\n    real n = - ( Delta*Delta)*val(b,0,0,0), d = - val(lambda,0,0,0)*( Delta*Delta);\n     {\n      n += _const_alpha.x*val(a,1,0,0) + _const_alpha.x*val(a,-1,0,0);\n      d += _const_alpha.x + _const_alpha.x;\n    } \n// #line 0\n{\n      n += _const_alpha.y*val(a,0,1,0) + _const_alpha.y*val(a,0,-1,0);\n      d += _const_alpha.y + _const_alpha.y;\n    }\n// # 328 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n      val_out_(c,0,0,0) = n/d;\n  }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;
#line 7 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 244 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
      
#line 303 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 303 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
if (level == 0 || ((point.i + parity) % 2) != (point.j % 2))



  {





    double n = - ( Delta*Delta)*val(b,0,0,0), d = - val(lambda,0,0,0)*( Delta*Delta);
     {
      n += _const_alpha.x*val(a,1,0,0) + _const_alpha.x*val(a,-1,0,0);
      d += _const_alpha.x + _const_alpha.x;
    } 
#line 314
{
      n += _const_alpha.y*val(a,0,1,0) + _const_alpha.y*val(a,0,-1,0);
      d += _const_alpha.y + _const_alpha.y;
    }
#line 328 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
      val(c,0,0,0) = n/d;
  }}    
#line 261 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 10 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
}
    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 329 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
}else {double _const_lambda=_constant[lambda.i-_NVARMAX];NOT_UNUSED(_const_lambda);_coord _const_alpha={_constant[alpha.x.i-_NVARMAX],_constant[alpha.y.i-_NVARMAX]};NOT_UNUSED(_const_alpha);    
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 80
{
    _region.level = l + 1;



  
#line 307 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{





;_stencil_val(b,0,0,0);
     {
;_stencil_val(a,1,0,0);;_stencil_val(a,-1,0,0);
;;    
} 
#line 314
{
;_stencil_val(a,0,1,0);;_stencil_val(a,0,-1,0);
;;    
}
#line 328 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
      _stencil_val_a(c,0,0,0);  
  }  
#line 83 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 80
(
#line 137
(
#line 302 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
(External[]){{.name="l",.type=44,.pointer=(void *)&l},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="parity",.type=44,.pointer=(void *)&parity},{.name="b",.type=sym_SCALAR,.pointer=(void *)&b},{.name="_const_lambda",.type=49,.pointer=(void *)&_const_lambda},{.name="_const_alpha",.type=sym__COORD,.pointer=(void *)&_const_alpha},{.name="a",.type=sym_SCALAR,.pointer=(void *)&a},{.name="c",.type=sym_SCALAR,.pointer=(void *)&c},{0}}
#line 137 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 80
)
#line 65
), "\n      \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\nif (level == 0 || ((point.i + parity) % 2) != (point.j % 2))\n\n\n\n  {\n\n\n\n\n\n    real n = - ( Delta*Delta)*val(b,0,0,0), d = - _const_lambda*( Delta*Delta);\n     {\n      n += _const_alpha.x*val(a,1,0,0) + _const_alpha.x*val(a,-1,0,0);\n      d += _const_alpha.x + _const_alpha.x;\n    } \n// #line 0\n{\n      n += _const_alpha.y*val(a,0,1,0) + _const_alpha.y*val(a,0,-1,0);\n      d += _const_alpha.y + _const_alpha.y;\n    }\n// # 328 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n      val_out_(c,0,0,0) = n/d;\n  }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;
#line 7 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
{
  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 244 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
      
#line 303 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 303 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
if (level == 0 || ((point.i + parity) % 2) != (point.j % 2))



  {





    double n = - ( Delta*Delta)*val(b,0,0,0), d = - _const_lambda*( Delta*Delta);
     {
      n += _const_alpha.x*val(a,1,0,0) + _const_alpha.x*val(a,-1,0,0);
      d += _const_alpha.x + _const_alpha.x;
    } 
#line 314
{
      n += _const_alpha.y*val(a,0,1,0) + _const_alpha.y*val(a,0,-1,0);
      d += _const_alpha.y + _const_alpha.y;
    }
#line 328 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
      val(c,0,0,0) = n/d;
  }}    
#line 261 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 10 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h"
}
    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 329 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
}}
#line 347 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
}






static double residual (scalar * al, scalar * bl, scalar * resl, void * data)
{
  scalar a = al[0], b = bl[0], res = resl[0];
  struct Poisson * p = (struct Poisson *) data;
          vector alpha = p->alpha;
          scalar lambda = p->lambda;
  double maxres = 0.;
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
  if(!is_constant(lambda) && !is_constant(alpha.x)){
  
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{ 
_stencil_val(b,0,0,0); _stencil_val(lambda,0,0,0);_stencil_val(a,0,0,0);    _stencil_val_a(res,0,0,0);  
    
      {_stencil_val(alpha.x,0,0,0);_stencil_val(a,0,0,0); _stencil_val(a,0 -1,0,0);
  _stencil_val(alpha.x,1,0,0);_stencil_val(a,1,0,0); _stencil_val(a,1 -1,0,0);
#line 384
_stencil_val_r(res,0,0,0);     
}      
#line 384
{_stencil_val(alpha.y,0,0,0);_stencil_val(a,0,0,0); _stencil_val(a,0,0 -1,0);
  _stencil_val(alpha.y,0,1,0);_stencil_val(a,0,1,0); _stencil_val(a,0,1 -1,0);
#line 384
_stencil_val_r(res,0,0,0);     
}






_stencil_val(res,0,0,0);
      {_stencil_val(res,0,0,0);   }  
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="res",.type=sym_SCALAR,.pointer=(void *)&res},{.name="b",.type=sym_SCALAR,.pointer=(void *)&b},{.name="lambda",.type=sym_SCALAR,.pointer=(void *)&lambda},{.name="a",.type=sym_SCALAR,.pointer=(void *)&a},{.name="alpha",.type=sym_VECTOR,.pointer=(void *)&alpha},{.name="maxres",.type=49,.pointer=(void *)&maxres,.reduct='M'},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), " \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{\n    val_out_(res,0,0,0) = val(b,0,0,0) - val(lambda,0,0,0)*val(a,0,0,0);\n    \n      val_out_(res,0,0,0) += (val(alpha.x,0,0,0)*((val(a,0,0,0) - val(a,0 -1,0,0))/Delta) -\n  val(alpha.x,1,0,0)*((val(a,1,0,0) - val(a,1 -1,0,0))/Delta))/Delta;      \n// #line 0\nval_out_(res,0,0,0) += (val(alpha.y,0,0,0)*((val(a,0,0,0) - val(a,0,0 -1,0))/Delta) -\n  val(alpha.y,0,1,0)*((val(a,0,1,0) - val(a,0,1 -1,0))/Delta))/Delta;\n\n\n\n\n\n\n    if (fabs (val(res,0,0,0)) > maxres)\n      maxres = fabs (val(res,0,0,0));\n  }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{
    val(res,0,0,0) = val(b,0,0,0) - val(lambda,0,0,0)*val(a,0,0,0);
    
      val(res,0,0,0) += (val(alpha.x,0,0,0)*((val(a,0,0,0) - val(a,0 -1,0,0))/Delta) -
  val(alpha.x,1,0,0)*((val(a,1,0,0) - val(a,1 -1,0,0))/Delta))/Delta;      
#line 384
val(res,0,0,0) += (val(alpha.y,0,0,0)*((val(a,0,0,0) - val(a,0,0 -1,0))/Delta) -
  val(alpha.y,0,1,0)*((val(a,0,1,0) - val(a,0,1 -1,0))/Delta))/Delta;






    if (fabs (val(res,0,0,0)) > maxres)
      maxres = fabs (val(res,0,0,0));
  }}      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 394 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{mpi_all_reduce_array(&maxres,MPI_DOUBLE,MPI_MAX,1);}}else if(is_constant(lambda) && !is_constant(alpha.x)){double _const_lambda=_constant[lambda.i-_NVARMAX];NOT_UNUSED(_const_lambda);
  
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{ 
_stencil_val(b,0,0,0);;_stencil_val(a,0,0,0);    _stencil_val_a(res,0,0,0);  
    
      {_stencil_val(alpha.x,0,0,0);_stencil_val(a,0,0,0); _stencil_val(a,0 -1,0,0);
  _stencil_val(alpha.x,1,0,0);_stencil_val(a,1,0,0); _stencil_val(a,1 -1,0,0);
#line 384
_stencil_val_r(res,0,0,0);     
}      
#line 384
{_stencil_val(alpha.y,0,0,0);_stencil_val(a,0,0,0); _stencil_val(a,0,0 -1,0);
  _stencil_val(alpha.y,0,1,0);_stencil_val(a,0,1,0); _stencil_val(a,0,1 -1,0);
#line 384
_stencil_val_r(res,0,0,0);     
}






_stencil_val(res,0,0,0);
      {_stencil_val(res,0,0,0);   }  
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="res",.type=sym_SCALAR,.pointer=(void *)&res},{.name="b",.type=sym_SCALAR,.pointer=(void *)&b},{.name="_const_lambda",.type=49,.pointer=(void *)&_const_lambda},{.name="a",.type=sym_SCALAR,.pointer=(void *)&a},{.name="alpha",.type=sym_VECTOR,.pointer=(void *)&alpha},{.name="maxres",.type=49,.pointer=(void *)&maxres,.reduct='M'},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), " \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{\n    val_out_(res,0,0,0) = val(b,0,0,0) - _const_lambda*val(a,0,0,0);\n    \n      val_out_(res,0,0,0) += (val(alpha.x,0,0,0)*((val(a,0,0,0) - val(a,0 -1,0,0))/Delta) -\n  val(alpha.x,1,0,0)*((val(a,1,0,0) - val(a,1 -1,0,0))/Delta))/Delta;      \n// #line 0\nval_out_(res,0,0,0) += (val(alpha.y,0,0,0)*((val(a,0,0,0) - val(a,0,0 -1,0))/Delta) -\n  val(alpha.y,0,1,0)*((val(a,0,1,0) - val(a,0,1 -1,0))/Delta))/Delta;\n\n\n\n\n\n\n    if (fabs (val(res,0,0,0)) > maxres)\n      maxres = fabs (val(res,0,0,0));\n  }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{
    val(res,0,0,0) = val(b,0,0,0) - _const_lambda*val(a,0,0,0);
    
      val(res,0,0,0) += (val(alpha.x,0,0,0)*((val(a,0,0,0) - val(a,0 -1,0,0))/Delta) -
  val(alpha.x,1,0,0)*((val(a,1,0,0) - val(a,1 -1,0,0))/Delta))/Delta;      
#line 384
val(res,0,0,0) += (val(alpha.y,0,0,0)*((val(a,0,0,0) - val(a,0,0 -1,0))/Delta) -
  val(alpha.y,0,1,0)*((val(a,0,1,0) - val(a,0,1 -1,0))/Delta))/Delta;






    if (fabs (val(res,0,0,0)) > maxres)
      maxres = fabs (val(res,0,0,0));
  }}      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 394 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{mpi_all_reduce_array(&maxres,MPI_DOUBLE,MPI_MAX,1);}}else if(!is_constant(lambda) && is_constant(alpha.x)){_coord _const_alpha={_constant[alpha.x.i-_NVARMAX],_constant[alpha.y.i-_NVARMAX]};NOT_UNUSED(_const_alpha);
  
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{ 
_stencil_val(b,0,0,0); _stencil_val(lambda,0,0,0);_stencil_val(a,0,0,0);    _stencil_val_a(res,0,0,0);  
    
      {;_stencil_val(a,0,0,0); _stencil_val(a,0 -1,0,0);
;_stencil_val(a,1,0,0); _stencil_val(a,1 -1,0,0);
#line 384
_stencil_val_r(res,0,0,0);     
}      
#line 384
{;_stencil_val(a,0,0,0); _stencil_val(a,0,0 -1,0);
;_stencil_val(a,0,1,0); _stencil_val(a,0,1 -1,0);
#line 384
_stencil_val_r(res,0,0,0);     
}






_stencil_val(res,0,0,0);
      {_stencil_val(res,0,0,0);   }  
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="res",.type=sym_SCALAR,.pointer=(void *)&res},{.name="b",.type=sym_SCALAR,.pointer=(void *)&b},{.name="lambda",.type=sym_SCALAR,.pointer=(void *)&lambda},{.name="a",.type=sym_SCALAR,.pointer=(void *)&a},{.name="_const_alpha",.type=sym__COORD,.pointer=(void *)&_const_alpha},{.name="maxres",.type=49,.pointer=(void *)&maxres,.reduct='M'},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), " \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{\n    val_out_(res,0,0,0) = val(b,0,0,0) - val(lambda,0,0,0)*val(a,0,0,0);\n    \n      val_out_(res,0,0,0) += (_const_alpha.x*((val(a,0,0,0) - val(a,0 -1,0,0))/Delta) -\n  _const_alpha.x*((val(a,1,0,0) - val(a,1 -1,0,0))/Delta))/Delta;      \n// #line 0\nval_out_(res,0,0,0) += (_const_alpha.y*((val(a,0,0,0) - val(a,0,0 -1,0))/Delta) -\n  _const_alpha.y*((val(a,0,1,0) - val(a,0,1 -1,0))/Delta))/Delta;\n\n\n\n\n\n\n    if (fabs (val(res,0,0,0)) > maxres)\n      maxres = fabs (val(res,0,0,0));\n  }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{
    val(res,0,0,0) = val(b,0,0,0) - val(lambda,0,0,0)*val(a,0,0,0);
    
      val(res,0,0,0) += (_const_alpha.x*((val(a,0,0,0) - val(a,0 -1,0,0))/Delta) -
  _const_alpha.x*((val(a,1,0,0) - val(a,1 -1,0,0))/Delta))/Delta;      
#line 384
val(res,0,0,0) += (_const_alpha.y*((val(a,0,0,0) - val(a,0,0 -1,0))/Delta) -
  _const_alpha.y*((val(a,0,1,0) - val(a,0,1 -1,0))/Delta))/Delta;






    if (fabs (val(res,0,0,0)) > maxres)
      maxres = fabs (val(res,0,0,0));
  }}      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 394 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{mpi_all_reduce_array(&maxres,MPI_DOUBLE,MPI_MAX,1);}}else {double _const_lambda=_constant[lambda.i-_NVARMAX];NOT_UNUSED(_const_lambda);_coord _const_alpha={_constant[alpha.x.i-_NVARMAX],_constant[alpha.y.i-_NVARMAX]};NOT_UNUSED(_const_alpha);
  
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{ 
_stencil_val(b,0,0,0);;_stencil_val(a,0,0,0);    _stencil_val_a(res,0,0,0);  
    
      {;_stencil_val(a,0,0,0); _stencil_val(a,0 -1,0,0);
;_stencil_val(a,1,0,0); _stencil_val(a,1 -1,0,0);
#line 384
_stencil_val_r(res,0,0,0);     
}      
#line 384
{;_stencil_val(a,0,0,0); _stencil_val(a,0,0 -1,0);
;_stencil_val(a,0,1,0); _stencil_val(a,0,1 -1,0);
#line 384
_stencil_val_r(res,0,0,0);     
}






_stencil_val(res,0,0,0);
      {_stencil_val(res,0,0,0);   }  
}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="res",.type=sym_SCALAR,.pointer=(void *)&res},{.name="b",.type=sym_SCALAR,.pointer=(void *)&b},{.name="_const_lambda",.type=49,.pointer=(void *)&_const_lambda},{.name="a",.type=sym_SCALAR,.pointer=(void *)&a},{.name="_const_alpha",.type=sym__COORD,.pointer=(void *)&_const_alpha},{.name="maxres",.type=49,.pointer=(void *)&maxres,.reduct='M'},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), " \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{\n    val_out_(res,0,0,0) = val(b,0,0,0) - _const_lambda*val(a,0,0,0);\n    \n      val_out_(res,0,0,0) += (_const_alpha.x*((val(a,0,0,0) - val(a,0 -1,0,0))/Delta) -\n  _const_alpha.x*((val(a,1,0,0) - val(a,1 -1,0,0))/Delta))/Delta;      \n// #line 0\nval_out_(res,0,0,0) += (_const_alpha.y*((val(a,0,0,0) - val(a,0,0 -1,0))/Delta) -\n  _const_alpha.y*((val(a,0,1,0) - val(a,0,1 -1,0))/Delta))/Delta;\n\n\n\n\n\n\n    if (fabs (val(res,0,0,0)) > maxres)\n      maxres = fabs (val(res,0,0,0));\n  }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 381 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{
    val(res,0,0,0) = val(b,0,0,0) - _const_lambda*val(a,0,0,0);
    
      val(res,0,0,0) += (_const_alpha.x*((val(a,0,0,0) - val(a,0 -1,0,0))/Delta) -
  _const_alpha.x*((val(a,1,0,0) - val(a,1 -1,0,0))/Delta))/Delta;      
#line 384
val(res,0,0,0) += (_const_alpha.y*((val(a,0,0,0) - val(a,0,0 -1,0))/Delta) -
  _const_alpha.y*((val(a,0,1,0) - val(a,0,1 -1,0))/Delta))/Delta;






    if (fabs (val(res,0,0,0)) > maxres)
      maxres = fabs (val(res,0,0,0));
  }}      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 394 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{mpi_all_reduce_array(&maxres,MPI_DOUBLE,MPI_MAX,1);}}

  return maxres;
}
#line 408 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
     
mgstats poisson (scalar a, scalar b,
           vector alpha,
           scalar lambda,
   double tolerance,
   int nrelax,
   int minlevel,
   scalar * res,
   double (* flux) (Point, scalar, vector, double *))
{tracing("poisson","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h",0);






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
#line 128
scalar *
#line 451
)((scalar[]){a,{-1}}),( 
#line 128
scalar *
#line 451
)((scalar[]) {b,{-1}}), residual, relax, &p
,   nrelax, res, ( 1 > minlevel ? 1 : minlevel)
#line 136
, 
TOLERANCE
#line 452
);




  if (tolerance)
    TOLERANCE = defaultol;

  {end_tracing("poisson","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h",0);return s;}
end_tracing("poisson","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h",0);}
#line 480 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
     
mgstats project (vector uf, scalar p,
           vector alpha,
   double dt,
   int nrelax)
{tracing("project","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h",0);






  scalar  div=new_scalar("div");  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0}; 
#line 493 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{
    _stencil_val_a(div,0,0,0);  
    
      { _stencil_val(uf.x,1,0,0); _stencil_val(uf.x,0,0,0);_stencil_val_r(div,0,0,0);  }      { _stencil_val(uf.y,0,1,0); _stencil_val(uf.y,0,0,0);_stencil_val_r(div,0,0,0);  }
    _stencil_val_r(div,0,0,0);  
  }
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 493 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="div",.type=sym_SCALAR,.pointer=(void *)&div},{.name="uf",.type=sym_VECTOR,.pointer=(void *)&uf},{.name="dt",.type=49,.pointer=(void *)&dt},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), " \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{\n    val_out_(div,0,0,0) = 0.f;\n    \n      val_out_(div,0,0,0) += val(uf.x,1,0,0) - val(uf.x,0,0,0);      val_out_(div,0,0,0) += val(uf.y,0,1,0) - val(uf.y,0,0,0);\n    val_out_(div,0,0,0) /= dt*Delta;\n  }}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 493 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 493 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{
    val(div,0,0,0) = 0.;
    
      val(div,0,0,0) += val(uf.x,1,0,0) - val(uf.x,0,0,0);      val(div,0,0,0) += val(uf.y,0,1,0) - val(uf.y,0,0,0);
    val(div,0,0,0) /= dt*Delta;
  }}      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 509 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
  mgstats mgp = poisson (p, div, alpha
#line 410
,
( scalar) {-1}
#line 510
, TOLERANCE/( dt*dt), nrelax
#line 413
, 
0, 
NULL, 
NULL
#line 510
);




if(!is_constant(alpha.x)){  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
#line 515 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{ 
#line 394 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
_loop.face |= (1 << 0);
    
#line 516 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{_stencil_val(alpha.x,0,0,0);_stencil_val(p,0,0,0); _stencil_val(p,0 -1,0,0);_stencil_val_r(uf.x,0,0,0);   } 
#line 395 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
_loop.face |= (1 << 1);
    
#line 516 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{_stencil_val(alpha.y,0,0,0);_stencil_val(p,0,0,0); _stencil_val(p,0,0 -1,0);_stencil_val_r(uf.y,0,0,0);   }}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 121
(
#line 515 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="uf",.type=sym_VECTOR,.pointer=(void *)&uf},{.name="dt",.type=49,.pointer=(void *)&dt},{.name="alpha",.type=sym_VECTOR,.pointer=(void *)&alpha},{.name="p",.type=sym_SCALAR,.pointer=(void *)&p},{0}}
#line 121 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nif (point.j < point.n.y + 2) {\n    int ig = -1; NOT_UNUSED(ig);\n    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\nval_out_(uf.x,0,0,0) -= dt*val(alpha.x,0,0,0)*((val(p,0,0,0) - val(p,0 -1,0,0))/Delta);}  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n  \n\n\nif (point.i < point.n.x + 2) {\n    int jg = -1; NOT_UNUSED(jg);\n    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_y = Delta;\n\n  real Delta_x = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_y);\n\n  NOT_UNUSED(Delta_x);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\nval_out_(uf.y,0,0,0) -= dt*val(alpha.y,0,0,0)*((val(p,0,0,0) - val(p,0,0 -1,0))/Delta);}  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 300 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 515 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{  
#line 353 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);
    
#line 516 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 516 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
val(uf.x,0,0,0) -= dt*val(alpha.x,0,0,0)*((val(p,0,0,0) - val(p,0 -1,0,0))/Delta);}  
#line 356 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);
    
#line 516 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 516 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
val(uf.y,0,0,0) -= dt*val(alpha.y,0,0,0)*((val(p,0,0,0) - val(p,0,0 -1,0))/Delta);}  
#line 363 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
#line 516 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
}      
#line 317 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 516 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
}else {_coord _const_alpha={_constant[alpha.x.i-_NVARMAX],_constant[alpha.y.i-_NVARMAX]};NOT_UNUSED(_const_alpha);  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
#line 515 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{ 
#line 394 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
_loop.face |= (1 << 0);
    
#line 516 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{;_stencil_val(p,0,0,0); _stencil_val(p,0 -1,0,0);_stencil_val_r(uf.x,0,0,0);   } 
#line 395 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
_loop.face |= (1 << 1);
    
#line 516 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{;_stencil_val(p,0,0,0); _stencil_val(p,0,0 -1,0);_stencil_val_r(uf.y,0,0,0);   }}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 121
(
#line 515 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="uf",.type=sym_VECTOR,.pointer=(void *)&uf},{.name="dt",.type=49,.pointer=(void *)&dt},{.name="_const_alpha",.type=sym__COORD,.pointer=(void *)&_const_alpha},{.name="p",.type=sym_SCALAR,.pointer=(void *)&p},{0}}
#line 121 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nif (point.j < point.n.y + 2) {\n    int ig = -1; NOT_UNUSED(ig);\n    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\nval_out_(uf.x,0,0,0) -= dt*_const_alpha.x*((val(p,0,0,0) - val(p,0 -1,0,0))/Delta);}  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n  \n\n\nif (point.i < point.n.x + 2) {\n    int jg = -1; NOT_UNUSED(jg);\n    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_y = Delta;\n\n  real Delta_x = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_y);\n\n  NOT_UNUSED(Delta_x);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\nval_out_(uf.y,0,0,0) -= dt*_const_alpha.y*((val(p,0,0,0) - val(p,0,0 -1,0))/Delta);}  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h\"\n}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 300 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 515 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{  
#line 353 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);
    
#line 516 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 516 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
val(uf.x,0,0,0) -= dt*_const_alpha.x*((val(p,0,0,0) - val(p,0 -1,0,0))/Delta);}  
#line 356 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);
    
#line 516 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 516 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
val(uf.y,0,0,0) -= dt*_const_alpha.y*((val(p,0,0,0) - val(p,0,0 -1,0))/Delta);}  
#line 363 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
#line 516 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
}      
#line 317 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }
#line 516 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
}

  {delete((scalar*)((scalar[]){div,{-1}}));{end_tracing("project","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h",0);return mgp;}}delete((scalar*)((scalar[]){div,{-1}}));
end_tracing("project","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h",0);}
#line 30 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"







scalar  omega={2},  psi={3};
mgstats mgpsi;
scalar * tracers =((scalar[]) {{2},{-1}});







static double _boundary0_homogeneous(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 47 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 47 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{return( dirichlet_homogeneous(0
#line 58 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
, point, _s
#line 47 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
));}}}static void _stencil_boundary0(Point point,Point neighbor,scalar _s,_stencil_undefined *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 47 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;     
  
  
   
                                              
  

  





   

  



  



  

  

  
  

  





  
   
   
  
#line 180 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
Point parent = point; 
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 47 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{return ;}}}static double _boundary0(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 47 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 47 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{return( dirichlet(0
#line 52 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
, point, _s
#line 47 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
));}}}
static double _boundary1_homogeneous(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 48 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 48 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{return( dirichlet_homogeneous(0
#line 58 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
, point, _s
#line 48 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
));}}}static void _stencil_boundary1(Point point,Point neighbor,scalar _s,_stencil_undefined *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 48 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;     
  
  
   
                                              
  

  





   

  



  



  

  

  
  

  





  
   
   
  
#line 180 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
Point parent = point; 
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 48 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{return ;}}}static double _boundary1(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 48 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 48 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{return( dirichlet(0
#line 52 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
, point, _s
#line 48 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
));}}}
static double _boundary2_homogeneous(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 49 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 49 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{return( dirichlet_homogeneous(0
#line 58 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
, point, _s
#line 49 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
));}}}static void _stencil_boundary2(Point point,Point neighbor,scalar _s,_stencil_undefined *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 49 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;     
  
  
   
                                              
  

  





   

  



  



  

  

  
  

  





  
   
   
  
#line 180 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
Point parent = point; 
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 49 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{return ;}}}static double _boundary2(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 49 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 49 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{return( dirichlet(0
#line 52 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
, point, _s
#line 49 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
));}}}
static double _boundary3_homogeneous(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 50 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 50 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{return( dirichlet_homogeneous(0
#line 58 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
, point, _s
#line 50 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
));}}}static void _stencil_boundary3(Point point,Point neighbor,scalar _s,_stencil_undefined *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 50 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;     
  
  
   
                                              
  

  





   

  



  



  

  

  
  

  





  
   
   
  
#line 180 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
Point parent = point; 
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 50 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{return ;}}}static double _boundary3(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 50 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{int ig=neighbor.i-point.i;if(ig==0)ig=_attribute[_s.i].d.x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attribute[_s.i].d.y;NOT_UNUSED(jg);  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 50 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{return( dirichlet(0
#line 52 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h"
, point, _s
#line 50 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
));}}}





static int defaults_1_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i = 0)!=0;*ip=i;*tp=t;return ret;}      static int defaults_1(const int i,const double t,Event *_ev){tracing("defaults_1","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h",0); {
  CFL = 0.8;




  display ("squares (color = 'omega', spread = -1);"
#line 526 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h"
, false
#line 62 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
);
}{end_tracing("defaults_1","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h",0);return 0;}end_tracing("defaults_1","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h",0);}






static int velocity_0_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i++)!=0;*ip=i;*tp=t;return ret;}      static int velocity_0(const int i,const double t,Event *_ev){tracing("velocity_0","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h",0);
{
  mgpsi = poisson (psi, omega
#line 409 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h"
,
( vector) {{-1}},
( scalar) {-1}, 
0., 
4, 
0, 
NULL, 
NULL
#line 72 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
);
#line 83 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
  trash (((vector[]){uf,{{-1},{-1}}}));
  coord f = {-1.,1.};  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 1;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};
#line 85 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{ 
#line 394 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
_loop.face |= (1 << 0);    
#line 86 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{_stencil_val(psi,0,1,0); _stencil_val(psi,-1,1,0); _stencil_val(psi,0,-1,0); _stencil_val(psi,-1,-1,0);_stencil_val_a(uf.x,0,0,0);     } 
#line 395 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../stencils.h"
_loop.face |= (1 << 1);    
#line 86 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{_stencil_val(psi,1,0,0); _stencil_val(psi,1,-1,0); _stencil_val(psi,-1,0,0); _stencil_val(psi,-1,-1,0);_stencil_val_a(uf.y,0,0,0);     }}
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (
#line 121
(
#line 85 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="uf",.type=sym_VECTOR,.global=1,.pointer=(void *)&uf},{.name="f",.type=sym_COORD,.pointer=(void *)&f},{.name="psi",.type=sym_SCALAR,.global=1,.pointer=(void *)&psi},{0}}
#line 121 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), "\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nif (point.j < point.n.y + 2) {\n    int ig = -1; NOT_UNUSED(ig);    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\nval_out_(uf.x,0,0,0) = f.x*(val(psi,0,1,0) + val(psi,-1,1,0) - val(psi,0,-1,0) - val(psi,-1,-1,0))/(4.f*Delta);}\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n  \n\n\nif (point.i < point.n.x + 2) {\n    int jg = -1; NOT_UNUSED(jg);    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_y = Delta;\n\n  real Delta_x = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_y);\n\n  NOT_UNUSED(Delta_x);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\nval_out_(uf.y,0,0,0) = f.y*(val(psi,1,0,0) + val(psi,1,-1,0) - val(psi,-1,0,0) - val(psi,-1,-1,0))/(4.f*Delta);}\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n}");
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 300 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 85 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{
  
#line 353 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
if (point.j < point.n.y + 2) {
    int ig = -1; NOT_UNUSED(ig);    
#line 86 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 86 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
val(uf.x,0,0,0) = f.x*(val(psi,0,1,0) + val(psi,-1,1,0) - val(psi,0,-1,0) - val(psi,-1,-1,0))/(4.*Delta);}
  
#line 356 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  


if (point.i < point.n.x + 2) {
    int jg = -1; NOT_UNUSED(jg);    
#line 86 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 86 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
val(uf.y,0,0,0) = f.y*(val(psi,1,0,0) + val(psi,1,-1,0) - val(psi,-1,0,0) - val(psi,-1,-1,0))/(4.*Delta);}
  
#line 363 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
#line 86 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
}
      
#line 317 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }

#line 87 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
}{end_tracing("velocity_0","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h",0);return 0;}end_tracing("velocity_0","/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h",0);}
#line 14 "turbulence.c"






int main (int argc, char * argv[]) {


_init_solver();  
#line 21
gpu_init_grid(argc > 1 ? atoi(argv[1]) : 256);
  run();
free_solver();}





static int init_0_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(i = 0)!=0;*ip=i;*tp=t;return ret;}      static int init_0(const int i,const double t,Event *_ev){tracing("init_0","turbulence.c",0); {

  double a = 1.;  
#line 14 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ;

#line 33
{
  ;
  static ForeachData _loop = { .fname = "turbulence.c", .func = __func__, .line = 0, .first = 1 };
  _loop.parallel = 2;
  if (baseblock)
    for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
      _attribute[s.i].stencil.io = 0;
      _attribute[s.i].stencil.width = 0;
    }
  int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
  Point point = {0}; NOT_UNUSED (point);
  RegionParameters _region = {0};    
#line 33 "turbulence.c"
{_stencil_val_a(omega,0,0,0);  }
#line 61 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
  bool _first = _loop.first;
  _loop.first = 0;
  check_stencil (&_loop);
  _loop.first = _first;
  _gpu_done_ = gpu_end_stencil (&_loop, &_region, (







(
#line 32 "turbulence.c"
(External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="omega",.type=sym_SCALAR,.global=1,.pointer=(void *)&omega},{.name="a",.type=49,.pointer=(void *)&a},{.name="noise",.type=sym_function_definition,.pointer=(void *)(long)noise},{0}}
#line 73 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
)
#line 65
), NULL);
  _loop.first = 0;
  ;
}    
#line 19
;
  }  
#line 14
if (_gpu_done_)
    _gpu_done_ = false;
  else {
    ; 
#line 265 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
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
#line 33 "turbulence.c"
{  
#line 3 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h"
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
  
#line 176 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
int level = point.level; NOT_UNUSED(level);
  struct { int x, y; } child = {
    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1
  }; NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;
#line 33 "turbulence.c"
val(omega,0,0,0) = a*noise();}
      
#line 282 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h"
}
  }
}    
#line 19 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/gpu.h"
;
  }

#line 34 "turbulence.c"
}{end_tracing("init_0","turbulence.c",0);return 0;}end_tracing("init_0","turbulence.c",0);}
#line 50
static int snap_ini_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(t=0)!=0;*ip=i;*tp=t;return ret;}
#line 50 "turbulence.c"
      static int snap_ini(const int i,const double t,Event *_ev){tracing("snap_ini","turbulence.c",0); {
  output_ppm (omega
#line 595 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
, 
fout, 
N
#line 51 "turbulence.c"
, "omega_ini", -0.3, 0.3
#line 599 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
, 5, 
0, 
false,
(   coord[2]) {{X0, Y0}, {X0 + L0, Y0 + L0*Dimensions.y/Dimensions.x}},
(   scalar) {-1}, 
jet, 
NULL, 
0, 
NULL
#line 51 "turbulence.c"
);
}{end_tracing("snap_ini","turbulence.c",0);return 0;}end_tracing("snap_ini","turbulence.c",0);}
static int snap_end_expr0(int *ip,double *tp,Event *_ev){int i=*ip;double t=*tp;int ret=(t=1000)!=0;*ip=i;*tp=t;return ret;}      static int snap_end(const int i,const double t,Event *_ev){tracing("snap_end","turbulence.c",0); {
  output_ppm (omega
#line 595 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
, 
fout, 
N
#line 54 "turbulence.c"
, "omega_end", -0.3, 0.3
#line 599 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h"
, 5, 
0, 
false,
(   coord[2]) {{X0, Y0}, {X0 + L0, Y0 + L0*Dimensions.y/Dimensions.x}},
(   scalar) {-1}, 
jet, 
NULL, 
0, 
NULL
#line 54 "turbulence.c"
);
}{end_tracing("snap_end","turbulence.c",0);return 0;}end_tracing("snap_end","turbulence.c",0);}
#line 2 "ast/init_solver.h"

static void _init_solver (void)
{
  void init_solver();
datasize=4*sizeof(real);  init_solver();
  {
#line 24
hip_multigrid_methods();register_function ((void (*)(void))compar_self,"compar_self","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h\"\n int compar_self (const void * p1, const void * p2)\n{\n  const TraceIndex * t1 = p1, * t2 = p2;\n  return t1->self < t2->self;\n}",NULL);
register_function ((void (*)(void))free_display_defaults,"free_display_defaults","\n@error /lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h:0: GLSL: error: unknown function 'pfree'\n",((External[]){{.name="display_defaults",.type=42,.global=1,.pointer=(void *)display_defaults,.nd=1},{0}}));
register_function ((void (*)(void))box_boundary_level,"box_boundary_level","\n@error /lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h:0: GLSL: error: unknown function 'disable_fpe'\n",((External[]){{.name=".block",.type=44,.nd=attroffset(block)},{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{.name=".face",.type=44,.nd=attroffset(face)},{.name=".v",.type=sym_VECTOR,.nd=attroffset(v)},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="periodic_bc",.type=sym_function_definition,.pointer=(void *)(long)periodic_bc},{.name="is_vertex_scalar",.type=sym_function_definition,.pointer=(void *)(long)is_vertex_scalar},{.name="list_len",.type=sym_function_definition,.pointer=(void *)(long)list_len},{.name="list_append",.type=sym_function_definition,.pointer=(void *)(long)list_append},{0}}));
register_function ((void (*)(void))periodic_boundary_level_x,"periodic_boundary_level_x","\n@error /lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h:0: GLSL: error: unknown function 'pfree'\n",((External[]){{.name=".block",.type=44,.nd=attroffset(block)},{.name=".face",.type=44,.nd=attroffset(face)},{.name="right",.type=sym_enumeration_constant,.global=1,.nd=right},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="periodic_bc",.type=sym_function_definition,.pointer=(void *)(long)periodic_bc},{.name="list_len",.type=sym_function_definition,.pointer=(void *)(long)list_len},{.name="list_append",.type=sym_function_definition,.pointer=(void *)(long)list_append},{.name="list_add",.type=sym_function_definition,.pointer=(void *)(long)list_add},{.name="Dimensions",.type=sym_IVEC,.global=1,.pointer=(void *)&Dimensions},{0}}));
register_function ((void (*)(void))periodic_boundary_level_y,"periodic_boundary_level_y","\n@error /lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h:0: GLSL: error: unknown function 'pfree'\n",((External[]){{.name=".block",.type=44,.nd=attroffset(block)},{.name=".face",.type=44,.nd=attroffset(face)},{.name="top",.type=sym_enumeration_constant,.global=1,.nd=top},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="periodic_bc",.type=sym_function_definition,.pointer=(void *)(long)periodic_bc},{.name="list_len",.type=sym_function_definition,.pointer=(void *)(long)list_len},{.name="list_append",.type=sym_function_definition,.pointer=(void *)(long)list_append},{.name="list_add",.type=sym_function_definition,.pointer=(void *)(long)list_add},{.name="Dimensions",.type=sym_IVEC,.global=1,.pointer=(void *)&Dimensions},{0}}));
register_function ((void (*)(void))caught_fpe,"caught_fpe","\n@error /lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../fpe.h:0: GLSL: error: unknown function 'fprintf'\n",((External[]){{.name="last_point",.type=151,.global=1,.pointer=(void *)&last_point},{.name="debug",.type=sym_function_declaration,.pointer=(void *)(long)debug},{.name="gdb",.type=sym_function_definition,.pointer=(void *)(long)gdb},{0}}));
register_function ((void (*)(void))caught_segfault,"caught_segfault","\n@error /lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../fpe.h:0: GLSL: error: unknown function 'fprintf'\n",((External[]){{.name="last_point",.type=151,.global=1,.pointer=(void *)&last_point},{.name="debug",.type=sym_function_declaration,.pointer=(void *)(long)debug},{.name="gdb",.type=sym_function_definition,.pointer=(void *)(long)gdb},{0}}));
register_function ((void (*)(void))caught_abort,"caught_abort","\n@error /lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../fpe.h:0: GLSL: error: unknown function 'fprintf'\n",((External[]){{.name="last_point",.type=151,.global=1,.pointer=(void *)&last_point},{.name="debug",.type=sym_function_declaration,.pointer=(void *)(long)debug},{.name="gdb",.type=sym_function_definition,.pointer=(void *)(long)gdb},{0}}));
register_function ((void (*)(void))symmetry,"symmetry","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\n real symmetry (Point point, Point neighbor, scalar s, bool * data)\n{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\nreturn val(s,0,0,0);\n}",((External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{0}}));
register_function ((void (*)(void))antisymmetry,"antisymmetry","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\n real antisymmetry (Point point, Point neighbor, scalar s, bool * data)\n{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\nreturn -val(s,0,0,0);\n}",((External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{0}}));
register_function ((void (*)(void))interpolate_linear,"interpolate_linear","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\n real interpolate_linear (Point point, scalar v,\n      real xp, real yp, real zp)\n{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n\n\n\n\n\n\n\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\nx = (xp - x)/Delta -_attr( v,d).x/2.f;\n  y = (yp - y)/Delta -_attr( v,d).y/2.f;\n  int i = (int ((x > 0 ? 1 : -1))), j = (int ((y > 0 ? 1 : -1)));\n  x = fabs(x); y = fabs(y);\n\n  return ((val(v,0,0,0)*(1.f - x) + val(v,i,0,0)*x)*(1.f - y) +\n   (val(v,0,j,0)*(1.f - x) + val(v,i,j,0)*x)*y);\n// # 963 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\n}",((External[]){{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{0}}));
register_function ((void (*)(void))periodic_bc,"periodic_bc","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\n real periodic_bc (Point point, Point neighbor, scalar s, bool * data)\n{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\nreturn val(s,0,0,0);\n}",((External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{0}}));
register_function ((void (*)(void))refine_bilinear,"refine_bilinear","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n  void refine_bilinear (Point point, scalar s)\n{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n  \n  \n// #line 0\n{\n    int _i = 2*point.i - 2, _j = 2*point.j - 2;\n    point.level++;\n    point.n.x *= 2, point.n.y *= 2;\n    for (int _k = 0; _k < 2; _k++)\n      for (int _l = 0; _l < 2; _l++) {\n point.i = _i + _k; point.j = _j + _l; \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;      \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\nval_out_(s,0,0,0) = bilinear (point, s);\n      \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n    point.i = (_i + 2)/2; point.j = (_j + 2)/2;\n    point.level--;\n    point.n.x /= 2, point.n.y /= 2;\n  }\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n}",((External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="bilinear",.type=sym_function_definition,.pointer=(void *)(long)bilinear},{0}}));
register_function ((void (*)(void))restriction_average,"restriction_average","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n  void restriction_average (Point point, scalar s)\n{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n{\n    real sum = 0.f;\n  \n    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n{\n    int _i = 2*point.i - 2, _j = 2*point.j - 2;\n    point.level++;\n    point.n.x *= 2, point.n.y *= 2;\n    for (int _k = 0; _k < 2; _k++)\n      for (int _l = 0; _l < 2; _l++) {\n point.i = _i + _k; point.j = _j + _l; \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;      \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\nsum += val(s,0,0,0);\n      \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\n}\n    point.i = (_i + 2)/2; point.j = (_j + 2)/2;\n    point.level--;\n    point.n.x /= 2, point.n.y /= 2;\n  }    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\nval_out_(s,0,0,0) = sum/(1 << 2);\n  }\n}",((External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{0}}));
register_function ((void (*)(void))restriction_vertex,"restriction_vertex","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n  void restriction_vertex (Point point, scalar s)\n{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\nfor (int i = 0; i <= 1; i++) {\n      val_out_(s,i,0,0) = fine(s,2*i,0,0);\n\n      val_out_(s,i,1,0) = fine(s,2*i,2,0);\n\n\n\n\n\n    }\n}",((External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{0}}));
register_function ((void (*)(void))no_restriction,"no_restriction","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n  void no_restriction (Point point, scalar s) {}",NULL);
register_function ((void (*)(void))restriction_face,"restriction_face","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n  void restriction_face (Point point, scalar s)\n{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\nface_average (point,_attr( s,v));\n}",((External[]){{.name=".v",.type=sym_VECTOR,.nd=attroffset(v)},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="face_average",.type=sym_function_definition,.pointer=(void *)(long)face_average},{0}}));
register_function ((void (*)(void))boundary_top,"boundary_top","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h\"\n void boundary_top (Point point, int i)\n{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h\"\nbool data = false;\n  {forin (scalar, s , apply_bc_list)\n    if (!bool(_attr(s,face)) || s.i !=_attr( s,v).y.i) {\n      scalar b = (_attr(s,v).x.i < 0 ? s : s.i ==_attr( s,v).y.i ?_attr( s,v).x :_attr( s,v).y);\n     \n val_out_(s,i,-bc_period_y,0) = _attr_boundary_top(b, (neighborp(i,0,0), neighborp(i,-bc_period_y,0), s, &data));\n    } endforin()}\n}",((External[]){{.name=".face",.type=44,.nd=attroffset(face)},{.name=".v",.type=sym_VECTOR,.nd=attroffset(v)},{.name=".boundary_top",.type=sym_function_declaration,.nd=attroffset(boundary_top)},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="apply_bc_list",.type=sym_SCALAR,.global=1,.pointer=(void *)apply_bc_list,.nd=1},{.name="bc_period_y",.type=44,.global=1,.pointer=(void *)&bc_period_y},{0}}));
register_function ((void (*)(void))boundary_bottom,"boundary_bottom","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h\"\n void boundary_bottom (Point point, int i)\n{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h\"\nbool data = false;\n  {forin (scalar, s , apply_bc_list)\n    if (!bool(_attr(s,face)) || s.i !=_attr( s,v).y.i) {\n      scalar b = (_attr(s,v).x.i < 0 ? s : s.i ==_attr( s,v).y.i ?_attr( s,v).x :_attr( s,v).y);\n     \n val_out_(s,i,bc_period_y,0) = _attr_boundary_bottom(b, (neighborp(i,0,0), neighborp(i,bc_period_y,0), s, &data));\n    } endforin()}\n}",((External[]){{.name=".face",.type=44,.nd=attroffset(face)},{.name=".v",.type=sym_VECTOR,.nd=attroffset(v)},{.name=".boundary_bottom",.type=sym_function_declaration,.nd=attroffset(boundary_bottom)},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="apply_bc_list",.type=sym_SCALAR,.global=1,.pointer=(void *)apply_bc_list,.nd=1},{.name="bc_period_y",.type=44,.global=1,.pointer=(void *)&bc_period_y},{0}}));
register_function ((void (*)(void))gpu_free,"gpu_free","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h\"\nvoid gpu_free()\n{\n  if (!bool(grid))\n    return;\n  free_boundaries();\n  if (bool((GridGPU *(grid))->shaders)) {\n    Shader * shader;\n    int nshaders = 0;\n    { khint_t __i; for (__i =khint_t ((0)); __i != (((GridGPU *(grid))->shaders)->n_buckets); ++__i) { if (!(!bool(((((GridGPU *(grid))->shaders)->flags[(__i)>>4]>>(((__i)&0xfU)<<1))&3)))) continue; (shader) = (((GridGPU *(grid))->shaders)->vals[__i]); free_shader (shader); nshaders++;; } }\n\n                                   ;\n\n\n\n    kh_destroy_INT((GridGPU *(grid))->shaders);\n    (GridGPU *(grid))->shaders = NULL;\n    gpu_free_context ((GridGPU *(grid))->data);\n    (GridGPU *(grid))->data = NULL;\n  }\n}",((External[]){{.name="grid",.type=sym_TYPEDEF,.global=1,.pointer=(void *)grid,.nd=1},{.name="boundaries",.type=151,.global=1,.pointer=(void *)boundaries,.nd=2},{.name="free_boundaries",.type=sym_function_definition,.pointer=(void *)(long)free_boundaries},{.name="kh_destroy_INT",.type=sym_function_definition,.pointer=(void *)(long)kh_destroy_INT},{0}}));
register_function ((void (*)(void))apply_bc,"apply_bc","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h\"\n\nvoid apply_bc (Point point)\n{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/grid.h\"\nbool data = false;\n\n  if (point.i == 2)\n    {forin (scalar, s , apply_bc_list)\n      if (bool(_attr(s,face)) && s.i ==_attr( s,v).x.i &&bool(_attr( s,boundary_left)))\n\n   val_out_(s,0,0,0) = _attr_boundary_left(s, (point, neighborp(bc_period_x,0,0), s, &data)); endforin()}\n  if (point.i == N*Dimensions.x + 2)\n    {forin (scalar, s , apply_bc_list)\n      if (bool(_attr(s,face)) && s.i ==_attr( s,v).x.i &&bool(_attr( s,boundary_right)))\n\n   val_out_(s,0,0,0) = _attr_boundary_right(s, (neighborp(bc_period_x,0,0), point, s, &data)); endforin()}\n  if (point.j == 2)\n    {forin (scalar, s , apply_bc_list)\n      if (bool(_attr(s,face)) && s.i ==_attr( s,v).y.i) {\n scalar b =_attr( s,v).x;\n if (bool(_attr(b,boundary_bottom)))\n  \n     val_out_(s,0,0,0) = _attr_boundary_bottom(b, (point, neighborp(0,bc_period_y,0), s, &data));\n      } endforin()}\n  if (point.j == N*Dimensions.y + 2)\n    {forin (scalar, s , apply_bc_list)\n      if (bool(_attr(s,face)) && s.i ==_attr( s,v).y.i) {\n scalar b =_attr( s,v).x;\n if (bool(_attr(b,boundary_top)))\n  \n     val_out_(s,0,0,0) = _attr_boundary_top(b, (neighborp(0,bc_period_y,0), point, s, &data));\n      } endforin()}\n\n  if (point.i == 2) {\n    {forin (scalar, s , apply_bc_list)\n      if (!bool(_attr(s,face)) || s.i !=_attr( s,v).x.i)\n\n   val_out_(s,bc_period_x,0,0) = _attr_boundary_left(s, (point, neighborp(bc_period_x,0,0), s, &data)); endforin()}\n    if (point.j == 2)\n      boundary_bottom (point, bc_period_x);\n    if (point.j == N*Dimensions.y + 2 - 1)\n      boundary_top (point, bc_period_x);\n  }\n  if (point.i == N*Dimensions.x + 2 - 1) {\n    {forin (scalar, s , apply_bc_list)\n      if (!bool(_attr(s,face)) || s.i !=_attr( s,v).x.i)\n\n   val_out_(s,- bc_period_x,0,0) = _attr_boundary_right(s, (point, neighborp(- bc_period_x,0,0), s, &data)); endforin()}\n    if (point.j == 2)\n      boundary_bottom (point, - bc_period_x);\n    if (point.j == N*Dimensions.y + 2 - 1)\n      boundary_top (point, - bc_period_x);\n  }\n  if (point.j == 2)\n    boundary_bottom (point, 0);\n  if (point.j == N*Dimensions.y + 2 - 1)\n    boundary_top (point, 0);\n}",((External[]){{.name=".face",.type=44,.nd=attroffset(face)},{.name=".v",.type=sym_VECTOR,.nd=attroffset(v)},{.name=".boundary_left",.type=sym_function_declaration,.nd=attroffset(boundary_left)},{.name=".boundary_right",.type=sym_function_declaration,.nd=attroffset(boundary_right)},{.name=".boundary_bottom",.type=sym_function_declaration,.nd=attroffset(boundary_bottom)},{.name=".boundary_top",.type=sym_function_declaration,.nd=attroffset(boundary_top)},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="apply_bc_list",.type=sym_SCALAR,.global=1,.pointer=(void *)apply_bc_list,.nd=1},{.name="bc_period_x",.type=44,.global=1,.pointer=(void *)&bc_period_x},{.name="N",.type=44,.global=1,.pointer=(void *)&N},{.name="Dimensions",.type=sym_IVEC,.global=1,.pointer=(void *)&Dimensions},{.name="bc_period_y",.type=44,.global=1,.pointer=(void *)&bc_period_y},{.name="boundary_bottom",.type=sym_function_definition,.pointer=(void *)(long)boundary_bottom},{.name="boundary_top",.type=sym_function_definition,.pointer=(void *)(long)boundary_top},{0}}));
register_function ((void (*)(void))open_image_cleanup,"open_image_cleanup","\n@error /lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h:0: GLSL: error: unknown function 'pfree'\n",((External[]){{.name="open_image_data",.type=151,.global=1,.pointer=(void *)&open_image_data},{.name="qpopen_pipes",.type=50,.global=1,.pointer=(void *)qpopen_pipes,.nd=2},{.name="qpclose",.type=sym_function_definition,.pointer=(void *)(long)qpclose},{0}}));
register_function ((void (*)(void))jet,"jet","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h\"\nvoid jet (real cmap[127][3])\n{\n  for (int i = 0; i < 127; i++) {\n    cmap[i][0] =\n      i <= 46 ? 0.f :\n      i >= 111 ? -0.03125f*(i - 111) + 1.f :\n      i >= 78 ? 1.f :\n      0.03125f*(i - 46);\n    cmap[i][1] =\n      i <= 14 || i >= 111 ? 0.f :\n      i >= 79 ? -0.03125f*(i - 111) :\n      i <= 46 ? 0.03125f*(i - 14) :\n      1.f;\n    cmap[i][2] =\n      i >= 79 ? 0.f :\n      i >= 47 ? -0.03125f*(i - 79) :\n      i <= 14 ? 0.03125f*(i - 14) + 1.f:\n      1.f;\n  }\n}",NULL);
register_function ((void (*)(void))colormap_color,"colormap_color","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/output.h\"\nColor colormap_color (real cmap[127][3],\n        real _val, real min, real max)\n{\n  Color c;\n  if (_val == 1e30f) {\n    c.r = c.g = c.b = 0;\n    return c;\n  }\n  int i;\n  real coef;\n  if (max != min)\n    _val = (_val - min)/(max - min);\n  else\n    _val = 0.f;\n  if (_val <= 0.f) i = 0, coef = 0.f;\n  else if (_val >= 1.f) i = 127 - 2, coef = 1.f;\n  else {\n    i = _val*(127 - 1);\n    coef = _val*(127 - 1) - i;\n  }\n  if (i < 0 || i >= 127 - 1)\n    returnColor (99,55,43);\n  uint char * c1 =unsigned char * ( &c);\n  for (int j = 0; j < 3; j++)\n    c1[j] = 255*(cmap[i][j]*(1.f - coef) + cmap[i + 1][j]*coef);\n  return c;\n}",NULL);
register_function ((void (*)(void))bilinear,"bilinear","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n  real bilinear (Point point, scalar s)\n{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\nreturn (9.f*coarse(s,0,0,0) +\n     3.f*(coarse(s,child.x,0,0) + coarse(s,0,child.y,0)) +\n     coarse(s,child.x,child.y,0))/16.f;\n// # 162 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n}",((External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{0}}));
register_function ((void (*)(void))residual,"residual","\n@error /lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h:0: GLSL: error: unknown function 'val_a'\n",((External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="sym_SCALAR",.type=sym_enumeration_constant,.global=1,.nd=sym_SCALAR},{.name="sym_VECTOR",.type=sym_enumeration_constant,.global=1,.nd=sym_VECTOR},{.name="_constant",.type=49,.global=1,.pointer=(void *)_constant,.nd=1},{.name="sym__COORD",.type=sym_enumeration_constant,.global=1,.nd=sym__COORD},{0}}));
register_function ((void (*)(void))relax,"relax","\n@error /lus/home/CT2B/cad16450/atsetoglou/basilisk/src/poisson.h:0: GLSL: error: unknown function 'val_a'\n",((External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="sym_SCALAR",.type=sym_enumeration_constant,.global=1,.nd=sym_SCALAR},{.name="sym_VECTOR",.type=sym_enumeration_constant,.global=1,.nd=sym_VECTOR},{.name="_constant",.type=49,.global=1,.pointer=(void *)_constant,.nd=1},{.name="sym__COORD",.type=sym_enumeration_constant,.global=1,.nd=sym__COORD},{0}}));
register_function ((void (*)(void))noise,"noise","\n@error /lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h:0: GLSL: error: unknown function 'rand'\n",NULL);
register_function ((void (*)(void))_boundary0,"_boundary0","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n real _boundary0(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{int ig=neighbor.i-point.i;if(ig==0)ig=_attr(_s,d).x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attr(_s,d).y;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{return( dirichlet(0\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\n, point, _s\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n));}}}",((External[]){{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="dirichlet",.type=sym_function_definition,.pointer=(void *)(long)dirichlet},{0}}));
register_function ((void (*)(void))_boundary0_homogeneous,"_boundary0_homogeneous","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n real _boundary0_homogeneous(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{int ig=neighbor.i-point.i;if(ig==0)ig=_attr(_s,d).x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attr(_s,d).y;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{return( dirichlet_homogeneous(0\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\n, point, _s\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n));}}}",((External[]){{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="dirichlet_homogeneous",.type=sym_function_definition,.pointer=(void *)(long)dirichlet_homogeneous},{0}}));
register_function ((void (*)(void))_stencil_boundary0,"_stencil_boundary0","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n void _stencil_boundary0(Point point,Point neighbor,scalar _s,_stencil_undefined *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{int ig=neighbor.i-point.i;if(ig==0)ig=_attr(_s,d).x;int jg=neighbor.j-point.j;if(jg==0)jg=_attr(_s,d).y;     \n  \n  \n   \n                                              \n  \n\n  \n\n\n\n\n\n   \n\n  \n\n\n\n  \n\n\n\n  \n\n  \n\n  \n  \n\n  \n\n\n\n\n\n  \n   \n   \n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nPoint parent = point; \n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{return ;}}}",((External[]){{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{0}}));
register_function ((void (*)(void))_boundary1,"_boundary1","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n real _boundary1(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{int ig=neighbor.i-point.i;if(ig==0)ig=_attr(_s,d).x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attr(_s,d).y;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{return( dirichlet(0\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\n, point, _s\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n));}}}",((External[]){{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="dirichlet",.type=sym_function_definition,.pointer=(void *)(long)dirichlet},{0}}));
register_function ((void (*)(void))_boundary1_homogeneous,"_boundary1_homogeneous","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n real _boundary1_homogeneous(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{int ig=neighbor.i-point.i;if(ig==0)ig=_attr(_s,d).x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attr(_s,d).y;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{return( dirichlet_homogeneous(0\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\n, point, _s\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n));}}}",((External[]){{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="dirichlet_homogeneous",.type=sym_function_definition,.pointer=(void *)(long)dirichlet_homogeneous},{0}}));
register_function ((void (*)(void))_stencil_boundary1,"_stencil_boundary1","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n void _stencil_boundary1(Point point,Point neighbor,scalar _s,_stencil_undefined *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{int ig=neighbor.i-point.i;if(ig==0)ig=_attr(_s,d).x;int jg=neighbor.j-point.j;if(jg==0)jg=_attr(_s,d).y;     \n  \n  \n   \n                                              \n  \n\n  \n\n\n\n\n\n   \n\n  \n\n\n\n  \n\n\n\n  \n\n  \n\n  \n  \n\n  \n\n\n\n\n\n  \n   \n   \n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nPoint parent = point; \n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{return ;}}}",((External[]){{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{0}}));
register_function ((void (*)(void))_boundary2,"_boundary2","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n real _boundary2(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{int ig=neighbor.i-point.i;if(ig==0)ig=_attr(_s,d).x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attr(_s,d).y;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{return( dirichlet(0\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\n, point, _s\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n));}}}",((External[]){{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="dirichlet",.type=sym_function_definition,.pointer=(void *)(long)dirichlet},{0}}));
register_function ((void (*)(void))_boundary2_homogeneous,"_boundary2_homogeneous","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n real _boundary2_homogeneous(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{int ig=neighbor.i-point.i;if(ig==0)ig=_attr(_s,d).x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attr(_s,d).y;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{return( dirichlet_homogeneous(0\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\n, point, _s\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n));}}}",((External[]){{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="dirichlet_homogeneous",.type=sym_function_definition,.pointer=(void *)(long)dirichlet_homogeneous},{0}}));
register_function ((void (*)(void))_stencil_boundary2,"_stencil_boundary2","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n void _stencil_boundary2(Point point,Point neighbor,scalar _s,_stencil_undefined *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{int ig=neighbor.i-point.i;if(ig==0)ig=_attr(_s,d).x;int jg=neighbor.j-point.j;if(jg==0)jg=_attr(_s,d).y;     \n  \n  \n   \n                                              \n  \n\n  \n\n\n\n\n\n   \n\n  \n\n\n\n  \n\n\n\n  \n\n  \n\n  \n  \n\n  \n\n\n\n\n\n  \n   \n   \n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nPoint parent = point; \n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{return ;}}}",((External[]){{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{0}}));
register_function ((void (*)(void))_boundary3,"_boundary3","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n real _boundary3(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{int ig=neighbor.i-point.i;if(ig==0)ig=_attr(_s,d).x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attr(_s,d).y;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{return( dirichlet(0\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\n, point, _s\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n));}}}",((External[]){{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="dirichlet",.type=sym_function_definition,.pointer=(void *)(long)dirichlet},{0}}));
register_function ((void (*)(void))_boundary3_homogeneous,"_boundary3_homogeneous","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n real _boundary3_homogeneous(Point point,Point neighbor,scalar _s,bool *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{int ig=neighbor.i-point.i;if(ig==0)ig=_attr(_s,d).x;NOT_UNUSED(ig);int jg=neighbor.j-point.j;if(jg==0)jg=_attr(_s,d).y;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{return( dirichlet_homogeneous(0\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\n, point, _s\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n));}}}",((External[]){{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{.name="dirichlet_homogeneous",.type=sym_function_definition,.pointer=(void *)(long)dirichlet_homogeneous},{0}}));
register_function ((void (*)(void))_stencil_boundary3,"_stencil_boundary3","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n void _stencil_boundary3(Point point,Point neighbor,scalar _s,_stencil_undefined *data){int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{int ig=neighbor.i-point.i;if(ig==0)ig=_attr(_s,d).x;int jg=neighbor.j-point.j;if(jg==0)jg=_attr(_s,d).y;     \n  \n  \n   \n                                              \n  \n\n  \n\n\n\n\n\n   \n\n  \n\n\n\n  \n\n\n\n  \n\n  \n\n  \n  \n\n  \n\n\n\n\n\n  \n   \n   \n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nPoint parent = point; \n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h\"\n{return ;}}}",((External[]){{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{0}}));
register_function ((void (*)(void))is_vertex_scalar,"is_vertex_scalar","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h\"\n  bool is_vertex_scalar (scalar s)\n{\n  \n    if (_attr(s,d).x != -1)\n      return false;    \n// #line 0\nif (_attr(s,d).y != -1)\n      return false;\n  return true;\n}",((External[]){{.name=".d",.type=sym_IVEC,.nd=attroffset(d)},{0}}));
register_function ((void (*)(void))list_len,"list_len","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h\"\nint list_len (scalar  list[2])\n{\n  if (!bool(list)) return 0;\n  int ns = 0;\n  {forin (scalar, s , list) ns++; endforin()}\n  return ns;\n}",NULL);
register_function ((void (*)(void))list_append,"list_append","\n@error /lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h:0: GLSL: error: unknown function 'prealloc'\n",((External[]){{.name="list_len",.type=sym_function_definition,.pointer=(void *)(long)list_len},{0}}));
register_function ((void (*)(void))list_add,"list_add","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h\"\nscalar * list_add (scalar  list[2], scalar s)\n{\n  {forin (scalar, t , list)\n    if (t.i == s.i)\n      return list; endforin()}\n  return list_append (list, s);\n}",((External[]){{.name="list_len",.type=sym_function_definition,.pointer=(void *)(long)list_len},{.name="list_append",.type=sym_function_definition,.pointer=(void *)(long)list_append},{0}}));
register_function ((void (*)(void))gdb,"gdb","\n@error /lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../fpe.h:0: GLSL: error: unknown function 'fputc'\n",((External[]){{.name="last_point",.type=151,.global=1,.pointer=(void *)&last_point},{.name="debug",.type=sym_function_declaration,.pointer=(void *)(long)debug},{0}}));
register_function ((void (*)(void))face_average,"face_average","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n  void face_average (Point point, vector v)\n{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;    \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid-common.h\"\n{\n\n\n\n\n      val_out_(v.x,0,0,0) = (fine(v.x,0,0,0) + fine(v.x,0,1,0))/2.f;\n      val_out_(v.x,1,0,0) = (fine(v.x,2,0,0) + fine(v.x,2,1,0))/2.f;\n\n\n\n\n\n\n  }    \n// #line 0\n{\n\n\n\n\n      val_out_(v.y,0,0,0) = (fine(v.y,0,0,0) + fine(v.y,1,0,0))/2.f;\n      val_out_(v.y,0,1,0) = (fine(v.y,0,2,0) + fine(v.y,1,2,0))/2.f;\n\n\n\n\n\n\n  }\n}",((External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{0}}));
register_function ((void (*)(void))free_boundaries,"free_boundaries","\n@error /lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/boundaries.h:0: GLSL: error: unknown function 'pfree'\n",((External[]){{.name="boundaries",.type=151,.global=1,.pointer=(void *)boundaries,.nd=2},{0}}));
register_function ((void (*)(void))kh_destroy_INT,"kh_destroy_INT","\n@error /lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../gpu/backend.h:0: GLSL: error: unknown function 'pfree'\n",NULL);
register_function ((void (*)(void))qpclose,"qpclose","\n@error /lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/config.h:0: GLSL: error: unknown function 'pid'\n",((External[]){{.name="qpopen_pipes",.type=50,.global=1,.pointer=(void *)qpopen_pipes,.nd=2},{0}}));
register_function ((void (*)(void))dirichlet,"dirichlet","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\n \nreal dirichlet (real expr, Point point, scalar s)\n{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\nreturn 2.f*expr - val(s,0,0,0);\n}",((External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{0}}));
register_function ((void (*)(void))dirichlet_homogeneous,"dirichlet_homogeneous","\n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\n \nreal dirichlet_homogeneous (real expr, Point point, scalar s)\n{int ig=0;NOT_UNUSED(ig);int jg=0;NOT_UNUSED(jg);  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../variables.h\"\nreal Delta = L0*(1.f/((1 << point.level)*Dimensions_scale));\n  real Delta_x = Delta;\n\n  real Delta_y = Delta;\n\n\n\n\n\n  real x = ((ig + 1)/2.f + (point.i - 2))*Delta + X0; NOT_UNUSED(x);\n\n  real y = ((jg + 1)/2.f + (point.j - 2))*Delta + Y0;\n\n\n\n  NOT_UNUSED(y);\n\n\n\n  real z = 0.f;\n\n  NOT_UNUSED(z);\n\n  NOT_UNUSED(Delta);\n  NOT_UNUSED(Delta_x);\n\n  NOT_UNUSED(Delta_y);\n\n\n\n\n\n  ;\n  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../multigrid.h\"\nint level = point.level; NOT_UNUSED(level);\n  struct { int x, y; } child = {\n    2*((point.i+2)%2)-1, 2*((point.j+2)%2)-1\n  }; NOT_UNUSED(child);\n  Point parent = point; NOT_UNUSED(parent);\n  parent.level--;\n  parent.i = (point.i + 2)/2; parent.j = (point.j + 2)/2;  \n// #line 0 \"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/grid/hip/../cartesian-common.h\"\nreturn - val(s,0,0,0);\n}",((External[]){{.name="L0",.type=49,.global=1,.pointer=(void *)&L0},{.name="Dimensions_scale",.type=44,.global=1,.pointer=(void *)&Dimensions_scale},{.name="X0",.type=49,.global=1,.pointer=(void *)&X0},{.name="Y0",.type=49,.global=1,.pointer=(void *)&Y0},{0}}));


    

    
#line 12
{
      
      
    
      {  
#line 42 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/run.h"
event_register((Event){0,1,defaults,{defaults_expr0},((int *)0),((double *)0),"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/run.h",0,"defaults"});  
#line 37 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/advection.h"
event_register((Event){0,1,defaults_0,{defaults_0_expr0},((int *)0),((double *)0),"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/advection.h",0,"defaults"});  







event_register((Event){0,1,init,{init_expr0},((int *)0),((double *)0),"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/advection.h",0,"init"});  
#line 56 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
event_register((Event){0,1,defaults_1,{defaults_1_expr0},((int *)0),((double *)0),"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h",0,"defaults"});  
#line 29 "turbulence.c"
event_register((Event){0,1,init_0,{init_0_expr0},((int *)0),((double *)0),"turbulence.c",0,"init"});  
#line 50
event_register((Event){0,1,snap_ini,{snap_ini_expr0},((int *)0),((double *)0),"turbulence.c",0,"snap_ini"});  


event_register((Event){0,1,snap_end,{snap_end_expr0},((int *)0),((double *)0),"turbulence.c",0,"snap_end"});
	
	
	
      
#line 22 "ast/init_solver.h"
}
#line 388 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/common.h"
init_const_vector((vector){{_NVARMAX+3},{_NVARMAX+4}},"zerof",(double[]){0.,0.,0.});
init_const_vector((vector){{_NVARMAX+5},{_NVARMAX+6}},"unityf",(double[]){1.,1.,1.});
init_const_scalar((scalar){_NVARMAX+7},"unity", 1.);
init_const_scalar((scalar){_NVARMAX+8},"zeroc", 0.);



init_const_vector((vector){{_NVARMAX+9},{_NVARMAX+10}},"fm",(double[]){1.,1.,1.});
init_const_scalar((scalar){_NVARMAX+11},"cm", 1.);  init_face_vector((vector){{0},{1}},"uf");  init_scalar((scalar){2},"omega");  init_scalar((scalar){3},"psi");    
#line 23 "ast/init_solver.h"
}set_dirty_stencil(psi),_attribute[psi.i].boundary[right]=_boundary0,_attribute[psi.i].boundary_homogeneous[right]=_boundary0_homogeneous,_attribute[psi.i].boundary_stencil[right]=_stencil_boundary0;set_dirty_stencil(psi),_attribute[psi.i].boundary[left]=_boundary1,_attribute[psi.i].boundary_homogeneous[left]=_boundary1_homogeneous,_attribute[psi.i].boundary_stencil[left]=_stencil_boundary1;set_dirty_stencil(psi),_attribute[psi.i].boundary[top]=_boundary2,_attribute[psi.i].boundary_homogeneous[top]=_boundary2_homogeneous,_attribute[psi.i].boundary_stencil[top]=_stencil_boundary2;set_dirty_stencil(psi),_attribute[psi.i].boundary[bottom]=_boundary3,_attribute[psi.i].boundary_homogeneous[bottom]=_boundary3_homogeneous,_attribute[psi.i].boundary_stencil[bottom]=_stencil_boundary3;  
#line 50 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/run.h"
event_register((Event){0,1,cleanup,{cleanup_expr0},((int *)0),((double *)0),"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/run.h",0,"cleanup"});  
#line 52 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/advection.h"
event_register((Event){0,1,velocity,{velocity_expr0},((int *)0),((double *)0),"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/advection.h",0,"velocity"});  
#line 43 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/tracer.h"
event_register((Event){0,1,tracer_advection,{tracer_advection_expr0},((int *)0),((double *)0),"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/tracer.h",0,"tracer_advection"});  






event_register((Event){0,1,vof,{vof_expr0},((int *)0),((double *)0),"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/tracer.h",0,"vof"});  




event_register((Event){0,1,tracer_diffusion,{tracer_diffusion_expr0},((int *)0),((double *)0),"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/tracer.h",0,"tracer_diffusion"});  
#line 70 "/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h"
event_register((Event){0,1,velocity_0,{velocity_0_expr0},((int *)0),((double *)0),"/lus/home/CT2B/cad16450/atsetoglou/basilisk/src/navier-stokes/stream.h",0,"velocity"});  
#line 24 "ast/init_solver.h"
}
  set_fpe();
}
