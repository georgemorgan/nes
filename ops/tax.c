#include "cpu.h"

/* TAX (TRANSFER ACCUMULATOR TO INDEX X) */

void nes_cpu_tax(void) {
	
	log_op("TAX");

	cpu.x = cpu.a;
	
	cpu_check_Z(cpu.x); cpu_check_N(cpu.x);
	
	cpu.pc ++;
	
}