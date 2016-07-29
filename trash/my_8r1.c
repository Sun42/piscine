/*
** my_8r1.c for les 8 reines 1 in /u/all/sundas_c/cu/rendu/piscine/Jour_05
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Fri Oct 10 18:07:34 2008 christophe sundas
** Last update Mon Oct 13 19:49:35 2008 christophe sundas
*/

int	my_8r1();
int     verif_column(int iline,int indice_col, int *tab);
int     verif_bishop_upleft(int iline, int icol, int *tab);
int     verif_bishop_upright(int iline, int icol, int *tab);
int     put_queen(int iline, int icol, int *tab);
void	test(int *tab);

int	main()
{
  my_8r1();
  return (0);
}

int     my_8r1()
{
  int	tab[8];
  int	i;
	
  /* *nbr = 0; */
  i = 0;
  while(i <= 7)
    {
      tab[i] = 0;
      i = i + 1;
    }
  put_queen(0, 1, tab);
  return (0);
}

int	verif_column(int iline, int indice_col, int *tab)
{
  int i;

  i = 0;
  while (i <= iline)
    {
      if (tab[i] == indice_col)
	{
	  return (0);
	}
      i = i +1;
    }
  return (1);
}

int	verif_bishop_upleft(int iline, int icol, int *tab)
{
  while ((iline > 0) && (icol > 1))
    {
      if (tab[iline - 1] == icol - 1)
	{
	  return (0);
	}
      iline = iline - 1;
      icol = icol - 1;
    }
  return (1);
}

int	verif_bishop_upright(int iline, int icol, int *tab)
{
  while ((iline > 0) && (icol < 8))
    {
      if (tab[iline - 1] == icol + 1)
	{
	  return (0);
	}
      iline = iline - 1;
      icol = icol + 1;
    }
  return (1);
}

int     put_queen(int iline, int icol, int *tab)
{   
  while (tab[7] == 0)
    {
      printf(" LINE:::%i,COL::::: %i\n", iline ,icol);
      if (verif_bishop_upleft(iline, icol, tab) && verif_bishop_upright(iline, icol, tab) && verif_column(iline, icol, tab))
	{
	  if (iline == 2)
	    {
	      /**nbr = *nbr + 1;*/
	     printf("GOOD LINE:::%i,COL::::: %i\n",iline , icol);
	    }
	  tab[iline] = icol;
          put_queen(iline + 1, 1 , tab);
        }
      else
        {
          if (icol < 8)
            {
	      put_queen(iline, icol + 1, tab);
            }
          else
            {
	      printf("ILINE :%i", iline);
	      printf("TEST :%d",(tab[iline - 1]) + 1);
	      if ((tab[iline - 1] + 1 ) > 7)
		{
		  put_queen(iline - 2, tab[iline - 2] + 1,tab);
		}
	      put_queen(iline - 1, tab[iline - 1] + 1, tab);
            }
	}
    }
  printf("SORTIE SANS MEME ENTRER\n");
  return (0);
}
