#include "contiki.h"
#include "aux-ctrl.h"
#include "scif_uart_emulator.h"

#define BV(x)    (1 << (x))

static aux_consumer_module_t uart_aux = { NULL, AUX_WUC_SMPH_CLOCK };

void cc26xx_scif_uart_init() {
    AONWUCAuxWakeupEvent(AONWUC_AUX_WAKEUP);
    while(!(AONWUCPowerStatusGet() & AONWUC_AUX_POWER_ON));
    aux_ctrl_register_consumer(&uart_aux);
    AONWUCMcuPowerDownConfig(AONWUC_CLOCK_SRC_LF);
    AONWUCAuxPowerDownConfig(AONWUC_CLOCK_SRC_LF);

    scifInit(&scifDriverSetup);
    scifResetTaskStructs((1 << SCIF_UART_EMULATOR_TASK_ID), (1 << SCIF_STRUCT_CFG) | (1 << SCIF_STRUCT_INPUT) | (1 << SCIF_STRUCT_OUTPUT));
    scifExecuteTasksOnceNbl(BV(SCIF_UART_EMULATOR_TASK_ID));

    scifUartSetBaudRate(SCIF_UART_BAUD_RATE);
}
