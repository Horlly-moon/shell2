#include "shell.h"

/**
 * printEnvironment - prints the current environment.
 * info: A struct for potential arguments.
 *
 * Returns: Always 0.
 */

int _myEnv(info_t *info)
{
	Print_list_str(info->env);
	return (0);
}

/**
 * getenvValue - retrieves the value of an environment variable.
 * info: A structure for potential arguments.
 * name: The name of the environment variable.
 *
 * Returns: The value of the environment variable.
 */
char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *p;

while (node)
{
    p = Starts_with(node->str, name);
    if (p && *p)
        return (p);
    node = node->next;
}
return (NULL);
}

/**
 * setEnvironmentVariable - Initialize a new environment variable or modify an existing one.
 * info: A structure for potential arguments.
 *
 * Returns: Always 0.
 */

int _mySetenv(info_t *info)
{
if (info->argc != 3)
{
    _eputs("Incorrect number of arguements\n");
    return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
    return (0);
return (1);
}

/**
 * unsetEnv - Remove an environment variable.
 * info: A structure for potential arguments.
 *
 * Returns: Always 0.
 */
int _myUnsetenv(info_t *info)
{
int i;

if (info->argc == 1)
{
    _eputs("Too few arguements.\n");
    return (1);
}
for (i = 1; i <= info->argc; i++)
    _unsetenv(info, info->argv[i]);
return (0);
}

/**
 * populateEnv - populates an environment linked list.
 * info: A structure for potential arguments.
 *
 * Returns: Always 0.
 */
int Populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t i;

for (i = 0; environ[i]; i++)
    Add_node_end(&node, environ[i], 0);
info->env = node;
return (0);
}
