#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>



int check_the_argument(int argc, char **argv)
{
    //Проверка аргументов
    //some arguments aren’t integers, some arguments arebigger than an integer, and/or there are duplicates.
  return(0);
}


typedef struct		s_stack
{
	int				num; //значение
	int				pos; 
  int       chunk;
	struct s_stack	*next; // след значение
  struct s_stack	*prev; //предыд значение
}					t_stack;




// https://github.com/sshiling/42-push_swap

t_stack *addelem(t_stack *stack, int number, int pos)
{
  t_stack *temp, *p;
  temp = (t_stack*)malloc(sizeof(t_stack));
  p = stack->next; // сохранение указателя на следующий узел
  stack->next = temp; // предыдущий узел указывает на создаваемый
  temp->num = number; // сохранение поля данных добавляемого узла
  temp->pos = pos;
  temp->next = p; // созданный узел указывает на следующий узел
  temp->prev = stack; // созданный узел указывает на предыдущий узел
  if (p != NULL)
    p->prev = temp;
}


t_stack init_stack(int first_argumnent, int position)
{
  t_stack         *stack;

}


t_stack *insert_into_stack(int argc, char **argv)
{
    t_stack         *stack;
    t_stack         *first_el_of_stack;
    int i;
    int pos_index;

    pos_index = 0;
    // printf("%d <- сколько аргументов\n",argc);
    stack = (t_stack *)malloc(sizeof(t_stack));
    stack->num = atoi(argv[1]);
    stack->chunk = 0;
    stack->pos = pos_index;
    stack->next = NULL; // указатель на следующий узел
    stack->prev = NULL; // указатель на предыдущий узел
    // printf("%d <- сколько аргументов\n",argc);
    i = 2;
    // printf('%d quant\n',argc);
    first_el_of_stack = stack;
    while (argc > i)
    {
      // printf("%d <- сколько аргументов\n",argc);
        pos_index++;
        addelem(stack, atoi(argv[i]), pos_index);
        i++;
        stack = stack->next;
    }

    //присоединение других узлов к превоначальному
    return(first_el_of_stack);
}


void listprint(t_stack *lst)
{
  t_stack *p;
  p = lst;
  while (p != NULL) 
  {
    printf("{%d | %d}", p->num, p-> pos); // вывод значения элемента p
    p = p->next; // переход к следующему узлу
  }  // условие окончания обхода
}

int detect_len_of_stack(t_stack *stack)
{
  int i;

  i = 0;
  while (stack-> next != NULL)
  {
    i++;
    stack = stack-> next;
  }
  return(i + 1);
}

t_stack *find_on_index(t_stack *stack_a, int index)
{

  while (index != stack_a->pos || !stack_a)
  {
    stack_a = stack_a -> next;
    // printf("%d - %d",stack_a->pos, index);
  }
  return stack_a;
}

t_stack *reset_index(t_stack *stack_a)
{
  t_stack *tmp;
  tmp = stack_a;
  int i = 0;
  while (tmp != NULL) 
  {
    tmp -> pos = i;
    // printf("{%d | %d}",tmp->num, tmp-> pos);
    tmp = tmp->next; // переход к следующему узлу
    i++;
  }  // условие окончания обхода
  return stack_a;
}


t_stack *sa(t_stack *stack_a)
{
  int len;
  t_stack *tmp;

  len = detect_len_of_stack(stack_a);
  if (len > 1)
  {
    // printf("HERE !\n");
    tmp = find_on_index(stack_a, 1);
    stack_a -> next = find_on_index(stack_a, 2);
    stack_a -> prev = tmp;
    // printf("%d", stack_a->num);
    // stack_a -> next = tmp;
    tmp -> next = stack_a;
    tmp -> prev = NULL;
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


// sa :swap a- swap the first 2 elements at the top of stack a. Do nothing if thereis only one or no elements).
// sb :swap b- swap the first 2 elements at the top of stackb. Do nothing if thereis only one or no elements).
// ss :sa and sb at the same time.
 

int main(int argc, char **argv)
{
    t_stack         *stack_a;
    t_stack         *stack_b;

    char *a[4];
    a[0] = "1";
    a[1] = "2";
    a[2] = "3";
    a[3] = "4";
    if (check_the_argument(argc, argv))
        write(1, "Error\n", 6);
    stack_a = insert_into_stack(argc, argv);
    stack_b = insert_into_stack(4, a);
    ss(&stack_a, &stack_b);
    printf("\na:");
    stack_a = sa(stack_a);
    listprint(stack_a);
    printf("\nb:");
    listprint(stack_b);
    printf("\n");
}

//atoi
// sa :swap a- swap the first 2 elements at the top of stacka. Do nothing if thereis only one or no elements).





// pb  pops the first elememt on A and puts it on top of B
// ra  rotates stuck A up by one

// 1) Стак А в массив
// 2) отсортировать
// 45 34 1 23 6 3
// 1 3 6 23 34 45
// 3) Найти индекс миддла
// 2 индекс - 23

// 4) Я хожу по стаку А и все что меньше 23 перекидываю в стак Б
// 4.1 - 45 - не меньше чем 23 - идем ra
// 3 6 23 1 34 45 
// 4.2 - 3 - pb 
// 4.3 - 6 - pb
// 4.4 - 23 нет 45 тоже нет
// поэтому мы в топ переводим все пока не анйдем то что меньше и то что 3 элиента 
// 45 34 1 23 ra 
// 34 1 23 45
// 1 23 45 34 - pb
// 23 45 34 
// 5) Повторить то же самое с остатком (23 45 34) -> 23 34 45
// Серединка 45
// Нам повезло 23 -  меньше чем 45 
// Что у нас в стаке 45 
// (23 1 6 3) и сам миддл 34
// (34 23 1 6 3)
// 6) Делаем пока не останется 2 или меньше елементов- при необходимости сорируем
// ({45} {23} {1 6 3})
// 7)Делать то же самое только в обратном порядке
// [45] - > [34] -> [23] -> []
// 1) Еслив оставшемяся больше чем 2 чанка - то мы не можем просто делаем 
// rb -  а когда нашли то rrb - чтобы все исправить!!!!
// СДЕЛАТЬ чекер на то что чанк уже остортирован!!!!