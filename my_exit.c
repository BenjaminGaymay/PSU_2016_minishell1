/*
** my_exit.c for minishell1 in /home/benjamin.g/delivery/PSU_2016_minishell1
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Jan 20 12:04:15 2017 Benjamin GAYMAY
** Last update Fri Jan 20 12:06:56 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "use_array.h"
#include "my.h"

char	*my_exit(char **tab)
{
  if (tab[1] == NULL)
    return ("OK");
  else if (tab[1] != NULL && tab[2] == NULL)
    {
      if (my_str_isnum(tab[1]) == 1)
	return ("OK");
    }
  else
    my_putstr("exit: Expression Syntax.\n");
  return ("NO");
}

int	exit_return(char **tab)
{
  int	ret;

  ret = (tab[1] == NULL ? 0 : my_getnbr(tab[1]));
  my_putstr("exit\n");
  free_tab(tab);
  return (ret);
}
