/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:32:26 by abourbou          #+#    #+#             */
/*   Updated: 2020/03/05 15:46:42 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

typedef	struct	s_list_fd
{
	int					fd;
	char				*reminder;
	struct s_list_fd	*next;
}				t_list_fd;

int				get_next_line(int fd, char **line);
int				ft_lstclear_fd(t_list_fd **lst);

int				ft_lstdelone_fd(t_list_fd **first_elem, int fd);
int				ft_strcut_gnl(char **reminder, char **line);
#endif
