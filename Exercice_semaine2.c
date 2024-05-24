
/*
 * Nom du fichier: Exercices_semaines2.c
 * Auteur: Thanisma Even Marcelin
 * Date: 2024/05/18
 * Description:Listes d'exercices de la semaine 2 pour le cours d'INF147
 */

#define _CRT_SECURE_NO_WARNINGS // pour ignorer les erreurs pour scanf_s
#define MAX 10
#define M_PI 3.1416
#define EPSILON 0.0001
#define FACTEUR_DE_SECURITE 0.5
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


// declaration de mes sous fonctions
double calculer_aire_cercle(double rayon);
double calculer_aire_rectangle(double largeur, double longueur);
void calculer_aire_piece();
void ex_2();
double ex_3(int pop_totale);
void ex_4();
void ex_5();
void ex_6();
double ex_7(int duree, double montant_initial, double taux_interet, double montant_final);
void ex_8();
void ex_9();
void ex_10();



/*
*Nom de l'exercice: Exercices_semaines1.c
* main()
* Description:programme qui test les differents exercices de la semaine 2
* Paramètres: aucun
* Retour : status de la fin du programme
*/
int main() {

	int choix;
	int population = 0;
	double rayon = 0.0, aire_cercle = 0.0;
	double largeur = 0.0, longueur = 0.0, aire_rectangle = 0.0;
	int duree = 0;
	double montant_initial = 0.0, taux_interet = 0.0, montant_final = 0.0;

	printf("Menu des exercices de la semaine1 :\n");
	printf(" 1 => ex_1_a\n");
	printf(" 2 => ex_1_b\n");
	printf(" 3 => ex_1_c\n");
	printf(" 4 => ex_2\n");
	printf(" 5 => ex_3\n");
	printf(" 6 => ex_4\n");
	printf(" 7 => ex_5\n");
	printf(" 8 => ex_6\n");
	printf(" 9 => ex_7\n");
	printf("10 => ex_8\n");
	printf("11 => ex_9\n");
	printf("12 => ex_10\n");
	printf("13 => Pour voir le code secret.\n");
	printf("14 => Pour mettre fin au programme.\n");


	do {
		printf("\n\nVeuillez entrez votre choix: ");
		scanf(" %d", &choix);

		switch (choix) {
		case 1:
			printf("\nCe programe permet de calculer l’aire d’un cercle => \n\n");
			calculer_aire_cercle(rayon);
			printf("L'aire du cercle est: %.2lf\n", aire_cercle);
			break;
		case 2:
			printf("\nCe programe permet de calculer l’aire d’un rectangle => \n\n");
			calculer_aire_rectangle(largeur, longueur);
			printf("L'aire du rectangle est: %.2lf\n", aire_rectangle);
			break;
		case 3:
			printf("\nCe programe permet de calculer l’aire d’une piece => \n\n");
			calculer_aire_piece();
			break;
		case 4:
			printf("\nCe programe  permet d’obtenir la valeur d’un point x de type double sur une courbe => \n\n");
			ex_2();
			break;
		case 5:
			printf("\nCe programe permet de savoir quand un certain nombre de cellules de levures a ete atteint => \n\n");
			printf("Le temps requis pour atteindre cette population est: %.2lf\n", ex_3(population));
			break;

		case 6:
			printf("\nCe programe permet d'indiquer une direction selon votre choix => \n\n");
			ex_4();
			break;
		case 7:
			printf("\nCe programe permet de compter => \n\n");
			ex_5();
			break;
		case 8:
			printf("\nCe programe permet d'afficher les valeurs du compteurs de la seconde boucle => \n\n");
			ex_6();;
			break;
		case 9:
			printf("\nCe programe permet de calculer le montant final d'un placement => \n\n");
			ex_7(duree, montant_initial, taux_interet, montant_final);
			break;
			/*case 10:
			printf("\nCe programe permet d'echanger deux valeurs en memoire => \n\n");
			Suppl_Ex2();
			break;
		case 11:
			printf("\nCe programe permet de calculer le diametre, l'aire et le volume d'une sphere ou l'aire d'un anneau=> \n\n");
			Suppl_Ex3();
			break;
		case 12:
			printf("\nCe programe permet de calculer la racine carree d'un nombre a par la methode de Newton => \n\n");
			Suppl_Ex4();
			break; */
		case 13:
			printf("La vie d'un futur  ingenieur est comme un code à deboguer:");
			printf("chaque probleme est une enigme a resoudre, et chaque \n");
			printf("solution nous rapproche un peu plus de la perfection.\n");
			printf("Ainsi, chaque défi est une opportunité de croissance,\n");
			printf("et chaque obstacle surmonte est une preuve\n");
			printf("de sa determination et de son ingeniosite.");
			break;
		case 14:
			printf("Fin du programme.\n");
			break;
		default:
			printf("Choix invalide. Veuillez réessayer.\n");
		}

	} while (choix != 14);

	// garde la console ouverte
	system("pause");
	return EXIT_SUCCESS;
}

