#include "cpu.h"

/* SEI (SET INTERRUPT DISABLE) */

void nes_cpu_sei(void) {
	
	log_op("SEI");
	
	cpu_set_I();
	
	cpu.pc ++;
	
}