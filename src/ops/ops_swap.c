/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollia <abollia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:19:01 by abollia           #+#    #+#             */
/*   Updated: 2025/02/11 14:27:58 by abollia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	ps_swap(t_node **head)
{
	t_node	*toswap;
	t_node	*third;

	if (!head || !*head || !(*head)->next)
		return ;
	toswap = (*head)->next;
	third = toswap->next;
	toswap->prev = (*head)->prev;
	toswap->next = *head;
	(*head)->prev = toswap;
	(*head)->next = third;
	if (third)
		third->prev = *head;
	*head = toswap;
}

void	swap_a(t_node **a)
{
	ps_swap(a);
	ft_printf("sa\n");
}

void	swap_b(t_node **b)
{
	ps_swap(b);
	ft_printf("sb\n");
}

void	swap_swap(t_node **a, t_node **b)
{
	ps_swap(a);
	ps_swap(b);
	ft_printf("ss\n");
}
