CC		=	gcc

SHELL	:= /bin/bash

RED		= \033[1;31m
BLUE	= \033[1;34m
CYAN	= \033[1;36m
ORANGE	= \033[1;38;5;214m
GREEN	= \033[1;32m
RESET	= \033[0m
UP1		= \033[1F
BEGIN	= \033[0G
SAVE	= \0337
RESTORE	= \0338
INSET	= $(BEGIN)$(GREEN)+ $(BLUE)

MLXDIR	= MLX42

GLFW	= -lglfw

LIBS		= libft.a libmlx42.a

NAME		=	base

SRCS		=	main.c \
					input.c \
					events.c

SRCDIR	= src/

INC			=	-I ./include

OBJS		=	$(patsubst $(SRCDIR)%.c, obj/%.o, $(addprefix $(SRCDIR),$(SRCS)))

COMPILED	=	0

DONE_OBJS	=	$(wildcard obj/*.o)

ifeq ($(words $(filter-out $(DONE_OBJS), $(OBJS))), 0)
TO_COMPILE	=	$(words $(OBJS))
else
TO_COMPILE	=	$(words $(filter-out $(DONE_OBJS), $(OBJS)))
endif

PERCENT		=	$(shell echo \
				$$(($(COMPILED)*100/$(TO_COMPILE)))%)

ifeq ($(DEBUG), 1)
CFLAGS	= -Wall -Wextra -Werror -fsanitize=thread -g
else
CFLAGS	= -Wall -Wextra -Werror
endif

$(NAME): $(OBJS) $(LIBS) $(GLFW)
	@printf "$(INSET)"
	$(CC) $(CFLAGS) $(INC) $^ -o $@
	@printf "$(GREEN)+ $(ORANGE)Created "$(NAME)" executable.\n$(RESET)"

all: $(NAME)

.PHONY: clean fclean re rere debug

obj/%.o: $(SRCDIR)%.c
	@mkdir -p $(@D)
	$(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
	@printf "$(INSET)$(CYAN)%4s  $(RESET)" "$(PERCENT)"
	$(CC) $(CFLAGS) $(INC) -c $^ -o $@


libft.a:
	@printf "$(RED)- $(BLUE)"
	@make -C libft
	@printf "$(RESET)"
	cp ./libft/libft.a ./
	cp ./libft/include/* ./include

libmlx42.a:
	cmake $(MLXDIR) -B $(MLXDIR)/build && make -s -C $(MLXDIR)/build -j4
	cp ./MLX42/build/libmlx42.a ./
		cp ./MLX42/include/MLX42/MLX42.h ./include


clean:
	@printf "$(RED)- $(BLUE)"
	rm -rf obj
	@printf "$(RESET)"

fclean: clean
	@printf "$(RED)- $(BLUE)"
	rm -f $(NAME) $(LIBS)
	@printf "$(RESET)"

re: fclean all

run: $(NAME)
	./$(NAME)

debug:
	@make DEBUG=1