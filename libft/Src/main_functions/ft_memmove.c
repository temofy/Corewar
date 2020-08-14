/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 23:24:27 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:53:37 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	if (str1 == str2)
		return ((void *)dst);
	else if (str1 > str2)
	{
		i = len - 1;
		while (len--)
		{
			str1[i] = str2[i];
			i--;
		}
	}
	else
	{
		i = -1;
		while (++i < len)
			str1[i] = str2[i];
	}
	return ((void *)str1);
}
