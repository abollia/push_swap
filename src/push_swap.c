/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollia <abollia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:18:23 by abollia           #+#    #+#             */
/*   Updated: 2025/02/10 11:27:25 by abollia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ps_stackerparser(char **args, t_node **a)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (args[i])
	{
		nb = atol(args[i]);
		if (!(is_nb_valid(nb)))
			return (ps_free_stack(a), 0);
		if (!(is_nb_dup(*a, (int)nb)))
			return (ps_free_stack(a), 0);
		if (!(appnode(a, (int)nb)))
			return (ps_free_stack(a), 0);
		i++;
	}
	return (1);
}

static int	ps_parserstacker(char **av, t_node **a)
{
	char	**args;

	args = (char **)malloc(sizeof(char *) * (ps_argcnt(av) + 1));
	if (!args)
		return (0);
	if (!ps_getargs(args, av))
		return (ft_ffa(args), 0);
	if (!ps_args_parser(args))
		return (ft_ffa(args), 0);
	if (!ps_stackerparser(args, a))
		return (ft_ffa(args), 0);
	ft_ffa(args);
	return (1);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (!ps_parserstacker(av, &a))
		return (1);
	ps_inisort(&a, &b);
	ps_free_stack(&a);
	ps_free_stack(&b);
	return (0);
}
