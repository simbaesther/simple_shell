#include "main.h"

/**
*rev - retrieves the user in env, cd
*@p: input user, array of pointers
*@L: loops counter
*@li: input user
*@v: arguments in input
*@m: copy of environmental variable
*@e: number of elements in m
*@f: complete input
* Return: -1 for different input to env or cd
*or 0 for cd or env as input
*/
int rev(char **p, int L, char *li, char **v, char ***m, int *e, char *f)
{
int valenv = 0, valcd = 0, other = -1, valex = 0, valhel = 0;
int valunset = 0, valset = 0;

valunset = _isunsetenv(p, *m, e, L, v);
if (valunset == 0)
return (valunset);
valset = _issetenv(p, m, e, L, v);
if (valset == 0)
return (valset);
valex = _isexit(p, L, li, v, *m, f);
if (valex == 0)
return (valex);
valhel = _ishelp(p, L, v, *m);
if (valhel == 0)
return (valhel);
valenv = _isenv(p, *m);
valcd = _iscd(p, L, v, *m);
if (valenv == 0)
return (valenv);
if (valcd == 0)
return (valcd);
return (other);
}
/**
*functions - detects all  funcitons
*@line: user input
*@loop: shell loops number
*@argv: array of argumnets
*@m: copy of environment variables
*@e: elements in m (number)
*@f: full user input
*/
void functions(char *line, int loop, char *argv[], char ***m, int *e, char *f)
{
char **args = NULL;
int value = 1, i = 0;

line = _comments(line);
args = parsing(line);
if (args)

{
for (i = 0; args[i] != NULL; i++)
;
value = rev(args, loop, line, argv, m, e, f);
if (value != 0)
{
args = checkbin(args, *m);
if (args)
_frk(args, line, i, loop, argv, *e, *m, f);
}
free_grid(args, i);
free(line);
}
else
{
free(line);
fflush(STDIN_FILENO);
}
_put_err(args, loop, 0, argv);
}
/**
* argv_n - shell form (no filename at input)
* @argv: array of input arguments
* @envp: environment variables
*/
void argv_n(char *argv[], char *envp[])
{
char *line = NULL, **m = NULL, *p = NULL, *pr1 = NULL;
int e = 0, *ploop, i = 0, sem = 0;
static int loop;

loop = 0;
ploop = &loop;
while (1)
{
if (loop == 0)
{
m = create_env(envp);
for (e = 0; m[e] != NULL; e++)
;
}
line = _getline(ploop, m, e);
sem = semicolon(line, loop, argv);
if (!(sem == 1))
{
p = _strtoky2(line, ";\n");
while (p)
{
pr1 = _calloc(_strlen(p) + 2, sizeof(char));
for (i = 0; p[i] != '\0'; i++)
pr1[i] = p[i];
pr1[i] = '\n';
pr1[i + 1] = '\0';
functions(pr1, loop, argv, &m, &e, line);
p = _strtoky2(NULL, ";\n");
}
}
free(line);
}
}

