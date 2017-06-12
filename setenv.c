/*
** setenv.c for minishell1 in /home/benjamin.g/delivery/PSU_2016_minishell1
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Wed Jan 18 12:54:38 2017 Benjamin GAYMAY
** Last update Mon Jan 23 10:29:45 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "minishell1.h"
#include "use_array.h"
#include "my.h"

int	put_newtab(char **envp, char **new_envp, char *new_str, char *s2)
{
  int	i;
  int	found;

  i = 0;
  found = 0;
  while (envp[i] != NULL)
    {
      if ((my_strncmp(new_str, envp[i], my_strlen(new_str)) != 0) ||
	  (found == 1))
	new_envp[i] = envp[i];
      else
	{
	  found = 1;
	  free(envp[i]);
	  new_envp[i] = my_malloc_strcat(new_str, s2);
	}
      i++;
    }
  return (found);
}

int	check_setenv_error(char *s1, char *s2)
{
  int	i;

  i = 0;
  if ((s1[0] < 'A') || (s1[0] > 'Z' && s1[0] < 'a') || (s1[0] > 'z'))
    {
      my_putstr("setenv: Variable name must begin whith a letter.\n");
      return (FAILURE);
    }
  while (s1[i] != '\0')
    {
      if ((s1[i] < '0') ||
	  (s1[i] > '9' && s1[i] < 'A') ||
	  (s1[i] > 'Z' && s1[i] < 'a') ||
	  (s1[i] > 'z'))
	{
	  my_putstr("setenv: Variable name must contain");
	  my_putstr(" alphanumeric characters.\n");
	  return (FAILURE);
	}
      i++;
    }
  return (SUCCESS);
}

int	my_setenv(char **envp, char *s1, char *s2)
{
  char	**new_envp;
  char	*new_str;
  int	i;

  if (s1 != NULL)
    {
      i = 0;
      if (check_setenv_error(s1, s2) == FAILURE)
	return (FAILURE);
      new_str = my_malloc_strcat(s1, "=");
      while (envp[i] != NULL)
	i++;
      if ((new_envp = malloc(sizeof(new_envp) * (i + 2))) == NULL)
	return (ERROR);
      new_envp[0] = NULL;
      if ((put_newtab(envp, new_envp, new_str, (s2 == NULL ? "\0" : s2))) == 0)
	new_envp[i++] = my_malloc_strcat(new_str, (s2 == NULL ? "\0" : s2));
      new_envp[i] = NULL;
      free(new_str);
      my_get_env(new_envp, 0);
    }
  else
    aff_array(envp);
  return (SUCCESS);
}

char	**delete_line(char **envp, char *tmp)
{
  int	f;

  f = 0;
  while (envp[f] != NULL &&
	 my_strncmp(tmp, envp[f], my_strlen(tmp) - 1) != 0)
    f++;
  if (envp[f] != NULL)
    free(envp[f]);
  while (envp[f] != NULL)
    {
      envp[f] = envp[f + 1];
      f++;
    }
  return (envp);
}

int	my_unsetenv(char **envp, char **tab)
{
  char	**new_envp;
  char	*tmp;
  int	i;

  if (tab[1] == NULL)
    my_putstr("unsetenv: Too few arguments.\n");
  else
    {
      i = 1;
      while (tab[i] != NULL)
	{
	  tmp = my_malloc_strcat(tab[i], "=");
	  envp = delete_line(envp, tmp);
	  free(tmp);
	  i++;
	}
      return (SUCCESS);
    }
  return (FAILURE);
}
