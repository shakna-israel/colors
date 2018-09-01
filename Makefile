IDIR=src
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=src
LDIR=

PREFIX=/usr/local

LIBS=

_DEPS=colors.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=ccolor.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ccolor: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: install
install: ccolor
	mkdir $(PREFIX)/ccolor
	cp ccolor $(PREFIX)/ccolor/ccolor
	cp LICENSE $(PREFIX)/ccolor/LICENSE
	cp README.md $(PREFIX)/ccolor/README.md
	cp Makefile $(PREFIX)/ccolor/Makefile
	ln -s $(PREFIX)/ccolor/ccolor $(PREFIX)/bin/ccolor

.PHONY: uninstall
uninstall:
	rm $(PREFIX)/bin/ccolor
	rm -rf $(PREFIX)/ccolor
