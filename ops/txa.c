#include "cpu.h"

/* TXA (TRANSFER INDEX X TO ACCUMULATOR) */

void nes_cpu_txa(void) {
	
	log_op("TXA");
	
	cpu.a = cpu.x;
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc ++;
	
}