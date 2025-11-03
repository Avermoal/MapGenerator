#include "Gui/interface.h"

#include <gtk/gtk.h>

enum EXIT_CODE initinterface(interface_t *interface)
{
  /*Map space init*/
  interface->mapspace = gtk_drawing_area_new();
  if(!interface->mapspace){
    return EXIT_CODE_CRITICAL;
  }
  gtk_widget_set_size_request(interface->mapspace, interface->m_width, interface->m_height);
  /*Settings space init*/
  interface->settingsspace = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
  if(!interface->settingsspace){
    g_object_unref(interface->mapspace);
    return EXIT_CODE_CRITICAL;
  }
  gtk_widget_set_size_request(interface->settingsspace, interface->s_width, interface->s_height);
  /*Fill interface settings space*/
  if(fill_settings_space(interface->settingsspace) != EXIT_CODE_SUCCESS){
    return EXIT_CODE_CRITICAL
  }
  return EXIT_CODE_SUCCESS;
}

void addinterface(interface_t *interface, GtkWidget *container, int width)
{
  int mapX = width/4;
  gtk_fixed_put(GTK_FIXED(container), interface->settingsspace, 0, 0);
  gtk_fixed_put(GTK_FIXED(container), interface->mapspace, mapX, 0);
}

void destroyinterface(interface_t *interface)
{
  if(interface){
    g_object_unref(interface->mapspace);
    g_object_unref(interface->settingsspace);
    g_clear_object(&interface->mapspace);
    g_clear_object(&interface->settingsspace);
  }
}

enum EXIT_CODE fill_settings_space(GtkWidget *settingsspace)
{
  
}
