/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:32:53 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:55:13 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*a;
	int		len;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	len = 0;
	while (s[len])
	{
		a[len] = f(s[len]);
		len++;
	}
	a[len] = '\0';
	return (a);
}
