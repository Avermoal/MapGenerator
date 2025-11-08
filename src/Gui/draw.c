#include "Gui/draw.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <jpeglib.h>

#include <MapGenerator/map_generator.h>

#define FILE_END_NAME 5 /*.jpg\0*/

void create_jpeg(const char *seed, int width, int height)
{
  const int channels = 1;
  const int quality = 100;/*100%*/
  const unsigned long datasize = (unsigned long)(width)*(unsigned long)(height)*(unsigned long)(channels);
  /*Output file name*/
  int seedlength = strlen(seed);
  int file_name_length = seedlength + FILE_END_NAME;
  char filename[file_name_length];
  char file_end_name[FILE_END_NAME] = ".jpg";
  for(int i = 0; i < seedlength; ++i){
    filename[i] = seed[i];
  }
  for(int i = 0; i < FILE_END_NAME; ++i){
    filename[seedlength - 1 + i] = file_end_name[i];
  }
  unsigned char *data = (unsigned char*)calloc(datasize, sizeof(unsigned char));
  if(!data){
    return;
  }
  /*MAP GENERATION*/
  generatemap(seed, data, datasize);
  /*Initialize compression structure*/
  struct jpeg_compress_struct cinfo;
  struct jpeg_error_mgr jerr;
  cinfo.err = jpeg_std_error(&jerr);
  jpeg_create_compress(&cinfo);
  /*Output file init*/
  FILE *out = fopen(filename, "wb");
  if(!out){
    free(data);
    return;
  }
  jpeg_stdio_dest(&cinfo, out);
  /*Set parametrs for monochrome image*/
  cinfo.image_width = width;
  cinfo.image_height = height;
  cinfo.input_components = channels;
  cinfo.in_color_space = JCS_GRAYSCALE;
  jpeg_set_defaults(&cinfo);
  jpeg_set_quality(&cinfo, quality, TRUE);
  /*Begin compressiion*/
  jpeg_start_compress(&cinfo, TRUE);
  /*Write image data*/
  JSAMPROW image_row_data;
  int scanline = 0;
  while((scanline = cinfo.next_scanline) < cinfo.image_height){
    image_row_data = &data[scanline * width];
    jpeg_write_scanlines(&cinfo, &image_row_data, 1);
  }
  /*Cleaning and finishing compression*/
  jpeg_finish_compress(&cinfo);
  fclose(out);
  jpeg_destroy_compress(&cinfo);
  free(data);
}
