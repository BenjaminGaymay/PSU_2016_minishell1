/*
** path.c for minishell1 in /home/benjamin.g/delivery/PSU_2016_minishell1
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Thu Jan 12 09:21:57 2017 Benjamin GAYMAY
** Last update Thu Jan 19 13:49:12 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "use_array.h"
#include "count.h"
#include "my.h"

char	*find_path(char **envp)
{
  int	i;

  i = 0;
  while (envp[i] != NULL)
    {
      if (my_strncmp(envp[i], "PATH=", 5) == 0)
	return (&envp[i][5]);
      i++;
    }
  return ("\0");
}

char	**create_path(char **envp)
{
  char	*str;
  char	**path;
  int	i;
  int	columns;

  if ((str = find_path(envp)) == NULL)
    return (NULL);
  i = 0;
  if ((path = malloc(sizeof(char*) * (count_path_lines(str) + 1))) == NULL)
    return (NULL);
  while (i < count_path_lines(str))
    {
      columns = count_path_col(str, i);
      if ((path[i] = malloc(sizeof(char) * (columns + 1))) == NULL)
	return (NULL);
      i++;
    }
  add_path_in_array(path, str, count_path_lines(str));
  return (path);
}

char	*find_home(char **envp)
{
  int	i;

  i = 0;
  while (envp[i] != NULL)
    {
      if (my_strncmp(envp[i], "HOME=", 5) == 0)
	return (&envp[i][5]);
      i++;
    }
  my_putstr("cd: No home directory.\n");
  return (NULL);
}

char	*find_oldpwd(char **envp)
{
  int	i;

  i = 0;
  while (envp[i] != NULL)
    {
      if (my_strncmp(envp[i], "OLDPWD=", 7) == 0)
	return (&envp[i][7]);
      i++;
    }
  i = 0;
  while (envp[i] != NULL)
    {
      if (my_strncmp(envp[i], "PWD=", 4) == 0)
	return (&envp[i][4]);
      i++;
    }
  return (NULL);
}
