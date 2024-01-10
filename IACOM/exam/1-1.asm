	list      p=16F84A          ; list directive to define processor
	#include <p16F84A.inc>      ; processor specific variable definitions

	__CONFIG   _FOSC_XT & _WDTE_OFF & _PWRTE_OFF & _CP_OFF

;***** VARIABLE DEFINITIONS
varA        EQU     0x0C        ; aponta para 0x0C
varB        EQU     0x0D        ; aponta para 0x0D
varC        EQU     0x0E        ; aponta para 0x0E
varD        EQU     0x0F        ; aponta para 0x0F
varE        EQU     0x10        ; aponta para 0x10 
varAux      EQU     0x11
retFunc	    EQU     0x12

;**********************************************************************
	    ORG     0x000	        ; processor reset vector
	    goto    start_prog	    ; go to beginning of program
	    ORG     0x004	        ; interrupt vector location


; isr code can go here or be located as a call subroutine elsewhere
start_prog
	    bcf     STATUS,RP0	    ; seleciona banco de memória 0
	    clrf    PORTA	        ; clear port A
	    bsf	    STATUS,RP0	    ; seleciona banco de memória 0
	    bsf     TRISA,RA1	    ; ativa RA1 como entrada

	    bcf	    STATUS,RP0	    ; seleciona banco de memória 0
	    clrf    PORTB	        ; clear port B
	    bsf	    STATUS,RP0	    ; seleciona banco de memória 1
	    movlw   0x00	        ; W <- 0x00
	    movwf   TRISB	        ; TRISB <- W
	    bcf	    STATUS,RP0	    ; seleciona banco de memoria 0

config_var
	    movlw   0x02	        ; W <- 0x002
	    movwf   varA	        ; varA <- W
	    
	    movlw   0x03	        ; W <- 0x03
	    movwf   varB	        ; varB <- W
	    
	    movlw   0xFD	        ; W <- 0xFD (-3)
	    movwf   varC	        ; varC <- W
	    
				                ; operação para varD
	    movlw   0x08	        ; W <- 0x08
	    addwf   varA,W	        ; W <- W + varA
	    
				                ; movendo o valor da soma de 0x08 com varA para varD
	    movwf   varD	        ; varD <- W
	    
	    goto    loop	        ; vai para loop
	    
loop
	    nop
				                ; inicio IF1
if1
	    btfss   PORTA,RA1	    ; testa bit RA1, se = 1, salta para then_if1
	    goto    else_if1
	    
then_if1
	    movf    varC,W	        ; W <- varC
	    call    func	        ; chama a função
	    movf    retFunc,W       ; W <- retFunc
	    movwf   varE	        ; varE <- W
	    movf    varE,W	        ; W <- varE
	    goto    ver_var	        ; verifica varE
	    
else_if1
	    movf    varD,W	        ; W <- varD
	    call    func	        ; chama a função
	    movf    retFunc,W       ; W <- retFunc
	    movwf   varE	        ; varE <- W
	    movf    varE,W	        ; W <- varE
	    goto    ver_var
	    
end_if1
	    nop			            ; fim do if1
	    goto    loop	        ; volta para o loop
	    
ver_var
	    btfsc   STATUS,Z
	    goto    else2
	    
bigger_then0
	    btfsc   varE,7
	    goto    else2
	    
then2
	    movlw   0x05	    ; W <- 0x05
	    movwf   PORTB	    ; escreve na PORTB <- 0x05
	    goto    loop
	   
else2
	    movlw   0x04	    ; W <- 0x04
	    movwf   PORTB	    ; escreve na PORTB < 0x04
	    goto    loop
	    
func
	    movwf   varAux	    ; varAux <- W (com valor de varD ou varC)
	    addwf   varAux	    ; W <- W + varAux
	    addwf   varAux	    ; W <- W + varAux
	    addwf   varAux	    ; W <- W + varAux
	    movwf   varAux
	    movlw   0x03
	    subwf   varAux,W
	    movwf   retFunc	    ; volta para o programa principal
	    return
	    
	    END