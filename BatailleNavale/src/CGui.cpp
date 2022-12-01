/**
 * Cette classe hérite de la classe abstraite CBaseJeu et s'occupe de l'affichage
 */

#include "CGui.h"
#include "exception/CException.h"

/**
 *  Constructeur par défaut : m_pArmada et m_pCoups à NULL
 */
CGui::CGui() {
    this->m_pArmada = NULL;
    this->m_pCoups = NULL;
}

/**
 * Constructeur qui reçoit un pointeur sur l'armada et un pointeur sur la structure d'enregistrement des tirs
 * @param pArmada pointeur sur l'armada
 * @param cCoups pointeur sur la structure d'enregistrement des tirs
 */
CGui::CGui(CArmada *pArmada, CCoups *cCoups) {
    this->m_pArmada = pArmada;
    this->m_pCoups = cCoups;
}

/**
 * Modificateur : mise à jour des attributs
 * @param pArmada pArmada pointeur sur l'armada
 * @param pCoups pointeur sur la structure d'enregistrement des tirs
 */
void CGui::setArmadaCoups(CArmada *pArmada, CCoups *pCoups) {
    this->m_pArmada = pArmada;
    this->m_pCoups = pCoups;
}

/**
 * Méthode appelée au début du jeu pour positionner
 * tous les bateaux sur la grille en exécutant placerAleatoirement de CArmada.
 * @return faux si le positionnement a échoué.
 */
bool CGui::positionnerBateaux() {
    bool isGood = false;
    CArmada armada;
    if (this->m_pArmada != NULL) {
        if (this->m_pArmada->placerAleatoirement()) {
            isGood = true;
        }
    }
    return isGood;
}

/**
 * Saisie de la coordonnée (ligne, colonne) de l'attaque
 * (vérification obligatoire bon/mauvais après saisie de
 * la coordonnée par l'utilisateur).
 * @return la coordonnée saisie
 */
pair<int,int> CGui::choisirAttaque(){
    bool isCorrect = false;
    string col;
    string li;
    int t = TAILLE_GRILLE - 2;
    stringstream ss;
    ss << t;
    string taille = ss.str();
    int colonne = 0;
    int ligne = 0;
    cout << "Choisissez les coordonnées de votre tir (Ligne / Colonne)" << endl;
    do {
        cout << "Ligne (0-" + taille + ") : " << endl;
        getline(cin, li);

        try {
            ligne = stoi(li);
            if (ligne >= 0 && ligne <= (TAILLE_GRILLE - 2)) {
                isCorrect = true;
            }
        }
        catch (invalid_argument &argument){
            cout << "Ceci n'est pas un nombre compris entre 0 et " +  taille << endl;
        }
    } while (!isCorrect);

    isCorrect = false;

    do {
        cout << "Colonne(0-" + taille + ") : " <<endl;
        getline(cin, col);

        try {
            colonne = stoi(col);
            if (colonne >= 0 && colonne <= (TAILLE_GRILLE - 2)) {
                isCorrect = true;
            }
        }
        catch (invalid_argument &argument ){

            cout << "Ceci n'est pas un nombre compris entre 0 et " + taille << endl;
        }
    } while (!isCorrect);



    return make_pair(ligne,colonne);
}

/**
 * remplit la grille du joueur m_grilleJou :
 * – en mettant 'B' dans les cases occupées par les cases des bateaux (du joueur) non touchées
 * – en mettant 'X' dans les cases occupées par les cases des bateaux (du joueur) touchées
 * – en mettant 'O' dans les cases ou les tirs adverses ont échoués (ploufs)
 *
 * remplit la grille de l'adversaire m_grilleAdv :
 * – en mettant 'X' dans les cases où les tirs du joueur sont victorieux
 * – en mettant 'O' dans les cases où les tirs du joueur ont échoués (ploufs)
 * @param os le stream de sortie.
 */
