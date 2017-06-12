/*
** minishell1.h for minishell1 in /home/benjamin.g/delivery/PSU_2016_minishell1
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Jan  6 16:15:48 2017 Benjamin GAYMAY
** Last update Fri Jan 20 12:07:21 2017 Benjamin GAYMAY
*/

#ifndef MINISHELL1_H_
# define MINISHELL1_H_

# define SUCCESS  0
# define FAILURE  1
# define ERROR    84
# define ABORT    134
# define FLOATING 136
# define SEGFAULT 139

int	prompt(char **envp, int ret, char **tab);
int	child(char **envp, char *command, char **tab);
int	my_cd(char **envp, char **tab);
char	**create_path(char **envp);
char	*find_path(char **envp);
char	*find_home(char **envp);
char	*find_oldpwd(char **envp);
char	**my_get_env(char **envp, int i);
int	my_setenv(char **envp, char *s1, char *s2);
int	my_unsetenv(char **envp, char **tab);
char	*my_exit(char **tab);
int	exit_return(char **tab);

#endif /* !MINISHELL1_H_ */
