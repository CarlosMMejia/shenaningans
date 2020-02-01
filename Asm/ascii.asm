title  ASCII to binary, octal, decimal and hexadecimal	[Ascii.ASM]
; Author: David Peled / Carlos Mejia
; Date:   11-16-2015
.model small
.stack 100h

.data


msg1 db  0DH,0AH, "Press any key",0DH,0AH,"$"
num  db ?   ; this is a numeric variable
num1 db 8 ; numerical variable with initial condition = 8 (Bit string loop of 8 bits)
num2 db ?
num3 db ?
num4 db ?
num5 db ?
num6 db ?
num7 dw ? ; 16-bit
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
	mov bl , al

	mov num , al ; saving the key pressed to 8-bit variable 'num' (BINARY)

	mov num2 , al ; saving the key pressed to 8-bit variable 'num2' (HEXADECIMAL first digit)
	mov num3 , al ; saving the key pressed to 8-bit variable 'num3' (HEXADECIMAL second digit)

	mov num4 , al ; saving the key pressed to 8-bit variable 'num4' (OCTAL first digit)
	mov num5 , al ; saving the key pressed to 8-bit variable 'num5' (OCTAL second digit)
	mov num6 , al ; saving the key pressed to 8-bit variable 'num6' (OCTAL third digit)

	mov bl, 1 ; bl = 1
	mul bl ; ax = al * bl, ax = al
	mov num7 , ax ; saving the key pressed to 16-bit variable 'num7' (DECIMAL)

mov ah ,6  ; sending ‘ = ‘ sign
mov dl, 3dH
int 21h

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
	int 21h
	
        shr num2 , 1
	shr num2 , 1
	shr num2 , 1
	shr num2 , 1
	call display_hex ; displaying digit # 1
	and num3 , 0FH
        mov bl, num3
        mov num2 , bl
	call display_hex ;displaying digit # 2

jmp octconvert

Octconvert:
	mov ah ,6  ; sending = sign
	mov dl, 3dH
	int 21h
	
	shr num4, 1 ; Only keeps 2 first digits
	shr num4, 1
	shr num4, 1
	shr num4, 1
	shr num4, 1
	shr num4, 1
	call display_oct ; displaying digit #1
	
	shl num5, 1 ;Only keeps 3rd, 4th and 5th digits
	shl num5, 1
	shr num5, 1
	shr num5, 1
	shr num5, 1
	shr num5, 1
	shr num5, 1
	mov cl, num5
	mov num4, cl
	call display_oct ; displaying digit #2
	
	shl num6, 1 ;Only keeps 3 last digits
	shl num6, 1
	shl num6, 1
	shl num6, 1
	shl num6, 1
	shr num6, 1
	shr num6, 1
	shr num6, 1
	shr num6, 1
	shr num6, 1	
	mov dl, num6
	mov num4, dl
	call display_oct ; displaying digit #3

jmp decconvert

decconvert:

	mov ah, 6  ; sending = sign
	mov dl, 3dh
	int 21h

	mov dx, 0
	mov ax, num7
	mov cx, 100
	div cx ; divide dx:ax by cx, quotient > ax, remainder > dx
	mov cx, dx ; store the remainder in cx
	mov dx, ax
	add dx, 48
	mov ah, 6 
	int 21h ; print dl > print hundred place

	mov dx, 0
	mov ax, cx ; store the remainder of the last division in ax
	mov cx, 10
	div cx ; divide dx:ax by cx, quotient > ax, remainder > dx
	mov cx, dx ; store the remainder in cx
	mov dx, ax
	add dx, 48
	mov ah, 6 
	int 21h ; print dl > print ten place

	mov dx, cx ; store the remainder of the last division in dx
	add dx, 48
	mov ah, 6
	int 21h ; print dl > print one place

jmp loopm

keyin proc
	mov ah, 1 ; getting a key from the keyboard 
   	int 21h
	ret
keyin endp

display_0 proc
	mov ah, 6  ; sending a single character to the screen
 	mov dl, 30h 
	int 21h
	ret
display_0 endp

display_1 proc
	mov ah, 6  ; sending a single character to the screen
 	mov dl, 31h 
	int 21h
	ret
display_1 endp

display_hex proc

	mov ah, 6
	mov dl, num2

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

display_oct proc

	mov ah, 6
	mov dl, num4

	cmp dl , 10 ; if num4 > 10
	jns adding7oct ; skips special characters and jumps to A
	add dl, 60O ; make it ascii compatible
	int 21h
	ret
	adding7oct: 
	add dl, 67O ; make it ascii compatible
	int 21h
	ret
display_oct endp

main endp
end  main
