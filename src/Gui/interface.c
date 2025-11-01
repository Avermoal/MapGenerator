#include "Gui/interface.h"

#include <gtk/gtk.h>

enum EXIT_CODE initinterface(interface_t *interface)
{



  return EXIT_CODE_SUCCESS;
}

void addinterface(interface_t *interface, GtkWidget *container)
{
  int mapX = gtk_widget_get_width(container)/25;
  gtk_fixed_put(GTK_FIXED(container), interface->settingsspace, 0, 0);
  gtk_fixed_put(GTK_FIXED(container), interface->mapspace, mapX, 0);
}
