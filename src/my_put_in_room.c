/*
** my_put_in_room.c for lem_in in /home/santin_a//Dropbox/lem-in/Uzzicoke/src
** 
** Made by alexis santini
** Login   <santin_a@epitech.net>
** 
** Started on  Sun Apr 28 00:43:39 2013 alexis santini
** Last update Sun Apr 28 23:08:35 2013 alexis santini
*/

#include <string.h>
#include <stdlib.h>
#include "header.h"

void		init_elem(t_room **new_elem, char *name, char *str)
{
  if (!strcmp(str, START))
    (*new_elem)->start = 1;
  else if (!strcmp(str, OTHER))
    (*new_elem)->start = 0;
  else if (!strcmp(str, END))
    (*new_elem)->end = 1;
  else if (!strcmp(str, OTHER))
    (*new_elem)->end = 0;
  (*new_elem)->id_room = name;
  (*new_elem)->occup = 0;
  (*new_elem)->way = 0;
  (*new_elem)->set = 0;
  (*new_elem)->nb_adj_room = 0;
  (*new_elem)->adj_room = NULL;
  (*new_elem)->next_end = NULL;
}

int		my_put_in_room(t_room **rooms, char *name, char *str)
{
  t_room	*new_elem;
  t_room	*tmp;

  if (!(new_elem = malloc(sizeof(*new_elem))))
    xerror(MALLOC_ERR, 0);
  init_elem(&new_elem, name, str);
  if (*rooms == NULL)
    {
      new_elem->next = new_elem;
      *rooms = new_elem;
      return (0);
    }
  tmp = *rooms;
  while (tmp->next_end != NULL)
    tmp = tmp->next_end;
  new_elem->next = *rooms;
  tmp->next_end = new_elem;
  tmp->next = new_elem;
  return (0);
}

int		my_put_in_adj_room(t_adj_room **adj_room, t_room *room)
{
  t_adj_room	*new_elem;
  t_adj_room	*tmp;

  if (!(new_elem = malloc(sizeof(*new_elem))))
    xerror(MALLOC_ERR, 0);
  new_elem->next_room = room;
  new_elem->next = NULL;
  if (*adj_room == NULL)
    {
      *adj_room = new_elem;
      return (0);
    }
  tmp = *adj_room;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_elem;
  return (0);
}

int		my_put_in_save(t_save **save, t_adj_room **adj_room)
{
  t_save	*new_elem;
  t_save	*tmp;

  if (!(new_elem = malloc(sizeof(*new_elem))))
    xerror(MALLOC_ERR, 0);
  new_elem->save = adj_room;
  new_elem->next = NULL;
  if (*save == NULL)
    {
      *save = new_elem;
      return (0);
    }
  tmp = *save;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_elem;
  return (0);
}
