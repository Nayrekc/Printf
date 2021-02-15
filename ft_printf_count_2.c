/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_count_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 08:40:32 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/15 09:18:48 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_base_count(t_input *s, unsigned int nbr, char *base)
{
	unsigned int	len_base;
	unsigned int	nb;
	int				nb_char;

	nb = nbr;
	len_base = ft_strlen(base);
	nb_char = 0;
	if (nb == 0 && s->preci == 0 && s->dot == 1)
	{
		s->nb_is_zero = 1;
		return (nb_char++);
	}
	if (nb >= len_base)
	{
		ft_putnbr_base_count(s, (nb / len_base), base);
	}
	while (nbr >= len_base)
	{
		nbr = nbr / len_base;
		nb_char++;
	}
	nb_char++;
	return (nb_char);
}
