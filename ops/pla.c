#include "cpu.h"

/* PLA (PULL ACCUMULATOR FROM STACK) */

void nes_cpu_pla(void) {
	
	log_op("PLA");
	
	cpu.a = cpu.stack[cpu.sp ++];
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
		
	cpu.pc ++;
	
}