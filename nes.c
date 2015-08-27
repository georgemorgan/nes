#include "nes.h"

#include <signal.h>

#define CYCLES_PER_HBLANK 144

struct _nes nes = { .reset = &nes_reset, .load = &nes_load, .play = &nes_play };

void nes_reset(void) {
	
	cpu.a = cpu.x = cpu.y = cpu.sreg = 0;
	
	cpu.sreg = (1 << 5);
	
	cpu.sp = 0xFF;
		
	cpu.pc = ((cpu.read(0xFFFD) << 8) | cpu.read(0xFFFC));
	
	cpu.pc = 0x8000;
	
	ppu.sreg = ((1 << 7) | (1 << 6));
	
}

void nes_load(FILE *rom) {
	
	fseek(rom, 16, SEEK_SET);

	fread(nes.rom0, NES_ROM0_SIZE, sizeof(uint8_t), rom);
	
	fread(nes.rom1, NES_ROM1_SIZE, sizeof(uint8_t), rom);
	
}

void pstat(void) {
	
	printf("\nA: %02x, X: %02x, Y: %02x, %c%c-%c%c%c%c%c\n", cpu.a, cpu.x, cpu.y,
		   (cpu_get_N()) ? 'N' : 'n',
		   (cpu_get_V()) ? 'V' : 'v',
		   (cpu_get_B()) ? 'B' : 'b',
		   (cpu_get_D()) ? 'D' : 'd',
		   (cpu_get_I()) ? 'I' : 'i',
		   (cpu_get_Z()) ? 'Z' : 'z',
		   (cpu_get_C()) ? 'C' : 'c'
		   );
	
}

void nesexit(int dummy) {
	
	printf("\n\n");
	
	exit(EXIT_FAILURE);
	
}

void nes_play(void) {
	
	signal(SIGINT, nesexit);
	
	nes_reset();

	while (step) {
		
		getchar();
		
		printf("\033[F\033[J");
		
		cpu.step();
		
		pstat();
		
	}
	
	while (!step) {
		
		for (int i = 0; i < 262; i ++) {
			
			while (1) { cpu.step(); pstat(); usleep(100); }
			
		}
		
		printf("\033[F\033[J");
		printf("\033[F\033[J");
		
	}
	
}
