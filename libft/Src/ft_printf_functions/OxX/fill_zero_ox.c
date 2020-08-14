/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_zero_ox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:49:01 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/30 01:30:45 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Headers/ft_printf.h"

void		ft_fill_zero(t_pf *data)
{
	int		i;

	i = 0;
	while (data->precision >= 0)
	{
		g_buffer->final[i++] = '0';
		data->precision--;
	}
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
}
