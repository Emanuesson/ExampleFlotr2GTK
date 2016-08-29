/*
 * main.c
 * This file is part of a simple test
 *
 * Copyright (C) 2013 - Emanuel Schmidt
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdlib.h>
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <webkit2/webkit2.h>

static void destroy( GtkWidget *widget,
                     gpointer   data )
{
    gtk_main_quit ();
}


int
main (int argc, char **argv)
{
  GtkWidget *frame;
  GtkWidget *main_window;
  GtkWidget *web_view;

  gtk_init (&argc, &argv);

  main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  frame = gtk_frame_new (NULL);

  g_object_set (main_window, "default-width", 650, "default-height", 422, NULL);

  g_signal_connect (main_window, "destroy",
	      G_CALLBACK (destroy), NULL);

  web_view = webkit_web_view_new ();

  gtk_container_set_border_width (GTK_CONTAINER (main_window), 8);
  gtk_container_add (GTK_CONTAINER (main_window), GTK_WIDGET (frame));
  gtk_container_add (GTK_CONTAINER (frame), GTK_WIDGET (web_view));

  gtk_widget_show_all (GTK_WIDGET (main_window));

  GBytes *html_file =
    g_resources_lookup_data (
      "/net/test/flotr2_example.htm",
      G_RESOURCE_LOOKUP_FLAGS_NONE,
      NULL);

  /* nice idea, but fails to translate the css location */
/*  webkit_web_view_load_bytes (
 *   WEBKIT_WEB_VIEW (web_view),
 *   html_file, NULL, NULL, NULL);
 */

  /* another nice idea, but requires a internet-connection and is probably no good general solution */
/*  webkit_web_view_load_uri (
 *    WEBKIT_WEB_VIEW (web_view),
 *    "http://www.humblesoftware.com/flotr2/example");
 */

  /* the best idea so far, but requires an installation */
/*  webkit_web_view_load_uri (
 *    WEBKIT_WEB_VIEW (web_view),
 *    "file://"DATADIR"/flotr2_example.htm");
 */

  /* this is porbably the worst idea so far */
  gchar* input_dir = g_get_current_dir ();
  gchar full_uri[512];
  snprintf(full_uri, sizeof full_uri, "file://%s/flotr2_example.htm", input_dir);
  webkit_web_view_load_uri (WEBKIT_WEB_VIEW (web_view), full_uri);

  gtk_main ();

  return 0;
}

