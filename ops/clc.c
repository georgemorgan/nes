#include "cpu.h"

/* CLC (CLEAR CARRY FLAG) */

void nes_cpu_clc(void) {
	
	log_op("CLC");
	
	cpu_clr_C();
	
	cpu.pc ++;
	
}