title  ASCII to binary, octal, decimal and hexadecimal	[Ascii.ASM]
; Author: David Peled / Carlos Mejia
; Date:   11-16-2015
.model small
.stack 100h

.data


msg1 db  0DH,0AH, "Press any key",0DH,0AH,"$"
num  db ? ; 8-bit numeric variable
num1 db 8 ; 8-bit numeric variable with initial condition = 8 (Bit string loop of 8 bits)
num2 dw ? ; 16-bit numeric variable
num3 dw ?
num4 dw ?
num5 dw ?
num6 dw ?
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
    
      
	call keyin
	mov ah, 0

	mov num , al ; saving the key pressed to 8-bit variable 'num' (BINARY)

	mov num2 , ax ; saving the key pressed to 16-bit variable 'num2' (HEXADECIMAL)

	mov num4 , ax ; saving the key pressed to 16-bit variable 'num4' (OCTAL)

	mov num6 , ax ; saving the key pressed to 16-bit variable 'num7' (DECIMAL)

mov ah ,6
mov dl, 3dH
int 21h ; prints 3dH ('=')

; Bin convert
mov num1, 8

loop1:
       
	SHL num , 1 ; (Registers each digit on flag as it moves outside the binary string, then prints it)
	jnc disp0
	call display_1
	DEC num1
	JNZ loop1

jmp hexconvert

 disp0: 
	call display_0       
	DEC num1
	JNZ loop1

jmp hexconvert


Hexconvert:
	mov ah ,6  ; sending = sign
	mov dl, 3dH
	int 21h ; prints 3dH ('=')
	
	mov dx, 0
	mov ax, num2
	mov cx, 16
	div cx
	mov num3, dx ; save first remainder in num3

	mov num2, ax ; print second remainder
	call display_hex

	mov dx, num3 ; print first remainder
	mov num2, dx
	call display_hex
jmp octconvert

Octconvert:
	mov ah ,6
	mov dl, 3dH
	int 21h ; prints 3dH ('=')

	mov dx, 0
	mov ax, num4
	mov cx, 8
	div cx
	mov num4, dx ; store first remainder in num4
	mov dx, 0
	div cx
	mov num5, dx ; store second remainder in num5

	mov dx, ax   ; store third remainder in dx
	add dx, 60o
	mov ah, 6
	int 21h	     ; print third remainder

	mov dx, num5 ; store second remainder in dx
	add dx, 60o
	mov ah, 6
	int 21h	     ; print second remainder

	mov dx, num4 ; store first remainder in dx
	add dx, 60o
	mov ah, 6
	int 21h	     ; print first remainder
jmp decconvert

decconvert:
	mov ah, 6
	mov dl, 3dh
	int 21h ; prints 3dH ('=')

	mov dx, 0
	mov ax, num6
	mov cx, 100
	div cx
	mov cx, dx ; store the remainder in cx
	mov dx, ax ; store the quotient in dx
	add dx, 48
	mov ah, 6 
	int 21h ; print first digit

	mov dx, 0
	mov ax, cx ; store the remainder of the last division in ax
	mov cx, 10
	div cx
	mov cx, dx ; store the remainder in cx
	mov dx, ax ; store the quotient in dx
	add dx, 48
	mov ah, 6 
	int 21h ; print second digit

	mov dx, cx ; store the remainder of the last division in dx
	add dx, 48
	mov ah, 6
	int 21h ; print third digit
jmp loopm

keyin proc
	mov ah, 1 ; store keyboard input in al
   	int 21h
	ret
keyin endp

display_0 proc
	mov ah, 6
 	mov dl, 30h ; dl = '0'
	int 21h
	ret
display_0 endp

display_1 proc
	mov ah, 6
 	mov dl, 31h ; dl = '1'
	int 21h
	ret
display_1 endp

display_hex proc
	mov ah, 6
	mov dx, num2

	cmp dl , 10 ; if number > 10
	jns adding7 ; skips special characters and jumps to A
	add dl, 30h ; make it ascii compatible
	int 21h
	ret
	adding7: 
	add dl, 37h ; make it ascii compatible
	int 21h
	ret
display_hex endp

main endp
end  main
