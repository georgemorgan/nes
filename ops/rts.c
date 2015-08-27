#include "cpu.h"

/* RTS (RETURN FROM SUBROUTINE) */

void nes_cpu_rts(void) {
	
	log_op("RTS");
	
	cpu_restore_PC();
	
}