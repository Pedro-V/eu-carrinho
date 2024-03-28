CC = g++
CFLAGS = -Wall -std=c++17
LDFLAGS = -lGL -lGLU -lglut
SRCDIR = src
OBJDIR = obj
BINDIR = bin
INCDIR = include

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

all: $(BINDIR)/simulator

$(BINDIR)/simulator: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c -o $@ $<

run: $(BINDIR)/simulator
	./$(BINDIR)/simulator imagens/grande.pgm

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: clean

