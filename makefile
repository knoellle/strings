CC=gcc
BINDIR=bin/

all: $(BINDIR)clean-strings $(BINDIR)strings2

$(BINDIR)clean-strings: clean-strings.c
	$(CC) -O3 -o $(BINDIR)clean-strings clean-strings.c

$(BINDIR)strings2: strings2.c
	$(CC) -O3 -o $(BINDIR)strings2 strings2.c

clean:
	rm -r $(BINDIR)

install:
	cp bin/* /usr/bin/

$(info $(shell mkdir -p bin))
