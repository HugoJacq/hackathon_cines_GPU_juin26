# Notes Hackathon

## Résumé

Ce qui a été fait

1) trouver les bon modules et flags pour compiler un program qui appelle la lib
`rocm` -> voir les fichiers de compile basilisk (qcc, liberrors.a, libhip.a,
voir ce [fichier](compile_bas) et compile d'un programme (voir ce
[fichier](compile_prog) et le run d'un programme (voir ce [fichier](run_prog))

2) finir d'adapter le code généré par hipify-perl pour que i) les instructions
soient correctement reconnues par le gpu amd (modification de
`src/grid/hip/hip.c`), ii) que la partie hip de Basilisk
se rattache au reste (modification de `src/grid/gpu/grid.h`)

Les pistes pour la suite

- l'exemple breaking.c crash avec `breaking.hip: hip.c:574: post_setup_shader:
Assertion false failed.`, est-ce un problème avec l'extension avec des couches ?

- profiler proprement un run sur gpu AMD. Est-on loin de la roofline ?

- le multigpu n'est pas forcement la panacée vu que je cherche plutot à faire
plus de pas de temps, et pas des domaines plus grands.

## Notes Hugo

### add -lhiprtc

for recent version of rocm (7.2.0)

### use hipcc to compile _??.c

### profiling

rocprofv3 --hip-trace --kernel-trace --memory-copy-trace -- ./turbulence.hip

### selection gpu

Les arguments de compilation on the fly sont différents de nvidia ! 
en particulier:

rajouter `-offload-arch=gfx90a`

### Bien charger un environnement unifié

utiliser le fichier [.env_bas](.env_bas)


## Profiling

Commande 1: regarder l'appel successifs. La commande génère un fichier .ptrace
qu'on ouvre sur ce [site](https://ui.perfetto.dev)
```bash
rocprofv3 --output-format=pftrace --hip-runtime-trace -- ./turbulence.hip $RES # 2> log > out
```

Commande 2: on regarde le temps total pour chaque kernel, output des csv
```bash
rocprofv3 --hip-trace --kernel-trace --memory-copy-trace -f csv -- ./turbulence.hip $RES # 2> log > out
```

exemple 1 : le gpu n'est pas utilisé. Voir le fichier
[3619281_results.pftrace](./profiling/3619281_results.pftrace)

exemple 2 : le gpu est utilisé. Voir le fichier
LIEN

Attention: lors du premier run, il y a une compilation des shaders. Il y a donc
un overhead assez important. Pour avoir une mesure de perf, il faut le refaire
tourner une deuxième fois (donc par exemple une première fois en basse
résolution puis on augmente ensuite)

## Pistes d'amélioration

- beaucoup de copies (Memcpy), à réduire ?
- multi GPU par mpi + transfers device to device ?

## Rapport Claude code

voir ce [fichier](basilisk_hip/HIP_AMD_PORT_REPORT.md)
