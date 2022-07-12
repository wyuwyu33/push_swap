/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 08:13:03 by wyu               #+#    #+#             */
/*   Updated: 2022/07/12 23:33:45 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_clear_argv(char **argv)
{
	int i;

	if (!argv)
		return ;
	i = -1;
	while (argv[++i])
		free(argv[i]);
	free(argv[i]);
	free(argv);
}

void ft_clear_arg(t_arg *arg)
{
	if (!arg)
		return ;
	ft_clear_argv(arg->argv);
	free(arg);
}

void ft_clear_arr(t_arr *arr)
{
	if (!arr)
		return ;
	free(arr->val);
	free(arr);
}

void ft_clear_deq(t_deq *deq)
{
	t_dll *node;
	t_dll *next;

	if (!deq)
		return ;	
	node = deq->header;
	while (node != deq->trailer)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(node);
	free(deq);
}

void ft_clear_frame(t_frame *frame)
{
	if (!frame)
		return ;
	ft_clear_deq(frame->deq_a);
	ft_clear_deq(frame->deq_b);
	free(frame);
}