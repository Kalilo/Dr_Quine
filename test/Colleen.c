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
	"nclude <string.h>\n#include <stdio.h>\n#include <ctype.h>\n\nchar\t\t*g_s",
	"rc[30] = { ",
	" };\n\nchar\tis_special(char c)\n{\n\treturn (c == '\\\"' || c == '\\t' |",
	"| c == '\\n' || c == '\"');\n}\n\nchar\t*escape_special(char c)\n{\n\tif ",
	"(c == '\\\"')\n\t\treturn (\"\\\\\");\n\tif (c == '\\t')\n\t\treturn (\"",
	"\\\\t\");\n\tif (c == '\\n')\n\t\treturn (\"\\\\n\");\n\treturn (\"\\\\\\",
	"\"\");\n}\n\nint\t\tmain(void)\n{\n\tFILE\t*fd;\n\tint\t\tk;\n\tint\t\tl;",
	"\n\tint\t\tm;\n\n\tl = -1;\n\tm = -1;\n\tfd = fopen(\"Colleen.c\", \"w\")",
	";\n\twhile (++l < 15)\n\t\tfprintf(fd, \"%s\", g_src[l]);\n\twhile (++m <",
	" 28)\n\t{\n\t\tfprintf(fd, \"%c\", '\"');\n\t\tk = -1;\n\t\twhile (g_src[",
	"m][++k])\n\t\t{\n\t\t\tif (!is_special(g_src[m][k]))\n\t\t\t\tfprintf(fd,",
	" \"%c\", g_src[m][k]);\n\t\t\telse\n\t\t\t\tfprintf(fd, \"%s\", escape_sp",
	"ecial(g_src[m][k]));\n\t\t}\n\t\tfprintf(fd, (m + 1 == 28) ? \"\\\"\" : ",
	"\"\\\",\\n\\t\");\n\t}\n\twhile (l < 28)\n\t\tfprintf(fd, \"%s\", g_src[l",
	"++]);\n\treturn (0);\n}\n" };

char	is_special(char c)
{
	return (c == '\"' || c == '\t' || c == '\n' || c == '"');
}

char	*escape_special(char c)
{
	if (c == '\"')
		return ("\\");
	if (c == '\t')
		return ("\\t");
	if (c == '\n')
		return ("\\n");
	return ("\\\"");
}

int		main(void)
{
	FILE	*fd;
	int		k;
	int		l;
	int		m;

	l = -1;
	m = -1;
	fd = fopen("Colleen.c", "w");
	while (++l < 15)
		fprintf(fd, "%s", g_src[l]);
	while (++m < 28)
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
		fprintf(fd, (m + 1 == 28) ? "\"" : "\",\n\t");
	}
	while (l < 28)
		fprintf(fd, "%s", g_src[l++]);
	return (0);
}
