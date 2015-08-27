#include "cpu.h"

/* CMP (COMPARE MEMORY WITH ACCUMULATOR) */

void nes_cpu_cmp_im(void) {
	
	uint8_t immediate = cpu_get_op();
	
	log_im("CMP", (uint8_t)(immediate));
	
	if (cpu.a < immediate) { cpu_set_N(); cpu_clr_Z(); cpu_clr_C(); }
	
	else if (cpu.a == immediate) { cpu_clr_N(); cpu_set_Z(); cpu_set_C(); }
	
	else if (cpu.a > immediate) { cpu_clr_N(); cpu_clr_Z(); cpu_set_C(); }
	
	cpu.pc += 2;
	
}

void nes_cpu_cmp_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("CMP", address);
	
	uint8_t value = cpu.read(address);
	
	if (cpu.a < value) { cpu_set_N(); cpu_clr_Z(); cpu_clr_C(); }
	
	else if (cpu.a == value) { cpu_clr_N(); cpu_set_Z(); cpu_set_C(); }
	
	else if (cpu.a > value) { cpu_clr_N(); cpu_clr_Z(); cpu_set_C(); }
	
	cpu.pc += 2;
	
}

void nes_cpu_cmp_zx(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zx("CMP", address);
	
	uint8_t value = cpu.read(address + cpu.x);
	
	if (cpu.a < value) { cpu_set_N(); cpu_clr_Z(); cpu_clr_C(); }
	
	else if (cpu.a == value) { cpu_clr_N(); cpu_set_Z(); cpu_set_C(); }
	
	else if (cpu.a > value) { cpu_clr_N(); cpu_clr_Z(); cpu_set_C(); }
	
	cpu.pc += 2;
	
}

void nes_cpu_cmp_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("CMP", address);
	
	uint8_t value = cpu.read(address);
	
	if (cpu.a < value) { cpu_set_N(); cpu_clr_Z(); cpu_clr_C(); }
	
	else if (cpu.a == value) { cpu_clr_N(); cpu_set_Z(); cpu_set_C(); }
	
	else if (cpu.a > value) { cpu_clr_N(); cpu_clr_Z(); cpu_set_C(); }
	
	cpu.pc += 3;
	
}

void nes_cpu_cmp_ax(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ax("CMP", address);
	
	uint8_t value = cpu.read(address + cpu.x);
	
	if (cpu.a < value) { cpu_set_N(); cpu_clr_Z(); cpu_clr_C(); }
	
	else if (cpu.a == value) { cpu_clr_N(); cpu_set_Z(); cpu_set_C(); }
	
	else if (cpu.a > value) { cpu_clr_N(); cpu_clr_Z(); cpu_set_C(); }
	
	cpu.pc += 3;
	
}

void nes_cpu_cmp_ay(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ay("CMP", address);
	
	uint8_t value = cpu.read(address + cpu.y);
	
	if (cpu.a < value) { cpu_set_N(); cpu_clr_Z(); cpu_clr_C(); }
	
	else if (cpu.a == value) { cpu_clr_N(); cpu_set_Z(); cpu_set_C(); }
	
	else if (cpu.a > value) { cpu_clr_N(); cpu_clr_Z(); cpu_set_C(); }

	cpu.pc += 3;
	
}

void nes_cpu_cmp_ix(void) {
	
	uint8_t address = cpu_get_op();
	
	log_ix("CMP", address);
	
	uint8_t _address = cpu.read(address + cpu.x);
	
	uint8_t value = cpu.read(_address);
	
	if (cpu.a < value) { cpu_set_N(); cpu_clr_Z(); cpu_clr_C(); }
	
	else if (cpu.a == value) { cpu_clr_N(); cpu_set_Z(); cpu_set_C(); }
	
	else if (cpu.a > value) { cpu_clr_N(); cpu_clr_Z(); cpu_set_C(); }
	
	cpu.pc += 2;
	
}

void nes_cpu_cmp_iy(void) {
	
	uint8_t address = cpu_get_op();
	
	log_iy("CMP", address);
	
	uint8_t _address = cpu.read(address);
	
	uint8_t value = cpu.read(_address + cpu.y);
	
	if (cpu.a < value) { cpu_set_N(); cpu_clr_Z(); cpu_clr_C(); }
	
	else if (cpu.a == value) { cpu_clr_N(); cpu_set_Z(); cpu_set_C(); }
	
	else if (cpu.a > value) { cpu_clr_N(); cpu_clr_Z(); cpu_set_C(); }
	
	cpu.pc += 2;
	
}