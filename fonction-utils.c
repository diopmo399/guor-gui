#include "fonction-utils.h"



int taille_liste_emp(liste_emp LE) {
    int taille = 0;

    while (LE != NULL) {
        taille++;
        LE = LE->suiv;
    }

    return taille;
}

struct employe *recherche_emp(liste_emp LE, int num) {
    while (LE != NULL) {
        if (LE->mat == num) {
            // L'employé a été trouvé
            return LE;
        }
        LE = LE->suiv;
    }

    // L'employé n'a pas été trouvé
    return NULL;
}

void inserer_tete_emp(liste_emp *LE, int mat, const char *nom, const char *prenom, const char *adresse,
                      int jour, int mois, int annee, int telephone, char service, float salairebrut) {
    // Création d'un nouvel employé
    struct employe *nouvelEmploye = (struct employe *)malloc(sizeof(struct employe));
    if (nouvelEmploye == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire pour le nouvel employé.\n");
        exit(EXIT_FAILURE);
    }

    // Initialisation des données de l'employé
    nouvelEmploye->mat = mat;
    snprintf(nouvelEmploye->nom, sizeof(nouvelEmploye->nom), "%s", nom);
    snprintf(nouvelEmploye->prenom, sizeof(nouvelEmploye->prenom), "%s", prenom);
    snprintf(nouvelEmploye->adresse, sizeof(nouvelEmploye->adresse), "%s", adresse);
    nouvelEmploye->DE.jour = jour;
    nouvelEmploye->DE.mois = mois;
    nouvelEmploye->DE.annee = annee;
    nouvelEmploye->telephone = telephone;
    nouvelEmploye->service = service;
    nouvelEmploye->salairebrut = salairebrut;

    // Ajout du nouvel employé en tête de la liste
    nouvelEmploye->suiv = *LE;
    *LE = nouvelEmploye;
}


void insere_queue_emp(liste_emp *LE, int mat, const char *nom, const char *prenom, const char *adresse,
                      int jour, int mois, int annee, int telephone, char service, float salairebrut) {
    // Création d'un nouvel employé
    struct employe *nouvelEmploye = (struct employe *)malloc(sizeof(struct employe));
    if (nouvelEmploye == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire pour le nouvel employé.\n");
        exit(EXIT_FAILURE);
    }

    // Initialisation des données de l'employé
    nouvelEmploye->mat = mat;
    snprintf(nouvelEmploye->nom, sizeof(nouvelEmploye->nom), "%s", nom);
    snprintf(nouvelEmploye->prenom, sizeof(nouvelEmploye->prenom), "%s", prenom);
    snprintf(nouvelEmploye->adresse, sizeof(nouvelEmploye->adresse), "%s", adresse);
    nouvelEmploye->DE.jour = jour;
    nouvelEmploye->DE.mois = mois;
    nouvelEmploye->DE.annee = annee;
    nouvelEmploye->telephone = telephone;
    nouvelEmploye->service = service;
    nouvelEmploye->salairebrut = salairebrut;

    nouvelEmploye->suiv = NULL;  // Le nouvel employé sera le dernier de la liste

    // Si la liste est vide, le nouvel employé devient le premier
    if (*LE == NULL) {
        *LE = nouvelEmploye;
    } else {
        // Sinon, trouvez le dernier employé actuel et faites-le pointer vers le nouvel employé
        struct employe *dernierEmploye = *LE;
        while (dernierEmploye->suiv != NULL) {
            dernierEmploye = dernierEmploye->suiv;
        }
        dernierEmploye->suiv = nouvelEmploye;
    }
}

void insere_pos_emp(liste_emp *LE, int pos, int mat, const char *nom, const char *prenom, const char *adresse,
                    int jour, int mois, int annee, int telephone, char service, float salairebrut) {
    // Création d'un nouvel employé
    struct employe *nouvelEmploye = (struct employe *)malloc(sizeof(struct employe));
    if (nouvelEmploye == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire pour le nouvel employé.\n");
        exit(EXIT_FAILURE);
    }

    // Initialisation des données de l'employé
    nouvelEmploye->mat = mat;
    snprintf(nouvelEmploye->nom, sizeof(nouvelEmploye->nom), "%s", nom);
    snprintf(nouvelEmploye->prenom, sizeof(nouvelEmploye->prenom), "%s", prenom);
    snprintf(nouvelEmploye->adresse, sizeof(nouvelEmploye->adresse), "%s", adresse);
    nouvelEmploye->DE.jour = jour;
    nouvelEmploye->DE.mois = mois;
    nouvelEmploye->DE.annee = annee;
    nouvelEmploye->telephone = telephone;
    nouvelEmploye->service = service;
    nouvelEmploye->salairebrut = salairebrut;

    // Cas où la position est 1 ou la taille actuelle plus 1
    if (pos == 1 || pos == taille_liste_emp(*LE) + 1) {
        nouvelEmploye->suiv = *LE;
        *LE = nouvelEmploye;
    } else {
        // Trouver le précédent à la position spécifiée
        struct employe *precedent = *LE;
        for (int i = 1; i < pos - 1; ++i) {
            if (precedent == NULL) {
                fprintf(stderr, "Position invalide pour l'insertion.\n");
                exit(EXIT_FAILURE);
            }
            precedent = precedent->suiv;
        }

        // Insérer le nouvel employé après le précédent
        nouvelEmploye->suiv = precedent->suiv;
        precedent->suiv = nouvelEmploye;
    }
}

void supprimer_tete_emp(liste_emp *LE) {
    if (*LE != NULL) {
        struct employe *temp = *LE;
        *LE = (*LE)->suiv;
        free(temp);
    }
}

void supprimer_queue_emp(liste_emp *LE) {
    if (*LE != NULL) {
        // Cas où la liste a un seul élément
        if ((*LE)->suiv == NULL) {
            free(*LE);
            *LE = NULL;
            return;
        }

        struct employe *precedent = NULL;
        struct employe *courant = *LE;

        // Parcours de la liste jusqu'à la fin
        while (courant->suiv != NULL) {
            precedent = courant;
            courant = courant->suiv;
        }

        // Le précédent devient la nouvelle fin de la liste
        precedent->suiv = NULL;

        // Libération de la mémoire occupée par l'ancienne fin de la liste
        free(courant);
    }
}

void suppression_pos_emp(liste_emp *LE, int pos) {
    if (*LE == NULL) {
        fprintf(stderr, "La liste est vide.\n");
        return;
    }

    // Cas où la position est 1
    if (pos == 1) {
        struct employe *temp = *LE;
        *LE = (*LE)->suiv;
        free(temp);
        return;
    }

    // Trouver le précédent à la position spécifiée
    struct employe *precedent = *LE;
    for (int i = 1; i < pos - 1; ++i) {
        if (precedent == NULL || precedent->suiv == NULL) {
            fprintf(stderr, "Position invalide pour la suppression.\n");
            return;
        }
        precedent = precedent->suiv;
    }

    // Supprimer l'employé à la position spécifiée
    struct employe *temp = precedent->suiv;
    precedent->suiv = temp->suiv;
    free(temp);
}


