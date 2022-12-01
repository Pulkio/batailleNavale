/**
 * Un bateau est caractérisé par le nombre de cases (m_taille) qu'il occupe sur la grille, par un
 *nom (porte-avion, croiseur, ...) et par le point de départ de sa position HORIZONTALE sur la
 *grille (appelé point d'ancrage du bateau sur la grille) : pair<int,int> m_position, (0, 0)
 *correspondant à la case en haut à gauche sur la grille. Il mémorise également dans un tableau de
 *booléens les dégâts occasionnés sur le bateau (une case est à faux si elle n'est pas touchée par un tir
 *adverse).
 */

#include "CBateau.h"
#include "exception/CException.h"

/**
 *  Constructeur par défaut : "neant", (0,0), 0, NULL
 */
CBateau::CBateau() {
    cout << "initialisation du constructeur par défaut" << endl;
    this->m_nom = "neant";
    this->m_position.first = 0;
    this->m_position.second = 0;
    this->m_taille = 0;
    this->m_pDegats = nullptr;
}

/**
 * Constructeur, le bateau n'a encore aucune case touchée (m_pDegats à faux partout)
 * @param n le nom du bateau
 * @param p la position du bateau (ligne, colonne)
 * @param t la taille du bateau
 */
CBateau::CBateau(string n, pair<int, int> p, int t) {
    this->m_pDegats = new bool[t];

    n = trim_right(n);
    if (!n.empty()) {
        this->m_nom = n;
    } else {
        string msg = "le nom du bateau est incorrect";
        throw CException((char*) msg.c_str());
    }

    if (p.first >= 0 && p.first < (TAILLE_GRILLE - 1) && p.second >= 0 && p.second < (TAILLE_GRILLE - 1)) {

        this->m_position = p;
    } else {
        string msg = "le bateau est situé hors de la grille";
        throw CException((char*) msg.c_str());
    }
    if (t > 0 && t + p.second <= (TAILLE_GRILLE - 1)) {

        this->m_taille = t;
        for (int i = 0; i < m_taille; i++) {
            this->m_pDegats[i] = false;
        }
    } else {
        string msg = "le bateau sort de la grille";
        throw CException((char*) msg.c_str());
    }
}

/**
 * Cette fonction permet d'enlever les espaces vides à droites d'un string
 * @param str le string
 * @return le string trimé
 */
string CBateau::trim_right(const string &str) {
    if (str.size() == 0) {
        string msg = "le nom du bateau est incorrect";
        throw CException((char*) msg.c_str());
    }
    const string pattern = " \f\n\r\t\v";
    return str.substr(0, str.find_last_not_of(pattern) + 1);
}

/**
 *
 * @param i la case numéro i du bateau
 * @return vrai si la case numéro i du bateau est touchée ( 0 <= i < m_taille )
 */
bool CBateau::getDegats(int i) {
    bool isHit = false;
    if (i >= 0 && i < m_taille) {

        if (m_pDegats[i] == 1) {

            isHit = true;
        }
    } else {
        string msg = "l'indice demandé ne correspond pas à la taille du bateau";
        throw CException((char*) msg.c_str());
    }
    return isHit;
}

/**
 * le getter pour le nom
 * @return le nom du bateau
 */
string CBateau::getNom() {
    return this->m_nom;
}

/**
 * le getter pour la taille
 * @return la taille du bateau
 */
int CBateau::getTaille() {
    return this->m_taille;
}

/**
 * le getter pour la position du bateay
 * @return la position du bateau
 */
pair<int, int> CBateau::getPosition() {
    return this->m_position;
}

/**
 * Modifie la position du bateau sur la grille en ième ligne, jème colonne (nouveau point d'ancrage)
 * @param i numéro de la ligne
 * @param j numéro de la colonne
 */
