#include "cpu.h"

/* LDA (LOAD ACCUMULATOR WITH MEMORY) */

void nes_cpu_lda_im(void) {
	
	uint8_t immediate = cpu_get_op();
	
	log_im("LDA", immediate);
	
	cpu.a = immediate;
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_lda_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("LDA", address);
	
	cpu.a = cpu.read(address);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_lda_zx(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zx("LDA", address);
	
	cpu.a = cpu.read(address + cpu.x);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_lda_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("LDA", address);
	
	cpu.a = cpu.read(address);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 3;
	
}

void nes_cpu_lda_ax(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ax("LDA", address);
	
	cpu.a = cpu.read(address + cpu.x);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 3;
	
}

void nes_cpu_lda_ay(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ay("LDA", address);
	
	cpu.a = cpu.read(address + cpu.y);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);

		cpu.pc += 3;
	
}

void nes_cpu_lda_ix(void) {
	
	uint8_t address = cpu_get_op();
	
	log_ix("LDA", address);
	
	uint8_t _address = cpu.read(address + cpu.x);
	
	cpu.a = cpu.read(_address);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_lda_iy(void) {
	
	uint8_t address = cpu_get_op();
	
	log_iy("LDA", address);
	
	uint8_t _address = cpu.read(address);
	
	cpu.a = cpu.read(_address + cpu.y);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}