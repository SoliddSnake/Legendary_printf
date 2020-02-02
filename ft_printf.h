/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsance <jsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:50:52 by nriker            #+#    #+#             */
/*   Updated: 2019/10/30 14:11:46 by jsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_limits.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdarg.h>

struct		s_parts
{
	unsigned long long	mantisa :	64;
	unsigned int		exponent :	15;
	unsigned int		sign :		1;
};

typedef union u_union	t_union;

union		u_union
{
	long double		f;
	struct s_parts	parts;
};

typedef struct s_multiply	t_multiply;

struct		s_multiply
{
	size_t	len_s1;
	size_t	len_s2;
	int		i;
	int		j;
	int		i_s1;
	int		i_s2;
	int		carry;
	int		num1;
	int		num2;
	int		sum;
	char	*res;
};

typedef struct s_float	t_float;

struct		s_float
{
	int		exp;
	int		inf_nan;
	char	*del;
	char	*man;
	char	*str_exp;
};

typedef struct s_flags	t_flags;

struct		s_flags
{
	char				*s_param;
	unsigned long long	ull_param;
	long long			ll_param;
	long double			ld_param;
	float				d_param;
	size_t				found_lll;
	size_t				found_minus;
	size_t				found_plus;
	size_t				found_space;
	size_t				found_zero;
	size_t				found_octotorp;
	size_t				found_dot;
	size_t				found_point;
	int					nr_width;
	size_t				undefind;
	int					fprecision;
	size_t				hsize;
	size_t				lsize;
	int					zero;
	int					pzero;
	int					len_rev_s;
	int					count;
	char				*rev_s;
	char				*right_s;
	char				*tmp;
	char				*main_str;
	char				type;
};

int			ft_printf(const char *s, ...);
int			ft_nblen_unsigned(unsigned int n);
int			ft_nblen(int nb);
void		ft_putnbr_unsigned(unsigned int nb);
void		ft_putnbr_hexadecimal(unsigned int nb, char letter);
void		ft_putnbr_float(float nb);
void		ft_putnbr_exponent_low(float nb);
void		ft_putnbr_exponent_up(float nb);
void		ft_putnbr_shortfloat(float nb);
int			flags(t_flags *fl, va_list args);
void		ft_error(void);
char		*flags_zero(va_list args, t_flags *fl);
char		*ft_itoa_base_xxx(long long numb, int base);
char		*flags_size(char *s, va_list args, t_flags *fl);
char		*flags_precision(t_flags *fl);
char		*ft_itoa_baseu(unsigned long long n, int base, int uppercase);
char		*ft_itoa_base(long long value, int base, int content);
char		*check_width(const char *src, char *str, t_flags *fl);
void		create_flags(t_flags **flags);
char		*str_s(char *s, char *str, t_flags *fl);
int			check_float(t_flags *fl, va_list args);
void		create_union(t_union **un);
void		create_struct_float(t_float **sfl);
char		*multiplyfree(const char *s1, const char *s2);
void		free_struct_un_float(t_union *un, t_float *sfl);
char		*float_round(const char *str, t_flags *fl);
char		*alternate(t_flags *flags, char *str);
char		*filling(size_t len, t_flags *flags, char *str);
char		*negative_dig(t_flags *flags, char *str, size_t len);
char		*float_without_minus(size_t len, t_flags *flags, char *str);
char		*pointer(size_t len, t_flags *flags, char *str);
char		*with_dot(size_t len, t_flags *flags, char *str);
int			check_digit(char *str);
char		*without_dot(size_t len, t_flags *flags, char *str);
int			colors(char *s);
void		check_fd(t_flags *fl);
char		*len_less(const char *str, t_flags *fl, size_t len);
void		more_five(char *copy, t_flags *fl, size_t len, size_t precision);
int			free_struct(t_flags *fl);
void		free_struct_un_float(t_union *un, t_float *sfl);
void		create_struct(t_flags **flags, char *s, va_list args);
void		set_type(t_flags *flags, char *s);
void		set_flags(t_flags *flags, char *copy);
void		find_width(t_flags **f, char *s, int i);
int			find_lh(t_flags **flags, char *s);
int			find_stars(t_flags *fl, va_list args);
void		read_param(t_flags *fl, va_list args);
int			find_end(const char *str);
void		fill_struct(const char *str, t_flags **struct_flags, va_list args);
int			find_stars_precision(t_flags *fl, va_list args, int *i);

#endif
