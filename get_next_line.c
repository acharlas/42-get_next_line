/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:43:32 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/20 20:02:03 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_init_data(t_data **data, int fd)
{
	if (BUFFER_SIZE < 1)
		return (-1);
	if (!(*data = malloc(sizeof(t_data))))
		return (0);
	data[0]->i = 0;
	if ((data[0]->res = read(fd, data[0]->buff, BUFFER_SIZE)) < 1)
		return (data[0]->res);
	return (1);
}

int		ft_realloc(int index, t_data *data, char **line)
{
	int		len;
	char	*s;
	int		i;

	i = 0;
	len = ft_strlen(*line);
	if (!(s = malloc(sizeof(char) * (len + 2))))
		return (0);
	while (i < len)
	{
		s[i] = line[0][i];
		i++;
	}
	s[i] = data->buff[index];
	s[i + 1] = '\0';
	free(*line);
	*line = s;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static t_data *data = 0;

	if ((!data || data->res == -1) && ft_init_data(&data, fd) == -1)
		return (ft_reset_props(&data, 1));
	if (!ft_init_line(line))
		return (0);
	while (data->i < data->res && data->res > 0)
	{
		if (data->buff[data->i] == '\n')
		{
			data->i++;
			if (data->i == data->res)
				ft_re_loop(data, fd);
			return (1);
		}
		if (!ft_realloc(data->i++, data, line))
			return (-1);
		if (data->i == data->res)
			ft_re_loop(data, fd);
	}
	return (ft_reset_props(&data, 0));
}
