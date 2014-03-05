#include<gtk/gtk.h>
#include<stdbool.h>

int ufc;
struct Statistics
{
	GtkWidget *window,*grid,*label1[5],*label2[5][3],*values[5][3],*button;
};

void ufc_calc(GtkWidget *button,struct Statistics *s1)
{
	struct Statistics s2=*s1;
	int mm[5][3]={3,4,6,4,5,7,3,4,6,7,10,15,5,7,10};
	int i,j;
	/*ufc=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<3;j++)
		{
			int v=0;
			const gchar *cv=gtk_entry_get_text(GTK_ENTRY(s2.values[i][j]));
			int k;
			for(k=0;cv[k]!=0;k++)
				v=v*10+(int)(cv[k]-48);
			ufc+=v*mm[i][j];
		}
	}
	printf("UFC=%d\n",ufc);*/
	gtk_widget_destroy(s2.window);
}
	

void first_window()
{
	struct Statistics s1;
	int i,j;
	char input[5][30]={"External Inputs", "External Outputs", "External Inquiries", "Internal Logic Files", "External Logic Files"};
	char type[3][10]={"Low","Average","High"};
	//declare and initialize
	s1.window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(s1.window,300,400);
	gtk_window_set_resizable(GTK_WINDOW(s1.window),FALSE);
	
	s1.grid=gtk_grid_new();
	//gtk_grid_set_row_homogeneous(GTK_GRID(grid),true);
	gtk_grid_set_column_homogeneous(GTK_GRID(s1.grid),true);
	//gtk_grid_set_row_spacing(GTK_GRID(grid),20);
		
	for(i=0;i<5;i++)
	{
		s1.label1[i]=gtk_label_new(input[i]);
		for(j=0;j<3;j++)
		{
			s1.label2[i][j]=gtk_label_new(type[j]);
			s1.values[i][j]=gtk_entry_new();
		}
	}
	
	s1.button=gtk_button_new_with_label("Proceed");	
	//packing
	gtk_container_add(GTK_CONTAINER(s1.window),s1.grid);
	for(i=0;i<5;i++)
	{
		gtk_grid_attach(GTK_GRID(s1.grid),s1.label1[i],0,i*3,3,1);
		for(j=0;j<3;j++)
		{
			gtk_grid_attach(GTK_GRID(s1.grid),s1.label2[i][j],j,i*3+1,1,1);
			gtk_grid_attach(GTK_GRID(s1.grid),s1.values[i][j],j,i*3+2,1,1);
		}
	}
	gtk_grid_attach(GTK_GRID(s1.grid),s1.button,1,15,1,1);
	//signals
	g_signal_connect(s1.window,"destroy",gtk_main_quit,NULL);
	g_signal_connect(s1.button,"clicked",G_CALLBACK(ufc_calc),(gpointer)&s1);
	//gtk_signal_connect_object (GTK_OBJECT (s1.button), "clicked",GTK_SIGNAL_FUNC (ufc_calc),&s1);
	
	gtk_widget_show_all(s1.window);
}

int main(int argc,char *argv[])
{
	gtk_init(&argc,&argv);
	first_window();
	gtk_main();
}