void suppression_employe_donne(liste_emp *LE, int num) {
    if (*LE == NULL) {
        fprintf(stderr, "La liste est vide.\n");
        return;
    }

    // Cas où l'employé à supprimer est en tête de liste
    if ((*LE)->mat == num) {
        struct employe *temp = *LE;
        *LE = (*LE)->suiv;
        free(temp);
        return;
    }

    // Trouver le précédent de l'employé à supprimer
    struct employe *precedent = *LE;
    while (precedent->suiv != NULL && precedent->suiv->mat != num) {
        precedent = precedent->suiv;
    }

    // Vérifier si l'employé à supprimer a été trouvé
    if (precedent->suiv == NULL) {
        fprintf(stderr, "Aucun employé trouvé avec le matricule %d.\n", num);
        return;
    }

    // Supprimer l'employé
    struct employe *temp = precedent->suiv;
    precedent->suiv = temp->suiv;
    free(temp);
}


void afficher_info_employe(liste_emp LE, int num) {
    while (LE != NULL) {
        if (LE->mat == num) {
            printf("Informations de l'employé avec le matricule %d:\n", LE->mat);
            printf("Nom: %s\n", LE->nom);
            printf("Prenom: %s\n", LE->prenom);
            printf("Adresse: %s\n", LE->adresse);
            printf("Date d'embauche: %d/%d/%d\n", LE->DE.jour, LE->DE.mois, LE->DE.annee);
            printf("Téléphone: %d\n", LE->telephone);
            printf("Service: %c\n", LE->service);
            printf("Salaire brut: %.2f\n", LE->salairebrut);
            return; // On a trouvé l'employé, donc on sort de la fonction
        }
        LE = LE->suiv;
    }

    // Si on n'a pas trouvé l'employé avec le matricule donné
    printf("Aucun employé trouvé avec le matricule %d.\n", num);
}


// Fonction pour afficher les informations de tous les employés
void afficher_tous_employes(liste_emp LE) {
    while (LE != NULL) {
        printf("Matricule: %d\n", LE->mat);
        printf("Nom: %s\n", LE->nom);
        printf("Prenom: %s\n", LE->prenom);
        printf("Adresse: %s\n", LE->adresse);
        printf("Date d'embauche: %d/%d/%d\n", LE->DE.jour, LE->DE.mois, LE->DE.annee);
        printf("Téléphone: %d\n", LE->telephone);
        printf("Service: %c\n", LE->service);
        printf("Salaire brut: %.2f\n", LE->salairebrut);
        printf("\n");

        LE = LE->suiv;
    }
}

void CREATION(liste_emp *LE) {
    int mat;
    char nom[20];
    char prenom[20];
    char adresse[50];
    int jour, mois, annee;
    int telephone;
    char service;
    float salairebrut;
    int position;
    char choix;

    do {
        // Saisie des données de l'employé
        printf("Matricule : ");
        scanf("%d", &mat);

        // Vérifier si la matricule est unique
        if (!matricule_unique(*LE, mat)) {
            printf("La matricule existe déjà. Veuillez saisir une matricule unique.\n");
            continue;
        }

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
        insere_pos_emp(LE, position, mat, nom, prenom, adresse, jour, mois, annee, telephone, service, salairebrut);

        printf("Voulez-vous ajouter un autre employé ? (0/N) : ");
        scanf(" %c", &choix);

    } while (choix == '1' || choix == 'O' || choix == 'o');

    printf("Fin de la saisie des employés.\n");
}

bool matricule_unique(liste_emp LE, int mat) {
    while (LE != NULL) {
        if (LE->mat == mat) {
            // La matricule n'est pas unique
            return false;
        }
        LE = LE->suiv;
    }
    // La matricule est unique
    return true;
}

int obtenirMatiricule(liste_emp  *LE){
    int matricul;
    do {
        printf("Matricule : ");
        scanf("%d", &matricul);
        if (!matricule_unique(*LE, matricul)) {
            printf("La matricule existe déjà. Veuillez saisir une matricule unique.\n");
            continue;
        }
    } while (!matricule_unique(*LE, matricul));
    return matricul;
}

// Fonction pour supprimer les employés d'un service donné
void supprimer_employes_service(liste_emp *LE, char service) {
    if (*LE == NULL) {
        printf("La liste est vide. Aucun employé à supprimer.\n");
        return;
    }

    struct employe *courant = *LE;
    struct employe *precedent = NULL;

    while (courant != NULL) {
        if (courant->service == service) {
            // L'employé a le service spécifié, on le supprime
            if (precedent == NULL) {
                // L'employé est en tête de liste
                *LE = courant->suiv;
                free(courant);
                courant = *LE;
            } else {
                // L'employé n'est pas en tête de liste
                precedent->suiv = courant->suiv;
                free(courant);
                courant = precedent->suiv;
            }
        } else {
            // L'employé n'a pas le service spécifié, on passe à l'employé suivant
            precedent = courant;
            courant = courant->suiv;
        }
    }

    printf("Suppression des employés du service %c terminée.\n", service);
}


void modifier_donnees_employe(liste_emp *LE, int mat, int choix) {
    struct employe *employeAModifier = recherche_emp(*LE, mat);

    if (employeAModifier == NULL) {
        printf("Aucun employé trouvé avec le matricule %d.\n", mat);
        return;
    }

    switch (choix) {
        case 1:
            // Modification de l'adresse
            printf("Nouvelle adresse : ");
            scanf("%s", employeAModifier->adresse);
            break;

        case 2:
            // Modification du téléphone
            printf("Nouveau téléphone : ");
            scanf("%d", &employeAModifier->telephone);
            break;

        default:
            printf("Choix invalide. Aucune modification effectuée.\n");
            return;
    }

    printf("Données de l'employé avec le matricule %d modifiées avec succès.\n", mat);
}

// Fonction pour afficher la liste des employés
void afficher_liste(liste_emp LE) {
    printf("Liste des employés:\n");
    afficher_tous_employes(LE);

}

// Fonction calcul salaire

// Fonction pour calculer le montant CNSS d'un employé
float CNSS(struct employe emp) {
    if (emp.salairebrut < 200) {
        return 0;
    } else {
        return 0.1 * emp.salairebrut; // 10% du Salaire_Brut
    }
}

// Fonction pour calculer le montant des Impôts d'un employé
float Impots(struct employe emp) {
    float salaireImposable = emp.salairebrut - CNSS(emp);

    if (salaireImposable <= 200) {
        return salaireImposable * 0.05; // 5%
    } else if (salaireImposable <= 400) {
        return 200 * 0.05 + (salaireImposable - 200) * 0.1; // 5% sur les premiers 200, 10% sur le reste
    } else if (salaireImposable <= 600) {
        return 200 * 0.05 + 200 * 0.1 + (salaireImposable - 400) * 0.2; // 5% sur les premiers 200, 10% sur les suivants 200, 20% sur le reste
    } else if (salaireImposable <= 800) {
        return 200 * 0.05 + 200 * 0.1 + 200 * 0.2 + (salaireImposable - 600) * 0.3; // 5% sur les premiers 200, 10% sur les suivants 200, 20% sur les suivants 200, 30% sur le reste
    } else {
        return 200 * 0.05 + 200 * 0.1 + 200 * 0.2 + 200 * 0.3 + (salaireImposable - 800) * 0.4; // 5% sur les premiers 200, 10% sur les suivants 200, 20% sur les suivants 200, 30% sur les suivants 200, 40% sur le reste
    }
}

