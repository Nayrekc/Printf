/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:10:52 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/15 11:01:30 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_input
{
	int		less;
	int		zero;
	int		dot;
	int		width;
	int		preci;
	int		index;
	int		count_char;
	int		nb_is_zero;
	int		negatif;
	int		width_supp;
	char	type;
}				t_input;

int				ft_atoi(const char *str);
int				ft_strlen(char *str);
void			ft_width(t_input *s, const char *input);
void			ft_precision(t_input *s, const char *input);
void			star(t_input *s, const char *input, va_list args, va_list copy);
void			ft_less_or_zero(t_input *s, const char *input);
void			dot(t_input *s, const char *input, va_list args, va_list copy);
void			ft_type_add(t_input *s, const char *input, va_list copy);
void			stru(t_input *s, const char *input, va_list args, va_list copy);
void			ft_initialize_structure(t_input	*s);
void			ft_putchar(char c);
int				ft_putstr(t_input *s, char *str);
int				ft_putstr_if_dot(t_input *s, char *str);
int				ft_putadress_hexa(t_input *s, void *str, char *base);
int				ft_putneg(void);
int				ft_putnbr(t_input *s, int n);
int				ft_putnbr_unsigned(t_input *s, unsigned int n);
int				ft_putnbr_base(t_input *s, unsigned int nbr, char *base);
int				ft_type(t_input *s, va_list args);
int				ft_char_type(t_input *s, va_list args);
int				ft_str_p_type(t_input *s, va_list args);
int				ft_d_i_type(t_input *s, va_list args);
int				ft_u_x_type(t_input *s, va_list args);
int				ft_putstr_count(t_input *s, char *str);
int				ft_putstr_if_dot_count(t_input *s, char *str);
int				ft_putadress_hexa_count(t_input *s, void *str, char *base);
int				ft_putnbr_count(t_input *s, int n);
int				ft_putnbr_count_unsigned(t_input *s, unsigned int n);
int				ft_putnbr_base_count(t_input *s, unsigned int nbr, char *base);
void			ft_type_count(t_input *s, va_list copy);
void			ft_str_p_type_count(t_input *s, va_list args);
void			ft_d_i_type_count(t_input *s, va_list copy);
void			ft_u_x_type_count(t_input *s, va_list copy);
int				flag_less(t_input *s, va_list args);
int				flag_dot(t_input *s, va_list args);
int				flag_zero(t_input *s, va_list args);
int				flag_less_dot(t_input *s, va_list args);
int				ft_width_supp_precision(t_input *s, va_list args);
int				flag_zero_dot(t_input *s, va_list args);
int				width_neg(t_input *s, int nb_char);
int				ft_pad(t_input *s, int nb_char, int tempo);
int				gestion_flag(t_input *s, va_list args);
int				ft_conversion(t_input *s, va_list args);
int				r(const char *input, va_list args, t_input *s, va_list copy);
int				ft_printf(const char *input, ...);

#endif
