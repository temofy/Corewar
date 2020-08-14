/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:28:37 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:55:41 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (s[++i])
		if (s[i] == c)
			j = i;
	if (s[i] == c)
		return ((char *)&s[i]);
	if (j == 0 && s[j] != c)
		return (NULL);
	return ((char *)&s[j]);
}
