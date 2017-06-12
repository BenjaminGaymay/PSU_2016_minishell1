/*
** parent.c for minishell1 in /home/benjamin.g/delivery/PSU_2016_minishell1
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Jan 13 10:22:47 2017 Benjamin GAYMAY
** Last update Tue Jan 24 23:10:08 2017 Benjamin GAYMAY
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "minishell1.h"
#include "use_array.h"
#include "get_next_line.h"
#include "my_printf.h"
#include "my.h"

char	*search_path(char **path, char **tab, char *command)
{
  int	i;

  i = 1;
  command = my_strcpy(command, tab[0]);
  if (my_strncmp(tab[0], "./", 2) != 0 && access(command, F_OK) != 0)
    {
      free(command);
      command = my_strcat(path[0], tab[0]);
      while (access(command, F_OK) != 0 && path[i] != NULL)
	{
	  free(command);
	  command = my_strcat(path[i], tab[0]);
	  i++;
	}
    }
  if (access(command, F_OK) != 0)
    my_printf("%s: Command not found.\n", tab[0]);
  else if (access(command, X_OK) != 0)
    my_printf("%s: Permission denied.\n", tab[0]);
  if ((access(command, F_OK) != 0) || (access(command, X_OK) != 0))
    {
      free_tab(path);
      return (NULL);
    }
  return (command);
}

int	put_error(int status)
{
  if (status == SEGFAULT)
    {
      my_putstr("Segmentation fault (core dumped)\n");
      return (SEGFAULT);
    }
  else if (status == FLOATING)
    {
      my_putstr("Floating exception (core dumped)\n");
      return (FLOATING);
    }
  else if (status == ABORT)
    {
      my_putstr("Abort (core dumped)\n");
      return (ABORT);
    }
  return (0);
}

int	parent(char **envp, char **tab)
{
  pid_t	child_pid;
  int	status;
  char	**path;
  char	*command;
  int	error;

  path = create_path(envp);
  if ((command = search_path(path, tab, command)) == NULL)
    return (FAILURE);
  free_tab(path);
  if ((child_pid = fork()) == -1)
    return (ERROR);
  if (child_pid != 0)
    {
      status = 0;
      wait(&status);
      free(command);
      if ((error = put_error(status)) != 0)
	return (error);
      else
	return (WEXITSTATUS(status));
    }
  else
    child(envp, command, tab);
}

int	check_tab0(char **envp, char **tab, int ret)
{
  char	*pwd;

  if (my_strcmp(tab[0], "env") == 0)
    ret = aff_array(envp);
  else if (my_strcmp(tab[0], "cd") == 0)
    {
      pwd = getcwd(pwd, 0);
      if ((ret = my_cd(envp, tab)) == 0)
	my_setenv(envp, "OLDPWD", pwd);
    }
  else if (my_strcmp(tab[0], "setenv") == 0)
    {
      ret = FAILURE;
      if (tab[2] != NULL && tab[3] != NULL)
	my_putstr("setenv: Too many arguments.\n");
      else
	ret = my_setenv(envp, tab[1], tab[2]);
    }
  else if (my_strcmp(tab[0], "unsetenv") == 0)
    ret = my_unsetenv(envp, tab);
  else
    ret = parent(envp, tab);
  return (ret);
}

int	prompt(char **envp, int ret, char **tab)
{
  char	*command;

  while (42)
    {
      envp = my_get_env(NULL, 1);
      if (isatty(0) == 1)
	my_printf("$> ");
      if ((command = get_next_line(0)) == NULL)
	{
	  my_putstr(isatty(0) == 1 ? "exit\n" : "\0");
	  return (ret);
	}
      if ((tab = create_tab(command)) == NULL)
	return (ERROR);
      if (my_strcmp(tab[0], "exit") == 0)
	{
	  if (my_strcmp(my_exit(tab), "OK") == 0)
	    return (exit_return(tab));
	  ret = 1;
	}
      else
	ret = check_tab0(envp, tab, ret);
      free_tab(tab);
    }
}
