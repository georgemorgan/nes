#include "cpu.h"

/* ROR (ROTATE ONE BIT RIGHT) */

uint8_t ror(uint8_t value) {
	
	return (value >> 1) | (value << 7);
	
}

void nes_cpu_ror_ac(void) {
	
	log_op("ROR A");
	
	cpu.a = ror(cpu.a);
	
	cpu.pc += 1;
	
}

void nes_cpu_ror_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("ROR", address);
	
	uint8_t value = ror(cpu.read(address));
	
	cpu.write(value, address);
	
	cpu.pc += 2;
	
}

void nes_cpu_ror_zx(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zx("ROR", address);
	
	uint8_t value = ror(cpu.read(address + cpu.x));
	
	cpu.write(value, address);
	
	cpu.pc += 2;
	
}

void nes_cpu_ror_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("ROR", address);
	
	uint8_t value = ror(cpu.read(address));
	
	cpu.write(value, address);
	
	cpu.pc += 3;
	
}

void nes_cpu_ror_ax(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("ROR", address);
	
	uint8_t value = ror(cpu.read(address + cpu.x));
	
	cpu.write(value, address);
	
	cpu.pc += 3;
	
}