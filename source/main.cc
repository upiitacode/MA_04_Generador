#include "cmsis_os.h"                   // ARM::CMSIS:RTOS:Keil RTX
#include "SerialStream_stm32f3.h"
#include "dac_stm32f3.h"
#include "ctimers_stm32f3.h"
#include "sine_table.h"
#include "stm32f30x.h"

void tarea1(void const * arguments); //tarea 1
osThreadId  tarea1ID;	//identificador del hilo tarea 1
osThreadDef (tarea1,osPriorityNormal,1,0);// macro para definir tareas (aputandor de la funcion, prioridad,?,?)

void tarea1Init(void);//funcion que iniciliza la tarea1

const char *functionNames[] = {"Senoidal","Triangular","Rampa"};

int main(){
	char inputBuffer[80];
	// hardware init
	dac_init();
	timer2_init(10,PERIOD_IN_MICROSECONDS);
	timer2_enableIRQ();
	SerialUSART2 serial(9600);
	serial.printf("\nProccesor Speed %d\n",(int) SystemCoreClock);

	// Kernel init
	osKernelInitialize();
	tarea1Init();
	osKernelStart();

	//User application
	timer2_start();
	int selector;
	while(1){
		serial.printf("Seleccione funcion: \n");
		serial.gets(inputBuffer, 80);
		serial.printf("hesdf: \n");
		sscanf(inputBuffer,"%d",&selector);
		if(selector >= 0 && selector < 3){
			serial.printf("usted selecciono %s\n",functionNames[selector]);
		}
		else{
			serial.printf("valor incorrecto\n");
		}
	}
}

void tarea1Init(void){
	tarea1ID= osThreadCreate(osThread(tarea1),NULL);
}

void tarea1(void const * arguments){
	while(1){
		osDelay(1000);
	}
}

void timer2_callback(void){
	static unsigned int  accu = 0;
	float volt = sine_table[((accu >> 8)&0xFF)]*(3.3/4095.0);
	dac_write(volt);
	accu++;
}
