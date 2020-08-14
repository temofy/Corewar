/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:21:21 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/31 18:18:48 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

void	*ft_realloc(void *s, int size)
{
	int				i;
	int				len;
	unsigned char	*c;
	unsigned char	*x;
	int				j;

	x = (unsigned char *)s;
	i = -1;
	j = -1;
	len = ft_strlen((char *)s) + 1 + size;
	if (!x || !(c = (unsigned char *)malloc(sizeof(unsigned char) * len)))
		return (NULL);
	while (x[++i])
		c[i] = x[i];
	while (++j <= size)
	{
		c[i] = '\0';
		i++;
	}
	return ((void *)c);
}
