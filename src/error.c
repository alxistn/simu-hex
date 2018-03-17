/*
** error.c for lem_in in /home/lecler_k//Dropbox/lem-in/Vieux
** 
** Made by brice leclercq
** Login   <lecler_k@epitech.net>
** 
** Started on  Sat Apr 27 23:35:31 2013 brice leclercq
** Last update Sun Apr 28 23:26:15 2013 thibault hardin
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

int	no_tubes(char **tab)
{
  int	i;
  int	j;
  int	ok;

  i = -1;
  ok = 0;
  while (tab[++i])
    {
      j = -1;
      while (tab[i][++j])
	if (tab[i][j] == '-')
	  ok++;
    }
  return (ok);
}

int	no_rooms(char **tab)
{
  int	i;
  int	j;
  int	num;

  i = -1;
  num = 0;
  while (tab[++i])
    {
      j = -1;
      while (tab[i][++j])
	{
	  if (isalnum(tab[i][j]) || tab[i][j] == ' '
	      || tab[i][j] == '\t' || tab[i][j] == '#' || tab[i][j] == '-')
	    num++;
	  else
	    {
	      fprintf(stderr, INVALID_LIGN, tab[j]);
	      exit(EXIT_FAILURE);
	    }
	}
    }
  return (num);
}

void	check_map(char **tab)
{
  int	i;
  int	start;
  int	end;

  i = 0;
  start = 0;
  end = 0;
  if (tab[i] == NULL)
    xerror(ERROR_MAP, 0);
  while (tab[0][i])
    if (!isdigit(tab[0][i++]))
      xerror(ANT_ERR, 0);
  i = -1;
  while (tab[++i])
    {
      if (!(strcmp(tab[i], "##start")))
	start++;
      if (!(strcmp(tab[i], "##end")))
	end++;
    }
  if (start != 1 || end != 1)
    xerror(NEED_EXITS, 0);
}
