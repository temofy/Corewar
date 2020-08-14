/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: space <space@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:22:48 by qmebble           #+#    #+#             */
/*   Updated: 2019/08/30 02:01:52 by space            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/get_next_line.h"

static char		*change_content(char *s, int len)
{
	char	*end;
	int		i;
	int		pos;

	pos = 0;
	while (s[pos] != '\n' && s[pos])
		pos++;
	end = (char *)malloc(sizeof(char) * (len - pos + 1));
	i = 0;
	while (++pos < len && s[pos])
	{
		end[i] = s[pos];
		i++;
	}
	end[i] = '\0';
	free(s);
	return (end);
}

static char		*new_line(char *s)
{
	int		i;
	char	*end;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	end = (char *)malloc(sizeof(char) * (i + 1));
	i = -1;
	while (s[++i] != '\n' && s[i])
		end[i] = s[i];
	end[i] = '\0';
	return (end);
}

static t_list	*check_num(t_list **file, int fd)
{
	t_list	*temp;

	temp = *file;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", fd);
	ft_lstadd(file, temp);
	temp = *file;
	return (temp);
}

int				get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static t_list	*file;
	t_list			*current;
	int				a;
	char			*b;

	if (fd < 0 || !line || (a = read(fd, buff, 0)) < 0)
		return (-1);
	current = check_num(&file, fd);
	while ((a = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[a] = '\0';
		b = (char *)current->content;
		current->content = ft_strjoin(current->content, buff);
		free(b);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (a < BUFF_SIZE && !ft_strlen(current->content))
		return (0);
	*line = new_line((char *)current->content);
	current->content = change_content((char *)current->content,
	ft_strlen((char *)current->content));
	return (1);
}
