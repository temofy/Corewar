/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:11:13 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:54:43 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = -1;
	if (!(c = ft_strnew(ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[++j] != '\0')
		c[j] = s1[j];
	c[j] = '\0';
	return (c);
}
