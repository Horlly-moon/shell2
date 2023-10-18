#include "shell.h"

/**
 * List_len – Determines the length of a linked list.
 * h: A pointer to the first node in the list.
 *
 * Returns: The size of the list, i.e., the number of nodes in the linked list.
 */
size_t List_len(const list_t *h)
{
size_t i = 0;

while (h)
{
    h = h->next;
    i++;
}
return (i);
}

/**
 * list_to_string - Converts a linked list into an array of strings.
 * head: A pointer to the first node in the linked list.
 *
 * Returns: An array of strings extracted from the list's node->str fields.
 */

char **List_to_strings(list_t *head)
{
list_t *node = head;
size_t i = List_len(head), j;
char **strs;
char *str;

if (!head || !i)
    return (NULL);
strs = malloc(sizeof(char *) * (i + 1));
if (!strs)
    return (NULL);
for (i = 0; node; node = node->next, i++)
{
    str = malloc(_strlen(node->str) + 1);
    if (!str)
    {
        for (j = 0; j < i; j++)
            free(strs[j]);
        free(strs);
        return (NULL);
    }

    str = _strcpy(str, node->str);
    strs[i] = str;
}
strs[i] = NULL;
return (strs);
}

/**
 * print_List - Prints all elements of a list_t linked list.
 * h: A pointer to the first node in the linked list.
 *
 * Returns: The size of the list, i.e., the number of nodes in the linked list.
 */
size_t Print_list(const list_t *h)
{
size_t i = 0;

while (h)
{
    _puts(Convert_number(h->num, 10, 0));
    _putchar(':');
    _putchar(' ');
    _puts(h->str ? h->str : "(nil)");
    _puts("\n");
    h = h->next;
    i++;
}
return (i);
}

/**
 * nodeStartswith –  returns node whose string would start with prefix
 * node: pointer to list head
 * prefix: string to match
 * c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_Starts_with(list_t *node, char *prefix, char c)
{
char *p = NULL;

while (node)
{
    p = Starts_with(node->str, prefix);
    if (p && ((c == -1) || (*p == c)))
        return (node);
    node = node->next;
}
return (NULL);
}

/**
 * get_Node_Index - Retrieves the index of a node in the linked list.
 * head: A pointer to the head of the list.
 * node: A pointer to the node for which the index is sought.
 *
 * Returns: The index of the node if found, or -1 if the node is not in the list.
 */

ssize_t get_Node_index(list_t *head, list_t *node)
{
size_t i = 0;

while (head)
{
    if (head == node)
        return (i);
    head = head->next;
    i++;
}
return (-1);
}
