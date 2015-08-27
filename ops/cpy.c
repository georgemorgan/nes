#include "cpu.h"

/* CPY (COMPARE MEMORY AND INDEX Y) */

void nes_cpu_cpy_im(void) {
	
	uint8_t immediate = cpu_get_op();
	
	log_im("CPY", (uint8_t)(immediate));
	
	if (cpu.y < immediate) { cpu_set_N(); cpu_clr_Z(); cpu_clr_C(); }
	
	else if (cpu.y == immediate) { cpu_clr_N(); cpu_set_Z(); cpu_set_C(); }
	
	else if (cpu.y > immediate) { cpu_clr_N(); cpu_clr_Z(); cpu_set_C(); }
	
	cpu.pc += 2;
	
}

void nes_cpu_cpy_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("CPY", address);
	
	uint8_t value = cpu.read(address);
	
	if (cpu.y < value) { cpu_set_N(); cpu_clr_Z(); cpu_clr_C(); }
	
	else if (cpu.y == value) { cpu_clr_N(); cpu_set_Z(); cpu_set_C(); }
	
	else if (cpu.y > value) { cpu_clr_N(); cpu_clr_Z(); cpu_set_C(); }
	
	cpu.pc += 2;
	
}

void nes_cpu_cpy_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("CPY", address);
	
	uint8_t value = cpu.read(address);
		
	if (cpu.y < value) { cpu_set_N(); cpu_clr_Z(); cpu_clr_C(); }
	
	else if (cpu.y == value) { cpu_clr_N(); cpu_set_Z(); cpu_set_C(); }
	
	else if (cpu.y > value) { cpu_clr_N(); cpu_clr_Z(); cpu_set_C(); }
	
	cpu.pc += 3;
	
}