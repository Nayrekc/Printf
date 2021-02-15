/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 08:50:20 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/15 10:25:02 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_type_count(t_input *s, va_list copy)
{
	int	arg;

	arg = va_arg(copy, int);
	s->count_char++;
}

void	ft_str_p_type_count(t_input *s, va_list copy)
{
	char	*arg;

	if (s->type == 's')
	{
		arg = va_arg(copy, char *);
		s->count_char += ft_putstr_count(s, arg);
	}
	if (s->type == 'p')
	{
		arg = va_arg(copy, void *);
		s->count_char += 2;
		s->count_char += ft_putadress_hexa_count(s, arg, "0123456789abcdef");
	}
}

void	ft_d_i_type_count(t_input *s, va_list copy)
{
	int	arg;

	arg = va_arg(copy, int);
	if (arg < 0)
	{
		s->negatif = 1;
		s->count_char -= 1;
	}
	s->count_char += ft_putnbr_count(s, arg);
	if (arg <= -2147483648)
		s->count_char = 10;
}

void	ft_u_x_type_count(t_input *s, va_list copy)
{
	unsigned int	arg;

	arg = 0;
	if (s->type == 'u')
	{
		arg = va_arg(copy, unsigned int);
		s->count_char += ft_putnbr_count_unsigned(s, arg);
	}
	if (s->type == 'x')
	{
		arg = va_arg(copy, unsigned int);
		s->count_char += ft_putnbr_base_count(s, arg, "0123456789abcdef");
	}
	if (s->type == 'X')
	{
		arg = va_arg(copy, unsigned int);
		s->count_char += ft_putnbr_base_count(s, arg, "0123456789ABCDEF");
	}
}

void	ft_type_count(t_input *s, va_list copy)
{
	if (s->type == 'c')
		ft_char_type_count(s, copy);
	if (s->type == 's' || s->type == 'p')
		ft_str_p_type_count(s, copy);
	if (s->type == 'd' || s->type == 'i')
		ft_d_i_type_count(s, copy);
	if (s->type == 'u' || s->type == 'x' || s->type == 'X')
		ft_u_x_type_count(s, copy);
	if (s->type == '%')
	{
		s->preci = 0;
		s->count_char++;
	}
}
