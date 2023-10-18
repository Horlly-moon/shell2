
#include "shell.h"

/**
 * strcpy - Copies a string from source to destination.
 * dest: The destination where 'src' is copied to.
 * src: The source string to be copied.
 *
 * Returns: A pointer to the destination string.
 */

char *_strcpy(char *dest, char *src)
{
int i = 0;

if (dest == src || src == 0)
    return (dest);
while (src[i])
{
    dest[i] = src[i];
    i++;
}
dest[i] = 0;
return (dest);
}

/**
 * strdup - Duplicates a string.
 * str: The string to be duplicated.
 *
 * Returns: A pointer to the duplicated string.
 */

char *_strdup(const char *str)
{
int length = 0;
char *ret;

if (str == NULL)
    return (NULL);
while (*str++)
    length++;
ret = malloc(sizeof(char) * (length + 1));
if (!ret)
    return (NULL);
for (length++; length--;)
    ret[length] = *--str;
return (ret);
}

/**
 * printString - Prints an input string.
 * str: The string to be printed.
 *
 * Returns: None (void).
 */
void _puts(char *str)
{
int i = 0;

if (!str)
    return;
while (str[i] != '\0')
{
    _putchar(str[i]);
    i++;
}
}

/**
 * putChar - Writes the character 'c' to standard output (stdout).
 * c: The character to be printed.
 *
 * Returns:
 *   - 1 on success.
 *   - -1 on error, with errno set appropriately.
 */

int _putchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
    write(1, buf, i);
    i = 0;
}
if (c != BUF_FLUSH)
    buf[i++] = c;
return (1);
}
