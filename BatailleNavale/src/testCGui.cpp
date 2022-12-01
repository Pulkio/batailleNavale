#include "CGui.h"

void testDefautConstructeur();

void testConstructeurAvecParam();

void testSetArmadaCoups();

void testPositionnerBateaux();

void testChoisirAttaque();

void testAffichageGagner();

void testAffichagePerdu();

void testAfficherLaGrille();


int main() {

    cout << "\n-------------------------------------------------------------\n" << endl;
    testDefautConstructeur();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testConstructeurAvecParam();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testPositionnerBateaux();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testSetArmadaCoups();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testChoisirAttaque();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testAffichageGagner();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testAffichagePerdu();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testAfficherLaGrille();
    cout << "\n-------------------------------------------------------------\n" << endl;
}

void testDefautConstructeur() {
    cout << "\n test constructeur par défaut CGui : \n" << endl;
    cout << "-----------------------------------------------------------" << endl;
    CGui *gui = new CGui();

    cout << gui << endl;

}

void testConstructeurAvecParam() {

    cout << "\ntest constructeur Avec param CGui : \n" << endl;
    cout << "-----------------------------------------------------------" << endl;


    CArmada *armada = new CArmada();

    CBateau b1("bateau(2)", make_pair(0, 0), 2);
    CBateau b2("bateau(3)", make_pair(0, 0), 3);
    CBateau b3("bateau(5)", make_pair(0, 0), 5);


    armada->ajouterBateau(b1);
    armada->ajouterBateau(b2);
    armada->ajouterBateau(b3);

    CCoups *coups = new CCoups();
    CGui gui(armada, coups);

    cout << "le constructeur a bien été créé" << endl;
    cout << gui << endl;

}

void testPositionnerBateaux() {

    cout << "test positionner bateaux (pour plus de tests voir testPlacerAleatoirement dans testCArmada) : " << endl;
    cout << "-----------------------------------------------------------" << endl;

    cout << "\ntest cas normal avec une armada qui contient 3 bateaux de taille 2,3 et 5 : \n" << endl;

    cout << "-----------------------------------------------------------" << endl;

    CArmada *armada = new CArmada();

    CBateau b1("bateau(2)", make_pair(0, 0), 2);
    CBateau b2("bateau(3)", make_pair(0, 0), 3);
    CBateau b3("bateau(5)", make_pair(0, 0), 5);


    armada->ajouterBateau(b1);
    armada->ajouterBateau(b2);
    armada->ajouterBateau(b3);

    CCoups *coups = new CCoups();
    CGui gui(armada, coups);

    cout << "Le positionnement a réussi : " << (gui.positionnerBateaux() ? "true" : "false") << endl;

}

void testSetArmadaCoups() {
    cout << "test methode setArmadaCoups : " << endl;
    cout << "-----------------------------------------------------------" << endl;

    cout << "\ntest cas normal avec une armada qui contient 3 bateaux et une instance de CCoups : \n" << endl;

    cout << "-----------------------------------------------------------" << endl;

    CGui *gui = new CGui();

    CArmada *armada = new CArmada();

    CBateau b1("bateau(2)", make_pair(0, 0), 2);
    CBateau b2("bateau(3)", make_pair(0, 0), 3);
    CBateau b3("bateau(5)", make_pair(0, 0), 5);


    armada->ajouterBateau(b1);
    armada->ajouterBateau(b2);
    armada->ajouterBateau(b3);

    CCoups *coups = new CCoups();

    gui->setArmadaCoups(armada, coups);

    cout << "le setter fonctionne" << endl;

}

void testChoisirAttaque() {
    cout << "test methode choisirAttaque" << endl;
    cout << "-----------------------------------------------------------" << endl;

    if ((TAILLE_GRILLE - 2) > 0) {
        cout << "\ntest cas normal avec des coordonnées comprisent entre 0 et " << (TAILLE_GRILLE - 2) << "\n" << endl;

        cout << "-----------------------------------------------------------" << endl;

        CArmada *armada = new CArmada();

        CBateau b1("bateau(2)", make_pair(0, 0), 2);
        CBateau b2("bateau(3)", make_pair(0, 0), 3);
        CBateau b3("bateau(5)", make_pair(0, 0), 5);


        armada->ajouterBateau(b1);
        armada->ajouterBateau(b2);
        armada->ajouterBateau(b3);

        CCoups *coups = new CCoups();
        CGui gui(armada, coups);

        pair<int, int> lapaire = gui.choisirAttaque();
        cout << "\n Voici les coordonnées de l'attaque : " << "\n" << endl;
        cout << "X : " << lapaire.first << endl;
        cout << "Y : " << lapaire.second << endl;

        cout << "-----------------------------------------------------------" << endl;

        cout << "\ntest cas limite avec X = 0 et Y =  " << (TAILLE_GRILLE - 2) << "\n" << endl;

        cout << "-----------------------------------------------------------" << endl;

        lapaire = gui.choisirAttaque();
        cout << "\n Voici les coordonnées de l'attaque : " << "\n" << endl;
        cout << "X : " << lapaire.first << endl;
        cout << "Y : " << lapaire.second << endl;

        cout << "-----------------------------------------------------------" << endl;

        cout << "test cas erreur avec X et Y hors de l'intervalle [0 ,   " << (TAILLE_GRILLE - 2) << "]\n" << endl;
        cout << "Vous devez obligatoirement rentrer des coordonnées qui sont dans l'ntervalle [0, "
             << (TAILLE_GRILLE - 2) << "] pour sortir de la boucle" << endl;

        cout << "-----------------------------------------------------------" << endl;

        lapaire = gui.choisirAttaque();
        cout << "\n Voici les coordonnées de l'attaque : " << "\n" << endl;
        cout << "X : " << lapaire.first << endl;
        cout << "Y : " << lapaire.second << endl;

        cout << "-----------------------------------------------------------" << endl;

        cout << "\ntest cas erreur avec X et Y qui ne sont pas des nombres\n " << endl;
        cout << "Vous devez obligatoirement rentrer des coordonnées qui sont dans l'ntervalle [0, "
             << (TAILLE_GRILLE - 2) << "] pour sortir de la boucle" << endl;

        cout << "-----------------------------------------------------------" << endl;

        lapaire = gui.choisirAttaque();
        cout << "\n Voici les coordonnées de l'attaque : " << "\n" << endl;
        cout << "X : " << lapaire.first << endl;
        cout << "Y : " << lapaire.second << endl;

    }

}

void testAffichagePerdu() {
    cout << "test methode AffichePerdu" << endl;
    cout << "-----------------------------------------------------------" << endl;

    CGui *gui = new CGui();
    gui->affichePerdu();
}

void testAffichageGagner() {
    cout << "test methode AfficheGagner" << endl;
    cout << "-----------------------------------------------------------" << endl;
    CGui *gui = new CGui();
    gui->afficheGagne();
}

void testAfficherLaGrille() {
    cout << "test methode AfficherLaGrille" << endl;
    cout << "-----------------------------------------------------------" << endl;


    CArmada *armada = new CArmada();

    CBateau b1("bateau(2)", make_pair(0, 0), 2);
    CBateau b2("bateau(3)", make_pair(0, 0), 3);
    CBateau b3("bateau(5)", make_pair(0, 0), 5);


    armada->ajouterBateau(b1);
    armada->ajouterBateau(b2);
    armada->ajouterBateau(b3);

    CCoups *coups = new CCoups();
    CGui gui(armada, coups);
    gui.positionnerBateaux();

    cout << gui << endl;
}





