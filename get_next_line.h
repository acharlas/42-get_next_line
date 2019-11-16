/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:02:01 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/16 17:02:04 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H

# define _GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_data
{
	char		buff[BUFFER_SIZE];
	int			i;
	int			res;
}				t_data;

int				get_next_line(int fd, char **line);
int				ft_strlen(char *s);
int				ft_alloc(char c, char **line);
int				ft_re_loop(t_data *data, int fd);
int				ft_init_line(char **line);
int				ft_reset_props(t_data **data, int i);
#endif
