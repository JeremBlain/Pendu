#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QTextStream>
#include <QInputDialog>

#include "jeu.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   MainWindow();

    
signals:
    
public slots:
    void New();
    void Enter_letter(QString letter);
    void Game_over();

private:
    QPushButton *bouton_NewGame;
    QPushButton *bouton_mot;
    QPushButton *bouton_mot_bis;
    QPushButton *bouton_lettres_dites;

    QLineEdit *box_lettre;

    jeu_courant jeu;
    
};

#endif // MAINWINDOW_H
