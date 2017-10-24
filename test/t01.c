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

char		*g_src[30] = { "/* ***********************************************",
	"*************************** */\n/*                                       ",
	"                                     */\n/*                              ",
	"                          :::      ::::::::   */\n/*   t01.c             ",
	"                                 :+:      :+:    :+:   */\n/*            ",
	"                                        +:+ +:+         +:+     */\n/*   ",
	"By: khansman <marvin@42.fr>                    +#+  +:+       +#+        ",
	"*/\n/*                                                +#+#+#+#+#+   +#+  ",
	"         */\n/*   Created: 2017/10/24 09:23:10 by khansman          #+#  ",
	"  #+#             */\n/*   Updated: 2017/10/24 09:23:11 by khansman      ",
	"   ###   ########.fr       */\n/*                                        ",
	"                                    */\n/* ******************************",
	"******************************************** */\n\n#include <fcntl.h>\n#i",
	"nclude <string.h>\n#include <stdio.h>\n#include <ctype.h>\n\nchar\t\t*g",
	"_src[30] = { \"",
	"\" };\n\nint\tmain(void)\n{\n\tFILE\t*fd;\n\tint\t\tk;\n\tint\t\tl;",
	"\n\tint\t\tm;\n\n\tk = -1;\n\tl = -1;\n\tm = -1;\n\tfd = fopen(\"Colle",
	"en\", \"w\");\n\twhile (++l < 15)\n\t\tfprintf(fd, g_src[l], g_src[l]",
	");\n\twhile (++m < 2)\n\t{\n\t\twhile (g_src[m][++k])\n\t\t\tif (!i",
	"scntrl(g_src[m][k]))\n\t\t\t\tfprintf(fd, \"%c\", g_src[m][k]);\n\t",
	"\t\telse\n\t\t\t\tfprintf(fd, \"%s\", (g_src[m][k] == '\n') ? \"",
	"\\n\" : \"\\t\");\n\t\tfprintf(fd, \",\n\t\");\n\t}\n\twhile (++l < 2",
	"3)\n\t\tfprintf(fd, g_src[l], g_src[l]);\n\treturn (0);\n}\n" };

char	is_special(char c)
{
	return (c == '\"' || c == '\t' || c == '\n');
}

char	*escape_special(char c)
{
	if (c == '\"')
		return ("\\");
	if (c == '\t')
		return ("\\t");
	if (c == '\n')
		return ("\\n");
	return ("");
}

int		main(void)
{
	FILE	*fd;
	int		k;
	int		l;
	int		m;

	l = -1;
	m = -1;
	fd = fopen("Colleen", "w");
	while (++l < 15)
		fprintf(fd, "%s", g_src[l]);
	while (++m < 23)
	{
		fprintf(fd, "%c", '"');
		k = -1;
		while (g_src[m][++k])
		{
			if (!is_special(g_src[m][k]))
				fprintf(fd, "%c", g_src[m][k]);
			else
				fprintf(fd, "%s", escape_special(g_src[m][k]));
		}
		fprintf(fd, (m + 1 == 23) ? "\"" : "\",\n\t");
	}
	while (++l < 23)
		fprintf(fd, "%s", g_src[l]);
	return (0);
}
