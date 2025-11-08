#include "Gui/interface.h"

#include <math.h>
#include <string.h>

#include <gtk/gtk.h>
#include <cairo.h>

#include "Gui/draw.h"

#define COEFF_EXPANTION 10

static void on_draw(GtkDrawingArea *area, cairo_t *cr, int width, int height, gpointer userdata)/*userdata = const char**/
{
  int image_width = 0, image_height = 0;
  /*Userdata to seedentry*/
  GtkWidget *seedentry = (GtkWidget*)userdata;
  const char *seed = gtk_entry_buffer_get_text(gtk_entry_get_buffer(GTK_ENTRY(seedentry)));
  if(strlen(seed) == 0){
    g_error("Seed don't obtained");
    return;
  }
  /*Cairo create surfece*/
  const char *filename = create_png(seed, width*COEFF_EXPANTION, width*COEFF_EXPANTION);
  cairo_surface_t *surf = cairo_image_surface_create_from_png(filename);
  if(cairo_surface_status(surf) != CAIRO_STATUS_SUCCESS){
    g_error("Failed to create surface from image file with name ");
    printf("%s\n", filename);
    return;
  }
  image_height = image_width = cairo_image_surface_get_width(surf);
  /*Cleanup area with white color*/
  cairo_set_source_rgb(cr, 1, 1, 1);
  cairo_paint(cr);
  /*Image scaling*/
  double scale_x = (double)width / (double)image_width;
  double scale_y = (double)height / (double)image_height;
  double scale = MIN(scale_x, scale_y);
  /*Image drawing*/
  cairo_save(cr);
  cairo_scale(cr, scale, scale);
  cairo_set_source_surface(cr, surf, 0, 0);
  cairo_paint(cr);
  cairo_restore(cr);
  /*Surface destroying*/
  cairo_surface_destroy(surf);
}

static void on_redraw_map_clicked(GtkWidget *button, gpointer userdata)/*userdata = mapspace*/
{
  GtkWidget *mapspace = (GtkWidget*)userdata;
  gtk_widget_queue_draw(mapspace);
}

enum EXIT_CODE initinterface(interface_t *interface)
{
  /*Map space init*/
  interface->mapspace = gtk_drawing_area_new();
  if(!interface->mapspace){
    return EXIT_CODE_CRITICAL;
  }
  gtk_widget_set_size_request(interface->mapspace, interface->m_width, interface->m_height);
  gtk_drawing_area_set_content_width(GTK_DRAWING_AREA(interface->mapspace), interface->m_width);
  gtk_drawing_area_set_content_height(GTK_DRAWING_AREA(interface->mapspace), interface->m_height);
  /*Settings space init*/
  interface->settingsspace = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
  if(!interface->settingsspace){
    g_object_unref(interface->mapspace);
    return EXIT_CODE_CRITICAL;
  }
  gtk_widget_set_size_request(interface->settingsspace, interface->s_width, interface->s_height);
  /*Fill interface settings space*/
  if(fill_settings_space(interface->settingsspace, &interface->settings) != EXIT_CODE_SUCCESS){
    return EXIT_CODE_CRITICAL;
  }
  /*Seed setup*/
  gtk_editable_set_text(GTK_EDITABLE(interface->settings.seedentry), "Avermoal");
  /*Map draw callbacks*/
  g_signal_connect(interface->settings.redrawmap, "clicked", G_CALLBACK(on_redraw_map_clicked), interface->mapspace);
  gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(interface->mapspace), on_draw, interface->settings.seedentry, NULL);
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
    g_clear_object(&interface->mapspace);
    g_clear_object(&interface->settingsspace);
    clear_settings_space(&interface->settings);
  }
}

enum EXIT_CODE fill_settings_space(GtkWidget *settingsspace, settings_t *settings)
{
  settings->redrawmap = gtk_button_new_with_label("Redraw map");
  settings->seedentry = gtk_entry_new();
  gtk_box_append(GTK_BOX(settingsspace), settings->seedentry);
  gtk_box_append(GTK_BOX(settingsspace), settings->redrawmap);
  return EXIT_CODE_SUCCESS;
}

void clear_settings_space(settings_t *settings)
{
  if(settings){
    settings->redrawmap = NULL;
    settings->seedentry = NULL;
  }
}
