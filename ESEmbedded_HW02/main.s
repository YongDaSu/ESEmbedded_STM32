.syntax unified

.word 0x20000100
.word _start

.global _start
.type _start, %function
_start:
	nop

	//
	//branch w/o link
	//
	b	label01

label01:
	movs r0, #0x00000001
	movs r1, #0x00000002
	movs r2, #0x00000003

	push	{r0, r1, r2}
	pop	{r2, r1, r0}

	//change the order of push
	movs r0, #0x00000001
	movs r1, #0x00000002
	movs r2, #0x00000003

	push	{r2, r0, r1}
	pop	{r0, r1, r2}

	//
	//branch w/ link
	//
	bl	sleep

sleep:
	nop
	b	.
