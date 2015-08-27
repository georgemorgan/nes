#include "cpu.h"

/* CPX (COMPARE MEMORY WITH INDEX X) */

void nes_cpu_cpx_im(void) {
	
	uint8_t immediate = cpu_get_op();
	
	log_im("CPX", (uint8_t)(immediate));
	
	if (cpu.x < immediate) { cpu_set_N(); cpu_clr_Z(); cpu_clr_C(); }
	
	else if (cpu.x == immediate) { cpu_clr_N(); cpu_set_Z(); cpu_set_C(); }
	
	else if (cpu.x > immediate) { cpu_clr_N(); cpu_clr_Z(); cpu_set_C(); }
	
	cpu.pc += 2;
	
}

void nes_cpu_cpx_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("CPX", address);
	
	uint8_t value = cpu.read(address);
	
	if (cpu.x < value) { cpu_set_N(); cpu_clr_Z(); cpu_clr_C(); }
	
	else if (cpu.x == value) { cpu_clr_N(); cpu_set_Z(); cpu_set_C(); }
	
	else if (cpu.x > value) { cpu_clr_N(); cpu_clr_Z(); cpu_set_C(); }
	
	cpu.pc += 2;
	
}

void nes_cpu_cpx_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("CPX", address);
	
	uint8_t value = cpu.read(address);
		
	if (cpu.x < value) { cpu_set_N(); cpu_clr_Z(); cpu_clr_C(); }
	
	else if (cpu.x == value) { cpu_clr_N(); cpu_set_Z(); cpu_set_C(); }
	
	else if (cpu.x > value) { cpu_clr_N(); cpu_clr_Z(); cpu_set_C(); }
	
	cpu.pc += 3;
	
}