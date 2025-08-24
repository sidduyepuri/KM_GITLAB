DATE: 09-OCT-2023 || TOPIC: STORAGE CLASSES

Rewrite the calculator program so that the main function is in main.c , remaining functions are in another source code file, operations.c.

1. Create the operand variables as global variables and use them in the operation functions directly, without passing as arguments. Function returns the result as return value.

2. Create the operand variables as global variables and use them in the operation functions directly, without passing as arguments. Function return value should be stored in another global variable in the operations file and be used to print in main.

3. WAP - for the 4 departments of a supermarket : Sales, Purchase, Stock and SuperMarket in four different source code files.
Stock : Maintains a variable for available stock.
Sales : Has one function: Sell – It will reduce the stock by the number of items sold. Before selling, check if enough stock is available.
Purchase : Has one function : Purchase – will increase the stock by the number of items purchased.Set a max value for stock, before purchasing check if the stock room has enough space for new items or not.
SuperMarket : Display menu with choices : 1 ) check AvailableStock 2 ) Purchase new items 3) Sell items … this should be continuous as long as the user wants to continue. Program should stop when the user wants to quit.
