/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:01:45 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:31:50 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Headers/ft_printf.h"

void	ft_itoa_unsigned(unsigned long long int num)
{
	int		i;

	if (num == 0)
	{
		g_buffer->str[0] = '0';
		g_buffer->str[1] = '\0';
		g_buffer->str_len = 1;
		return ;
	}
	i = 0;
	while (num > 0)
	{
		g_buffer->str[i] = num % 10 + '0';
		num /= 10;
		i++;
		if (num == 0)
			break ;
	}
	g_buffer->str_len = i;
	ft_strrev();
}
