/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollia <abollia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:26:57 by abollia           #+#    #+#             */
/*   Updated: 2025/02/10 11:29:52 by abollia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	splitcount(char **splito)
{
	int	count;

	count = 0;
	while (splito[count])
		count++;
	return (count);
}

int	ps_argcnt(char **av)
{
	int		i;
	int		count;
	char	**splito;

	i = 1;
	count = 0;
	splito = NULL;
	while (av[i])
	{
		if (ft_strchr(av[i], ' '))
		{
			splito = ft_split(av[i], ' ');
			if (!splito)
				return (0);
			count += splitcount(splito);
			ft_ffa(splito);
		}
		else
			count++;
		i++;
	}
	return (count);
}

static int	appsplit(char **args, char **av, int *j, int *i)
{
	int		k;
	char	**splito;

	k = 0;
	splito = ft_split(av[*i], ' ');
	if (!splito)
		return (0);
	while (splito[k])
	{
		args[*j] = ft_strdup(splito[k]);
		(*j)++;
		k++;
	}
	ft_ffa(splito);
	return (1);
}

int	ps_getargs(char **args, char **av)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (av[i])
	{
		if (ft_strchr(av[i], ' '))
		{
			if (!appsplit(args, av, &j, &i))
				return (ft_ffa(args), 0);
		}
		else
		{
			args[j] = ft_strdup(av[i]);
			if (!args[j])
				return (ft_ffa(args), 0);
			j++;
		}
		i++;
	}
	args[j] = NULL;
	return (1);
}
