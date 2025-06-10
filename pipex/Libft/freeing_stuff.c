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
