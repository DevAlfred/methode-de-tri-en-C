//Directives du preprocesseur
#include <stdio.h>
#include <stdlib.h>
//Declaration des autres fonctions ou procedure autre que main
void tri_rapide(int *tab, int debut_tab, int taille_tab);
void permuter(int *a , int *b);

//Debut de la fonction main
int main()
{
     int i,n; //declaration de notre variable i qui va nous permettre d'afficher chaque element du tableau une fois trié
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
    
    tri_rapide(tab,0,n-1); //appel de la precedure tri_rapide

    //Affichage du tableau trié
    printf("Tableau trie :\n{");
    for ( i = 0; i < n; i++)
    {
     printf(" %d ",tab[i]);
    }
    printf("}"); 

    return 0;

} //fin de la fonction main


//Definition des autres fonctions autre que main

// permuter
void permuter(int *a , int *b){
    int temp;
    temp= *a;
    *a=*b;
    *b=temp;
}

// tri_rapide
void tri_rapide(int *tab, int debut_tab , int taille_tab){
    

    if (taille_tab>debut_tab) //Si le tableau contient au moins 2 elements
    {


    int p,k,i,temp;

    p=debut_tab;

    permuter( &tab[0],&tab[p] );

    k=0;
    for ( i = debut_tab; i <= taille_tab; i++) //cette boucle for permet de placer le pivot (début du tableau à trier dans mon cas)
    {                                 //au bon endroit dans le tableau
        if (tab[i]<tab[0])            //avec toutes les valeurs plus petites avant
                                      //et les valeurs plus grandes après
        {
            k++;
    
           permuter( &tab[k],&tab[i] );


        }
        
    } //fin de la boucle for
            
   permuter( &tab[k],&tab[0] );

    /*rappel de la procédure tri_rapide
    sur le début du tableau jusquà k-1 */
    tri_rapide(tab,0,k-1);

    /*Et rappel de la procédure de tri_rapide
    sur la fin du tableau à partir de la première valeur après le pivot : k+1 */
    tri_rapide(tab,k+1,taille_tab);

    }
}

//fin