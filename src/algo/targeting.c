/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targeting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollia <abollia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:20:04 by abollia           #+#    #+#             */
/*   Updated: 2025/02/10 12:51:30 by abollia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static t_node	*find_closest_smaller(t_node *b, int nb)
{
	int		closest_smaller;
	t_node	*target;

	closest_smaller = INT_MIN;
	target = NULL;
	while (b)
	{
		if (b->data < nb & b->data > closest_smaller)
		{
			closest_smaller = b->data;
			target = b;
		}
		b = b->next;
	}
	return (target);
}

void	asstarto_a(t_node *a, t_node *b)
{
	t_node	*target;

	if (!b || ps_lstsize(b) == 0)
		return ;
	while (a)
	{
		target = find_closest_smaller(b, a->data);
		if (!target)
			a->target = ps_findmax(b);
		else
			a->target = target;
		a = a->next;
	}
}

static t_node	*find_closest_bigger(t_node *a, int nb)
{
	int		closest_bigger;
	t_node	*target;

	closest_bigger = INT_MAX;
	target = NULL;
	while (a)
	{
		if (a->data > nb & a->data < closest_bigger)
		{
			closest_bigger = a->data;
			target = a;
		}
		a = a->next;
	}
	return (target);
}

void	asstarto_b(t_node *a, t_node *b)
{
	t_node	*target;

	if (!a || ps_lstsize(a) == 0)
		return ;
	while (b)
	{
		target = find_closest_bigger(a, b->data);
		if (!target)
			b->target = ps_findmin(a);
		else
			b->target = target;
		b = b->next;
	}
}
