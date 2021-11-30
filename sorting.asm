
section .text

extern memcpy

strlen:
    ; Адрес сообщения уже загружен в rdi
    mov rcx, -1     ; ecx должен быть < 0
    xor al, al      ; конечный симврл = 0
    cld             ; направление обхода от начала к концу
    repne   scasb   ; while(msg[rdi]) != al) {rdi++, rcx--}
    neg rcx
    sub rcx, 2      ; ecx = length(msg)
    mov rax, rcx
    ret

;double CompareValue() {
;    int len = strlen((char*)l);
;    return (double) *(int*)(l + nameSize) / len;
;}
global CompareValue
CompareValue:
    push    rbp
    mov     rbp, rsp
    sub     rsp, 16; двиагаем stack pointer на 16 вниз
    call    strlen
    mov     [rbp - 12], rax; кладем результат int32 
    cvtsi2sd        xmm0, [rdi + 26]
    cvtsi2sd        xmm1, [rbp - 12]
    divsd   xmm0, xmm1
    add     rsp, 16
    pop     rbp
    ret

global ShellSort
ShellSort:                              ; @ShellSort
        push    rbp
        mov     rbp, rsp
        sub     rsp, 64
        mov     [rbp - 8], rdi
        mov     [rbp - 12], esi
        mov     eax, [rbp - 12]
        mov     ecx, 2
        cdq
        idiv    ecx
        mov     [rbp - 16], eax
.LBB1_1:                                ; =>This Loop Header: Depth=1
        cmp     dword [rbp - 16], 0
        jle     .LBB1_14
        mov     eax, [rbp - 16]
        mov     [rbp - 20], eax
.LBB1_3:                                ;   Parent Loop BB1_1 Depth=1
        mov     eax, [rbp - 20]
        cmp     eax, [rbp - 12]
        jge     .LBB1_12
        mov     eax, [rbp - 20]
        mov     [rbp - 24], eax
.LBB1_5:                                ;   Parent Loop BB1_1 Depth=1
        mov     ecx, [rbp - 24]
        xor     eax, eax
        cmp     ecx, [rbp - 16]
        mov     [rbp - 33], al         ; 1-byte Spill
        jl      .LBB1_7
        mov     rdi, [rbp - 8]
        imul    eax, [rbp - 24], 50
        cdqe
        add     rdi, rax
        add     rdi, 4
        call    CompareValue
        movsd   [rbp - 48], xmm0      ; 8-byte Spill
        mov     rdi, [rbp - 8]
        mov     eax, [rbp - 24]
        sub     eax, [rbp - 16]
        imul    eax, eax, 50
        cdqe
        add     rdi, rax
        add     rdi, 4
        call    CompareValue
        movsd   xmm1, [rbp - 48]      ; 8-byte Reload
        ucomisd xmm0, xmm1
        seta    al
        mov     [rbp - 33], al         ; 1-byte Spill
.LBB1_7:                                ;   in Loop: Header=BB1_5 Depth=3
        mov     al, [rbp - 33]         ; 1-byte Reload
        test    al, 1
        jne     .LBB1_8
        jmp     .LBB1_10
.LBB1_8:                                ;   in Loop: Header=BB1_5 Depth=3
        mov     rax, rsp
        mov     [rbp - 32], rax
        mov     rdi, rsp
        add     rdi, -400
        mov     [rbp - 56], rdi       ; 8-byte Spill
        mov     rsp, rdi
        mov     rsi, [rbp - 8]
        imul    eax, [rbp - 24], 50
        cdqe
        add     rsi, rax
        mov     edx, 50
        call    memcpy
        mov     rdi, [rbp - 8]
        imul    eax, [rbp - 24], 50
        cdqe
        add     rdi, rax
        mov     rsi, [rbp - 8]
        mov     eax, [rbp - 24]
        sub     eax, [rbp - 16]
        imul    eax, eax, 50
        cdqe
        add     rsi, rax
        mov     edx, 50
        call    memcpy
        mov     rsi, [rbp - 56]       ; 8-byte Reload
        mov     rdi, [rbp - 8]
        mov     eax, [rbp - 24]
        sub     eax, [rbp - 16]
        imul    eax, eax, 50
        cdqe
        add     rdi, rax
        mov     edx, 50
        call    memcpy
        mov     rax, [rbp - 32]
        mov     rsp, rax
        mov     ecx, [rbp - 16]
        mov     eax, [rbp - 24]
        sub     eax, ecx
        mov     [rbp - 24], eax
        jmp     .LBB1_5
.LBB1_10:                               ;   in Loop: Header=BB1_3 Depth=2
        jmp     .LBB1_11
.LBB1_11:                               ;   in Loop: Header=BB1_3 Depth=2
        mov     eax, [rbp - 20]
        add     eax, 1
        mov     [rbp - 20], eax
        jmp     .LBB1_3
.LBB1_12:                               ;   in Loop: Header=BB1_1 Depth=1
        jmp     .LBB1_13
.LBB1_13:                               ;   in Loop: Header=BB1_1 Depth=1
        mov     eax, [rbp - 16]
        mov     ecx, 2
        cdq
        idiv    ecx
        mov     [rbp - 16], eax
        jmp     .LBB1_1
.LBB1_14:
        mov     rsp, rbp
        pop     rbp
        ret