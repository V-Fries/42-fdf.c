NAME =			libmlx_tools.a

NAME_DEBUG =	libmlx_tools_debug.a


SRCS =			mlx_tools.c


DIR_OBJS = 		./.objs/

OBJS =			${addprefix ${DIR_OBJS},${SRCS:.c=.o}}

OBJS_DEBUG =	${addprefix ${DIR_OBJS},${SRCS:.c=_debug.o}}


FLAGS =			-Wall -Wextra -Werror -O3

DEBUG_FLAGS	=	${FLAGS} -g3 -fsanitize=address


MLX_PATH =		../minilibx_macos/

MLX_A =			${MLX_PATH}libmlx.a


RMF =	 		rm -f

MKDIR = 		mkdir -p


INCLUDES =		-I headers/ \
				-I ${MLX_PATH}

HEADERS = 		mlx_tools.h

MAKE_MLX =		${MAKE} -C ${MLX_PATH}

all:			${DIR_OBJS}
				${MAKE_MLX}
				${MAKE} -j ${NAME}

debug:			${DIR_OBJS}
				${MAKE_MLX}
				${MAKE} -j ${NAME_DEBUG}

$(NAME):		${OBJS}
				ar rcs ${NAME} ${OBJS}

${NAME_DEBUG}: ${OBJS_DEBUG}
				ar rcs ${NAME_DEBUG} ${OBJS_DEBUG}

${DIR_OBJS}%.o: %.c ${HEADERS} Makefile ${MLX_A}
				cc ${FLAGS} ${INCLUDES} -c $< -o $@

${DIR_OBJS}%_debug.o: %.c ${HEADERS} Makefile ${MLX_A}
				cc ${FLAGS_DEBUG} ${INCLUDES} -c $< -o $@

${DIR_OBJS}: Makefile
				@echo ${OBJS} | tr ' ' '\n'\
					| sed 's|\(.*\)/.*|\1|'\
					| sed 's/^/${MKDIR} /'\
					| sh -s
				@# Prints all OBJS. 1 per line
					@# Removes the .o file names
					@# Adds mkdir -p at start of each lines
					@# Executes the script (Creates all folders)

clean:
				${MAKE_MLX} clean
				${RMF} ${OBJS} ${OBJS_DEBUG}


fclean:			clean
				${RMF} ${NAME} ${NAME_DEBUG}

re:				fclean
				${MAKE} all

.PHONY:			all debug clean fclean re
