#include <string.h>
#include "b24me1047_b24bb1014_b24ch1037_b24cm1066_utils.h"

void trimNewline(char *str) 
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
