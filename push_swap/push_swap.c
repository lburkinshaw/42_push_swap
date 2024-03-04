/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:11:47 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/04 13:50:12 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))//eliminate invalid no. of args.
		exit(1);// or should it be : error_n_exit(argv, 0); ?? "If no parameters are specified, the program must not display anything and give the prompt back."
	create_a(argc, argv, &a);//processes arguments, checks valid values and appends to stack 'a'.
	sort_stack(&a, &b);//sorts stack by pushing to and from 'b', printing each operation used.
	free_stack(&a);//frees stack after completing.
	return (0);
}
