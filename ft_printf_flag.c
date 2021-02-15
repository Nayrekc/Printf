/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 08:41:07 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/15 09:19:02 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_less(t_input *s, va_list args)
{
	int	nb_char;

	nb_char = 0;
	if (s->negatif == 1)
		nb_char += ft_putneg();
	nb_char += ft_type(s, args);
	while ((nb_char) < s->width)
	{
		ft_putchar(' ');
		nb_char++;
	}
	return (nb_char);
}

int	flag_dot(t_input *s, va_list args)
{
	int	nb_char;

	nb_char = 0;
	if (s->preci < 0)
		nb_char += flag_less(s, args);
	if (s->negatif == 1)
		ft_putchar('-');
	if (s->type != 's')
	{
		while ((nb_char + s->count_char) < s->preci)
		{
			ft_putchar('0');
			nb_char++;
		}
	}
	if (s->type == 's')
		nb_char += flag_less(s, args);
	if (s->negatif == 1)
		nb_char++;
	return (nb_char += ft_type(s, args));
}

int	flag_zero(t_input *s, va_list args)
{
	int nb_char;

	nb_char = 0;
	if (s->negatif == 1)
		ft_putchar('-');
	while ((nb_char + s->negatif) + s->count_char < s->width)
	{
		ft_putchar('0');
		nb_char++;
	}
	if (s->negatif == 1)
		nb_char++;
	return (nb_char += ft_type(s, args));
}

int	flag_less_dot(t_input *s, va_list args)
{
	int	nb_char;

	nb_char = 0;
	if (s->preci >= s->width)
		nb_char += flag_dot(s, args);
	if (s->preci < s->width)
	{
		nb_char += flag_dot(s, args);
		while (nb_char < s->width)
		{
			ft_putchar(' ');
			nb_char++;
		}
	}
	return (nb_char);
}
