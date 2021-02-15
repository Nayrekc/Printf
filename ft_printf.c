/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 08:52:57 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/15 09:24:21 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	gestion_flag(t_input *s, va_list args)
{
	int	nb_char;

	nb_char = 0;
	if (s->less == 1 && s->zero == 1)
		s->zero = 0;
	if (s->less == 1 && s->dot == 0 && s->zero == 0)
		nb_char += flag_less(s, args);
	if (s->type != 's')
	{
		if (s->less == 0 && s->dot == 1 && s->width_supp == 0 && s->zero == 0)
			nb_char += flag_dot(s, args);
		if (s->less == 0 && s->dot == 1 && s->width_supp == 1 && s->zero == 0)
			nb_char += ft_width_supp_precision(s, args);
		if (s->less == 0 && s->dot == 1 && s->zero == 1)
			nb_char += flag_zero_dot(s, args);
		if (s->less == 0 && s->dot == 0 && s->zero == 1)
			nb_char += flag_zero(s, args);
	}
	if (s->less == 1 && s->dot == 1 && s->zero == 0)
		nb_char += flag_less_dot(s, args);
	return (nb_char);
}

int	ft_conversion(t_input *s, va_list args)
{
	int	nb_char;

	nb_char = 0;
	nb_char += gestion_flag(s, args);
	while ((nb_char) + s->count_char < s->width - s->negatif)
	{
		ft_putchar(' ');
		nb_char++;
	}
	if (s->type == 'c' || s->type == 's' || s->type == 'p' ||
		s->type == 'd' || s->type == 'i' || s->type == 'u' ||
		s->type == 'x' || s->type == 'X' || s->type == '%')
	{
		if (s->negatif == 1)
			nb_char += ft_putneg();
		nb_char += ft_type(s, args);
	}
	if (s->width < 0)
		nb_char = width_neg(s, nb_char);
	return (nb_char);
}

int	r(const char *input, va_list args, t_input *s, va_list copy)
{
	int	nb_char;

	nb_char = 0;
	while (input[s->index])
	{
		if (input[s->index] == '%')
		{
			(s->index)++;
			if (input[s->index] == ' ')
				nb_char++;
			ft_initialize_structure(s);
			stru(s, input, args, copy);
			nb_char += ft_conversion(s, args);
		}
		else
		{
			ft_putchar(input[s->index]);
			(s->index)++;
			nb_char++;
		}
	}
	return (nb_char);
}

int	ft_printf(const char *input, ...)
{
	int		nb_char;
	va_list	args;
	va_list	copy;
	t_input	s;

	s.index = 0;
	va_start(args, input);
	va_copy(copy, args);
	nb_char = r(input, args, &s, copy);
	va_end(args);
	ft_initialize_structure(&s);
	return (nb_char);
}
