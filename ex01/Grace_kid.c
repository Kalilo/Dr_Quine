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

# define FT(x) int main() { x; return (0); }
# define FT_ESCAPE(x) char *escape_special(char c) { x }
# define IS_SPECIAL(x) (x == '\"' || x == '\t' || x == '\n' || x == '\\')

char		*g_src[30] = { "/* ***********************************************",
	"*************************** */\n/*                                       ",
	"                                     */\n/*                              ",
	"                          :::      ::::::::   */\n/*   Grace.c           ",
	"                                 :+:      :+:    :+:   */\n/*            ",
	"                                        +:+ +:+         +:+     */\n/*   ",
	"By: khansman <marvin@42.fr>                    +#+  +:+       +#+        ",
	"*/\n/*                                                +#+#+#+#+#+   +#+  ",
	"         */\n/*   Created: 2017/10/24 14:16:59 by khansman          #+#  ",
	"  #+#             */\n/*   Updated: 2017/10/24 14:17:00 by khansman      ",
	"   ###   ########.fr       */\n/*                                        ",
	"                                    */\n/* ******************************",
	"******************************************** */\n\n#include <fcntl.h>\n#i",
	"nclude <stdio.h>\n\n# define FT(x) int main() { x; return (0); }\n# defin",
	"e FT_ESCAPE(x) char *escape_special(char c) { x }\n# define IS_SPECIAL(x)",
	" (x == '\\\"' || x == '\\t' || x == '\\n' || x == '\\\\')\n\nchar\t\t*g_s",
	"rc[30] = { ",
	" };\n\n/*\n\tThis program will print its own source when run.\n*/\n\nFT_E",
	"SCAPE(\n\tif (c == '\\\"')\n\t\treturn (\"\\\\\\\"\");\n\tif (c == '\\t')",
	"\n\t\treturn (\"\\\\t\");\n\tif (c == '\\n')\n\t\treturn (\"\\\\n\");\n\t",
	"return (\"\\\\\\\\\");\n)\n\nFT(\n\tFILE\t*fd;\n\tint\t\tk;\n\tint\t\tl;",
	"\n\tint\t\tm;\n\n\tl = -1;\n\tm = -1;\n\tfd = fopen(\"Grace_kid.c\", \"w",
	"\");\n\twhile (++l < 17)\n\t\tfprintf(fd, \"%s\", g_src[l]);\n\twhile (++",
	"m < 29)\n\t{\n\t\tfprintf(fd, \"%c\", '\"');\n\t\tk = -1;\n\t\twhile (g_s",
	"rc[m][++k])\n\t\t{\n\t\t\tif (!IS_SPECIAL(g_src[m][k]))\n\t\t\t\tfprintf(",
	"fd, \"%c\", g_src[m][k]);\n\t\t\telse\n\t\t\t\tfprintf(fd, \"%s\", escape",
	"_special(g_src[m][k]));\n\t\t}\n\t\tfprintf(fd, (m + 1 == 29) ? \"\\\"\" ",
	": \"\\\",\\n\\t\");\n\t}\n\twhile (l < 29)\n\t\tfprintf(fd, \"%s\", g_src",
	"[l++]);\n)\n" };

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
	fd = fopen("Grace_kid.c", "w");
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
)
