
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// #include <stddef.h>
typedef struct		s_stack
{
	int				num; //значение
	int				pos; 
  int       chunk;
	struct s_stack	*next; // след значение
  struct s_stack	*prev; //предыд значение
}					t_stack;

int detect_len_of_stack(t_stack *stack);
t_stack *sa(t_stack *stack_a);
void *ss(t_stack **stack_a, t_stack **stack_b);
void ra(t_stack **stack_a);
void rra(t_stack **stack_a);
t_stack *find_on_index(t_stack *stack_a, int index);
t_stack *insert_into_stack(int argc, char **argv);
t_stack *addelem(t_stack *stack, int number, int pos);
t_stack *reset_index(t_stack *stack_a);


#endif