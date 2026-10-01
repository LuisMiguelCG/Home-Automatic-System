#include "FreeRTOS.h"
#include "task.h"

int main(void)
{

}

//*****************************************************************************
//
// Hooks de FreeRTOS (activados en FreeRTOSConfig.h).
//
//*****************************************************************************
void
vApplicationIdleHook(void)
{
    //
    // Se ejecuta en la tarea Idle cuando no hay nada mas que hacer. No debe
    // bloquearse nunca.
    //
}

void
vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    //
    // Una tarea ha desbordado su pila. Detener aqui con el depurador y mirar
    // pcTaskName; despues aumentar el tamano de pila de esa tarea.
    //
    (void)xTask;
    (void)pcTaskName;
    taskDISABLE_INTERRUPTS();
    for(;;)
    {
    }
}

void
vApplicationMallocFailedHook(void)
{
    //
    // pvPortMalloc() ha fallado: aumentar configTOTAL_HEAP_SIZE o reducir
    // pilas/colas.
    //
    taskDISABLE_INTERRUPTS();
    for(;;)
    {
    }
}
