/*
** my.h for my in /home/benjamin.g/save/nouveau_projet/include
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Sun Nov 20 13:42:46 2016 Benjamin GAYMAY
** Last update Tue Jan 24 23:09:57 2017 Benjamin GAYMAY
*/

#ifndef MY_H_
# define MY_H_

/*
** libmy.a
*/
void	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_putstr(char *str);
int	my_puterror(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
char	*my_strcat(char *dest, char *src);
char	*my_malloc_strcat(char *dest, char *src);
char	*my_revstr(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strcpy(char *s1, char *s2);
int	my_str_isnum(char *str);

#endif /* !MY_H_ */
