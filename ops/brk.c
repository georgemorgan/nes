#include "cpu.h"

/* BRK (FORCE BREAK) */

/* MODIFIES: B */

void nes_cpu_brk(void) {
	
	log_op("BRK");
	
	cpu_set_B();
	
	if (!cpu_get_I()) {
		
		cpu_set_I();
		
		cpu_save_PC();
		
		cpu.stack[cpu.sp --] = cpu.sreg;
		
		cpu.pc = ((cpu.read(0xFFFE) << 8) | cpu.read(0xFFFF));
		
	}
	
	exit(-1);
	
}