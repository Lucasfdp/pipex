/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 01:56:06 by luferna3          #+#    #+#             */
/*   Updated: 2025/06/11 01:56:07 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_array(char **arr, int count)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	if (count == -1)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
	}
	else
	{
		while (i < count)
		{
			free(arr[i]);
			i++;
		}
	}
	free(arr);
}

void	free_lst(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
