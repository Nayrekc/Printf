/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 08:41:10 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/15 09:45:41 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr(t_input *s, int n)
{
	long	nb;
	int		nb_char;

	nb = (long)n;
	nb_char = 0;
	if (nb == 0 && s->preci == 0 && s->dot == 1)
		return (nb_char);
	if (nb < 0)
	{
		n = n * -1;
		nb = nb * -1;
	}
	if (nb > 9)
		ft_putnbr(s, nb / 10);
	ft_putchar((nb % 10) + '0');
	while (n > 9)
	{
		n = n / 10;
		nb_char++;
	}
	nb_char++;
	return (nb_char);
}

int		ft_putnbr_unsigned(t_input *s, unsigned int n)
{
	unsigned int	nb;
	int				nb_char;

	nb = n;
	nb_char = 0;
	if (nb == 0 && s->preci == 0 && s->dot == 1)
		return (nb_char);
	if (nb > 9)
		ft_putnbr_unsigned(s, nb / 10);
	ft_putchar((nb % 10) + '0');
	while (n > 9)
	{
		n = n / 10;
		nb_char++;
	}
	nb_char++;
	return (nb_char);
}

int		ft_putnbr_base(t_input *s, unsigned int nbr, char *base)
{
	unsigned int	len_base;
	unsigned int	nb;
	int				nb_char;

	nb = nbr;
	len_base = ft_strlen(base);
	nb_char = 0;
	if (nb == 0 && s->preci == 0 && s->dot == 1)
		return (nb_char);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
		nb_char++;
	}
	if (nb >= len_base)
		ft_putnbr_base(s, (nb / len_base), base);
	ft_putchar(base[nb % len_base]);
	while (nbr >= len_base)
	{
		nbr = nbr / len_base;
		nb_char++;
	}
	nb_char++;
	return (nb_char);
}
