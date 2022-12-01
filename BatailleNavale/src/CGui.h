//
// Created by guill on 27/02/2021.
//

#ifndef CGUI_H
#define CGUI_H


#include "CGui.h"
#include "BiblioStd.h"
#include "CArmada.h"
#include "CBaseJeu.h"
#include "CCoups.h"

class CGui : public CBaseJeu{
private:
    char m_grilleJou[TAILLE_GRILLE - 1][TAILLE_GRILLE - 1];
    char m_grilleAdv[TAILLE_GRILLE - 1][TAILLE_GRILLE - 1];
    CArmada* m_pArmada;
    CCoups* m_pCoups;
    void remplirDeuxGrilles(ostream& os);
    void afficherLaGrille(ostream& os, string jouOuAdv);

public:
    CGui();
    CGui(CArmada* pArmada, CCoups* cCoups);
    virtual ~CGui();
    void setArmadaCoups(CArmada* pArmada, CCoups* pCoups);
    bool positionnerBateaux();
    pair<int, int> choisirAttaque();
    void afficheGagne();
    void affichePerdu();
    friend ostream& operator<<(ostream& os, CGui& theG);

};

#endif //CGUI_H
