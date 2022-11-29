#include <stdio.h>

//Declaration des autres fonctions ou procedure autre que main
void tri_selection(int tab[],int n);
void permuter(int *a, int *b);
//Fonction principale main

int main()
{
    int n,i;
     printf("Vous avez combien d elements dans votre tableau ?");
    scanf("%d",&n);  
    int tab[n]; //declaration de notre tableau tab de taille n
    
   
 for ( i = 0; i < n; i++)
    {
        printf("Entrez le %de element du tableau ? ",i+1);
        scanf("%d",&tab[i]);
    }
    //Affichage du tableau avant tri
    printf("Tableau :\n{");
    for ( i = 0; i < n; i++)
    {
     printf(" %d ",tab[i]);
    }
    printf("}\n"); 
    
    
    tri_selection(tab , n); //appel de la fonction tri_tableau_selection
    
      //Affichage du tableau trié
    printf("Tableau trie\n{");
    for ( i = 0; i < n; i++)
    {
     printf(" %d ",tab[i]);
    }
    printf("}"); 

    return 0;
}

//Definition des autres fonctions autre que main

void permuter(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
//definition d'une procedure tri_tableau_selection qui prend en entrée un tableau (tab[]) et sa taille (n)

void tri_selection(int tab[] , int n) {
    
    int i,j,min,imin,temp ; //déclaration des autres variables

    for ( i = 0; i < n; i++) //debut de la boucle pour
    {
        min = tab[i];   //on prend le 1er nombre du tableau comme plus petit (min)
        imin = i;     //on prend sa position i (imin)
        for ( j=i+1; j < n; j++) //debut de la 2e boucle 
        {
            if (tab[j] < min) //si au rang j la valeur est inferieur au min 
            {
               min = tab[j]; // alors le plus petit devient le nombre qui se trouve au rang j (tab[j])
               imin= j; 
            }       
        }
        permuter(&tab[i],&tab[imin]);
      
        
    } //fin de la boucle pour
  
}

