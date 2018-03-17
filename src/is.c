/*
** is.c for lem_in in /home/santin_a//Dropbox/lem-in/Uzzicoke/src
** 
** Made by alexis santini
** Login   <santin_a@epitech.net>
** 
** Started on  Sun Apr 28 02:50:03 2013 alexis santini
** Last update Sun Apr 28 15:01:51 2013 alexis santini
*/

#include <ctype.h>
#include "header.h"

int	is(char *str, int ind)
{
  while (*str)
    {
      if (ind == ROOM)
	{
	  if (!isalnum(*str) && *str != ' ')
	    return (0);
	}
      else
	if (ind == PATH)
	  {
	    if (!isalnum(*str) && *str != '-')
	      return (0);
	  }
      str++;
    }
  return (1);
}
