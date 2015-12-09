#include "ctimers_stm32f3.h"
#include "stm32f30x.h"                  // Device header

void timer2_init(uint32_t period,int use_us){
	int prescaler = 0;
	SystemCoreClockUpdate();
	
	prescaler = use_us ? ((SystemCoreClock/1000000)-1) : ((SystemCoreClock/1000)-1); //CountFreq=(CoreClock/Prescaler+1)
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	TIM_TimeBaseInitTypeDef myTimer;
	TIM_TimeBaseStructInit(&myTimer);
	myTimer.TIM_CounterMode=TIM_CounterMode_Down;
	myTimer.TIM_Prescaler=prescaler;
	myTimer.TIM_ClockDivision=TIM_CKD_DIV1;
	myTimer.TIM_Period=period;
	TIM_TimeBaseInit(TIM2,&myTimer);
	
	TIM_InternalClockConfig(TIM2);
}

void timer2_enableIRQ(void){		
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	NVIC_EnableIRQ(TIM2_IRQn);
}

void timer2_start(void){
	TIM_Cmd(TIM2,ENABLE);
}

void timer2_stop(void){
	TIM_Cmd(TIM2,DISABLE);
}

void __attribute__((weak)) timer2_callback(void){}

#ifdef __cplusplus
extern "C" {
#endif
void TIM2_IRQHandler(void){
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
		timer2_callback();
	}
#ifdef __cplusplus
}
#endif


void timer15_init(uint16_t period,int use_us){
	int prescaler = 0;
	SystemCoreClockUpdate();
	
	prescaler = use_us ? ((SystemCoreClock/1000000)-1) : ((SystemCoreClock/1000)-1); //CountFreq=(CoreClock/Prescaler+1)
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM15,ENABLE);
	TIM_TimeBaseInitTypeDef myTimer;
	TIM_TimeBaseStructInit(&myTimer);
	myTimer.TIM_CounterMode=TIM_CounterMode_Up;//TIM15 can only be up timer
	myTimer.TIM_Prescaler=prescaler;
	myTimer.TIM_ClockDivision=TIM_CKD_DIV1;
	myTimer.TIM_Period=(period-1);
	TIM_TimeBaseInit(TIM15,&myTimer);
	TIM_InternalClockConfig(TIM15);
}

void timer15_enableIRQ(void){		
	TIM_ITConfig(TIM15,TIM_IT_Update,ENABLE);
	NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn);
}
void timer15_start(void){
	TIM_Cmd(TIM15,ENABLE);
}

void timer15_stop(void){
	TIM_Cmd(TIM15,DISABLE);
}

void __attribute__((weak)) timer15_callback(void){}

#ifdef __cplusplus
extern "C" {
#endif
void TIM1_BRK_TIM15_IRQHandler(void){
		TIM_ClearITPendingBit(TIM15,TIM_IT_Update);
		timer15_callback();
	}
#ifdef __cplusplus
}
#endif

void timer16_init(uint16_t period,int use_us){
	int prescaler = 0;
	SystemCoreClockUpdate();
	
	prescaler = use_us ? ((SystemCoreClock/1000000)-1) : ((SystemCoreClock/1000)-1); //CountFreq=(CoreClock/Prescaler+1)
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM16,ENABLE);
	TIM_TimeBaseInitTypeDef myTimer;
	TIM_TimeBaseStructInit(&myTimer);
	myTimer.TIM_CounterMode=TIM_CounterMode_Up;//TIM16 can only be up timer
	myTimer.TIM_Prescaler=prescaler;
	myTimer.TIM_ClockDivision=TIM_CKD_DIV1;
	myTimer.TIM_Period=(period-1);
	TIM_TimeBaseInit(TIM16,&myTimer);
	TIM_InternalClockConfig(TIM16);
}

void timer16_enableIRQ(void){		
	TIM_ITConfig(TIM16,TIM_IT_Update,ENABLE);
	NVIC_EnableIRQ(TIM1_UP_TIM16_IRQn);
}
void timer16_start(void){
	TIM_Cmd(TIM16,ENABLE);
}

void timer16_stop(void){
	TIM_Cmd(TIM16,DISABLE);
}

void __attribute__((weak)) timer16_callback(void){}
	
#ifdef __cplusplus
extern "C" {
#endif
void TIM1_UP_TIM16_IRQHandler(void){
		TIM_ClearITPendingBit(TIM16,TIM_IT_Update);
		timer16_callback();
	}
#ifdef __cplusplus
}
#endif

void timer17_init(uint16_t period,int use_us){
	int prescaler = 0;
	SystemCoreClockUpdate();
	
	prescaler = use_us ? ((SystemCoreClock/1000000)-1) : ((SystemCoreClock/1000)-1); //CountFreq=(CoreClock/Prescaler+1)
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM17,ENABLE);
	TIM_TimeBaseInitTypeDef myTimer;
	TIM_TimeBaseStructInit(&myTimer);
	myTimer.TIM_CounterMode=TIM_CounterMode_Up;//TIM17 can only be up timer
	myTimer.TIM_Prescaler=prescaler;
	myTimer.TIM_ClockDivision=TIM_CKD_DIV1;
	myTimer.TIM_Period=(period-1);
	TIM_TimeBaseInit(TIM17,&myTimer);
	TIM_InternalClockConfig(TIM17);
}

void timer17_enableIRQ(void){		
	TIM_ITConfig(TIM17,TIM_IT_Update,ENABLE);
	NVIC_EnableIRQ(TIM1_TRG_COM_TIM17_IRQn);
}

void timer17_start(void){
	TIM_Cmd(TIM17,ENABLE);
}

void timer17_stop(void){
	TIM_Cmd(TIM17,DISABLE);
}

void __attribute__((weak)) timer17_callback(void){}

#ifdef __cplusplus
extern "C" {
#endif
void TIM1_TRG_COM_TIM17_IRQHandler(void){
		TIM_ClearITPendingBit(TIM17,TIM_IT_Update);
		timer17_callback();
	}
#ifdef __cplusplus
}
#endif

void timer6_init(uint16_t period,int use_us){
	int prescaler = 0;
	SystemCoreClockUpdate();
	
	prescaler = use_us ? ((SystemCoreClock/1000000)-1) : ((SystemCoreClock/1000)-1); //CountFreq=(CoreClock/Prescaler+1)
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);
	TIM_TimeBaseInitTypeDef myTimer;
	TIM_TimeBaseStructInit(&myTimer);
	myTimer.TIM_CounterMode=TIM_CounterMode_Up;//TIM6 can only be up timer
	myTimer.TIM_Prescaler=prescaler;
	myTimer.TIM_ClockDivision=TIM_CKD_DIV1;
	myTimer.TIM_Period=(period-1);
	TIM_TimeBaseInit(TIM6,&myTimer);
	TIM_InternalClockConfig(TIM6);
}

void timer6_enableIRQ(void){		
	TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);
	NVIC_EnableIRQ(TIM6_DAC_IRQn);
}

void timer6_start(void){
	TIM_Cmd(TIM6,ENABLE);
}

void timer6_stop(void){
	TIM_Cmd(TIM6,DISABLE);
}

void __attribute__((weak)) timer6_callback(void){}

#ifdef __cplusplus
extern "C" {
#endif
void TIM6_DAC_IRQHandler(void){
		TIM_ClearITPendingBit(TIM6,TIM_IT_Update);
		timer6_callback();
	}
#ifdef __cplusplus
}
#endif

