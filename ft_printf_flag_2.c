/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 08:40:53 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/15 09:18:45 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_width_supp_precision(t_input *s, va_list args)
{
	int	nb_char;
	int	tempo;

	tempo = 0;
	nb_char = 0;
	if (s->preci < 0 && s->width < s->count_char)
		nb_char += flag_less(s, args);
	nb_char = ft_pad(s, nb_char, tempo);
	if (s->negatif == 1)
		nb_char++;
	return (nb_char += ft_type(s, args) + tempo);
}

int	flag_zero_dot(t_input *s, va_list args)
{
	int	nb_char;
	int tempo;

	tempo = 0;
	nb_char = 0;
	if (s->preci < 0)
		return (nb_char += flag_zero(s, args));
	nb_char = ft_pad(s, nb_char, tempo);
	if (s->negatif == 1)
		nb_char++;
	return (nb_char += ft_type(s, args) + tempo);
}

int	ft_pad(t_input *s, int nb_char, int tempo)
{
	if (s->preci == 0 && s->dot == 1 && s->negatif == 1)
	{
		tempo += s->negatif;
		nb_char--;
	}
	if (s->preci < s->count_char)
	{
		if (s->preci == 0 && s->dot == 1 & s->nb_is_zero != 1)
			s->preci = s->count_char - s->negatif;
		else
			s->preci = s->count_char;
	}
	while (tempo + s->negatif < (s->width - s->preci))
	{
		ft_putchar(' ');
		tempo++;
	}
	if (s->negatif == 1)
		ft_putchar('-');
	while ((nb_char + s->count_char) < (s->preci))
	{
		ft_putchar('0');
		nb_char++;
	}
	return (nb_char + tempo);
}

int	width_neg(t_input *s, int nb_char)
{
	s->width *= -1;
	while (nb_char < s->width)
	{
		ft_putchar(' ');
		nb_char++;
	}
	return (nb_char++);
}
