#include <stdio.h>
 
int is_valid(const char *tab, int line, int cas)
{
        int i, j, ret;
 
        for (i = 0, ret = 0; i < line && (tab[i] != cas || ++ret); i++)
                ;
        for (i = line - 1, j = cas - 1; i >=0 && j >= 0 && !ret && (tab[i] != j || ++ret); i--, j--)
                ;
        for (i = line - 1, j = cas + 1; i >=0 && j < 8 && !ret && (tab[i] != j || ++ret); i--, j++)
                ;
        return ret;
}
 
void aff(const char *tab)
{
        int i, j;
 
        for (i = 0; i < 8; i++) {
                printf("\n");
                for (j = 0; j < 8; j++)
                         if (tab[i] == j)
                                printf("X ");
                         else
                                printf("0 ");
        }
 
        printf("\n\n");
}   
 
int recu(char *tab, int line)
{
        static int solution = 0;
        int cas;
 
        if (line == 8) {
                aff(tab);
                return ++solution;
        }
 
        for (cas = 0; cas < 8; cas++) {
                if (!is_valid(tab, line, cas)) {
                        tab[line] = cas;          
                        recu(tab, line + 1);
                        tab[line] = 9;
                }
        }
 
        return solution;
}
 
int main(void)
{
        char tab[8] = {9, 9, 9, 9, 9, 9, 9, 9};
 
        printf("Les 8 reines peuvent se r	soudre de %d m	thodes\n", recu(tab, 0));
        return 0;
}
