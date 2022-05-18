#include "main.h"
/**
* _strlen - returns string length.
* @s: string to be measured length
* Return: 0.
*/
int _strlen(char *s)
{
int length = 0;

while (s[length] != '\0')
{
length++;
}
return (length);
}

