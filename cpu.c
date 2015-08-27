#include "cpu.h"

struct _cpu cpu = { .step = &nes_cpu_step, .read = &_nes_cpu_read, .write = &_nes_cpu_write };

uint8_t _nes_cpu_read(uint16_t address) {
	
	return (nes_cpu_read[(address / 0x800)])(address);
	
}

void _nes_cpu_write(uint16_t address, uint8_t value) {
	
	(nes_cpu_write[(address / 0x800)])(address, value);
	
}


void nes_cpu_step(void) {
	
	(nes_cpu_exec[cpu.read(cpu.pc)])();
	
}

void cpu_restore_PC(void) {
	
	/* WTF? */
	
	cpu.sp ++;
	
	uint8_t hia = cpu.stack[cpu.sp];
	
	cpu.sp ++;
	
	uint8_t loa = cpu.stack[cpu.sp];
	
	cpu.pc = ((hia << 8) | loa);
	
}

void cpu_save_PC(void) {
	
	cpu.stack[cpu.sp] = lo(cpu.pc);
	
	cpu.sp --;
	
	cpu.stack[cpu.sp] = hi(cpu.pc);
	
	/* WTF? */
	
	cpu.sp --;
	
}

void cpu_generate_NMI(void) {
	
	cpu_set_I();
	
	cpu_save_PC();
	
	cpu.stack[cpu.sp --] = cpu.sreg;
	
	cpu.pc = ((cpu.read(0xFFFB) << 8) | cpu.read(0xFFFA));
	
}

void cpu_check_N(int8_t result) {
	
	if (result < 0) cpu_set_N(); else cpu_clr_N();
	
}

void cpu_check_V(uint8_t result) {
	
	
	
}

void cpu_check_Z(uint8_t result) {
	
	if (result == 0) cpu_set_Z(); else cpu_clr_Z();
	
}

void cpu_check_C(uint8_t result) {
	
	
	
}

void nes_cpu_null_op(void) {
	
	printf("CPU ERROR: The executed opcode '%02x' is invalid.\n\n", cpu.read(cpu.pc));
	
	exit(EXIT_FAILURE);
	
}

/* ~ This array maps vaild 6502 opcodes to their counterpart functions. ~ */

