#include "cpu.h"

/* STX (STORE INDEX X IN MEMORY) */

void nes_cpu_stx_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("STX", address);
	
	cpu.write(address, cpu.x);
	
	cpu.pc += 2;
	
}

void nes_cpu_stx_zy(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zy("STX", address);
	
	cpu.write(address + cpu.y, cpu.x);
	
	cpu.pc += 2;
	
}

void nes_cpu_stx_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("STX", address);
	
	cpu.write(address, cpu.x);
	
	cpu.pc += 3;
	
}