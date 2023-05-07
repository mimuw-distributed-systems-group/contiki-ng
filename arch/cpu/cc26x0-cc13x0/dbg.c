/*
 * Copyright (c) 2014, Texas Instruments Incorporated - http://www.ti.com/
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*---------------------------------------------------------------------------*/
#include "cc26xx-uart.h"
#include "ti-lib.h"
#include "contiki.h"
#if SCIF_UART_PRINTF
#include "scif_uart_emulator.h"
#define LOST_BUFFER_SIZE 16
#define SC_UART_FREE_THRESHOLD (2 * SCIF_UART_TX_FIFO_MAX_COUNT / 4)
#endif

#include <string.h>
/*---------------------------------------------------------------------------*/
int
dbg_putchar(int c)
{
#if SCIF_UART_PRINTF
  scifUartTxPutChar(c);
#else
  cc26xx_uart_write_byte(c);
#endif
  return c;
}
/*---------------------------------------------------------------------------*/
unsigned int
dbg_send_bytes(const unsigned char *s, unsigned int len)
{
  unsigned int i = 0;
#if SCIF_UART_PRINTF
  static int bytes_lost = 0;
  char lost_buffer[LOST_BUFFER_SIZE];

  int free = 2 * (SCIF_UART_TX_FIFO_MAX_COUNT - scifUartGetTxFifoCount());
  if (bytes_lost > 0) {   
    if (free >= SC_UART_FREE_THRESHOLD) {
      int message_size = len + 
            snprintf(lost_buffer, LOST_BUFFER_SIZE, "\nLOST:%d\n", bytes_lost);
          
      if (free < message_size) {
        bytes_lost += len;
        return 0;
      }
      else {
        scifUartTxPutChars(lost_buffer, message_size);
        bytes_lost = 0;
      }
    }
    else {
      bytes_lost += len;
      return 0;
    }
  }
  else {
    if (free < len) {
      bytes_lost += len - free;
      len = free;
    }
  }
  while (i + 1 < len && s[i] != 0 && s[i + 1] != 0) {
    scifUartTxPutTwoChars(s[i], s[i + 1]);
    i += 2;
  }
  if (i < len && s[i] != 0)
    scifUartTxPutChar(s[i++]);
#else
  while(s && *s != 0) {
    if(i >= len) {
      break;
    }
    cc26xx_uart_write_byte(*s++);
    i++;
  }


  /*
   * Wait for the buffer to go out. This is to prevent garbage when used
   * between UART on/off cycles
   */
  while(cc26xx_uart_busy() == UART_BUSY);
#endif
  return i;
}
/*---------------------------------------------------------------------------*/