void (* nes_cpu_exec[0x100])(void) = {
	
	&nes_cpu_brk,
	&nes_cpu_ora_ix,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_ora_zp,
	&nes_cpu_asl_zp,
	&nes_cpu_null_op,
	&nes_cpu_php,
	&nes_cpu_ora_im,
	&nes_cpu_asl_ac,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_ora_ab,
	&nes_cpu_asl_ab,
	&nes_cpu_null_op,
	&nes_cpu_bpl,
	&nes_cpu_ora_iy,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_ora_zx,
	&nes_cpu_asl_zx,
	&nes_cpu_null_op,
	&nes_cpu_clc,
	&nes_cpu_ora_ay,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_ora_ax,
	&nes_cpu_asl_ax,
	&nes_cpu_null_op,
	&nes_cpu_jsr_ab,
	&nes_cpu_and_ix,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_bit_zp,
	&nes_cpu_and_zp,
	&nes_cpu_rol_zp,
	&nes_cpu_null_op,
	&nes_cpu_plp,
	&nes_cpu_and_im,
	&nes_cpu_rol_ac,
	&nes_cpu_null_op,
	&nes_cpu_bit_ab,
	&nes_cpu_and_ab,
	&nes_cpu_rol_ab,
	&nes_cpu_null_op,
	&nes_cpu_bmi,
	&nes_cpu_and_iy,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_and_zx,
	&nes_cpu_rol_zx,
	&nes_cpu_null_op,
	&nes_cpu_sec,
	&nes_cpu_and_ay,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_and_ax,
	&nes_cpu_rol_ax,
	&nes_cpu_null_op,
	&nes_cpu_rti,
	&nes_cpu_eor_ix,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_eor_zp,
	&nes_cpu_lsr_zp,
	&nes_cpu_null_op,
	&nes_cpu_pha,
	&nes_cpu_eor_im,
	&nes_cpu_lsr_ac,
	&nes_cpu_null_op,
	&nes_cpu_jmp_ab,
	&nes_cpu_eor_ab,
	&nes_cpu_lsr_ab,
	&nes_cpu_null_op,
	&nes_cpu_bvc,
	&nes_cpu_eor_iy,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_eor_zx,
	&nes_cpu_lsr_zx,
	&nes_cpu_null_op,
	&nes_cpu_cli,
	&nes_cpu_eor_ay,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_eor_ax,
	&nes_cpu_lsr_ax,
	&nes_cpu_null_op,
	&nes_cpu_rts,
	&nes_cpu_adc_ix,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_adc_zp,
	&nes_cpu_ror_zp,
	&nes_cpu_null_op,
	&nes_cpu_pla,
	&nes_cpu_adc_im,
	&nes_cpu_ror_ac,
	&nes_cpu_null_op,
	&nes_cpu_jmp_in,
	&nes_cpu_adc_ab,
	&nes_cpu_ror_ab,
	&nes_cpu_null_op,
	&nes_cpu_bvs,
	&nes_cpu_adc_iy,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_adc_zx,
	&nes_cpu_ror_zx,
	&nes_cpu_null_op,
	&nes_cpu_sei,
	&nes_cpu_adc_ay,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_adc_ax,
	&nes_cpu_ror_ax,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_sta_ix,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_sty_zp,
	&nes_cpu_sta_zp,
	&nes_cpu_stx_zp,
	&nes_cpu_null_op,
	&nes_cpu_dey,
	&nes_cpu_null_op,
	&nes_cpu_txa,
	&nes_cpu_null_op,
	&nes_cpu_sty_ab,
	&nes_cpu_sta_ab,
	&nes_cpu_stx_ab,
	&nes_cpu_null_op,
	&nes_cpu_bcc,
	&nes_cpu_sta_iy,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_sty_zx,
	&nes_cpu_sta_zx,
	&nes_cpu_stx_zy,
	&nes_cpu_null_op,
	&nes_cpu_tya,
	&nes_cpu_sta_ay,
	&nes_cpu_txs,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_sta_ax,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_ldy_im,
	&nes_cpu_lda_ix,
	&nes_cpu_ldx_im,
	&nes_cpu_null_op,
	&nes_cpu_ldy_zp,
	&nes_cpu_lda_zp,
	&nes_cpu_ldx_zp,
	&nes_cpu_null_op,
	&nes_cpu_tay,
	&nes_cpu_lda_im,
	&nes_cpu_tax,
	&nes_cpu_null_op,
	&nes_cpu_ldy_ab,
	&nes_cpu_lda_ab,
	&nes_cpu_ldx_ab,
	&nes_cpu_null_op,
	&nes_cpu_bcs,
	&nes_cpu_lda_iy,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_ldy_zx,
	&nes_cpu_lda_zx,
	&nes_cpu_ldx_zy,
	&nes_cpu_null_op,
	&nes_cpu_clv,
	&nes_cpu_lda_ay,
	&nes_cpu_tsx,
	&nes_cpu_null_op,
	&nes_cpu_ldy_ax,
	&nes_cpu_lda_ax,
	&nes_cpu_ldx_ay,
	&nes_cpu_null_op,
	&nes_cpu_cpy_im,
	&nes_cpu_cmp_ix,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_cpy_zp,
	&nes_cpu_cmp_zp,
	&nes_cpu_dec_zp,
	&nes_cpu_null_op,
	&nes_cpu_iny,
	&nes_cpu_cmp_im,
	&nes_cpu_dex,
	&nes_cpu_null_op,
	&nes_cpu_cpy_ab,
	&nes_cpu_cmp_ab,
	&nes_cpu_dec_ab,
	&nes_cpu_null_op,
	&nes_cpu_bne,
	&nes_cpu_cmp_iy,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_cmp_zx,
	&nes_cpu_dec_zx,
	&nes_cpu_null_op,
	&nes_cpu_cld,
	&nes_cpu_cmp_ay,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_cmp_ax,
	&nes_cpu_dec_ax,
	&nes_cpu_null_op,
	&nes_cpu_cpx_im,
	&nes_cpu_sbc_ix,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_cpx_zp,
	&nes_cpu_sbc_zp,
	&nes_cpu_inc_zp,
	&nes_cpu_null_op,
	&nes_cpu_inx,
	&nes_cpu_sbc_im,
	&nes_cpu_nop,
	&nes_cpu_null_op,
	&nes_cpu_cpx_ab,
	&nes_cpu_sbc_ab,
	&nes_cpu_inc_ab,
	&nes_cpu_null_op,
	&nes_cpu_beq,
	&nes_cpu_sbc_iy,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_sbc_zx,
	&nes_cpu_inc_zx,
	&nes_cpu_null_op,
	&nes_cpu_sed,
	&nes_cpu_sbc_ay,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_null_op,
	&nes_cpu_sbc_ax,
	&nes_cpu_inc_ax,
	&nes_cpu_null_op
	
};