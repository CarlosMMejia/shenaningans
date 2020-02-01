; author: NHI DINH TRAN
; HW: addition, subtraction, multiplication and division


.model small
.386
.stack 100h
.data
msg1 db 0AH, 0DH, 0AH, "Insert first number: ", 0DH, 0AH, "$"
msg2 db 0AH, 0DH, 0AH, "Insert second number: ", 0DH, 0AH, "$"	
msg3 db 0Ah, 0DH, 0AH, "Addition: ", 0dh, 0ah, "$"
msg4 db 0Ah, 0DH, 0AH, "Subtraction: ", 0dh, 0ah, "$"
msg5 db 0Ah, 0DH, 0AH, "Multiplication: ", 0dh, 0ah, "$"
msg6 db 0Ah, 0DH, 0AH, "Quotient of division: ", 0dh, 0ah, "$"
msg7 db 0AH, 0DH, 0AH, "Remainder of divison: ", 0dh, 0ah, "$"
	num1 dw ?		; first number
	num2 dw ?		; second number
	num3 dw 0		; counter
.code
extrn clrscr: proc

main proc

	mov ax,@data
	mov ds, ax
	call clrscr

	loopm:

		mov bx, 10

		mov ah, 9			; print first message
		mov dx, offset msg1
		int 21h
		
		mov ah, 1        		;first digit of first number
        	int 21h  
		mov ah, 0
		sub ax, 48        
        	mul bx
		mov num1, ax
		
		
		mov ah, 1			; second digit of first number
		int 21h
		mov ah, 0
		sub ax, 48
		add num1, ax

		mov ah, 9
        	mov dx, offset msg2  		;displays the string in second_msg
    		int 21h   
	

    	    	mov ah, 1        		;first digit of second number
        	int 21h  
		mov ah, 0
		sub ax, 48        
        	mul bx
		mov num2, ax
		
		
		mov ah, 1			; second digit of second number
		int 21h
		mov ah, 0
		sub ax, 48
		add num2, ax

		mov ah, 9			; print third message
		mov dx, offset msg3
		int 21h
				
  		call add_func

		
		mov ah, 9			; print fourth message
		mov dx, offset msg4
		int 21h
	
		call sub_func

		
		mov ah, 9			; print fifth message
		mov dx, offset msg5
		int 21h

		call mult_func

		
		mov ah, 9			; print sixth message
		mov dx, offset msg6
		int 21h
 
		call div_func


	jmp loopm


; ADDITION
	
	add_func proc
		

		mov ax, num1

		add ax, num2

		call print_it

		ret


	add_func endp

; SUBTRACTING
		
	sub_func proc

		mov ax, num2
		mov dx, num1        
		
		cmp dx, ax

		jl negative
	

	positive:

		mov ax, num1
		
		sub ax, num2

		call print_it

		ret

	negative:

		mov ah, 6
		
		mov dl, 2dh	; '-'

		int 21h		

		
		mov ax, num2    	
	
		sub ax ,num1 

		call print_it
   	 	
		ret	

	sub_func endp


; MULTIPLICATION


	mult_func proc

		mov ax, num1

		mul num2

		call print_it

		ret

	mult_func endp


; DIVISION

	div_func proc

		mov dx, 0
		
		mov ax, num1

		div num2

		mov bx, dx		; store the remainder in cx for later use

		call print_it


		mov dx, offset msg7	; print seventh message
		mov ah, 9
		int 21h

		mov ax, bx

		call print_it

		ret

	div_func endp

	print_it proc

		mov num3, 0
		loop1:
		mov dx, 0
		mov cx, 10
		div cx 
		add dx, 48	
		push dx		; store remainder in the stack 
		inc num3	; keeps track of how many remainders we store in the stack
		cmp ax, 0
		jnz loop1

		loop2:
		pop dx
		mov ah, 6
		int 21h
		dec num3	; decreases count of how many remainders are left in the stack
		cmp num3, 0 	; repeat loop until num2 reaches 0
		jnz loop2

		ret

	print_it endp

main endp
end main