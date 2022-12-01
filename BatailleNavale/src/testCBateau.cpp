//
// Created by guill on 14/02/2021.
//
#include "CBateau.h"
#include "exception/CException.h"

void testDefautConstruct();

void testAutreConstruct();

void testGetNom();

void testGetDegat();

void testGetTaille();

void testGetPosition();

void testSetPosition();

void testTirAdverse();

void testEstCoule();

void testSurchargeOpEgale();

int main() {
    testDefautConstruct();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testAutreConstruct();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testGetNom();
    cout << "\n-------------------------------------------------------------\n" << endl;
      testGetDegat();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testGetTaille();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testGetPosition();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testSetPosition();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testTirAdverse();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testEstCoule();
    cout << "\n-------------------------------------------------------------\n" << endl;
    testSurchargeOpEgale();
    return 0;
}

void testDefautConstruct() {
    cout << "test constructeur par défaut : " << endl;
    CBateau bateau;
    cout << bateau << endl;
}

void testAutreConstruct() {
    cout << "test constructeur avec paramètres : " << endl;
    cout << "-----------------------------------------------------------" << endl;

    cout << "\ntest cas normal1 : \n" << endl;

    cout << "-----------------------------------------------------------" << endl;
    try {
        CBateau bateau1("Bateau1", make_pair(2, 2), 5);
        cout << bateau1 << endl;
    }
    catch (CException& exception) {
        cout << exception.what() << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas normal2 : \n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau2("Bateau2", make_pair(5,5), 4);
        cout << bateau2 << endl;
    }
    catch (CException& exception) {
        cout << exception.what() << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas limite1 avec bateau qui fait la taille de la grille : \n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau3("Bateau3", make_pair(0, 0), 10);
        cout << bateau3 << endl;
    }
    catch (CException& exception) {
        cout << exception.what() << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas limite avec bateau en (9,9) de taille 1 : \n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau4("Bateau4", make_pair(9, 9), 1);
        cout << bateau4 << endl;
    }
    catch (CException& exception) {
        cout << exception.what() << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas erreur avec bateau en (10,10) de taille 1 : \n" << endl;
    cout << "-----------------------------------------------------------" << endl;


    try {
        CBateau bateau5("Bateau5", make_pair(10, 10), 1);
        cout << bateau5 << endl;
    }
    catch (CException& exception) {
        cout << exception.what() << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas erreur avec bateau en (-1,1) de taille 1 : \n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau6("Bateau6", make_pair(-1, 1), 1);
        cout << bateau6 << endl;
    }
    catch (CException& exception) {
        cout << exception.what() << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas erreur avec bateau en (1,-1) de taille 1 : \n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau7("Bateau7", make_pair(1, -1), 1);
        cout << bateau7 << endl;
    }
    catch (CException& exception) {
        cout << exception.what() << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas erreur avec bateau en (5,5) de taille 0 : \n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau8("Bateau8", make_pair(5, 5), 0);
        cout << bateau8 << endl;
    }
    catch (CException& exception) {
        cout << exception.what() << endl;
    }

}

void testGetNom() {
    cout << "\n" << endl;
    cout << "_________________________________________" << endl;
    cout << "test de la methode getNom" << endl;
    cout << "_________________________________________" << endl;
    cout << "\n" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas normal avec bateau nommé Bateau1\n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau1("Bateau1", make_pair(2, 2), 5);
        cout << "test de la methode getNom : " << bateau1.getNom() << endl;
    }
    catch (CException& exception) {
        cout << exception.what() << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas limite avec un bateau nommé avec des espaces \n" << endl;
    cout << "-----------------------------------------------------------" << endl;
    try {
        CBateau bateau2("     ", make_pair(2,2),5);
        cout << "test de la methode getNom : " << bateau2.getNom() << endl;
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas limite avec un bateau nommé avec rien \n" << endl;
    cout << "-----------------------------------------------------------" << endl;
    try {
        CBateau bateau2("", make_pair(2,2),5);
        cout << "test de la methode getNom : " << bateau2.getNom() << endl;
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }

}

void testGetTaille() {
    cout << "\n" << endl;
    cout << "_________________________________________" << endl;
    cout << "test de la methode getTaille" << endl;
    cout << "_________________________________________" << endl;
    cout << "\n" << endl;

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas normal avec un bateau de taille 5 \n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau1("BateauFirst1", make_pair(2, 2), 5);
        cout << "test de la methode getTaille : " << bateau1.getTaille() << endl;
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }

}

void testGetDegat() {
    cout << "\n" << endl;
    cout << "_________________________________________" << endl;
    cout << "test de la methode getDegats" << endl;
    cout << "_________________________________________" << endl;
    cout << "\n" << endl;

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas normal avec un bateau positionné en (2,2) de taille 3 \n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau1("Bateau1", make_pair(2, 2), 3);
        cout << "test de la methode getPosition ( getDegats(0) ): " << (bateau1.getDegats(0) ? "true" : "false") << endl;
        cout << "test de la methode getPosition ( getDegats(1) ): " << (bateau1.getDegats(0) ? "true" : "false")<< endl;
        cout << "test de la methode getPosition ( getDegats(2) ): " << (bateau1.getDegats(0) ? "true" : "false")<< endl;
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas erreur avec un bateau positionné en (2,2) de taille 3 \n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau1("Bateau1", make_pair(2, 2), 3);
        cout << "test de la methode getPosition ( getDegats(3) ): " << (bateau1.getDegats(3) ? "true" : "false") << endl;
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas erreur avec un bateau positionné en (2,2) de taille 3 \n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau1("Bateau1", make_pair(2, 2), 3);
        cout << "test de la methode getPosition ( getDegats(-1) ): " << (bateau1.getDegats(-1) ? "true" : "false") << endl;
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }

}

