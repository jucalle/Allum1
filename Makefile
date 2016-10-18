##
## Makefile for  in /home/callew_j/rendu/semestre2/Prog_elem/CPE_2015_Allum1
## 
## Made by julien callewaert
## Login   <callew_j@epitech.net>
## 
## Started on  Tue Jul 12 21:33:45 2016 julien callewaert
## Last update Mon Jul 18 13:35:22 2016 julien callewaert
##

CC	= gcc

RM	= rm -f

CFLAGS  += -W -Wextra -Wall

CFLAGS  += -I.

LDFLAGS =

NAME	= allum1

SRCS	= main.c\
	  core.c\
	  update.c\
	  matches.c\
	  error.c\
	  my_put_nbr.c\
	  my_getnbr.c\
	  useful.c\
	  get_next_line.c\
	  board.c\
	  aff.c\
	  ai.c\
	  ai_2.c\
	  ai_3.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
