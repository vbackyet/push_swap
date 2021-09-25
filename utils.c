#include "push_swap.h"
#include "stdio.h"
#include	"get_next_line1/get_next_line.h"

int	len_of_the_args(char **my_values)
{
	int	i;

	i = 0;
	while (my_values[i])
		i++;
	return (i);
}

void	continue_perform_command(t_stack **stack_a, t_stack **stack_b, \
	char *command, int flag)
{
	if (ft_strcmp(command, "rra") == 0)
		rra(stack_a);
	if (ft_strcmp(command, "rrb") == 0)
		rra(stack_b);
	if (ft_strcmp(command, "rrr") == 0)
	{		
		rra(stack_a);
		rra(stack_b);
	}
	if (ft_strcmp(command, "pb") == 0)
		pa(stack_a, stack_b);
	if (ft_strcmp(command, "pa") == 0)
		pa(stack_b, stack_a);
	if (flag)
	{
		write(1, command, ft_strlen(command));
		write(1, "\n", 1);
	}
}

void	perform_command(t_stack **stack_a, t_stack **stack_b, \
char *command, int flag)
{
	if (ft_strcmp(command, "ra") == 0)
		ra(stack_a);
	if (ft_strcmp(command, "rb") == 0)
		ra(stack_b);
	if (ft_strcmp(command, "sa") == 0)
		sa(stack_a);
	if (ft_strcmp(command, "sb") == 0)
		sa(stack_b);
	if (ft_strcmp(command, "ss") == 0)
	{
		sa(stack_a);
		sa(stack_b);
	}
	if (ft_strcmp(command, "rr") == 0)
	{
		ra(stack_a);
		ra(stack_b);
	}
	else
		continue_perform_command(stack_a, stack_b, command, flag);
}
