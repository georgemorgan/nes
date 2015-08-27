#include "cpu.h"

/* LSR (SHIFT ONE BIT RIGHT) */

void nes_cpu_lsr_ac(void) {
	
	log_op("LSR A");
	
	uint16_t value = (uint16_t)(cpu.a) >> 1;
	
	if (hi(value)) cpu_set_C();
	
	cpu.a = lo(value);
	
	cpu_check_Z(cpu.a);
	
	cpu.pc ++;
	
}

void nes_cpu_lsr_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("LSR", address);
	
	uint16_t value = cpu.read(address);
	
	value >>= 1;
	
	if (hi(value)) cpu_set_C();
	
	cpu.write(address, value);
	
	cpu_check_Z(value);
	
	cpu.pc += 2;
	
}

void nes_cpu_lsr_zx(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zx("LSR", address);
	
	uint16_t value = cpu.read(address + cpu.x);
	
	value >>= 1;
	
	if (hi(value)) cpu_set_C();
	
	cpu.write(address, value);
	
	cpu_check_Z(value);
	
	cpu.pc += 2;
	
}

void nes_cpu_lsr_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("LSR", address);
	
	uint16_t value = cpu.read(address);
	
	value >>= 1;
	
	if (hi(value)) cpu_set_C();
	
	cpu.write(address, value);
	
	cpu_check_Z(value);
	
	cpu.pc += 3;
	
}

void nes_cpu_lsr_ax(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ax("LSR", address);
	
	uint16_t value = cpu.read(address + cpu.x);
	
	value <<= 1;
	
	if (hi(value)) cpu_set_C();
	
	cpu.write(address, value);
	
	cpu_check_Z(value);
	
	cpu.pc += 3;
	
}