/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:50:07 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/30 01:30:50 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Headers/ft_printf.h"

void		ft_caps(t_pf *list)
{
	int		i;

	if (list->type != 'X')
		return ;
	i = 0;
	while (g_buffer->str[i] && g_buffer->str[i] != '\0')
	{
		if (g_buffer->str[i] >= 'a' && g_buffer->str[i] <= 'z')
			g_buffer->str[i] -= 32;
		i++;
	}
}
