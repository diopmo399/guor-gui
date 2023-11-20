#include <stdio.h>

#include "fonction-utils.h"

// Définition de la structure et des types
// ...

// Déclaration des fonctions
// ...

int main() {
    liste_emp ma_liste = NULL;

    int choixGeneral, choixMAJ, choixAjouter, choixSupprimer, choixModifier, choixMenuTri;

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
                                int positionSupprimer;
                                int matriculeSupprimer;
                                char serviceSupprimer;

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
                                switch (choixSupprimer) {
                                    case 1:
                                        // Suppression en tête
                                        supprimer_tete_emp(&ma_liste);
                                        printf("Employé supprimé en tête de la liste.\n");
                                        break;

                                    case 2:
                                        // Suppression en queue
                                        supprimer_queue_emp(&ma_liste);
                                        printf("Employé supprimé en queue de la liste.\n");
                                        break;

                                    case 3:
                                        // Suppression à partir d'une position
                                        printf("Position dans la liste : ");
                                        scanf("%d", &positionSupprimer);
                                        suppression_pos_emp(&ma_liste, positionSupprimer);
                                        printf("Employé supprimé à la position %d de la liste.\n", positionSupprimer);
                                        break;

                                    case 4:
                                        // Suppression d'un employé donné

                                        printf("Matricule de l'employé à supprimer : ");
                                        scanf("%d", &matriculeSupprimer);
                                        suppression_employe_donne(&ma_liste, matriculeSupprimer);
                                        printf("Employé avec le matricule %d supprimé de la liste.\n", matriculeSupprimer);
                                        break;

                                    case 5:
                                        // Suppression des employés d'un service

                                        printf("Service des employés à supprimer : ");
                                        scanf(" %c", &serviceSupprimer);
                                        supprimer_employes_service(&ma_liste, serviceSupprimer);
                                        printf("Employés du service %c supprimés de la liste.\n", serviceSupprimer);
                                        break;

                                    case 6:
                                        // Retour au Menu MAJ
                                        break;

                                    default:
                                        printf("Choix invalide. Veuillez choisir à nouveau.\n");
                                }

                            } while (choixSupprimer != 6);

                            break;

                        case 3:
                            do {
                                int matriculeModifier;
                                // Affichage du Menu Modification
                                printf("MENU MODIFICATION\n");
                                printf("1. Adresse\n");
                                printf("2. Téléphone\n");
                                printf("3. Retour au menu MAJ\n");
                                printf("Donner votre choix SVP : ");
                                scanf("%d", &choixModifier);

                                // Traiter choixModifier

                                switch (choixModifier) {
                                    case 1:
                                        // Appel de la fonction pour modifier les données
                                        printf("Matricule de l'employé à modifier : ");
                                        scanf("%d", &matriculeModifier);
                                        modifier_donnees_employe(&ma_liste, matriculeModifier, choixModifier);
                                        break;
                                    case 2:
                                        // Appel de la fonction pour modifier les données
                                        printf("Matricule de l'employé à modifier : ");
                                        scanf("%d", &matriculeModifier);
                                        modifier_donnees_employe(&ma_liste, matriculeModifier, choixModifier);
                                        break;

                                    case 3:
                                        // Retour au Menu MAJ
                                        break;

                                    default:
                                        printf("Choix invalide. Veuillez choisir à nouveau.\n");
                                }

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
                Afficher_Salaires_Nets(ma_liste);

                break;

            case 4:
                // Recherche, affichage et Tri
                do {
                    printf("\nMenu Recherche et affichage :\n");
                    printf("1- Contenu de la liste des employés\n");
                    printf("2- Recherche par matricule\n");
                    printf("3- Recherche par nom\n");
                    printf("4- Recherche par téléphone\n");
                    printf("5- Recherche année bissextile\n");
                    printf("6- Recherche date ancienne\n");
                    printf("7- Recherche retraite\n");
                    printf("8- Recherche par indicatif téléphone\n");
                    printf("9- Tri 1\n");
                    printf("10- Tri 2\n");
                    printf("11- Retour au menu général\n");
                    printf("Donner votre choix SVP : ");
                    scanf("%d", &choixMenuTri);

                    switch (choixMenuTri) {
                        case 1:
                            afficher_tous_employes(ma_liste);
                            break;
                        case 2:
                            recherche_par_matricule(ma_liste);
                            break;
                        case 3:
                            recherche_par_nom(ma_liste);
                            break;
                        case 4:
                            recherche_par_telephone(ma_liste);
                            break;
                        case 5:
                            recherche_embauche_annee_bissextile(ma_liste);
                            break;
                        case 6:
                            comparaison_date_embauche(ma_liste);
                            break;
                        case 7:
                            recherche_retraite_proche(ma_liste);
                            break;
                        case 8:
                            recherche_par_indicatif(ma_liste);
                            break;
                        case 9:
                            TRI1(ma_liste);
                            break;
                        case 10:
                            TRI2(&ma_liste);
                            break;
                            // ... (Ajouter d'autres cas pour les autres options du menu)
                        case 11:
                            printf("Retour au menu général.\n");
                            break;
                        default:
                            printf("Choix invalide. Veuillez réessayer.\n");
                    }

                } while (choixMenuTri != 11);

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
