/*
** my_strcat.c for strcat in /home/benjamin.g/delivery/CPool_Day07/lib/my
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Oct 11 13:10:25 2016 Benjamin GAYMAY
** Last update Wed Jan 18 15:24:15 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcpy(char *s1, char *s2)
{
  int	i;

  if ((s1 = malloc(sizeof(char) * (my_strlen(s2) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (s2[i] != '\0')
    {
      s1[i] = s2[i];
      i++;
    }
  s1[i] = '\0';
  return (s1);
}

char	*my_malloc_strcat(char *dest, char *src)
{
  int	i;
  int	f;
  char	*new;

  i = my_strlen(dest) + my_strlen(src);
  f = 0;
  if ((new = malloc(sizeof(*new) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  new[0] = '\0';
  while (dest[i] != '\0')
    {
      new[i] = dest[i];
      i++;
    }
  while (src[f] != '\0')
    {
      new[i] = src[f];
      i++;
      f++;
    }
  new[i] = '\0';
  return (new);
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	f;
  char	*new;

  i = my_strlen(dest) + my_strlen(src);
  f = 0;
  if ((new = malloc(sizeof(*new) * (i + 2))) == NULL)
    return (NULL);
  i = 0;
  new[0] = '\0';
  while (dest[i] != '\0')
    {
      new[i] = dest[i];
      i++;
    }
  new[i] = '/';
  i++;
  while (src[f] != '\0')
    {
      new[i] = src[f];
      i++;
      f++;
    }
  new[i] = '\0';
  return (new);
}
