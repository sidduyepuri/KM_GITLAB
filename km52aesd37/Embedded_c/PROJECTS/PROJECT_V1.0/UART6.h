void KM_UART6_init_cofig(void);
void KM_UART6_outchar(unsigned char data);
unsigned char KM_UART6_inchar(void);
void KM_UART6_OutString(char str[]);
void UART6_MUX_init(void);
#define RCC_AHB1ENR (*((int *)0x40023830))
#define RCC_APB2ENR (*((int *)0x40023844))

