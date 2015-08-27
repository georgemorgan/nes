#include "cpu.h"

/* DEY (DECREMENT INDEX Y BY ONE) */

void nes_cpu_dey(void) {
	
	log_op("DEY");
	
	cpu.y --;
	
	cpu_check_Z(cpu.y); cpu_check_N(cpu.y);
	
	cpu.pc ++;
	
}