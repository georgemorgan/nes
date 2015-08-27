#include "cpu.h"

/* STY (STORE INDEX Y IN MEMORY) */

void nes_cpu_sty_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("STY", address);
	
	cpu.write(address, cpu.y);
	
	cpu.pc += 2;
	
}

void nes_cpu_sty_zx(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zy("STY", address);
	
	cpu.write(address + cpu.x, cpu.y);
	
	cpu.pc += 2;
	
}

void nes_cpu_sty_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("STY", address);
	
	cpu.write(address, cpu.y);
	
	cpu.pc += 3;
	
}