// Fonction pour calculer le Salaire_Net d'un employé
float Salaire_Net(struct employe emp) {
    return emp.salairebrut - CNSS(emp) - Impots(emp);
}

// Fonction pour calculer la somme des montants CNSS de tous les employés
float Somme_CNSS(liste_emp LE) {
    float sommeCNSS = 0;

    while (LE != NULL) {
        sommeCNSS += CNSS(*LE);
        LE = LE->suiv;
    }

    return sommeCNSS;
}

// Fonction pour calculer la somme des salaires bruts de tous les employés
float Somme_Salaires_Bruts(liste_emp LE) {
    float sommeSalairesBruts = 0;

    while (LE != NULL) {
        sommeSalairesBruts += LE->salairebrut;
        LE = LE->suiv;
    }

    return sommeSalairesBruts;
}

// Fonction pour afficher les salaires nets de tous les employés
void Afficher_Salaires_Nets(liste_emp LE) {
    printf("Salaires Nets de tous les employés :\n");
    while (LE != NULL) {
        printf("Matricule: %d, Salaire Net: %.2f\n", LE->mat, Salaire_Net(*LE));
        LE = LE->suiv;
    }
}

// Fonction pour rechercher un employé par matricule
void recherche_par_matricule(liste_emp LE) {
    int matricule;
    printf("Veuillez entrer le matricule de l'employé : ");
    scanf("%d", &matricule);

    struct employe* resultat = recherche_emp(LE, matricule);

    if (resultat != NULL) {
        printf("Employé trouvé avec le matricule %d :\n", matricule);
        printf("Nom : %s\n", resultat->nom);
        printf("Prenom : %s\n", resultat->prenom);
        // ... (Afficher d'autres informations de l'employé)
    } else {
        printf("Aucun employé trouvé avec le matricule %d.\n", matricule);
    }
}

// Fonction pour rechercher un employé par nom
void recherche_par_nom(liste_emp LE) {
    char nomRecherche[20];
    printf("Veuillez entrer le nom de l'employé : ");
    scanf("%s", nomRecherche);

    while (LE != NULL) {
        if (strcmp(LE->nom, nomRecherche) == 0) {
            printf("Employé trouvé avec le nom %s :\n", nomRecherche);
            printf("Matricule : %d\n", LE->mat);
            printf("Prenom : %s\n", LE->prenom);
            // ... (Afficher d'autres informations de l'employé)
        }
        LE = LE->suiv;
    }
}

// Fonction pour rechercher un employé par téléphone
void recherche_par_telephone(liste_emp LE) {
    int telephoneRecherche;
    printf("Veuillez entrer le numéro de téléphone de l'employé : ");
    scanf("%d", &telephoneRecherche);

    while (LE != NULL) {
        if (LE->telephone == telephoneRecherche) {
            printf("Employé trouvé avec le numéro de téléphone %d :\n", telephoneRecherche);
            printf("Matricule : %d\n", LE->mat);
            printf("Nom : %s\n", LE->nom);
            printf("Prenom : %s\n", LE->prenom);
            // ... (Afficher d'autres informations de l'employé)
        }
        LE = LE->suiv;
    }
}

// Fonction pour rechercher les employés dont l'année d'embauche est bissextile
void recherche_annee_bissextile(liste_emp LE) {
    int anneeRecherche;
    printf("Veuillez entrer l'année de recherche : ");
    scanf("%d", &anneeRecherche);

    while (LE != NULL) {
        if (LE->DE.annee == anneeRecherche && (LE->DE.annee % 4 == 0 && LE->DE.annee % 100 != 0 || LE->DE.annee % 400 == 0)) {
            printf("Employé trouvé avec une date d'embauche bissextile :\n");
            printf("Matricule : %d\n", LE->mat);
            printf("Nom : %s\n", LE->nom);
            printf("Prenom : %s\n", LE->prenom);
            // ... (Afficher d'autres informations de l'employé)
        }
        LE = LE->suiv;
    }
}

// Fonction pour chercher et afficher si un employé donné est embauché dans une année bissextile ou non
void recherche_embauche_annee_bissextile(liste_emp LE) {
    int matricule;
    printf("Veuillez entrer le matricule de l'employé : ");
    scanf("%d", &matricule);
    struct employe* employeRecherche = recherche_emp(LE, matricule);

    if (employeRecherche != NULL) {
        if ((employeRecherche->DE.annee % 4 == 0 && employeRecherche->DE.annee % 100 != 0) || (employeRecherche->DE.annee % 400 == 0)) {
            printf("L'employé avec le matricule %d a été embauché dans une année bissextile.\n", matricule);
        } else {
            printf("L'employé avec le matricule %d n'a pas été embauché dans une année bissextile.\n", matricule);
        }
    } else {
        printf("Aucun employé trouvé avec le matricule %d.\n", matricule);
    }
}

// Fonction pour rechercher l'employé avec la date d'embauche la plus ancienne

void comparaison_date_embauche(liste_emp LE) {
    int mat1, mat2;
    printf("Veuillez entrer le matricule de l'employé 1 : ");
    scanf("%d", &mat1);
    printf("Veuillez entrer le matricule de l'employé 2 : ");
    scanf("%d", &mat2);
    struct employe* employe1 = recherche_emp(LE, mat1);
    struct employe* employe2 = recherche_emp(LE, mat2);

    if (employe1 != NULL && employe2 != NULL) {
        if (employe1->DE.annee < employe2->DE.annee ||
            (employe1->DE.annee == employe2->DE.annee && employe1->DE.mois < employe2->DE.mois) ||
            (employe1->DE.annee == employe2->DE.annee && employe1->DE.mois == employe2->DE.mois && employe1->DE.jour < employe2->DE.jour)) {
            printf("La date d'embauche de l'employé avec le matricule %d est plus ancienne que celle de l'employé avec le matricule %d.\n", mat1, mat2);
        } else {
            printf("La date d'embauche de l'employé avec le matricule %d n'est pas plus ancienne que celle de l'employé avec le matricule %d.\n", mat1, mat2);
        }
    } else {
        printf("Au moins l'un des employés n'a pas été trouvé.\n");
    }
}

void parcourirListe(liste_emp liste) {
    struct employe *courant = liste;

    while (courant != NULL) {
        // Traitement ou affichage des données de l'employé actuel
        printf("Matricule: %d, Nom: %s, Prenom: %s\n", courant->mat, courant->nom, courant->prenom);

        // Passer à l'employé suivant dans la liste
        courant = courant->suiv;
    }
}


