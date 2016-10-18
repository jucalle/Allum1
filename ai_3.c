/*
** ai_3.c for  in /home/callew_j/rendu/semestre2/Prog_elem/CPE_2015_Allum1
** 
** Made by julien callewaert
** Login   <callew_j@epitech.net>
** 
** Started on  Thu Jul 14 01:58:39 2016 julien callewaert
** Last update Thu Jul 14 12:18:07 2016 julien callewaert
*/

#include "my.h"

int	*loop_of_checking_before_calcul(char **grid, int *sign)
{
  int	i;
  int	j;
  int	k;
  int	*check;

  i = 1;
  k = 0;
  if ((check = malloc(sizeof(int) * NB_LINE)) == NULL)
    return (NULL);
  while (i < NB_LINE)
    {
      j = 0;
      *sign = 0;
      while (j < NB_COL)
	{
	  if (grid[i][j] == '|')
	    *sign += 1;
	  j++;
	}
      if (i <= 4)
	check[k] = *sign;
      k++;
      i++;
    }
  return (check);
}

int	checking_before_calcul(char **grid, int *sign)
{
  int	i;
  int	to_much;
  int	*check;

  i = 0;
  to_much = 0;
  if ((check = loop_of_checking_before_calcul(grid, sign)) == NULL)
    return (-1);
  while (i < 4)
    {
      if (check[i] == 1)
	*sign += 1;
      if (check[i] > 1)
	to_much++;
      i++;
    }
  if (to_much > 1)
    return (1);
  else
    return (0);
}

void	loop_of_delete_matches(char **grid,
			       int *save_sign,
			       int *max,
			       int *sign)
{
  int	i;
  int	j;

  i = 1;
  while (i < NB_LINE)
    {
      *sign = 0;
      j = 0;
      while (j < NB_COL)
	{
	  if (grid[i][j] == '|')
	    *sign += 1;
	  if (*sign > *max)
	    {
	      *max = i;
	      *save_sign = *sign;
	    }
	  j++;
	}
      i++;
    }
}

void	delete_matches(char **grid,
		       int *line,
		       int *nb_matches,
		       int pair_or_not)
{
  int	sign;
  int	save_sign;
  int	max;

  sign = 0;
  max = 0;
  save_sign = 0;
  loop_of_delete_matches(grid, &save_sign, &max, &sign);
  *line = max;
  if (pair_or_not % 2 != 0)
    {
      if ((*nb_matches = save_sign + 1) > sign)
	*nb_matches = save_sign;
    }
  else
    {
      *nb_matches = save_sign - 1;
      if (*nb_matches == 0 || *nb_matches == -1)
	*nb_matches = 1;
    }
}
