/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 00:23:18 by aait-ham          #+#    #+#             */
/*   Updated: 2019/10/13 00:48:24 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int newvar;

	newvar = n;
	if (n < 0)
	{
		newvar = -n;
		ft_putchar_fd('-', fd);
	}
	if (newvar <= 9)
	{
		ft_putchar_fd(newvar + 48, fd);
	}
	if (newvar > 9)
	{
		ft_putnbr_fd(newvar / 10, fd);
		ft_putchar_fd(newvar % 10 + 48, fd);
	}
}
