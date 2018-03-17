/*
** error.c for lem_in in /home/santin_a//Dropbox/lem-in/src
** 
** Made by alexis santini
** Login   <santin_a@epitech.net>
** 
** Started on  Fri Apr 26 14:52:46 2013 alexis santini
** Last update Sun Apr 28 15:28:00 2013 alexis santini
*/

#include <stdlib.h>
#include <stdio.h>
#include "header.h"

void	xerror(char *err, int x)
{
  if (!x)
    fprintf(stderr, "%s\n", err);
  else
    fprintf(stderr, INVALID_ROOM(err));
  exit(EXIT_FAILURE);
}
