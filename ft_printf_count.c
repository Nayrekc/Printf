/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:12:44 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/15 10:02:23 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_count(t_input *s, char *str)
{
	int	i;
	int	nb_char;

	i = 0;
	nb_char = 0;
	if (s->type == 's' && str == NULL)
		str = "(null)";
	if (str)
	{
		if (s->dot == 1)
			return (nb_char += ft_putstr_if_dot_count(s, str));
		while (str[i])
		{
			i++;
			nb_char++;
		}
	}
	if (s->type == 's' && str == NULL)
		nb_char = 6;
	return (nb_char);
}

int		ft_putstr_if_dot_count(t_input *s, char *str)
{
	int i;
	int nb_char;

	nb_char = 0;
	i = 0;
	if (s->dot == 1 && s->preci < 0)
	{
		while (str[i])
		{
			i++;
			nb_char++;
		}
		return (nb_char);
	}
	while (str[i] && i < s->preci)
	{
		i++;
		nb_char++;
	}
	return (nb_char);
}

int		ft_putadress_hexa_count(t_input *s, void *str, char *base)
{
	char			dest[9];
	int				i;
	unsigned long	nb;
	int				nb_char;

	nb = (unsigned long)str;
	i = 8;
	nb_char = 0;
	if (nb == 0 && s->dot == 1)
		return (nb_char);
	while ((nb / ft_strlen(base) > 0))
	{
		dest[i] = base[((nb % ft_strlen(base)))];
		nb = nb / ft_strlen(base);
		i--;
	}
	dest[i] = base[((nb % ft_strlen(base)))];
	while (i < 9)
	{
		i++;
		nb_char++;
	}
	return (nb_char);
}

int		ft_putnbr_count(t_input *s, int n)
{
	long	nb;
	int		nb_char;

	nb = (long)n;
	nb_char = 0;
	if (nb == 0 && s->preci == 0 && s->dot == 1)
	{
		s->nb_is_zero = 1;
		return (nb_char++);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		n = n * -1;
		nb_char++;
	}
	if (nb > 9)
		ft_putnbr_count(s, nb / 10);
	while (n > 9)
	{
		n = n / 10;
		nb_char++;
	}
	nb_char++;
	return (nb_char);
}

int		ft_putnbr_count_unsigned(t_input *s, unsigned int n)
{
	unsigned int	nb;
	int				nb_char;

	nb = n;
	nb_char = 0;
	if (nb == 0 && s->preci == 0 && s->dot == 1)
	{
		s->nb_is_zero = 1;
		return (nb_char++);
	}
	if (nb > 9)
		ft_putnbr_count_unsigned(s, nb / 10);
	while (n > 9)
	{
		n = n / 10;
		nb_char++;
	}
	nb_char++;
	return (nb_char);
}
