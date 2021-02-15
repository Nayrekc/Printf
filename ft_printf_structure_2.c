/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structure_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 08:41:18 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/15 09:25:28 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width(t_input *s, const char *input)
{
	s->width = ft_atoi(&input[s->index]);
	while (input[s->index] >= '0' && input[s->index] <= '9')
		(s->index)++;
}

void	ft_precision(t_input *s, const char *input)
{
	if (input[s->index] >= '0' || input[s->index] <= '9')
		s->preci = ft_atoi(&input[s->index]);
	while (input[s->index] >= '0' && input[s->index] <= '9')
		(s->index)++;
}

void	star(t_input *s, const char *input, va_list args, va_list copy)
{
	int cpy;

	(s->index)++;
	if (input[s->index] >= '0' || input[s->index] <= '9')
	{
		s->width = va_arg(args, int);
		cpy = va_arg(copy, int);
	}
	while (input[s->index] >= '0' && input[s->index] <= '9')
		(s->index)++;
}

void	ft_less_or_zero(t_input *s, const char *input)
{
	if (input[s->index] == '-')
	{
		s->index++;
		s->less = 1;
		if ((input[s->index]) == '-')
			s->index++;
	}
	if (input[s->index] == '0')
	{
		s->zero = 1;
		(s->index)++;
		if ((input[s->index]) == '-')
		{
			s->zero = 0;
			s->less = 1;
			s->index++;
		}
	}
	s->width = 1;
}

void	dot(t_input *s, const char *input, va_list args, va_list copy)
{
	int cpy;

	s->dot = 1;
	(s->index)++;
	if (input[s->index] >= '0' || input[s->index] <= '9')
		ft_precision(s, input);
	if (input[s->index] == '*')
	{
		(s->index)++;
		if (input[s->index] >= '0' || input[s->index] <= '9')
		{
			s->preci = va_arg(args, int);
			cpy = va_arg(copy, int);
		}
		while (input[s->index] >= '0' && input[s->index] <= '9')
			(s->index)++;
	}
	if (input[s->index] == '-')
	{
		(s->index)++;
		ft_precision(s, input);
		s->preci = s->preci * (-1);
	}
}
