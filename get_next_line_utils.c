/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:43:24 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/16 17:43:27 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_re_loop(t_data *data, int fd)
{
	data->i = 0;
	if (!(data->res = read(fd, data->buff, BUFFER_SIZE)))
		return (0);
	return (1);
}

int		ft_init_line(char **line)
{
	if (!(*line = malloc(sizeof(char))))
		return (0);
	**line = '\0';
	return (1);
}

int		ft_reset_props(t_data **data, int i)
{
	int res;

	res = data[0]->res;
	free(*data);
	*data = 0;
	if (i == 1)
		return (res);
	return (0);
}
