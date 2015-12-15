CC         = gcc
GCCFLAGS   = -O
INCLUDE    = -I. -I/usr/include
FILENAME_A = sql_exec
FILENAME_B = sqlite3
FILENAME_C = shell
LDLIBS     = -lXext -lX11 -lm -lpthread
LDFLAGS    = -L/usr/X11R6/lib -L/usr/lib -L/lib
all:
	$(CC) $(GCCFLAGS) $(INCLUDE) $(FILENAME_A).c $(FILENAME_B).c $(LDFLAGS) $(LDLIBS) -o $(FILENAME_A)
	$(CC) $(GCCFLAGS) $(INCLUDE) $(FILENAME_B).c $(FILENAME_C).c $(LDFLAGS) $(LDLIBS) -o $(FILENAME_B)
