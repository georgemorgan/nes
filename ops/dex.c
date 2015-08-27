#include "cpu.h"

/* DEX (DECREMENT INDEX X BY ONE) */

/* MODIFIES: N Z */

void nes_cpu_dex(void) {
	
	log_op("DEX");
	
	cpu.x --;
	
	cpu_check_Z(cpu.x); cpu_check_N(cpu.x);

	cpu.pc ++;
	
}