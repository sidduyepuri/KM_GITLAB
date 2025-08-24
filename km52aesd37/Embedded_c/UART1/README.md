DATE: 17-NOV-2023 || TOPIC: UART(Universal asynchronous receiver & Transmitter)

Experiment 1: USART Polling
	Write a pseudo code and Embedded C program to Configure UART2 with 9600 8N1.
	And transmit character ‘A’ and Receive same character using hardware Loop back.
	a. System Clock Initialization to 16MHZ.
	b. UART Communication protocol specifications –
		9600 8N1 = 1 start bit+8 word length +parity(0 bit)+ 1 stop bit = 10 bits.
	c. Enable polling (nothing but disable UART Interrupts)
Experiment 2: Write an Embedded C Program and implement USART Non-Blocking and USART
		TIMEOUT Functions.
Experiment 3: USART RX interrupts
	Write a Pseudo code and Embedded C program to USAR2 Configuration using the below
	conditions.
	a. System Clock Initialization to 16MHZ
	b. 9600 8N1 (1+8+0+1=10 bits)
	Assign a Hardware breakpoint in UART2_ISR and run program. Program execution time sends
	‘A’ character from host system using Tera term application. Verify results in ISR.
