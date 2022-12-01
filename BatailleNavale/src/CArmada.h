//
// Created by guill on 17/02/2021.
//

#ifndef CARMADA_H
#define CARMADA_H

#include "BiblioStd.h"
#include "CArmada.h"
#include "CBateau.h"

class CArmada {


private:
    vector<CBateau> m_listeBateaux;
    bool isBoatHere(CBateau &bateau, pair<int, int> p);

public:
    void ajouterBateau(CBateau& unBat);
    CBateau* getBateau(int i);
    int getEffectifTotal();
    int getNbreTotCases();
    int getEffectif();
    void getArmadaFromFile();
    bool placerAleatoirement();
    string trim_right(const string& str);
};


#endif //CARMADA_H