void testGetPosition() {
    cout << "\n" << endl;
    cout << "_________________________________________" << endl;
    cout << "test de la methode getPosition" << endl;
    cout << "_________________________________________" << endl;
    cout << "\n" << endl;

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas normal avec un bateau positionné en (2,2) \n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau1("BateauFirst1", make_pair(2, 2), 5);
        cout << "test de la methode getPosition : " << bateau1.getPosition().first << " , " << bateau1.getPosition().second << endl;
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }

}

void testSetPosition() {
    cout << "\n" << endl;
    cout << "_________________________________________" << endl;
    cout << "test de la methode setPosition" << endl;
    cout << "_________________________________________" << endl;
    cout << "\n" << endl;

    try {

        cout << "-----------------------------------------------------------" << endl;
        cout << "\ntest de cas normal et de set la position en 3 , 3\n" << endl;
        cout << "-----------------------------------------------------------" << endl;

        CBateau bateau1("BateauFirst1", make_pair(2, 2), 5);
        cout << "le bateau est positionné en : " << bateau1.getPosition().first << " , " << bateau1.getPosition().second
             << endl;

        bateau1.setPosition(3, 3);
        cout << "le bateau est maintenant positionné en : " << bateau1.getPosition().first << " , "
             << bateau1.getPosition().second << endl;
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }


    try {
        cout << "-----------------------------------------------------------" << endl;
        cout << "test de cas normal et de set la position en 4 , 4" << endl;
        cout << "-----------------------------------------------------------" << endl;

        CBateau bateau1("BateauFirst1", make_pair(2, 2), 5);
        cout << "le bateau est positionné en : " << bateau1.getPosition().first << " , " << bateau1.getPosition().second
             << endl;
        bateau1.setPosition(4, 4);
        cout << "le bateau est maintenant positionné en : " << bateau1.getPosition().first << " , "
             << bateau1.getPosition().second << endl;
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }


    try {
        cout << "-----------------------------------------------------------" << endl;
        cout << "test de cas limite et de set la position en 0 , 0" << endl;
        cout << "-----------------------------------------------------------" << endl;

        CBateau bateau1("BateauFirst1", make_pair(2, 2), 5);
        cout << "le bateau est positionné en : " << bateau1.getPosition().first << " , " << bateau1.getPosition().second
             << endl;
        bateau1.setPosition(0, 0);
        cout << "le bateau est maintenant positionné en : " << bateau1.getPosition().first << " , "
             << bateau1.getPosition().second << endl;
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }


    try {
        cout << "-----------------------------------------------------------" << endl;
        cout << "test de cas limite et de set la position en 9 , 9 pour un bateau de taille 1" << endl;
        cout << "-----------------------------------------------------------" << endl;

        CBateau bateau1("BateauFirst1", make_pair(2, 2), 1);
        cout << "le bateau est positionné en : " << bateau1.getPosition().first << " , " << bateau1.getPosition().second
             << endl;
        bateau1.setPosition(9, 9);
        cout << "le bateau est maintenant positionné en : " << bateau1.getPosition().first << " , "
             << bateau1.getPosition().second << endl;
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }


    try {
        cout << "-----------------------------------------------------------" << endl;
        cout << "test de cas d'erreur et de set la position en 10 , 10 pour un bateau de taille 1" << endl;
        cout << "-----------------------------------------------------------" << endl;

        CBateau bateau1("BateauFirst1", make_pair(2, 2), 1);
        cout << "le bateau est positionné en : " << bateau1.getPosition().first << " , " << bateau1.getPosition().second
             << endl;
        bateau1.setPosition(10, 10);
        cout << "le bateau est maintenant positionné en : " << bateau1.getPosition().first << " , "
             << bateau1.getPosition().second << endl;
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }

    try {
        cout << "-----------------------------------------------------------" << endl;
        cout << "test de cas d'erreur et de set la position en 7 , 7 pour un bateau de taille 4" << endl;
        cout << "-----------------------------------------------------------" << endl;

        CBateau bateau1("BateauFirst1", make_pair(5, 5), 4);
        cout << "le bateau est positionné en : " << bateau1.getPosition().first << " , " << bateau1.getPosition().second
             << endl;
        bateau1.setPosition(7, 7);
        cout << "le bateau est maintenant positionné en : " << bateau1.getPosition().first << " , "
             << bateau1.getPosition().second << endl;
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }

    try {
        cout << "-----------------------------------------------------------" << endl;
        cout << "test de cas d'erreur et de set la position en -1 , 1 pour un bateau de taille 3" << endl;
        cout << "-----------------------------------------------------------" << endl;

        CBateau bateau1("BateauFirst1", make_pair(5, 5), 3);
        cout << "le bateau est positionné en : " << bateau1.getPosition().first << " , " << bateau1.getPosition().second
             << endl;
        bateau1.setPosition(-1, 1);
        cout << "le bateau est maintenant positionné en : " << bateau1.getPosition().first << " , "
             << bateau1.getPosition().second << endl;
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }

    try {
        cout << "-----------------------------------------------------------" << endl;
        cout << "test de cas d'erreur et de set la position en 1 , -1 pour un bateau de taille 3" << endl;
        cout << "-----------------------------------------------------------" << endl;

        CBateau bateau1("BateauFirst1", make_pair(5, 5), 3);
        cout << "le bateau est positionné en : " << bateau1.getPosition().first << " , " << bateau1.getPosition().second
             << endl;
        bateau1.setPosition(1, -1);
        cout << "le bateau est maintenant positionné en : " << bateau1.getPosition().first << " , "
             << bateau1.getPosition().second << endl;
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }


}

