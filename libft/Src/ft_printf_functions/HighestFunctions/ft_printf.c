/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:01:11 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:30:16 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Headers/ft_printf.h"

int			ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	t_pf	*data;
	int		return_value;

	if (!format)
		return (-1);
	i = 0;
	return_value = 0;
	data = (t_pf *)malloc(sizeof(t_pf));
	data->fd = 1;
	va_start(args, format);
	while (format[i] && format[i] != '\0')
	{
		i = ft_parsing(data, args, format, i);
		return_value += data->return_value;
		free_buffer();
	}
	ft_set_to_null(data);
	free(data);
	va_end(args);
	return (return_value);
}
