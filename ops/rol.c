#include "cpu.h"

/* ROL (ROTATE ONE BIT LEFT) */

uint8_t rol(uint8_t value) {
	
	return (value << 1) | (value >> 7);
	
}

void nes_cpu_rol_ac(void) {
	
	log_op("ROL A");
	
	cpu.a = rol(cpu.a);
	
	cpu.pc += 1;
	
}

void nes_cpu_rol_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("ROL", address);
	
	uint8_t value = rol(cpu.read(address));
	
	cpu.write(value, address);
	
	cpu.pc += 2;
	
}

void nes_cpu_rol_zx(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zx("ROL", address);
	
	uint8_t value = rol(cpu.read(address + cpu.x));
	
	cpu.write(value, address);
	
	cpu.pc += 2;
	
}

void nes_cpu_rol_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("ROL", address);
	
	uint8_t value = rol(cpu.read(address));
	
	cpu.write(value, address);
	
	cpu.pc += 3;
	
}

void nes_cpu_rol_ax(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("ROL", address);
	
	uint8_t value = rol(cpu.read(address + cpu.x));
	
	cpu.write(value, address);
	
	cpu.pc += 3;
	
}