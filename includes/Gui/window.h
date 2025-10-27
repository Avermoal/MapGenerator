#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H

#include "exit_code.h"

struct GtkWidget;

typedef struct {
  GtkWidget *win;
  int width;
  int height;
  int ismax;
}window_t;

enum EXIT_CODE createwindow(window_t *win);

enum EXIT_CODE destroywindow(window_t *win);

#endif/*GUI_WINDOW_H*/
