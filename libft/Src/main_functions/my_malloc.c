/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:19:28 by qmebble           #+#    #+#             */
/*   Updated: 2019/10/14 13:19:57 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*my_malloc(size_t size, const char *file, int line, const char *func)
{
	void	*p;

	p = malloc(size);
	printf("Allocated = %s, %i, %s, %p[%li]\n", file, line, func, p, size);
	return (p);
}
