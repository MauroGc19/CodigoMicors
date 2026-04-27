.include "m2560def.inc"    
         
.equ KEY_PIN = 1           
.equ PIN_1 = 2
.equ PIN_2 = 3
.equ PIN_3 = 4
.equ PIN_4 = 5

.def temp = r16
.def contador = r17
.def last_state = r18

.cseg
.org 0x0000               
    rjmp start

start:

    ; Configuración puertos
    ldi temp, (1<<PIN_1)|(1<<PIN_2)|(1<<PIN_3)|(1<<PIN_4)
    out DDRB, temp        

    ; Pull-up botón
    ldi temp, (1<<KEY_PIN)
    out PORTB, temp       

    clr contador
    ldi last_state, 1     ; botón no presionado

main_loop:
    in temp, PINB
    andi temp, (1<<KEY_PIN)

    cp temp, last_state
    breq no_change

    mov last_state, temp

    cpi temp, 0
    brne no_change   ; solo actuar cuando se presiona

    ; ---- BOTÓN PRESIONADO ----
    inc contador
    cpi contador, 10
    brlo mostrar
    clr contador     ; volver a 0

mostrar:
    rcall mostrar_numero

no_change:
    rjmp main_loop

mostrar_numero:
    cpi contador, 0
    breq Numero0
    cpi contador, 1
    breq Numero1
    cpi contador, 2
    breq Numero2
    cpi contador, 3
    breq Numero3
    cpi contador, 4
    breq Numero4
    cpi contador, 5
    breq Numero5
    cpi contador, 6
    breq Numero6
    cpi contador, 7
    breq Numero7
    cpi contador, 8
    breq Numero8
    cpi contador, 9
    breq Numero9
    ret

clear_pins:
    in temp, PORTB
    andi temp, ~((1<<PIN_1)|(1<<PIN_2)|(1<<PIN_3)|(1<<PIN_4))
    out PORTB, temp
    ret

Numero0:
    rcall clear_pins
    ret

Numero1:
	rcall clear_pins
	in temp,PORTB
	ori temp, (1 << PIN_4)
	out PORTB, temp
	ret
Numero2:
	rcall clear_pins
	in temp, PORTB
	ori temp, (1 << PIN_3)
	out PORTB, temp ret 
Numero3:
	rcall clear_pins
	in temp, PORTB
	ori temp, (1 << PIN_4)
	out PORTB, temp
	in temp, PORTB
	ori temp, (1 << PIN_3)
	out PORTB, temp 
	ret
Numero4:
	rcall clear_pins
	in temp, PORTB 
	ori temp, (1 << PIN_2)
	out PORTB, temp 
	ret 
Numero5:
	rcall clear_pins
	in temp, PORTB 
	ori temp, (1 << PIN_2) 
	out PORTB, temp 
	in temp, PORTB 
	ori temp, (1 << PIN_4)
	out PORTB, temp 
	ret 
Numero6:
	rcall clear_pins
	in temp, PORTB 
	ori temp, (1 << PIN_2)
	out PORTB, temp 
	in temp, PORTB 
	ori temp, (1 << PIN_3)
	out PORTB, temp 
	ret
Numero7:
	rcall clear_pins
	in temp, PORTB 
	ori temp, (1 << PIN_4)
	out PORTB, temp 
	in temp, PORTB 
	ori temp, (1 << PIN_3)
	out PORTB, temp 
	in temp, PORTB 
	ori temp, (1 << PIN_2)
	out PORTB, temp 
	ret 
Numero8:
	rcall clear_pins
	in temp, PORTB 
	ori temp, (1 << PIN_1)
	out PORTB, temp 
	ret 
Numero9:
	rcall clear_pins
	in temp, PORTB 
	ori temp, (1 << PIN_1)
	out PORTB, temp 
	in temp, PORTB 
	ori temp, (1 << PIN_4)
	out PORTB, temp 
	ret 