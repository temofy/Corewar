/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:20:32 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:55:37 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	t;

	i = -1;
	j = 0;
	if (s1 == s2)
		return ((char *)s1);
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[++i] && i < len)
	{
		t = i;
		while (s2[j] == s1[i] && s1[i] && s2[j] && i < len)
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)(&s1[t]));
		j = 0;
		i = t;
	}
	return (NULL);
}
