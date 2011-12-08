	.file	"tmp/middle.bc"
	.text
	.globl	writeln
	.align	16, 0x90
	.type	writeln,@function
writeln:                                # @writeln
.Leh_func_begin1:
# BB#0:                                 # %entry
	subl	$4, %esp
.Llabel1:
	movl	8(%esp), %eax
	movl	%eax, (%esp)
	call	printf
	movl	$__unnamed_1, (%esp)
	call	printf
	addl	$4, %esp
	ret
	.size	writeln, .-writeln
.Leh_func_end1:

	.globl	write
	.align	16, 0x90
	.type	write,@function
write:                                  # @write
.Leh_func_begin2:
# BB#0:                                 # %entry
	subl	$4, %esp
.Llabel2:
	movl	8(%esp), %eax
	movl	%eax, (%esp)
	call	printf
	addl	$4, %esp
	ret
	.size	write, .-write
.Leh_func_end2:

	.globl	writeint
	.align	16, 0x90
	.type	writeint,@function
writeint:                               # @writeint
.Leh_func_begin3:
# BB#0:                                 # %bb
	subl	$12, %esp
.Llabel3:
	movl	16(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$__unnamed_2, (%esp)
	call	printf
	addl	$12, %esp
	ret
	.size	writeint, .-writeint
.Leh_func_end3:

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
.Leh_func_begin4:
# BB#0:                                 # %entry
	subl	$4, %esp
.Llabel4:
	movl	$5, (%esp)
	call	simple
	xorl	%eax, %eax
	addl	$4, %esp
	ret
	.size	main, .-main
.Leh_func_end4:

	.globl	simple
	.align	16, 0x90
	.type	simple,@function
simple:                                 # @simple
.Leh_func_begin5:
# BB#0:                                 # %entry
	subl	$12, %esp
.Llabel5:
	movl	$0, 8(%esp)
	movl	$0, 4(%esp)
	movl	$13, 4(%esp)
	movl	$__unnamed_3, (%esp)
	call	write
	movl	4(%esp), %eax
	movl	%eax, (%esp)
	call	writeint
	movl	$__unnamed_4, (%esp)
	call	write
	movl	8(%esp), %eax
	addl	$12, %esp
	ret
	.size	simple, .-simple
.Leh_func_end5:

	.type	__unnamed_1,@object
	.data
	.globl	__unnamed_1
__unnamed_1:                            # @0
	.asciz	 "\n"
	.size	__unnamed_1, 2

	.type	__unnamed_2,@object
	.globl	__unnamed_2
__unnamed_2:                            # @1
	.asciz	 "%d"
	.size	__unnamed_2, 3

	.type	__unnamed_3,@object
	.globl	__unnamed_3
__unnamed_3:                            # @2
	.asciz	 "result: "
	.size	__unnamed_3, 9

	.type	__unnamed_4,@object
	.globl	__unnamed_4
__unnamed_4:                            # @3
	.asciz	 "\n"
	.size	__unnamed_4, 2

	.section	.eh_frame,"aw",@progbits
.LEH_frame0:
.Lsection_eh_frame:
.Leh_frame_common:
	.set	.Lset1eh,.Leh_frame_common_end-.Leh_frame_common_begin
	.long	.Lset1eh                # Length of Common Information Entry
.Leh_frame_common_begin:
	.long	0                       # CIE Identifier Tag
	.byte	1                       # DW_CIE_VERSION
	.byte	0
                                        # CIE Augmentation
	.uleb128	1               # CIE Code Alignment Factor
	.sleb128	-4              # CIE Data Alignment Factor
	.byte	8
                                        # CIE Return Address Column
	.byte	12                      # CFA_def_cfa
	.uleb128	4               # Register
	.uleb128	4               # Offset
	.byte	136                     # DW_CFA_offset + Reg (8)
	.uleb128	1               # Offset
	.align	4
.Leh_frame_common_end:

.Lwriteln.eh:
	.set	.Lset2eh,.Leh_frame_end1-.Leh_frame_begin1
	.long	.Lset2eh                # Length of Frame Information Entry
.Leh_frame_begin1:
	.long	.Leh_frame_begin1-.Leh_frame_common # FDE CIE offset
	.long	.Leh_func_begin1        # FDE initial location
	.set	.Lset3eh,.Leh_func_end1-.Leh_func_begin1
	.long	.Lset3eh                # FDE address range
	.uleb128	0               # Augmentation size
	.byte	4                       # CFA_advance_loc4
	.set	.Lset4eh,.Llabel1-.Leh_func_begin1
	.long	.Lset4eh
	.byte	14                      # CFA_def_cfa_offset
	.uleb128	8               # Offset
	.align	4
.Leh_frame_end1:

.Lwrite.eh:
	.set	.Lset5eh,.Leh_frame_end2-.Leh_frame_begin2
	.long	.Lset5eh                # Length of Frame Information Entry
.Leh_frame_begin2:
	.long	.Leh_frame_begin2-.Leh_frame_common # FDE CIE offset
	.long	.Leh_func_begin2        # FDE initial location
	.set	.Lset6eh,.Leh_func_end2-.Leh_func_begin2
	.long	.Lset6eh                # FDE address range
	.uleb128	0               # Augmentation size
	.byte	4                       # CFA_advance_loc4
	.set	.Lset7eh,.Llabel2-.Leh_func_begin2
	.long	.Lset7eh
	.byte	14                      # CFA_def_cfa_offset
	.uleb128	8               # Offset
	.align	4
.Leh_frame_end2:

.Lwriteint.eh:
	.set	.Lset8eh,.Leh_frame_end3-.Leh_frame_begin3
	.long	.Lset8eh                # Length of Frame Information Entry
.Leh_frame_begin3:
	.long	.Leh_frame_begin3-.Leh_frame_common # FDE CIE offset
	.long	.Leh_func_begin3        # FDE initial location
	.set	.Lset9eh,.Leh_func_end3-.Leh_func_begin3
	.long	.Lset9eh                # FDE address range
	.uleb128	0               # Augmentation size
	.byte	4                       # CFA_advance_loc4
	.set	.Lset10eh,.Llabel3-.Leh_func_begin3
	.long	.Lset10eh
	.byte	14                      # CFA_def_cfa_offset
	.uleb128	16              # Offset
	.align	4
.Leh_frame_end3:

.Lmain.eh:
	.set	.Lset11eh,.Leh_frame_end4-.Leh_frame_begin4
	.long	.Lset11eh               # Length of Frame Information Entry
.Leh_frame_begin4:
	.long	.Leh_frame_begin4-.Leh_frame_common # FDE CIE offset
	.long	.Leh_func_begin4        # FDE initial location
	.set	.Lset12eh,.Leh_func_end4-.Leh_func_begin4
	.long	.Lset12eh               # FDE address range
	.uleb128	0               # Augmentation size
	.byte	4                       # CFA_advance_loc4
	.set	.Lset13eh,.Llabel4-.Leh_func_begin4
	.long	.Lset13eh
	.byte	14                      # CFA_def_cfa_offset
	.uleb128	8               # Offset
	.align	4
.Leh_frame_end4:

.Lsimple.eh:
	.set	.Lset14eh,.Leh_frame_end5-.Leh_frame_begin5
	.long	.Lset14eh               # Length of Frame Information Entry
.Leh_frame_begin5:
	.long	.Leh_frame_begin5-.Leh_frame_common # FDE CIE offset
	.long	.Leh_func_begin5        # FDE initial location
	.set	.Lset15eh,.Leh_func_end5-.Leh_func_begin5
	.long	.Lset15eh               # FDE address range
	.uleb128	0               # Augmentation size
	.byte	4                       # CFA_advance_loc4
	.set	.Lset16eh,.Llabel5-.Leh_func_begin5
	.long	.Lset16eh
	.byte	14                      # CFA_def_cfa_offset
	.uleb128	16              # Offset
	.align	4
.Leh_frame_end5:


	.section	.note.GNU-stack,"",@progbits
