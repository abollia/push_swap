/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollia <abollia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:48:19 by abollia           #+#    #+#             */
/*   Updated: 2025/02/10 13:02:49 by abollia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ps_managerror(void)
{
	write(2, "Error\n", 6);
}

static int	is_synthax_valid(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '-' || str[i] == '+')
			&& (!(str[i + 1]) || !('0' <= str[i + 1] && str[i + 1] <= '9')))
			return (0);
		if (!(str[i] == ' ' || str[i] == '-' || str[i] == '+'
				|| ('0' <= str[i] && str[i] <= '9')))
			return (0);
		i++;
	}
	return (1);
}

int	ps_args_parser(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		if (!is_synthax_valid(args[i]))
			return (ps_managerror(), 0);
	}
	return (1);
}

int	is_nb_valid(long nb)
{
	if (nb > 2147483647 || nb < -2147483648)
		return (ps_managerror(), 0);
	else
		return (1);
}

int	is_nb_dup(t_node *head, int nb)
{
	t_node	*current;

	if (!head)
		return (1);
	current = head;
	while (current)
	{
		if (nb == current->data)
			return (ps_managerror(), 0);
		current = current->next;
	}
	return (1);
}
