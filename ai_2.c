/*
** ai_2.c for  in /home/callew_j/rendu/semestre2/Prog_elem/CPE_2015_Allum1
** 
** Made by julien callewaert
** Login   <callew_j@epitech.net>
** 
** Started on  Thu Jul 14 01:51:35 2016 julien callewaert
** Last update Thu Jul 14 11:09:56 2016 julien callewaert
*/

#include "my.h"

char	**copy_grid(char **cp_grid, char **grid)
{
  int	i;
  int	j;

  i = 0;
  while (i < NB_LINE)
    {
      j = 0;
      while (j < NB_COL)
	{
	  cp_grid[i][j] = grid[i][j];
	  j++;
	}
      cp_grid[i][j] = '\0';
      i++;
    }
  return (cp_grid);
}

char	**take_allum(char **grid, int line, int *take, int sign_max)
{
  int	j;
  int	find;

  j = 0;
  find = 0;
  while (grid[line][j] != '\0')
    {
      if (grid[line][j] == '|')
	find = j;
      j++;
    }
  while (*take < sign_max)
    {
      grid[line][find] = ' ';
      find--;
      *take += 1;
    }
  return (grid);
}

void	nb_match_is_greater_than_one(t_ai *intel,
				     int line,
				     int *take,
				     int cp_nb)
{
  int	i;

  i = 1;
  while (cp_nb - (cp_nb - i) <= cp_nb && calcul(intel) != 0)
    {
      intel->cp_grid =
	take_allum(intel->cp_grid, line, take, cp_nb - (cp_nb - i));
      if (line == 2)
	intel->nb_2 = count_nb_matches_on_this_line(intel->cp_grid, line);
      if (line == 3)
	intel->nb_3 = count_nb_matches_on_this_line(intel->cp_grid, line);
      if (line == 4)
	intel->nb_4 = count_nb_matches_on_this_line(intel->cp_grid, line);
      i++;
    }
}

void	nb_match_is_one(t_ai *intel, int line, int *take, int cp_nb)
{
  int	i;

  i = 1;
  while (cp_nb - (cp_nb - i) > 0 && calcul(intel) != 0)
    {
      intel->cp_grid
	= take_allum(intel->cp_grid, line, take, cp_nb - (cp_nb - i));
      if (line == 1)
	intel->nb_1 = count_nb_matches_on_this_line(intel->cp_grid, line);
      if (line == 2)
	intel->nb_2 = count_nb_matches_on_this_line(intel->cp_grid, line);
      if (line == 3)
	intel->nb_3 = count_nb_matches_on_this_line(intel->cp_grid, line);
      if (line == 4)
	intel->nb_4 = count_nb_matches_on_this_line(intel->cp_grid, line);
      i--;
    }
}

void	remove_matches(t_ai *intel, int line, int *take)
{
  int	cp_nb;

  if (line == 1)
    cp_nb = intel->nb_1;
  if (line == 2)
    cp_nb = intel->nb_2;
  if (line == 3)
    cp_nb = intel->nb_3;
  if (line == 4)
    cp_nb = intel->nb_4;
  if (cp_nb > 1)
    nb_match_is_greater_than_one(intel, line, take, cp_nb);
  else if (cp_nb == 1)
    nb_match_is_one(intel, line, take, cp_nb);
}
