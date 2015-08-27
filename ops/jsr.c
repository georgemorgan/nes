#include "cpu.h"

/* JSR (JUMP TO NEW LOCATION AND SAVE RETURN ADDRESS) */

void nes_cpu_jsr_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("JSR", address);
	
	cpu.pc += 3;

	cpu_save_PC();
	
	cpu.pc = address;
	
}