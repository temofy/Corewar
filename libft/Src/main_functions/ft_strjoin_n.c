/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 02:21:00 by space             #+#    #+#             */
/*   Updated: 2019/09/23 20:26:59 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

char	*check_for_overflow_strjoin(int len, t_dynamic_buffer *buffer,
									char **str)
{
	char	*new;

	if (buffer->amount_chars + len <= buffer->size_for_malloc)
		return (*str);
	while (buffer->size_for_malloc < buffer->amount_chars + len)
	{
		buffer->overflow_counter++;
		buffer->size_for_malloc *= buffer->overflow_counter;
	}
	new = (char *)malloc(sizeof(char) * buffer->size_for_malloc);
	ft_bzero(new, buffer->size_for_malloc);
	new = ft_strcpy(new, *str);
	ft_strdel(str);
	return (new);
}

void	strjoin_n(char **dest, char *src, t_dynamic_buffer *buffer)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(src);
	while (++i < len)
	{
		(*dest)[buffer->amount_chars] = src[i];
		buffer->amount_chars++;
	}
}

char	*ft_strjoin_n(int num, ...)
{
	va_list				open;
	char				*final;
	char				*temp;
	t_dynamic_buffer	buffer;

	va_start(open, num);
	buffer = make_new_dynamic_buffer();
	final = (char *)malloc(sizeof(char) * buffer.size_for_malloc);
	ft_bzero(final, buffer.size_for_malloc);
	while (num > 0)
	{
		temp = va_arg(open, char *);
		final = check_for_overflow_strjoin(ft_strlen(temp), &buffer, &final);
		strjoin_n(&final, temp, &buffer);
		num--;
	}
	va_end(open);
	return (final);
}
