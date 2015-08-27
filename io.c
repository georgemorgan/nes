#include "nes.h"

uint8_t nes_cpu_read_null(uint16_t address) {
	
	printf("NULL READ AT %04x\n", address);
	
	exit(0);
	
	return 0;
	
}

void nes_cpu_write_null(uint16_t address, uint8_t value) {
	
}

uint8_t nes_cpu_bad_read(uint16_t address) {
	
	printf("CPU ERROR: BAD READ AT 0x%04x.\n\n", address);
	
	exit(EXIT_FAILURE);
	
	return 0;
	
}

void nes_cpu_bad_write(uint16_t address, uint8_t value) {
	
	printf("CPU ERROR: BAD WRITE OF %i AT 0x%04x.\n\n", value, address);
	
	exit(EXIT_FAILURE);
	
}

uint8_t nes_cpu_read_ram(uint16_t address) {
	
	return nes.ram[address % NES_RAM_SIZE];
	
	if (address >= 0x100 && address <= 0x200) { printf("ABORT: CPU TRIED TO ACCESS STACK\n"); exit(EXIT_FAILURE); }
	
}

void nes_cpu_write_ram(uint16_t address, uint8_t value) {
	
	nes.ram[address % NES_RAM_SIZE] = value;
	
}

uint8_t nes_cpu_read_io(uint16_t address) {
	
	switch (address) {
			
		/* PPU 0x2000 - 0x2007 */
			
		case 0x2000:
			
			/* PPU CTL1 */
			
			return ppu.ctl1;
			
			break;
			
		case 0x2001:
			
			/* PPU CTL2 */
			
			return ppu.ctl2;
			
			break;
			
		case 0x2002:
			
			/* PPU SREG */
			
			ppu.sreg ^= (1 << 6);
			
			return ppu.sreg;
			
			break;
			
		case 0x2003:
			
			/* PPU SPR-RAM LATCH */
			
			
			
			break;
			
		case 0x2004:
			
			/* PPU SPR-RAM DATA */
			
			
			
			break;
			
		case 0x2005:
			
			/* VRAM SCROLL */
			
			
			
			break;
			
		case 0x2006:
			
			/* VRAM LATCH */
			
			
			
			break;
			
		case 0x2007:
			
			/* VRAM DATA */
			
			
			
			break;
			
		/* APU 0x4000 - 0x4013 */
			
		case 0x4000:
			
			
			break;
			
		case 0x4001:
			
			
			break;
			
		case 0x4002:
			
			
			break;
			
		case 0x4003:
			
			
			break;
			
		case 0x4004:
			
			
			break;
			
		case 0x4005:
			
			
			break;
			
		case 0x4006:
			
			
			break;
			
		case 0x4007:
			
			
			break;
			
		case 0x4008:
			
			
			break;
			
		case 0x4009:
			
			
			break;
			
		case 0x400a:
			
			
			break;
			
		case 0x400b:
			
			
			break;
			
		case 0x400c:
			
			
			break;
			
		case 0x400d:
			
			
			break;
			
		case 0x400e:
			
			
			break;
			
		case 0x400f:
			
			
			break;
			
		case 0x4010:
			
			
			break;
			
		case 0x4011:
			
			
			break;
			
		case 0x4012:
			
			
			break;
			
		case 0x4013:
			
			
			break;
			
		/* PPU SPR-RAM DMA 0x4014 */
			
		case 0x4014:
			
			/* SPR_RAM DMA */
			
			
			
			break;
			
			/* APU 0x4015 */
			
		case 0x4015:
			
			
			
			break;
			
		/* Joypad 0x4016 - 0x4017 */
			
		case 0x4016:
			
			/* Controller A */
			
			
			
			break;
			
		case 0x4017:
			
			/* Controller B */
			
			
			
			break;
			
		default:
			
			printf("ABORT: IO read error at 0x%04x.\n\n", address);
			
			exit(EXIT_FAILURE);
			
			break;
			
	}
	
	return 0;
	
}

