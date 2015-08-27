#include "cpu.h"

/* TYA (TRANSFER INDEX Y TO ACCUMULATOR) */

void nes_cpu_tya(void) {
	
	log_op("TYA");
	
	cpu.a = cpu.y;
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc ++;
	
}