// Fonction pour modifier l'adresse d'un employé
void modifier_adresse_employe(liste_emp *LE, int mat) {
    struct employe *employeAModifier = recherche_emp(*LE, mat);

    if (employeAModifier == NULL) {
        printf("Aucun employé trouvé avec le matricule %d.\n", mat);
        return;
    }

    printf("Nouvelle adresse : ");
    scanf(" %[^\n]", employeAModifier->adresse);

    printf("Adresse de l'employé avec le matricule %d modifiée avec succès.\n", mat);
}


// Fonction pour afficher le contenu de la liste des employés
void afficher_contenu_liste(liste_emp LE) {
    printf("Contenu de la liste des employés:\n");
    afficher_tous_employes(LE);
}

// Fonction pour rechercher l'employé avec la date d'embauche la plus ancienne
void recherche_date_ancienne(liste_emp LE) {
    struct employe* employeAncien = NULL;

    while (LE != NULL) {
        if (employeAncien == NULL || (LE->DE.annee < employeAncien->DE.annee) ||
            (LE->DE.annee == employeAncien->DE.annee && LE->DE.mois < employeAncien->DE.mois) ||
            (LE->DE.annee == employeAncien->DE.annee && LE->DE.mois == employeAncien->DE.mois && LE->DE.jour < employeAncien->DE.jour)) {
            employeAncien = LE;
        }
        LE = LE->suiv;
    }

    if (employeAncien != NULL) {
        printf("Employé avec la date d'embauche la plus ancienne :\n");
        printf("Matricule : %d\n", employeAncien->mat);
        printf("Nom : %s\n", employeAncien->nom);
        printf("Prenom : %s\n", employeAncien->prenom);
        // ... (Afficher d'autres informations de l'employé)
    } else {
        printf("Aucun employé trouvé.\n");
    }
}

// Fonction pour convertir struct date en struct tm
struct tm convertir_date_en_tm(struct date date) {
    struct tm tm_date = {0}; // Initialiser à zéro pour éviter des valeurs indéfinies

    // Assurer que les valeurs sont valides

    tm_date.tm_year = date.annee - 1900; // Année depuis 1900
    tm_date.tm_mon = date.mois - 1;      // Mois de 0 à 11
    tm_date.tm_mday = date.jour;         // Jour du mois


    return tm_date;
}


// Fonction pour calculer la date de retraite potentielle pour un employé
struct tm dateRetraitePotentielle(struct tm *dateEmbauche) {
    struct tm dateRetraite = *dateEmbauche;
    dateRetraite.tm_year += 60; // Ajoute 60 ans pour estimer la date de retraite
    mktime(&dateRetraite); // Normalise la date
    return dateRetraite;
}

// Fonction pour chercher et afficher les employés dont il reste 60 jours pour la retraite
void recherche_retraite_proche(liste_emp LE) {
    // Obtenez la date actuelle
    time_t t = time(NULL);
    struct tm *today = localtime(&t);

    while (LE != NULL) {
        struct tm dateEnTm = convertir_date_en_tm(LE->DE);
        // Calculez la date de retraite potentielle pour cet employé
        struct tm dateRetraite = dateRetraitePotentielle(&dateEnTm);

        // Comparez la date de retraite potentielle avec la date actuelle
        if (difftime(mktime(&dateRetraite), t) <= 60 * 24 * 60 * 60) {
            printf("L'employé avec le matricule %d a 60 jours ou moins avant la retraite.\n", LE->mat);
            printf("Nom : %s\n", LE->nom);
            printf("Prenom : %s\n", LE->prenom);
            printf("Matricule : %d\n", LE->mat);
            // Affichez d'autres informations de l'employé selon vos besoins
        }

        LE = LE->suiv;
    }
}

// Fonction pour afficher les employés dont les numéros commencent par un indicatif
void recherche_par_indicatif(liste_emp LE) {
    int indicatif;
    printf("Veuillez entrer l'indicatif : ");
    scanf("%d", &indicatif);

    int aucunNumeroTrouve = 1; // Variable pour vérifier si aucun numéro n'est trouvé

    while (LE != NULL) {
        // Extraire les trois premiers chiffres du numéro de téléphone (indicatif)
        // Cette approche est basée sur l'hypothèse que les numéros de téléphone ont la structure suivante : IND + XXXXXXX,
        int numeroIndicatif = LE->telephone / 1000000;

        // Vérifier si l'indicatif correspond à celui recherché
        if (numeroIndicatif == indicatif) {
            aucunNumeroTrouve = 0; // Au moins un numéro trouvé
            printf("Employé trouvé avec le numéro de téléphone commençant par l'indicatif %d:\n", indicatif);
            printf("Nom : %s\n", LE->nom);
            printf("Prenom : %s\n", LE->prenom);
            printf("Matricule : %d\n", LE->mat);
            printf("Numéro de téléphone : %d\n", LE->telephone);
            // Affichez d'autres informations de l'employé selon vos besoins
            printf("\n");
        }

        LE = LE->suiv;
    }

    // Si aucun numéro n'est trouvé, affichez le message approprié
    if (aucunNumeroTrouve) {
        printf("Aucun numéro n'a été trouvé avec l'indicatif %d.\n", indicatif);
    }
}

void echanger_employes(struct employe *a, struct employe *b) {
    // Échange des valeurs des employés a et b
    struct employe temp = *a;
    *a = *b;
    *b = temp;
}

void TRI1(liste_emp LE) {
    liste_emp head = LE;  // Sauvegarde du pointeur initial de la liste

    int taille = taille_liste_emp(LE);

    for (int i = 0; i < taille - 1; i++) {
        for (int j = 0; j < taille - i - 1; j++) {
            // Comparaison des salaires bruts pour un tri décroissant
            if (LE->salairebrut < LE->suiv->salairebrut) {
                // Échange des employés
                echanger_employes(LE, LE->suiv);
            }

            LE = LE->suiv;
        }

        // Réinitialiser le pointeur à la tête de la liste pour chaque passage
        LE = head;
    }
}

void TRI2(liste_emp *LE) {
    if (*LE == NULL || (*LE)->suiv == NULL) {
        // La liste est vide ou a un seul élément, elle est déjà triée
        return;
    }

    int taille = taille_liste_emp(*LE);

    for (int i = 0; i < taille - 1; i++) {
        struct employe **courant = LE;
        struct employe **suivant = &((*LE)->suiv);

        for (int j = 0; j < taille - i - 1; j++) {
            // Comparaison des salaires bruts pour un tri décroissant
            if ((*courant)->salairebrut < (*suivant)->salairebrut) {
                // Échange des pointeurs
                struct employe *temp = *courant;
                *courant = *suivant;
                *suivant = temp;
            }

            // Déplacer les pointeurs vers la cellule suivante
            courant = suivant;
            suivant = &((*suivant)->suiv);
        }
    }
}

#include "fonction-utils.h"



int taille_liste_emp(liste_emp LE) {
    int taille = 0;

    while (LE != NULL) {
        taille++;
        LE = LE->suiv;
    }

    return taille;
}

