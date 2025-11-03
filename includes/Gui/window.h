#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H

#include "exit_code.h"
#include "Gui/interface.h"

struct _GtkWidget;

typedef struct {
  struct _GtkWidget *win;
  struct _GtkWidget *container;/*GtkFixed*/
  interface_t interface;
  int width;
  int height;
}window_t;

enum EXIT_CODE createwindow(window_t *win);

enum EXIT_CODE destroywindow(window_t *win);

void onupdate(window_t *win);

#endif/*GUI_WINDOW_H*/
