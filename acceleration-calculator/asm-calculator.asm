section .data
velocity_factor dd 0.2777777778 ; conversion factor from KM/H to M/S

section .text
bits 64
default rel

global calculate
calculate:
	; parameter 1: xmm0 = initial velocity in KM/H (v0)
	; parameter 2: xmm1 = final velocity in KM/H (v)
	; parameter 3: xmm2 = time in seconds (t)


	; convert velocity from KM/H to M/S
	mulss xmm0, [velocity_factor]
	mulss xmm1, [velocity_factor]

	; calculate acceleration (a = (v - v0) / t)
	subss xmm1, xmm0
	divss xmm1, xmm2
	
	; convert acceleration to int (truncate)
	cvttss2si rax, xmm1

	ret
