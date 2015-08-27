#include "cpu.h"

/* NOP (NO OPERATION) */

void nes_cpu_nop(void) {
	
	log_op("NOP");
	
	cpu.pc ++;
	
}