; author: NHI DINH TRAN
; HW: addition, subtraction, multiplication and division


.model small
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

.code
extrn clrscr: proc

main proc

	mov ax,@data
	mov ds, ax
	call clrscr

	loopm:
		mov ah, 9			; print first message
		mov dx, offset msg1
		int 21h
		
		mov ah, 1        		;read first number
        	int 21h  
		mov ah, 0           
        	mov num1, ax
		sub num1, 48

		mov ah, 9
        	mov dx, offset msg2  ;displays the string in second_msg
    		int 21h   
	

    	    	mov ah, 1          		 ;read second number
        	int 21h    
		mov ah, 0        
   		mov num2, ax   
		sub num2, 48

		mov ah, 9			; print third message
		mov dx, offset msg3
		int 21h
				
  		call add_func

		
		mov ah, 9			; print forth message
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

		mov bx, ax

		call dec_convert

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
		
		mov bx, ax

		call dec_convert

		ret

	negative:

		mov ah, 6
		
		mov dl, 2dh	; '-'

		int 21h		

		
		mov ax, num2    	
	
		sub ax ,num1 

	
		mov bx, ax

		call dec_convert
   	 	
		ret	

	sub_func endp


; MULTIPLICATION


	mult_func proc

		mov ax, num1

		mov bx, num2

		mul bx

		mov bx, ax

		call dec_convert

		ret

	mult_func endp


; DIVISION

	div_func proc

		mov dx, 0
		
		mov ax, num1

		div num2

		
					; the quotient will be in ax

					; remainder will be in dx

		mov cx, dx		; store the remainder in cx for later use

		mov dx, ax

		add dx, 48	
		
		mov ah, 6

		int 21h 

		mov dx, offset msg7	; print seventh message
		mov ah, 9
		int 21h

		mov dx, cx

		add dx, 48

		mov ah, 6

		int 21h

		ret

	div_func endp


	dec_convert proc
	
		mov dx, 0
		mov ax, bx
		mov cx, 10
		div cx
		mov cx, dx
		mov dx, ax
		add dx, 48
		mov ah, 6 
		int 21h ; prints first digit

		mov dx, cx 
		add dx, 48
		mov ah, 6
		int 21h ; prints second digit

		ret

	dec_convert endp

main endp
end main