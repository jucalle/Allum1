/*
** aff.c for  in /home/callew_j/rendu/semestre2/Prog_elem/CPE_2015_Allum1
** 
** Made by julien callewaert
** Login   <callew_j@epitech.net>
** 
** Started on  Tue Jul 12 21:47:26 2016 julien callewaert
** Last update Tue Jul 12 21:47:38 2016 julien callewaert
*/

#include "my.h"

void	aff(char **grid, int nb_line, int nb_col)
{
  int	i;
  int	j;

  i = 0;
  while (i < nb_line)
    {
      j = 0;
      while (j < nb_col)
	{
	  my_putchar(grid[i][j]);
	  j++;
	}
      my_putchar('\n');
      i++;
    }
}
