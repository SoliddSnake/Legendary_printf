NAME = libftprintf.a

SOURCE = check_wigth.c\
flags.c\
flags_precision.c\
flags_size.c\
flags_zero.c\
ft_error.c\
ft_itoa_base.c\
ft_itoa_baseu.c\
ft_printf.c\
str_s.c\
check_float.c\
ft_pow.c\
multiplyfree.c\
float_round.c\
alternate.c\
filling_minus.c\
filling_without_minus.c\
check_digit.c\
without_dot.c\
negative_digit.c\
create_flags.c\
colors.c\
check_fd.c\
len_less.c\
more_five.c\
free_struct.c\
free_struct_un_float.c\
create_struct.c\
set_type.c\
set_flags.c\
find_width.c\
find_lh.c\
find_stars.c\
read_param.c\
find_end.c\
fill_struct.c\
find_stars_precision.c

SOURCE_LIB = ft_putchar.o ft_putstr.o ft_putstrstr.o ft_strrev.o ft_strlen.o\
ft_swap.o ft_isupper.o ft_islower.o\
ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o ft_memchr.o\
ft_memcmp.o ft_strdup.o ft_strcpy.o ft_strncpy.o\
ft_strcat.o ft_strncat.o ft_strlcat.o ft_strstr.o ft_strnstr.o ft_strcmp.o\
ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o\
ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_strchr.o\
ft_strrchr.o ft_putnbr.o ft_memalloc.o ft_memdel.o\
ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o ft_striteri.o ft_strmap.o\
ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o\
ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putendl.o ft_putchar_fd.o ft_putstr_fd.o\
ft_putendl_fd.o  ft_putnbr_fd.o ft_lstnew.o ft_lstdelone.o\
ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_strcut.o ft_strjoinfree.o\
ft_strjoinfreefree.o ft_abs.o

LIBFT_PATH = ./libft/
LIBFT = libft/libft.a
OBJECTS = ${SOURCE:.c=.o}
LIBFT_OBJ = $(addprefix $(LIBFT_PATH), $(SOURCE_LIB))

FLAGS = -Wall -Wextra -Werror

HEADER=libft\libft.h

all: $(LIBFT) $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS) $(LIBFT_OBJ)
	@ranlib $(NAME)

$(LIBFT):
	@make -C ./libft

$(OBJECTS): %.o : %.c
	@gcc -I $(HEADER) -c $<

clean:
	@make clean -C ./libft
	@/bin/rm -f *.o

fclean: clean
	@make fclean -C ./libft
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re