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
#include <string.h>

extern const char *__progname;

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
	"nclude <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\nextern cons",
	"t char *__progname;\n\nchar\t\t*g_src[40] = { ",
	" };\nint\t\t\tg_x = ",
	";\n\nchar\tis_special(char c)\n{\n\treturn (c == '\\\"' || c == '\\t' || ",
	"c == '\\n' || c == '\\\\');\n}\n\nchar\t*escape_special(char c)\n{\n\tif ",
	"(c == '\\\"')\n\t\treturn (\"\\\\\\\"\");\n\tif (c == '\\t')\n\t\treturn ",
	"(\"\\\\t\");\n\tif (c == '\\n')\n\t\treturn (\"\\\\n\");\n\treturn (\"\\",
	"\\\\\\\");\n}\n\nvoid\tprint_prog(char *filename)\n{\n\tFILE\t*fd;\n\tint",
	"\t\tk;\n\tint\t\tl;\n\tint\t\tm;\n\n\tl = -1;\n\tm = -1;\n\tfd = fopen(fi",
	"lename, \"w\");\n\twhile (++l < 15)\n\t\tfprintf(fd, \"%s\", g_src[l]);\n",
	"\twhile (++m < 36)\n\t{\n\t\tfprintf(fd, \"%c\", '\"');\n\t\tk = -1;\n\t",
	"\twhile (g_src[m][++k])\n\t\t{\n\t\t\tif (!is_special(g_src[m][k]))\n\t\t",
	"\t\tfprintf(fd, \"%c\", g_src[m][k]);\n\t\t\telse\n\t\t\t\tfprintf(fd, \"",
	"%s\", escape_special(g_src[m][k]));\n\t\t}\n\t\tfprintf(fd, (m + 1 == 36)",
	" ? \"\\\"\" : \"\\\",\\n\\t\");\n\t}\n\tfprintf(fd, \"%s%d\", g_src[l], g",
	"_x);\n\twhile (++l < 36)\n\t\tfprintf(fd, \"%s\", g_src[l]);\n\tfclose(fd",
	");\n}\n\nint\t\tmain(void)\n{\n\tchar\tfilename[50];\n\tchar\tbuff[100];",
	"\n\n\tif (strchr(__progname, '_'))\n\t\tg_x--;\n\tif (g_x < 0)\n\t\tretur",
	"n (0);\n\tsprintf(filename, \"Sully_%d.c\", g_x);\n\tprint_prog(filename)",
	";\n\tsprintf(filename, \"Sully_%d\", g_x);\n\tsprintf(buff, \"clang -Wall",
	" -Wextra -Werror %s.c -o %s\\n\", filename,\n\t\tfilename);\n\tsystem(buf",
	"f);\n\tif (g_x < 1)\n\t\treturn (0);\n\tsprintf(buff, \"./%s\", filename)",
	";\n\tsystem(buff);\n\treturn (0);\n}\n" };
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
	while (++l < 15)
		fprintf(fd, "%s", g_src[l]);
	while (++m < 36)
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
		fprintf(fd, (m + 1 == 36) ? "\"" : "\",\n\t");
	}
	fprintf(fd, "%s%d", g_src[l], g_x);
	while (++l < 36)
		fprintf(fd, "%s", g_src[l]);
	fclose(fd);
}

int		main(void)
{
	char	filename[50];
	char	buff[100];

	if (strchr(__progname, '_'))
		g_x--;
	if (g_x < 0)
		return (0);
	sprintf(filename, "Sully_%d.c", g_x);
	print_prog(filename);
	sprintf(filename, "Sully_%d", g_x);
	sprintf(buff, "clang -Wall -Wextra -Werror %s.c -o %s\n", filename,
		filename);
	system(buff);
	if (g_x < 1)
		return (0);
	sprintf(buff, "./%s", filename);
	system(buff);
	return (0);
}
