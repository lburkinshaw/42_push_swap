/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:18:14 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/04 13:50:08 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_cheapest(t_node *stack)
{
	t_node	*cheapest;
	t_node	*curr;

	cheapest = NULL;
	curr = stack;
	if (!stack)
		error_n_exit(NULL, 0);
	while (curr)
	{
		if (curr->cheapest == 1)// 1 = cheapest.
		{
			cheapest = curr;
			break ;
		}
		curr = curr->next;
	}
	return (cheapest);
}

void	move_to_top(t_node **stack, t_node *top, char stack_name)
{
	while (*stack != top)//iterates until top node is at head.
	{
		if (stack_name == 'a')//so that we know to call "ra" or "rra" rather than "rb"/"rrb".
		{
			if (top->above_median)
				ra(stack);
			else
				rra(stack);
		}
		if (stack_name == 'b')
		{
			if (top->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = find_cheapest(*a);//moves cheapest node and its target to top of stacks.
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)//if both above median, rotate both until on of cheapest reaches top/
		rotate_both(a, b, cheapest_node);//rotates until one of nodes reaches top.
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))//if both below median, rev rotate both.
		rev_rotate_both(a, b, cheapest_node);//rev rotates until one reaches top.
	move_to_top(a, cheapest_node, 'a');
	move_to_top(b, cheapest_node->target_node, 'b');
	pb(b, a);//pushes cheapest node on top of its target node in B.
}

void	move_b_to_a(t_node **a, t_node **b)//this is simpler because only needs to rotate B's target node in A to top and push B to A (no cost analysis)
{
	move_to_top(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	put_min_ontop(t_node **stack)
{
	t_node	*min;

	min = find_min(*stack);
	current_index(*stack);
	while (*stack != min)
	{
		if (min->above_median)
			ra(stack);
		else
			rra(stack);
	}
}
