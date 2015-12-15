all:
	gcc -I. -I/usr/include sqlite3.c -lXext -lX11 -lm -lpthread -ldl -L/usr/X11R6/lib -L/usr/lib -L/lib c_inc.c -o e
#	gcc -I. -I/usr/include sqlite3.c -lXext -lX11 -lm -lpthread -ldl -L/usr/X11R6/lib -L/usr/lib -L/lib sql_exec.c
