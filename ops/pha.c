#include "cpu.h"

/* PHA (PUSH ACCUMULATOR TO STACK) */

void nes_cpu_pha(void) {
	
	log_op("PHA");
	
	cpu.stack[cpu.sp --] = cpu.a;
	
	cpu.pc ++;
		
}