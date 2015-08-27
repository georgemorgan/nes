#include "cpu.h"

/* BCS (BRANCH ON CARRY SET) */

void nes_cpu_bcs(void) {
	
	if (cpu_get_C()) {
		
		int8_t address = cpu_get_op();
		
		log_rl("BCS", address + 2);
		
		cpu.pc += address;
		
	}
	
	cpu.pc += 2;
	
}