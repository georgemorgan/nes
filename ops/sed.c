#include "cpu.h"

/* SED (SET DECIMAL FLAG) */

void nes_cpu_sed(void) {
	
	log_op("SED");
	
	cpu_set_D();
	
	cpu.pc ++;
	
}