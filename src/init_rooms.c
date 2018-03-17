/*
** parsing_data.c for lem_in in /home/santin_a//Dropbox/lem-in/Uzzicoke/src
** 
** Made by alexis santini
** Login   <santin_a@epitech.net>
** 
** Started on  Sat Apr 27 22:32:57 2013 alexis santini
** Last update Sun Apr 28 20:39:06 2013 alexis santini
*/

#include <stdlib.h>
#include <string.h>
#include "header.h"

void		setting_graph(t_graph **graph, char *str)
{
  (*graph)->nb_ant = atoi(str);
  (*graph)->nb_room = 0;
  (*graph)->nb_path = 0;
  (*graph)->rooms = NULL;
}

char		*rooms_name(char *str)
{
  int		i;
  char		*name;

  i = 0;
  while (str[i] != ' ' && str[i] != '\t')
    i++;
  if (!(name = malloc(i + 1)))
    xerror(MALLOC_ERR, 0);
  i = 0;
  while (*str != ' ' && *str != '\t')
    name[i++] = *str++;
  name[i] = '\0';
  return (name);
}

int		init_rooms(char **data)
{
  int		i;
  t_graph	*graph;

  i = 0;
  if (!(graph = malloc(sizeof(*graph))))
    xerror(MALLOC_ERR, 0);
  setting_graph(&graph, data[i]);
  while (data[++i])
    {
      if (is(data[i], ROOM))
	{
	  if (!strcmp(data[i - 1], START))
	    my_put_in_room(&graph->rooms, rooms_name(data[i]), START);
	  else if (!strcmp(data[i - 1], END))
	    my_put_in_room(&graph->rooms, rooms_name(data[i]), END);
	  else
	    my_put_in_room(&graph->rooms, rooms_name(data[i]), OTHER);
	  graph->nb_room++;
	}
      if (is(data[i], PATH))
	graph->nb_path++;
    }
  complete_rooms(data, &graph);
  push_ant(graph);
  return (0);
}
