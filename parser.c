#include "shell.h"

/**
 * isCmnd - Determines if a file is an executable command.
 * info: The info struct.
 * path: The path to the file.
 *
 * Returns: 1 if the file is an executable command, 0 otherwise.
 */

int is_cmnd(info_t *info, char *path)
{
struct stat st;

(void)info;
if (!path || stat(path, &st))
    return (0);

if (st.st_mode & S_IFREG)
{
    return (1);
}
return (0);
}

/**
 * dup_char - Duplicates characters from a string.
 * pathstr: The PATH string.
 * start: The starting index for duplication.
 * stop: The stopping index for duplication.
 *
 * Returns: A pointer to the new buffer containing duplicated characters.
 */

char *dup_characs(char *pathstr, int start, int stop)
{
static char buf[1024];
int i = 0, k = 0;

for (k = 0, i = start; i < stop; i++)
    if (pathstr[i] != ':')
        buf[k++] = pathstr[i];
buf[k] = 0;
return (buf);
}

/**
 * find_Path - Finds a command in the PATH string.
 * info: The info struct.
 * pathstr: The PATH string to search.
 * cmnd: The command to find.
 *
 * Returns: The full path of the command if found, or NULL if not found.
 */

char *find_a_path(info_t *info, char *pathstr, char *cmnd)
{
int i = 0, curr_pos = 0;
char *path;

if (!pathstr)
    return (NULL);
if ((_strlen(cmnd) > 2) && Starts_with(cmnd, "./"))
{
    if (is_cmnd(info, cmnd))
        return (cmnd);
}
while (1)
{
    if (!pathstr[i] || pathstr[i] == ':')
    {
    path = dup_characs(pathstr, curr_pos, i);
    if (!*path)
        _strcat(path, cmnd);
    else
        {
            _strcat(path, "/");
            _strcat(path, cmnd);
        }
        if (is_cmnd(info, path))
            return (path);
        if (!pathstr[i])
            break;
        curr_pos = i;
    }
    i++;
}
return (NULL);
}