void CGui::remplirDeuxGrilles(ostream &os) {

    /** partie joueur */
    /** bateau remove de l effectif une fois coule */
    for(int i = 0; i < m_pArmada->getEffectifTotal(); i++) {
        CBateau *bat = m_pArmada->getBateau(i);
        int ligne = bat->getPosition().first;
        int colonne = bat->getPosition().second;
        for(int j = 0 ; j < bat->getTaille(); j++) {
            if(!(bat->getDegats(j))) {

                m_grilleJou[ligne][colonne + j] = 'B';
            }
            else {

                m_grilleJou[ligne][colonne + j] = 'X';
            }

        }
    }


    for(int i = 0; i < m_pCoups->getTaille("ploufAdverse"); i++) {
       int ligne = m_pCoups->getPair("ploufAdverse", i).first;
       int colonne = m_pCoups->getPair("ploufAdverse", i).second;

       if(m_grilleJou[ligne][colonne] != 'X') {
           m_grilleJou[ligne][colonne] = 'O';
       }
    }

    afficherLaGrille(os, "joueur");

    /** partie adversaire */
    for(int i = 0; i < m_pCoups->getTaille("touche"); i++) {
        int ligne = m_pCoups->getPair("touche", i).first;
        int colonne = m_pCoups->getPair("touche", i).second;

        m_grilleAdv[ligne][colonne] = 'X';
    }

    for(int i = 0; i < m_pCoups->getTaille("dansLEau"); i++) {
        int ligne = m_pCoups->getPair("dansLEau", i).first;
        int colonne = m_pCoups->getPair("dansLEau", i).second;

        m_grilleAdv[ligne][colonne] = 'O';
    }

    afficherLaGrille(os, "adversaire");

}

/**
 * Affichage d'une grille (joueur ou adversaire) à l'écran
 * @param os le stream de sortie
 * @param jouOuAdv le string joueur ou adversaire
 */
void CGui::afficherLaGrille(ostream &os, string jouOuAdv) {
    for(int i = 0; i < TAILLE_GRILLE; i++) {
        if(i == 0) {
            os << "\t";
        }
        else {
            os << (i - 1);
            os << "\t";
        }
    }

    if(jouOuAdv == "joueur") {

        for(int i = 0; i < TAILLE_GRILLE; i++) {
            if(i == 0) {
                os << "\n";
                os << "\n";
            }
            else {
                os << (i - 1);
                os << "\t";
                for(int j = 1; j < TAILLE_GRILLE; j++) {
                    if (m_grilleJou[i - 1][j - 1] == 'B') {
                        os << 'B';
                        os << '\t';
                    } else if (m_grilleJou[i - 1][j - 1] == 'X') {
                        os << 'X';
                        os << '\t';
                    } else if (m_grilleJou[i - 1][j - 1] == 'O') {
                        os << 'O';
                        os << '\t';
                    }
                    else {
                        os << '-';
                        os << '\t';
                    }
                }
                os << "\n";
                os << "\n";
            }
        }
        os << "\n";
    } else {
        for(int i = 0; i < TAILLE_GRILLE; i++) {
            if(i == 0) {
                os << "\n";
                os << "\n";
            }
            else {
                os << (i - 1);
                os << "\t";
                for(int j = 1; j < TAILLE_GRILLE; j++) {
                    if (m_grilleAdv[i - 1][j - 1] == 'X') {
                        os << 'X';
                        os << '\t';
                    } else if (m_grilleAdv[i - 1][j - 1] == 'O') {
                        os << 'O';
                        os << '\t';
                    }
                    else {
                        os << '-';
                        os << '\t';
                    }
                }

                os << "\n";
                os << "\n";
            }
        }
    }
}

/**
 * Affiche la partie est gagnée
 */
void CGui::afficheGagne() {
    cout << "FELICITATION, VOUS AVEZ GAGNE !" << endl;
}

/**
 * Affiche la partie est perdue.
 */
void CGui::affichePerdu() {
    cout << "DOMMAGE, VOUS AVEZ PERDU !" << endl;
}

/**
 * Surcharge de l'opérateur << pour afficher à l'écran CGui
 * @param os le stream de sortie
 * @param theG CGui
 * @return CGui
 */
ostream& operator<< (ostream& os, CGui& theG) {
    theG.remplirDeuxGrilles(os);
    return os;
}

/**
 * Le destructeur de CGui
 */
CGui::~CGui() {
    if(m_pArmada != NULL) {
        delete m_pArmada;
        cout << "destruction de pArmada" << endl;
    }
    if(m_pCoups != NULL) {
        delete m_pCoups;
        cout << "destruction de pCoups" << endl;
    }

}