#include "cpu.h"

/* AND (AND MEMORY WITH ACCUMULATOR) */

void nes_cpu_and_im(void) {
	
	uint8_t value = cpu_get_op();
	
	log_im("AND", value);

	cpu.a &= value;
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
		
	cpu.pc += 2;
	
}

void nes_cpu_and_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("AND", address);
	
	cpu.a &= cpu.read(address);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_and_zx(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zx("AND", address);
	
	cpu.a &= cpu.read(address + cpu.x);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_and_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("AND", address);
	
	cpu.a &= cpu.read(address);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 3;
	
}

void nes_cpu_and_ax(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ax("AND", address);
	
	cpu.a &= cpu.read(address + cpu.x);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 3;
	
}

void nes_cpu_and_ay(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ay("AND", address);
	
	cpu.a &= cpu.read(address + cpu.y);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 3;
	
}

void nes_cpu_and_ix(void) {
	
	uint8_t address = cpu_get_op();
	
	log_ix("AND", address);
	
	uint16_t indirect = cpu.read(address + cpu.x);
	
	cpu.a &= cpu.read(indirect);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_and_iy(void) {
	
	uint8_t address = cpu_get_op();
	
	log_iy("AND", address);
	
	uint16_t _address = cpu.read(address);
	
	cpu.a &= cpu.read(_address + cpu.y);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}