.model small
.386
.stack 100h

.data
msg db 0DH,0AH, "Input n: ","$"
msg1 db 0DH,0AH, "Fib(n): ","$"
msg2 db " ", "$"
num dw ? 			; number input
num2 dw 0

.code   

main proc
	mov ax, @data
	mov ds, ax
	
	mov ah, 9		; print first message
	mov dx, offset msg
	int 21h
	
	mov ah, 1		; input n
	int 21h
	mov ah, 0
	sub ax, 48
	mov num, ax

	mov ah, 9		; print second message
	mov dx, offset msg1
	int 21h

	mov num2, 0
	
	loop1:

		mov ax, num2	; calls Fibonacci(num2)
		call Fibonacci

		mov dx, ax

		call display

		mov ah, 9	; prints a space
		mov dx, offset msg2
		int 21h
	
		inc num2	; if num2 > num(input), then break loop
		mov dx, num2
		cmp dx, num
	
	jbe loop1

mov ax, 4c00h
int 21h

Fibonacci proc

	cmp ax, 1
	jbe exit

	dec ax
	push ax
	call Fibonacci
	mov bx, ax
	pop ax
	push bx
	dec ax
	call Fibonacci
	pop cx
	add ax, cx

exit:
	ret

Fibonacci endp

display proc
	
	cmp dx, 10	; if dx is 10 or greater, skip 7 characters (to 'A')
	jns two_digits
	
	add dx, 48
	mov ah, 6
	int 21h
	ret

	two_digits:
	
	mov ax, dx	; divide by 10 to print first digit (quotient)
	mov dx, 0
	mov cx, 10
	div cx
	
	mov cx, dx	; store remainder for later
	
	mov dx, ax
	add dx, 48
	mov ah, 6
	int 21h
	
	mov dx, cx	; prints second digit (remainder)
	add dx, 48
	mov ah,6
	int 21h

	ret
		
display endp

main endp
end main