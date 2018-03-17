/*
** clear_map.c for lem_in in /home/lecler_k//Dropbox/lem-in/Vieux/ce-Bri
** 
** Made by brice leclercq
** Login   <lecler_k@epitech.net>
** 
** Started on  Sun Apr 28 00:50:25 2013 brice leclercq
** Last update Sun Apr 28 21:44:12 2013 thibault hardin
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define	START	"##start"
#define	END	"##end"
#define CUT	'-'

char	**my_str_to_word_tab(char *, char, int);

int	word_is_ok(char *word)
{
  int	i;
  int	carac;
  int	valid;

  i = 0;
  valid = 0;
  carac = 0;
  if (!strcmp(word, START) || !strcmp(word, END))
    return (1);
  while (word[i])
    {
      if (!isalnum(word[i]) && word[i] != CUT &&
	  word[i] != ' ' && word[i] != '\t')
	return (2);
      if (word[i++] == CUT)
	{
	  if (word[i] && isalnum(word[i]))
	    valid++;
	  carac++;
	}
    }
  if (carac > 1 || (carac == 1 && !valid))
    return (2);
  return (0);
}

char	**clear_map(char **map, char *word)
{
  int	i;
  int	j;

  j = 0;
  while (map[j])
    {
      if ((!strncmp(map[j], word, strlen(word)) && !word_is_ok(map[j])) ||
	  word_is_ok(map[j]) == 2)
	{
	  i = j - 1;
	  while (map[++i])
	    map[i] = map[i + 1];
	}
      else
	j++;
    }
  return (map);
}
