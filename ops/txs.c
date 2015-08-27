#include "cpu.h"

/* TXS (TRANSFER INDEX X TO STACK POINTER) */

void nes_cpu_txs(void) {
	
	log_op("TXS");
	
	cpu.sp = cpu.x;
		
	cpu_check_Z(cpu.sp); cpu_check_N(cpu.sp);
	
	cpu.pc ++;
	
}