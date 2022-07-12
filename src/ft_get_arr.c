/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:26:09 by wyu               #+#    #+#             */
/*   Updated: 2022/07/12 06:14:19 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static
void ft_init_arr(t_arr *arr, t_arg *arg)
{
	int i;

	i = -1;
	while (++i < arg->argc)
		arr->val[i] = ft_atoi(arg->argv[i]);
	arr->size = arg->argc;
}

t_arr *ft_get_arr(t_arg *arg)
{
	t_arr *new_arr;

	new_arr = (t_arr *)malloc(sizeof(t_arr));
	if (!new_arr)
		ft_allocation_error("ft_get_arr");
	new_arr->val = (int *)malloc(sizeof(int) * arg->argc);
	if (!new_arr->val)
		ft_allocation_error("ft_get_arr");
	ft_init_arr(new_arr, arg);
	return (new_arr);
}