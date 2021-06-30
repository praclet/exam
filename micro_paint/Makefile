NAME			:=	micro_paint

SRCS			:=	main.c

SRCS_DIR		:=	./srcs/
HEADERS_DIR		:=	./headers/
OBJS_DIR		:=	./objs/
DEP_DIR			:=	./dependencies/

#################################################################

vpath				%.c $(SRCS_DIR)
vpath				%.h $(HEADERS_DIR)
vpath				%.o $(OBJS_DIR)
vpath				%.d $(DEP_DIR)

OBJS			:=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
DEP				:=	$(addprefix $(DEP_DIR), $(SRCS:.c=.d))

CC				:=	gcc
CFLAGS			:=	-g -Wall -Wextra -Werror $(addprefix -I,$(HEADERS_DIR))
DEPFLAGS		=	-MT $@ -MMD -MP -MF $(DEP_DIR)$*.d

all				:	$(NAME)

$(NAME)			:	$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o	:	%.c
					@mkdir -p $(DEP_DIR)
					@mkdir -p $(OBJS_DIR)
					$(CC) $(CFLAGS) $(DEPFLAGS) -o $@ -c $<

clean			:
					rm -rf $(OBJS_DIR)

fclean			:	clean
					rm -rf $(DEP_DIR)
					rm -rf $(NAME)

re				:	fclean	all

.PHONY			:	all clean fclean re

$(DEP)			:
include $(wildcard $(DEP))
