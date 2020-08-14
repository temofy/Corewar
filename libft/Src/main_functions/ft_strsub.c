/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:00:25 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:55:52 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*a;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
		i++;
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (start > i || !a || len > i)
		return (NULL);
	i = start;
	start = 0;
	while (start < len)
	{
		a[j] = s[i];
		j++;
		i++;
		start++;
	}
	a[j] = '\0';
	return (a);
}
