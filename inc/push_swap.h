/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 04:33:57 by wyu               #+#    #+#             */
/*   Updated: 2022/07/15 22:16:27 by wyu              ###   ########.fr       */
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
}	t_arg;

typedef struct s_arr
{
	int	*val;
	int	size;
}	t_arr;

typedef struct s_dll
{
	struct s_dll	*prev;
	int				data;
	int				step;
	int				rotate;
	struct s_dll	*next;
}	t_dll;

typedef struct s_deq
{
	t_dll	*header;
	t_dll	*trailer;
	int		size;
}	t_deq;

typedef struct s_frame
{
	t_deq	*deq_a;
	t_deq	*deq_b;
	int		max;
	int		sec_max;
	int		mid;
	int		min;
	int		sort;
}	t_frame;

typedef struct s_steps
{
	int	a_step;
	int	b_step;
	int	a_rotate;
	int	b_rotate;
	int	total;
}	t_steps;

// ft_error.c
void	ft_allocation_error(char *func);
void	ft_arg_error(void);

// ft_clear.c
void	ft_clear_argv(char **argv);
void	ft_clear_arg(t_arg *arg);
void	ft_clear_arr(t_arr *arr);
void	ft_clear_deq(t_deq *deq);
void	ft_clear_frame(t_frame *frame);

// ft_argv_split.c
t_arg	*ft_argv_split(int argc, char **argv);

// ft_arg_errorcheck.c
void	ft_arg_errorcheck(t_arg *arg);

// ft_get_arr.c
t_arr	*ft_get_arr(t_arg *arg);

// ft_get_frame.c
t_frame	*ft_get_frame(t_arr *arr, t_arr *sarr);

// ft_get_deq.c
t_deq	*ft_get_deq_a(t_arr *arr);
t_deq	*ft_get_deq_b(void);

// ft_get_dll.c
t_dll	*ft_get_dll(int data);

// ft_deq.c
void	ft_add_front(t_deq *deq, t_dll *dll);
void	ft_add_rear(t_deq *deq, t_dll *dll);
t_dll	*ft_remove_front(t_deq *deq);
t_dll	*ft_remove_rear(t_deq *deq);

// ft_get_sarr.c
t_arr	*ft_get_sarr(t_arr *arr);

// ft_arg_dupcheck.c
void	ft_arg_dupcheck(t_arr *arr);

// ft_arr_sortcheck.c
int		ft_arr_sortcheck(t_arr *arr);

// ft_start_sort.c
void	ft_start_sort(t_frame *frame);

// ft_push.c
void	ft_pa(t_frame *frame);
void	ft_pb(t_frame *frame);

// ft_rotate.c
void	ft_ra(t_frame *frame);
void	ft_rb(t_frame *frame);
void	ft_rr(t_frame *frame);

// ft_reverse_rotate.c
void	ft_rra(t_frame *frame);
void	ft_rrb(t_frame *frame);
void	ft_rrr(t_frame *frame);

// ft_swap.c
void	ft_sa(t_frame *frame);
void	ft_sb(t_frame *frame);

// ft_find_min_step.c
t_steps	ft_find_min_step(t_frame *frame);

// ft_steps_running.c
void	ft_steps_running(t_frame *frame, t_steps steps);

#endif