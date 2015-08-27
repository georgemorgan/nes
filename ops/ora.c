#include "cpu.h"

/* ORA (OR MEMORY WITH ACCUMULATOR) */

void nes_cpu_ora_im(void) {
	
	uint8_t immediate = cpu_get_op();
	
	log_im("ORA", immediate);
	
	cpu.a |= immediate;
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_ora_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("ORA", address);
	
	cpu.a |= cpu.read(address);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_ora_zx(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zx("ORA", address);
	
	cpu.a |= cpu.read(address + cpu.x);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_ora_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("ORA", address);
	
	cpu.a |= cpu.read(address);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 3;
	
}

void nes_cpu_ora_ax(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ax("ORA", address);
	
	cpu.a |= cpu.read(address + cpu.x);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 3;
	
}

void nes_cpu_ora_ay(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ay("ORA", address);
	
	cpu.a |= cpu.read(address + cpu.y);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 3;
	
}

void nes_cpu_ora_ix(void) {
	
	uint8_t address = cpu_get_op();
	
	log_ix("ORA", address);
	
	uint8_t _address = cpu.read(address + cpu.x);
	
	cpu.a |= cpu.read(_address);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_ora_iy(void) {
	
	uint8_t address = cpu_get_op();
	
	log_iy("ORA", address);
	
	uint8_t _address = cpu.read(address);
	
	cpu.a |= cpu.read(_address + cpu.y);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}