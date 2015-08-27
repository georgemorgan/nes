#include "cpu.h"

/* STA (STORE ACCUMULATOR IN MEMORY) */

void nes_cpu_sta_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("STA", address);
	
	cpu.write(address, cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_sta_zx(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zx("STA", address);
	
	cpu.write(address + cpu.x, cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_sta_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("STA", address);
	
	cpu.write(address, cpu.a);
	
	cpu.pc += 3;
	
}

void nes_cpu_sta_ax(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ax("STA", address);
	
	cpu.write(address + cpu.x, cpu.a);
	
	cpu.pc += 3;
	
}

void nes_cpu_sta_ay(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ay("STA", address);
	
	cpu.write(address + cpu.y, cpu.a);
	
	cpu.pc += 3;
	
}

void nes_cpu_sta_ix(void) {
	
	uint8_t address = cpu_get_op();
	
	log_ix("STA", address);
	
	uint8_t _address = cpu.read(address + cpu.x);
	
	cpu.write(_address, cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_sta_iy(void) {
	
	uint8_t address = cpu_get_op();
	
	log_iy("STA", address);
	
	uint8_t _address = cpu.read(address);
	
	cpu.write(_address + cpu.y, cpu.a);
	
	cpu.pc += 2;
	
}