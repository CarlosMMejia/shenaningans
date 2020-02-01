title  ASCII to every base	[bases.ASM]
; Author: Carlos Mejia
; Date:   11-18-2015
.model small
.386
.stack 100h

.data


msg1 db  0DH,0AH, "Press any key",0DH,0AH,"$"

num dw ? ; our input

num1 dw 2 ; initial condition = 2 (Start printing from base 2)

num2 dw 0 ; to count how many remainders we store in the stack

.code
extrn clrscr:proc    


main proc
    mov   ax,@data       ; set up data segment
    mov   ds,ax

    call  clrscr         ; clear the screen
    
   loopm:
	 mov   ah,9           ; send first message
    mov   dx,offset msg1
    int   21h            
    
      
	mov ah, 1 ; getting a key from the keyboard 
   	int 21h

	mov ah, 0

	mov num , ax ; saving the key pressed to 16-bit variable 'num'

mov num1, 2

loop1:
	mov ah ,6
	mov dl, 3dH
	int 21h ; prints 3dH ('=')
	
	mov num2, 0 ; resets number of divisions performed
	mov ax, num ; stores num in ax for division
	
	loop2:
		mov dx, 0
		mov cx, num1
		div cx 		; ax = ax/num1 , dx = remainder
		call ascii	
		push dx		; store remainder in the stack 
		inc num2	; keeps track of how many remainders we store in the stack
		cmp ax, 0
	jnz loop2

	loop3:
		pop dx
		mov ah, 6
		int 21h
		dec num2	; decreases count of how many remainders are left in the stack
		cmp num2, 0 	; repeat loop until num2 reaches 0
	jnz loop3
	
	mov ah, 6
	mov dl, 40 ; prints '('
	int 21h


	mov dx, 0
	mov ax, num1
	mov cx, 10
	div cx
	mov cx, dx
	mov dx, ax
	add dx, 48
	mov ah, 6
	int 21h

	mov dx, cx
	add dx, 48
	mov ah, 6
	int 21h


	mov ah, 6
	mov dl, 41 ; prints ')'
	int 21h

	inc num1
	mov dx, num1
	cmp dx, 65 ; break loop when num1 reaches 65
jnz loop1	
	
jmp loopm

ascii proc
	cmp dx, 36	; if dx is 36 or greater, skip 13 characters (to 'a')
	jns adding13
	
	cmp dx, 10	; if dx is 10 or greater, skip 7 characters (to 'A')
	jns adding7
	add dx, 48 	; ASCII compatible
	ret

	adding7:
		add dx, 55	; ASCII compatible
		ret
	
	adding13:
		add dx, 61	; ASCII compatible
		ret	
ascii endp
main endp
end  main
