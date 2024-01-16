 LIBFT_DIR = libft
LIBFT_PATH = libft/libft.a 

INCLUDES = minitalk.h minitalk_bonus.h

CLIENT_NAME = client
CLIENT_SRCS = client.c

CLIENT_NAME_B = client_bonus
CLIENT_SRCS_B = client_bonus.c

SERVER_NAME = server
SERVER_SRCS = server.c

SERVER_NAME_B = server_bonus
SERVER_SRCS_B = server_bonus.c

CC = cc 
CFLAGS = -Wall -Werror -Wextra

all: ${CLIENT_NAME} ${SERVER_NAME}

${CLIENT_NAME}: ${CLIENT_SRCS} ${LIBFT_PATH} ${INCLUDES}
				${CC} ${CFLAGS} -o $@ ${CLIENT_SRCS} -L${LIBFT_DIR} -lft

${SERVER_NAME}: ${SERVER_SRCS} ${LIBFT_PATH} ${INCLUDES}
				${CC} ${CFLAGS} -o $@ ${SERVER_SRCS} -L${LIBFT_DIR} -lft

${LIBFT_PATH}:
				${MAKE} -C ${LIBFT_DIR}

bonus: ${CLIENT_NAME_B} ${SERVER_NAME_B}

${CLIENT_NAME_B} :
				${CC} ${CFLAGS} -o $@ ${CLIENT_SRCS_B} -L${LIBFT_DIR} -lft

${SERVER_NAME_B} :
				${CC} ${CFLAGS} -o $@ ${SERVER_SRCS_B} -L${LIBFT_DIR} -lft

clean:
				${MAKE} -C ${LIBFT_DIR} clean

fclean: clean;
				${MAKE} -C ${LIBFT_DIR} fclean
				rm -f ${CLIENT_NAME} ${SERVER_NAME} ${CLIENT_NAME_B} ${SERVER_NAME_B}

re:		fclean all

.PHONY: all clean fclean re