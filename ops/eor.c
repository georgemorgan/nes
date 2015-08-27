#include "cpu.h"

/* EOR (EXCLUSIVE OR MEMORY WITH ACCUMULATOR) */

void nes_cpu_eor_im(void) {
	
	uint8_t immediate = cpu_get_op();
	
	log_im("EOR", immediate);
	
	cpu.a ^= immediate;
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_eor_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("EOR", address);
	
	uint8_t value = cpu.read(address);
	
	cpu.a ^= value;
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_eor_zx(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zx("EOR", address);
	
	uint8_t value = cpu.read(address + cpu.x);
	
	cpu.a ^= value;
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_eor_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("EOR", address);
	
	uint8_t value = cpu.read(address);
	
	cpu.a ^= value;
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 3;
	
}

void nes_cpu_eor_ax(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ax("EOR", address);
	
	uint8_t value = cpu.read(address + cpu.x);
	
	cpu.a ^= value;
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 3;
	
}

void nes_cpu_eor_ay(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ax("EOR", address);
	
	uint8_t value = cpu.read(address + cpu.y);
	
	cpu.a ^= value;
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 3;
	
}

void nes_cpu_eor_ix(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zx("EOR", address);
	
	uint8_t _address = cpu.read(address + cpu.x);
	
	uint8_t value = cpu.read(_address);
	
	cpu.a ^= value;
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_eor_iy(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zx("EOR", address);
	
	uint8_t _address = cpu.read(address);
	
	uint8_t value = cpu.read(_address + cpu.y);
	
	cpu.a ^= value;
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}