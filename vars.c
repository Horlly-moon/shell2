#include "shell.h"

/**
 * isChain - Tests if the current character in the buffer is a chain delimiter.
 * info: The parameter struct.
 * buf: The character buffer.
 * p: The address of the current position in 'buf.'
 *
 * Returns:
 *   - 1 if the character is a chain delimiter.
 *   - 0 otherwise.
 */

int isChain(info_t *info, char *buf, size_t *p)
{
size_t j = *p;

if (buf[j] == '|' && buf[j + 1] == '|')
{
    buf[j] = 0;
    j++;
    info->cmnd_buf_type = CMD_OR;
}
else if (buf[j] == '&' && buf[j + 1] == '&')
{
    buf[j] = 0;
    j++;
    info->cmnd_buf_type = CMD_AND;
}
else if (buf[j] == ';') /* found end of this command */
{
    buf[j] = 0; /* replace semicolon with null */
    info->cmnd_buf_type = CMD_CHAIN;
}
else
    return (0);
*p = j;
return (1);
}

/**
 * checkChain - Checks whether chaining should continue based on the last status.
 * info: The parameter struct.
 * buf: The character buffer.
 * p: The address of the current position in 'buf.'
 * i: The starting position in 'buf.'
 * len: The length of 'buf.'
 *
 * Returns: Void.
 */

void checkChain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
size_t j = *p;

if (info->cmnd_buf_type == CMD_AND)
{
    if (info->status)
    {
        buf[i] = 0;
        j = len;
    }
}
if (info->cmnd_buf_type == CMD_OR)
{
    if (!info->status)
    {
        buf[i] = 0;
        j = len;
    }
}

*p = j;
}

/**
 * replaceAliases - Replaces aliases in the tokenized string.
 * info: The parameter struct.
 *
 * Returns:
 *   - 1 if replacements are successful.
 *   - 0 otherwise.
 */

int replaceAlias(info_t *info)
{
int i;
list_t *node;
char *p;

for (i = 0; i < 10; i++)
{
    node = node_Starts_with(info->alias, info->argv[0], '=');
    if (!node)
        return (0);
    free(info->argv[0]);
    p = _strchr(node->str, '=');
    if (!p)
        return (0);
    p = _strdup(p + 1);
    if (!p)
        return (0);
    info->argv[0] = p;
}
return (1);
}

/**
 * replaceVariables - Replaces variables in the tokenized string.
 * info: The parameter struct.
 *
 * Returns:
 *   - 1 if replacements are successful.
 *   - 0 otherwise.
 */
int replaceVars(info_t *info)
{
int i = 0;
list_t *node;

for (i = 0; info->argv[i]; i++)
{
    if (info->argv[i][0] != '$' || !info->argv[i][1])
        continue;

    if (!_strcmp(info->argv[i], "$?"))
    {
        replaceString(&(info->argv[i]),
                _strdup(Convert_number(info->status, 10, 0)));
        continue;
    }
    if (!_strcmp(info->argv[i], "$$"))
    {
        replaceString(&(info->argv[i]),
                _strdup(Convert_number(getpid(), 10, 0)));
        continue;
    }
    node = node_Starts_with(info->env, &info->argv[i][1], '=');
    if (node)
    {
        replaceString(&(info->argv[i]),
                _strdup(_strchr(node->str, '=') + 1));
        continue;
    }
    replaceString(&info->argv[i], _strdup(""));

}
return (0);
}

/**
 * replaceString - Replaces a specified string.
 * old: The address of the old string to be replaced.
 * new: The new string to replace 'old.'
 *
 * Returns:
 *   - 1 if the replacement is successful.
 *   - 0 otherwise.
 */
int replaceString(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}

