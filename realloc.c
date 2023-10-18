#include "shell.h"

/**
 * memSet - Fills a memory area with a constant byte.
 * s: The pointer to the memory area.
 * b: The byte used to fill *s.
 * n: The number of bytes to be filled.
 *
 * Returns: A pointer to the memory area 's'.
 */
char *_memSet(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
    s[i] = b;
return (s);
}

/**
 * f-free - Frees a string of strings.
 * pp: The string of strings to be freed.
 */

void f_free(char **pp)
{
char **a = pp;

if (!pp)
    return;
while (*pp)
    free(*pp++);
free(a);
}

/**
 * reallocate - Reallocates a block of memory.
 * ptr: Pointer to the previously malloc'ated block.
 * old_size: Byte size of the previous block.
 * new_size: Byte size of the new block.
 *
 * Returns: A pointer to the reallocated memory block.
 */

void *_reallocate(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;

if (!ptr)
    return (malloc(new_size));
if (!new_size)
    return (free(ptr), NULL);
if (new_size == old_size)
    return (ptr);

p = malloc(new_size);
if (!p)
    return (NULL);

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
    p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}
