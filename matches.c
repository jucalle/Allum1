/*
** matches.c for  in /home/callew_j/rendu/semestre2/Prog_elem/CPE_2015_Allum1
** 
** Made by julien callewaert
** Login   <callew_j@epitech.net>
** 
** Started on  Tue Jul 12 21:37:53 2016 julien callewaert
** Last update Wed Jul 13 16:17:50 2016 julien callewaert
*/

#include "my.h"

int	check_nb_matches(char **grid, int line, int nb_matches)
{
  int	j;
  int	nb_of_sign;

  j = 0;
  nb_of_sign = 0;
  while (grid[line][j] != '\0')
    {
      if (grid[line][j] == '|')
	nb_of_sign++;
      j++;
    }
  if (nb_of_sign < nb_matches)
    return (1);
  else
    return (0);
}

int	count_nb_matches(char **grid, int nb_line, int nb_col)
{
  int	i;
  int	j;
  int	sign;

  i = 0;
  sign = 0;
  while (i < nb_line)
    {
      j = 0;
      while (j < nb_col)
	{
	  if (grid[i][j] == '|')
	    sign++;
	  j++;
	}
      i++;
    }
  return (sign);
}

int	count_nb_matches_on_this_line(char **grid, int nb_line)
{
  int	j;
  int	sign;

  j = 0;
  sign = 0;
  while (grid[nb_line][j] != '\0')
    {
      if (grid[nb_line][j] == '|')
	sign++;
      j++;
    }
  return (sign);
}
