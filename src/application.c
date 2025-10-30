#include "application.h"

#include <gtk/gtk.h>

#include "exit_code.h"
#include "Gui/window.h"

enum APP_EXIT_CODE startapp()
{
  /*GTK initialization*/
  gtk_init();
  /*Window creation*/
  window_t window;
  if(createwindow(&window) != EXIT_CODE_SUCCESS){
    return APP_FAILURE;
  }

  while(g_list_model_get_n_items(gtk_window_get_toplevels()) > 0){
    onupdate(&window);
  }

  return APP_EXIT_SUCCESS;
}
