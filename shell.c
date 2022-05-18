#include "main.h"

/**
* main - simple shell
* @argc: number of input arguments
* @argv: array of input arguments
* @envp: environment variables
* Return: 0
*/
int main(int argc, char *argv[], char *envp[])
{

if (argc == 1)
{
argv_n(argv, envp);
}
else if (argc == 2)
{
argv_y(argv, envp);
}
else
{
write(STDIN_FILENO, "ACCEPTED ARGS NUMBER", 31);
write(STDIN_FILENO, "\n", 1);
}
return (0);
}

