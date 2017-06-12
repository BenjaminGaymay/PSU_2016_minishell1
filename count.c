/*
** count.c for count in /home/benjamin.g/delivery/PSU_2016_my_sokoban
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Dec  9 11:42:16 2016 Benjamin GAYMAY
** Last update Tue Jan 17 16:59:24 2017 Benjamin GAYMAY
*/

int	count_col(char *buffer, int i)
{
  int	f;
  int	j;

  j = 0;
  f = 0;
  while (buffer[f] == ' ')
    f++;
  while (i > 0 && buffer[f] != '\0')
    {
      if (buffer[f] == ' ' && buffer[f + 1] != ' ')
	i--;
      f++;
    }
  j = f;
  while (buffer[j] != ' ' && buffer[j] != '\0')
    j++;
  return (j - f);
}

int	count_lines(char *buffer)
{
  int	f;
  int	nb_line;

  f = 0;
  nb_line = 0;
  while (buffer[f] == ' ')
    f++;
  while (buffer[f] != '\0')
    {
      if (buffer[f] == ' ' && buffer[f + 1] != ' ' && buffer[f + 1] != '\0')
	nb_line++;
      f++;
    }
  return (nb_line + 1);
}

int	count_path_col(char *buffer, int i)
{
  int	f;
  int	j;

  j = 0;
  f = 0;
  while (i > 0 && buffer[f] != '\0')
    {
      if (buffer[f] == ':')
	i--;
      f++;
    }
  j = f;
  while (buffer[j] != ':' && buffer[j] != '\0')
    j++;
  return (j - f);
}

int	count_path_lines(char *buffer)
{
  int	f;
  int	nb_line;

  f = 0;
  nb_line = 0;
  while (buffer[f] != '\0')
    {
      if (buffer[f] == ':')
	nb_line++;
      f++;
    }
  return (nb_line + 1);
}
