/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:20:36 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/13 15:50:17 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nums(t_node	*stack)
{
	t_node	*ptr;
	int		count;

	if (stack == NULL)
		return (0);
	ptr = stack;
	count = 0;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		count++;
	}
	return (count);
}

int	check_sorted(t_node	*stack)
{
	t_node	*current_ptr;
	t_node	*next_ptr;

	current_ptr = stack;
	next_ptr = current_ptr->next;
	if (!stack)
		return (1);
	while (current_ptr->next != NULL)
	{
		if (current_ptr->num > next_ptr->num)
			return (0);
		current_ptr = current_ptr->next;
		next_ptr = next_ptr->next;
	}
	return (1);
}

void	sort_three(t_node	**a)
{
	t_node	*highest;

	highest = find_max(*a);
	if (highest == *a)
		ra(a, 0);//not sure about 0/1 value here for print. why is it necessary? found on thuggonaut.
	else if ((*a)->next == highest)
		rra(a, 0);
	if ((*a)->num > (*a)->next->num)
		sa(a, 0);
}
/*
void	sort_more(t_node	**a)
{
	t_node	*highest;
	t_node	*b;
	t_node	*new_top;

	b = NULL;
	while (count_nums(*a) > 3 && !check_sorted(a))
	{
		pb(a, b, 0);
		// highest = find_max(*a);
		// if (highest == *a)
		// 	new_top = (*a)->next;
		// else
		// 	new_top = *a;
		// highest->next = b;
		// b = highest;
		// *a = new_top;
	}
	sort_three(a);
	retrieve_b(a, &b);
}*/

void retrieve_b(t_node **a, t_node ** b)
{
	t_node *b_last;
	t_node *b_pen;
	
	while ((*b)->next)
	{
		b_last = find_last(*b);
		b_pen = find_penultimate(*b);
		
	}
}

void	sort_stack(t_node	**stack)//could return int 1/0 to indicate success/error?
{
	int	count;

	count = count_nums(*stack);
	//ft_printf("%d\n", count);
	if (count == 0)
		return ;//or print error?
	if (check_sorted(*stack) == 1)
	{
		ft_printf("sorted\n");//delete this
		return ;
	}
	find_max(*stack);
	find_min(*stack);
	if (count == 3)
		sort_three(stack);
	/*if (count > 3)
		sort_more(stack);*/
}