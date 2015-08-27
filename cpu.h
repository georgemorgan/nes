#ifndef cpu_h

#define cpu_h

#include "nes.h"

#define cpu_get_N() ((cpu.sreg >> 7) & 1)

#define cpu_set_N() cpu.sreg |= (1 << 7)

#define cpu_clr_N() cpu.sreg &= ~(1 << 7)

#define cpu_get_V() ((cpu.sreg >> 6) & 1)

#define cpu_set_V() cpu.sreg |= (1 << 6)

#define cpu_clr_V() cpu.sreg &= ~(1 << 6)

#define cpu_get_B() ((cpu.sreg >> 4) & 1)

#define cpu_set_B() cpu.sreg |= (1 << 4)

#define cpu_clr_B() cpu.sreg &= ~(1 << 4)

#define cpu_get_D() ((cpu.sreg >> 3) & 1)

#define cpu_set_D() cpu.sreg |= (1 << 3)

#define cpu_clr_D() cpu.sreg &= ~(1 << 3)

#define cpu_get_I() ((cpu.sreg >> 2) & 1)

#define cpu_set_I() cpu.sreg |= (1 << 2)

#define cpu_clr_I() cpu.sreg &= ~(1 << 2)

#define cpu_get_Z() ((cpu.sreg >> 1) & 1)

#define cpu_set_Z() cpu.sreg |= (1 << 1)

#define cpu_clr_Z() cpu.sreg &= ~(1 << 1)

#define cpu_get_C() ((cpu.sreg >> 0) & 1)

#define cpu_set_C() cpu.sreg |= (1 << 0)

#define cpu_clr_C() cpu.sreg &= ~(1 << 0)

#define cpu_get_op() cpu.read(cpu.pc + 1)

#define cpu_get_op16() (((uint16_t)(cpu.read(cpu.pc + 1))) | ((uint16_t)(cpu.read(cpu.pc + 2) << 8)))

#define log_ops

#ifdef log_ops

#define log_op(op) printf("%04x: %02x	%s\n", cpu.pc, cpu.read(cpu.pc), op);

#define log_im(opcode, argument) printf("%04x: %02x %02x %02x	%s #$%02X\n", cpu.pc, cpu.read(cpu.pc), cpu.read(cpu.pc + 1), cpu.read(cpu.pc + 2), opcode, argument);

#define log_zp(opcode, argument) printf("%04x: %02x %02x %02x	%s $%02X\n", cpu.pc, cpu.read(cpu.pc), cpu.read(cpu.pc + 1), cpu.read(cpu.pc + 2), opcode, argument);

#define log_zx(opcode, argument) printf("%04x: %02x %02x %02x	%s $%02X,X\n", cpu.pc, cpu.read(cpu.pc), cpu.read(cpu.pc + 1), cpu.read(cpu.pc + 2), opcode, argument);

#define log_zy(opcode, argument) printf("%04x: %02x %02x %02x	%s $%02X,Y\n", cpu.pc, cpu.read(cpu.pc), cpu.read(cpu.pc + 1), cpu.read(cpu.pc + 2), opcode, argument);

#define log_ab(opcode, argument) printf("%04x: %02x %02x %02x	%s $%04X\n", cpu.pc, cpu.read(cpu.pc), cpu.read(cpu.pc + 1), cpu.read(cpu.pc + 2), opcode, argument);

#define log_ax(opcode, argument) printf("%04x: %02x %02x %02x	%s $%04X,X\n", cpu.pc, cpu.read(cpu.pc), cpu.read(cpu.pc + 1), cpu.read(cpu.pc + 2), opcode, argument);

#define log_ay(opcode, argument) printf("%04x: %02x %02x %02x	%s $%04X,Y\n", cpu.pc, cpu.read(cpu.pc), cpu.read(cpu.pc + 1), cpu.read(cpu.pc + 2), opcode, argument);

#define log_in(opcode, argument) printf("%04x: %02x %02x %02x	%s ($%02X)\n", cpu.pc, cpu.read(cpu.pc), cpu.read(cpu.pc + 1), cpu.read(cpu.pc + 2), opcode, argument);

#define log_ix(opcode, argument) printf("%04x: %02x %02x %02x	%s ($%02X,X)\n", cpu.pc, cpu.read(cpu.pc), cpu.read(cpu.pc + 1), cpu.read(cpu.pc + 2), opcode, argument);

