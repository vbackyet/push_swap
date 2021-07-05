#include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

// int     main(int aa, char **args)
// {
//     t_stack         *stack_a;
//     t_stack         *stack_b;
//     t_binary_tree   *root;
//     int             status;

//     root = NULL;
//     stack_b = NULL;
//     stack_a = create_stack_a(args, &root, aa);
//     if ((errno & EINVAL) == 0 && aa > 1)
//     {
//         stack_b = init_stack();
//         status = cmp_stack_to_sorted_tree(stack_a, root);
//         init_rank(root);
//         fill_rank(stack_a, root);
//         if (status == STACK_NOT_SORTED)
//             sorting_process(stack_a, stack_b);
//         flush_buffer_str();
//     }
//     else
//         write(1, RED"Error\n"COLOR_RESET, 15);
//     free_structures(stack_a, stack_b, root);
//     return (0);
// }

int check_the_argument(int argc, char **argv)
{
    //Проверка аргументов
    //some arguments aren’t integers, some arguments arebigger than an integer, and/or there are duplicates.
  return(0);
}


typedef struct		s_stack
{
	int				num; //значение
	// int				diff; 
	struct s_stack	*next; // след значение
    struct s_stack	*prev; //предыд значение
}					t_stack;




// https://github.com/sshiling/42-push_swap

t_stack *addelem(t_stack *stack, char *number)
{
  t_stack *temp, *p;
  temp = (t_stack*)malloc(sizeof(t_stack));
  p = stack->next; // сохранение указателя на следующий узел
  stack->next = temp; // предыдущий узел указывает на создаваемый
  temp->num = number; // сохранение поля данных добавляемого узла
  temp->next = p; // созданный узел указывает на следующий узел
  temp->prev = stack; // созданный узел указывает на предыдущий узел
  if (p != NULL)
    p->prev = temp;
  return(temp);
}


t_stack *insert_into_stack(int argc, char **argv)
{
    //создание узла 
    t_stack         *stack;
    int i;

    stack = (t_stack *)malloc(sizeof(t_stack));
    stack->num = 0;
    stack->next = NULL; // указатель на следующий узел
    stack->prev = NULL; // указатель на предыдущий узел
    i = 0;
    while (argc < i)
    {
        addelem(stack, argv[i]);
    }

    //присоединение других узлов к превоначальному
    return(stack);
}


void listprint(t_stack *lst)
{
  t_stack *p;
  p = lst;
  do {
    printf("%d ", p->num); // вывод значения элемента p
    p = p->next; // переход к следующему узлу
  } while (p != NULL); // условие окончания обхода
}


int main(int argc, char **argv)
{
    t_stack         *stack_a;
    t_stack         *stack_b;


    if (check_the_argument(argc, argv))
        write(1, "Error\n", 6);
    printf("%d\n",argc);
    int i = 0;

    while (argc - i > 0) 
    {
      printf("%s\n",argv[i]);
      i++;
    }

    // stack_a = insert_into_stack(argc, argv);
}











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