#include "cpu.h"

/* TSX (TRANSFER STACK POINTER TO INDEX X) */

void nes_cpu_tsx(void) {
	
	log_op("TSX");
	
	cpu.x = cpu.sp;
	
	cpu_check_Z(cpu.x); cpu_check_N(cpu.x);
	
	cpu.pc ++;
	
}