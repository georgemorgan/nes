#include "cpu.h"

/* SBC (SUBTRACT MEMORY FROM ACCUMULATOR WITH BORROW) */

void nes_cpu_sbc_im(void) {
	
	int8_t immediate = cpu_get_op();
	
	log_im("SBC", (uint8_t)(immediate));
	
	if (cpu_get_C()) cpu_clr_C(); else cpu_set_C();
	
	uint16_t result = cpu.a - immediate - cpu_get_C();
	
	if (~(cpu.a ^ immediate) & (cpu.a ^ lo(result)) & 0x80) cpu_clr_V();
	
	if (hi(result)) cpu_clr_C(); else cpu_set_C();
	
	cpu.a = lo(result);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_sbc_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("SBC", address);
	
	if (cpu_get_C()) cpu_clr_C(); else cpu_set_C();
	
	uint8_t value = cpu.read(address);
	
	uint16_t result = cpu.a - value - cpu_get_C();
	
	cpu_clr_N(); cpu_clr_V(); cpu_clr_C(); cpu_clr_Z();
	
	if (~(cpu.a ^ value) & (cpu.a ^ lo(result)) & 0x80) cpu_clr_V();
	
	if (hi(result)) cpu_clr_C(); else cpu_set_C();
	
	cpu.a = lo(result);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_sbc_zx(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zx("SBC", address);
	
	if (cpu_get_C()) cpu_clr_C(); else cpu_set_C();
	
	uint8_t value = cpu.read(address + cpu.x);
	
	uint16_t result = cpu.a - value - cpu_get_C();
	
	cpu_clr_N(); cpu_clr_V(); cpu_clr_C(); cpu_clr_Z();
	
	if (~(cpu.a ^ value) & (cpu.a ^ lo(result)) & 0x80) cpu_clr_V();
	
	if (hi(result)) cpu_clr_C(); else cpu_set_C();
	
	cpu.a = lo(result);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_sbc_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("SBC", address);
	
	if (cpu_get_C()) cpu_clr_C(); else cpu_set_C();
	
	uint8_t value = cpu.read(address);
	
	uint16_t result = cpu.a - value - cpu_get_C();
	
	cpu_clr_N(); cpu_clr_V(); cpu_clr_C(); cpu_clr_Z();
	
	if (~(cpu.a ^ value) & (cpu.a ^ lo(result)) & 0x80) cpu_clr_V();
	
	if (hi(result)) cpu_clr_C(); else cpu_set_C();
	
	cpu.a = lo(result);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 3;
	
}

void nes_cpu_sbc_ax(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ax("SBC", address);
	
	if (cpu_get_C()) cpu_clr_C(); else cpu_set_C();
	
	uint8_t value = cpu.read(address + cpu.x);
	
	uint16_t result = cpu.a - value - cpu_get_C();
	
	cpu_clr_N(); cpu_clr_V(); cpu_clr_C(); cpu_clr_Z();
	
	if (~(cpu.a ^ value) & (cpu.a ^ lo(result)) & 0x80) cpu_clr_V();
	
	if (hi(result)) cpu_clr_C(); else cpu_set_C();
	
	cpu.a = lo(result);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 3;
	
}

void nes_cpu_sbc_ay(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ay("SBC", address);
	
	if (cpu_get_C()) cpu_clr_C(); else cpu_set_C();
	
	uint8_t value = cpu.read(address + cpu.y);
	
	uint16_t result = cpu.a - value - cpu_get_C();
	
	cpu_clr_N(); cpu_clr_V(); cpu_clr_C(); cpu_clr_Z();
	
	if (~(cpu.a ^ value) & (cpu.a ^ lo(result)) & 0x80) cpu_clr_V();
	
	if (hi(result)) cpu_clr_C(); else cpu_set_C();
	
	cpu.a = lo(result);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 3;
	
}

void nes_cpu_sbc_ix(void) {
	
	uint8_t address = cpu_get_op();
	
	log_ix("SBC", address);
	
	if (cpu_get_C()) cpu_clr_C(); else cpu_set_C();
	
	uint8_t _address = cpu.read(address + cpu.x);
	
	uint8_t value = cpu.read(_address);
	
	uint16_t result = cpu.a - value - cpu_get_C();
	
	cpu_clr_N(); cpu_clr_V(); cpu_clr_C(); cpu_clr_Z();
	
	if (~(cpu.a ^ value) & (cpu.a ^ lo(result)) & 0x80) cpu_clr_V();
	
	if (hi(result)) cpu_clr_C(); else cpu_set_C();
	
	cpu.a = lo(result);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_sbc_iy(void) {
	
	uint8_t address = cpu_get_op();
	
	log_iy("SBC", address);
	
	if (cpu_get_C()) cpu_clr_C(); else cpu_set_C();
	
	uint8_t _address = cpu.read(address);
	
	uint8_t value = cpu.read(_address + cpu.y);
	
	uint16_t result = cpu.a - value - cpu_get_C();
	
	cpu_clr_N(); cpu_clr_V(); cpu_clr_C(); cpu_clr_Z();
	
	if (~(cpu.a ^ value) & (cpu.a ^ lo(result)) & 0x80) cpu_clr_V();
	
	if (hi(result)) cpu_clr_C(); else cpu_set_C();
	
	cpu.a = lo(result);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}