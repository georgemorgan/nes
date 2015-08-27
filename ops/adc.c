#include "cpu.h"

/* ADC (ADD MEMORY TO ACCUMULATOR WITH CARRY) */

/* MODIFIES: N Z C V */

void nes_cpu_adc_im(void) {
	
	uint8_t immediate = cpu_get_op();
	
	log_im("ADC", (uint8_t)(immediate));
	
	uint16_t result = cpu.a + immediate + cpu_get_C();
	
	if (~(cpu.a ^ immediate) & (cpu.a ^ lo(result)) & 0x80) cpu_set_V();
	
	if (hi(result)) cpu_set_C(); else cpu_clr_C();
	
	cpu.a = lo(result);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_adc_zp(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zp("ADC", address);
	
	uint8_t value = cpu.read(address);
	
	uint16_t result = cpu.a + value + cpu_get_C();
	
	if (~(cpu.a ^ value) & (cpu.a ^ lo(result)) & 0x80) cpu_set_V();
	
	if (hi(result)) cpu_set_C(); else cpu_clr_C();
	
	cpu.a = lo(result);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_adc_zx(void) {
	
	uint8_t address = cpu_get_op();
	
	log_zx("ADC", address);
	
	uint8_t value = cpu.read(address + cpu.x);
	
	uint16_t result = cpu.a + value + cpu_get_C();
	
	if (~(cpu.a ^ value) & (cpu.a ^ lo(result)) & 0x80) cpu_set_V();
	
	if (hi(result)) cpu_set_C(); else cpu_clr_C();
	
	cpu.a = lo(result);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_adc_ab(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ab("ADC", address);
	
	uint8_t value = cpu.read(address);
	
	uint16_t result = cpu.a + value + cpu_get_C();
	
	if (~(cpu.a ^ value) & (cpu.a ^ lo(result)) & 0x80) cpu_set_V();
	
	if (hi(result)) cpu_set_C(); else cpu_clr_C();
	
	cpu.a = lo(result);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 3;
	
}

void nes_cpu_adc_ax(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ax("ADC", address);
	
	uint8_t value = cpu.read(address + cpu.x);
	
	uint16_t result = cpu.a + value + cpu_get_C();
	
	if (~(cpu.a ^ value) & (cpu.a ^ lo(result)) & 0x80) cpu_set_V();
	
	if (hi(result)) cpu_set_C(); else cpu_clr_C();
	
	cpu.a = lo(result);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 3;

}

void nes_cpu_adc_ay(void) {
	
	uint16_t address = cpu_get_op16();
	
	log_ay("ADC", address);
	
	uint8_t value = cpu.read(address + cpu.y);
	
	uint16_t result = cpu.a + value + cpu_get_C();
	
	if (~(cpu.a ^ value) & (cpu.a ^ lo(result)) & 0x80) cpu_set_V();
	
	if (hi(result)) cpu_set_C(); else cpu_clr_C();
	
	cpu.a = lo(result);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 3;
	
}

void nes_cpu_adc_ix(void) {
	
	uint8_t address = cpu_get_op();
	
	log_ix("ADC", address);
	
	uint8_t _address = cpu.read(address + cpu.x);
	
	uint8_t value = cpu.read(_address);
	
	uint16_t result = cpu.a + value + cpu_get_C();
	
	if (~(cpu.a ^ value) & (cpu.a ^ lo(result)) & 0x80) cpu_set_V();
	
	if (hi(result)) cpu_set_C(); else cpu_clr_C();
	
	cpu.a = lo(result);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}

void nes_cpu_adc_iy(void) {
	
	uint8_t address = cpu_get_op();
	
	log_iy("ADC", address);
	
	uint8_t _address = cpu.read(address);
	
	uint8_t value = cpu.read(_address + cpu.y);
	
	uint16_t result = cpu.a + value + cpu_get_C();
	
	if (~(cpu.a ^ value) & (cpu.a ^ lo(result)) & 0x80) cpu_set_V();
	
	if (hi(result)) cpu_set_C(); else cpu_clr_C();
	
	cpu.a = lo(result);
	
	cpu_check_Z(cpu.a); cpu_check_N(cpu.a);
	
	cpu.pc += 2;
	
}