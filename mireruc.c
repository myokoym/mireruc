#include <gtk/gtk.h>

static void
cb_button_clicked (GtkWidget *button, gpointer user_data)
{
    gtk_main_quit();
}

int
main (int argc, char* argv[])
{
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *image;
    GtkWidget *button;
    char *image_path = argv[1];

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(window, 300, 200);

    vbox = gtk_vbox_new(FALSE, 2);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    image = gtk_image_new_from_file(image_path);
    gtk_box_pack_start(GTK_BOX(vbox), image, TRUE, TRUE, 0);

    button = gtk_button_new_with_label("Quit");
    gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 0);

    g_signal_connect(G_OBJECT(button), "clicked",
                     G_CALLBACK(cb_button_clicked), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
