/*
** main.c for main in /home/benjamin.g/delivery/PSU_2016_my_exec
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Wed Jan  4 14:17:31 2017 Benjamin GAYMAY
** Last update Sat Jan 21 14:14:17 2017 Benjamin GAYMAY
*/

#include <signal.h>
#include <stdlib.h>
#include "use_array.h"
#include "minishell1.h"
#include "my.h"

char		**my_get_env(char **envp, int i)
{
  static char	**save_envp;

  if (i == 0)
    save_envp = envp;
  else
    return (save_envp);
  return (NULL);
}

char	**copy_tab(char **envp)
{
  char	**new_env;
  char	*str;
  int	i;

  i = 0;
  while (envp[i] != NULL)
    i++;
  if ((new_env = malloc(sizeof(*new_env) * (i + 1))) == NULL)
    return (NULL);
  new_env[0] = NULL;
  i = 0;
  while (envp[i] != NULL)
    {
      new_env[i] = my_strcpy(str, envp[i]);
      i++;
    }
  new_env[i] = NULL;
  return (new_env);
}

void	my_ctrl_c()
{
  my_putstr("\n$> ");
}

int	main(int ac, char **av, char **envp)
{
  char	**new_env;
  char	**tab;
  int	ret;

  ret = 0;
  signal(2, my_ctrl_c);
  if ((new_env = copy_tab(envp)) == NULL)
    return (ERROR);
  my_get_env(new_env, 0);
  ret = prompt(new_env, ret, tab);
  free_tab(new_env);
  return (ret);
}
