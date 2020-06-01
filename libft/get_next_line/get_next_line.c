/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:32:17 by abourbou          #+#    #+#             */
/*   Updated: 2020/03/04 14:53:29 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	**ft_search(int fd, t_list_fd *first_elem)
{
	t_list_fd	*new_elem;
	t_list_fd	*current_elem;

	current_elem = first_elem;
	while (current_elem->next)
	{
		if (fd == current_elem->fd)
			return (&(current_elem->reminder));
		current_elem = current_elem->next;
	}
	if (fd == current_elem->fd)
		return (&(current_elem->reminder));
	if (!(new_elem = ft_calloc(sizeof(t_list_fd ), 1)))
		return (0);
	new_elem->fd = fd;
	if (!(new_elem->reminder = ft_calloc(sizeof(char), 1)))
		return (0);
	current_elem->next = new_elem;
	return (&(new_elem->reminder));
}

int		ft_read(int fd, char **reminder)
{
	char	*buffer;
	int		val_read;
	char	*save;

	if (!(buffer = wrmalloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (0);
	if ((val_read = read(fd, buffer, BUFFER_SIZE)) == -1)
		return (0);
	buffer[val_read] = 0;
	save = *reminder;
	if (!(*reminder = ft_strjoin(save, buffer)))
	{
		*reminder = save;
		return (0);
	}
	wrfree(save);
	wrfree(buffer);
	return (1);
}

int		gnl2(t_list_fd **first_elem, char **line, char **reminder, int fd)
{
	int i;

	i = 0;
	while (1)
	{
		while (reminder[0][i] && reminder[0][i] != '\n')
			i++;
		if (reminder[0][i] == '\n')
		{
			return ((!(ft_strcut_gnl(reminder, line))) ?
					ft_lstclear_fd(first_elem) : 1);
		}
		if (!(ft_read(fd, reminder)))
			return (ft_lstclear_fd(first_elem));
		if (!reminder[0][i])
		{
			if (!(ft_strcut_gnl(reminder, line)))
				return (ft_lstclear_fd(first_elem));
			ft_lstdelone_fd(first_elem, fd);
			return (0);
		}
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	char				test;
	char				**reminder;
	static t_list_fd	*first_elem;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || (read(fd, &test, 0) == -1))
		return (-1);
	if (!first_elem)
	{
		if (!(first_elem = ft_calloc(sizeof(t_list_fd ), 1)))
			return (-1);
		first_elem->fd = fd;
		if (!(first_elem->reminder = ft_calloc(sizeof(char), 1)))
		{
			first_elem = 0;
			return (-1);
		}
	}
	if (!(reminder = ft_search(fd, first_elem)))
		return (ft_lstclear_fd(&first_elem));
	return (gnl2(&first_elem, line, reminder, fd));
}
