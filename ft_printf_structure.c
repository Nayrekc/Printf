/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:08:52 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/15 09:25:22 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_add(t_input *s, const char *input, va_list copy)
{
	if (input[s->index] == 'c' || input[s->index] == 's' ||
			input[s->index] == 'p' || input[s->index] == 'd' ||
			input[s->index] == 'i' || input[s->index] == 'u' ||
			input[s->index] == 'x' || input[s->index] == 'X' ||
			input[s->index] == '%')
	{
		s->type = input[s->index];
		ft_type_count(s, copy);
		(s->index)++;
	}
}

void	stru(t_input *s, const char *input, va_list args, va_list copy)
{
	if (input[s->index] == ' ')
	{
		ft_putchar(input[s->index]);
		while (input[s->index] == ' ')
			s->index++;
	}
	while (input[s->index] == '-' || input[s->index] == '0')
		ft_less_or_zero(s, input);
	ft_width(s, input);
	if (input[s->index] == '*')
		star(s, input, args, copy);
	while (input[s->index] == '.')
		dot(s, input, args, copy);
	ft_type_add(s, input, copy);
	if (s->width > s->preci)
		s->width_supp = 1;
}

void	ft_initialize_structure(t_input *s)
{
	s->less = 0;
	s->zero = 0;
	s->dot = 0;
	s->width = 0;
	s->preci = 0;
	s->count_char = 0;
	s->negatif = 0;
	s->width_supp = 0;
	s->type = '\0';
	s->nb_is_zero = 0;
}
