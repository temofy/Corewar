/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:11:36 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:53:57 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

void	ft_putendl(char const *s)
{
	int		i;
	char	c;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
	c = '\n';
	write(1, &c, 1);
}