#define log_iy(opcode, argument) printf("%04x: %02x %02x %02x	%s ($%02X),Y\n", cpu.pc, cpu.read(cpu.pc), cpu.read(cpu.pc + 1), cpu.read(cpu.pc + 2), opcode, argument);

#define log_rl(opcode, argument) printf("%04x: %02x %02x %02x	%s $.%+i\n", cpu.pc, cpu.read(cpu.pc), cpu.read(cpu.pc + 1), cpu.read(cpu.pc + 2), opcode, argument);

#else

#define log_op(op)

#define log_rl(opcode, argument)

#define log_im(opcode, argument)

#define log_zp(opcode, argument)

#define log_zx(opcode, argument)

#define log_zy(opcode, argument)

#define log_ab(opcode, argument)

#define log_ax(opcode, argument)

#define log_ay(opcode, argument)

#define log_in(opcode, argument)

#define log_ix(opcode, argument)

#define log_iy(opcode, argument)

#endif

#define lo(x)								(uint8_t)(x)

#define hi(x)								(uint8_t)(x >> 8)

#define little16(x) (((uint16_t)(x >> 8)) | ((uint16_t)(x << 8)))

struct _cpu {
	
	uint8_t a; /* The Accumulator Register */
	
	uint8_t x; /* The X Index Register */
	
	uint8_t y; /* The Y Index Register */
	
	uint8_t sreg; /* The Status Register (NV-BDICZ) */
	
	uint8_t sp; /* The Stack Pointer */
	
	uint16_t pc; /* The Program Counter */
		
	uint8_t stack[0x100];
	
	void (* step)(void);
	
	uint8_t (* read)(uint16_t address);
	
	void (* write)(uint16_t address, uint8_t value);
	
} cpu;

uint8_t _nes_cpu_read(uint16_t address);

void _nes_cpu_write(uint16_t address, uint8_t value);

uint8_t (* nes_cpu_read[0x20])(uint16_t address);

void (* nes_cpu_write[0x20])(uint16_t address, uint8_t value);

void (* nes_cpu_exec[0x100])(void);

void nes_cpu_step(void);

void cpu_restore_PC(void);

void cpu_save_PC(void);

void cpu_generate_NMI(void);

void cpu_check_N(int8_t result);

void cpu_check_V(uint8_t result);

void cpu_check_Z(uint8_t result);

void cpu_check_C(uint8_t result);

/* ~ 6502 Opcodes ~ */

/*

	~ Abbreviations ~
 
	ac: accumulator

	im: immediate

	zp: zero page

	zx: zero page X

	zy: zero page Y

	ab: absolute

	ax: absolute X

	ay: absolute Y

	in: indirect

	ix: indirect X

	iy: indirect y

	rl: relative
 
*/

/* ADC (ADD MEMORY TO ACCUMULATOR WITH CARRY) */

void nes_cpu_adc_im(void);

void nes_cpu_adc_zp(void);

void nes_cpu_adc_zx(void);

void nes_cpu_adc_ab(void);

void nes_cpu_adc_ax(void);

void nes_cpu_adc_ay(void);

void nes_cpu_adc_ix(void);

void nes_cpu_adc_iy(void);

/* AND (AND MEMORY WITH ACCUMULATOR) */

void nes_cpu_and_im(void);

void nes_cpu_and_zp(void);

void nes_cpu_and_zx(void);

void nes_cpu_and_ab(void);

void nes_cpu_and_ax(void);

void nes_cpu_and_ay(void);

void nes_cpu_and_ix(void);

void nes_cpu_and_iy(void);

/* ASL (SHIFT LEFT ONE BIT: MEMORY OR ACCUMULATOR) */

void nes_cpu_asl_ac(void);

void nes_cpu_asl_zp(void);

void nes_cpu_asl_zx(void);

void nes_cpu_asl_ab(void);

void nes_cpu_asl_ax(void);

/* BCC (BRANCH ON CARRY CLEAR) */

void nes_cpu_bcc(void);

/* BCS (BRANCH ON CARRY SET) */

void nes_cpu_bcs(void);

/* BEQ (BRANCH ON RESULT ZERO) */

void nes_cpu_beq(void);

/* BIT (TEST BITS IN MEMORY WITH ACCUMULATOR) */

