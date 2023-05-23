NAME = philo

CFILES = philo.c check_number.c

OBJ = ${CFILES:.c=.o}

CFLAGS = -Wall -Wextra -Werror

CC = cc

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all