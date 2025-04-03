#include "uart.h"
#include "gpio.h"

void uart_init(){
	GPIO->PIN_CNF[6] = 1;
	GPIO->PIN_CNF[8] = 0;

    /*
    GPIO->DIRSET = (1 << 6);
    GPIO->DIRCLR = (1 << 8);
    */
   
    UART->PSELTXD = 6;
    UART->PSELRXD = 8;

    UART->PSELCTS = 0xFFFFFFFF;
    UART->PSELRTS = 0xFFFFFFFF;

    UART->ENABLE = 4;
    UART->TASKS_STARTRX = 1;

    UART->BAUDRATE = 0x00275000;


}

void uart_send(char letter){
    UART->TASKS_STARTTX = 1;

    UART->TXD = letter;

    while (!UART->EVENTS_TXDRDY){};


    UART->EVENTS_TXDRDY = 0;
    UART->TASKS_STOPTX = 1;

}

char uart_read(){
    UART->EVENTS_RXDRDY = 0;
    char c = UART->RXD;
    
    return c;
}

ssize_t _write(int fd, const void *buf, size_t count){
    char * letter = (char *)(buf);
    for(int i = 0; i < count; i++){
        uart_send(*letter);
        letter++;
    }
    return count;
}