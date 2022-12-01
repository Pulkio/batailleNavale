/**
 * Cette classe permet de lancer des exceptions personnalisées
 */

#ifndef CEXCEPTION_H
#define CEXCEPTION_H
#include "../BiblioStd.h"

class CException {
private:
    char *m_pText;

public:
    // Constructeur
    CException(char *theText) {
        m_pText = new char[strlen(theText) + 1];
        strcpy(m_pText, theText);
    }

// Copy-Constructeur (important !!)
    CException(const CException &theObj) {
        m_pText = new char[strlen(theObj.m_pText) + 1];
        strcpy(m_pText, theObj.m_pText);
    }

// Accesseur
    char *what() { return m_pText; }

// Destructeur
    ~ CException() {
        if (m_pText != NULL) delete m_pText;
    }
};


#endif //BATAILLENAVALE_CEXCEPTION_H