void nes_cpu_bit_zp(void);

void nes_cpu_bit_ab(void);

/* BMI (BRANCH ON RESULT MINUS) */

void nes_cpu_bmi(void);

/* BNE (BRANCH ON RESULT NOT ZERO) */

void nes_cpu_bne(void);

/* BPL (BRANCH ON RESULT PLUS) */

void nes_cpu_bpl(void);

/* BRK (FORCE BREAK) */

void nes_cpu_brk(void);

/* BVC (BRANCH ON OVERFLOW CLEAR) */

void nes_cpu_bvc(void);

/* BVS (BRANCH ON OVERFLOW SET) */

void nes_cpu_bvs(void);

/* CLC (CLEAR CARRY FLAG) */

void nes_cpu_clc(void);

/* CLD (CLEAR DECIMAL MODE) */

void nes_cpu_cld(void);

/* CLI (CLEAR INTERRUPT DISABLE BIT) */

void nes_cpu_cli(void);

/* CLV (CLEAR OVERFLOW FLAG) */

void nes_cpu_clv(void);

/* CMP (COMPARE MEMORY WITH ACCUMULATOR) */

void nes_cpu_cmp_im(void);

void nes_cpu_cmp_zp(void);

void nes_cpu_cmp_zx(void);

void nes_cpu_cmp_ab(void);

void nes_cpu_cmp_ax(void);

void nes_cpu_cmp_ay(void);

void nes_cpu_cmp_ix(void);

void nes_cpu_cmp_iy(void);

/* CPX (COMPARE MEMORY WITH INDEX X) */

void nes_cpu_cpx_im(void);

void nes_cpu_cpx_zp(void);

void nes_cpu_cpx_ab(void);

/* CPY (COMPARE MEMORY WITH INDEX Y) */

void nes_cpu_cpy_im(void);

void nes_cpu_cpy_zp(void);

void nes_cpu_cpy_ab(void);

/* DEC (DECREMENT MEMORY BY ONE) */

void nes_cpu_dec_zp(void);

void nes_cpu_dec_zx(void);

void nes_cpu_dec_ab(void);

void nes_cpu_dec_ax(void);

/* DEX (DECREMENT INDEX X BY ONE) */

void nes_cpu_dex(void);

/* DEY (DECREMENT INDEX Y BY ONE) */

void nes_cpu_dey(void);

/* EOR (EXCLUSIVE OR MEMORY WITH ACCUMULATOR) */

void nes_cpu_eor_im(void);

void nes_cpu_eor_zp(void);

void nes_cpu_eor_zx(void);

void nes_cpu_eor_ab(void);

void nes_cpu_eor_ax(void);

void nes_cpu_eor_ay(void);

void nes_cpu_eor_ix(void);

void nes_cpu_eor_iy(void);

/* INC (INCREMENT MEMORY BY ONE) */

void nes_cpu_inc_zp(void);

void nes_cpu_inc_zx(void);

void nes_cpu_inc_ab(void);

void nes_cpu_inc_ax(void);

/* INX (INCREMENT X INDEX BY ONE) */

void nes_cpu_inx(void);

/* INY (INCREMENT Y INDEX BY ONE) */

void nes_cpu_iny(void);

/* JMP (JUMP TO NEW LOCATION) */

void nes_cpu_jmp_ab(void);

void nes_cpu_jmp_in(void);

/* JSR (JUMP TO NEW LOCATION AND SAVE RETURN ADDRESS) */

void nes_cpu_jsr_ab(void);

/* LDA (LOAD ACCUMULATOR WITH MEMORY) */

void nes_cpu_lda_im(void);

void nes_cpu_lda_zp(void);

void nes_cpu_lda_zx(void);

void nes_cpu_lda_ab(void);

void nes_cpu_lda_ax(void);

void nes_cpu_lda_ay(void);

void nes_cpu_lda_ix(void);

void nes_cpu_lda_iy(void);

/* LDX (LOAD INDEX X WITH MEMORY) */

void nes_cpu_ldx_im(void);

void nes_cpu_ldx_zp(void);

void nes_cpu_ldx_zy(void);

void nes_cpu_ldx_ab(void);

void nes_cpu_ldx_ay(void);

/* LDY (LOAD INDEX Y WITH MEMORY) */

