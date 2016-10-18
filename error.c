/*
** error.c for  in /home/callew_j/rendu/semestre2/Prog_elem/CPE_2015_Allum1
**
** Made by julien callewaert
** Login   <callew_j@epitech.net>
**
** Started on  Tue Jul 12 21:38:58 2016 julien callewaert
** Last update Sun Jul 24 11:16:24 2016 
*/

#include "my.h"

int	check_line(char **grid, int line)
{
  int	nb_matches;
  int	j;

  j = 0;
  nb_matches = 0;
  while (grid[line][j] != '\0')
    {
      if (grid[line][j] == '|')
	nb_matches++;
      j++;
    }
  if (nb_matches == 0)
    return (1);
  else
    return (0);
}

int	lines(char **grid, int *line, int check_l)
{
  while ((*line = my_getnbr(get_next_line(0))) <= 0
	 || *line > 4 || (check_l = check_line(grid, *line)) == 1)
    {
      if (*line == -2)
	return (-1);
      if (*line <= -1)
	my_putstr("Error: invalid input (positive number expected)\n");
      else if (check_l == 1)
	my_putstr("Error: this line is empty\n");
      else
	my_putstr("Error: this line is out of range\n");
      my_putstr("Line: ");
    }
  return (0);
}

int	matches(char **grid, int *line, int *nb_matches, int check_m)
{
  my_putstr("Matches: ");
  while ((*nb_matches = my_getnbr(get_next_line(0))) <= 0
  	 || (check_m = check_nb_matches(grid, *line, *nb_matches)) == 1)
    {
      if (*nb_matches == -2)
	return (-1);
      if (*nb_matches == 0)
	my_putstr("Error: you have to remove at least one match\n");
      else if (*nb_matches <= -1)
	my_putstr("Error: invalid input (positive number expected)\n");
      else if (check_m == 1)
	my_putstr("Error: not enough matches on this line\n");
      my_putstr("Line: ");
      if (lines(grid, line, 0) == -1)
	return (-1);
      my_putstr("Matches: ");
    }
  return (0);
}

int	all_the_errors(char **grid, int *line, int *nb_matches)
{
  int	check_l;
  int	check_m;

  check_l = 0;
  check_m = 0;
  if (lines(grid, line, check_l) == -1)
    return (-1);
  if (matches(grid, line, nb_matches, check_m) == -1)
    return (-1);
  return (0);
}
