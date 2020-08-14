/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:24:50 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/31 07:21:13 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 100

/*
**	Reads a line from an open file descriptor
**
**	@param			fd			An open file descriptor
**	@param			line		Pointer to char array
**
**	@return			1 If reading was succsessful
**					0 If reading reached an end of file
**					-1 If reading failured
*/
int	get_next_line(const int fd, char **line);

#endif
