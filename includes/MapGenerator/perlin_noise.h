#ifndef MAPGENERATOR_PERLIN_NOISE_H
#define MAPGENERATOR_PERLIN_NOISE_H

#define PERM_TABLE_SIZE 512
#define PERM_TABLE_HALF_SIZE 256

/*Permutation table*/
extern int perm[PERM_TABLE_SIZE];

/*Init perm. table*/
void initperlin(const char *seed);

/*Fade function*/
float fade(float t);

/*Linear interpolation*/
float lerp(float t, float a, float b);

/*Gradient*/
float grad(int hash, float x);

/*1D Perlin noise*/
float perlin1D(float param);

#endif/*MAPGENERATOR_PERLIN_NOISE_H*/