void testTirAdverse() {
    cout << "\n" << endl;
    cout << "_________________________________________" << endl;
    cout << "test de la methode tirAdverse" << endl;
    cout << "_________________________________________" << endl;
    cout << "\n" << endl;


    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest de cas normal : tir adverse en position 2,2 qui est la première case du bateau\n " << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau1("BateauFirst1", make_pair(2, 2), 5);
        bateau1.tirAdverse(make_pair(2, 2));
        for(int i = 0; i < bateau1.getTaille(); i++) {
            cout << "voici le resultat du tir, bateau.getDegat(" << i << ") = " << (bateau1.getDegats(i) ? "true" : "false")  << endl;
        }

    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest de cas normal : tir adverse sur toutes les cases du bateau\n " << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau1("BateauTest", make_pair(2, 2), 5);
        bateau1.tirAdverse(make_pair(2, 2));
        bateau1.tirAdverse(make_pair(2, 3));
        bateau1.tirAdverse(make_pair(2, 4));
        bateau1.tirAdverse(make_pair(2, 5));
        bateau1.tirAdverse(make_pair(2, 6));
        for(int i = 0; i < bateau1.getTaille(); i++) {
            cout << "voici le resultat du tir, bateau.getDegat(" << i << ") = " << (bateau1.getDegats(i) ? "true" : "false")  << endl;
        }

    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest de cas limite : tir adverse dans l'eau : le bateau est positionné en (2,2) je vais donc tirer en (1,1)\n " << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau1("BateauFirst1", make_pair(2, 2), 5);
        cout << "premier tir" << endl;
        bateau1.tirAdverse(make_pair(1, 1));
        for(int i = 0; i < bateau1.getTaille(); i++) {
            cout << "voici le resultat du tir, bateau.getDegat(" << i << ") = " << (bateau1.getDegats(i) ? "true" : "false")  << endl;
        }
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }


    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas erreur : Essayer de tirer en (10,10) en dehors de la carte\n " << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau1("BateauFirst1", make_pair(2, 2), 5);
        cout << "premier tir" << endl;
        bateau1.tirAdverse(make_pair(10, 10));
        for(int i = 0; i < bateau1.getTaille(); i++) {
            cout << "voici le resultat du tir, bateau.getDegat(" << i << ") = " << (bateau1.getDegats(i) ? "true" : "false")  << endl;
        }
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "\ntest cas erreur : Essayer de tirer en (-1,-1) en dehors de la carte\n " << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau1("BateauFirst1", make_pair(2, 2), 5);
        cout << "premier tir" << endl;
        bateau1.tirAdverse(make_pair(-1, -1));
        for(int i = 0; i < bateau1.getTaille(); i++) {
            cout << "voici le resultat du tir, bateau.getDegat(" << i << ") = " << (bateau1.getDegats(i) ? "true" : "false")  << endl;
        }
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }

}

