#include "Gui/draw.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stbi/stb_image_write.h"

#include "MapGenerator/map_generator.h"

#define FILE_END_NAME 5 /*.png\0*/

const char* create_png(const char *seed, int width, int height)
{
  const int channels = 1;
  const unsigned long datasize = (unsigned long)(width)*(unsigned long)(height)*(unsigned long)(channels);
  /*Output file name*/
  int seedlength = strlen(seed);
  int file_name_length = seedlength + FILE_END_NAME;
  char *filename = (char*)calloc(file_name_length, sizeof(char));
  if(!filename){
    fprintf(stderr, "Memmory don't allocate for filename\n");
    return NULL;
  }
  char file_end_name[FILE_END_NAME] = ".png";
  for(int i = 0; i < seedlength; ++i){
    filename[i] = seed[i];
  }
  for(int i = 0; i < FILE_END_NAME; ++i){
    filename[seedlength + i] = file_end_name[i];
  }
  unsigned char *data = (unsigned char*)calloc(datasize, sizeof(unsigned char));
  if(!data){
    free(filename);
    fprintf(stderr, "Memmory don't allocate for data\n");
    return NULL;
  }
  /*MAP GENERATION*/
  generatemap(seed, &data, height, width);
  /*Write png*/
  if(!stbi_write_png(filename, width, height, channels, data, width*channels)){
    fprintf(stderr, "Image save error\n");
    free(filename);
    return NULL;
  }
  free(data);
  printf("%s\n", filename);
  return filename;
}
