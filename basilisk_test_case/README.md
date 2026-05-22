# Basilisk test case

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


