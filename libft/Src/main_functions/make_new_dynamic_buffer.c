/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_new_dynamic_buffer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 06:51:00 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/31 15:44:27 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

t_dynamic_buffer	make_new_dynamic_buffer(void)
{
	t_dynamic_buffer	buffer;

	buffer.amount_chars = 0;
	buffer.size_for_malloc = 50;
	buffer.overflow_counter = 1;
	return (buffer);
}
