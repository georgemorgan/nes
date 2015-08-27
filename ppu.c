#include "nes.h"

struct _ppu ppu = { .read = &nes_ppu_read_address, .write = &nes_ppu_write_address };

uint8_t nes_ppu_read_null(uint16_t address) {
	
	return 0;
	
}

void nes_ppu_write_null(uint16_t address, uint8_t value) {
	
}

uint8_t ppu_read_pattern_table(uint16_t address) {
	
	printf("READ PATTERN\n");
	
	return 0;
	
}

void ppu_write_pattern_table(uint16_t address, uint8_t value) {
	
	printf("WROTE PATTERN\n");
	
}

uint8_t ppu_read_name_table(uint16_t address) {
	
	printf("READ NAME\n");
	
	return 0;
	
}

void ppu_write_name_table(uint16_t address, uint8_t value) {
	
	printf("WROTE NAME\n");
	
}

uint8_t ppu_read_palette(uint16_t address) {
	
	printf("READ PALETTE\n");
	
	return 0;
	
}

void ppu_write_palette(uint16_t address, uint8_t value) {
	
	printf("WROTE PALETTE\n");
	
}

uint8_t (* nes_ppu_read[0x10])(uint16_t address) = {
	
	ppu_read_pattern_table,
	ppu_read_pattern_table,
	ppu_read_pattern_table,
	ppu_read_pattern_table,
	
	ppu_read_pattern_table,
	ppu_read_pattern_table,
	ppu_read_pattern_table,
	ppu_read_pattern_table,
	
	ppu_read_name_table,
	ppu_read_name_table,
	ppu_read_name_table,
	ppu_read_name_table,
	
	ppu_read_palette,
	ppu_read_palette,
	ppu_read_palette,
	ppu_read_palette
	
};

void (* nes_ppu_write[0x10])(uint16_t address, uint8_t value) = {
	
	nes_ppu_write_null,
	nes_ppu_write_null,
	nes_ppu_write_null,
	nes_ppu_write_null,
	
	nes_ppu_write_null,
	nes_ppu_write_null,
	nes_ppu_write_null,
	nes_ppu_write_null,
	
	ppu_write_name_table,
	ppu_write_name_table,
	ppu_write_name_table,
	ppu_write_name_table,
	
	ppu_write_palette,
	ppu_write_palette,
	ppu_write_palette,
	ppu_write_palette
	
};

uint8_t nes_ppu_read_address(uint16_t address) {
	
	return ppu.vram[address];//(nes_ppu_read[(address % NES_PPU_VRAM_SIZE) / 0x400])(address);
	
}

void nes_ppu_write_address(uint16_t address, uint8_t value) {
	
	ppu.vram[address] = value;
	
	(nes_ppu_write[(address % NES_PPU_VRAM_SIZE) / 0x400])(address, value);
	
}