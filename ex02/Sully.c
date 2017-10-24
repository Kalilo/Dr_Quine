/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sully.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:04:39 by khansman          #+#    #+#             */
/*   Updated: 2017/10/24 15:04:42 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char		*g_src[40] = { "/* ***********************************************",
	"*************************** */\n/*                                       ",
	"                                     */\n/*                              ",
	"                          :::      ::::::::   */\n/*   Sully.c           ",
	"                                 :+:      :+:    :+:   */\n/*            ",
	"                                        +:+ +:+         +:+     */\n/*   ",
	"By: khansman <marvin@42.fr>                    +#+  +:+       +#+        ",
	"*/\n/*                                                +#+#+#+#+#+   +#+  ",
	"         */\n/*   Created: 2017/10/24 15:04:39 by khansman          #+#  ",
	"  #+#             */\n/*   Updated: 2017/10/24 15:04:42 by khansman      ",
	"   ###   ########.fr       */\n/*                                        ",
	"                                    */\n/* ******************************",
	"******************************************** */\n\n#include <fcntl.h>\n#i",
	"nclude <stdio.h>\n#include <stdlib.h>\n\nchar\t\t*g_src[40] = { ",
	" };\nint\t\t\tg_x = ",
	";\n\nchar\tis_special(char c)\n{\n\treturn (c == '\\\"' || c == '\\t' || ",
	"c == '\\n' || c == '\\\\');\n}\n\nchar\t*escape_special(char c)\n{\n\tif ",
	"(c == '\\\"')\n\t\treturn (\"\\\\\\\"\");\n\tif (c == '\\t')\n\t\treturn ",
	"(\"\\\\t\");\n\tif (c == '\\n')\n\t\treturn (\"\\\\n\");\n\treturn (\"\\",
	"\\\\\\\");\n}\n\nvoid\tprint_prog(char *filename)\n{\n\tFILE\t*fd;\n\tint",
	"\t\tk;\n\tint\t\tl;\n\tint\t\tm;\n\n\tl = -1;\n\tm = -1;\n\tfd = fopen(fi",
	"lename, \"w\");\n\twhile (++l < 14)\n\t\tfprintf(fd, \"%s\", g_src[l]);\n",
	"\twhile (++m < 33)\n\t{\n\t\tfprintf(fd, \"%c\", '\"');\n\t\tk = -1;\n\t",
	"\twhile (g_src[m][++k])\n\t\t{\n\t\t\tif (!is_special(g_src[m][k]))\n\t\t",
	"\t\tfprintf(fd, \"%c\", g_src[m][k]);\n\t\t\telse\n\t\t\t\tfprintf(fd, \"",
	"%s\", escape_special(g_src[m][k]));\n\t\t}\n\t\tfprintf(fd, (m + 1 == 33)",
	" ? \"\\\"\" : \"\\\",\\n\\t\");\n\t}\n\tfprintf(fd, \"%s%d\", g_src[l], g",
	"_x - 5);\n\twhile (++l < 33)\n\t\tfprintf(fd, \"%s\", g_src[l]);\n}\n\nin",
	"t\t\tmain(void)\n{\n\tchar\tfilename[50];\n\tchar\tbuff[100];\n\n\tif (g_x < 1)\n\t\treturn (0);\n\tsprint",
	"f(filename, \"Sully_%d.c\", g_x);\n\tprint_prog(filename);\n\tsprintf(fil",
	"ename, \"Sully_%d\", g_x);\n\tsprintf(buff, \"clang -Wall -Wextra -Werror",
	" %s.c -o %s\", filename, filename);\n\tsystem(buff);\n\tsprintf(buff, \".",
	"/%s\", filename);\n\treturn (0);\n}\n" };
int			g_x = 5;

char	is_special(char c)
{
	return (c == '\"' || c == '\t' || c == '\n' || c == '\\');
}

char	*escape_special(char c)
{
	if (c == '\"')
		return ("\\\"");
	if (c == '\t')
		return ("\\t");
	if (c == '\n')
		return ("\\n");
	return ("\\\\");
}

void	print_prog(char *filename)
{
	FILE	*fd;
	int		k;
	int		l;
	int		m;

	l = -1;
	m = -1;
	fd = fopen(filename, "w");
	while (++l < 14)
		fprintf(fd, "%s", g_src[l]);
	while (++m < 33)
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
		fprintf(fd, (m + 1 == 33) ? "\"" : "\",\n\t");
	}
	fprintf(fd, "%s%d", g_src[l], g_x - 1);
	while (++l < 33)
		fprintf(fd, "%s", g_src[l]);
}

int		main(void)
{
	char	filename[50];
	char	buff[100];

	if (g_x < 1)
		return (0);
	sprintf(filename, "Sully_%d.c", g_x);
	print_prog(filename);
	sprintf(filename, "Sully_%d", g_x);
	sprintf(buff, "clang -Wall -Wextra -Werror %s.c -o %s", filename, filename);
	system(buff);
	sprintf(buff, "./%s", filename);
	return (0);
}
