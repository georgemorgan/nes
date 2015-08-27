#include "cpu.h"

/* LDX (LOAD INDEX X WITH MEMORY) */

void nes_cpu_ldx_im(void) {
	
	uint8_t immediate = cpu_get_op();
	
	log_im("LDX", immediate);
	
	cpu.x = immediate;
	
	cpu_check_Z(immediate); cpu_check_N(immediate);
	
	cpu.pc += 2;
	
}

void nes_cpu_ldx_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("LDX", address);
	
	cpu.x = cpu.read(address);
	
	cpu_check_Z(cpu.x); cpu_check_N(cpu.x);
	
	cpu.pc += 2;
	
}

void nes_cpu_ldx_zy(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zy("LDX", address);
	
	cpu.x = cpu.read(address + cpu.y);
	
	cpu_check_Z(cpu.x); cpu_check_N(cpu.x);
	
	cpu.pc += 2;
	
}

void nes_cpu_ldx_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("LDX", address);
	
	cpu.x = cpu.read(address);
	
	cpu_check_Z(cpu.x); cpu_check_N(cpu.x);
	
	cpu.pc += 3;
	
}

void nes_cpu_ldx_ay(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ay("LDX", address);
	
	cpu.x = cpu.read(address + cpu.y);
	
	cpu_check_Z(cpu.x); cpu_check_N(cpu.x);
	
	cpu.pc += 3;
	
}