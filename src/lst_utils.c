/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollia <abollia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:56:09 by abollia           #+#    #+#             */
/*   Updated: 2025/02/10 11:31:28 by abollia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ps_issorted(t_node *head)
{
	t_node	*tmp;

	if (!head)
		return (1);
	tmp = head;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ps_lstsize(t_node *head)
{
	int		count;
	t_node	*tmp;

	count = 0;
	tmp = head;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

t_node	*ps_findlast(t_node *head)
{
	t_node	*tmp;

	if (!head)
		return (NULL);
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_node	*ps_findmin(t_node *head)
{
	int		smallest_data;
	t_node	*smallest;

	smallest_data = INT_MAX;
	smallest = NULL;
	while (head)
	{
		if (head->data < smallest_data)
		{
			smallest_data = head->data;
			smallest = head;
		}
		head = head->next;
	}
	return (smallest);
}

t_node	*ps_findmax(t_node *head)
{
	int		biggest_data;
	t_node	*biggest;

	biggest_data = INT_MIN;
	biggest = NULL;
	while (head)
	{
		if (head->data > biggest_data)
		{
			biggest_data = head->data;
			biggest = head;
		}
		head = head->next;
	}
	return (biggest);
}
