##
## Makefile for make_param in /home/bechad_p/Revision/Piscine_Jour_9
## 
## Made by bechade_pierre
## Login   <bechad_p@epitech.net>
## 
## Started on  Sat Feb 22 15:28:57 2014 bechade_pierre
## Last update Sun Mar 16 23:06:00 2014 bechade_pierre
##

CC	=	gcc

RM	=	rm -f

NAME	=	rtv1

CFLAGS	=	-W -Wall -Werror -L/usr/lib64 -lmlx_x86_64 -L/usr/lib64/X11 -lXext -lX11 -lm

SRCS	=	rtv1.c 		\
		calcul_forme.c	\
		light.c		\
		manage.c

OBJS	=	$(SRCS:.c=.o)

LFLAGS	=

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

all	:	$(NAME)

clean	:	
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)
		$(RM) *~ *#

re	:	fclean all

.PHONY	:	all clean fclean re	
