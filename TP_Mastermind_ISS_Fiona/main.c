#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#define CARN '-'
#define CARVERT 'v'
#define CARJAUNE 'j'


//Prototype
void random(int CODE[4]);
void initCouleur (char nTabCouleur[4]);
void testbon(int nProposition[4],char nTabCouleur[4],int CODE[4]);
void testmal (int nProposition[4],char nTabCouleur[4],int CODE[4]);
void test(int nProposition[4], int nTabEssai[12][4],char nTabCouleur[4], int nEssai, int CODE[4]);
void affichage(int nEssai, int nProposition[4], char nTabCouleur[4], int nTabEssai[12][4]);



//Programme principal
int main()
{
	srand(time(NULL)); //Fonction qui génère de l'aléatoire
    int CODE[4]; //tableau contenant le code secret
	int nTest = 0;
	int nTesttemp=0;
	int nEssai=0;
	int nTabEssai[12][4]; //tableau contenant les différents essais
	char nTabCouleur[4]; //tableau permettant d'affiche si le chiffre est bien ou mal placé
	int nProposition[4]; //La proposition du joueur

	random(CODE);//on appelle la fonction random pour que le code secret soit généré aléatoirement

	//Boucle qui permet d'afficher le CODE secret
	/*for (int i = 0; i < 4; ++i)
	{
		printf("%d\n",CODE[i] );
	}*/

    printf("Nous allons jouer au Mastermind\n");
    while ((nEssai<12)) //tant que le nombre d'essai est inférieur à 12
    {
        initCouleur (nTabCouleur); //on initialise le tableau de couleur
        printf("Veuillez donner votre proposition\n");
    	for (int i = 0; i < 4; ++i) //on demande à l'utilisateur sa proposition
    	{
    		printf("Chiffre %d : ",i+1);
    		scanf("%d",&nProposition[i]);
    	}
    	nEssai++;
    	for (int i = 0; i < 4; ++i)//on vérifie si la proposition est la même chose que le code secret
    	{
    		if (nProposition[i]==CODE[i]) nTesttemp++;
    	}
    	if ((nTesttemp==4)&&(nEssai<12)) //si c'est le cas on affiche "gagne"
    	{
    		printf("Vous avez gagne\n");
    		nEssai=14;
    	}
    	else //sinon on appelle les procédures pour tester et afficher
    	{
    		test(nProposition,nTabEssai,nTabCouleur,nEssai,CODE);
    		affichage(nEssai,nProposition,nTabCouleur,nTabEssai);
    		nTesttemp=0;
    	}

    }
    printf("Vous êtes au maximum des essais\n");
    printf("La réponse est : \n");
    for (int i = 0; i < 4; ++i)
	{
		printf("%d\n",CODE[i] );
	}

    return 0;
}


//Cette procédure permet de vérifier si le chiffre est placé au bon endroit
void testbon (int nProposition[4],char nTabCouleur[4],int CODE[4])
{
	int nBon=0;
	for (int i = 0; i < 4; ++i)
	{
		if ((nProposition[i]==CODE[i])) nBon++;
		while ((nBon!=0)&&(nTabCouleur[i]==CARN))
		{

			nTabCouleur[i]=CARVERT;
			nBon--;
		}
	}
}

//Cette procédure permet de vérifier si le chiffre est présent dans le code mais est mal placé
void testmal (int nProposition[4],char nTabCouleur[4],int CODE[4])
{
	int nMal=0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if ((nProposition[i]==CODE[j])&&(i!=j)&&(nProposition[i]!=nProposition[j])) nMal++;
			while ((nMal!=0)&&(nTabCouleur[i]==CARN))
		{

			nTabCouleur[i]=CARJAUNE;
			nMal--;
		}
		}
	}
}

//Cette procédure permet d'appeler les deux procédures test et de placer la proposition du joueur dans le tableau des essai
void test (int nProposition[4], int nTabEssai[12][4],char nTabCouleur[4], int nEssai, int CODE[4])
{
	testbon(nProposition,nTabCouleur,CODE);
	testmal (nProposition,nTabCouleur,CODE);
	for (int i = 0; i < 4; ++i)
	{
		nTabEssai[nEssai-1][i]=nProposition[i];
		nTabEssai[nEssai-1][i]=nProposition[i];
		nTabEssai[nEssai-1][i]=nProposition[i];
		nTabEssai[nEssai-1][i]=nProposition[i];
	}
	
}

//Cette procédure permet d'afficher les différentes informations
void affichage (int nEssai, int nProposition[4], char nTabCouleur[4], int nTabEssai[12][4])
{

	for (int i = 0; i < 4; ++i)
	{
		printf("%d",nProposition[i]);
	}
	printf("\n");
	for (int i = 0; i < 4; ++i)
	{
		printf("%c ",nTabCouleur[i]);
	}
	printf("\n");

	for (int i = 0; i < nEssai; ++i)
	{

		for (int j = 0; j < 4; ++j)
		{
			printf("%d",nTabEssai[i][j]);
			
		}
		printf("\n");
	}
}

//Cette procédure permet d'initialiser le tableau ou l'on affiche la lettre de la couleur
void initCouleur (char nTabCouleur[4])
{
	for (int i = 0; i < 4; ++i)
	{
		nTabCouleur[i]=CARN;
	}
}
 //Cette procédure permet de générer aléatoirement un chiffre de 0 à 9
void random(int CODE[4])
{
	for (int i = 0; i < 4; ++i)
	{
		CODE[i]=(rand()%9);
	}
}
