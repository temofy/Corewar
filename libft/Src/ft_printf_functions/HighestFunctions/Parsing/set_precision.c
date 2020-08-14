/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:54:37 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/30 01:29:48 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../Headers/ft_printf.h"

int	set_precision(t_pf *data, const char *format, int i)
{
	i += 1;
	if (char_bin_search(NUMBERS, format[i]) == -1)
	{
		data->precision = -1;
		return (i);
	}
	while (char_bin_search(NUMBERS, format[i]) != -1)
	{
		data->precision = data->precision * 10 + format[i] - '0';
		i++;
	}
	if (data->precision * 10 / 10 != data->precision)
		data->precision = 6;
	if (data->precision == 0)
		data->precision = -1;
	return (i);
}
