#include "cpu.h"

/* BCC (BRANCH ON CARRY CLEAR) */

void nes_cpu_bcc(void) {
	
	if (!cpu_get_C()) {
		
		int16_t address = cpu_get_op();
		
		log_ab("BCC", address + 2);
		
		cpu.pc += address;
		
	}
	
	cpu.pc += 2;
	
}