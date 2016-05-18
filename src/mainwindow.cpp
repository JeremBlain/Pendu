#include "mainwindow.h"

MainWindow::MainWindow()
{

    bouton_NewGame = new QPushButton("New game", this);
    bouton_NewGame->setFixedSize(200, 42);
    bouton_NewGame->setFont(QFont("Arial", 20) );

    bouton_mot = new QPushButton("",this);
    bouton_mot->move(0,50);
    bouton_mot->setFixedSize(200, 42);
    bouton_mot->setFont(QFont("Arial", 20) );

    bouton_mot_bis = new QPushButton("",this);
    bouton_mot_bis->move(210,50);
    bouton_mot_bis->setFixedSize(200, 42);
    bouton_mot_bis->setFont(QFont("Arial", 20) );


    box_lettre = new QLineEdit(this);
    box_lettre->move(0,100);
    box_lettre->setFixedSize(200, 42);
    box_lettre->setFont(QFont("Arial", 20) );

    bouton_lettres_dites = new QPushButton("OK", this);
    bouton_lettres_dites->move(210, 100);
    bouton_lettres_dites->setFont(QFont("Arial", 20) );

    QObject::connect(bouton_NewGame, SIGNAL(clicked()), this, SLOT(New()));
    QObject::connect(box_lettre, SIGNAL(textChanged(QString)), this, SLOT(Enter_letter(QString) ) );
    QObject::connect(box_lettre, SIGNAL(textChanged(QString)), box_lettre, SLOT(clear()) );
    QObject::connect(box_lettre, SIGNAL(textChanged(QString)), this, SLOT(Game_over() ) );
}



void MainWindow::New()
{
    init_jeu(&jeu);
    bouton_mot->setText(jeu.mot_courant);
    bouton_mot_bis->setText(jeu.mot);
}


void MainWindow::Enter_letter(QString letter)
{
    letter = letter.toUpper();
    jeu.mot_courant = remplacer_lettres_trouvees(jeu.mot, jeu.mot_courant, letter[0]);
    bouton_mot->setText(jeu.mot_courant);
}

void MainWindow::Game_over()
{
    jeu_terminer(jeu.mot_courant);
}

