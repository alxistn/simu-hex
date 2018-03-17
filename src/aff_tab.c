/*
** aff_tab.c for lem_in in /home/santin_a//Dropbox/lem-in/Uzzicoke/src
** 
** Made by alexis santini
** Login   <santin_a@epitech.net>
** 
** Started on  Fri Apr 26 15:02:51 2013 alexis santini
** Last update Fri Apr 26 15:40:51 2013 alexis santini
*/

#include <stdio.h>

void	aff_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    puts(tab[i++]);
}
