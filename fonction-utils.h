#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct date {
    int jour;
    int mois;
    int annee;
};

struct employe {
    int mat;
    char nom[20];
    char prenom[20];
    char adresse[50];
    struct date DE; /* date d'embauche */
    int telephone;
    char service;
    float salairebrut;
    struct employe *suiv;
};

typedef struct employe *liste_emp;

int taille_liste_emp(liste_emp LE);
struct employe *recherche_emp(liste_emp LE, int num);
void inserer_tete_emp(liste_emp *LE, int mat, const char *nom, const char *prenom, const char *adresse,
                      int jour, int mois, int annee, int telephone, char service, float salairebrut);
void insere_queue_emp(liste_emp *LE, int mat, const char *nom, const char *prenom, const char *adresse,
                      int jour, int mois, int annee, int telephone, char service, float salairebrut);
void insere_pos_emp(liste_emp *LE, int pos, int mat, const char *nom, const char *prenom, const char *adresse,
                    int jour, int mois, int annee, int telephone, char service, float salairebrut);
void supprimer_tete_emp(liste_emp *LE);
void supprimer_queue_emp(liste_emp *LE);
void suppression_pos_emp(liste_emp *LE, int pos);
void suppression_employe_donne(liste_emp *LE, int num);
void afficher_info_employe(liste_emp LE, int num);
void afficher_tous_employes(liste_emp LE);
void afficher_liste(liste_emp LE);
bool matricule_unique(liste_emp LE, int mat);
void CREATION(liste_emp *LE);
int obtenirMatiricule(liste_emp  *LE);

#endif /* EMPLOYE_H */
