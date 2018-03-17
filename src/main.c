/*
** main.c for lem_in in /home/santin_a//Dropbox/lem-in/src
** 
** Made by alexis santini
** Login   <santin_a@epitech.net>
** 
** Started on  Fri Apr 26 14:26:54 2013 alexis santini
** Last update Sun Apr 28 23:27:33 2013 thibault hardin
*/

#include <unistd.h>
#include <stdlib.h>
#include "header.h"

char	**clean_param(char **tab)
{
  tab = clear_map(tab, "#");
  tab = check_doubles(tab);
  check_map(tab);
  if (my_tablen(tab) < 6 || !no_tubes(tab) || !no_rooms(tab))
    xerror(MAP_ERR, 0);
  return (tab);
}

int	recover_data(void)
{
  int	nb_read;
  char	**data;
  char	buff[BUFF_SZ + 1];

  if ((nb_read = read(0, buff, BUFF_SZ)) == -1)
    xerror(READ_ERR, 0);
  if (nb_read == BUFF_SZ)
    xerror(SZ_MAP_ERR, 0);
  buff[nb_read] = '\0';
  data = my_str_to_word_tab(buff, '\n', DONT_FREE);
  data = clean_param(data);
  init_rooms(data);
  free_tab(data);
  return (0);
}

int	main(void)
{
  recover_data();
  return (0);
}
