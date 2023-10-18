#include "shell.h"

/**
 * strlen - Calculates the length of a string.
 * s: The string for which the length is determined.
 *
 * Returns: An integer representing the length of the string.
 */

int _strlen(char *s)
{
int i = 0;

if (!s)
    return (0);

while (*s++)
    i++;
return (i);
}

/**
 * strcmp - Performs lexicographic comparison of two strings.
 * s1: The first string for comparison.
 * s2: The second string for comparison.
 *
 * Returns:
 *   - A negative value if s1 is lexicographically less than s2.
 *   - A positive value if s1 is lexicographically greater than s2.
 *   - Zero if s1 is lexicographically equal to s2.
 */

int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
    if (*s1 != *s2)
        return (*s1 - *s2);
    s1++;
    s2++;
}
if (*s1 == *s2)
    return (0);
else
    return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_With - Checks if the 'needle' starts with 'haystack.'
 * haystack: The string to search within.
 * needle: The substring to find at the beginning of 'haystack.'
 *
 * Returns:
 *   - The address of the next character in 'haystack' after the match, or
 *   - NULL if 'needle' is not found at the beginning of 'haystack.'
 */

char *Starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * strcat - Concatenates two strings.
 * dest: The destination buffer to which 'src' is appended.
 * src: The source buffer that is appended to 'dest.'
 *
 * Returns: A pointer to the destination buffer.
 */

char *_strcat(char *dest, char *src)
{
char *ret = dest;

while (*dest)
    dest++;
while (*src)
    *dest++ = *src++;
*dest = *src;
return (ret);
}
