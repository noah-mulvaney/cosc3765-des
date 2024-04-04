CC = gcc
DEBFLAGS = -g -Wall -Wextra -Wpedantic
OPTFLAGS = -O2

BINDIR = bin
OBJDIR = obj
SRCDIR = src

DEBUG = $(BINDIR)/debug
RELEASE = $(BINDIR)/release
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all: $(DEBUG)

run:
	$(DEBUG)

$(DEBUG): $(OBJS)
	$(CC) $(DEBFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(DEBFLAGS) -c -o $@ $^

$(RELEASE): $(SRCS)
	$(CC) $(OPTFLAGS) -o $@ $^

clean:
	rm $(BINDIR)/* $(OBJDIR)/*