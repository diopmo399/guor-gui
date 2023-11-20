#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


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
void supprimer_employes_service(liste_emp *LE, char service);
void modifier_donnees_employe(liste_emp *LE, int mat, int choix);

// fonction calcul salaire

float CNSS(struct employe emp);
float Impots(struct employe emp);
float Salaire_Net(struct employe emp);
float Somme_CNSS(liste_emp LE);
float Somme_Salaires_Bruts(liste_emp LE);
void Liberer_Memoire(liste_emp LE);
void Afficher_Salaires_Nets(liste_emp LE);
void recherche_par_matricule(liste_emp LE);
void recherche_par_nom(liste_emp LE);
void recherche_par_telephone(liste_emp LE);
void recherche_annee_bissextile(liste_emp LE);
void recherche_embauche_annee_bissextile(liste_emp LE);
void comparaison_date_embauche(liste_emp LE);
void recherche_retraite_proche(liste_emp LE);
void recherche_par_indicatif(liste_emp LE);
void TRI1(liste_emp LE);
void TRI2(liste_emp *LE);

#endif /* EMPLOYE_H */
