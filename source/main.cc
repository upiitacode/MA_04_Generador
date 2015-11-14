#include "cmsis_os.h"                   // ARM::CMSIS:RTOS:Keil RTX
#include "SerialStream_stm32f3.h"
#include "dac_stm32f3.h"
#include "ctimers_stmf3.h"
#include "sine_table.h"
#include "stm32f30x.h"

void tarea1(void const * arguments); //tarea 1
osThreadId  tarea1ID;	//identificador del hilo tarea 1
osThreadDef (tarea1,osPriorityNormal,1,0);// macro para definir tareas (aputandor de la funcion, prioridad,?,?)

void tarea2(void const * arguments); //tarea 2
osThreadId  tarea2ID;	//identificador del hilo  tarea 2
osThreadDef (tarea2,osPriorityNormal,1,0);// macro para definir tareas (aputandor de la funcion, prioridad,?,?)

void tarea1Init(void);//funcion que iniciliza la tarea1
void tarea2Init(void);//funcion que iniciliza la tarea1

int main(){
	// hardware init
	dac_init();
	timer2_init(9,1);
	SerialUSART2 serial(9600);
	serial.printf("\nProccesor Speed %d\n", SystemCoreClock);

	// Kernel init
	osKernelInitialize();
	tarea1Init();
	tarea2Init();
	osKernelStart();

	//User application
	timer2_start();
	while(1){
		osDelay(1000);
	}
}

void tarea1Init(void){
	tarea1ID= osThreadCreate(osThread(tarea1),NULL);
}

void tarea2Init(void){
	tarea2ID= osThreadCreate(osThread(tarea2),NULL);
}

void tarea1(void const * arguments){
	while(1){
		osDelay(1000);
	}
}

void tarea2(void const * arguments){
	while(1){
		osDelay(1000);
	}
}

void timer2_callback(void){
	static unsigned int  accu = 0;
	float volt = sine_table[(accu&0xFF)]*(3.3/4095.0);
	dac_write(volt);
	accu++;
}
