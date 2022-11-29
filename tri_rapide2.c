#include <stdio.h>

void permuter(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void triRapid(int tab[], int first, int last) {
    int pivot, i, j;
    if(first < last) {
        pivot = first;
        i = first;
        j = last;
        printf("a i=%d \n",i);
        printf("a j=%d \n",j);
        while (i < j) {
            while(tab[i] <= tab[pivot] && i < last)
                i++;
                printf("i=%d \n",i);
            while(tab[j] > tab[pivot])
                j--;
                printf("j=%d \n",j);
            if(i < j) {
                printf("Ci=%d \n",i);
                printf("Cj=%d \n",j);
                permuter(&tab[i], &tab[j]);
            }
        }
        permuter(&tab[pivot], &tab[j]);
        triRapid(tab, first, j - 1);
        triRapid(tab, j + 1, last);
    }
}

int main() {
    int tab[100], nbr, i;
  
    printf("\n Entrer le nombre total d'elements :  ");
    scanf("%d", &nbr);
    
    printf("\n Entrer les elements du tableau  :  ");
    for(i = 0; i < nbr; i++)
        scanf("%d", &tab[i]);
    
    triRapid(tab, 0, nbr - 1);
    
    printf("\n Tableau trie : ");
    for(i = 0; i < nbr; i++)  {
        printf(" %4d", tab[i]);
    }
    printf("\n");
    return 0;
}