struct employe *recherche_emp(liste_emp LE, int num) {
    while (LE != NULL) {
        if (LE->mat == num) {
            // L'employé a été trouvé
            return LE;
        }
        LE = LE->suiv;
    }

    // L'employé n'a pas été trouvé
    return NULL;
}

void inserer_tete_emp(liste_emp *LE, int mat, const char *nom, const char *prenom, const char *adresse,
                      int jour, int mois, int annee, int telephone, char service, float salairebrut) {
    // Création d'un nouvel employé
    struct employe *nouvelEmploye = (struct employe *)malloc(sizeof(struct employe));
    if (nouvelEmploye == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire pour le nouvel employé.\n");
        exit(EXIT_FAILURE);
    }

    // Initialisation des données de l'employé
    nouvelEmploye->mat = mat;
    snprintf(nouvelEmploye->nom, sizeof(nouvelEmploye->nom), "%s", nom);
    snprintf(nouvelEmploye->prenom, sizeof(nouvelEmploye->prenom), "%s", prenom);
    snprintf(nouvelEmploye->adresse, sizeof(nouvelEmploye->adresse), "%s", adresse);
    nouvelEmploye->DE.jour = jour;
    nouvelEmploye->DE.mois = mois;
    nouvelEmploye->DE.annee = annee;
    nouvelEmploye->telephone = telephone;
    nouvelEmploye->service = service;
    nouvelEmploye->salairebrut = salairebrut;

    // Ajout du nouvel employé en tête de la liste
    nouvelEmploye->suiv = *LE;
    *LE = nouvelEmploye;
}


void insere_queue_emp(liste_emp *LE, int mat, const char *nom, const char *prenom, const char *adresse,
                      int jour, int mois, int annee, int telephone, char service, float salairebrut) {
    // Création d'un nouvel employé
    struct employe *nouvelEmploye = (struct employe *)malloc(sizeof(struct employe));
    if (nouvelEmploye == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire pour le nouvel employé.\n");
        exit(EXIT_FAILURE);
    }

    // Initialisation des données de l'employé
    nouvelEmploye->mat = mat;
    snprintf(nouvelEmploye->nom, sizeof(nouvelEmploye->nom), "%s", nom);
    snprintf(nouvelEmploye->prenom, sizeof(nouvelEmploye->prenom), "%s", prenom);
    snprintf(nouvelEmploye->adresse, sizeof(nouvelEmploye->adresse), "%s", adresse);
    nouvelEmploye->DE.jour = jour;
    nouvelEmploye->DE.mois = mois;
    nouvelEmploye->DE.annee = annee;
    nouvelEmploye->telephone = telephone;
    nouvelEmploye->service = service;
    nouvelEmploye->salairebrut = salairebrut;

    nouvelEmploye->suiv = NULL;  // Le nouvel employé sera le dernier de la liste

    // Si la liste est vide, le nouvel employé devient le premier
    if (*LE == NULL) {
        *LE = nouvelEmploye;
    } else {
        // Sinon, trouvez le dernier employé actuel et faites-le pointer vers le nouvel employé
        struct employe *dernierEmploye = *LE;
        while (dernierEmploye->suiv != NULL) {
            dernierEmploye = dernierEmploye->suiv;
        }
        dernierEmploye->suiv = nouvelEmploye;
    }
}

void insere_pos_emp(liste_emp *LE, int pos, int mat, const char *nom, const char *prenom, const char *adresse,
                    int jour, int mois, int annee, int telephone, char service, float salairebrut) {
    // Création d'un nouvel employé
    struct employe *nouvelEmploye = (struct employe *)malloc(sizeof(struct employe));
    if (nouvelEmploye == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire pour le nouvel employé.\n");
        exit(EXIT_FAILURE);
    }

    // Initialisation des données de l'employé
    nouvelEmploye->mat = mat;
    snprintf(nouvelEmploye->nom, sizeof(nouvelEmploye->nom), "%s", nom);
    snprintf(nouvelEmploye->prenom, sizeof(nouvelEmploye->prenom), "%s", prenom);
    snprintf(nouvelEmploye->adresse, sizeof(nouvelEmploye->adresse), "%s", adresse);
    nouvelEmploye->DE.jour = jour;
    nouvelEmploye->DE.mois = mois;
    nouvelEmploye->DE.annee = annee;
    nouvelEmploye->telephone = telephone;
    nouvelEmploye->service = service;
    nouvelEmploye->salairebrut = salairebrut;

    // Cas où la position est 1 ou la taille actuelle plus 1
    if (pos == 1 || pos == taille_liste_emp(*LE) + 1) {
        nouvelEmploye->suiv = *LE;
        *LE = nouvelEmploye;
    } else {
        // Trouver le précédent à la position spécifiée
        struct employe *precedent = *LE;
        for (int i = 1; i < pos - 1; ++i) {
            if (precedent == NULL) {
                fprintf(stderr, "Position invalide pour l'insertion.\n");
                exit(EXIT_FAILURE);
            }
            precedent = precedent->suiv;
        }

        // Insérer le nouvel employé après le précédent
        nouvelEmploye->suiv = precedent->suiv;
        precedent->suiv = nouvelEmploye;
    }
}

void supprimer_tete_emp(liste_emp *LE) {
    if (*LE != NULL) {
        struct employe *temp = *LE;
        *LE = (*LE)->suiv;
        free(temp);
    }
}

void supprimer_queue_emp(liste_emp *LE) {
    if (*LE != NULL) {
        // Cas où la liste a un seul élément
        if ((*LE)->suiv == NULL) {
            free(*LE);
            *LE = NULL;
            return;
        }

        struct employe *precedent = NULL;
        struct employe *courant = *LE;

        // Parcours de la liste jusqu'à la fin
        while (courant->suiv != NULL) {
            precedent = courant;
            courant = courant->suiv;
        }

        // Le précédent devient la nouvelle fin de la liste
        precedent->suiv = NULL;

        // Libération de la mémoire occupée par l'ancienne fin de la liste
        free(courant);
    }
}

void suppression_pos_emp(liste_emp *LE, int pos) {
    if (*LE == NULL) {
        fprintf(stderr, "La liste est vide.\n");
        return;
    }

    // Cas où la position est 1
    if (pos == 1) {
        struct employe *temp = *LE;
        *LE = (*LE)->suiv;
        free(temp);
        return;
    }

    // Trouver le précédent à la position spécifiée
    struct employe *precedent = *LE;
    for (int i = 1; i < pos - 1; ++i) {
        if (precedent == NULL || precedent->suiv == NULL) {
            fprintf(stderr, "Position invalide pour la suppression.\n");
            return;
        }
        precedent = precedent->suiv;
    }

    // Supprimer l'employé à la position spécifiée
    struct employe *temp = precedent->suiv;
    precedent->suiv = temp->suiv;
    free(temp);
}


