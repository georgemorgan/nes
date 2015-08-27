files = $(shell find . -name '*.c')

all:

	gcc -std=gnu99 -I . $(files) -o nes

run:

	./nes test.nes