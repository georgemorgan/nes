#include "cpu.h"

/* TAY (TRANSFER ACCUMULATOR TO INDEX Y) */

void nes_cpu_tay(void) {
	
	log_op("TAY");
	
	cpu.y = cpu.a;
	
	cpu_check_Z(cpu.y); cpu_check_N(cpu.y);
	
	cpu.pc ++;
	
}