void suppression_employe_donne(liste_emp *LE, int num) {
    if (*LE == NULL) {
        fprintf(stderr, "La liste est vide.\n");
        return;
    }

    // Cas où l'employé à supprimer est en tête de liste
    if ((*LE)->mat == num) {
        struct employe *temp = *LE;
        *LE = (*LE)->suiv;
        free(temp);
        return;
    }

    // Trouver le précédent de l'employé à supprimer
    struct employe *precedent = *LE;
    while (precedent->suiv != NULL && precedent->suiv->mat != num) {
        precedent = precedent->suiv;
    }

    // Vérifier si l'employé à supprimer a été trouvé
    if (precedent->suiv == NULL) {
        fprintf(stderr, "Aucun employé trouvé avec le matricule %d.\n", num);
        return;
    }

    // Supprimer l'employé
    struct employe *temp = precedent->suiv;
    precedent->suiv = temp->suiv;
    free(temp);
}


void afficher_info_employe(liste_emp LE, int num) {
    while (LE != NULL) {
        if (LE->mat == num) {
            printf("Informations de l'employé avec le matricule %d:\n", LE->mat);
            printf("Nom: %s\n", LE->nom);
            printf("Prenom: %s\n", LE->prenom);
            printf("Adresse: %s\n", LE->adresse);
            printf("Date d'embauche: %d/%d/%d\n", LE->DE.jour, LE->DE.mois, LE->DE.annee);
            printf("Téléphone: %d\n", LE->telephone);
            printf("Service: %c\n", LE->service);
            printf("Salaire brut: %.2f\n", LE->salairebrut);
            return; // On a trouvé l'employé, donc on sort de la fonction
        }
        LE = LE->suiv;
    }

    // Si on n'a pas trouvé l'employé avec le matricule donné
    printf("Aucun employé trouvé avec le matricule %d.\n", num);
}


// Fonction pour afficher les informations de tous les employés
void afficher_tous_employes(liste_emp LE) {
    while (LE != NULL) {
        printf("Matricule: %d\n", LE->mat);
        printf("Nom: %s\n", LE->nom);
        printf("Prenom: %s\n", LE->prenom);
        printf("Adresse: %s\n", LE->adresse);
        printf("Date d'embauche: %d/%d/%d\n", LE->DE.jour, LE->DE.mois, LE->DE.annee);
        printf("Téléphone: %d\n", LE->telephone);
        printf("Service: %c\n", LE->service);
        printf("Salaire brut: %.2f\n", LE->salairebrut);
        printf("\n");

        LE = LE->suiv;
    }
}

void CREATION(liste_emp *LE) {
    int mat;
    char nom[20];
    char prenom[20];
    char adresse[50];
    int jour, mois, annee;
    int telephone;
    char service;
    float salairebrut;
    int position;
    char choix;

    do {
        // Saisie des données de l'employé
        printf("Matricule : ");
        scanf("%d", &mat);

        // Vérifier si la matricule est unique
        if (!matricule_unique(*LE, mat)) {
            printf("La matricule existe déjà. Veuillez saisir une matricule unique.\n");
            continue;
        }

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
        insere_pos_emp(LE, position, mat, nom, prenom, adresse, jour, mois, annee, telephone, service, salairebrut);

        printf("Voulez-vous ajouter un autre employé ? (0/N) : ");
        scanf(" %c", &choix);

    } while (choix == '1' || choix == 'O' || choix == 'o');

    printf("Fin de la saisie des employés.\n");
}

bool matricule_unique(liste_emp LE, int mat) {
    while (LE != NULL) {
        if (LE->mat == mat) {
            // La matricule n'est pas unique
            return false;
        }
        LE = LE->suiv;
    }
    // La matricule est unique
    return true;
}

int obtenirMatiricule(liste_emp  *LE){
    int matricul;
    do {
        printf("Matricule : ");
        scanf("%d", &matricul);
        if (!matricule_unique(*LE, matricul)) {
            printf("La matricule existe déjà. Veuillez saisir une matricule unique.\n");
            continue;
        }
    } while (!matricule_unique(*LE, matricul));
    return matricul;
}

// Fonction pour supprimer les employés d'un service donné
void supprimer_employes_service(liste_emp *LE, char service) {
    if (*LE == NULL) {
        printf("La liste est vide. Aucun employé à supprimer.\n");
        return;
    }

    struct employe *courant = *LE;
    struct employe *precedent = NULL;

    while (courant != NULL) {
        if (courant->service == service) {
            // L'employé a le service spécifié, on le supprime
            if (precedent == NULL) {
                // L'employé est en tête de liste
                *LE = courant->suiv;
                free(courant);
                courant = *LE;
            } else {
                // L'employé n'est pas en tête de liste
                precedent->suiv = courant->suiv;
                free(courant);
                courant = precedent->suiv;
            }
        } else {
            // L'employé n'a pas le service spécifié, on passe à l'employé suivant
            precedent = courant;
            courant = courant->suiv;
        }
    }

    printf("Suppression des employés du service %c terminée.\n", service);
}


void modifier_donnees_employe(liste_emp *LE, int mat, int choix) {
    struct employe *employeAModifier = recherche_emp(*LE, mat);

    if (employeAModifier == NULL) {
        printf("Aucun employé trouvé avec le matricule %d.\n", mat);
        return;
    }

    switch (choix) {
        case 1:
            // Modification de l'adresse
            printf("Nouvelle adresse : ");
            scanf("%s", employeAModifier->adresse);
            break;

        case 2:
            // Modification du téléphone
            printf("Nouveau téléphone : ");
            scanf("%d", &employeAModifier->telephone);
            break;

        default:
            printf("Choix invalide. Aucune modification effectuée.\n");
            return;
    }

    printf("Données de l'employé avec le matricule %d modifiées avec succès.\n", mat);
}

// Fonction pour afficher la liste des employés
void afficher_liste(liste_emp LE) {
    printf("Liste des employés:\n");
    afficher_tous_employes(LE);

}

// Fonction calcul salaire

// Fonction pour calculer le montant CNSS d'un employé
float CNSS(struct employe emp) {
    if (emp.salairebrut < 200) {
        return 0;
    } else {
        return 0.1 * emp.salairebrut; // 10% du Salaire_Brut
    }
}

// Fonction pour calculer le montant des Impôts d'un employé
float Impots(struct employe emp) {
    float salaireImposable = emp.salairebrut - CNSS(emp);

    if (salaireImposable <= 200) {
        return salaireImposable * 0.05; // 5%
    } else if (salaireImposable <= 400) {
        return 200 * 0.05 + (salaireImposable - 200) * 0.1; // 5% sur les premiers 200, 10% sur le reste
    } else if (salaireImposable <= 600) {
        return 200 * 0.05 + 200 * 0.1 + (salaireImposable - 400) * 0.2; // 5% sur les premiers 200, 10% sur les suivants 200, 20% sur le reste
    } else if (salaireImposable <= 800) {
        return 200 * 0.05 + 200 * 0.1 + 200 * 0.2 + (salaireImposable - 600) * 0.3; // 5% sur les premiers 200, 10% sur les suivants 200, 20% sur les suivants 200, 30% sur le reste
    } else {
        return 200 * 0.05 + 200 * 0.1 + 200 * 0.2 + 200 * 0.3 + (salaireImposable - 800) * 0.4; // 5% sur les premiers 200, 10% sur les suivants 200, 20% sur les suivants 200, 30% sur les suivants 200, 40% sur le reste
    }
}

