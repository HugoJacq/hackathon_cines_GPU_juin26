# Basilisk test case

## How to compile and run (local)

> Compile the base Basilisk with [link](https://basilisk.fr/src/INSTALL)

> Compile for GPU, OpenGL (see [link](https://basilisk.fr/src/grid/gpu/grid.h#installation))
```
sudo apt install libglfw3-dev
cd $BASILISK/grid/gpu
make
```

> Compile for GPU, Nvidia
```
apt install cuda-driver-toolkit
cd $BASILISK/grid/cuda
make
```
The compilation (you might need to modify the Makefile) command is
```
cc -I/home/jacqhugo/basilisk/src -I.. -DSINGLE_PRECISION -O2 -g -Wall -pipe -D_FORTIFY_SOURCE=2   -c -o cuda.o cuda.c
ar cr libbuda.a cuda.o
```


> Compile for GPU, HIP through Nvidia
```
apt install hipcc
apt install cuda-driver-toolkit # if not done already
cd $BASILISK/grid/hip
make
```

The compilation (you might need to modify the Makefile) command is
```
hipcc -I/home/jacqhugo/basilisk/src -I.. -DSINGLE_PRECISION -O2 -D__HIP_PLATFORM_NVIDIA__ -g -D_FORTIFY_SOURCE=2 -c -o hip.o hip.c
```

***Notes***

- if your GPU is recent, you may get this error:
```
(fragment shader):399: CUDA: nvrtc: error: invalid value for --gpu-architecture (-arch)
```
Then you need to modify cuda.c and hip.c to force an older
architecture

```
sprintf(arch, "--gpu-architecture=compute_89");

```
just after the architecture detection, so after the line
```
sprintf (arch, "--gpu-architecture=compute_%d%d", major, minor);
```

- make sure that the nvidia driver is updated
```
apt install nvidia-drivers
```


## How to compile and run (adastra)

todo:
compilation CPU ok
compilation GPU : pas de openGL sur les GPU HPC AMD ?

### Compile Basilisk

Copy the `config.adastra` and `compile.sh` into the `/src` folder of Basilisk
Then run `./compile.sh`

### Transfer the file

1) use two scp : one to cal1 then one to adastra.
2) use scp with proxy jump :

`export ADA_HOME="/lus/home/....../username"
scp -r -o "ProxyJump cal1" file ada:$ADA_HOME/`

with local file `.ssh/config` as

```
Host cal1
  HostName ige-meom-cal1.u-ga.fr
  User jacqhugo
  ForwardAgent yes

Host ada
  HostName adastra.cines.fr
  User hjacquet
  ProxyJump cal1
```

### Compile the program
  


### Run

## How to compile and run (jean zay)

todo: ma méthode de compilation cpu que j'utilisais pour mes simus ne fonctionne
plus ??

## Results


