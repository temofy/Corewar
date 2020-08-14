/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:55:46 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:55:29 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t len)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	if (len == 0)
		return (1);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < len - 1)
		i++;
	if (s1[i] == s2[i])
		return (1);
	return (0);
}
