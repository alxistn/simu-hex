/*
** set_way.c for lem_in in /home/santin_a//Dropbox/lem-in/Uzzicoke/src
** 
** Made by alexis santini
** Login   <santin_a@epitech.net>
** 
** Started on  Sun Apr 28 20:36:34 2013 alexis santini
** Last update Sun Apr 28 23:39:23 2013 thibault hardin
*/

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int		g_i = 0;

void		mark_adj_room(t_adj_room **adj_room)
{
  t_adj_room	*tmp;
  int		i;

  i = 0;
  g_i++;
  tmp = *adj_room;
  while (tmp != NULL)
    {
      i++;
      if (!tmp->next_room->way)
	tmp->next_room->way = g_i;
      tmp = tmp->next;
    }
  if (!i)
    xerror(ISO_END, 0);
}

int		not_yet(t_room *tmp)
{
  while (!tmp->start)
    tmp = tmp->next;
  if (!tmp->way)
    return (1);
  return (0);
}

int		set_way(t_room **rooms)
{
  t_room	*tmp;

  tmp = *rooms;
  if (g_i == 0)
    while (!tmp->end)
      tmp = tmp->next;
  else
    {
      while (tmp->way != g_i)
	tmp = tmp->next_end;
    }
  mark_adj_room(&tmp->adj_room);
  if (not_yet(*rooms))
    set_way(rooms);
  return (0);
}

void		show_way(t_room *tmp)
{
  while (tmp != NULL)
    {
      printf("%s : %d\n", tmp->id_room, tmp->way);
      tmp = tmp->next_end;
    }
}

int		push_ant(t_graph *graph)
{
  set_way(&graph->rooms);
  show_way(graph->rooms);
  return (0);
}
