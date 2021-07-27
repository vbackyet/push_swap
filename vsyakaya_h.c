#include "push_swap.h"

t_stack *sa(t_stack *stack_a)
{
  int len;
  t_stack *tmp;

  len = detect_len_of_stack(stack_a);
  if (len > 1)
  {
    tmp = find_on_index(stack_a, 1);
    stack_a -> next = find_on_index(stack_a, 2);
    stack_a -> prev = tmp;
    // printf("%d", stack_a->num);
    // stack_a -> next = tmp;
    tmp -> next = stack_a;
    tmp -> prev = 0;
    stack_a = stack_a -> prev;
    stack_a = reset_index(stack_a);
  }
  return(stack_a);
}


void *ss(t_stack **stack_a, t_stack **stack_b)
{
  *stack_a = sa(*stack_a);
  *stack_b = sa(*stack_b);
}

void *pa(t_stack **stack_a, t_stack **stack_b)
{
  int len;
  t_stack *tmp;

  len = detect_len_of_stack(*stack_b);
  if (len > 0)
  {
      tmp = find_on_index(*stack_a, 0);
      *stack_a = (*stack_a)->next;
      (*stack_a)->prev = 0;
      *stack_a = reset_index(*stack_a);
      (*stack_b) -> prev = tmp;
      tmp -> next = *stack_b;
      *stack_b = (*stack_b) -> prev;
      *stack_b = reset_index(*stack_b);
  }
}


void ra(t_stack **stack_a)
{
  t_stack *head;
  int len;

  len = detect_len_of_stack(*stack_a);
  head = (*stack_a);
  (*stack_a)  = (*stack_a)-> next;
  (*stack_a)-> prev = 0;
  head -> prev = find_on_index(*stack_a,len -1);
  head -> next = 0;
  find_on_index(*stack_a,len -1) -> next = head;
  *stack_a = reset_index(*stack_a);
}


void rra(t_stack **stack_a)
{
  t_stack *tail;
  int len;

  len = detect_len_of_stack(*stack_a);
  tail = find_on_index(*stack_a,len -1);
  find_on_index(*stack_a,len -2) -> next = 0;
  tail -> prev = 0;
  tail -> next = *stack_a;
  *stack_a = tail;
  // listprint(*stack_a);
  // find_on_index(*stack_a,len -1) -> next = head;
  *stack_a = reset_index(*stack_a);
}

// sa :swap a- swap the first 2 elements at the top of stack a. Do nothing if thereis only one or no elements).
// sb :swap b- swap the first 2 elements at the top of stackb. Do nothing if thereis only one or no elements).
// ss :sa and sb at the same time.
 


//  pa :push a- take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
//  pb :push b- take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
//  ra :rotate a- shift up all elements of stack a by 1. The first element becomes the last one.


// rr :ra and rb at the same time.
// rra :reverse rotate a- shift down all elements of stackaby 1. The last elementbecomes the first one
// rrb :reverse rotate b- shift down all elements of stackbby 1. The last element becomes the first one.
// rrr :rra and rrb at the same time.