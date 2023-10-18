#include "shell.h"

/**
 * interactive_mode - it returns true if shell is interactive mode
 * info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive_mode(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * isDelimiter - checks if a character is a delimiter.
 * c: the character to check.
 * delim: the delimiter string.
 *
 * Returns: 1 if the character is a delimiter, 0 if it's not.
 */

int is_Delim(char c, char *delim)
{
while (*delim)
    if (*delim++ == c)
        return (1);
return (0);
}

/**
 * isAlpha - checks if a character is alphabetic.
 * c: The character to be checked.
 *
 * Returns: 1 if 'c' is an alphabetic character, 0 otherwise.
 */

int _isAlpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
else
    return (0);
}

/**
 * stringToInteger - converts a string to an integer.
 * s: The string to be converted.
 *
 * Returns: 0 if there are no numbers in the string, or the converted number otherwise.
 */

int _Atoi(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;

for (i = 0; s[i] != '\0' && flag != 2; i++)
{
    if (s[i] == '-')
        sign *= -1;

    if (s[i] >= '0' && s[i] <= '9')
    {
        flag = 1;
        result *= 10;
        result += (s[i] - '0');
    }
    else if (flag == 1)
        flag = 2;
}

if (sign == -1)
    output = -result;
else
    output = result;
return (output);
}
