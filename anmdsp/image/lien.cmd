-stack 0x800
-heap  0x800

MEMORY { 
	PPEM	:origin = 0x00000000, len = 0x00010000	
	PMEM	:origin = 0x80000000, len = 0x00002000
	
	DMEM	:origin = 0x80002001, len = 0x00100000
}
SECTIONS
{
	.text	>PPEM
	.bss	>PPEM
	.cinit	>PMEM
	.const	>PPEM
	.cio	>PPEM
	.far	>PPEM
	.data	>PPEM
	.tables	>PPEM
	.stack 	>PMEM
	.sysmem	>PMEM
	.mydata	>DMEM
}