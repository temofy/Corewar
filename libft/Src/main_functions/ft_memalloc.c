/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:52:18 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:53:14 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*a;

	a = (void *)malloc(size);
	if (!a || size == 0)
		return (NULL);
	ft_bzero(a, size);
	return (a);
}
