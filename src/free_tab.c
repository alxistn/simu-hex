/*
** free_tab.c for lem_in in /home/santin_a//Dropbox/lem-in/Uzzicoke/src
** 
** Made by alexis santini
** Login   <santin_a@epitech.net>
** 
** Started on  Fri Apr 26 15:42:41 2013 alexis santini
** Last update Fri Apr 26 15:43:19 2013 alexis santini
*/

#include <stdlib.h>

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}
