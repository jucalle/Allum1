/*
** core.c for  in /home/callew_j/rendu/semestre2/Prog_elem/CPE_2015_Allum1
** 
** Made by julien callewaert
** Login   <callew_j@epitech.net>
** 
** Started on  Tue Jul 12 21:35:27 2016 julien callewaert
** Last update Mon Jul 18 13:30:17 2016 julien callewaert
*/

#include "my.h"

int	play(char **grid, int *line, int *nb_matches, int player)
{
  if (player % 2 == 0)
    {
      my_putstr("Your turn:\n");
      my_putstr("Line: ");
      if (all_the_errors(grid, line, nb_matches) == -1)
	return (-1);
    }
  else
    {
      my_putstr("AI's turn...\n");
      if (art_int(grid, line, nb_matches) == -1)
	return (-1);
    }
  if (player % 2 == 0)
    my_putstr("Player removed ");
  else
    my_putstr("AI removed ");
  return (0);
}

char	**update_board(char **grid, int line, int nb_matches, int *add_matches)
{
  my_put_nbr(nb_matches);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putchar('\n');
  grid = update(grid, line, nb_matches);
  *add_matches += nb_matches;
  aff(grid, NB_LINE, NB_COL);
  return (grid);
}

void	lose_or_win(int player)
{
  if ((player - 1) % 2 == 0)
    my_putstr("You lost, too bad..\n");
  else
    my_putstr("I lost.. snif.. but I'll get you next time!!\n");
}

void	init_my_values(int *line,
		       int *player,
		       int *nb_matches,
		       int *add_matches)
{
  *line = 0;
  *player = 0;
  *nb_matches = 0;
  *add_matches = 0;
}

int	make_human_and_ai_play()
{
  int	line;
  int	player;
  int	add_matches;
  int	nb_matches;
  int	nb_total_matches;
  char	**grid;

  init_my_values(&line, &player, &nb_matches, &add_matches);
  if ((grid = get_board_game_in_a_pretty_frame()) == NULL)
    return (-1);
  nb_total_matches = count_nb_matches(grid, NB_LINE, NB_COL);
  aff(grid, NB_LINE, NB_COL);
  my_putchar('\n');
  while (add_matches < nb_total_matches)
    {
      if (play(grid, &line, &nb_matches, player) == -1)
	return (-1);
      grid = update_board(grid, line, nb_matches, &add_matches);
      if (nb_total_matches - add_matches >= 1)
	my_putchar('\n');
      player++;
     }
  lose_or_win(player);
  return (0);
}