void testEstCoule() {

    cout << "\n" << endl;
    cout << "_________________________________________" << endl;
    cout << "test de la methode estCoule" << endl;
    cout << "_________________________________________" << endl;
    cout << "\n" << endl;

    cout << "-----------------------------------------------------------" << endl;
    cout << "\n test cas normal : Couler un bateau de 5 cases : \n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau1("Bateau1", make_pair(2, 2), 5);

        for (int i = 2; i < bateau1.getTaille() + 2; i++) {
            bateau1.tirAdverse(make_pair(2, i));
        }
        cout << bateau1 << endl;
        cout << "le bateau est coulé ? : " << (bateau1.estCoule()? "true" : "false") << endl;
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "\n test cas normal : Toucher 4 cases d'un bateau de 5 cases : \n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau1("Bateau1", make_pair(2, 2), 5);

        for (int i = 2; i < (bateau1.getTaille() - 1) + 2; i++) {
            bateau1.tirAdverse(make_pair(2, i));
        }
        cout << bateau1 << endl;
        cout << "le bateau est coulé ? : " << (bateau1.estCoule()? "true" : "false") << endl;
    }
    catch(CException& exception) {
        cout << exception.what() << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "\n test cas limite : Couler un bateau de 1 case : \n" << endl;
    cout << "-----------------------------------------------------------" << endl;

    try {
        CBateau bateau1("Bateau1", make_pair(2, 2), 1);
        bateau1.tirAdverse(make_pair(2, 2));
        cout << bateau1 << endl;
        cout << "le bateau est coulé ? : " << (bateau1.estCoule()? "true" : "false") << endl;
    }
    catch (CException& exception){
        cout << exception.what() << endl;
    }

}

void testSurchargeOpEgale() {
    cout << "test methode surchargeOpEgale" << endl;
    cout << "-----------------------------------------------------------" << endl;

    cout << "\ntest cas normal avec 2 bateaux\n" << endl;

    cout << "\n Création de 2 bateaux \n" << endl;
    CBateau bateau10("Bateau1", make_pair(2, 2), 1);

    cout << "\n PREMIER BATEAU : \n" << endl;
    cout << bateau10 << endl;

    cout << "\n DEUXIEME BATEAU : \n" << endl;
    CBateau bateau20("Bateau2", make_pair(5, 5), 5);

    cout << bateau20 << endl;

    cout << "\n Bateau2 = Bateau1 \n" << endl;
    cout << "resultat : " << endl;

    bateau20 = bateau10;

    cout << "\n DEUXIEME BATEAU : \n" << endl;
    cout << bateau20 << endl;


    cout << "\ntest cas limite avec 5 bateaux\n" << endl;

    cout << "\n Création de 2 bateaux \n" << endl;
    CBateau bateau1("Bateau1", make_pair(1, 1), 1);

    cout << "\n PREMIER BATEAU : \n" << endl;
    cout << bateau1 << endl;

    cout << "\n DEUXIEME BATEAU : \n" << endl;
    CBateau bateau2("Bateau2", make_pair(2, 2), 2);

    cout << bateau2 << endl;

    cout << "\n TROISIEME BATEAU : \n" << endl;
    CBateau bateau3("Bateau3", make_pair(3, 3), 3);

    cout << bateau3 << endl;

    cout << "\n QUATRIEME BATEAU : \n" << endl;
    CBateau bateau4("Bateau4", make_pair(4, 4), 4);

    cout << bateau4 << endl;

    cout << "\n CINQUIEME BATEAU : \n" << endl;
    CBateau bateau5("Bateau5", make_pair(5, 5), 5);

    cout << bateau5 << endl;

    cout << "\n BATEAU 1 = BATEAU 2 = BATEAU 3 = BATEAU 4 = BATEAU 5\n" << endl;

    bateau1 = bateau2 = bateau3 = bateau4 = bateau5;

    cout << "\n EST CE QUE BATEAU 1 = BATEAU 5 ?????" << endl;

    cout << "PREMIER BATEAU" << endl;
    cout << bateau1 << endl;

}




