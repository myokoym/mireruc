PROGRAM = mireruc
OBJS = mireruc.o

CC = gcc
CFLAGS += -g $(shell pkg-config --cflags gtk+-3.0)
LDFLAGS += -g
LIBS += $(shell pkg-config --libs gtk+-3.0)

$(PROGRAM): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(PROGRAM) $(LIBS)
