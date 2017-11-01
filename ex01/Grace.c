/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:16:59 by khansman          #+#    #+#             */
/*   Updated: 2017/10/24 14:17:00 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

# define FT(x) int main() { x; return (0); }
# define FT_ESCAPE(x) char *escape_special(char c) { x }
# define IS_SPECIAL(x) (x == '\"' || x == '\t' || x == '\n' || x == '\\')

char		*g_src[30] = { "/* ***************************************************",
	"*********************** */\n/*                                             ",
	"                               */\n/*                                      ",
	"                  :::      ::::::::   */\n/*   Grace.c                     ",
	"                       :+:      :+:    :+:   */\n/*                        ",
	"                            +:+ +:+         +:+     */\n/*   By: khansman <",
	"marvin@42.fr>                    +#+  +:+       +#+        */\n/*          ",
	"                                      +#+#+#+#+#+   +#+           */\n/*   ",
	"Created: 2017/10/24 14:16:59 by khansman          #+#    #+#             */",
	"\n/*   Updated: 2017/10/24 14:17:00 by khansman         ###   ########.fr  ",
	"     */\n/*                                                                ",
	"            */\n/* ********************************************************",
	"****************** */\n\n#include <fcntl.h>\n#include <stdio.h>\n#include <",
	"stdlib.h>\n\n# define FT(x) int main() { x; return (0); }\n# define FT_ESC",
	"APE(x) char *escape_special(char c) { x }\n# define IS_SPECIAL(x) (x == '\\",
	"\"' || x == '\\t' || x == '\\n' || x == '\\\\')\n\nchar\t\t*g_src[30] = { ",
	" };\n\n/*\n\tThis program will print its own source when run.\n*/\n\nFT_ESC",
	"APE(\n\tif (c == '\\\"')\n\t\treturn (\"\\\\\\\"\");\n\tif (c == '\\t')\n\t",
	"\treturn (\"\\\\t\");\n\tif (c == '\\n')\n\t\treturn (\"\\\\n\");\n\treturn",
	" (\"\\\\\\\\\");\n)\n\nFT(\n\tFILE\t*fd;\n\tint\t\tk;\n\tint\t\tl;\n\tint\t",
	"\tm;\n\n\tl = -1;\n\tm = -1;\n\tif ((fd = fopen(\"Grace_kid.c\", \"w\")) < ",
	"0)\n\t{\n\t\tprintf(\"Error opening file.\");\n\t\texit(1);\n\t}\n\twhile (",
	"++l < 17)\n\t\tfprintf(fd, \"%s\", g_src[l]);\n\twhile (++m < 29)\n\t{\n\t",
	"\tfprintf(fd, \"%c\", '\"');\n\t\tk = -1;\n\t\twhile (g_src[m][++k])\n\t\t{",
	"\n\t\t\tif (!IS_SPECIAL(g_src[m][k]))\n\t\t\t\tfprintf(fd, \"%c\", g_src[m]",
	"[k]);\n\t\t\telse\n\t\t\t\tfprintf(fd, \"%s\", escape_special(g_src[m][k]))",
	";\n\t\t}\n\t\tfprintf(fd, (m + 1 == 29) ? \"\\\"\" : \"\\\",\\n\\t\");\n\t}",
	"\n\twhile (l < 29)\n\t\tfprintf(fd, \"%s\", g_src[l++]);\n\tfclose(fd);\n)",
	"\n" };

/*
	This program will print its own source when run.
*/

FT_ESCAPE(
	if (c == '\"')
		return ("\\\"");
	if (c == '\t')
		return ("\\t");
	if (c == '\n')
		return ("\\n");
	return ("\\\\");
)

FT(
	FILE	*fd;
	int		k;
	int		l;
	int		m;

	l = -1;
	m = -1;
	if ((fd = fopen("Grace_kid.c", "w")) < 0)
	{
		printf("Error opening file.");
		exit(1);
	}
	while (++l < 17)
		fprintf(fd, "%s", g_src[l]);
	while (++m < 29)
	{
		fprintf(fd, "%c", '"');
		k = -1;
		while (g_src[m][++k])
		{
			if (!IS_SPECIAL(g_src[m][k]))
				fprintf(fd, "%c", g_src[m][k]);
			else
				fprintf(fd, "%s", escape_special(g_src[m][k]));
		}
		fprintf(fd, (m + 1 == 29) ? "\"" : "\",\n\t");
	}
	while (l < 29)
		fprintf(fd, "%s", g_src[l++]);
	fclose(fd);
)
