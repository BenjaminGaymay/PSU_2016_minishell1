/*
** use_array.c for use_array in /home/benjamin.g/delivery/CPE_2016_BSQ
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Dec  6 13:41:33 2016 Benjamin GAYMAY
** Last update Wed Jan 18 11:43:09 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "count.h"
#include "my.h"

void	add_in_array(char **array, char *buffer, int line)
{
  int	i;
  int	f;
  int	g;

  i = 0;
  f = 0;
  g = 0;
  while (i < line)
    {
      while (f < count_col(buffer, i))
	{
	  while (buffer[g] == ' ')
	    g++;
	  array[i][f] = buffer[g];
	  g++;
	  f++;
	}
      array[i][f] = '\0';
      f = 0;
      g++;
      i++;
    }
  array[i] = NULL;
}

void	add_path_in_array(char **array, char *buffer, int line)
{
  int	i;
  int	f;
  int	g;

  i = 0;
  f = 0;
  g = 0;
  while (i < line)
    {
      while (f < count_path_col(buffer, i))
	{
	  array[i][f] = buffer[g];
	  g++;
	  f++;
	}
      array[i][f] = '\0';
      f = 0;
      g++;
      i++;
    }
  array[i] = NULL;
}

int	aff_array(char **array)
{
  int	i;

  i = 0;
  while (array[i] != NULL)
    {
      my_putstr(array[i++]);
      my_putchar('\n');
    }
  return (0);
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    free(tab[i++]);
  free(tab);
}

char	**create_tab(char *command)
{
  int	i;
  int	columns;
  char	**tab;

  i = 0;
  while (command[i] != '\0')
    {
      if (command[i] == '\t')
	command[i] = ' ';
      i++;
    }
  if ((tab = malloc(sizeof(char *) * (count_lines(command) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < count_lines(command))
    {
      columns = count_col(command, i);
      if ((tab[i] = malloc(sizeof(char) * (columns + 1))) == NULL)
	return (NULL);
      i++;
    }
  add_in_array(tab, command, count_lines(command));
  free(command);
  return (tab);
}
