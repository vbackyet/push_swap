#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"


int main(int argc, char **argv)
{
    t_stack         *stack_a;
    t_stack         *stack_b;
    //if (argc == 2)
    //{
      //char **my_values = ft_split(argv[1], " ");
      //printf("%s %d\n", my_values[0], len_of_the_args(my_values));
      //argc += (len_of_the_args(my_values) - 2);
      //argv = my_values;
    //}
    if (check_the_argument(argc, argv))
    {
        write(1, "Error\n", 6);
        //printf("%d\n", check_the_argument(argc, argv));
        return(1);
    }

    stack_a = insert_into_stack(argc, argv);
    stack_a = sort_and_index(stack_a);
    stack_a = make_base(stack_a);
    //printf("\nstack_is_sorted: %d", the_stack_is_sorted(stack_a));
    // listprint(stack_a);
    stack_b = NULL;
    //stack_b = insert_into_stack(4, a);
    //stack_b = sort_and_index(stack_b);
    //stack_b = make_base(stack_b);
    stack_a = sort_the_stack(stack_a, stack_b);
    
    //  stack_b = sort_and_index(stack_b);
    //perform_command(&stack_a, &stack_b, "pa");
    // printf("\nafter:");
    // listprint(stack_a);
    
    
    
    // printf("\nb:");
    // listprint(stack_b);
    // printf("\n");


    // printf("\n\n\n\n\n");



    // rra(&stack_a);
    // printf("\na:");
    // listprint(stack_a);
    // printf("\nb:");
    // listprint(stack_b);
    // printf("\n");


}