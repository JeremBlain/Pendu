#include <QApplication>
#include <MainWindow.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv); //démarrage du programme

    MainWindow window; //creation de la fenetre de class MainWindow
    window.show(); //pour afficher la fenetre (et le bouton dedans)

    return app.exec();
}
