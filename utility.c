#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

// use to clear redundant scanf
void clear(void)
{
    char b;
    do
    {
        scanf("%c",&b);
    }
    while(b !='\n');
}

