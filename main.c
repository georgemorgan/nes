#include "nes.h"

char step;

int main(int argc, char *argv[]) {

	if (argc < 2) { printf("\nUsage:\n\nnes [rom] [step]\n\n"); exit(EXIT_FAILURE); }
	
	FILE *rom = fopen(argv[1], "rb");
	
	if (rom == NULL) { printf("\nCould not find a file at the path specified.\n\n"); exit(EXIT_FAILURE); }
	
	if (argc > 2 && !strcmp(argv[2], "step")) {
		
		step = 1;
		
	}
	
	nes.load(rom);
	
	fclose(rom);
	
	nes.play();

	return 0;

}
