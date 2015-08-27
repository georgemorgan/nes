#include "cpu.h"

/* RTI (RETURN FROM INTERRUPT) */

void nes_cpu_rti(void) {
	
	log_op("RTI");

	cpu_clr_I();
	
	cpu.stack[cpu.sp ++] = cpu.sreg;
	
	cpu_restore_PC();
	
	exit(EXIT_SUCCESS);
	
}