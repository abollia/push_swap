/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollia <abollia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:50:22 by abollia           #+#    #+#             */
/*   Updated: 2025/02/10 11:32:22 by abollia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	ps_finalsort(t_node **head)
{
	t_node	*smallest;

	smallest = ps_findmin(*head);
	if (!smallest)
		return ;
	assign_properties(*head);
	while (*head != smallest)
	{
		if (smallest->abovemedian)
			rotate_a(head);
		else
			reverse_rotate_a(head);
	}
}

static void	ps_sort(t_node **a, t_node **b)
{
	int	len_a;

	len_a = ps_lstsize(*a);
	while (len_a > 3 && !(ps_issorted(*a)))
	{
		lstini(*a, *b, 'a');
		ps_atob(b, a);
		len_a--;
	}
	ps_microsort(a);
	while (*b)
	{
		lstini(*a, *b, 'b');
		ps_btoa(a, b);
	}
	ps_finalsort(a);
}

void	ps_inisort(t_node **a, t_node **b)
{
	if (!ps_issorted(*a))
	{
		if (ps_lstsize(*a) == 2)
			swap_a(a);
		else if (ps_lstsize(*a) == 3)
			ps_microsort(a);
		else
			ps_sort(a, b);
	}
}

void	ps_microsort(t_node **head)
{
	if (((*head)->data > (*head)->next->data
			&& (*head)->data > (*head)->next->next->data))
		rotate_a(head);
	if (((*head)->data < (*head)->next->data
			&& (*head)->next->data > (*head)->next->next->data))
		reverse_rotate_a(head);
	if ((*head)->data > (*head)->next->data)
		swap_a(head);
}
