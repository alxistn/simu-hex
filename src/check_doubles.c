/*
** check_doubles.c for Lem-in in /home/hardin_t//Dropbox/lem-in/Juif/ERROR_BITCHIZ
** 
** Made by thibault hardin
** Login   <hardin_t@epitech.net>
** 
** Started on  Sun Apr 28 19:56:24 2013 thibault hardin
** Last update Sun Apr 28 23:26:42 2013 thibault hardin
*/

#include <string.h>
#include <stdio.h>

char	**my_str_to_word_tab(char *, char, int);

int	is_tube(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    if (str[i] == '-')
      return (0);
  return (1);
}

int	wordtabcmp(char **tab_a, char **tab_b)
{
  if ((!strcmp(tab_a[0], tab_b[0]) && !strcmp(tab_a[1], tab_b[1])) ||
      (!strcmp(tab_a[0], tab_b[1]) && !strcmp(tab_a[1], tab_b[0])))
    return (0);
  return (1);
}

int	my_tablen(char **tab)
{
  int	i;

  while (tab[i])
    i++;
  return (i);
}

char	**check_doubles(char **tab)
{
  int	i;
  int	j;
  int	k;

  j = -1;
  while (tab[++j])
    if (!is_tube(tab[j]))
      {
	i = j;
	while (tab[++i])
	  if (!is_tube(tab[i]))
	    if (!wordtabcmp(my_str_to_word_tab(tab[j], '-', 0),
			    my_str_to_word_tab(tab[i], '-', 0)))
	      {
		k = i - 1;
		while (tab[++k])
		  tab[k] = tab[k + 1];
	      }
      }
  return (tab);
}
