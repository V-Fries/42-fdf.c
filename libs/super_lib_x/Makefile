NAME =			libslx.a

NAME_DEBUG =	libslx_debug.a


HEADERS_NO_PATH =	keys.h		\
					lines.h		\
					matrices.h	\
					mlx_tools.h	\
					points.h	\
					vector.h

HEADERS = 			${addprefix includes/,${HEADERS_NO_PATH}}	\
					srcs/utils/slx_utils.h


C_FILES =		lines/clip_line.c			\
				lines/create_t_line_point.c	\
				lines/draw_line.c			\
\
				matrices/matrix_multiplication.c	\
				matrices/projection_matrix.c		\
				matrices/rotation_matrices.c		\
				matrices/translation_matrix.c		\
				matrices/world_matrix.c				\
\
				utils/utils.c	\
\
				vectors/vector_math.c	\
				vectors/vector_tools.c	\
\
				keys.c	\
				mlx_tools.c

SRCS = ${addprefix srcs/,${C_FILES}}


DIR_OBJS = 		./.objs/

OBJS =			${addprefix ${DIR_OBJS},${SRCS:.c=.o}}

OBJS_DEBUG =	${addprefix ${DIR_OBJS},${SRCS:.c=_debug.o}}


FLAGS =			-Wall -Wextra -Werror -O3

DEBUG_FLAGS	=	${FLAGS} -g3 -fsanitize=address


MLX_PATH =		minilibx_macos/

MLX_A =			${MLX_PATH}libmlx.a


RMF =	 		rm -f

MKDIR = 		mkdir -p


INCLUDES =		-I includes/	\
				-I srcs/utils/	\
				-I ${MLX_PATH}


MAKE_MLX =		${MAKE} -C ${MLX_PATH}


all:			${DIR_OBJS}
				${MAKE_MLX}
				${MAKE} ${NAME}

debug:			${DIR_OBJS}
				${MAKE_MLX}
				${MAKE} ${NAME_DEBUG}

$(NAME):		${OBJS}
				cp ${MLX_PATH}libmlx.a ${NAME}
				ar rcs ${NAME} ${OBJS}

${NAME_DEBUG}: ${OBJS_DEBUG}
				cp ${MLX_PATH}libmlx.a ${NAME_DEBUG}
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
