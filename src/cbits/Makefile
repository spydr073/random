
NAME         = pcg_idris_ffi
CC           = gcc
FLAGS        = -std=gnu99 -Iinclude
CFLAGS       = -fPIC -g -pedantic -Wall -Wextra -ggdb3
LDFLAGS      = -shared

.PHONY : clean

SOURCES = $(shell echo *.c)
HEADERS = $(shell echo *.h)
OBJECTS = $(SOURCES:.c=.o)

#LIBS   = ../
LIBS   = ./
INCUDE = ../

TARGET=$(LIBS)/$(NAME).so

all: $(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)


