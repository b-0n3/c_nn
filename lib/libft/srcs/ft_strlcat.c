/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 01:52:30 by aait-ham          #+#    #+#             */
/*   Updated: 2019/10/21 09:42:47 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned	int		length_d;
	unsigned	int		length_s;
	int					i;

	i = -1;
	length_d = ft_strlen(dest);
	length_s = ft_strlen(src);
	if (size == 0)
		return (length_s);
	else if (length_d >= size)
		length_s = length_s + size;
	else
		length_s = length_s + length_d;
	while (src[++i] && length_d < size - 1)
		dest[length_d++] = src[i];
	dest[length_d] = '\0';
	return (length_s);
}
