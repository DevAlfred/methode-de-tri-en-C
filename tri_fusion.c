#include <stdio.h>

void triFusion(int i, int j, int tab[], int tmp[]);

int main() {
  int  nbr, i;
 
  printf(" Entrez le nombre d'elements dans le tableau: ");
  scanf("%d", &nbr);
 int tab[nbr], tmp[nbr];
  printf(" Entrez %d entiers : ", nbr);
 
  for (i = 0; i < nbr; i++)
    scanf("%d", &tab[i]);
 
  triFusion(0, nbr-1, tab, tmp);
 
  printf("\n Tableau trie : {");
  for(i = 0; i < nbr; i++)  {
     printf("%d ", tab[i]);
  }
  printf("}\n");
  
  return 0;
}

void triFusion(int i, int j, int tab[], int tmp[]) {
    if(j <= i){
        return;
    }
  
    int m = (i + j) / 2;
    
    triFusion(i, m, tab, tmp);     //diviser la moitié gauche récursivement
    triFusion(m + 1, j, tab, tmp); //diviser la moitié droite récursivement
    
    int pg = i;     //pg pointe au début du sous-tableau de gauche
    int pd = m + 1; //pd pointe au début du sous-tableau de droite
    int c;          //compteur

// on boucle de i à j pour remplir chaque élément du tableau final fusionné
    for(c = i; c <= j; c++) {
        if(pg == m + 1) { //le pointeur du sous-tableau de gauche a atteint la limite
            tmp[c] = tab[pd];
            pd++;
        }else if (pd == j + 1) { //le pointeur du sous-tableau de droite a atteint la limite
            tmp[c] = tab[pg];
            pg++;
        }else if (tab[pg] < tab[pd]) { //le pointeur du sous-tableau de gauche pointe vers un élément plus petit
            tmp[c] = tab[pg];
            pg++;
        }else {  //le pointeur du sous-tableau de droite pointe vers un élément plus petit
            tmp[c] = tab[pd];
            pd++;
        }
    }

    for(c = i; c <= j; c++) {  //copier les éléments de tmp[] à tab[]
        tab[c] = tmp[c];
    }
}