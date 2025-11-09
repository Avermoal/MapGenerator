#include "MapGenerator/perlin_noise.h"

#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int perm[PERM_TABLE_SIZE];

void initperlin(const char *seed)
{
  /*Init random*/
  srand(atoi(seed));
  /*Filling perm. table*/
  for(int i = 0; i < PERM_TABLE_HALF_SIZE; ++i){
    perm[i] = i;
  }
  for(int i = 0; i < PERM_TABLE_HALF_SIZE; ++i){
    int j = rand() % PERM_TABLE_HALF_SIZE;
    int temp = perm[i];
    perm[i] = perm[j];
    perm[j] = temp;
  }
  /*Copy the half of perm for easy calculation*/
  for(int i = 0; i < PERM_TABLE_HALF_SIZE; ++i){
    perm[PERM_TABLE_HALF_SIZE + i] = perm[i];
  }
}

float perlin1D(float param)
{
  int xi0 = (int)floor(param) & 255;/*That doesn't exceed 255*/
  int xi1 = (xi0 + 1) & 255;
  float xf0 = param - floor(param);
  float xf1 = xf0 - 1.0f;
  /*Gradients*/
  float g0 = grad(perm[xi0], xf0);
  float g1 = grad(perm[xi1], xf1);
  /*Fading*/
  float u = fade(xf1);
  /*Interpalation*/
  return lerp(u, g0, g1);
}

/*Fade function*/
float fade(float t)
{
  return t * t * t * (t * (t * 6 - 15) + 10);
}

/*Linear interpolation*/
float lerp(float t, float a, float b)
{
  return a + t * (b - a);
}

/*Gradient*/
float grad(int hash, float x)
{
  return (hash & 1)? x: -x;
}
