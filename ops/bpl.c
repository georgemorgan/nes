#include "cpu.h"

/* BPL (BRANCH ON RESULT PLUS) */

void nes_cpu_bpl(void) {
	
	if (!cpu_get_N()) {
		
		int8_t address = cpu_get_op();
		
		log_rl("BPL", address + 2);
		
		cpu.pc += address;
		
	}
	
	cpu.pc += 2;
	
}