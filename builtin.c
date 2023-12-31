#include "shell.h"

/**
 * exitShell - exits the shell.
 * info: A structure that may contain relevant arguments. This parameter is used to maintain
 * the consistent function prototype.
 *
 * Returns: Exits the shell with a given exit status (0) if info.argv[0] is not "exit."
 */

int _myExit(info_t *info)
{
int exitcheck;

if (info->argv[1]) /* If there is an exit arguement */
{
    exitcheck = _err_atoi(info->argv[1]);
    if (exitcheck == -1)
    {
        info->status = 2;
        Print_error(info, "Illegal number: ");
        _eputs(info->argv[1]);
        _eputchar('\n');
        return (1);
    }
    info->err_num = _err_atoi(info->argv[1]);
    return (-2);
}
info->err_num = -1;
return (-2);
}

/**
 * myCd - changes the current directory of the process.
 * info: A structure that may contain relevant arguments. This parameter is used to maintain
 * the consistent function prototype.
 *
 * Returns: Always 0.
 */

int _myCd(info_t *info)
{
char *s, *dir, buffer[1024];
int chdir_ret;

s = getcwd(buffer, 1024);
if (!s)
    _puts("TODO: >>getcwd failure emsg here<<\n");
if (!info->argv[1])
{
    dir = _getenv(info, "HOME=");
    if (!dir)
        chdir_ret = /* TODO: what should this be? */
            chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
    else
        chdir_ret = chdir(dir);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
    if (!_getenv(info, "OLDPWD="))
    {
        _puts(s);
        _putchar('\n');
        return (1);
    }
    _puts(_getenv(info, "OLDPWD=")), _putchar('\n');
    chdir_ret = /* TODO: what should this be? */
        chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
}
else
    chdir_ret = chdir(info->argv[1]);
if (chdir_ret == -1)
{
    Print_error(info, "can't cd to ");
    _eputs(info->argv[1]), _eputchar('\n');
}
else
{
    _setenv(info, "OLDPWD", _getenv(info, "PWD="));
    _setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}

/**
 * myHelp - displays help information for the process.
 * info: A structure that may contain relevant arguments. This parameter is used to maintain
 * the consistent function prototype.
 *
 * Returns: Always 0.
 */
int _myHelp(info_t *info)
{
char **arg_array;

arg_array = info->argv;
_puts("help call works. Function not yet implemented \n");
if (0)
    _puts(*arg_array); /* temp att_unused workaround */
return (0);
}
