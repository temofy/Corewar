/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:42:23 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:55:07 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		len;

	i = ft_strlen(dst);
	len = ft_strlen(src);
	j = i;
	if (size < j)
		return (size + len);
	while (src[i - j] != '\0' && i < (size - 1))
	{
		dst[i] = src[i - j];
		i++;
	}
	if (j < size)
		dst[i] = '\0';
	return (j + len);
}
