#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INITIALSIZE 100

int main(int argc, char *argv[])
{
  int i, tam, num;
  FILE *x;
  char *s;

  tam = INITIALSIZE;
  s = malloc(sizeof(char) * tam);

  x = fopen(argv[1], "r");

  if (!x)
  {
    perror("Erro ao abrir o primeiro arquivo");
    exit(1);
  }

  while (!feof(x))
  {
    fread(&num, sizeof(int), 1, x);

    if (num > tam)
    {
      s = realloc(s, sizeof(char) * (num + 1));
      tam = num;
    }

    fread(&s[num], sizeof(char), 1, x);
  }

  puts(s);

  free(s);
  fclose(x);
}