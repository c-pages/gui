#ifndef AFFICONE__H
#define AFFICONE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "AffImage.h"



namespace gui {



/////////////////////////////////////////////////
/// \brief Classe concrète d'affichage d'une icône
///
/////////////////////////////////////////////////
class AffIcone : public AffImage {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_index
    void setIndex( unsigned int val ){
//        std::cout << "AffIcone::nom: " << getNom() << " INDEX : " << m_index << "\n";
        m_index = val;
        actualiserStyle ();
    };

    ///< Acceder à m_index
    unsigned int getIndex () const { return m_index;  };

    virtual     void setStyle ( std::shared_ptr<Style> style , Etat etat = Etat::tous )
    {
        m_style = style;
        if (etat!= Etat::tous)
            setIndex ( int ( etat ) - 1 );
        actualiser();
    };

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    AffIcone ();

//    virtual void actualiser ();

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();


/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    unsigned int    m_index;    ///< #G#S
    float           m_nbrIcones;///< le nombre d'icones correspond au nombre largeur qu'il y a dans longueur.

}; // fin class AffIcone

} // fin namespace gui

#endif
