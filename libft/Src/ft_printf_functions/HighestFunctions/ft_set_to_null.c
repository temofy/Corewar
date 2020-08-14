/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_to_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:01:18 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:30:26 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Headers/ft_printf.h"

void	ft_set_to_null(t_pf *data)
{
	data->base = 0;
	data->flags = 0;
	data->indents = 0;
	data->indents_symb = 0;
	data->modificators = 0;
	data->precision = 0;
	data->return_value = 0;
	data->str_after = NULL;
	data->str_before = NULL;
	data->str_middle = NULL;
	data->type = 0;
	data->width = 0;
	data->indents_symb = 0;
	data->colors = 0;
}
