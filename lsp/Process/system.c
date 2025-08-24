#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("start\n");
    system("ps -eaf");
    printf("end\n");
    exit(0);
}
