#include "application.h"

#include <gtk/gtk.h>

#include "window.h"

enum APP_EXIT_CODE startapp()
{
  /*GTK initialization*/
  gtk_init();



  return APP_EXIT_SUCCES;
}
