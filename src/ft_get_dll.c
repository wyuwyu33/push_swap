/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:00:27 by wyu               #+#    #+#             */
/*   Updated: 2022/07/12 21:21:21 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_dll *ft_get_dll(int data)
{
	t_dll *new_dll;

	new_dll = (t_dll *)malloc(sizeof(t_dll));
	if (!new_dll)
		ft_allocation_error("ft_get_dll");
	new_dll->data = data;
	new_dll->prev = NULL;
	new_dll->next = NULL;
	new_dll->step = 0;
	new_dll->rotate = 0;
	return (new_dll);
}