#include "cpu.h"

/* CLV (CLEAR OVERFLOW FLAG) */

void nes_cpu_clv(void) {
	
	log_op("CLV");
	
	cpu_clr_V();
	
	cpu.pc ++;
	
}