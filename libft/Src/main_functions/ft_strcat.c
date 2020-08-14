/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:38:09 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:54:22 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (s1[i])
		i++;
	while (s2[++j])
		s1[i + j] = s2[j];
	s1[i + j] = '\0';
	return (s1);
}
