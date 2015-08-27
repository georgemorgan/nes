#include "cpu.h"

/* BMI (BRANCH ON RESULT MINUS) */

void nes_cpu_bmi(void) {
	
	if (cpu_get_N()) {
		
		int8_t address = cpu_get_op();
		
		log_rl("BMI", address + 2);
		
		cpu.pc += address;
		
	}
	
	cpu.pc += 2;
	
}