void CBateau::setPosition(int i, int j) {
    if (i >= 0 && i < (TAILLE_GRILLE - 1) && j >= 0 && j < (TAILLE_GRILLE - 1)) {
        if (((this->m_taille - 1) + j ) < (TAILLE_GRILLE - 1)) {
            this->m_position.first = i;
            this->m_position.second = j;
        } else {
            string msg = "La taille du bateau ne permet pas de placer le bateau ici";
            throw CException((char*) msg.c_str());
        }
    } else {
        string msg = "Impossible de positionner le bateau en dehors de la grille";
        throw CException((char*) msg.c_str());
    }
}

/**
 * @return vrai si le bateau est coulé
 */
bool CBateau::estCoule() {
    bool isSunk = true;
    for (int i = 0; i < this->m_taille; i++) {
        if (!this->getDegats(i)) {
            isSunk = false;
        }
    }
    return isSunk;
}

/**
 * Surcharge de l'opérateur << pour afficher à l'écran les caractéristiques du bateau
 * @param os le stream de sortie
 * @param theB le bateau à imprimer
 * @return les caractéristiques du bateau
 */
ostream &operator<<(ostream &os, CBateau &theB) {
    os << "le nom du bateau est : " << theB.m_nom << endl;
    os << "la taille du bateau est de " << theB.m_taille << " cases" << endl;
    os << "le bateau est donc sur les cases : " << endl;
    for (int i = 0; i < theB.m_taille; i++) {
        os << theB.m_position.first << " : " << theB.m_position.second + i << endl;
    }
    for (int i = 0; i < theB.m_taille; i++) {
        os << "la case " << i << " a pris un degat ? " << (theB.getDegats(i) ? "true" : "false") << endl;
    }

    return os;
}

/**
 * Surcharge de l'opérateur =
 */
CBateau &CBateau::operator = (const CBateau &theB){
    if(this != &theB){
        if(this->m_pDegats != NULL) {
            delete[] m_pDegats;
        }
        this->m_nom = theB.m_nom;
        this->m_taille = theB.m_taille;
        this->m_position = theB.m_position;
        this->m_pDegats = new bool[this->m_taille];
        for(int i = 0; i < this->m_taille; i++){
            this->m_pDegats[i] = theB.m_pDegats[i];
        }
    }
    return *this;
}

/**
 * @param p les coordonnées du tir (ligne, colonne)
 * @return vrai si la coordonnée passée en paramètre est un tir victorieux (une case du
 * bateau est touchée.
 */
bool CBateau::tirAdverse(pair<int, int> p) {
    bool hit = false;
    if (p.first == this->m_position.first) {
        if (p.second >= m_position.second && p.second <= (m_position.second + m_taille)) {
            int posDegat = p.second - m_position.second;

            if (!this->getDegats(posDegat)) {

                this->m_pDegats[posDegat] = true;
                hit = true;

            }
        } else {
            if (p.first >= (TAILLE_GRILLE - 1) || p.second >= (TAILLE_GRILLE - 1) || p.first < 0 || p.second < 0) {
                string msg = "Impossible de tirer en dehors de la grille !";
                throw CException((char*) msg.c_str());
            }
        }
    } else {
        if (p.first >= (TAILLE_GRILLE - 1) || p.second >= (TAILLE_GRILLE - 1) || p.first < 0 || p.second < 0) {
            string msg = "Impossible de tirer en dehors de la grille !";
            throw CException((char*) msg.c_str());
        }
    }
    return hit;
}

/**
 * le copie constructeur de CBateau
 * @param bateauToCopy
 */
CBateau::CBateau(const CBateau &bateauToCopy) {
    this->m_nom = bateauToCopy.m_nom;
    this->m_position = bateauToCopy.m_position;
    this->m_taille = bateauToCopy.m_taille;

    m_pDegats = new bool[m_taille];
    for(int i = 0; i < this->m_taille; i++){
        this->m_pDegats[i] = bateauToCopy.m_pDegats[i];
    }
}



/**
 * le destructeur de CBateau
 */
CBateau::~CBateau() {
    if(this->m_pDegats) {
        delete[] this->m_pDegats;
    }

}







