#include "cpu.h"

/* DEC (DECREMENT MEMORY BY ONE) */

void nes_cpu_dec_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("DEC", address);
	
	uint8_t value = cpu.read(address);
	
	value --;
	
	cpu.write(address, value);
	
	cpu_check_Z(value); cpu_check_N(value);
	
	cpu.pc += 2;
	
}

void nes_cpu_dec_zx(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zx("DEC", address);
	
	uint8_t value = cpu.read(address + cpu.x);
	
	value --;
	
	cpu.write(address, value);
	
	cpu_check_Z(value); cpu_check_N(value);
	
	cpu.pc += 2;
	
}

void nes_cpu_dec_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("DEC", address);
	
	uint8_t value = cpu.read(address);
	
	value --;
	
	cpu.write(address, value);
	
	cpu_check_Z(value); cpu_check_N(value);
	
	cpu.pc += 3;
	
}

void nes_cpu_dec_ax(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ax("DEC", address);
	
	uint8_t value = cpu.read(address + cpu.x);
	
	value --;
	
	cpu.write(address, value);
	
	cpu_check_Z(value); cpu_check_N(value);
	
	cpu.pc += 3;
	
}