// Fonction pour calculer le Salaire_Net d'un employé
float Salaire_Net(struct employe emp) {
    return emp.salairebrut - CNSS(emp) - Impots(emp);
}

// Fonction pour calculer la somme des montants CNSS de tous les employés
float Somme_CNSS(liste_emp LE) {
    float sommeCNSS = 0;

    while (LE != NULL) {
        sommeCNSS += CNSS(*LE);
        LE = LE->suiv;
    }

    return sommeCNSS;
}

// Fonction pour calculer la somme des salaires bruts de tous les employés
float Somme_Salaires_Bruts(liste_emp LE) {
    float sommeSalairesBruts = 0;

    while (LE != NULL) {
        sommeSalairesBruts += LE->salairebrut;
        LE = LE->suiv;
    }

    return sommeSalairesBruts;
}

// Fonction pour afficher les salaires nets de tous les employés
void Afficher_Salaires_Nets(liste_emp LE) {
    printf("Salaires Nets de tous les employés :\n");
    while (LE != NULL) {
        printf("Matricule: %d, Salaire Net: %.2f\n", LE->mat, Salaire_Net(*LE));
        LE = LE->suiv;
    }
}

// Fonction pour rechercher un employé par matricule
void recherche_par_matricule(liste_emp LE) {
    int matricule;
    printf("Veuillez entrer le matricule de l'employé : ");
    scanf("%d", &matricule);

    struct employe* resultat = recherche_emp(LE, matricule);

    if (resultat != NULL) {
        printf("Employé trouvé avec le matricule %d :\n", matricule);
        printf("Nom : %s\n", resultat->nom);
        printf("Prenom : %s\n", resultat->prenom);
        // ... (Afficher d'autres informations de l'employé)
    } else {
        printf("Aucun employé trouvé avec le matricule %d.\n", matricule);
    }
}

// Fonction pour rechercher un employé par nom
void recherche_par_nom(liste_emp LE) {
    char nomRecherche[20];
    printf("Veuillez entrer le nom de l'employé : ");
    scanf("%s", nomRecherche);

    while (LE != NULL) {
        if (strcmp(LE->nom, nomRecherche) == 0) {
            printf("Employé trouvé avec le nom %s :\n", nomRecherche);
            printf("Matricule : %d\n", LE->mat);
            printf("Prenom : %s\n", LE->prenom);
            // ... (Afficher d'autres informations de l'employé)
        }
        LE = LE->suiv;
    }
}

// Fonction pour rechercher un employé par téléphone
void recherche_par_telephone(liste_emp LE) {
    int telephoneRecherche;
    printf("Veuillez entrer le numéro de téléphone de l'employé : ");
    scanf("%d", &telephoneRecherche);

    while (LE != NULL) {
        if (LE->telephone == telephoneRecherche) {
            printf("Employé trouvé avec le numéro de téléphone %d :\n", telephoneRecherche);
            printf("Matricule : %d\n", LE->mat);
            printf("Nom : %s\n", LE->nom);
            printf("Prenom : %s\n", LE->prenom);
            // ... (Afficher d'autres informations de l'employé)
        }
        LE = LE->suiv;
    }
}

// Fonction pour rechercher les employés dont l'année d'embauche est bissextile
void recherche_annee_bissextile(liste_emp LE) {
    int anneeRecherche;
    printf("Veuillez entrer l'année de recherche : ");
    scanf("%d", &anneeRecherche);

    while (LE != NULL) {
        if (LE->DE.annee == anneeRecherche && (LE->DE.annee % 4 == 0 && LE->DE.annee % 100 != 0 || LE->DE.annee % 400 == 0)) {
            printf("Employé trouvé avec une date d'embauche bissextile :\n");
            printf("Matricule : %d\n", LE->mat);
            printf("Nom : %s\n", LE->nom);
            printf("Prenom : %s\n", LE->prenom);
            // ... (Afficher d'autres informations de l'employé)
        }
        LE = LE->suiv;
    }
}

// Fonction pour chercher et afficher si un employé donné est embauché dans une année bissextile ou non
void recherche_embauche_annee_bissextile(liste_emp LE) {
    int matricule;
    printf("Veuillez entrer le matricule de l'employé : ");
    scanf("%d", &matricule);
    struct employe* employeRecherche = recherche_emp(LE, matricule);

    if (employeRecherche != NULL) {
        if ((employeRecherche->DE.annee % 4 == 0 && employeRecherche->DE.annee % 100 != 0) || (employeRecherche->DE.annee % 400 == 0)) {
            printf("L'employé avec le matricule %d a été embauché dans une année bissextile.\n", matricule);
        } else {
            printf("L'employé avec le matricule %d n'a pas été embauché dans une année bissextile.\n", matricule);
        }
    } else {
        printf("Aucun employé trouvé avec le matricule %d.\n", matricule);
    }
}

// Fonction pour rechercher l'employé avec la date d'embauche la plus ancienne

void comparaison_date_embauche(liste_emp LE) {
    int mat1, mat2;
    printf("Veuillez entrer le matricule de l'employé 1 : ");
    scanf("%d", &mat1);
    printf("Veuillez entrer le matricule de l'employé 2 : ");
    scanf("%d", &mat2);
    struct employe* employe1 = recherche_emp(LE, mat1);
    struct employe* employe2 = recherche_emp(LE, mat2);

    if (employe1 != NULL && employe2 != NULL) {
        if (employe1->DE.annee < employe2->DE.annee ||
            (employe1->DE.annee == employe2->DE.annee && employe1->DE.mois < employe2->DE.mois) ||
            (employe1->DE.annee == employe2->DE.annee && employe1->DE.mois == employe2->DE.mois && employe1->DE.jour < employe2->DE.jour)) {
            printf("La date d'embauche de l'employé avec le matricule %d est plus ancienne que celle de l'employé avec le matricule %d.\n", mat1, mat2);
        } else {
            printf("La date d'embauche de l'employé avec le matricule %d n'est pas plus ancienne que celle de l'employé avec le matricule %d.\n", mat1, mat2);
        }
    } else {
        printf("Au moins l'un des employés n'a pas été trouvé.\n");
    }
}

void parcourirListe(liste_emp liste) {
    struct employe *courant = liste;

    while (courant != NULL) {
        // Traitement ou affichage des données de l'employé actuel
        printf("Matricule: %d, Nom: %s, Prenom: %s\n", courant->mat, courant->nom, courant->prenom);

        // Passer à l'employé suivant dans la liste
        courant = courant->suiv;
    }
}


// Fonction pour modifier l'adresse d'un employé
void modifier_adresse_employe(liste_emp *LE, int mat) {
    struct employe *employeAModifier = recherche_emp(*LE, mat);

    if (employeAModifier == NULL) {
        printf("Aucun employé trouvé avec le matricule %d.\n", mat);
        return;
    }

    printf("Nouvelle adresse : ");
    scanf(" %[^\n]", employeAModifier->adresse);

    printf("Adresse de l'employé avec le matricule %d modifiée avec succès.\n", mat);
}


