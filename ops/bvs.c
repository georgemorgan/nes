#include "cpu.h"

/* BVS (BRANCH ON OVERFLOW SET) */

void nes_cpu_bvs(void) {
	
	if (cpu_get_V()) {
		
		int8_t address = cpu_get_op();
		
		log_rl("BVS", address + 2);
		
		cpu.pc += address;
		
	}
	
	cpu.pc += 2;
	
}