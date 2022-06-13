.data
    message: db "Hello World!", 0xA
    message_length equ $-message

.code
    mov rdx, message_length
    mov rcx, message
    mov rbx, 1
    mov rax, 4
    int 80

    mov rax, 1
    mov rbx, 0
    int 80