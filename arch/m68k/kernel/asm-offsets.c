
#define ASM_OFFSETS_C

#include <linux/stddef.h>
#include <linux/sched.h>
#include <linux/kernel_stat.h>
#include <linux/kbuild.h>
#include <asm/bootinfo.h>
#include <asm/irq.h>
#include <asm/amigahw.h>
#include <linux/font.h>

int main(void)
{
	
	DEFINE(TASK_THREAD, offsetof(struct task_struct, thread));
	DEFINE(TASK_MM, offsetof(struct task_struct, mm));
	DEFINE(TASK_STACK, offsetof(struct task_struct, stack));

	
	DEFINE(THREAD_KSP, offsetof(struct thread_struct, ksp));
	DEFINE(THREAD_USP, offsetof(struct thread_struct, usp));
	DEFINE(THREAD_SR, offsetof(struct thread_struct, sr));
	DEFINE(THREAD_FS, offsetof(struct thread_struct, fs));
	DEFINE(THREAD_CRP, offsetof(struct thread_struct, crp));
	DEFINE(THREAD_ESP0, offsetof(struct thread_struct, esp0));
	DEFINE(THREAD_FPREG, offsetof(struct thread_struct, fp));
	DEFINE(THREAD_FPCNTL, offsetof(struct thread_struct, fpcntl));
	DEFINE(THREAD_FPSTATE, offsetof(struct thread_struct, fpstate));

	
	DEFINE(TINFO_PREEMPT, offsetof(struct thread_info, preempt_count));
	DEFINE(TINFO_FLAGS, offsetof(struct thread_info, flags));

	
	DEFINE(PT_OFF_D0, offsetof(struct pt_regs, d0));
	DEFINE(PT_OFF_ORIG_D0, offsetof(struct pt_regs, orig_d0));
	DEFINE(PT_OFF_D1, offsetof(struct pt_regs, d1));
	DEFINE(PT_OFF_D2, offsetof(struct pt_regs, d2));
	DEFINE(PT_OFF_D3, offsetof(struct pt_regs, d3));
	DEFINE(PT_OFF_D4, offsetof(struct pt_regs, d4));
	DEFINE(PT_OFF_D5, offsetof(struct pt_regs, d5));
	DEFINE(PT_OFF_A0, offsetof(struct pt_regs, a0));
	DEFINE(PT_OFF_A1, offsetof(struct pt_regs, a1));
	DEFINE(PT_OFF_A2, offsetof(struct pt_regs, a2));
	DEFINE(PT_OFF_PC, offsetof(struct pt_regs, pc));
	DEFINE(PT_OFF_SR, offsetof(struct pt_regs, sr));

	
#ifdef CONFIG_COLDFIRE
	DEFINE(PT_OFF_FORMATVEC, offsetof(struct pt_regs, sr) - 2);
#else
	DEFINE(PT_OFF_FORMATVEC, offsetof(struct pt_regs, pc) + 4);
#endif

	
	DEFINE(CPUSTAT_SOFTIRQ_PENDING, offsetof(irq_cpustat_t, __softirq_pending));

	
	DEFINE(LSIGSEGV, SIGSEGV);
	DEFINE(LSEGV_MAPERR, SEGV_MAPERR);
	DEFINE(LSIGTRAP, SIGTRAP);
	DEFINE(LTRAP_TRACE, TRAP_TRACE);

#ifdef CONFIG_MMU
	
	DEFINE(BIR_TAG, offsetof(struct bi_record, tag));
	DEFINE(BIR_SIZE, offsetof(struct bi_record, size));
	DEFINE(BIR_DATA, offsetof(struct bi_record, data));

	
	DEFINE(FONT_DESC_IDX, offsetof(struct font_desc, idx));
	DEFINE(FONT_DESC_NAME, offsetof(struct font_desc, name));
	DEFINE(FONT_DESC_WIDTH, offsetof(struct font_desc, width));
	DEFINE(FONT_DESC_HEIGHT, offsetof(struct font_desc, height));
	DEFINE(FONT_DESC_DATA, offsetof(struct font_desc, data));
	DEFINE(FONT_DESC_PREF, offsetof(struct font_desc, pref));

	
	DEFINE(CUSTOMBASE, &amiga_custom);
	DEFINE(C_INTENAR, offsetof(struct CUSTOM, intenar));
	DEFINE(C_INTREQR, offsetof(struct CUSTOM, intreqr));
	DEFINE(C_INTENA, offsetof(struct CUSTOM, intena));
	DEFINE(C_INTREQ, offsetof(struct CUSTOM, intreq));
	DEFINE(C_SERDATR, offsetof(struct CUSTOM, serdatr));
	DEFINE(C_SERDAT, offsetof(struct CUSTOM, serdat));
	DEFINE(C_SERPER, offsetof(struct CUSTOM, serper));
	DEFINE(CIAABASE, &ciaa);
	DEFINE(CIABBASE, &ciab);
	DEFINE(C_PRA, offsetof(struct CIA, pra));
	DEFINE(ZTWOBASE, zTwoBase);
#endif

	return 0;
}
