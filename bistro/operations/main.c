
#include "my.h"
#include "operations.h"
#include <stdlib.h>
#include <string.h>

int		main(int ac, char **av)
{
  my_putstr(operations(av[1], av[2], av[3], av[4], av[5]));
  return (0);
}

