#include "window.h"

#include <gtk/gtk.h>

enum EXIT_CODE createwindow(window_t *win)
{
  /*Main window creation*/
  GtkWidget *window = gtk_window_new();
  if(!window){
    return EXIT_CRITICAL;
  }
  /**/



  return EXIT_SUCCES;
}


