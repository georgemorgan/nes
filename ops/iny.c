#include "cpu.h"

/* INY (INCREMENT Y INDEX BY ONE) */

/* MODIFIES: N Z */

void nes_cpu_iny(void) {
	
	log_op("INY");
	
	cpu.y ++;
	
	cpu_check_Z(cpu.y); cpu_check_N(cpu.y);
	
	cpu.pc ++;
	
}