void nes_cpu_write_io(uint16_t address, uint8_t value) {
		
	switch (address) {
			
		/* PPU 0x2000 - 0x2007 */
			
		case 0x2000:
			
			/* PPU CTL1 */
			
			ppu.ctl1 = value;
			
			break;
			
		case 0x2001:
			
			/* PPU CTL2 */
			
			ppu.ctl2 = value;
			
			break;
			
		case 0x2002:
			
			/* PPU SREG */
			
			ppu.sreg = value;
			
			break;
			
		case 0x2003:
			
			/* PPU SPR-RAM LATCH */
			
			
			
			break;
			
		case 0x2004:
			
			/* PPU SPR-RAM DATA */
			
			
			
			break;
			
		case 0x2005:
			
			/* VRAM SCROLL */
			
			
			
			break;
			
		case 0x2006:
			
			/* VRAM LATCH */
			
			if (!ppu.latch0) ppu.vaddrlo = value;
			
			else ppu.vaddrhi = value;
			
			ppu.latch0 ^= 1;
			
			break;
			
		case 0x2007:
			
			/* VRAM DATA */
			
			ppu.write(((ppu.vaddrhi << 8) | (ppu.vaddrlo)), value);
			
			break;
			
		/* APU 0x4000 - 0x4013 */
			
		case 0x4000:
			
			
			break;
			
		case 0x4001:
			
			
			break;
			
		case 0x4002:
			
			
			break;
			
		case 0x4003:
			
			
			break;
			
		case 0x4004:
			
			
			break;
			
		case 0x4005:
			
			
			break;
			
		case 0x4006:
			
			
			break;
			
		case 0x4007:
			
			
			break;
			
		case 0x4008:
			
			
			break;
			
		case 0x4009:
			
			
			break;
			
		case 0x400a:
			
			
			break;
			
		case 0x400b:
			
			
			break;
			
		case 0x400c:
			
			
			break;
			
		case 0x400d:
			
			
			break;
			
		case 0x400e:
			
			
			break;
			
		case 0x400f:
			
			
			break;
			
		case 0x4010:
			
			
			break;
			
		case 0x4011:
			
			
			break;
			
		case 0x4012:
			
			
			break;
			
		case 0x4013:
			
			
			break;
			
		/* PPU SPR-RAM DMA 0x4014 */
			
		case 0x4014:
			
			/* SPR_RAM DMA */
			
			
			
			break;
			
			/* APU 0x4015 */
			
		case 0x4015:
			
			
			break;
			
		/* Joypad 0x4016 - 0x4017 */
			
		case 0x4016:
			
			/* Controller A */
			
			
			
			break;
			
		case 0x4017:
			
			/* Controller B */
			
			
			
			break;
			
		default:
			
			printf("ABORT: IO write error at 0x%04x.\n\n", address);
			
			exit(EXIT_FAILURE);
			
			break;
			
	}
	
}

uint8_t nes_cpu_read_rom0(uint16_t address) {
	
	return nes.rom0[address % NES_ROM0_SIZE];
	
}

void nes_cpu_write_rom0(uint16_t address, uint8_t value) {
	
	nes.rom0[address % NES_ROM0_SIZE] = value;
	
}

uint8_t nes_cpu_read_rom1(uint16_t address) {
	
	return nes.rom1[address % NES_ROM1_SIZE];
	
}

void nes_cpu_write_rom1(uint16_t address, uint8_t value) {
	
	nes.rom1[address % NES_ROM1_SIZE] = value;
	
}

uint8_t (* nes_cpu_read[0x20])(uint16_t address) = {
	
	/* ADDRESS 0x0000 - 0x0800 */
	
	nes_cpu_read_ram,
	nes_cpu_read_ram,
	nes_cpu_read_ram,
	nes_cpu_read_ram,
	
	/* ADDRESS 0x2000 - 0x4020 */
	
	nes_cpu_read_io,
	nes_cpu_read_io,
	nes_cpu_read_io,
	nes_cpu_read_io,
	nes_cpu_read_io,
	
	/* ADDRESS 0x04020 - 0x8000 */
	
	nes_cpu_read_null,
	nes_cpu_read_null,
	nes_cpu_read_null,
	nes_cpu_read_null,
	nes_cpu_read_null,
	nes_cpu_read_null,
	nes_cpu_read_null,
	
	/* ADDRESS 0x8000 - 0xC000 */
	
	nes_cpu_read_rom0,
	nes_cpu_read_rom0,
	nes_cpu_read_rom0,
	nes_cpu_read_rom0,
	nes_cpu_read_rom0,
	nes_cpu_read_rom0,
	nes_cpu_read_rom0,
	nes_cpu_read_rom0,
	
	/* ADDRESS 0xC000 - 0x10000 */
	
	nes_cpu_read_rom1,
	nes_cpu_read_rom1,
	nes_cpu_read_rom1,
	nes_cpu_read_rom1,
	nes_cpu_read_rom1,
	nes_cpu_read_rom1,
	nes_cpu_read_rom1,
	nes_cpu_read_rom1,
	
};

void (* nes_cpu_write[0x20])(uint16_t address, uint8_t value) = {
	
	/* ADDRESS 0x0000 - 0x0800 */
	
	nes_cpu_write_ram,
	nes_cpu_write_ram,
	nes_cpu_write_ram,
	nes_cpu_write_ram,
	
	/* ADDRESS 0x2000 - 0x4020 */
	
	nes_cpu_write_io,
	nes_cpu_write_io,
	nes_cpu_write_io,
	nes_cpu_write_io,
	nes_cpu_write_io,
	
	/* ADDRESS 0x04020 - 0x8000 */
	
	nes_cpu_write_null,
	nes_cpu_write_null,
	nes_cpu_write_null,
	nes_cpu_write_null,
	nes_cpu_write_null,
	nes_cpu_write_null,
	nes_cpu_write_null,
	
	/* ADDRESS 0x8000 - 0xC000 */
	
	nes_cpu_write_rom0,
	nes_cpu_write_rom0,
	nes_cpu_write_rom0,
	nes_cpu_write_rom0,
	nes_cpu_write_rom0,
	nes_cpu_write_rom0,
	nes_cpu_write_rom0,
	nes_cpu_write_rom0,
	
	/* ADDRESS 0xC000 - 0x10000 */
	
	nes_cpu_write_rom1,
	nes_cpu_write_rom1,
	nes_cpu_write_rom1,
	nes_cpu_write_rom1,
	nes_cpu_write_rom1,
	nes_cpu_write_rom1,
	nes_cpu_write_rom1,
	nes_cpu_write_rom1,
	
};