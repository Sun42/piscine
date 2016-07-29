int     main(int argc, char **argv)
{
  char **piece;
  char **tab;

  piece = malloc(sizeof(*piece) * 4);
  *(piece) = malloc(sizeof(**piece) * 7);
  *(piece + 1) = malloc(sizeof(**piece) * 7);
  *(piece + 2) = malloc(sizeof(**piece) * 7);
  *(piece) = "..00..";
  *(piece + 1) = "..00..";
  *(piece + 2) = "..00..";
  *(piece + 3) = NULL;

  tab = malloc(sizeof(*tab) * 10);
  int i;
  i = 0;
  while (i <= 10)
    {
      *(tab + i) = malloc(sizeof(**tab) * 11);
      *(tab + i) = "..........";
      i = i + 1;
    }
  *(tab + 4) = ".....0....";

  printf("%i\n", check(tab, piece, 0, 0));
  return (0);
}
