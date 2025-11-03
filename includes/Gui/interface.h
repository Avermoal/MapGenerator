#ifndef GUI_INTERFACE_H
#define GUI_INTERFACE_H

#include "exit_code.h"

struct _GtkWidget;

typedef struct{
  struct _GtkWidget *mapspace;/*GtkDrawinArea*/
  int m_width, m_height;
  struct _GtkWidget *settingsspace;/*GtkBox*/
  int s_width, s_height;
}interface_t;

enum EXIT_CODE initinterface(interface_t *interface);

void addinterface(interface_t *interface, struct _GtkWidget *container, int width);

void destroyinterface(interface_t *interface);

/*Settings space*/
enum EXIT_CODE fill_settings_space(struct _GtkWidget *settingspace);

#endif/*GUI_INTERFACE_H*/
