/*
** update.c for  in /home/callew_j/rendu/semestre2/Prog_elem/CPE_2015_Allum1
** 
** Made by julien callewaert
** Login   <callew_j@epitech.net>
** 
** Started on  Tue Jul 12 21:38:22 2016 julien callewaert
** Last update Tue Jul 12 21:38:35 2016 julien callewaert
*/

#include "my.h"

char	**update(char **grid, int line, int nb_matches)
{
  int	j;
  int	find;
  int	cp_find;

  j = 0;
  find = 0;
  while (grid[line][j] != '\0')
    {
      if (grid[line][j] == '|')
	find = j;
      j++;
    }
  cp_find = find;
  while (find > cp_find - nb_matches)
    {
      grid[line][find] = ' ';
      find--;
    }
  return (grid);
}
