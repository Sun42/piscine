#include "add.h"
#include "my.h"
#include <stdlib.h>
#include <string.h>

int		main(int ac,char **av)
{
  my_putstr(addition(av[1], av[2], av[3]));
  return (0);
}

