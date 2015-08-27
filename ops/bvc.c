#include "cpu.h"

/* BVC (BRANCH ON OVERFLOW CLEAR) */

void nes_cpu_bvc(void) {
	
	if (!cpu_get_V()) {
		
		int8_t address = cpu_get_op();
		
		log_rl("BVC", address + 2);
		
		cpu.pc += address;
		
	}
	
	cpu.pc += 2;
	
}