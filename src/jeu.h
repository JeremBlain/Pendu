#ifndef JEU_H
#define JEU_H

/*
 *  Toutes les fonctionnalités du jeu se trouvent ici
 *  comme par exemple :
 *  demande du mot, son enregistrement, l'état du mot (caractères trouvés ou non)
 *
 *
 */

#include <QFile>
#include <QInputDialog>
#include <QTextStream>
#include <QtWidgets>
#include <QMessageBox>

struct jeu_courant
{
    QString mot;
    QString mot_courant;
    QString lettres_dites;
};

/*Fonction d'initialisation du jeu
 *
 */

void init_jeu(jeu_courant *jeu);

/* Fonction demander mot joueur
 ******************************
 * Cette fonction permet de demander un mot au joueur
 *
 * Elle ne prend rien en paramètre
 *
 * Elle renvoie la chaine de caractère du mot
 */
QString demander_mot_joueur();


/* Fonction transformer mot underscore
 ******************************
 * Cette fonction permet de transformer le mot que le joueur a donné en
 * son éauivalent en underscore
 *
 * Elle prend le mot a transformer en paramètre
 *
 * Elle renvoie la chaine de caractère du mot transformé
 */
QString transformer_mot_underscore(QString mot);


/* Fonction remplacer_lettres_trouvees
 ******************************
 * Cette fonction permet de remplacer les lettres trouvées par l'user
 *
 * Elle prend en paramètre :
 *      - le mot à trouver
 *      - le mot courant
 *      - la lettre choisie par l'user
 *
 * Elle renvoie le mot courant correctement modifié
 */

QString remplacer_lettres_trouvees(QString mot, QString mot_courant, QChar letter);


/* Fonction jeu_terminer
 *  Si le mot ne contient plus d'underscore, alors le jeu est terminé
 *
 *Paramètres : le mot
 *Renvoie 0 si le mot contient des _, 1 sinon (le jeu est terminé)
 */

void jeu_terminer(QString mot);


#endif // JEU_H
