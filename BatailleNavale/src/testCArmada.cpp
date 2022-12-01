//
// Created by guill on 17/02/2021.
//
#include "CArmada.h"
#include "exception/CException.h"

void testAjouterBateau();

void testGetBateau();

void testGetEffectifTotal();

void testGetNbreTotCases();

void testGetEffectif();

void testGetArmadaFromFile();

void testPlacerAleatoirement();


int main() {

    cout << "\n-------------------------------------------------------------\n" << endl;
    testAjouterBateau();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testGetBateau();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testGetEffectifTotal();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testGetNbreTotCases();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testGetEffectif();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testGetArmadaFromFile();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testPlacerAleatoirement();
    cout << "\n-------------------------------------------------------------\n" << endl;

    return 0;
}

void testAjouterBateau() {
    cout << "\n" << endl;
    cout << "_________________________________________" << endl;
    cout << "test de la methode AjouterBateau" << endl;
    cout << "_________________________________________" << endl;
    cout << "\n" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas normal avec bateau nommé bateau1\n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    CArmada armada;
    CBateau bateau1("Bateau1", make_pair(1, 1), 5);
    armada.ajouterBateau(bateau1);


    cout << "TEST DE RECUPERER LE BATEAU" << endl;
    CBateau *bat1 = armada.getBateau(0);



    cout << "\n ----------------------------------- \n" << endl;
    cout << "Voici le premier bateau de la liste de l'armada : " << *bat1 << endl;
    cout << "\n ----------------------------------- \n" << endl;

}

void testGetBateau() {
    cout << "\n" << endl;
    cout << "_________________________________________" << endl;
    cout << "test de la methode GetBateau" << endl;
    cout << "_________________________________________" << endl;
    cout << "\n" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas normal avec insertion de 3 bateaux dans la liste, et récupération des 3 bateaux\n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    CArmada armada;
    cout << "Ajout de Bateau1, Bateau2 et Bateau3 successivement dans l'armada" << endl;
    try {
        CBateau bateau1("Bateau1", make_pair(1, 1), 5);
        CBateau bateau2("Bateau2", make_pair(1, 1), 5);
        CBateau bateau3("Bateau3", make_pair(1, 1), 5);
        armada.ajouterBateau(bateau1);
        armada.ajouterBateau(bateau2);
        armada.ajouterBateau(bateau3);
    }
    catch (CException &exception) {
        cout << exception.what() << endl;
    }


    try {
        CBateau *bat1 = armada.getBateau(0);
        CBateau *bat2 = armada.getBateau(1);
        CBateau *bat3 = armada.getBateau(2);
        cout << "\n ----------------------------------- \n" << endl;
        cout << "Voici le premier bateau de la liste de l'armada : " << *bat1 << endl;
        cout << "\n ----------------------------------- \n" << endl;
        cout << "\n ----------------------------------- \n" << endl;
        cout << "Voici le deuxieme bateau de la liste de l'armada : " << *bat2 << endl;
        cout << "\n ----------------------------------- \n" << endl;
        cout << "\n ----------------------------------- \n" << endl;
        cout << "Voici le troisième bateau de la liste de l'armada : " << *bat3 << endl;
        cout << "\n ----------------------------------- \n" << endl;
    }
    catch (CException &exception) {
        cout << exception.what() << endl;
    }


    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas erreur : Récupérer un bateau d'un indice négatif\n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau *bat4 = armada.getBateau(-1);
        cout << bat4 << endl;
    }
    catch (CException &exception) {
        cout << exception.what() << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas erreur : Récupérer un bateau d'un indice supérieur à la taille de la liste\n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau *bat4 = armada.getBateau(3);
        cout << bat4 << endl;
    }
    catch (CException &exception) {
        cout << exception.what() << endl;
    }

}

void testGetEffectifTotal() {
    cout << "\n" << endl;
    cout << "_________________________________________" << endl;
    cout << "test de la methode GetEffectifTotal" << endl;
    cout << "_________________________________________" << endl;
    cout << "\n" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas normal avec insertion de 3 bateaux dans l'armada\n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    CArmada armada;
    try {
        CBateau bateau1("Bateau1", make_pair(1, 1), 5);
        CBateau bateau2("Bateau2", make_pair(1, 1), 5);
        CBateau bateau3("Bateau3", make_pair(1, 1), 5);
        armada.ajouterBateau(bateau1);
        armada.ajouterBateau(bateau2);
        armada.ajouterBateau(bateau3);
    }
    catch (CException &exception) {
        cout << exception.what() << endl;
    }

    cout << "GetEffectifTotal : " << armada.getEffectifTotal() << endl;

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas limite avec insertion de 0 bateau dans l'armada\n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    CArmada armada1;

    cout << "GetEffectifTotal : " << armada1.getEffectifTotal() << endl;
}

