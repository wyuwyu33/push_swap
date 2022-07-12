/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 08:13:03 by wyu               #+#    #+#             */
/*   Updated: 2022/07/12 20:16:00 by wyu              ###   ########.fr       */
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
	free(arr->val);
	free(arr);
}