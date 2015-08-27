#include "cpu.h"

/* SEC (SET CARRY FLAG) */

void nes_cpu_sec(void) {
	
	log_op("SEC");
	
	cpu_set_C();
	
	cpu.pc ++;
	
}