// Fonction pour afficher le contenu de la liste des employés
void afficher_contenu_liste(liste_emp LE) {
    printf("Contenu de la liste des employés:\n");
    afficher_tous_employes(LE);
}

// Fonction pour rechercher l'employé avec la date d'embauche la plus ancienne
void recherche_date_ancienne(liste_emp LE) {
    struct employe* employeAncien = NULL;

    while (LE != NULL) {
        if (employeAncien == NULL || (LE->DE.annee < employeAncien->DE.annee) ||
            (LE->DE.annee == employeAncien->DE.annee && LE->DE.mois < employeAncien->DE.mois) ||
            (LE->DE.annee == employeAncien->DE.annee && LE->DE.mois == employeAncien->DE.mois && LE->DE.jour < employeAncien->DE.jour)) {
            employeAncien = LE;
        }
        LE = LE->suiv;
    }

    if (employeAncien != NULL) {
        printf("Employé avec la date d'embauche la plus ancienne :\n");
        printf("Matricule : %d\n", employeAncien->mat);
        printf("Nom : %s\n", employeAncien->nom);
        printf("Prenom : %s\n", employeAncien->prenom);
        // ... (Afficher d'autres informations de l'employé)
    } else {
        printf("Aucun employé trouvé.\n");
    }
}

// Fonction pour convertir struct date en struct tm
struct tm convertir_date_en_tm(struct date date) {
    struct tm tm_date = {0}; // Initialiser à zéro pour éviter des valeurs indéfinies

    // Assurer que les valeurs sont valides

    tm_date.tm_year = date.annee - 1900; // Année depuis 1900
    tm_date.tm_mon = date.mois - 1;      // Mois de 0 à 11
    tm_date.tm_mday = date.jour;         // Jour du mois


    return tm_date;
}


// Fonction pour calculer la date de retraite potentielle pour un employé
struct tm dateRetraitePotentielle(struct tm *dateEmbauche) {
    struct tm dateRetraite = *dateEmbauche;
    dateRetraite.tm_year += 60; // Ajoute 60 ans pour estimer la date de retraite
    mktime(&dateRetraite); // Normalise la date
    return dateRetraite;
}

// Fonction pour chercher et afficher les employés dont il reste 60 jours pour la retraite
void recherche_retraite_proche(liste_emp LE) {
    // Obtenez la date actuelle
    time_t t = time(NULL);
    struct tm *today = localtime(&t);

    while (LE != NULL) {
        struct tm dateEnTm = convertir_date_en_tm(LE->DE);
        // Calculez la date de retraite potentielle pour cet employé
        struct tm dateRetraite = dateRetraitePotentielle(&dateEnTm);

        // Comparez la date de retraite potentielle avec la date actuelle
        if (difftime(mktime(&dateRetraite), t) <= 60 * 24 * 60 * 60) {
            printf("L'employé avec le matricule %d a 60 jours ou moins avant la retraite.\n", LE->mat);
            printf("Nom : %s\n", LE->nom);
            printf("Prenom : %s\n", LE->prenom);
            printf("Matricule : %d\n", LE->mat);
            // Affichez d'autres informations de l'employé selon vos besoins
        }

        LE = LE->suiv;
    }
}

// Fonction pour afficher les employés dont les numéros commencent par un indicatif
void recherche_par_indicatif(liste_emp LE) {
    int indicatif;
    printf("Veuillez entrer l'indicatif : ");
    scanf("%d", &indicatif);

    int aucunNumeroTrouve = 1; // Variable pour vérifier si aucun numéro n'est trouvé

    while (LE != NULL) {
        // Extraire les trois premiers chiffres du numéro de téléphone (indicatif)
        // Cette approche est basée sur l'hypothèse que les numéros de téléphone ont la structure suivante : IND + XXXXXXX,
        int numeroIndicatif = LE->telephone / 1000000;

        // Vérifier si l'indicatif correspond à celui recherché
        if (numeroIndicatif == indicatif) {
            aucunNumeroTrouve = 0; // Au moins un numéro trouvé
            printf("Employé trouvé avec le numéro de téléphone commençant par l'indicatif %d:\n", indicatif);
            printf("Nom : %s\n", LE->nom);
            printf("Prenom : %s\n", LE->prenom);
            printf("Matricule : %d\n", LE->mat);
            printf("Numéro de téléphone : %d\n", LE->telephone);
            // Affichez d'autres informations de l'employé selon vos besoins
            printf("\n");
        }

        LE = LE->suiv;
    }

    // Si aucun numéro n'est trouvé, affichez le message approprié
    if (aucunNumeroTrouve) {
        printf("Aucun numéro n'a été trouvé avec l'indicatif %d.\n", indicatif);
    }
}

void echanger_employes(struct employe *a, struct employe *b) {
    // Échange des valeurs des employés a et b
    struct employe temp = *a;
    *a = *b;
    *b = temp;
}

void TRI1(liste_emp LE) {
    liste_emp head = LE;  // Sauvegarde du pointeur initial de la liste

    int taille = taille_liste_emp(LE);

    for (int i = 0; i < taille - 1; i++) {
        for (int j = 0; j < taille - i - 1; j++) {
            // Comparaison des salaires bruts pour un tri décroissant
            if (LE->salairebrut < LE->suiv->salairebrut) {
                // Échange des employés
                echanger_employes(LE, LE->suiv);
            }

            LE = LE->suiv;
        }

        // Réinitialiser le pointeur à la tête de la liste pour chaque passage
        LE = head;
    }
}

void TRI2(liste_emp *LE) {
    if (*LE == NULL || (*LE)->suiv == NULL) {
        // La liste est vide ou a un seul élément, elle est déjà triée
        return;
    }

    int taille = taille_liste_emp(*LE);

    for (int i = 0; i < taille - 1; i++) {
        struct employe **courant = LE;
        struct employe **suivant = &((*LE)->suiv);

        for (int j = 0; j < taille - i - 1; j++) {
            // Comparaison des salaires bruts pour un tri décroissant
            if ((*courant)->salairebrut < (*suivant)->salairebrut) {
                // Échange des pointeurs
                struct employe *temp = *courant;
                *courant = *suivant;
                *suivant = temp;
            }

            // Déplacer les pointeurs vers la cellule suivante
            courant = suivant;
            suivant = &((*suivant)->suiv);
        }
    }
}


// Fonction pour libérer la mémoire allouée à la liste
void Liberer_Memoire(liste_emp LE) {
    while (LE != NULL) {
        liste_emp temp = LE;
        LE = LE->suiv;
        free(temp);
    }
}


// Fonction pour libérer la mémoire allouée à la liste
void Liberer_Memoire(liste_emp LE) {
    while (LE != NULL) {
        liste_emp temp = LE;
        LE = LE->suiv;
        free(temp);
    }
}

