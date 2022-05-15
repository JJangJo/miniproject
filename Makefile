CC=gcc
CFLAGS = -W -Wall
OBJECTS = prodManager.c
TARGET = test

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o $(TARGET)
