/*
** my_put_nbr.c for  in /home/callew_j/rendu/tests
** 
** Made by julien callewaert
** Login   <callew_j@epitech.net>
** 
** Started on  Mon Apr  4 11:37:00 2016 julien callewaert
** Last update Fri Apr 15 12:46:09 2016 julien callewaert
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  int	modulo;

  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  modulo = nb % 10;
	  nb = nb - modulo;
	  nb = nb / 10;
	  my_put_nbr(nb);
	  my_putchar(48 + modulo);
	}
      else
	my_putchar(48 + nb);
    }
  else
    {
      my_putchar('-');
      my_put_nbr(-nb);
    }
}
