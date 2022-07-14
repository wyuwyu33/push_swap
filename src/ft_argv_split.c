/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 05:02:32 by wyu               #+#    #+#             */
/*   Updated: 2022/07/14 18:01:20 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static
char	**ft_get_argv(int size)
{
	char	**new_argv;

	new_argv = (char **)malloc(sizeof(char *) * size);
	if (!new_argv)
		ft_allocation_error("ft_get_argv");
	new_argv[size - 1] = NULL;
	return (new_argv);
}

static
t_arg	*ft_get_arg(void)
{
	t_arg	*new_arg;

	new_arg = (t_arg *)malloc(sizeof(t_arg));
	if (!new_arg)
		ft_allocation_error("ft_get_arg");
	new_arg->argc = 0;
	new_arg->argv = ft_get_argv(1);
	return (new_arg);
}

static
void	ft_argvcpy(char **dest_argv, char **src_argv)
{
	int	i;

	i = -1;
	while (src_argv[++i])
		dest_argv[i] = ft_strdup(src_argv[i]);
}

static
char	**ft_append_argv(char **dest_argv, char **src_argv)
{
	int		dest_i;
	int		src_i;
	char	**new_argv;

	dest_i = -1;
	while (dest_argv[++dest_i])
		;
	src_i = -1;
	while (src_argv[++src_i])
		;
	new_argv = ft_get_argv(dest_i + src_i + 1);
	ft_argvcpy(new_argv, dest_argv);
	ft_argvcpy(new_argv + dest_i, src_argv);
	new_argv[dest_i + src_i] = NULL;
	ft_clear_argv(dest_argv);
	ft_clear_argv(src_argv);
	return (new_argv);
}

t_arg	*ft_argv_split(int argc, char **argv)
{
	t_arg	*res;
	int		i;
	char	**separator;

	res = ft_get_arg();
	i = 0;
	while (++i < argc)
	{
		separator = ft_split(argv[i], ' ');
		if (!separator)
			ft_allocation_error("ft_argv_split");
		res->argv = ft_append_argv(res->argv, separator);
	}
	i = -1;
	while (res->argv[++i])
		;
	res->argc = i;
	return (res);
}
