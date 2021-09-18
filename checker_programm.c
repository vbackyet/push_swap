#include <stdio.h>
#include <unistd.h>
#include "get_next_line/get_next_line.h"
#include "push_swap.h"




int check_the_argument_valid(char *command)
{
	if (ft_strcmp(command, "ra") && ft_strcmp(command, "rb") && ft_strcmp(command, "sa") \
			&& ft_strcmp(command, "sb") && ft_strcmp(command, "ss") && ft_strcmp(command, "rr")\
			&& ft_strcmp(command, "rra") && ft_strcmp(command, "rrb") && ft_strcmp(command, "rrr")\
			&& ft_strcmp(command, "pb") && ft_strcmp(command, "pa"))
		return(1);
	return(0);

}


int main(int argc, char **argv)
{
	int ret;
	char *line;
	t_stack         *stack_a;
    t_stack         *stack_b;
	
	ret = 1;
	stack_a = insert_into_stack(argc, argv);
	listprint(stack_a);
	while (ret > 0)
	{
		ret = get_next_line(1, &line);
		printf("{%s} ret %d\n",line, ret);
		free(line);
		if (check_the_argument_valid(line))
		{
			write(1, "Error", 6);
			return(1);
		}




	}
	return(1);
}