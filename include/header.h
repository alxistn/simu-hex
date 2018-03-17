/*
** header.h for lem_in in /home/santin_a//Dropbox/lem-in/src
** 
** Made by alexis santini
** Login   <santin_a@epitech.net>
** 
** Started on  Fri Apr 26 14:34:53 2013 alexis santini
** Last update Sun Apr 28 23:39:46 2013 thibault hardin
*/

#ifndef HEADER_H_
# define HEADER_H_

# ifndef MACRO_ERR_H_
#  define MACRO_ERR_H_

#  define MALLOC_ERR		"Error: Syscall malloc has failed."
#  define READ_ERR		"Error: Syscall read has failed."
#  define MAP_ERR		"Error: Your map is invalid.\n"
#  define ERROR_MAP		"Error: Your map is empty\n"
#  define SZ_MAP_ERR		"Error: Too much informations.\n"
#  define ANT_ERR		"Error: You must enter a number of ants"
#  define ISO_END		"The exit is not accessible.\n"
#  define INVALID_LIGN		"Lign: \'%s\' is invalid.\n"
#  define NEED_EXITS		"Need an entrance and an exit in the parameters.\n"
#  define INVALID_ROOM(x)	"Error: room: \'%s\' does not exist.\n", x

# endif	/* !MACRO_ERR_H_ */

# ifndef MACRO_H_
#  define MACRO_H_

enum {ROOM, PATH};

#  define BUFF_SZ	4096
#  define FREE		1
#  define DONT_FREE	0
#  define START		"##start"
#  define END		"##end"
#  define OTHER		"other"
#  define CUT		'-'

# endif /* !MACRO_H_ */

# ifndef DATA_STRUCT_H_
#  define DATA_STRUCT_H_

typedef struct		s_adj_room
{
  struct s_room		*next_room;
  struct s_adj_room	*next;
}			t_adj_room;

typedef struct		s_save
{
  t_adj_room		**save;
  struct s_save		*next;
}			t_save;

typedef struct		s_room
{
  char			*id_room;
  int			nb_adj_room;
  int			start;
  int			end;
  int			occup;
  int			way;
  int			set;
  t_adj_room		*adj_room;
  struct s_room		*next;
  struct s_room		*next_end;
}			t_room;

typedef struct		s_graph
{
  int			nb_room;
  int			nb_path;
  int			nb_ant;
  struct s_room		*rooms;
}			t_graph;

# endif /* !DATA_STRUC_H_ */

# ifndef FUNCTION_PROTOTYPES_H_
#  define FUNCTION_PROTOTYPES_H_

void	free_tab(char **);
void	aff_tab(char **);
void	xerror(char *, int);

int	init_rooms(char **);
int	my_put_in_room(t_room **, char *, char *);
int	my_put_in_save(t_save **, t_adj_room **);
int	my_put_in_adj_room(t_adj_room **, t_room *);
int	is(char *, int);
int	complete_rooms(char **, t_graph **);
int	push_ant(t_graph *graph);
int	no_rooms(char **);
int	no_tubes(char **);
char	**check_doubles(char **);
char	**clear_map(char **, char *);
char	**my_str_to_word_tab(char *, char, int);
void	check_map(char **);
int	my_tablen(char **);

char	**my_str_to_word_tab(char *, char, int);
char	**clear_map(char **, char *);

# endif /* !FUNCTION_PROTOTYPES_H_ */

#endif /* !HEADER_H_ */
