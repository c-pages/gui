/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <DnBarreDefilement.h>



namespace gui {

/////////////////////////////////////////////////
DnBarreDefilement::DnBarreDefilement ()
: m_horizontal  ( true )
, m_slider      ( std::make_shared<DnSlider>() )
, m_btnPlus     ( std::make_shared<BtnIcone>() )
, m_btnMoins    ( std::make_shared<BtnIcone>() )
, m_longueur     ( 180 )
, m_largeur     ( 15 )
{

    ajouterComposant( m_slider );
    ajouterComposant( m_btnPlus );
    ajouterComposant( m_btnMoins );

    std::string fichier = "media/img/ico_fleches.png";

    m_btnMoins->chargerDepuisFichier ( fichier );
    m_btnPlus->chargerDepuisFichier ( fichier );

    m_btnMoins->setFix( true );
    m_btnPlus->setFix( true );

    m_btnMoins->setIconeIndex( 3 );
    m_btnPlus->setIconeIndex( 4 );

    m_btnMoins->setMarge( {0,0} );
    m_btnPlus->setMarge( {0,0} );

    m_btnPlus->lier (Evenement::onBtnG_relacher, [this](){
        m_slider->incrementer();
        declencher(Evenement::on_changerValeur);
    });

    m_btnMoins->lier (Evenement::onBtnG_relacher, [this](){
        m_slider->decrementer();
        declencher(Evenement::on_changerValeur);
    });


    m_slider->lier (Evenement::on_changerValeur , [this](){
        declencher(Evenement::on_changerValeur);
    });

}


void DnBarreDefilement::actualiserGeometrie ()
{
       if (m_horizontal)
        m_taille = { m_longueur , m_largeur };
    else
        m_taille = { m_largeur , m_longueur };

    if (m_horizontal){


        m_btnMoins->setIconeIndex( 3 );
        m_btnPlus->setIconeIndex( 4 );

        m_btnMoins->setTaille   ( { m_largeur , m_largeur} );
        m_btnMoins->setPosition ( 0 , 0 );

        m_slider->setHorizontal ();
        m_slider->setLongueur   ( m_longueur - 2*m_largeur );
        m_slider->setLargeur    ( m_largeur );
        m_slider->setPosition   ( m_largeur , 0 );

        m_btnPlus->setTaille   ( { m_largeur , m_largeur} );
        m_btnPlus->setPosition ( m_longueur - m_largeur , 0 );

    }else {
        m_btnMoins->setIconeIndex( 1 );
        m_btnPlus->setIconeIndex( 2 );

//        m_btnMoins->setTexte ( "/\\");
//        m_btnPlus->setTexte ( "\\/");
        m_btnMoins->setTaille   ( { m_largeur , m_largeur} );
        m_btnMoins->setPosition ( 0 , 0  );

        m_slider->setVertical ();
        m_slider->setLongueur   (  m_longueur - 2*m_largeur );
        m_slider->setLargeur   ( m_largeur );
        m_slider->setPosition   ( 0, m_largeur  );

        m_btnPlus->setTaille   ( { m_largeur , m_largeur} );
        m_btnPlus->setPosition ( 0 , m_longueur - m_largeur  );

    }
}

void DnBarreDefilement::actualiserStyle ()
{

}
/*

/////////////////////////////////////////////////
void DnBarreDefilement::actualiser ()
{
    if (m_horizontal)
        m_taille = { m_longueur , m_largeur };
    else
        m_taille = { m_largeur , m_longueur };

    if (m_horizontal){


        m_btnMoins->setIconeIndex( 3 );
        m_btnPlus->setIconeIndex( 4 );

        m_btnMoins->setTaille   ( { m_largeur , m_largeur} );
        m_btnMoins->setPosition ( 0 , 0 );

        m_slider->setHorizontal ();
        m_slider->setLongueur   ( m_longueur - 2*m_largeur );
        m_slider->setLargeur    ( m_largeur );
        m_slider->setPosition   ( m_largeur , 0 );

        m_btnPlus->setTaille   ( { m_largeur , m_largeur} );
        m_btnPlus->setPosition ( m_longueur - m_largeur , 0 );

    }else {
        m_btnMoins->setIconeIndex( 1 );
        m_btnPlus->setIconeIndex( 2 );

//        m_btnMoins->setTexte ( "/\\");
//        m_btnPlus->setTexte ( "\\/");
        m_btnMoins->setTaille   ( { m_largeur , m_largeur} );
        m_btnMoins->setPosition ( 0 , 0  );

        m_slider->setVertical ();
        m_slider->setLongueur   (  m_longueur - 2*m_largeur );
        m_slider->setLargeur   ( m_largeur );
        m_slider->setPosition   ( 0, m_largeur  );

        m_btnPlus->setTaille   ( { m_largeur , m_largeur} );
        m_btnPlus->setPosition ( 0 , m_longueur - m_largeur  );

    }

    actualiserBounds();
    m_btnMoins->actualiserBounds();
    m_btnPlus->actualiserBounds();
    m_slider->actualiserBounds();

    if ( m_parent != nullptr ) m_parent->actualiserContenu();
}
*/

} // fin namespace gui

