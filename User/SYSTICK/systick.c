#include "./SYSTICK/systick.h"

uint32_t TimingDelay = 0;

#if 0

static __INLINE uint32_t SysTick_Config(uint32_t ticks)
{ 
  if (ticks > SysTick_LOAD_RELOAD_Msk)  return (1);            /* ������װ�ڼĴ�����ֵReload value impossible */
                                                               
  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;      /* ������װ�ڼĴ�����ֵset reload register */
  NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);  /* �����ж����ȼ�set Priority for Cortex-M0 System Interrupts */
  SysTick->VAL   = 0;                                          /* ��ʼ��counter��ֵΪ0 Load the SysTick Counter Value */
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk | 
                   SysTick_CTRL_TICKINT_Msk   | 
                   SysTick_CTRL_ENABLE_Msk;                    /* ʹ���ж��Լ�ʹ�ܶ�ʱ�� ����ʱ��ΪAHB��ʱ�� Enable SysTick IRQ and SysTick Timer */
  return (0);                                                  /* Function successful */
}

#endif

//��ʱus
void SysTick_Delay_us(uint32_t us)
{
	uint32_t i;
	SysTick_Config(72);			//t=72*(1/72M)=1us
	for(i=0;i<us;i++)
	{
		while(!(SysTick->CTRL&(1<<16)));			//��ȡ��־λ��ֵ
	}
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;	//�رն�ʱ��  ʹ�ܹ�
}

//��ʱms
void SysTick_Delay_ms(uint32_t ms)
{
	uint32_t i;
	SysTick_Config(72000);	//t=72000*(1/72M)=1ms
	for(i=0;i<ms;i++)
	{
		while(!(SysTick->CTRL&(1<<16)));			//��ȡ��־λ��ֵ
	}
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;	//�رն�ʱ��	ʹ�ܹ�
}

void SysTick_TI_Init(void)					//ʹ���жϽ���ms��ʱ��ʼ��
{
	/* SystemFrequency / 1000    1ms�ж�һ��
	* SystemFrequency / 100000	 10us�ж�һ��
	* SystemFrequency / 1000000 1us�ж�һ��
	*/
	SysTick_Config(SystemCoreClock/1000);
	
	SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;			// �رյδ�ʱ�� 
}

void Delay_ms(uint32_t ms)			//ʹ���жϽ���ms��ʱ
{
	TimingDelay = ms;
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;			// ʹ�ܵδ�ʱ�� 
	while(TimingDelay > 0);			//�ж�����TimingDelay--
	SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;			// �رյδ�ʱ�� 
}

void Delay_us(uint32_t us)			//ʹ���жϽ���us��ʱ
{
	TimingDelay = us;
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;			// ʹ�ܵδ�ʱ�� 
	while(TimingDelay > 0);			//�ж�����TimingDelay--
	SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;			// �رյδ�ʱ�� 
}

