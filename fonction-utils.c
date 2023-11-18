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

// Fonction pour afficher la liste des employés
void afficher_liste(liste_emp LE) {
    printf("Liste des employés:\n");
    afficher_tous_employes(LE);



}