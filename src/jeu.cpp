#include "jeu.h"



void init_jeu(jeu_courant *jeu)
{
    jeu->mot = demander_mot_joueur();
    jeu->mot_courant = transformer_mot_underscore(jeu->mot);
    jeu->lettres_dites = QString("");
}



QString demander_mot_joueur()
{
    QString mot;
    while( (mot = QInputDialog::getText(NULL,"Word ?","Give a word ?")).isEmpty() )
        QMessageBox::critical(NULL, "Error", "Give a word !");

    mot = mot.toUpper();

    return mot;
}


QString transformer_mot_underscore(QString mot)
{
    int length = mot.length();
    QString mot_underscore = "_ ";

    mot_underscore = mot_underscore.repeated(length);

    return mot_underscore;
}

QString remplacer_lettres_trouvees(QString mot, QString mot_courant, QChar letter)
{
    int length = mot.length();

    for(int pos_lettre=0; pos_lettre < length; pos_lettre++)
    {
        if(mot[pos_lettre] == letter)
            mot_courant[2*pos_lettre] = letter;
    }

    return mot_courant;
}

void jeu_terminer(QString mot)
{
    int length = mot.length();

    for(int pos_lettre=0; pos_lettre < length; pos_lettre++)
    {
        if(mot[2*pos_lettre] == '_')
             QMessageBox(QMessageBox::Information, "WIN !", "Tu as gagné, bravo !");
        }

}
