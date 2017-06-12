/*
** my_put_nbr.c for my_put_nbr in /home/benjamin.g/delivery/CPool_Day03
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Thu Oct  6 09:04:03 2016 Benjamin GAYMAY
** Last update Tue Jan 17 17:01:23 2017 Benjamin GAYMAY
*/

#include "my.h"

int	my_put_nbr(int n)
{
  if (n < 0)
    {
      my_putchar('-');
      n = (n * (-1));
    }
  if ((n >= 0) && (n <= 9))
    {
      my_putchar(n + '0');
    }
  if (n > 9)
    {
      my_put_nbr(n / 10);
      my_put_nbr(n % 10);
    }
  return (0);
}
