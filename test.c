#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main()
{
char *str;
write(1, "output", 10);
str = calloc(sizeof(char), 1000);
read(0,str,1000);
write(1,str,1000);
free(str);
}
