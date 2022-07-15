/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_errorcheck.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:52:16 by wyu               #+#    #+#             */
/*   Updated: 2022/07/15 22:16:20 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static
void	ft_range_check(const char *s)
{
	long long	nbr;
	long long	sign;
	size_t		i;

	i = 0;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	nbr = 0;
	while (s[i] && ft_isdigit(s[i]))
	{
		nbr = (nbr * 10) + (s[i] - '0');
		if (sign * nbr > INT_MAX || sign * nbr < INT_MIN)
			ft_arg_error();
		i++;
	}
}

static
void	ft_validvalue_check(char *s)
{
	int	i;

	if (*s == '+' || *s == '-')
		s++;
	i = -1;
	while (ft_isdigit(s[++i]))
		;
	if (!i || s[i])
		ft_arg_error();
}

void	ft_arg_errorcheck(t_arg *arg)
{
	int	i;

	i = -1;
	while (++i < arg->argc)
	{
		ft_validvalue_check(arg->argv[i]);
		ft_range_check(arg->argv[i]);
	}
}
