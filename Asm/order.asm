
; Author: Carlos Mejia
; Date:   12/2/2015
.model small
.386
.stack 100h
.data

buff	db  21		;Max string lenght
	db  ?		;Lenght of string input by user
	db  21 dup(0)	;String input by user

msg1 db  0AH,0DH,0AH, "Input a string (Max 20 characters):",0DH,0AH,"$"

msg2 db  0DH,0AH, "Ascending Order:",0DH,0AH,"$"

msg3 db  0DH,0AH, "Descending Order:",0DH,0AH,"$"

num db 0

num2 db 0

num3 db 0

.code
extrn clrscr:proc

main:
	
mov ax, @data
mov ds, ax



mov   ah,9		;Print "Input a string (Max 20 characters):"
mov   dx,offset msg1
int   21h    


mov ah, 0Ah 		;Input string from keyboard
mov dx, offset buff
int 21h                 

mov si, offset buff + 1 ;si = lenght of our string (excluding enter)
mov cl, [ si ] 	;cl = last character (before enter)
mov ch, 0       
inc cx 		;cx now points to enter
add si, cx	;si now points to enter
mov al, '$'	
mov [ si ], al 	;replace enter by '$'

	;Counts how many characters are in the string (length) and store it into num

	mov si, offset buff + 2	

	mov bx, si
	mov cl, [si]

	mov num, 0

	counting:

	add bx, 1
	mov dx, [bx]
	inc num
	cmp dx, 36
	jne counting

mov   ah,9           	;Print "Ascending Order:"
mov   dx,offset msg2
int   21h  

call Ascending		;Print original string in ascending order

mov   ax,4C00h		;return to DOS
int   21h  


Ascending proc

mov num2, 0
mov num3, 0
mov si, offset buff + 2	

loop1:

mov bx, si
mov cl, [si]

	loop2:

	mov ch, [bx]
	cmp cl, ch
	jg skip

		cmp num3, ch
		jne skip2
			mov ah, [si]
			cmp num3, ah
			jz skip2

				mov ch, 0
				mov [bx], ch
				mov num3, 0

		skip2:

		cmp cl, ch
		jg skip

			mov cl, ch
	
	skip:

	add bx, 1
	mov dx, [bx]
	cmp dx, 36
	jne loop2

mov num3, cl

mov ch, [si]
cmp cl, ch
jne skip3

mov ch, 1
mov [si], ch
mov num3, 1
skip3:

mov ch, 0
push cx
inc num2

dec num
cmp num, 0
jne loop1

loop3:

pop dx

mov ah, 6
int 21h

dec num2
cmp num2, 0
jnz loop3

ret

Ascending endp

mov ah, 4ch
int 21h

end main