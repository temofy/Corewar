/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:40:33 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/30 01:28:45 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Headers/ft_printf.h"

void		number_to_arr(unsigned long mant, char *arr)
{
	int		i;

	i = 0;
	while (mant > 0)
	{
		arr[i++] = mant % 10;
		mant /= 10;
	}
}