void testGetNbreTotCases() {
    cout << "\n" << endl;
    cout << "_________________________________________" << endl;
    cout << "test de la methode GetNbreCases" << endl;
    cout << "_________________________________________" << endl;
    cout << "\n" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas normal avec insertion de 3 bateaux de 5 cases dans l'armada\n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    CArmada armada;
    try {
        CBateau bateau1("Bateau1", make_pair(1, 1), 5);
        CBateau bateau2("Bateau2", make_pair(1, 1), 5);
        CBateau bateau3("Bateau3", make_pair(1, 1), 5);
        armada.ajouterBateau(bateau1);
        armada.ajouterBateau(bateau2);
        armada.ajouterBateau(bateau3);
    }
    catch (CException &exception) {
        cout << exception.what() << endl;
    }

    cout << "GetNbreTotCases : " << armada.getNbreTotCases() << endl;

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas limite avec insertion de 0 bateau dans l'armada\n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    CArmada armada1;

    cout << "GetEffectifTotal : " << armada1.getNbreTotCases() << endl;

}

void testGetEffectif() {
    cout << "\n" << endl;
    cout << "_________________________________________" << endl;
    cout << "test de la methode GetEffectif" << endl;
    cout << "_________________________________________" << endl;
    cout << "\n" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas normal avec insertion de 3 bateaux dans l'armada qui ne sont donc pas coulés\n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    CArmada armada;
    try {
        CBateau bateau1("Bateau1", make_pair(1, 1), 5);
        CBateau bateau2("Bateau2", make_pair(1, 1), 5);
        CBateau bateau3("Bateau3", make_pair(1, 1), 5);
        armada.ajouterBateau(bateau1);
        armada.ajouterBateau(bateau2);
        armada.ajouterBateau(bateau3);
    }
    catch (CException &exception) {
        cout << exception.what() << endl;
    }

    cout << "GetEffectif : " << armada.getEffectif() << endl;

    cout << "on coule un bateau : " << endl;

    try {
        CBateau *bat1 = armada.getBateau(0);

        for (int i = 1; i < bat1->getTaille() + 1; i++) {
            bat1->tirAdverse(make_pair(1, i));
        }
        cout << "le bateau est coulé ? : " << (bat1->estCoule() ? "true" : "false") << endl;
        cout << "GetEffectif : " << armada.getEffectif() << endl;
    }
    catch (CException &exception) {
        cout << exception.what() << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas limite avec insertion de 0 bateau dans l'armada\n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    CArmada armada1;
    cout << "GetEffectif : " << armada1.getEffectif() << endl;

}

void testGetArmadaFromFile() {
    cout << "\n" << endl;
    cout << "_________________________________________" << endl;
    cout << "test de la methode GetArmadaFromFile" << endl;
    cout << "_________________________________________" << endl;
    cout << "\n" << endl;
    CArmada armada;
    cout << "test cas normal : le fichier contient deux bateau torpilleurs de taille 2 et un porte-avion de taille 4" << endl;
    armada.getArmadaFromFile();
    cout << "GetEffectifTotal : " << armada.getEffectifTotal() << endl;
}


void testPlacerAleatoirement() {
    srand(time(NULL));
    cout << "\n" << endl;
    cout << "_________________________________________" << endl;
    cout << "test de la methode PlacerAleatoirement" << endl;
    cout << "_________________________________________" << endl;
    cout << "\n" << endl;

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas normal avec le positionnement de 5 bateaux dans l'armada\n" << endl;
    cout << "-----------------------------------------------------------" << endl;


    try {
        CArmada armada;
        CBateau bateau1("Bateau1", make_pair(1, 1), 5);
        CBateau bateau2("Bateau2", make_pair(1, 1), 5);
        CBateau bateau3("Bateau3", make_pair(1, 1), 5);
        CBateau bateau4("Bateau4", make_pair(1, 1), 5);
        CBateau bateau5("Bateau5", make_pair(1, 1), 5);

        armada.ajouterBateau(bateau1);
        armada.ajouterBateau(bateau2);
        armada.ajouterBateau(bateau3);
        armada.ajouterBateau(bateau4);
        armada.ajouterBateau(bateau5);

        if (armada.placerAleatoirement()) {
            CBateau *bat1 = armada.getBateau(0);
            CBateau *bat2 = armada.getBateau(1);
            CBateau *bat3 = armada.getBateau(2);
            CBateau *bat4 = armada.getBateau(3);
            CBateau *bat5 = armada.getBateau(4);

            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau1 : " << *bat1 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau2 : " << *bat2 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau3 : " << *bat3 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau4 : " << *bat4 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau5 : " << *bat5 << endl;
            cout << "\n ----------------------------------- \n" << endl;

        } else {
            cout << "le placement n'a pas fonctionné, le nombre de bateau est trop important" << endl;
        }

    }
    catch (CException &exception) {
        cout << exception.what() << endl;
    }


    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas limite avec le positionnement de 16 bateaux dans l'armada\n" << endl;
    cout << "ce placement ne fonctionne pas à tous les coups, vous pouvez executer plusieurs fois ce test afin de rencontrer des succès et des erreurs" << endl;
    cout << "-----------------------------------------------------------" << endl;


    try {
        CArmada armada;
        CBateau bateau1("Bateau1", make_pair(1, 1), 5);
        CBateau bateau2("Bateau2", make_pair(1, 1), 5);
        CBateau bateau3("Bateau3", make_pair(1, 1), 5);
        CBateau bateau4("Bateau4", make_pair(1, 1), 5);
        CBateau bateau5("Bateau5", make_pair(1, 1), 5);
        CBateau bateau6("Bateau6", make_pair(1, 1), 3);
        CBateau bateau7("Bateau7", make_pair(1, 1), 4);
        CBateau bateau8("Bateau8", make_pair(1, 1), 5);
        CBateau bateau9("Bateau9", make_pair(1, 1), 3);
        CBateau bateau10("Bateau10", make_pair(1, 1), 4);
        CBateau bateau11("Bateau11", make_pair(1, 1), 3);
        CBateau bateau12("Bateau12", make_pair(1, 1), 4);
        CBateau bateau13("Bateau13", make_pair(1, 1), 5);
        CBateau bateau14("Bateau14", make_pair(1, 1), 3);
        CBateau bateau15("Bateau15", make_pair(1, 1), 3);
        CBateau bateau16("Bateau16", make_pair(1, 1), 4);
        armada.ajouterBateau(bateau1);
        armada.ajouterBateau(bateau2);
        armada.ajouterBateau(bateau3);
        armada.ajouterBateau(bateau4);
        armada.ajouterBateau(bateau5);
        armada.ajouterBateau(bateau6);
        armada.ajouterBateau(bateau7);
        armada.ajouterBateau(bateau8);
        armada.ajouterBateau(bateau9);
        armada.ajouterBateau(bateau10);
        armada.ajouterBateau(bateau11);
        armada.ajouterBateau(bateau12);
        armada.ajouterBateau(bateau13);
        armada.ajouterBateau(bateau14);
        armada.ajouterBateau(bateau15);
        armada.ajouterBateau(bateau16);
        if (armada.placerAleatoirement()) {
            CBateau *bat1 = armada.getBateau(0);
            CBateau *bat2 = armada.getBateau(1);
            CBateau *bat3 = armada.getBateau(2);
            CBateau *bat4 = armada.getBateau(3);
            CBateau *bat5 = armada.getBateau(4);
            CBateau *bat6 = armada.getBateau(5);
            CBateau *bat7 = armada.getBateau(6);
            CBateau *bat8 = armada.getBateau(7);
            CBateau *bat9 = armada.getBateau(8);
            CBateau *bat10 = armada.getBateau(9);
            CBateau *bat11 = armada.getBateau(10);
            CBateau *bat12 = armada.getBateau(11);
            CBateau *bat13 = armada.getBateau(12);
            CBateau *bat14 = armada.getBateau(13);
            CBateau *bat15 = armada.getBateau(14);
            CBateau *bat16 = armada.getBateau(15);


            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau1 : " << *bat1 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau2 : " << *bat2 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau3 : " << *bat3 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau4 : " << *bat4 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau5 : " << *bat5 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau6 : " << *bat6 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau7 : " << *bat7 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau8 : " << *bat8 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau9 : " << *bat9 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau10 : " << *bat10 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau11 : " << *bat11 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau12 : " << *bat12 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau13 : " << *bat13 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau14 : " << *bat14 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau15 : " << *bat15 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau2 : " << *bat16 << endl;
            cout << "\n ----------------------------------- \n" << endl;
        } else {
            cout << "le placement n'a pas fonctionné, le nombre de bateau est trop important" << endl;
        }


    }
    catch (CException &exception) {
        cout << exception.what() << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas erreur avec le positionnement de 16 bateaux de taille 5 dans l'armada\n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CArmada armada;
        CBateau bateau1("Bateau1", make_pair(1, 1), 5);
        CBateau bateau2("Bateau2", make_pair(1, 1), 5);
        CBateau bateau3("Bateau3", make_pair(1, 1), 5);
        CBateau bateau4("Bateau4", make_pair(1, 1), 5);
        CBateau bateau5("Bateau5", make_pair(1, 1), 5);
        CBateau bateau6("Bateau6", make_pair(1, 1), 5);
        CBateau bateau7("Bateau7", make_pair(1, 1), 5);
        CBateau bateau8("Bateau8", make_pair(1, 1), 5);
        CBateau bateau9("Bateau9", make_pair(1, 1), 5);
        CBateau bateau10("Bateau10", make_pair(1, 1), 5);
        CBateau bateau11("Bateau11", make_pair(1, 1), 5);
        CBateau bateau12("Bateau12", make_pair(1, 1), 5);
        CBateau bateau13("Bateau13", make_pair(1, 1), 5);
        CBateau bateau14("Bateau14", make_pair(1, 1), 5);
        CBateau bateau15("Bateau15", make_pair(1, 1), 5);
        CBateau bateau16("Bateau16", make_pair(1, 1), 5);
        armada.ajouterBateau(bateau1);
        armada.ajouterBateau(bateau2);
        armada.ajouterBateau(bateau3);
        armada.ajouterBateau(bateau4);
        armada.ajouterBateau(bateau5);
        armada.ajouterBateau(bateau6);
        armada.ajouterBateau(bateau7);
        armada.ajouterBateau(bateau8);
        armada.ajouterBateau(bateau9);
        armada.ajouterBateau(bateau10);
        armada.ajouterBateau(bateau11);
        armada.ajouterBateau(bateau12);
        armada.ajouterBateau(bateau13);
        armada.ajouterBateau(bateau14);
        armada.ajouterBateau(bateau15);
        armada.ajouterBateau(bateau16);
        if (armada.placerAleatoirement()) {
            CBateau *bat1 = armada.getBateau(0);
            CBateau *bat2 = armada.getBateau(1);
            CBateau *bat3 = armada.getBateau(2);
            CBateau *bat4 = armada.getBateau(3);
            CBateau *bat5 = armada.getBateau(4);
            CBateau *bat6 = armada.getBateau(5);
            CBateau *bat7 = armada.getBateau(6);
            CBateau *bat8 = armada.getBateau(7);
            CBateau *bat9 = armada.getBateau(8);
            CBateau *bat10 = armada.getBateau(9);
            CBateau *bat11 = armada.getBateau(10);
            CBateau *bat12 = armada.getBateau(11);
            CBateau *bat13 = armada.getBateau(12);
            CBateau *bat14 = armada.getBateau(13);
            CBateau *bat15 = armada.getBateau(14);
            CBateau *bat16 = armada.getBateau(15);


            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau1 : " << *bat1 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau2 : " << *bat2 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau3 : " << *bat3 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau4 : " << *bat4 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau5 : " << *bat5 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau6 : " << *bat6 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau7 : " << *bat7 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau8 : " << *bat8 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau9 : " << *bat9 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau10 : " << *bat10 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau11 : " << *bat11 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau12 : " << *bat12 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau13 : " << *bat13 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau14 : " << *bat14 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau15 : " << *bat15 << endl;
            cout << "\n ----------------------------------- \n" << endl;
            cout << "bateau2 : " << *bat16 << endl;
            cout << "\n ----------------------------------- \n" << endl;
        } else {
            cout << "le placement n'a pas fonctionné, le nombre de bateau est trop important" << endl;
        }


    }
    catch (CException &exception) {
        cout << exception.what() << endl;
    }

}



