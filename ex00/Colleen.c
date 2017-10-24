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

/*
	This program will print its own source when run.
*/

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
	"nclude <string.h>\n#include <stdio.h>\n#include <ctype.h>\n\n/*\n\tThis p",
	"rogram will print its own source when run.\n*/\n\nchar\t\t*g_src[30] = { ",
	" };\n\nchar\t*escape_special(char c)\n{\n\tif (c == '\\\"')\n\t\treturn (",
	"\"\\\\\\\"\");\n\tif (c == '\\t')\n\t\treturn (\"\\\\t\");\n\tif (c == '",
	"\\n')\n\t\treturn (\"\\\\n\");\n\treturn (\"\\\\\\\\\");\n}\n\nint\t\tmai",
	"n(void)\n{\n\tint\t\tk;\n\tint\t\tl;\n\tint\t\tm;\n\tchar\tc;\n\n\t/*\n\t",
	"\tThis program will print its own source when run.\n\t*/\n\tl = -1;\n\tm ",
	"= -1;\n\twhile (++l < 15)\n\t\tprintf(\"%s\", g_src[l]);\n\twhile (++m < ",
	"27)\n\t{\n\t\tprintf(\"%c\", '\"');\n\t\tk = -1;\n\t\twhile (g_src[m][++k",
	"])\n\t\t{\n\t\t\tc = g_src[m][k];\n\t\t\tif (!(c == '\\\"' || c == '\\t",
	"' || c == '\\n' || c == '\\\\'))\n\t\t\t\tprintf(\"%c\", g_src[m][k]);\n",
	"\t\t\telse\n\t\t\t\tprintf(\"%s\", escape_special(g_src[m][k]));\n\t\t}\n",
	"\t\tprintf((m + 1 == 27) ? \"\\\"\" : \"\\\",\\n\\t\");\n\t}\n\twhile (l ",
	"< 27)\n\t\tprintf(\"%s\", g_src[l++]);\n}\n" };

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

int		main(void)
{
	int		k;
	int		l;
	int		m;
	char	c;

	/*
		This program will print its own source when run.
	*/
	l = -1;
	m = -1;
	while (++l < 15)
		printf("%s", g_src[l]);
	while (++m < 27)
	{
		printf("%c", '"');
		k = -1;
		while (g_src[m][++k])
		{
			c = g_src[m][k];
			if (!(c == '\"' || c == '\t' || c == '\n' || c == '\\'))
				printf("%c", g_src[m][k]);
			else
				printf("%s", escape_special(g_src[m][k]));
		}
		printf((m + 1 == 27) ? "\"" : "\",\n\t");
	}
	while (l < 27)
		printf("%s", g_src[l++]);
}
