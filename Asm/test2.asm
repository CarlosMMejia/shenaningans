
; Author: Carlos Mejia
; Date:   11/23/2015
.model small
.stack 100h
.data

buff	db  10        ;Max string lenght
	db  ?         ;Lenght of string input by user
	db  10 dup(0) ;String input by user

msg1 db  0AH,0DH,0AH, "Input a string:",0DH,0AH,"$"

msg2 db  0DH,0AH, "Reverse:",0DH,0AH,"$"

msg3 db  0DH,0AH, "Original Input:",0DH,0AH,"$"

.code
main:
	
mov ax, @data
mov ds, ax
	
loopm:

mov   ah,9		;Print "Input a string:"
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


mov   ah,9           	;Print "Reverse:"
mov   dx,offset msg2
int   21h  

call Reverse_it		;Print original string backwards

mov   ah,9           	;Print "Original Input:"
mov   dx,offset msg3
int   21h  

call Reverse_it		;Print original string

jmp loopm



Reverse_it proc

mov si, offset buff + 2	;si = lenght of our string (including '$')
mov bx, si

loop1:			;bx "scans" the string character by character
	add bx, 1	;until it points to '$'
	mov dx, [bx]	
	cmp dx, 36
	jne loop1
	sub bx, 1

loop2:
	mov cl, [si]	;first character switches places with last character
	mov ch, [bx]	;second character switches places with second to last character
	mov [si], ch	;and so on, until all the characters have been switched (reversed)
	mov [bx], cl
	add si, 1
	sub bx, 1
	cmp si, bx
	jl loop2

mov ah, 9
mov dx, offset buff+2	;prints the string (offset buff+2 to include '$'
int 21h

ret
Reverse_it endp

mov ah, 4ch
int 21h
end main