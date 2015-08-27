#include "cpu.h"

/* INX (INCREMENT X INDEX BY ONE) */

/* MODIFIES: N Z */

void nes_cpu_inx(void) {
	
	log_op("INX");
	
	cpu.x ++;
	
	cpu_check_Z(cpu.x); cpu_check_N(cpu.x);
	
	cpu.pc ++;
	
}