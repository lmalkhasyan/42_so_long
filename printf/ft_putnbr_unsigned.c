/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:39:47 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/01 21:39:05 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putnbr_unsigned(unsigned long long n, unsigned int base, int type)
{
	int	count;

	count = 0;
	if (n > base - 1)
		count += ft_putnbr_unsigned(n / base, base, type);
	n = n % base;
	if (n < 10)
		count += ft_putchar(n + '0');
	else if (n > 9 && type == 0)
		count += ft_putchar(n + 87);
	else if (n > 9 && type == 1)
		count += ft_putchar(n + 55);
	return (count);
}
