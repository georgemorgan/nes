#include "cpu.h"

/* BEQ (BRANCH ON RESULT ZERO) */

void nes_cpu_beq(void) {
	
	if (cpu_get_Z()) {
		
		int8_t address = cpu_get_op();
		
		log_rl("BEQ", address + 2);
		
		cpu.pc += address;
		
	}
	
	cpu.pc += 2;
	
}