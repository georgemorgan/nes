#include "cpu.h"

/* INC (INCREMENT MEMORY BY ONE) */

void nes_cpu_inc_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("INC", address);
	
	uint8_t value = cpu.read(address);
	
	value ++;
	
	cpu.write(address, value);
	
	cpu_check_Z(value); cpu_check_N(value);
	
	cpu.pc += 2;
	
}

void nes_cpu_inc_zx(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zx("INC", address);
	
	uint8_t value = cpu.read(address + cpu.x);
	
	value ++;
	
	cpu.write(address, value);
	
	cpu_check_Z(value); cpu_check_N(value);
	
	cpu.pc += 2;
	
}

void nes_cpu_inc_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("INC", address);
	
	uint8_t value = cpu.read(address);
	
	value ++;
	
	cpu.write(address, value);
	
	cpu_check_Z(value); cpu_check_N(value);
	
	cpu.pc += 3;
	
}

void nes_cpu_inc_ax(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("INC", address);
	
	uint8_t value = cpu.read(address + cpu.x);
	
	value ++;
	
	cpu.write(address, value);
	
	cpu_check_Z(value); cpu_check_N(value);
	
	cpu.pc += 3;
	
}