double calculer_aire_cercle(double rayon) {
	return M_PI * rayon;
}

double calculer_aire_rectangle(double largeur, double longueur) {
	return largeur * longueur;
}


void calculer_aire_piece() {
	double diametre = 0.0;
	double aire_piece = 0.0;
	double aire_rectangle = 0.0;
	double aire_cercle = 0.0;
	double largeur = 0.0;
	double longueur = 0.0;
	double rayon = 0.0;

	printf("Veuillez entrer une valeure decimale pour le rayon: \n");
	scanf(" %lf", &rayon);

	printf("Veuillez entrer la largeur du rectangle: \n");
	scanf(" %lf", &largeur);

	printf("Veuillez entrer la largeur du rectangle: \n");
	scanf(" %lf", &largeur);


	calculer_aire_cercle(rayon);
	calculer_aire_rectangle(largeur, longueur);
    
	diametre = rayon * 2;

	printf("L'aire du rectangle est: %.2lf\n", aire_rectangle);
	printf("L'aire du cercle est: %.2lf\n", aire_cercle);


	if (diametre < (longueur * FACTEUR_DE_SECURITE) && diametre < (largeur * FACTEUR_DE_SECURITE)) {
		aire_piece = aire_rectangle - aire_cercle;

		printf("L'aire de la piece est: %.2lf\n", aire_piece);
	}
	else {
		printf("le facteur de securite n’a pas ete respecte");
		exit(EXIT_FAILURE);
	}
}

void ex_2() {
	double x = 0;
	double fonction = 0;

	printf("Veuillez entrer le point x rechercher: \n");
	scanf(" %lf", &x);

	fonction = 1 / (1 + exp(-x));

	printf("La valeur du point x rechercher est: %lf\n", fonction);
}


/*
* Nom de l'exercice: ex_3
* Description: Ce programe permet de savoir quand un certain nombre de cellules de levures a ete atteint
* Paramètres: 1
* Retour : temps_requis
*/

double ex_3(int pop_totale) {

	double temps_requis = 0;

	printf("Veuillez entrer une valeur entiere de la population totale: \n");
	scanf(" %d", &pop_totale);


	return 	temps_requis = log(pop_totale) / log(2);
}

void ex_4() {

	int choix;

	printf("Menu des points cardinaux :\n");
	printf(" 1 => Nord\n");
	printf(" 2 => Sud\n");
	printf(" 3 => Est\n");
	printf(" 4 => Ouest\n");
	printf("5 => Pour mettre fin au programme.\n");


	do {
		printf("\n\nVeuillez entrez votre choix: ");
		scanf(" %d", &choix);

		switch (choix) {
		case 1:
			printf("\nVous allez vers le Nord. \n\n");
			break;
		case 2:
			printf("\nVous allez vers le Sud. \n\n");
			break;
		case 3:
			printf("\nVous allez vers l'Est. \n\n");
			break;
		case 4:
			printf("\nVous allez vers l'Ouest. \n\n");
			break;
		case 5:
			printf("Fin du programme.\n");
			break;
		default:
			printf("Choix invalide! Veuillez réessayer.\n");
		}

	} while (choix != 5);
}

void ex_5() {

	int i = 0;

	printf(" Les valeurs du premier compteur sont : %d\n", i);
	for (int i = 1; i <= 10; i++) {

		printf(" [%d],\t", i);
	}
	printf("\n\n\nLes valeurs du deuxieme compteur sont : %d\n", i);
	for (int i = 10; i >= -20; i--) {

		printf(" [%d],\t", i);
	}
	printf("\n\n\nLes valeurs du troisieme compteur sont : %d\n", i);
	for (int i = 100; i <= 200; i += 5) {

		printf(" [%d],\t", i);
	}
	printf("\n\n\nLes valeurs du quatrieme compteur sont : %d\n", i);
	for (int i = -100; i <= 100; i += 50) {

		printf(" [%d],\t", i);
	}
}

void ex_6() {

	int i = 0;

	printf("  Les valeurs du compteurs de la seconde boucle sont: ");
	for (int i = 1; i <= 100; i++) {
		for (int j = i; j <= 100; j += 2) {

			printf(" [%d],\t", j);
		}
	}
}


/*
* Nom de l'exercice: ex_7
* Description: Ce programe permet de calculer le montant final d'un placement
* Paramètres: 4
* Retour : montant_final
*/

double ex_7(int duree, double montant_initial, double taux_interet, double montant_final) {

	montant_initial = 0.0;
	taux_interet = 0.0;
	montant_final = 0.0;
	duree = 0;
	double taux = 0.0;

	printf("Quel est le montant initial: ");
	scanf(" %lf", &montant_initial);

	printf("Quel est la duree: ");
	scanf(" %d", &duree);

	printf("Quel est le taux d'interet: ");
	scanf(" %lf", &taux_interet);

	for (int i = 1; i <= duree; i++) {
		taux *= (1 + taux_interet);
	}

	printf(" Le montant final est: %.2lf", montant_final);

	return montant_final = montant_initial * taux;
}
  
