#include "MapGenerator/map_generator.h"

#include <math.h>

#include "MapGenerator/perlin_noise.h"
#include "MapGenerator/fractal_noise.h"

#define PIXEL_WHITE 255
#define PIXEL_BLACK 0

void generatemap(const char *seed, unsigned char **data, int height, int width)
{
  /*Perlin noise init*/
  initperlin(seed);
  /*The coastline creation*/
  for(int t = 0; t < height*width; ++t){
   if(1){
    (*data)[t] = PIXEL_WHITE*perlin1D(t/10);
    }
  }
  
}
