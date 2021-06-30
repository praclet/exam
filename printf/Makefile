NAME		:=	libftprintf.a

SRCS		:=	ft_printf.c			

CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror

AR			:=	ar
ARFLAGS		:=	rs


##########################################################

OBJS		:=	$(SRCS:.c=.o)
DEPS		:=	$(SRCS:.c=.d)


%.o			:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)(%.o)	:	%.o
	$(AR) $(ARFLAGS) $(NAME) $%

$(NAME)	:	 $(patsubst %,$(NAME)(%),$(OBJS))
