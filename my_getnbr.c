/*
** my_getnbr.c for  in /home/callew_j/renduP/tests
** 
** Made by julien callewaert
** Login   <callew_j@epitech.net>
** 
** Started on  Tue Apr  5 22:45:06 2016 julien callewaert
** Last update Thu Jul 21 18:43:22 2016 julien callewaert
*/

#include <stdio.h>

int	first_check(char *str, int i)
{
  if (str == NULL)
    return (-2);
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || str[i] > '9') && (str[i] != '-' || str[i] != '+'))
	return (-1);
      i++;
    }
  if (str[0] == '\0')
    return (-3);
  return (0);
}

int	call_first_check(char *str, int i)
{
  int	ret;

  if ((ret = first_check(str, i)) == -1)
    return (-1);
  else if (ret == -2)
    return (-2);
  else if (ret == -3)
    return (-3);
  return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	j;
  int	nb;
  int	ret;

  i = 0;
  j = 0;
  nb = 0;
  if ((ret = call_first_check(str, i)) != 0)
    return (ret);
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	j++;
      i++;
    }
  while (str[i] != '\0')
    {
      nb = nb * 10 + str[i] - '0';
      i++;
    }
  if (j % 2 != 0)
    return (-nb);
  else
    return (nb);
}
