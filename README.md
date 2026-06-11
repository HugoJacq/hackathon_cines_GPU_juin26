# hackathon_cines_GPU_juin26

[Questions pour les ingé AMD](questions.md)

[Test case avec Basilisk](basilisk_test_case)

## Some results

`

### reference : OpenGL using RTX 4090


## Results: nonlinear.c

see this [file](results_nonlinear.md)

`$basilisk/test/non-linear.c` test case, 

first `make`, then run again at higher res (example for cpu run):
```
cd $BASILISK/test
cflags='-dtrace=2 -dmtrace=1' make non-linear.tst
cd non-linear/
./non-linear 512 > logs512
```

### recap

Elapsed time compared to GPU OpenGL

> local
CUDA x2.7 HIP(CUDA) x2.6
> Adastra


## Results: turbulence.c


see this [file](results_turbulence.md)

`$basilisk/test/turbulence.c` test case, 

first `make`, then run again at higher res (example for cpu run):
```
cd $BASILISK/test
cflags='-dtrace=2 -dmtrace=1' make turbulence.tst
cd turbulence/
./turbulence 512 > logs512
```

### recap

Elapsed time compared to GPU OpenGL

> local
CUDA x2.7 HIP(CUDA) x2.6
> Adastra



