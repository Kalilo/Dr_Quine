#include <ctype.h>
#include <stdio.h>

int main()
{
  printf(iscntrl('\"') ? "Yes\n" : "No\n");
  return (0);
}