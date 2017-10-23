#include <fcntl.h>
#include <string.h>
#include <stdio.h>

char *src = "#include <fcntl.h>\n#include <string.h>\n#include <stdio.h>\n\nchar *src = \"%s\";\n\nint main()\n{\n\tFILE\t*fd;\n\tchar\tbuff[1000];\n\tfd = fopen(\"Colleen\", \"w\");\n\tfprintf(fd, src, src);\n}\n";

int main()
{
	FILE	*fd;
	char	buff[1000];

	fd = fopen("Colleen", "w");
	fprintf(fd, src, src);
}