# Contiki-NG for CherryMotes of 1KT

This is a fork of [Contiki-NG](https://github.com/contiki-ng/contiki-ng) for the CherryMote devices of the [1KT testbed](https://www.mimuw.edu.pl/~iwanicki/projects/heni/1kt.html).

Currently, supported are: the CC2650 MCU itself (incl. RF core), the main UART (115200 baud rate, software flow control _xo/xoff_), _SCIF UART PRINTF_ (see below), and LEDs (see below).

## Modifications

The design of CherryMote is based on the SmartRF 06 Evaluation Board with CC2650. Use this target and board to compile an app for CherryMotes:
```
make TARGET=cc26x0-cc13x0 BOARD=srf06/cc26x0
```

Our modifications to the target and the board include:

1. Pinout adjusted to CherryMote and its peripherals.

3. _SCIF UART PRINTF_: an additional, fast UART implemented on the CC2650's Sensor Controller to emit logs with low overhead:
   ```C
   printf("Hello world\n");  // Will be emitted via SCIF UART PRINTF
   ```

4. Customized LEDs colors:
   - `LEDS_YELLOW`: CherryMote's yellow LED,
   - `LEDS_VLED1`: CherryMote's virtual LED 1,
   - `LEDS_VLED2`: CherryMote's virtual LED 2.

5. Modified build system to output `.elf`, `.hex`, and `.flash`.
