/*
** my.h for  in /home/callew_j/rendu/semestre2/Prog_elem/CPE_2015_Allum1
**
** Made by julien callewaert
** Login   <callew_j@epitech.net>
**
** Started on  Tue Jul 12 21:42:13 2016 julien callewaert
** Last update Sun Jul 24 23:15:20 2016 
*/

#ifndef MY_H_
# define MY_H_

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define STR_SIZE 1000
# define READ_SIZE 1
# define NB_LINE 6
# define NB_COL 9

typedef struct	s_gnl
{
  int		i;
  int		j;
  int		r;
  int		ct;
  int		cp;
  char		*str;
  int		end_line;
  char		buffer[READ_SIZE + 1];
}		t_gnl;

typedef struct	s_board
{
  int		i;
  int		j;
  int		cp_j;
  int		draw;
  int		nb_line;
  int		nb_max_col;
  int		nb_per_line;
  char		**grid;
}		t_board;

typedef struct	s_ai
{
  int		nb_1;
  int		nb_2;
  int		nb_3;
  int		nb_4;
  int		lines;
  int		take;
  int		sign;
  int		result;
  char		**cp_grid;
}		t_ai;

void		aff(char **grid, int nb_line, int nb_col);
char		**get_board_game_in_a_pretty_frame();
char		*get_next_line(const int fd);
void		my_putchar(char c);
void		my_putstr(char *str);
int		my_getnbr(char *str);
void		my_put_nbr(int nb);
int		make_human_and_ai_play();
int		all_the_errors(char **grid, int *line, int *nb_matches);
int		check_nb_matches(char **grid, int line, int nb_matches);
int		count_nb_matches(char **grid, int line, int nb_col);
int		count_nb_matches_on_this_line(char **grid, int nb_line);
char		**update(char **grid, int line, int nb_matches);
int		art_int(char **grid, int *line, int *nb_matches);
char		**copy_grid(char **cp_grid, char **grid);
char		**take_allum(char **grid, int line, int *take, int sign_max);
void		nb_match_is_greater_than_one(t_ai *intel,
					     int line,
					     int *take,
					     int cp_nb);
void		nb_match_is_one(t_ai *intel, int line, int *take, int cp_nb);
void		remove_matches(t_ai *intel, int line, int *take);
int		checking_before_calcul(char **grid, int *sign);
void		delete_matches(char **grid,
			       int *line,
			       int *nb_matches,
			       int pair_or_not);
int		calcul(t_ai *intel);

#endif /* !MY_H_ */
