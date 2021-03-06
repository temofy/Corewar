/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:14:32 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:54:30 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

void	ft_strclr(char *s)
{
	int	i;
	int	len;

	if (!s)
		return ;
	i = -1;
	len = 0;
	while (s[++i])
		s[i] = '\0';
}
