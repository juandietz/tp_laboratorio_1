
#include <stdio.h>
#include "strings_esp.h"
//#include "strings_eng.h"

void welcome(void)
{
    printf("\n-----------------------------------------\n");
    printf("%s\n"  , MSG_WELCOME);
    printf("-----------------------------------------\n\n");
    printf("\n%s\n", MSG_SET_VALUES);

    return;
}
