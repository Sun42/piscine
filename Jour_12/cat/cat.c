/*
** cat.c for read write file moulinette je te hais! in /u/all/sundas_c/cu/rendu/piscine/Jour_12/cat
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Oct 23 01:00:59 2008 christophe sundas
** Last update Thu Oct 23 19:03:50 2008 christophe sundas
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "my.h"

#define BUFF_SIZE 2048

char	*my_perror(int num_error);
void	display_error(char *file_name, int  num_error);

int	main(int argc, char **argv)
{
  int	i;
  char	buffer[BUFF_SIZE];
  int	nbread;

  i = 1;
  if (argc == 0)
    {
      return (0);
    }
  if (argc == 1)
    {
      while (1)
	{ 
	  nbread = read(0, buffer, BUFF_SIZE);
	  write(2, buffer, nbread);
	}
    }
  else
    {
      while (i < argc)
	{
	  cat(argv[i]);
	  i = i + 1;
	}
    }
  return (0);
}

int	cat(char *file_name)
{
  int	file_descriptor;
  char	buffer[BUFF_SIZE];
  int	nbread;
  
  file_descriptor = open(file_name, O_RDONLY);
  if (file_descriptor == -1)
    {
      display_error(file_name, errno);
      return (-1);
    }
  nbread = read(file_descriptor, buffer, BUFF_SIZE);
  while (nbread > 0)
    {
      if (nbread == -1)
	{
	  display_error(file_name, errno);
	  return (-1);
	}
      write(1, buffer, nbread);
      nbread = read(file_descriptor, buffer, BUFF_SIZE);
    }
  close(file_descriptor);
}

char	*my_perror(int num_error)
{
  char	*tab[64];
  
  tab[0] = "Undefined error: 0\n";
  tab[1] = "Operation not permitted\n";
  tab[2] = "No such file or directory\n";
  tab[3] = "No such process\n";
  tab[4] = "Interrupted system call\n";
  tab[5] = "Input/output error\n";
  tab[6] = "Device not configured\n";
  tab[7] = "Argument list too long\n";
  tab[8] = "Exec format error\n";
  tab[13] = "Permission denied\n";
  tab[63] = "File name too long\n";
    return (tab[num_error]);
}

void	display_error(char *file_name, int  num_error)
{
  write(2, "cat: ", my_strlen("cat: "));
  write(2, file_name, my_strlen(file_name));
  write(2, ": ", my_strlen(": "));
  write(2, my_perror(num_error), my_strlen(my_perror(num_error)));
}
