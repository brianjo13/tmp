#ifndef UART_H
#define UART_H
#include <stdint.h>
#include <sys/types.h>
#include <stdio.h>

void uart_init();
void uart_send(char letter);
char uart_read();
ssize_t _write(int fd, const void *buf, size_t count);

#define UART ((NRF_UART_REG*)0x40002000)

/*
typedef struct {
    volatile uint32_t TASKS_STARTRX;
    volatile uint32_t TASKS_STOPRX;
    volatile uint32_t TASKS_STARTTX;
    volatile uint32_t buffer[61];
    volatile uint32_t EVENTS_CTS;
    volatile uint32_t EVENTS_NCTS;
    volatile uint32_t EVENTS_RXDRDY;
    volatile uint32_t EVENTS_TXDRDY;
    volatile uint32_t EVENTS_ERROR;
    volatile uint32_t EVENTS_RXTO;

} NRF_UART_REG;
*/
typedef struct {
    volatile uint32_t TASKS_STARTRX;
    volatile uint32_t TASKS_STOPRX;
    volatile uint32_t TASKS_STARTTX;
    volatile uint32_t TASKS_STOPTX;
    volatile uint32_t offset2[3];
    volatile uint32_t TASKS_SUSPEND;
    volatile uint32_t offset[56];
    volatile uint32_t EVENTS_CTS;
    volatile uint32_t EVENTS_NCTS;
    volatile uint32_t EVENTS_RXDRDY;
    volatile uint32_t offset3[4];
    volatile uint32_t EVENTS_TXDRDY;
    volatile uint32_t offset4[1];
    volatile uint32_t EVENTS_ERROR;
    volatile uint32_t offset5[7];
    volatile uint32_t EVENTS_RXTO;
    volatile uint32_t offset1[46];
    volatile uint32_t SHORTS;
    volatile uint32_t offset6[64];
    volatile uint32_t INTENSET;
    volatile uint32_t INTENCLR;
    volatile uint32_t offset10[93];
    volatile uint32_t ERRORSRC;
    volatile uint32_t offset7[31];
    volatile uint32_t ENABLE;
    volatile uint32_t offset8[1];
    volatile uint32_t PSELRTS;
    volatile uint32_t PSELTXD;
    volatile uint32_t PSELCTS;
    volatile uint32_t PSELRXD;
    volatile uint32_t RXD;
    volatile uint32_t TXD;
    volatile uint32_t offset11[1];
    volatile uint32_t BAUDRATE;
    volatile uint32_t offset9[17];
    volatile uint32_t CONFIG;
} NRF_UART_REG;
#endif