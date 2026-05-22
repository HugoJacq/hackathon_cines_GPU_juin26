# Basilisk et APU AMD

Ce document rassemble les questions relatives à l'utilisation de Basilisk (https://basilisk.fr/) sur des apu AMD type MI250X.

## Option 1: Utiliser les directives OpenMP de Basilisk

Présentation de AMD : https://www.ccs.tsukuba.ac.jp/wp-content/uploads/sites/14/2025/09/03.-Introduction_to_OpenMP_Offload.pdf

Partir de :  https://basilisk.fr/src/grid/cartesian.h


## Option 2 : Utiliser ROCm

Coder l'équivalent ROCm de https://basilisk.fr/src/grid/gpu/grid.h qui est en
OpenGL.

Selon Stéphane : 

  Il n'y a pas d'exemple simple. Le seul "exemple" est ce qui est fait
  avec OpenGL i.e. :

  https://basilisk.fr/src/grid/gpu/grid.h

  mais c'est compliqué...

  Si je résume, pour écrire une version ROCm de grid/gpu/grid.h il faut
  savoir (en ROCm):

  - initialiser le GPU / allouer la mémoire sur le GPU
  - interfacer les variables CPU "externes" avec leurs correspondant
  "internes" sur le GPU
  - compiler et linker les "kernels" GPU correspondants
  - lancer les kernels sur un nombre approprié de "threads" GPU
  - synchroniser la mémoire CPU/GPU
  - éventuellement faire des "réductions" sur le GPU

  pour apprendre à faire ca, il ne faut évidement pas essayer d'écrire
  grid/rocm/grid.h directement. Il faut écrire un programme simple (en C,
  sans basilisk) qui:

  - alloue une matrice (2D ou même un vecteur 1D) sur le CPU et le GPU
  - loop une operation simple sur cette matrice soit sur le CPU, soit sur
  le GPU
  - récupère le résultat sur le CPU (i.e. synchronise la mémoire CPU/GPU)
  - affiche le résultat

  pour complexifier tu peux:

  - ajouter l'acces à une/plusieurs variables "externes" CPU
  - ajouter une reduction

  Si tu sais faire tout ca, alors tu as a priori tous les morceaux
  nécessaires pour coder grid/rocm/grid.h
