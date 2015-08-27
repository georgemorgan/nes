#ifndef nes_h

#define nes_h

#include <stdint.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#define NES_RAM_SIZE 0x800

#define NES_ROM0_SIZE 0x4000

#define NES_ROM1_SIZE 0x4000

#define NES_PPU_VRAM_SIZE 0x4000

#define NES_PPU_SPR_RAM_SIZE 0x100

#include "cpu.h"

#include "ppu.h"

extern char step;

void nes_reset(void);

void nes_load(FILE *rom);

void nes_play(void);

struct _nes {
	
	uint8_t ram[NES_RAM_SIZE];
	
	uint8_t rom0[NES_ROM0_SIZE];
	
	uint8_t rom1[NES_ROM1_SIZE];
	
	void (* reset)(void);
	
	void (* load)(FILE *rom);
	
	void (* play)(void);
	
} nes;

#endif
