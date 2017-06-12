/*
** child.c for minishell1 in /home/benjamin.g/delivery/PSU_2016_minishell1
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Jan 13 15:03:28 2017 Benjamin GAYMAY
** Last update Tue Jan 17 16:58:39 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell1.h"

int	child(char **envp, char *command, char **tab)
{
  execve(command, tab, envp);
  exit(FAILURE);
}
