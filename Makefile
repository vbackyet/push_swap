PUSH_SWAP = push_swap
CHECKER = checker
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

PUSH_SWAP_SRC = push_swap.c\
				main.c\
				utils.c\
				get_next_line1/get_next_line.c\
				get_next_line1/get_next_line_utils.c\



CHECKER_SRC = 	push_swap.c\
				checker_programm.c\
				utils.c\
				get_next_line1/get_next_line.c\
				get_next_line1/get_next_line_utils.c\


all : $(PUSH_SWAP) $(CHECKER)


PUSH_SWAP_OBJS =  $(PUSH_SWAP_SRC:.c=.o)

CHECKER_OBJS =  $(CHECKER_SRC:.c=.o)

$(PUSH_SWAP) :	$(PUSH_SWAP_OBJS)
				$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) -o $@


$(CHECKER) : $(CHECKER_OBJS)
			$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $@

clean: 
	$(RM) $(PUSH_SWAP_OBJS)
	$(RM) $(CHECKER_OBJS)


fclean: clean
		$(RM) $(PUSH_SWAP)
		$(RM) $(CHECKER)

re: 
	fclean
	all

.PHONY: all fclean clean re


