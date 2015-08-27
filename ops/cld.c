#include "cpu.h"

/* CLD (CLEAR DECIMAL MODE) */

void nes_cpu_cld(void) {
	
	log_op("CLD");
	
	cpu_clr_D();

	cpu.pc ++;
	
}