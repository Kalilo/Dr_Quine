/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t01.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 09:23:10 by khansman          #+#    #+#             */
/*   Updated: 2017/10/24 09:23:11 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

char		*g_src[10] = { "here" };

int	main(void)
{
	FILE	*fd;
	int		k;
	int		l;
	int		m;

	k = -1;
	l = -1;
	m = -1;
	fd = fopen("Colleen", "w");
	while (++l < 1)
		fprintf(fd, g_src[l], g_src[l]);
	while (++m < 2)
	{
		while (g_src[m][++k])
			if (!iscntrl(g_src[m][k]))
				fprintf(fd, "%c", g_src[m][k]);
			else
				fprintf(fd, "%s", (g_src[m][k] == '\n') ? "\\n" : "\\t");
		fprintf(fd, ",\n\t");
	}
	while (++l < 2)
		fprintf(fd, g_src[l], g_src[l]);
	return (0);
}