void nes_cpu_ldy_im(void);

void nes_cpu_ldy_zp(void);

void nes_cpu_ldy_zx(void);

void nes_cpu_ldy_ab(void);

void nes_cpu_ldy_ax(void);

/* LSR (SHIFT ONE BIT RIGHT) */

void nes_cpu_lsr_ac(void);

void nes_cpu_lsr_zp(void);

void nes_cpu_lsr_zx(void);

void nes_cpu_lsr_ab(void);

void nes_cpu_lsr_ax(void);

/* NOP (NO OPERATION) */

void nes_cpu_nop(void);

/* ORA (OR MEMORY WITH ACCUMULATOR) */

void nes_cpu_ora_im(void);

void nes_cpu_ora_zp(void);

void nes_cpu_ora_zx(void);

void nes_cpu_ora_ab(void);

void nes_cpu_ora_ax(void);

void nes_cpu_ora_ay(void);

void nes_cpu_ora_ix(void);

void nes_cpu_ora_iy(void);

/* PHA (PUSH ACCUMULATOR TO STACK) */

void nes_cpu_pha(void);

/* PHP (PUSH PROCESSOR STATUS TO STACK) */

void nes_cpu_php(void);

/* PLA (PULL ACCUMULATOR FROM STACK) */

void nes_cpu_pla(void);

/* PLP (PULL PROCESSOR STATUS FROM STACK) */

void nes_cpu_plp(void);

/* ROL (ROTATE ONE BIT LEFT) */

void nes_cpu_rol_ac(void);

void nes_cpu_rol_zp(void);

void nes_cpu_rol_zx(void);

void nes_cpu_rol_ab(void);

void nes_cpu_rol_ax(void);

/* ROR (ROTATE ONE BIT RIGHT) */

void nes_cpu_ror_ac(void);

void nes_cpu_ror_zp(void);

void nes_cpu_ror_zx(void);

void nes_cpu_ror_ab(void);

void nes_cpu_ror_ax(void);

/* RTI (RETURN FROM INTERRUPT) */

void nes_cpu_rti(void);

/* RTS (RETURN FROM SUBROUTINE) */

void nes_cpu_rts(void);

/* SBC (SUBTRACT MEMORY FROM ACCUMULATOR WITH BORROW) */

void nes_cpu_sbc_im(void);

void nes_cpu_sbc_zp(void);

void nes_cpu_sbc_zx(void);

void nes_cpu_sbc_ab(void);

void nes_cpu_sbc_ax(void);

void nes_cpu_sbc_ay(void);

void nes_cpu_sbc_ix(void);

void nes_cpu_sbc_iy(void);

/* SEC (SET CARRY FLAG) */

void nes_cpu_sec(void);

/* SED (SET DECIMAL FLAG) */

void nes_cpu_sed(void);

/* SEI (SET INTERRUPT DISABLE) */

void nes_cpu_sei(void);

/* STA (STORE ACCUMULATOR IN MEMORY) */

void nes_cpu_sta_zp(void);

void nes_cpu_sta_zx(void);

void nes_cpu_sta_ab(void);

void nes_cpu_sta_ax(void);

void nes_cpu_sta_ay(void);

void nes_cpu_sta_ix(void);

void nes_cpu_sta_iy(void);

/* STX (STORE INDEX X IN MEMORY) */

void nes_cpu_stx_zp(void);

void nes_cpu_stx_zy(void);

void nes_cpu_stx_ab(void);

/* STY (STORE INDEX Y IN MEMORY) */

void nes_cpu_sty_zp(void);

void nes_cpu_sty_zx(void);

void nes_cpu_sty_ab(void);

/* TAX (TRANSFER ACCUMULATOR TO INDEX X) */

void nes_cpu_tax(void);

/* TAY (TRANSFER ACCUMULATOR TO INDEX Y) */

void nes_cpu_tay(void);

/* TSX (TRANSFER STACK POINTER TO INDEX X) */

void nes_cpu_tsx(void);

/* TXA (TRANSFER INDEX X TO ACCUMULATOR) */

void nes_cpu_txa(void);

/* TXS (TRANSFER INDEX X TO STACK POINTER) */

void nes_cpu_txs(void);

/* TYA (TRANSFER INDEX Y TO ACCUMULATOR) */

void nes_cpu_tya(void);

#endif
