const char data [] =
"#vapyhqr <fgqvb.u>\n\nvag\nznva (ibvq)\n{\n  hafvtarq vag v;\n\n  c"
"evags (\"pbafg pune qngn [] =\");\n  sbe ( v=0 ; qngn[v] ; v++ "
")\n    {\n      vs ( v%60 == 0 )\n\tcevags (\"\\a\\\"\");\n      fjvgp"
"u ( qngn[v] )\n\t{\n\tpnfr '\\\\':\n\tpnfr '\"':\n\t  cevags (\"\\\\%p\", q"
"ngn[v]);\n\t  oernx;\n\tpnfr '\\a':\n\t  cevags (\"\\\\a\");\n\t  oernx;\n"
"\tpnfr '\\g':\n\t  cevags (\"\\\\g\");\n\t  oernx;\n\tqrsnhyg:\n\t  cevags"
" (\"%p\", qngn[v]);\n\t}\n      vs ( v%60 == 59 || !qngn[v+1] )\n\t"
"cevags (\"\\\"\");\n    }\n  cevags (\";\\a\\a\");\n  sbe ( v=0 ; qngn["
"v] ; v++ )\n    {\n      vs ( ( qngn[v] >= 'N' && qngn[v] < 'A"
"' )\n\t   || ( qngn[v] >= 'n' && qngn[v] < 'a' ) )\n\tchgpune (q"
"ngn[v] + 13);\n      ryfr vs ( ( qngn[v] >= 'A' && qngn[v] <="
" 'M' )\n\t\t|| ( qngn[v] >= 'a' && qngn[v] <= 'm' ) )\n\tchgpune "
"(qngn[v] - 13);\n      ryfr\n\tchgpune (qngn[v]);\n    }\n  erghe"
"a 0;\n}\n";

#include <stdio.h>

int
main (void)
{
  unsigned int i;

  printf ("const char data [] =");
  for ( i=0 ; data[i] ; i++ )
    {
      if ( i%60 == 0 )
	printf ("\n\"");
      switch ( data[i] )
	{
	case '\\':
	case '"':
	  printf ("\\%c", data[i]);
	  break;
	case '\n':
	  printf ("\\n");
	  break;
	case '\t':
	  printf ("\\t");
	  break;
	default:
	  printf ("%c", data[i]);
	}
      if ( i%60 == 59 || !data[i+1] )
	printf ("\"");
    }
  printf (";\n\n");
  for ( i=0 ; data[i] ; i++ )
    {
      if ( ( data[i] >= 'A' && data[i] < 'N' )
	   || ( data[i] >= 'a' && data[i] < 'n' ) )
	putchar (data[i] + 13);
      else if ( ( data[i] >= 'N' && data[i] <= 'Z' )
		|| ( data[i] >= 'n' && data[i] <= 'z' ) )
	putchar (data[i] - 13);
      else
	putchar (data[i]);
    }
  return 0;
}