#include "cpu.h"

/* PLP (PULL PROCESSOR STATUS FROM STACK) */

void nes_cpu_plp(void) {
	
	log_op("PLP");
	
	cpu.sreg = cpu.stack[cpu.sp ++];
	
	cpu.pc ++;
		
}