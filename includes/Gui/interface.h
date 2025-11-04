#ifndef GUI_INTERFACE_H
#define GUI_INTERFACE_H

#include "exit_code.h"

struct _GtkWidget;

typedef struct{
  struct _GtkWidget *redrawmap;/*GtkLabel (button)*/
  struct _GtkWidget *seedentry;/*GtkEntry*/
}settings_t;

typedef struct{
  struct _GtkWidget *mapspace;/*GtkDrawinArea*/
  int m_width, m_height;
  struct _GtkWidget *settingsspace;/*GtkBox*/
  int s_width, s_height;
  settings_t settings;
}interface_t;

enum EXIT_CODE initinterface(interface_t *interface);

void addinterface(interface_t *interface, struct _GtkWidget *container, int width);

void destroyinterface(interface_t *interface);

/*Settings space*/
enum EXIT_CODE fill_settings_space(struct _GtkWidget *settingspace, settings_t *settings);

void clear_settings_space(settings_t *settings);

/*Map space*/
void drawmap(struct _GtkWidget *mapspace, const char *seed);

#endif/*GUI_INTERFACE_H*/
