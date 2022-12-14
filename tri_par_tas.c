#include <stdio.h>  //directives du preprossesseur
 
void affiche(int T[], const int n); //declaration de la procedure achicher
void echanger (int T[], int i, int j); //declaration de la procedure echanger
void remonter (int T[], int n, int i); //declaration de la procedure pour faire monter un element
void redescendre ( int T[], const int n, int i); //declaration de la procedure pour faire descendre un element
void organiser( int T[], int n );       //declaration de la procedure pour organiser l'arbre
void Tri_Arbre( int T[], const int n ); //declaration de la procedure tri arbre


// Debut de la fonction principale main
int main() 
 
{
 
        int n,i,T[100];
        
  printf("Combien de nombres dans le tableau ? Taille max = 100 a ne pas depasser !");
  do
  {
        scanf("%d", &n); //on recupère la taille du tableau
        if (n>100)
        {
                printf("%d > 100 !! Entrer un nombre inferieur ou egal a 100 ! ",n);
        }
        

  } while (n>100);
  

  printf(" Entrez %d entiers : ", n);
 
  for (i = 0; i < n; i++){
        printf("Nombre %d = ",i+1);
       scanf("%d", &T[i]);   //on rempli notre tableau
  }
 
        printf("Tableau de depart : ");
        affiche(T, n);
 
        Tri_Arbre( T, n );
 
        printf("Tableau trie : ");
        affiche(T, n);
 
        return 0;
 
}



// Debut de la procedure afficher
void affiche(int T[], const int n)
 
{
 
        int i;
 
        printf("{");
 
        for(i=0;i<n;++i)
 
        {
            printf("%ld ",T[i]);
        }
 
        printf("}\n");
 
}
 
  
// Debut de la procedure echanger
void echanger (int T[], int i, int j)
 
{
        int temp;
        temp=T[i];       
        T[i]=T[j];
        T[j]=temp;
 
}
 
// Debut de la procedure remonter
void remonter (int T[], int n, int i)
 
{
 
        if (i==0) return; //Si on atteint la racine de l'arbre, on n'arrette de monter
 
        if (T[i]>T[i/2]) //si le nombre qui est en dessous(ou à gauche) est superieur à celui du haut(ou du droite)
 
        {
 
                echanger (T, i, i/2); //alors on echange leur place
 
                remonter (T, n, i/2); //Ensuite on rappelle de manière recursive remonter
 
        }
 
}
 
// Debut de la procedure redescendre qui va nous permettre de reconstituer le tas
void redescendre ( int T[], int n, int i)
 
{
 
        int imax;
 
        if (2*i+1>=n) return; //si on le nombre plus grand bien placé, on s'arrête   
 
        if (T[2*i+1]>T[2*i])   
 
        imax=2*i+1;
 
        else
 
        imax=2*i;
 
        if (T[imax]>T[i])
 
        {
 
                echanger (T, imax, i);
 
                redescendre (T, n, imax);
 
  
 
        }
 
}
 
// Debut de la procedure organiser
void organiser( int T[], int n )
 
{
 
        int i;
 
        for(i = 1 ; i < n ; i++)  

        remonter(T, n, i);
 
}
 
  
// Debut de la procedure tri_arbre
void Tri_Arbre( int T[], int n )
 
{
 
        int i;
 
        organiser(T, n);   //on va constituer un tas
 
        for(i=n-1 ; i>0 ; i-- ) //on parcourt l'arbre de bas en haut
 
        {
 
                echanger(T, 0, i);  
 
                redescendre(T, i, 0);
 
        }
 
}
 
  
 