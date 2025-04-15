#--------------------------\\\\\___VARIABLES___/////---------------------------#

MAKEFLAGS	+= --no-print-directory

NAME		=	push_swap

CC			=	cc
FLAGS		=	-Wall -Werror -Wextra -g3

OBJ_DIR		=	obj
SRC_DIR		=	src \
				src/algo \
				srcops 

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

OBJ			=	$(patsubst %.c,${OBJ_DIR}/%.o,${SRC})

#----------------------------\\\\\___RULES___/////-----------------------------#

all:			${NAME} 

${OBJ_DIR}/%.o: %.c | ${OBJ_DIR}
				@mkdir -p $(dir $@)
				@${CC} ${FLAGS} -c $< -o $@

${OBJ_DIR}:
				@mkdir -p ${OBJ_DIR}

${LIBFT}:
				@echo "📡 Pulling libft..."
				@git clone https://github.com/abollia/libft.git > /dev/null 2>&1;
				@make -C libft

vpath %.c . ${SRC_DIR}

${NAME}:		${LIBFT} ${OBJ}
				@echo "🧠 Compiling ${NAME}..."
				@${CC} ${FLAGS} ${OBJ} ${LIBFT} -o ${NAME}
				@echo "✅🦾 ${NAME} is ready!"

clean:
				@echo "🚮 Removing project files..."
				@rm -rf ${OBJ_DIR}
				@make clean -C ./libft

fclean:			clean
				@echo "🚮 Removing project..."
				@rm -f ${NAME}
				@rm -rf libft
				@echo "❌ ${NAME} has been removed."

re:				fclean all

.PHONY:			all clean fclean re