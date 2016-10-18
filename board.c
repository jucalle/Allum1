/*
** board.c for  in /home/callew_j/rendu/semestre2/Prog_elem/CPE_2015_Allum1
** 
** Made by julien callewaert
** Login   <callew_j@epitech.net>
** 
** Started on  Tue Jul 12 21:44:19 2016 julien callewaert
** Last update Mon Jul 18 13:29:48 2016 julien callewaert
*/

#include "my.h"

void	get_board_game_in_a_pretty_frame2(t_board *game)
{
  game->cp_j = game->j;
  if (game->i == 0 || game->i == game->nb_line - 1)
    game->grid[game->i][game->cp_j] = '*';
  else
    {
      if (game->j == 0 || game->j == game->nb_max_col - 1)
	game->grid[game->i][game->cp_j] = '*';
      else if (game->i > 0)
	{
	  if (game->j < (game->nb_max_col - (game->nb_line - 1)) - (game->i - 1))
	    game->grid[game->i][game->cp_j] = ' ';
	  if (game->j == (game->nb_max_col - (game->nb_line - 1)) - (game->i - 1))
	    {
	      while (game->draw < game->nb_per_line)
		{
		  game->grid[game->i][game->cp_j] = '|';
		  game->cp_j++;
		  game->draw++;
		}
	    }
	  if (game->j > (game->nb_max_col -
			 (game->nb_line - 1)) - game->i + game->draw)
	    game->grid[game->i][game->cp_j] = ' ';
	}
    }
}

int	m_get_board_game(t_board *game)
{
  int	i;

  i = 0;
  if ((game->grid = malloc(sizeof(char*) * game->nb_line)) == NULL)
    return (-1);
  while (i < game->nb_line)
    {
      if ((game->grid[i] = malloc(sizeof(char)
				  * game->nb_line * game->nb_max_col)) == NULL)
	return (-1);
      i++;
    }
  return (0);
}

char		**get_board_game_in_a_pretty_frame()
{
  t_board	game;

  game.i = 0;
  game.nb_line = 6;
  game.nb_max_col = (game.nb_line - 2) * 2 + 1;
  game.nb_per_line = 1;
  if (m_get_board_game(&game) != 0)
    return (NULL);
  while (game.i < game.nb_line)
    {
      game.j = 0;
      game.draw = 0;
      while (game.j < game.nb_max_col)
	{
	  get_board_game_in_a_pretty_frame2(&game);
	  game.j++;
	}
      if (game.i > 0)
	game.nb_per_line += 2;
      game.grid[game.i][game.j] = '\0';
      game.i++;
    }
  return (game.grid);
}
