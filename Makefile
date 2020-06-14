# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: lrobert <lrobert@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/02/10 13:42:37 by lrobert      #+#   ##    ##    #+#        #
#    Updated: 2020/02/10 13:42:37 by lrobert     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME        		=   Cub3d

FLAGS       		=   -Wall -Wextra -Werror

PATH_INC			=	Cub3d_code/includes
PATH_INC_MINILIBX	=	minilibx-linux

INCL 				=	cub3d.h

INCLUDE				=	$(addprefix include/,$(INCL))

PATH_SRC			=	Cub3d_code/srcs/
SRC         		=   Cub3d_code/srcs/display_window.c	\
						Cub3d_code/srcs/ft_config.c			\
						Cub3d_code/srcs/ft_rgb.c			\
						Cub3d_code/srcs/gest_key.c			\
						Cub3d_code/srcs/where_is_waldo.c
						

LIBFT_PATH			=	libft
LIBFT				=	libft/libft.a

MINI_LIBX_PATH		=	minilibx-linux
MINI_LIBX			=	minilibx-linux/libmlx_Linux.a

OBJSRC = $(SRC:.c=.o)

all:	$(LIBFT) $(MINI_LIBX) $(NAME)

$(NAME):	$(LIBFT) $(MINI_LIBX) $(OBJSRC)
	@ gcc $(FLAGS) -o $(NAME) Cub3d_code/srcs/cub3d.c $(OBJSRC) $(LIBFT) $(MINI_LIBX) -lX11 -lbsd -lm -lXext 
	@ printf "\033[2K\033[0;32mCompilation terminée\n\033[1m"

$(LIBFT):
	@ make -C $(LIBFT_PATH)

$(MINI_LIBX):
	@ make -C $(MINI_LIBX_PATH)

%.o: $(PATH_SRC)%.c $(INCLUDE)
	@ printf "\033[2K\033[0;38;5;226mCompilation de \033[1m$< ..."
	@ gcc $(OBJSRC) -I$(PATH_INC) -c $< -o $@


clean:
	@ rm -rf $(PATH_SRC)*.o
	@ make -C $(LIBFT_PATH) clean
	@ make -C $(MINI_LIBX_PATH) clean

fclean:	clean
	@ rm -rf *.out
	@ rm -rf $(NAME)
	@ make -C $(LIBFT_PATH) fclean

re:	fclean all