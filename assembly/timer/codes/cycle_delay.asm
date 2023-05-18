;.include "/home/gadepall/m328Pdef.inc"
.include "/sdcard/Download/latex/digital-design/trunk/assembly/setup/m328Pdef/m328Pdef.inc"
ldi r31,0b00100000
out DDRB,r31 ;Defining Pin 13 as output
ldi r16, 0 
out SREG , r16 ;Clearing Status register
ldi r16 ,low (RAMEND) ;Lower byte of address is stored in r16
out SPL , r16 ;Lower byte of address is moved to SPL
ldi r16 ,high (RAMEND) ;Higher byte of address is stored in r16
out SPH , r16 ;Higher byte of address is moved to SPH
ldi r27,0b00000000
ldi r28,0b00100000
comp:
eor r27,r28 ;To blink the LED
out PORTB,r27
call wait
rcall comp

wait:
     push r16
     push r17
     push r18

    ldi r16,0x50
    ldi r17,0x00
    ldi r18,0x00

w0:
    dec r18 
    brne w0 ;loop breaks after running 256 times
    dec r17
    brne w0 ;loop breaks after running 256 times
    dec r16
    brne w0 ;loop breaks after running 80 times
    pop r18
    pop r17
    pop r16
    ret

    ;Calculated delay is around 0.32768 sec
    ;Actual delay is around 1 sec
