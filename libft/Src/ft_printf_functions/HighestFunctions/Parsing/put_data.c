/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:54:20 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/30 01:29:34 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../Headers/ft_printf.h"

t_pf	*put_data(t_pf *data, va_list args)
{
	if (!data->type)
		return (data);
	if (data->type == 'c' || data->type == '%')
		char_process(data, args);
	else if (data->type == 's')
		string_process(data, args);
	else if (data->type == 'p')
		ft_pointer(data, args);
	else if (data->type == 'x' || data->type == 'X' || data->type == 'o')
		ox_process(data, args);
	else if (data->type == 'd' || data->type == 'i')
		ft_di(data, args);
	else if (data->type == 'u')
		ft_unsigned(data, args);
	else if (data->type == 'f')
		ft_floats(data, args);
	return (data);
}
