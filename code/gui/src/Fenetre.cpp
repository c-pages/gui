/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Fenetre.h>
#include <GrpSliders.h>
#include <GrpSimple.h>



namespace gui {

/////////////////////////////////////////////////
Fenetre::Fenetre ()
: m_panneau ( std::make_shared<GrpSliders>() )
, m_fond ( std::make_shared<AffRectangle>() )
, m_ombre ( std::make_shared<AffRectangle>() )
{
    ajouterComposant( m_ombre );
    ajouterComposant( m_fond );
    ajouterComposant( m_panneau );


    m_panneauFndCouleur             = sf::Color( 70,70,70, 255 );
    m_panneauFndLgnCouleur          = sf::Color( 255,255,255, 20 );
    m_panneauFndLgnepaisseur        = 1;
    m_panneauContenantCouleur       = sf::Color( 255,255,255, 255 );
    m_panneauContenantLgnCouleur    = sf::Color( 90,90,90, 255 );
    m_panneauContenantLgnepaisseur  = 0;

    m_fondCouleur                   = sf::Color( 55,55,55, 255 );
    m_fondLgnCouleur                = sf::Color( 90,90,90, 255 );
    m_fondLgnepaisseur              = 1;

    m_ombreCouleur                  = sf::Color( 0,0,0, 100 );
    m_ombreLgnCouleur               = sf::Color( 255,255,255, 255 );
    m_ombreLgnepaisseur             = 0;
}



/////////////////////////////////////////////////
void Fenetre::setDefilementActif (bool val)
{

}

/////////////////////////////////////////////////
void Fenetre::ajouter (std::shared_ptr<Gadget> enfant)
{
    m_panneau->ajouter ( enfant );
    if (m_parent != nullptr)
        m_parent->actualiserContenu();
}


/////////////////////////////////////////////////
std::shared_ptr<Gadget> Fenetre::retirer (std::shared_ptr<Gadget> enfant)
{
    m_panneau->retirer ( enfant );
}

/////////////////////////////////////////////////
void Fenetre::actualiserGeometrie ()
{



/*
    sf::Color               m_panneauFndCouleur;
    sf::Color               m_panneauFndLgnCouleur;
    float                   m_panneauFndLgnepaisseur;
    sf::Color               m_panneauContenantCouleur;
    sf::Color               m_panneauContenantLgnCouleur;
    float                   m_panneauContenantLgnepaisseur;

    sf::Color               m_fondCouleur;
    sf::Color               m_fondLgnCouleur;
    float                   m_fondLgnepaisseur;

    sf::Color               m_ombreCouleur;
    sf::Color               m_ombreLgnCouleur;
    float                   m_ombreLgnepaisseur;*/
}

/////////////////////////////////////////////////
void Fenetre::actualiserStyle ()
{

    m_panneau->setFillColor            ( m_panneauFndCouleur ) ;
    m_panneau->setOutlineColor         ( m_panneauFndLgnCouleur  ) ;
    m_panneau->setOutlineThickness     ( m_panneauFndLgnepaisseur  );

    m_panneau->setContenantFillColor       ( m_panneauContenantCouleur ) ;
    m_panneau->setContenantOutlineColor    ( m_panneauContenantLgnCouleur  ) ;
    m_panneau->setContenantOutlineThickness( m_panneauContenantLgnepaisseur  );

    m_fond->setFillColor            ( m_fondCouleur ) ;
    m_fond->setOutlineColor         ( m_fondLgnCouleur  ) ;
    m_fond->setOutlineThickness     ( m_fondLgnepaisseur  );

    m_ombre->setFillColor            ( m_ombreCouleur ) ;
    m_ombre->setOutlineColor         ( m_ombreLgnCouleur  ) ;
    m_ombre->setOutlineThickness     ( m_ombreLgnepaisseur  );

}

} // fin namespace gui

