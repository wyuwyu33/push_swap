# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 18:14:59 by wyu               #+#    #+#              #
#    Updated: 2022/07/17 14:23:27 by wyu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -rf

NAME 	= push_swap

LIBFT			= libft
LIBFT_NAME		= libft.a
PUSH_SWAP_LIBFT = push_swap.a

SRC_LIST	= ft_error.c ft_clear.c ft_argv_split.c \
				ft_arg_errorcheck.c ft_get_arr.c ft_get_frame.c \
				ft_get_deq.c ft_get_dll.c ft_deq.c \
				ft_get_sarr.c ft_arg_dupcheck.c ft_arr_sortcheck.c \
				ft_start_sort.c ft_push.c ft_rotate.c \
				ft_reverse_rotate.c ft_swap.c ft_find_min_step.c \
				ft_steps_running.c ft_argv_check.c

SRC_DIR 	= src

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_LIST))
OBJS		= $(SRC_LIST:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(PUSH_SWAP_LIBFT)
		$(CC) $(CFLAGS) $(SRC_DIR)/push_swap.c -o $@ $<

$(PUSH_SWAP_LIBFT) : $(OBJS) $(LIBFT)/$(LIBFT_NAME)
		cp $(LIBFT)/$(LIBFT_NAME) $(PUSH_SWAP_LIBFT)
		$(AR) $@ $(OBJS)

$(LIBFT)/$(LIBFT_NAME) :
		make all -C $(LIBFT)

$(OBJS) : $(SRCS)
		$(CC) $(CFLAGS) -c $^

clean :
		$(RM) $(OBJS) $(PUSH_SWAP_LIBFT)
		make clean -C $(LIBFT)

fclean : clean
		$(RM) $(NAME)
		make fclean -C $(LIBFT)

re : clean all
