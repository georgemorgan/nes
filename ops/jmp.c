#include "cpu.h"

/* JMP (JUMP TO NEW LOCATION) */

void nes_cpu_jmp_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("JMP", address);
	
	cpu.pc = address;
	
}

void nes_cpu_jmp_in(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_in("JMP", address);
	
	cpu.pc = ((cpu.read(address + 1) << 8) | cpu.read(address));
	
}