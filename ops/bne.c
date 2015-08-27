#include "cpu.h"

/* BNE (BRANCH ON RESULT NOT ZERO) */

void nes_cpu_bne(void) {
	
	if (!cpu_get_Z()) {
		
		int8_t address = cpu_get_op();
		
		log_rl("BNE", address + 2);
		
		cpu.pc += address;
		
	}
	
	cpu.pc += 2;
	
}