/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:33:16 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/09 13:52:37 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_digit(long int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		digit = 1;
	if (n < 0)
	{
		n *= -1;
		digit++;
	}
	while (n > 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	int			digit;
	int			i;
	char		*rt;
	long int	nb;

	nb = (long int)n;
	i = 0;
	digit = ft_digit(nb);
	rt = (char *)malloc(sizeof(char) * (digit + 1));
	if (!rt)
		return (0);
	rt[digit] = 0;
	if (nb < 0)
	{
		rt[i++] = '-';
		nb = -nb;
	}
	while (i <= --digit)
	{
		rt[digit] = nb % 10 + '0';
		nb /= 10;
	}
	return (rt);
}
