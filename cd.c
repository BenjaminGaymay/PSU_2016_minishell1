/*
** cd.c for minishell1 in /home/benjamin.g/delivery/PSU_2016_minishell1
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Thu Jan 19 13:03:53 2017 Benjamin GAYMAY
** Last update Mon Jan 23 14:35:56 2017 Benjamin GAYMAY
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "minishell1.h"
#include "my_printf.h"
#include "my.h"

int		check_is_dir(char *path)
{
  struct stat	file;

  lstat(path, &file);
  if (S_ISDIR(file.st_mode) == 1)
    return (SUCCESS);
  return (FAILURE);
}

int	check_access(char *path)
{
  if (access(path, F_OK) == 0)
    {
      if (access(path, R_OK) == 0)
	{
	  if (check_is_dir(path) == FAILURE)
	    {
	      my_printf("%s: Not a directory.\n", path);
	      return (FAILURE);
	    }
	  chdir(path);
	  return (SUCCESS);
	}
      my_printf("%s: Permission denied.\n", path);
      return (FAILURE);
    }
  my_printf("%s: No such file or directory.\n", path);
  return (FAILURE);
}

int	my_cd(char **envp, char **tab)
{
  char	*path;

  if (tab[1] == NULL)
    {
      if ((path = find_home(envp)) == NULL)
	return (FAILURE);
    }
  else if (my_strcmp(tab[1], "-") == 0)
    {
      if ((path = find_oldpwd(envp)) == NULL)
	{
	  my_putstr(": No such file or directory.\n");
	  return (FAILURE);
	}
    }
  else
    path = tab[1];
  return (check_access(path));
}
