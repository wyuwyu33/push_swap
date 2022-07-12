/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_deq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 02:55:01 by wyu               #+#    #+#             */
/*   Updated: 2022/07/12 06:10:39 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static
t_deq *ft_get_deq()
{
	t_deq *new_deq;

	new_deq = (t_deq *)malloc(sizeof(t_deq));
	if (!new_deq)
		ft_allocation_error("ft_get_deq");
	new_deq->header = (t_dll *)malloc(sizeof(t_dll));
	new_deq->trailer = (t_dll *)malloc(sizeof(t_dll));
	if (!new_deq->header || !new_deq->trailer)
		ft_allocation_error("ft_get_deq");
	new_deq->header->prev = NULL;
	new_deq->header->data = 0;
	new_deq->header->next = new_deq->trailer;
	new_deq->trailer->prev = new_deq->header;
	new_deq->trailer->data = 0;
	new_deq->trailer->next = NULL;
	return (new_deq);
}

t_deq *ft_get_deq_a(t_arr *arr)
{
	t_deq *new_a;
	t_dll *new_dll;
	int i;

	new_a = ft_get_deq();
	i = -1;
	while (++i < arr->size)
	{
		new_dll = ft_get_dll(arr->val[i]);
		ft_add_rear(new_a, new_dll);
	}
	return (new_a);
}

t_deq *ft_get_deq_b()
{
	t_deq *new_b;

	new_b = ft_get_deq();
	return (new_b);
}