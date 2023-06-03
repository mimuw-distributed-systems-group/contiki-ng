#include "contiki.h"

#include <stdio.h> /* For printf() */
#include "../../arch/cpu/cc26x0-cc13x0/lib/cc26xxware/driverlib/prcm.h" // To disable RFC.

#define HWREG(x)                                                              \
        (*((volatile unsigned long *)(x)))
void __attribute((noinline)) semihosting_exit(uint32_t value) {
  #define EXIT_ADDR 0xFEED0004
  HWREG(EXIT_ADDR) = value;

  // Avoid decoding unimplemented instructions after call site.
  __asm volatile(
    "NOP\n"
    "NOP\n"
    "NOP\n"
    "NOP\n"
    "NOP\n"
    "NOP\n"
  );
}

/*---------------------------------------------------------------------------*/
PROCESS(hello_world_process, "Hello world process");
AUTOSTART_PROCESSES(&hello_world_process);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(hello_world_process, ev, data)
{
  static struct etimer timer;

  PROCESS_BEGIN();

#ifdef FORCE_DEEP_SLEEP
  PRCMPowerDomainOff(PRCM_DOMAIN_RFCORE);
#endif

  etimer_set(&timer, CLOCK_SECOND * 10);

  PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
  semihosting_exit(42);

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
