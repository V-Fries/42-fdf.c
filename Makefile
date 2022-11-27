NAME =			fdf

NAME_DEBUG =	fdf_debug


HEADERS =		utils.h	\
				line_drawing/line_drawing.h	\
				parsing/parsing.h			\
				parsing/get_splited_lines.h	\
				perspective_projection/perspective_projection.h

INCLUDES =	-I ${LIBFT_PATH}headers/	\
			-I ${MLX_PATH}	\
			-I ${MLX_TOOLS_PATH}	\
			-I .	\
			-I line_drawing/	\
			-I parsing/	\
			-I perspective_projection/


SRCS =			main.c	\
				line_drawing/line_drawing.c					\
				line_drawing/bresenham_3d_driving_axis.c	\
				line_drawing/bresenham_3d.c					\
				perspective_projection/perspective_projection.c
				# parsing/parsing.c
				# parsing/get_splited_lines.c


DIR_OBJS = 		./.objs/

OBJS =			${addprefix ${DIR_OBJS},${SRCS:.c=.o}}

OBJS_DEBUG =	${addprefix ${DIR_OBJS},${SRCS:.c=_debug.o}}


FLAGS =			-Wall -Wextra -Werror -O3

FLAGS_DEBUG	=	${FLAGS} -g3 -fsanitize=address


MLX_L =		-L${MLX_PATH} -lmlx

MLX_A =		${MLX_PATH}libmlx.a

MLX_PATH =	minilibx_macos/


MLX_TOOLS_PATH =		mlx_tools/

MLX_TOOLS_HEADERS =		${MLX_TOOLS_PATH}mlx_tools.h

MLX_TOOLS_A =			${MLX_TOOLS_PATH}libmlx_tools.a

MLX_TOOLS_A_DEBUG =		${MLX_TOOLS_PATH}libmlx_tools_debug.a

MLX_TOOLS_L	=			-L${MLX_TOOLS_PATH} -lmlx_tools

MLX_TOOLS_L_DEBUG	=	-L${MLX_TOOLS_PATH} -lmlx_tools_debug


LIBFT_L =		-L${LIBFT_PATH} -lft

LIBFT_L_DEBUG =	-L${LIBFT_PATH} -lft_debug

LIBFT_A =		${LIBFT_PATH}libft.a

LIBFT_A_DEBUG =	${LIBFT_PATH}libft_debug.a

LIBFT_PATH =	libft/


SHARED_DEPENDENCIES =	${HEADERS} Makefile ${MLX_A}

DEFAULT_DEPENDENCIES =	${LIBFT_A} ${MLX_TOOLS_A}

DEBUG_DEPENDENCIES = 	${LIBFT_A_DEBUG} ${MLX_TOOLS_A_DEBUG}


FRAMEWORKS =			-framework OpenGL -framework AppKit


SHARED_L = ${MLX_L}

DEBUG_L = ${LIBFT_L_DEBUG} ${MLX_TOOLS_L_DEBUG}

DEFAULT_L = ${LIBFT_L} ${MLX_TOOLS_L}


RMF =	 		rm -f

MKDIR = 		mkdir -p

MAKE_LIBFT =	${MAKE} -C ${LIBFT_PATH}

MAKE_MLX_TOOLS = 		${MAKE} -C ${MLX_TOOLS_PATH}


all:			${DIR_OBJS}
				${MAKE_LIBFT}
				${MAKE_MLX_TOOLS}
				@${MAKE} -j ${NAME}

$(NAME):		${OBJS}
				${CC} ${FLAGS} ${FRAMEWORKS} ${INCLUDES} ${SHARED_L}\
					${DEFAULT_L} ${OBJS} -o ${NAME}

${DIR_OBJS}%.o: %.c ${SHARED_DEPENDENCIES} ${DEFAULT_DEPENDENCIES}
				${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

debug:			${DIR_OBJS}
				${MAKE_LIBFT} debug
				${MAKE_MLX_TOOLS} debug
				${MAKE} -j ${NAME_DEBUG}

${NAME_DEBUG}:	${OBJS_DEBUG}
				${CC} ${FLAGS_DEBUG} ${FRAMEWORKS} ${INCLUDES} ${SHARED_L}\
					${DEBUG_L} ${OBJS_DEBUG} -o ${NAME_DEBUG}

${DIR_OBJS}%_debug.o: %.c ${SHARED_DEPENDENCIES} ${DEBUG_DEPENDENCIES}
					cc ${FLAGS_DEBUG} ${INCLUDES} -c $< -o $@

clean:
				${MAKE_MLX_TOOLS} clean
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

run:		all
			./fdf

run_debug:	debug
			./fdf_debug

.PHONY:			all debug clean fclean re re_debug run run_debug
