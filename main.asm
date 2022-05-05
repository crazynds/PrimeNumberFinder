[bits 64]

%define PARAM1  rcx
%define PARAM2  rdx
%define PARAM3  r8
%define PARAM4  r9


section .text

global sumVectorU64

testeNasm:
	mov rax,PARAM1
	mov rbx,PARAM2
	mov rcx,PARAM3
	mov rdx,PARAM4
    add rax,rbx
    add rax,rcx
    add rax,rdx
	ret

sumVectorU64:
    ; Primeiro parametro é o primeiro vetor e onde os dados serao armazenados
    ; Segundo parametro é o segundo vetor
    VMOVDQA YMM1,[PARAM1] 
    VMOVDQA YMM2,[PARAM2] 
    VPADDW YMM1,YMM1,YMM2
    VMOVDQA [PARAM1],YMM1
    ret



section .data




