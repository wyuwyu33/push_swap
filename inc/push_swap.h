/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 04:33:57 by wyu               #+#    #+#             */
/*   Updated: 2022/07/12 20:17:09 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "../libft/libft.h"

typedef struct s_arg
{
	int		argc;
	char	**argv;
} t_arg;

typedef struct s_arr
{
    int *val;
    int size;
} t_arr;

typedef struct s_dll
{
	struct s_dll *prev;
	int data;
	struct s_dll *next;
} t_dll;

typedef struct s_deq
{
    t_dll *header;
    t_dll *trailer;
    int size;
} t_deq;

typedef struct s_frame
{
    t_deq *deq_a;
    t_deq *deq_b;
} t_frame;


// ft_error.c
void    ft_allocation_error(char *func);
void    ft_arg_error();

// ft_clear.c
void ft_clear_argv(char **argv);
void ft_clear_arg(t_arg *arg);
void ft_clear_arr(t_arr *arr);


// ft_argv_split.c
t_arg *ft_argv_split(int argc, char **argv);

// ft_arg_errorcheck.c
void ft_arg_errorcheck(t_arg *arg);

// ft_get_arr.c
t_arr *ft_get_arr(t_arg *arg);

// ft_get_frame.c
t_frame *ft_get_frame(t_arr *arr);

// ft_get_deq.c
t_deq *ft_get_deq_a(t_arr *arr);
t_deq *ft_get_deq_b();

// ft_get_dll.c
t_dll *ft_get_dll(int data);

// ft_deq.c
void ft_add_front(t_deq *deq, t_dll *dll);
void ft_add_rear(t_deq *deq, t_dll *dll);
t_dll *ft_remove_front(t_deq *deq);
t_dll *ft_remove_rear(t_deq *deq);

// ft_get_sarr.c
t_arr *ft_get_sarr(t_arr *arr);

// ft_arg_dupcheck.c
void ft_arg_dupcheck(t_arr *arr);



#endif