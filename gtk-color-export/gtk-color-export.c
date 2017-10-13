#include <sys/types.h>
#include <gtk/gtk.h>

char *fmt = "%s:#%02x%02x%02x";

void export_fg_color(GtkWidget *widget, char* name, GtkStateFlags flags) {
      GtkStyleContext* context = gtk_widget_get_style_context(widget);
      GdkRGBA rgba;
      gtk_style_context_get_color(context, flags, &rgba);
      printf(fmt, name, (int) (rgba.red * 0xFF), (int) (rgba.green * 0xFF), (int) (rgba.blue * 0xFF));
}

void export_bg_color(GtkWidget *widget, char* name, GtkStateFlags flags) {
      GtkStyleContext* context = gtk_widget_get_style_context(widget);
      GdkRGBA rgba;
      gtk_style_context_get_background_color(context, flags, &rgba);
      printf(fmt, name, (int) (rgba.red * 0xFF), (int) (rgba.green * 0xFF), (int) (rgba.blue * 0xFF));
}

int main(int argc, char** argv) {
      GtkWidget *i;

      GtkWidget *window;
      gtk_init(&argc, &argv);
      window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

      GtkWidget *entry = gtk_entry_new();
      GtkWidget *notebook = gtk_notebook_new();
      gtk_container_add(GTK_CONTAINER(window), entry);

      gtk_widget_show(entry);
      gtk_widget_show(window);

      printf("gtk-color-scheme = \"");
      export_fg_color(window, "fg_color", GTK_STATE_FLAG_NORMAL);
      printf("\\n");
      export_bg_color(window, "bg_color", GTK_STATE_FLAG_NORMAL);
      printf("\\n");
      export_fg_color(notebook, "text_color", GTK_STATE_FLAG_NORMAL);
      printf("\\n");
      export_bg_color(notebook, "base_color", GTK_STATE_FLAG_NORMAL);
      printf("\\n");
      export_fg_color(entry, "selected_fg_color", GTK_STATE_FLAG_SELECTED);
      printf("\\n");
      export_bg_color(entry, "selected_bg_color", GTK_STATE_FLAG_SELECTED);
      printf("\\n");
      export_fg_color(entry, "insensitive_fg_color", GTK_STATE_FLAG_SELECTED);
      printf("\\n");
      export_bg_color(entry, "insensitive_bg_color", GTK_STATE_FLAG_SELECTED);
      printf("\\n");
      export_fg_color(entry, "tooltip_fg_color", GTK_STATE_FLAG_NORMAL);
      printf("\\n");
      export_bg_color(entry, "tooltip_bg_color", GTK_STATE_FLAG_NORMAL);
      printf("\"\n");
}
