/*
** my_str_isnum.c for minishell1 in /home/benjamin.g/delivery/PSU_2016_minishell1
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Jan 20 10:43:01 2017 Benjamin GAYMAY
** Last update Fri Jan 20 11:55:44 2017 Benjamin GAYMAY
*/

#include "my.h"

void	check_exit_error(char *str)
{
  if (str[0] == '-' && str[0] != '\0')
    my_putstr("exit: Badly formed number.\n");
  else
    {
      if ((str[0] >= '0') && (str[0] <= '9'))
	my_putstr("exit: Badly formed number.\n");
      else
	my_putstr("exit: Expression Syntax.\n");
    }
}

int	my_str_isnum(char *str)
{
  int	i;
  int	f;

  i = 0;
  f = 0;
  if (str[i] == '-' && str[i] != '\0')
    i++;
  while (str[i] != '\0')
    {
      if ((str[i] < '0') || (str[i] > '9'))
	f++;
      i++;
    }
  if (f != 0)
    check_exit_error(str);
  return (f != 0 ? 0 : 1);
}
