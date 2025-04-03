#include "uart.h"
#include "gpio.h"

int main(){
    int matrixOn = 0;
    
    //configure LEDs
    for(int i = 17; i <= 20; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTSET = (1 << i);
		
	}


    GPIO->PIN_CNF[13] = (3 << 2);
	GPIO->PIN_CNF[14] = (3 << 2);
	GPIO->PIN_CNF[15] = (3 << 2);


    uart_init();

    while(1){  

        if (!(GPIO->IN & (1 << 13))){
            uart_send('A');
		}

        if (!(GPIO->IN & (1 << 14))){
			uart_send('B');
		}

        if (!(GPIO->IN & (1 << 15))){
	        iprintf("The average grade in TTK%d was in %d was: %c\n\r",4235,2022,'B');
		}

        char letter = uart_read();
        if (letter != '\0'){
            matrixOn = !matrixOn;
        }

        if (matrixOn){
            GPIO->OUTCLR = (15 << 17);

        }
        else{
            GPIO->OUTSET = (15 << 17);
        }



        int s = 10000;
        while(s--){}
    }

}