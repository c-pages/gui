#include "DnZoneNum.h"
#include "DnZoneTexte.h"
#include "BtnIcone.h"

#include "Interface.h"

namespace gui {


/////////////////////////////////////////////////
DnZoneNum::DnZoneNum()
: m_zoneTexte       ( std::make_shared<DnZoneTexte>() )
, m_btnPlus         ( std::make_shared<BtnIcone>() )
, m_btnMoins        ( std::make_shared<BtnIcone>() )
//, m_tailleBoutons   ( {  ,  } )
{
    m_taille = { 180 , 20 };

    ajouterComposant ( m_zoneTexte );
    ajouterComposant ( m_btnPlus );
    ajouterComposant ( m_btnMoins );

    m_btnPlus->setImage( &Interface::ms_icones.get( "ico_fleches" ) ) ;
    m_btnMoins->setImage( &Interface::ms_icones.get( "ico_fleches" ) ) ;
    m_btnMoins->setIconeIndex ( 2 );

    m_zoneTexte->setNumerique (  true );

    auto fct_plus = [this]()  {
        std::cout << " Valeur plus !!!!! : " << m_valeur << "\n";
        m_valeur = m_valeur + m_pas;
        std::cout << " apres : " << m_valeur << "\n";
        if ( m_valeur > m_max ) m_valeur = m_max;
        m_zoneTexte->setTexte ( patch::to_string( m_valeur ) );
        std::cout << " m_pas : " << m_pas << "\n";
    };
    auto fct_moins = [this]()  {
        std::cout << " Valeur moins !!!!!\n";
        m_valeur -= m_pas;
        if ( m_valeur < m_min ) m_valeur = m_min;
        m_zoneTexte->setTexte ( patch::to_string( m_valeur ) );
    };



    m_btnPlus->lier     ( Evenement::onBtnG_relacher , fct_plus );
    m_btnPlus->lier     ( Evenement::onBtnM_roulerHaut , fct_plus );
    m_btnPlus->lier     ( Evenement::onBtnM_roulerBas , fct_moins );
    m_btnMoins->lier    ( Evenement::onBtnG_relacher , fct_moins );
    m_btnMoins->lier     ( Evenement::onBtnM_roulerHaut , fct_plus );
    m_btnMoins->lier     ( Evenement::onBtnM_roulerBas , fct_moins );

    auto fct_valeurChange = [this]()  {
    };
    auto fct_valeurValide = [this]()  {
        std::cout << " Valeur valide !!!!! : " << m_zoneTexte->getValeur() << "\n";
        m_valeur = patch::to_float( m_zoneTexte->getValeur() ) ;
        std::cout << " m_valeur : " << m_valeur << "\n";
        if ( m_valeur > m_max ) m_valeur = m_max;
        if ( m_valeur < m_min ) m_valeur = m_min;
        m_zoneTexte->setTexte ( patch::to_string( m_valeur ) );
    };

    m_zoneTexte->lier ( Evenement::on_valeurChange , fct_valeurChange );
    m_zoneTexte->lier ( Evenement::on_valeurValide , fct_valeurValide );

    m_zoneTexte->lier ( Evenement::onBtnM_roulerHaut , fct_plus );
    m_zoneTexte->lier ( Evenement::onBtnM_roulerBas , fct_moins );





}



/////////////////////////////////////////////////
void DnZoneNum::actualiserGeometrie ()
{
    m_btnPlus->setTaille    ( { m_taille.y , m_taille.y/2 } );
    m_btnPlus->setPosition  ( m_taille.x - m_taille.y + m_marge.x, m_marge.y );

    m_btnMoins->setTaille   ( { m_taille.y , m_taille.y/2 } );
    m_btnMoins->setPosition ( m_taille.x - m_taille.y + m_marge.x, m_marge.y + m_taille.y/2 );

    m_zoneTexte->setTaille  ( { m_taille.x - m_taille.y , m_taille.y } );
    m_zoneTexte->setPosition(  m_marge.x  , m_marge.y );

    m_zoneTexte->setTexte ( patch::to_string( m_valeur ) );
}

/////////////////////////////////////////////////
void DnZoneNum::actualiserStyle ()
{}

/////////////////////////////////////////////////
void DnZoneNum::traiterEvenements (const sf::Event& evenement)
{
    m_zoneTexte->traiterEvenements ( evenement);
}

}; // fin namesapce gui




















