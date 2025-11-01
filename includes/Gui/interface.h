#ifndef GUI_INTERFACE_H
#define GUI_INTERFACE_H

#include "exit_code.h"

struct _GtkWidget;

typedef struct{
  struct _GtkWidget *mapspace;
  struct _GtkWidget *settingsspace;
}interface_t;

enum EXIT_CODE initinterface(interface_t *interface);

void addinterface(interface_t *interface, struct _GtkWidget *container);

#endif/*GUI_INTERFACE_H*/
