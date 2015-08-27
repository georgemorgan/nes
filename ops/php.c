#include "cpu.h"

/* PHP (PUSH PROCESSOR STATUS TO STACK) */

void nes_cpu_php(void) {
	
	log_op("PHP");
	
	cpu.stack[cpu.sp --] = cpu.sreg;
	
	cpu.pc ++;
	
}