#--------------------------\\\\\___VARIABLES___/////---------------------------#

MAKEFLAGS	+= --no-print-directory

NAME		=	push_swap

CC			=	cc
FLAGS		=	-Wall -Werror -Wextra -g3

#---------------------------\\\\\___SOURCES___/////----------------------------#

SRC			=	${MAIN} ${ALGO} ${OPS}

MAIN		=	./src/push_swap.c \
				./src/args_ops.c \
				./src/parsing_ops.c \
				./src/node_ops.c \
				./src/lst_utils.c

ALGO		=	./src/algo/sorting.c \
				./src/algo/targeting.c \
				./src/algo/sorting_ops.c \
				./src/algo/ops_counting.c \
				./src/algo/transfering.c

OPS			=	./src/ops/ops_swap.c \
				./src/ops/ops_push.c \
				./src/ops/ops_rotate.c \
				./src/ops/ops_rrotate.c

LIBFT		=	./libft/libft.a

OBJ			=	${SRC:.c=.o}

#----------------------------\\\\\___RULES___/////-----------------------------#

all:			${NAME} 

%.o: %.c
				@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${LIBFT}:
				@echo "🧠 Compiling libft..."
				@make -C libft

${NAME}:		${OBJ} ${LIBFT}
				@echo "🧠 Compiling ${NAME}..."
				@${CC} ${FLAGS} ${OBJ} ${LIBFT} -o ${NAME}
				@echo "✅ 🦾 ${NAME} is ready!"

clean:
				@echo "🚮 Removing project files..."
				@rm -f ${OBJ}
				@make clean -C ./libft

fclean:			clean
				@echo "🚮 Removing project..."
				@rm -f ${NAME}
				@rm -f ${LIBFT}
				@echo "❌ ${NAME} has been removed."

re:				fclean all

.PHONY:			all clean fclean re