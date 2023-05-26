NAME = philo

CFILES = philo.c check_number.c init_args.c thread_init.c

OBJ = ${CFILES:.c=.o}

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

CC = cc

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all