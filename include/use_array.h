/*
** use_array.h for use_array in /home/benjamin.g/delivery/PSU_2016_my_sokoban
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Fri Dec  9 11:34:10 2016 Benjamin GAYMAY
** Last update Wed Jan 18 11:42:49 2017 Benjamin GAYMAY
*/

#ifndef USE_ARRAY_H_
# define USE_ARRAY_H_

void	add_in_array(char **array, char *buffer, int line);
void	add_path_in_array(char **array, char *buffer, int line);
int	aff_array(char **array);
void	free_tab(char **tab);
char	**create_tab(char *command);

#endif /* !USE_ARRAY_H_ */
