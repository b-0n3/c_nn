/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 03:08:33 by aait-ham          #+#    #+#             */
/*   Updated: 2019/10/15 14:51:07 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char			i;
	const unsigned char		*s;
	unsigned char			*d;

	i = 0;
	d = dst;
	s = src;
	if (d == NULL && s == NULL && len == 0 && c == 0)
		return (dst);
	while (i < len)
	{
		if (s[i] == (unsigned char)c)
		{
			d[i] = s[i];
			return (dst + i + 1);
		}
		d[i] = s[i];
		i++;
	}
	if (i == len)
		return (NULL);
	return (dst);
}
