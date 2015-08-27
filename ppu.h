#ifndef ppu_c

#define ppu_c

struct _ppu {
	
	uint8_t ctl1;
	
	uint8_t ctl2;
	
	uint8_t sreg;
	
	uint8_t latch0;
	
	uint8_t vaddrlo;
	
	uint8_t vaddrhi;
	
	uint8_t vram[NES_PPU_VRAM_SIZE];
	
	uint8_t (* read)(uint16_t address);
	
	void (* write)(uint16_t address, uint8_t value);
	
} ppu;

uint8_t nes_ppu_read_address(uint16_t address);

void nes_ppu_write_address(uint16_t address, uint8_t value);

#endif