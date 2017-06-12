/*
** my_putstr.c for my_putstr in /home/benjamin.g/delivery/CPool_Day04
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Thu Oct  6 15:28:00 2016 Benjamin GAYMAY
** Last update Tue Jan 17 17:01:29 2017 Benjamin GAYMAY
*/

#include <unistd.h>
#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  write(1, str, i);
  return (0);
}
