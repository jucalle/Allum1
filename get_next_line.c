/*
** get_next_line.c for  in /home/callew_j/rendu/GNL/CPE_2015_getnextline
** 
** Made by julien callewaert
** Login   <callew_j@epitech.net>
** 
** Started on  Mon Jun  6 13:36:01 2016 julien callewaert
** Last update Tue Jul 12 17:32:59 2016 julien callewaert
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int	end_of_line(t_gnl *gnl)
{
  int	i;

  i = 0;
  gnl->end_line = 0;
  while (gnl->buffer[i] != '\0')
    {
      if (gnl->buffer[i] == '\n')
	{
	  gnl->end_line = i;
	  return (0);
	}
      i++;
    }
  return (1);
}

void	fill_str_with_static(t_gnl *gnl, char *rem)
{
  while (rem[gnl->i] != '\0')
    {
      gnl->str[gnl->i] = rem[gnl->i];
      gnl->i++;
    }
}

int	fill_str(t_gnl *gnl, const int fd)
{
  while (end_of_line(gnl) != 0)
    {
      gnl->j = 0;
      while (gnl->buffer[gnl->j] != '\0')
	{
	  gnl->str[gnl->i] = gnl->buffer[gnl->j];
	  gnl->j++;
	  gnl->i++;
	}
      gnl->ct = read(fd, gnl->buffer, READ_SIZE);
      if (gnl->ct == 0 || gnl->ct == -1)
	return (1);
      gnl->buffer[gnl->ct] = 0;
    }
  gnl->cp = gnl->i;
  gnl->j = 0;
  while (gnl->i < gnl->cp + gnl->end_line)
    {
      gnl->str[gnl->i] = gnl->buffer[gnl->j];
      gnl->i++;
      gnl->j++;
    }
  gnl->j++;
  return (0);
}

char		*get_next_line(const int fd)
{
  t_gnl		gnl;
  static char	rem[READ_SIZE + 1];

  gnl.r = 0;
  gnl.i = 0;
  gnl.j = 0;
  gnl.ct = read(fd, gnl.buffer, READ_SIZE);
  if (gnl.ct == 0 || gnl.ct == -1)
    return (NULL);
  if ((gnl.str = malloc(sizeof(char*) * STR_SIZE)) == NULL)
    return (NULL);
  gnl.buffer[gnl.ct] = 0;
  if (my_strlen(rem) != 0)
    fill_str_with_static(&gnl, rem);
  if (fill_str(&gnl, fd) == 1)
    return (NULL);
  while (gnl.buffer[gnl.j] != '\0')
    {
      rem[gnl.r] = gnl.buffer[gnl.j];
      gnl.j++;
      gnl.r++;
    }
  gnl.str[gnl.i] = '\0';
  rem[gnl.r] = '\0';
  return (gnl.str);
}
