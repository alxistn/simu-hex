/*
** complete_rooms.c for lem_in in /home/santin_a//Dropbox/lem-in/Uzzicoke
** 
** Made by alexis santini
** Login   <santin_a@epitech.net>
** 
** Started on  Sun Apr 28 02:51:37 2013 alexis santini
** Last update Sun Apr 28 19:49:12 2013 alexis santini
*/

#include <string.h>
#include "header.h"

int		update_room(t_room **rooms, char **path, int nb_room)
{
  t_room	*tmp;
  t_room	*save;

  tmp = *rooms;
  while (nb_room && strcmp(tmp->id_room, path[1]))
    {
      tmp = tmp->next;
      nb_room--;
    }
  if (!nb_room)
    xerror(path[1], 1);
  save = tmp;
  while (strcmp(tmp->id_room, path[0]))
    tmp = tmp->next;
  my_put_in_adj_room(&tmp->adj_room, save);
  save = tmp;
  while (strcmp(tmp->id_room, path[1]))
    tmp = tmp->next;
  my_put_in_adj_room(&tmp->adj_room, save);
  return (0);
}

int		complete_rooms(char **data, t_graph **graph)
{
  int		i;
  char		**path;

  i = 0;
  while (is(data[i], ROOM) || data[i][0] == '#')
    i++;
  while (data[i])
    {
      path = my_str_to_word_tab(data[i], '-', DONT_FREE);
      update_room(&(*graph)->rooms, path, (*graph)->nb_room);
      i++;
    }
  return (0);
}
