#include "cpu.h"

/* ASL (SHIFT LEFT ONE BIT: MEMORY OR ACCUMULATOR) */

void nes_cpu_asl_ac(void) {
	
	log_op("ASL A");
	
	uint16_t value = (uint16_t)(cpu.a) << 1;
	
	if (hi(value)) cpu_set_C();
	
	cpu.a = lo(value);

	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc ++;
	
}

void nes_cpu_asl_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("ASL", address);
	
	uint16_t value = cpu.read(address);
	
	value <<= 1;
	
	if (hi(value)) cpu_set_C();
	
	cpu.write(address, value);
	
	cpu_check_Z(value); cpu_check_N(value);
	
	cpu.pc += 2;
	
}

void nes_cpu_asl_zx(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zx("ASL", address);
	
	uint16_t value = cpu.read(address + cpu.x);
	
	value <<= 1;
	
	if (hi(value)) cpu_set_C();
	
	cpu.write(address, value);
	
	cpu_check_Z(value); cpu_check_N(value);
	
	cpu.pc += 2;
	
}

void nes_cpu_asl_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("ASL", address);
	
	uint16_t value = cpu.read(address);
	
	value <<= 1;
	
	if (hi(value)) cpu_set_C();
	
	cpu.write(address, value);
	
	cpu_check_Z(value); cpu_check_N(value);
	
	cpu.pc += 3;
	
}

void nes_cpu_asl_ax(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ax("ASL", address);
	
	uint16_t value = cpu.read(address + cpu.x);
	
	value <<= 1;
	
	if (hi(value)) cpu_set_C();
	
	cpu.write(address, value);
	
	cpu_check_Z(value); cpu_check_N(value);
	
	cpu.pc += 3;
	
}