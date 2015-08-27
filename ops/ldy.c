#include "cpu.h"

/* LDY (LOAD INDEX Y WITH MEMORY) */

void nes_cpu_ldy_im(void) {
	
	uint8_t immediate = cpu_get_op();
	
	log_im("LDY", immediate);
	
	cpu.y = immediate;
	
	cpu_check_Z(immediate); cpu_check_N(immediate);
	
	cpu.pc += 2;
	
}

void nes_cpu_ldy_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("LDY", address);
	
	cpu.y = cpu.read(address);
	
	cpu_check_Z(cpu.y); cpu_check_N(cpu.y);
	
	cpu.pc += 2;
	
}

void nes_cpu_ldy_zx(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zx("LDY", address);
	
	cpu.y = cpu.read(address + cpu.x);
	
	cpu_check_Z(cpu.y); cpu_check_N(cpu.y);
	
	cpu.pc += 2;
	
}

void nes_cpu_ldy_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("LDY", address);
	
	cpu.y = cpu.read(address);
	
	cpu_check_Z(cpu.y); cpu_check_N(cpu.y);
	
	cpu.pc += 3;
	
}

void nes_cpu_ldy_ax(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ax("LDY", address);
	
	cpu.y = cpu.read(address + cpu.x);
	
	cpu_check_Z(cpu.y); cpu_check_N(cpu.y);
	
	cpu.pc += 3;
	
}