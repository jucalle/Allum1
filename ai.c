/*
** ai.c for  in /home/callew_j/rendu/semestre2/Prog_elem/CPE_2015_Allum1
** 
** Made by julien callewaert
** Login   <callew_j@epitech.net>
** 
** Started on  Tue Jul 12 22:37:22 2016 julien callewaert
** Last update Thu Jul 14 16:16:26 2016 julien callewaert
*/

#include "my.h"

int	calcul(t_ai *intel)
{
  int	binary_calc;

  binary_calc = intel->nb_1 ^ intel->nb_2 ^ intel->nb_3 ^ intel->nb_4;
  return (binary_calc);
}

void	change_all_values(char **grid, t_ai *intel)
{
  intel->cp_grid = copy_grid(intel->cp_grid, grid);
  intel->nb_1 = count_nb_matches_on_this_line(intel->cp_grid, 1);
  intel->nb_2 = count_nb_matches_on_this_line(intel->cp_grid, 2);
  intel->nb_3 = count_nb_matches_on_this_line(intel->cp_grid, 3);
  intel->nb_4 = count_nb_matches_on_this_line(intel->cp_grid, 4);
}

int	operations_to_win(char **grid, int *line, int *nb_matches, t_ai *intel)
{
  if ((intel->result = checking_before_calcul(grid, &intel->sign)) == 1)
    {
      while (calcul(intel) != 0)
	{
	  remove_matches(intel, intel->lines, &intel->take);
	  if (calcul(intel) != 0)
	    change_all_values(grid, intel);
	  else
	    {
	      *line = intel->lines;
	      *nb_matches = intel->take;
	    }
	  intel->take = 0;
	  intel->lines++;
	  if (intel->lines > 4)
	    intel->lines = 1;
	}
    }
  else if (intel->result == -1)
    return (-1);
  else
    delete_matches(grid, line, nb_matches, intel->sign);
  return (0);
}

int	init_ai(t_ai *intel)
{
  int	i;

  i = 0;
  intel->nb_1 = 0;
  intel->nb_2 = 0;
  intel->nb_3 = 0;
  intel->nb_4 = 0;
  intel->lines = 1;
  intel->take = 0;
  intel->sign = 0;
  intel->result = 0;
  if ((intel->cp_grid = malloc(sizeof(char*) * NB_LINE)) == NULL)
    return (-1);
  while (i < NB_LINE)
    {
      if ((intel->cp_grid[i]
	   = malloc(sizeof(char) * NB_LINE * NB_COL)) == NULL)
	return (-1);
      i++;
    }
  return (0);
}

int	art_int(char **grid, int *line, int *nb_matches)
{
  int	i;
  t_ai	intel;

  i = 1;
  if (init_ai(&intel) == -1)
    return (-1);
  intel.cp_grid = copy_grid(intel.cp_grid, grid);
  while (i <= 4)
    {
      if (i == 1)
	intel.nb_1 = count_nb_matches_on_this_line(grid, i);
      if (i == 2)
	intel.nb_2 = count_nb_matches_on_this_line(grid, i);
      if (i == 3)
	intel.nb_3 = count_nb_matches_on_this_line(grid, i);
      if (i == 4)
	intel.nb_4 = count_nb_matches_on_this_line(grid, i);
      i++;
    }
  if (operations_to_win(grid, line, nb_matches, &intel) == -1)
    return (-1);
  return (0);
}
