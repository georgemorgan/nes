#include "cpu.h"

/* CLI (CLEAR INTERRUPT DISABLE BIT) */

void nes_cpu_cli(void) {
	
	log_op("CLI");
	
	cpu_clr_I();
	
	cpu.pc ++;
	
}