NAME =			fdf

NAME_DEBUG =	fdf_debug.a


SRCS =			main.c


DIR_OBJS = 		./.objs/

OBJS =			${addprefix ${DIR_OBJS},${SRCS:.c=.o}}

OBJS_DEBUG =	${addprefix ${DIR_OBJS},${SRCS:.c=_debug.o}}


FLAGS =			-Wall -Wextra -Werror -O3

FLAGS_DEBUG	=	${FLAGS} -g3 -fsanitize=address


MLX_L =			-L${MLX_PATH} -lmlx

MLX_A =			${MLX_PATH}libmlx.a

MLX_PATH =		minilibx_macos/


LIBFT_L =		-L${LIBFT_PATH} -lft

LIBFT_L_DEBUG =	-L${LIBFT_PATH} -lft_debug

LIBFT_A =		${LIBFT_PATH}libft.a

LIBFT_A_DEBUG =		${LIBFT_PATH}libft_debug.a

LIBFT_PATH =	libft/


FRAMEWORKS =	-framework OpenGL -framework AppKit


INCLUDES =		-I ${LIBFT_PATH}headers/ -I minilibx_macos/

HEADERS =


RMF =	 		rm -f

MKDIR = 		mkdir -p

MAKE_LIBFT =	${MAKE} -C ${LIBFT_PATH}

MAKE_MLX = 		${MAKE} -C ${MLX_PATH}

all:			${DIR_OBJS}
				@${MAKE} -j ${NAME}

$(NAME):		${OBJS}
				${MAKE_LIBFT}
				${MAKE_MLX}
				${CC} ${FLAGS} ${FRAMEWORKS} ${INCLUDES} ${MLX_L} ${LIBFT_L}\
					${OBJS} -o ${NAME}

${DIR_OBJS}%.o: %.c ${HEADERS} Makefile ${LIBFT_A} ${MLX_A}
				${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

debug:			${DIR_OBJS}
				${MAKE} -j ${NAME_DEBUG}

${NAME_DEBUG}:	${OBJS_DEBUG}
				${MAKE_LIBFT} debug
				${MAKE_MLX}
				${CC} ${FLAGS_DEBUG} ${FRAMEWORKS} ${INCLUDES} ${MLX_L}\
					${LIBFT_L_DEBUG} ${OBJS_DEBUG} -o ${NAME_DEBUG}

${DIR_OBJS}%_debug.o: %.c ${HEADERS} Makefile ${LIBFT_A_DEBUG} ${MLX_A}
					cc ${FLAGS_DEBUG} ${INCLUDES} -c $< -o $@

clean:
				${MAKE_MLX} clean
				${MAKE_LIBFT} clean
				${RMF} ${OBJS} ${OBJS_DEBUG}

fclean:			clean
				${MAKE_LIBFT} fclean
				${RMF} ${NAME} ${NAME_DEBUG}

re:				fclean
				${MAKE} all

re_debug:				fclean
				${MAKE} debug

${DIR_OBJS}: Makefile
			@echo ${OBJS} | tr ' ' '\n'\
				| sed 's|\(.*\)/.*|\1|'\
				| sed 's/^/${MKDIR} /'\
				| sh -s
			@# Prints all OBJS. 1 per line
				@# Removes the .o file names
				@# Adds mkdir -p at start of each lines
				@# Executes the script (Creates all folders)

.PHONY:			all debug clean fclean re re_debug
