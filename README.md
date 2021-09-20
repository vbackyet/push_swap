# effective-guacamole


t_stack *sort_the_stack(t_stack *stack_a,t_stack *stack_b)
{
   //Here we treat A as box 1 and B as box 0
   //At the i-th digit from the right, if the i-th digit of the top number of A is 0, we perform pb to put this number in stack B. 
   //Else, we perform ra to leave it in stack A. After we perform one operation on each number, each of them is in the box that corresponds 
   //to its digit, as how we put numbers in the boxes in radix sort.
  //1) узнать длину последнего номера
  //2) пройти цикл столько раз 
  //3) узнать длину стаки и пройтись по циклу и закидывать pb /ra
  //4) все получилось алилуя
  int length_the_biggest = depth(find_on_value(stack_a,find_maximum(stack_a, detect_len_of_stack(stack_a)-1,find_minimum(stack_a)))->base);
  int i = 0;
  while (length_the_biggest)
  {
    int length_of_the_stacky = detect_len_of_stack(stack_a);
    while (length_of_the_stacky)
    {
      if ((stack_a->base) % ft_power(10, i) == 0)
        perform_command(&stack_a, &stack_b, "pb");
      else
        perform_command(&stack_a, &stack_b, "ra");
      length_of_the_stacky--;
      while(stack_b->num)
        perform_command(&stack_a, &stack_b, "pa");
    }
    length_the_biggest--;
    i++;
  }
}


1) Сделать обработку валидности аргументов - цифры, не одинаковые 
2) Сделать чекер - бонусы
3) если а аргументе есть пробелы значи нужно делать split
