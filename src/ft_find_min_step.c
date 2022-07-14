/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min_step.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:35:53 by wyu               #+#    #+#             */
/*   Updated: 2022/07/15 04:42:07 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static
int	ft_find_stuck(t_dll *pnode, t_dll *end_point, int min)
{
	int	max;

	max = pnode->data;
	while (pnode != end_point)
	{
		if (min < pnode->data && pnode->data < max)
			return (1);
		pnode = pnode->next;
	}
	return (0);
}

static
t_steps	ft_put_steps(t_dll *a, t_dll *b)
{
	t_steps	res;

	res.a_step = 0;
	res.a_rotate = 0;
	res.b_step = 0;
	res.b_rotate = 0;
	res.total = 0;
	if (a->next == NULL)
		return (res);
	res.a_step = a->step;
	res.a_rotate = a->rotate;
	res.b_step = b->step;
	res.b_rotate = b->rotate;
	res.total = res.a_step + res.b_step;
	return (res);
}

static
t_steps	ft_find_steps(t_deq *a, t_dll *dll_b)
{
	t_steps	res;
	t_dll	*search_a;
	int		p_data;

	search_a = a->header->next;
	while (search_a != a->trailer)
	{
		if (search_a->data > dll_b->data)
			break ;
		search_a = search_a->next;
	}
	p_data = search_a->data;
	if (ft_find_stuck(search_a, a->trailer, dll_b->data))
	{
		while (search_a != a->trailer)
		{
			if (dll_b->data < search_a->data && search_a->data < p_data)
				break ;
			search_a = search_a->next;
		}
	}
	res = ft_put_steps(search_a, dll_b);
	return (res);
}

t_steps	ft_find_min_step(t_frame *frame)
{
	t_dll	*search_b;
	t_steps	steps;
	t_steps	tmp;

	search_b = frame->deq_b->header->next;
	steps.total = frame->deq_a->size + frame->deq_b->size;
	while (search_b != frame->deq_b->trailer)
	{
		tmp = ft_find_steps(frame->deq_a, search_b);
		if (tmp.total < steps.total)
		{
			steps.a_step = tmp.a_step;
			steps.a_rotate = tmp.a_rotate;
			steps.b_step = tmp.b_step;
			steps.b_rotate = tmp.b_rotate;
			steps.total = tmp.total;
		}
		search_b = search_b->next;
	}
	return (steps);
}
