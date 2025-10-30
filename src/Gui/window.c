#include "Gui/window.h"

#include <gtk/gtk.h>

enum EXIT_CODE createwindow(window_t *win)
{
  /*Main window creation*/
  GtkWidget *window = gtk_window_new();
  if(!window){
    return EXIT_CODE_CRITICAL;
  }
  win->win = window;
  /*Set window parametrs*/
  win->width = 800;
  win->height = 700;
  win->ismax = 0;
  gtk_window_set_title(GTK_WINDOW(window), "Map Generator");
  gtk_window_set_default_size(GTK_WINDOW(window), win->width, win->height);
  gtk_window_set_resizable(GTK_WINDOW(window), TRUE);
  /*Set current window*/
  gtk_window_present(GTK_WINDOW(window));

  return EXIT_CODE_SUCCESS;
}

enum EXIT_CODE destroywindow(window_t *win)
{
  gtk_window_destroy(GTK_WINDOW(win->win));
  return EXIT_CODE_SUCCESS;
}


void onupdate(window_t *win)
{
  g_main_context_iteration(NULL, TRUE);
}
