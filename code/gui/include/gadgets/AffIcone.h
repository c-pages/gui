#ifndef AFFICONE__H
#define AFFICONE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "AffImage.h"



namespace gui {



/////////////////////////////////////////////////
/// \brief Classe concr�te d'affichage d'une ic�ne
///
/////////////////////////////////////////////////
class AffIcone : public AffImage {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
    ///< Definir m_index
    void setIndex( unsigned int val ){ m_index = val; actualiser (); };

    ///< Acceder � m_index
    unsigned int getIndex () const { return m_index;  };

    virtual     void setStyle ( std::shared_ptr<Style> style , Etat etat = Etat::tous )
    {
        m_style = style;
        setIndex ( int ( etat ) - 1 );
        actualiser();
//        switch
//        setIndex
    };

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /////////////////////////////////////////////////
    AffIcone ();

    virtual void actualiser ();



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    unsigned int m_index;    ///< #G#S

}; // fin class AffIcone

} // fin namespace gui

#endif
