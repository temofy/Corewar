/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_precision_pointer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:01:34 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:31:28 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Headers/ft_printf.h"

void	ft_put_precision_pointer(t_pf *data)
{
	int		i;
	int		j;
	int		len;

	if (!data->precision)
		return ;
	if (data->precision == -1 && g_buffer->str[0] == '0')
	{
		g_buffer->str[0] = '\0';
		g_buffer->str_len = 0;
		return ;
	}
	len = g_buffer->str_len - data->precision;
	if (len >= 0)
		return ;
	check_and_add(-len);
	i = -1;
	while (++i < (-len))
		g_buffer->final[i] = '0';
	j = -1;
	while (g_buffer->str[++j] != '\0' && g_buffer->str[j])
		g_buffer->final[i++] = g_buffer->str[j];
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, i);
}
