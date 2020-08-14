/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:31:34 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 01:53:47 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
