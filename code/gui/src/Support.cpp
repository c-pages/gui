/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Support.h>
#include <Interface.h>



namespace gui {

/////////////////////////////////////////////////
Support::Support ()
: m_interface   ( nullptr )
, m_fond        ( std::make_shared<AffRectangle>() )
//, m_panneaux    ( std::make_shared<PanSimple>() )
{
    ajouterComposant ( m_fond );
//    ajouterComposant ( m_panneaux );

    m_taille = { 150 , 28 };

    m_fndCouleur        = sf::Color( 60, 60, 60 );
    m_fndLgnCouleur     = sf::Color( 90,90,90 );
    m_fndLgnEpaisseur   = 1 ;

//    ajouterComposant ( m_panneau );
}

/////////////////////////////////////////////////
void Support::actualiserGeometrie ()
{

//        std::cout << " BAH IL PASS PAR ICI ON DIRAIT BIEN\n";
    if (m_interface != nullptr)
    {
        auto tailleFenetre = m_interface->getFenetre()->getSize();
        m_taille = {tailleFenetre.x , m_taille.y};
    }
    m_fond->setTaille ( m_taille );
//    m_panneaux->setTaille ( { m_taille.x - 2*m_marge.x , m_taille.y - 2*m_marge.y });

}




/////////////////////////////////////////////////
void Support::actualiserStyle ()
{
    m_fond->setFillColor (m_fndCouleur);
    m_fond->setOutlineColor (m_fndLgnCouleur);
    m_fond->setOutlineThickness (m_fndLgnEpaisseur);
}


/*
/////////////////////////////////////////////////
void Support::ajouter (std::shared_ptr<Gadget> enfant)
{
    m_panneaux->ajouter ( enfant );
}*/


} // fin namespace gui

