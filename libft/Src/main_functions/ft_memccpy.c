/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 22:57:44 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:53:17 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	int					i;
	unsigned char		charact;
	unsigned char		*str1;
	unsigned const char	*str2;

	i = 0;
	charact = (unsigned char)c;
	str1 = (unsigned char *)s1;
	str2 = (unsigned const char *)s2;
	while (n > 0)
	{
		str1[i] = str2[i];
		if (str2[i] == charact)
		{
			i++;
			return ((void *)&str1[i]);
		}
		i++;
		n--;
	}
	return (NULL);
}
