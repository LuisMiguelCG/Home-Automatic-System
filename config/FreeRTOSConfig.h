/*
 * FreeRTOSConfig.h
 *
 * Configuracion de FreeRTOS V8.2.3 para TM4C123GH6PM (Cortex-M4F).
 * Ver http://www.freertos.org/a00110.html
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"


/*-----------------------------------------------------------
 * Planificador
 *----------------------------------------------------------*/
#define configUSE_PREEMPTION                1
#define configUSE_IDLE_HOOK                 1
#define configUSE_TICK_HOOK                 0
/* Debe coincidir con el reloj configurado con SysCtlClockSet() en main(). */
#define configCPU_CLOCK_HZ                  ( ( unsigned long ) MAP_SysCtlClockGet() )
#define configTICK_RATE_HZ                  ( ( TickType_t ) 1000 )
#define configMAX_PRIORITIES                ( 16 )
#define configMINIMAL_STACK_SIZE            ( ( unsigned short ) 128 )
#define configTOTAL_HEAP_SIZE               ( ( size_t ) ( 20 * 1024 ) )
#define configMAX_TASK_NAME_LEN             ( 12 )
#define configUSE_16_BIT_TICKS              0
#define configIDLE_SHOULD_YIELD             1

/*-----------------------------------------------------------
 * Sincronizacion
 *----------------------------------------------------------*/
#define configUSE_MUTEXES                   1
#define configUSE_RECURSIVE_MUTEXES         1
#define configUSE_COUNTING_SEMAPHORES       1
/* Permite ver las colas/semaforos por nombre en el depurador. */
#define configQUEUE_REGISTRY_SIZE           8

/*-----------------------------------------------------------
 * Depuracion
 *----------------------------------------------------------*/
/* 2 = comprueba el puntero de pila y un patron al final de la pila en cada
   cambio de contexto. Llama a vApplicationStackOverflowHook() (main.c). */
#define configCHECK_FOR_STACK_OVERFLOW      2
/* Llama a vApplicationMallocFailedHook() (main.c) si se agota el heap. */
#define configUSE_MALLOC_FAILED_HOOK        1
#define configUSE_TRACE_FACILITY            0
#define configGENERATE_RUN_TIME_STATS       0

/*-----------------------------------------------------------
 * Co-rutinas
 *----------------------------------------------------------*/
#define configUSE_CO_ROUTINES               0
#define configMAX_CO_ROUTINE_PRIORITIES     ( 2 )

/*-----------------------------------------------------------
 * Software timers
 *----------------------------------------------------------*/
#define configUSE_TIMERS                    1
#define configTIMER_TASK_PRIORITY           ( 2 )
#define configTIMER_QUEUE_LENGTH            32
#define configTIMER_TASK_STACK_DEPTH        ( configMINIMAL_STACK_SIZE * 2 )

/*-----------------------------------------------------------
 * Funciones de la API incluidas
 *----------------------------------------------------------*/
#define INCLUDE_vTaskPrioritySet            1
#define INCLUDE_uxTaskPriorityGet           1
#define INCLUDE_vTaskDelete                 1
#define INCLUDE_vTaskSuspend                1
#define INCLUDE_vTaskDelayUntil             1
#define INCLUDE_vTaskDelay                  1
#define INCLUDE_xTaskGetSchedulerState      1
#define INCLUDE_uxTaskGetStackHighWaterMark 1

#define INCLUDE_xTimerPendFunctionCallFromISR          1
#define INCLUDE_xTimerPendFunctionCall			          1

/*-----------------------------------------------------------
 * Prioridades de interrupcion (Cortex-M4F: 3 bits de prioridad en TM4C)
 *----------------------------------------------------------*/
#define configPRIO_BITS                     3

/* Prioridad mas baja: usada por el kernel (PendSV y SysTick). */
#define configKERNEL_INTERRUPT_PRIORITY         ( 7 << 5 )

/* Las ISR que llamen a funciones "...FromISR()" deben tener una prioridad
   numericamente >= 5. Las de prioridad 0..4 nunca son bloqueadas por el
   kernel, pero no pueden usar la API de FreeRTOS. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY    ( 5 << 5 )

/*-----------------------------------------------------------
 * Asserts
 *----------------------------------------------------------*/
#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }

#endif /* FREERTOS_CONFIG_H */
