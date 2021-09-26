#include <stdio.h>
#include <unistd.h>
#include "get_next_line1/get_next_line.h"
#include "push_swap.h"

int	check_the_argument_valid(char *command)
{
	if (ft_strcmp(command, "ra") && ft_strcmp(command, "rb") && \
	ft_strcmp(command, "sa") && ft_strcmp(command, "sb") \
		&& ft_strcmp(command, "ss") && ft_strcmp(command, "rr") \
			&& ft_strcmp(command, "rra") && ft_strcmp(command, "rrb") \
			&& ft_strcmp(command, "rrr") \
			&& ft_strcmp(command, "pb") && ft_strcmp(command, "pa"))
		return (1);
	return (0);
}

void	perform_the_checker(t_stack *stack_a, t_stack *stack_b)
{
	int		ret;
	char	*line;

	ret = 1;
	while (ret > 0)
	{
		line = 0;
		ret = get_next_line(0, &line);
		if (check_the_argument_valid(line))
		{
			free(line);
			if (ret == 0)
			{
				if (the_stack_is_sorted(stack_a))
					write(1, "OK\n", 3);
				else
					write(1, "KO\n", 3);
				return ;
			}
			write(1, "Error\n", 6);
			return ;
		}
		perform_command(&stack_a, &stack_b, line, 0);
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		flag;
	char	**my_values;

	flag = 1;
	if (argc == 2)
	{
		my_values = ft_split(argv[1], ' ');
		if (len_of_the_args(my_values) > 1)
		{
			argc += (len_of_the_args(my_values) - 2);
			argv = my_values;
			flag = 0;
		}
	}
	if (check_the_argument(argc, argv, flag))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	stack_a = insert_into_stack(argc, argv, flag);
	stack_b = NULL;
	perform_the_checker(stack_a, stack_b);
	return (1);
}
