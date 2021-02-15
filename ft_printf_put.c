/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:08:21 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/15 10:02:11 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	unsigned char	d;

	d = (unsigned char)c;
	write(1, &c, 1);
}

int		ft_putstr(t_input *s, char *str)
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
			return (nb_char += ft_putstr_if_dot(s, str));
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
			nb_char++;
		}
	}
	return (nb_char);
}

int		ft_putstr_if_dot(t_input *s, char *str)
{
	int i;
	int nb_char;

	nb_char = 0;
	i = 0;
	if (s->dot == 1 && s->preci < 0)
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
			nb_char++;
		}
		return (nb_char);
	}
	while (str[i] && i < s->preci)
	{
		ft_putchar(str[i]);
		i++;
		nb_char++;
	}
	return (nb_char);
}

int		ft_putadress_hexa(t_input *s, void *str, char *base)
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
		ft_putchar(dest[i]);
		i++;
		nb_char++;
	}
	return (nb_char);
}

int		ft_putneg(void)
{
	int	nb_char;

	nb_char = 0;
	ft_putchar('-');
	nb_char++;
	return (nb_char);
}
