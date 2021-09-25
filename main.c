#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"
#include	"get_next_line1/get_next_line.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**my_values;
	int		flag;

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
	stack_a = sort_and_index(insert_into_stack(argc, argv, flag));
	stack_a = make_base(stack_a);
	stack_b = NULL;
	stack_a = sort_the_stack(stack_a, stack_b);
}
