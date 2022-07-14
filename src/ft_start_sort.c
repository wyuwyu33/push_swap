/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:33:31 by wyu               #+#    #+#             */
/*   Updated: 2022/07/15 05:20:22 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static
void	ft_init_deq_a(t_frame *frame)
{
	if (frame->deq_a->header->next->data == frame->min && \
		frame->deq_a->header->next->next->data == frame->max)
		ft_sa(frame);
	else if (frame->deq_a->trailer->prev->data == frame->max && \
			frame->deq_a->trailer->prev->prev->data == frame->min)
		ft_sa(frame);
	else if (frame->deq_a->header->next->data == frame->max && \
			frame->deq_a->trailer->prev->data == frame->min)
		ft_sa(frame);
}

static
int	ft_find_min_rotate(t_frame *frame)
{
	t_dll	*dll_a;

	dll_a = frame->deq_a->header->next;
	while (dll_a != frame->deq_a->trailer)
	{
		if (dll_a->data == frame->min)
			return (dll_a->rotate);
		dll_a = dll_a->next;
	}
	return (0);
}

static
void	ft_set_step_deq(t_deq *deq)
{
	t_dll	*dll;
	int		i;
	int		step;

	dll = deq->header->next;
	i = -1;
	step = 0;
	while (++i <= (int)(deq->size / 2))
	{
		dll->step = step;
		dll->rotate = 1;
		step++;
		dll = dll->next;
	}
	i = deq->size;
	step = 1;
	dll = deq->trailer->prev;
	while (--i > (int)(deq->size / 2))
	{
		dll->step = step;
		dll->rotate = -1;
		step++;
		dll = dll->prev;
	}
}

static
void	ft_enter_in_order(t_frame *frame)
{
	t_steps	steps;

	while (frame->deq_b->size)
	{
		ft_set_step_deq(frame->deq_a);
		ft_set_step_deq(frame->deq_b);
		steps = ft_find_min_step(frame);
		ft_steps_running(frame, steps);
		ft_pa(frame);
	}
	ft_set_step_deq(frame->deq_a);
	if (ft_find_min_rotate(frame) == 1)
	{
		while (frame->deq_a->header->next->data != frame->min)
			ft_ra(frame);
	}
	else
	{
		while (frame->deq_a->header->next->data != frame->min)
			ft_rra(frame);
	}
}

void	ft_start_sort(t_frame *frame)
{
	t_dll	*a_header;

	a_header = frame->deq_a->header;
	while (frame->deq_a->size > 3)
	{
		if (a_header->next->data != frame->min && \
				a_header->next->data != frame->max && \
				a_header->next->data != frame->sec_max)
		{
			ft_pb(frame);
			if (frame->deq_b->header->next->data > frame->mid && \
					frame->deq_b->size > 1)
				ft_rb(frame);
		}
		else
			ft_ra(frame);
	}
	ft_init_deq_a(frame);
	ft_enter_in_order(frame);
}
