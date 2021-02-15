/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 08:36:40 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/15 09:46:25 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char_type(t_input *s, va_list args)
{
	int	c;
	int	nb_char;

	nb_char = 0;
	c = va_arg(args, int);
	ft_putchar(c);
	nb_char++;
	s->type = '\0';
	return (nb_char);
}

int	ft_str_p_type(t_input *s, va_list args)
{
	char	*str;
	int		nb_char;

	nb_char = 0;
	if (s->type == 's')
	{
		str = va_arg(args, char *);
		nb_char += ft_putstr(s, str);
	}
	if (s->type == 'p')
	{
		str = va_arg(args, void *);
		nb_char += 2;
		write(1, "0x", 2);
		nb_char += ft_putadress_hexa(s, str, "0123456789abcdef");
	}
	s->type = '\0';
	return (nb_char);
}

int	ft_d_i_type(t_input *s, va_list args)
{
	int	nb_char;
	int	integer;

	integer = 0;
	nb_char = 0;
	integer = va_arg(args, int);
	if (s->negatif == 1)
	{
		integer *= -1;
		s->negatif = 0;
	}
	nb_char += ft_putnbr(s, integer);
	if (integer <= -2147483648)
		nb_char = 10;
	s->type = '\0';
	return (nb_char);
}

int	ft_u_x_type(t_input *s, va_list args)
{
	int				nb_char;
	unsigned int	numunsigned;

	numunsigned = 0;
	nb_char = 0;
	if (s->type == 'u')
	{
		numunsigned = va_arg(args, int);
		nb_char += ft_putnbr_unsigned(s, numunsigned);
	}
	if (s->type == 'x')
	{
		numunsigned = va_arg(args, int);
		nb_char += ft_putnbr_base(s, numunsigned, "0123456789abcdef");
	}
	if (s->type == 'X')
	{
		numunsigned = va_arg(args, int);
		nb_char += ft_putnbr_base(s, numunsigned, "0123456789ABCDEF");
	}
	s->type = '\0';
	return (nb_char);
}

int	ft_type(t_input *s, va_list args)
{
	int	nb_char;

	nb_char = 0;
	if (s->type == 'c')
		nb_char += ft_char_type(s, args);
	if (s->type == 's' || s->type == 'p')
		nb_char += ft_str_p_type(s, args);
	if (s->type == 'd' || s->type == 'i')
		nb_char += ft_d_i_type(s, args);
	if (s->type == 'u' || s->type == 'x' || s->type == 'X')
		nb_char += ft_u_x_type(s, args);
	if (s->type == '%')
	{
		ft_putchar('%');
		nb_char++;
		s->type = '\0';
	}
	return (nb_char);
}
