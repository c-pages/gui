/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <DnBarreDefilement.h>



namespace gui {

/////////////////////////////////////////////////
DnBarreDefilement::DnBarreDefilement ()
: m_horizontal  ( true )
, m_slider      ( std::make_shared<DnSlider>() )
, m_btnPlus     ( std::make_shared<BtnRectangle>() )
, m_btnMoins    ( std::make_shared<BtnRectangle>() )
, m_longeur     ( 180 )
, m_largeur     ( 15 )
{
    ajouterComposant( m_slider );
    ajouterComposant( m_btnPlus );
    ajouterComposant( m_btnMoins );

    m_btnPlus->lier (Evenement::onBtnG_relacher, [this](){
        m_slider->incrementer();
    });
    m_btnMoins->lier (Evenement::onBtnG_relacher, [this](){
        m_slider->decrementer();
    });
}


/////////////////////////////////////////////////
void DnBarreDefilement::actualiser ()
{
    if (m_horizontal)
        m_taille = { m_longeur , m_largeur };
    else
        m_taille = { m_largeur , m_longeur };

    if (m_horizontal){
//        m_btnMoins->setTexte ( "<");
//        m_btnPlus->setTexte ( ">");
        m_btnMoins->setTaille   ( { m_largeur , m_largeur} );
        m_btnMoins->setPosition ( 0 , 0 );

        m_slider->setHorizontal ();
        m_slider->setLongueur   ( m_longeur - 2*m_largeur );
        m_slider->setLargeur   ( m_largeur );
        m_slider->setPosition   ( m_largeur , 0 );

        m_btnPlus->setTaille   ( { m_largeur , m_largeur} );
        m_btnPlus->setPosition ( m_longeur - m_largeur , 0 );

    }else {
//        m_btnMoins->setTexte ( "/\\");
//        m_btnPlus->setTexte ( "\\/");
        m_btnMoins->setTaille   ( { m_largeur , m_largeur} );
        m_btnMoins->setPosition ( 0 , 0  );

        m_slider->setVertical ();
        m_slider->setLongueur   (  m_longeur - 2*m_largeur );
        m_slider->setLargeur   ( m_largeur );
        m_slider->setPosition   ( 0, m_largeur  );

        m_btnPlus->setTaille   ( { m_largeur , m_largeur} );
        m_btnPlus->setPosition ( 0 , m_longeur - m_largeur  );

    }

    actualiser_bounds();
    m_btnMoins->actualiser_bounds();
    m_btnPlus->actualiser_bounds();
    m_slider->actualiser_bounds();
}


} // fin namespace gui

