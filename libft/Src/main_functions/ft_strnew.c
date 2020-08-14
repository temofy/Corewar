/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:08:32 by qmebble           #+#    #+#             */
/*   Updated: 2019/09/23 00:03:03 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

char	*ft_strnew(size_t size)
{
	char	*a;

	if (!(a = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(a, size);
	return (a);
}
