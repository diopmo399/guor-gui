#include <stdio.h>

#include "fonction-utils.h"

// Définition de la structure et des types
// ...

// Déclaration des fonctions
// ...

int main() {
    liste_emp ma_liste = NULL;

    int choixGeneral, choixMAJ, choixAjouter, choixSupprimer, choixModifier;

    do {
        // Affichage du Menu Général
        printf("MENU GÉNÉRAL\n");
        printf("1. Création des employés\n");
        printf("2. Mise à jour de la liste des employés\n");
        printf("3. Calcul et affichage des salaires des employés\n");
        printf("4. Recherche, affichage et Tri\n");
        printf("5. Quitter\n");
        printf("Donner votre choix SVP : ");
        scanf("%d", &choixGeneral);

        switch (choixGeneral) {
            case 1:
                // Appel de la fonction CREATION pour créer des employés
                CREATION(&ma_liste);
                break;

            case 2:
                do {
                    // Affichage du Menu MAJ
                    printf("MENU MAJ\n");
                    printf("1. Ajouter un nouvel employé\n");
                    printf("2. Supprimer un employé\n");
                    printf("3. Modifier les données d'un employé\n");
                    printf("4. Retour Menu général\n");
                    printf("Donner votre choix SVP : ");
                    scanf("%d", &choixMAJ);

                    int mat;
                    char nom[20];
                    char prenom[20];
                    char adresse[50];
                    int jour, mois, annee;
                    int telephone;
                    char service;
                    float salairebrut;
                    int position;

                    switch (choixMAJ) {
                        case 1:
                            do {
                                // Affichage du Menu Ajouter
                                printf("MENU AJOUTER\n");
                                printf("1. Ajout en tête\n");
                                printf("2. Ajout en queue\n");
                                printf("3. Ajout dans une position\n");
                                printf("4. Retour au menu MAJ\n");
                                printf("Donner votre choix SVP : ");
                                scanf("%d", &choixAjouter);


                                    // Traiter le choix du menu Ajouter
                                    switch (choixAjouter) {
                                        case 1:
                                            // Ajout en tête
                                            // appel à la fonction insere_tete_emp
                                            printf("Saisissez les informations de l'employé :\n");



                                            // Saisie des données de l'employé
                                            mat = obtenirMatiricule(&ma_liste);

                                            printf("Nom : ");
                                            scanf("%s", nom);

                                            printf("Prénom : ");
                                            scanf("%s", prenom);

                                            printf("Adresse : ");
                                            scanf("%s", adresse);

                                            printf("Date d'embauche (jour mois annee) : ");
                                            scanf("%d %d %d", &jour, &mois, &annee);

                                            printf("Téléphone : ");
                                            scanf("%d", &telephone);

                                            printf("Service : ");
                                            scanf(" %c", &service);

                                            printf("Salaire brut : ");
                                            scanf("%f", &salairebrut);

                                            // Appel de la fonction insere_tete_emp
                                            inserer_tete_emp( &ma_liste, mat, nom, prenom, adresse, jour, mois, annee, telephone, service, salairebrut);
                                            choixAjouter = 4;
                                            printf("Employé ajouté avec succès en tête de la liste.\n");
                                            break;
                                        case 2:
                                            // Ajout en queue
                                            printf("Saisissez les informations de l'employé :\n");

                                            // Saisie des données de l'employé
                                            mat = obtenirMatiricule(&ma_liste);


                                            printf("Nom : ");
                                            scanf("%s", nom);

                                            printf("Prénom : ");
                                            scanf("%s", prenom);

                                            printf("Adresse : ");
                                            scanf("%s", adresse);

                                            printf("Date d'embauche (jour mois annee) : ");
                                            scanf("%d %d %d", &jour, &mois, &annee);

                                            printf("Téléphone : ");
                                            scanf("%d", &telephone);

                                            printf("Service : ");
                                            scanf(" %c", &service);
                                            //   printf("\n"); // Nouvelle ligne pour séparer visuellement les saisies

                                            printf("Salaire brut : ");
                                            scanf("%f", &salairebrut);

                                            // Appel de la fonction insere_queue_emp
                                            insere_queue_emp(&ma_liste, mat, nom, prenom, adresse, jour, mois, annee, telephone, service, salairebrut);
                                            choixAjouter = 4;
                                            printf("Employé ajouté avec succès en queue de la liste.\n");
                                            break;
                                        case 3:
                                            // Ajout dans une position
                                            printf("Saisissez les informations de l'employé :\n");

                                            // Saisie des données de l'employé
                                            mat = obtenirMatiricule(&ma_liste);


                                            printf("Nom : ");
                                            scanf("%s", nom);

                                            printf("Prénom : ");
                                            scanf("%s", prenom);

                                            printf("Adresse : ");
                                            scanf("%s", adresse);

                                            printf("Date d'embauche (jour mois annee) : ");
                                            scanf("%d %d %d", &jour, &mois, &annee);

                                            printf("Téléphone : ");
                                            scanf("%d", &telephone);

                                            printf("Service : ");
                                            scanf(" %c", &service);
                                            printf("\n"); // Nouvelle ligne pour séparer visuellement les saisies

                                            printf("Salaire brut : ");
                                            scanf("%f", &salairebrut);

                                            printf("Position dans la liste : ");
                                            scanf("%d", &position);

                                            // Appel de la fonction insere_pos_emp
                                            insere_pos_emp(&ma_liste, position, mat, nom, prenom, adresse, jour, mois, annee, telephone, service, salairebrut);
                                            choixAjouter = 4;
                                            printf("Employé ajouté avec succès à la position %d de la liste.\n", position);
                                            break;
                                        case 4:
                                            // Retour au menu MAJ
                                            break;
                                        default:
                                            printf("Choix invalide. Veuillez choisir une option valide.\n");
                                    }

                            } while (choixAjouter != 4);

                            break;

                        case 2:
                            do {
                                // Affichage du Menu Suppression
                                printf("MENU SUPPRESSION\n");
                                printf("1. Suppression en tête\n");
                                printf("2. Suppression en queue\n");
                                printf("3. Suppression à partir d'une position\n");
                                printf("4. Suppression d'un employé donné\n");
                                printf("5. Suppression des employés d'un service\n");
                                printf("6. Retour au menu MAJ\n");
                                printf("Donner votre choix SVP : ");
                                scanf("%d", &choixSupprimer);

                                // Traiter choixSupprimer
                                // ...

                            } while (choixSupprimer != 6);

                            break;

                        case 3:
                            do {
                                // Affichage du Menu Modification
                                printf("MENU MODIFICATION\n");
                                printf("1. Adresse\n");
                                printf("2. Téléphone\n");
                                printf("3. Retour au menu MAJ\n");
                                printf("Donner votre choix SVP : ");
                                scanf("%d", &choixModifier);

                                // Traiter choixModifier
                                // ...

                            } while (choixModifier != 3);

                            break;

                        case 4:
                            // Retour au Menu Général
                            break;

                        default:
                            printf("Choix invalide. Veuillez choisir à nouveau.\n");
                    }

                } while (choixMAJ != 4);

                break;

            case 3:
                // Calcul et affichage des salaires des employés
                // ...

                break;

            case 4:
                // Recherche, affichage et Tri
                // ...

                break;

            case 5:
                // Quitter
                break;

            default:
                printf("Choix invalide. Veuillez choisir à nouveau.\n");
        }

    } while (choixGeneral != 5);

    return 0;
}
