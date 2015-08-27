#include "cpu.h"

/* BIT (TEST BITS IN MEMORY WITH ACCUMULATOR) */

void nes_cpu_bit_zp(void) {

	uint8_t address = cpu_get_op();
	
	log_zp("BIT", address);

	uint8_t value = cpu.read(address);
	
	uint8_t test = cpu.a & value;
	
	cpu_check_Z(test);
	
	if (((value >> 7) & 1)) { cpu_set_N(); } else { cpu_clr_N(); }
	
	if (((value >> 6) & 1)) { cpu_set_V(); } else { cpu_clr_V(); }
	
	cpu.pc += 2;
	
}

void nes_cpu_bit_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_zp("BIT", address);
	
	uint8_t value = cpu.read(address);
	
	uint8_t test = cpu.a & value;
	
	cpu_check_Z(test);
	
	if (((value >> 7) & 1)) { cpu_set_N(); } else { cpu_clr_N(); }
	
	if (((value >> 6) & 1)) { cpu_set_V(); } else { cpu_clr_V(); }
	
	cpu.pc += 3;
	
}