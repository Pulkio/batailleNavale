/**
 * Une armada se compose d'une collection de bateaux ( vector<CBateau> m_listeBateaux )
 */

#include "CArmada.h"
#include "exception/CException.h"

/**
 * Ajoute un bateau dans la structure
 * @param unBat le bateau à ajouter
 */
void CArmada::ajouterBateau(CBateau &unBat) {
    m_listeBateaux.push_back(unBat);
}

/**
 * Accesseur : renvoie (par pointeur) le bateau qui se trouve à l'index i dans le tableau (0 <= i < taille)
 * @param i l'index i
 * @return le pointeur sur le bateau qui se trouve à l'index i.
 */
CBateau *CArmada::getBateau(int i) {
    if (i >= 0 && i < (int) this->m_listeBateaux.size()) {
        return &this->m_listeBateaux.at(i);
    }
    else {
        string msg = "l'indice demandé n'est pas accessible : ";
        throw CException((char*) msg.c_str());
    }
}

/**
 * Renvoie le nombre total de bateaux de l'armada
 * @return le nombre de bateaux de l'armada
 */
int CArmada::getEffectifTotal() {
    return m_listeBateaux.size();
}

/**
 * @return le nombre total de cases occupées par l'armada.
 */
int CArmada::getNbreTotCases() {
    int nbCases = 0;
    CBateau *bat = m_listeBateaux.data();
    for (int i = 0; i < getEffectifTotal(); i++) {
        nbCases += bat[i].getTaille();
    }
    return nbCases;
}

/**
 * @return le nombre de bateaux qui ne sont pas encore coulés (flottille encore en vie sur l'eau).
 */
int CArmada::getEffectif() {
    int nbBat = 0;
    CBateau *bat = m_listeBateaux.data();
    for (int i = 0; i < getEffectifTotal(); i++) {
        if (!bat[i].estCoule()) {
            nbBat++;
        }
    }
    return nbBat;
}

/**
 * Cette fonction permet d'enlever les espaces vides à droites d'un string
 * @param str le string
 * @return le string trimé
 */
string CArmada::trim_right(const string& str)
{
    if(str.size() == 0) {
        string msg = "le nom du bateau est incorrect";
        throw CException((char*) msg.c_str());
    }
    const string pattern = " \f\n\r\t\v";
    return str.substr(0,str.find_last_not_of(pattern) + 1);
}


/**
 * Lecture du fichier flotille.txt qui contient la liste complète de tous les bateaux
 */
void CArmada::getArmadaFromFile() {
    int cpt = 0;
    vector<string> listeBateaux;
    vector<string> listeElement;
    ifstream fichier("../ws/flotille.txt");
    string ligne = "";
    if(fichier) {
        while (getline(fichier, ligne)) {
            if(ligne[0] != '#') {
                ligne = trim_right(ligne);
                if(!ligne.empty()) {
                    listeBateaux.push_back(ligne);
                    ligne = "";
                }

            }
        }
    }

    for(int i = 0; i < (int) listeBateaux.size(); i++) {
        string bateau = "";
        string nb = "";
        string taille = "";
        int nbre = 0;
        int length = 0;

        string line = listeBateaux.at(i);


        istringstream ss(line);
        string token;
        while(getline(ss, token, ' ')) {
            if(!token.empty()) {
                listeElement.push_back(token);
            }
        }


        bateau = listeElement.at(cpt);
        cpt++;
        nb = listeElement.at(cpt);
        cpt++;
        taille = listeElement.at(cpt);
        cpt++;
        cout << "bateau : " << bateau << endl;
        cout << "nb : " << nb << endl;
        cout << "taille : " << taille << endl;

        try {
            nbre = stoi(nb);
            length = stoi(taille);
        }
        catch (invalid_argument const &e)
        {
            cout << "Bad input: std::invalid_argument thrown" << endl;
        }

        for(int i = 0; i < nbre; i++) {
            CBateau bateau1(bateau, make_pair(0,0), length);
            ajouterBateau(bateau1);
        }

    }

}

/**
 * Placement aléatoire ET automatique horizontalement de TOUS les bateaux sur la grille.
 * @return faux si le positionnement automatique a échoué.
 */
bool CArmada::placerAleatoirement() {

    bool isPlace = false;
    int cpt = 0;
    int nbEssais = 0;



    do {
        int i = 0;
        cpt = 0;
        bool isGood = true;
        while (i < getEffectifTotal() && isGood) {

            CBateau *bateau = getBateau(i);
            int ligne = 0;
            int colonne = 0;

            int k = 0;

            do {
                ligne = rand() % ((TAILLE_GRILLE - 2) + 1);
                colonne = rand() % ((TAILLE_GRILLE - 2) + 1);
                k++;

            } while (isBoatHere(*bateau, make_pair(ligne, colonne)) && k < MAXESSAIS);

            if (k < MAXESSAIS) {

                try {

                    bateau->setPosition(ligne, colonne);

                    cpt++;
                    if (cpt == getEffectifTotal()) {

                        isPlace = true;

                    }
                }
                catch (CException &exception) {
                    cout << exception.what() << endl;
                }
            } else {

                cpt = 0;
                isGood = false;
                for (int j = 0; j < getEffectifTotal(); j++) {
                    CBateau *bat = getBateau(j);
                    bat->setPosition(0, 0);
                }
            }

            i++;
        }
        nbEssais++;

    } while (!isPlace && nbEssais <= MAXESSAIS);
    return isPlace;
}

/**
 * Cette methode permet de savoir si un bateau est présent sur les cases où l'on essaye de placer un autre bateau.
 * Elle considère qu'un bateau est présent sur une case en plus afin de laisser un espacement d'une case entre 2 bateaux.
 * Elle considère également qu'un bateau est présent si le positionnement est hors de la grille.
 * @param bateau le bateau a positionner
 * @param p les coordonnées suggérées
 * @return false s'il est possible de positionner le bateau a ces coordonnées
 */
bool CArmada::isBoatHere(CBateau &bateau, pair<int, int> p) {

    bool isHere = false;
    int i = 0;
    while (i < getEffectifTotal() && !isHere) {
        CBateau *bat = getBateau(i);

        int li = p.first;
        int co = p.second;
        int li2 = bat->getPosition().first;
        int co2 = bat->getPosition().second;


        if (li < 0 || (li > (TAILLE_GRILLE - 2)) || co < 0 || ((co + bateau.getTaille()) > (TAILLE_GRILLE - 2))) {
            isHere = true;
        } else if (li == li2) {
            if (((co >= co2 && co <= (co2 + bat->getTaille())) || ((co < co2 && co + bateau.getTaille() >= co2)))) {

                isHere = true;
            }
        }

        i++;
    }
    return isHere;

}