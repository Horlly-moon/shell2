#include "shell.h"

/**
 * bFree - Frees a pointer and sets the address to NULL.
 * ptr: The address of the pointer to free.
 *
 * Returns: 1 if the pointer was freed, otherwise 0.
 */
int b_free(void **ptr)
{
if (ptr && *ptr)
{
    free(*ptr);
    *ptr = NULL;
    return (1);
}
return (0);
}
