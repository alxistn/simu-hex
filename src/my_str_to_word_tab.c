/*
** my_str_to_word_tab.c for in in /home/santin_a/
** 
** Made by alexis santini
** Login   <santin_a@epitech.net>
** 
** Started on  Tue Dec 18 17:12:45 2012 alexis santini
** Last update Sun Apr 28 17:56:38 2013 alexis santini
*/

#include <string.h>
#include <stdlib.h>
#include "header.h"

int     is_caract(char c)
{
  if ((c >= 'a' && c <= '~') || (c >= 'A' && c <= '`') ||
      (c >= '!' && c <= '9' && c == ';' && c == ' ') || c == '\t' || c != '%')
    return (1);
  return (0);
}

int	my_strlen_bis(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] && str[i] != c && str[i] != '\n')
    i++;
  return (i - 2);
}

int	count_nb_word(char *str, char c)
{
  int   i;
  int	nb_word;

  i = 0;
  nb_word = 0;
  while (i < (int)strlen(str))
    {
      if (str[i] && str[i] != c && str[i + 1] == c)
	nb_word++;
      i++;
    }
  return (nb_word + 1);
}

char	*recup_word(char *str, int j, char c)
{
  int	i;
  int	k;
  int	l;
  char	*word;

  i = 0;
  k = 0;
  while (str[j] && k == i)
    {
      l = j;
      while (str[j] && str[j] != c && str[j] != '\n')
	{
	  if (!(is_caract(str[j++])))
	    k++;
	  i++;
	}
    }
  i = 0;
  if (!(word = malloc(sizeof(*word) * (j - l) + 1)))
    xerror(MALLOC_ERR, 0);
  while (l < j && str[l] != c && str[l] != '\n')
    word[i++] = str[l++];
  word[i] = '\0';
  return (word);
}

char	**my_str_to_word_tab(char *str, char c, int ind)
{
  int	i;
  int	j;
  int	nb_word;
  char	**av;

  i = 0;
  j = 0;
  nb_word = count_nb_word(str, c);
  if (!(av = malloc((sizeof(*av) * (nb_word + 1)))))
    xerror(MALLOC_ERR, 0);
  while (str[j])
    {
      if (str[j] != c)
	av[i++] = recup_word(str, j, c);
      while (str[j] && str[j] != c && str[j] != '\n')
	j++;
      while (str[j] && (str[j] == c || str[j] == '\n' || str[j] == ' '))
	j++;
    }
  if (ind)
    free(str);
  av[i] = NULL;
  return (av);
}
