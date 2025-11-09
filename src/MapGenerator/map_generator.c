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
  for(int i = 0; i < height; ++i){
    for(int j = 0; j < width; ++j){
      (*data)[i*j+j] = PIXEL_WHITE;
    }
  }
}
