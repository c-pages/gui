/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <DnZoneTexte.h>
#include <Interface.h>


#include <string>

namespace gui {

/////////////////////////////////////////////////
DnZoneTexte::DnZoneTexte ()
: m_bouton  ( std::make_shared<BtnRectangle>() )
, m_curseur ( std::make_shared<AffRectangle>() )
, m_label   ( std::make_shared<AffLabel>() )
, m_ecritureActive  ( false )
, m_numerique       ( false )
{
    // initialiser
    m_taille.x = 180;
    m_taille.y = 20;

    m_marge.x = 2;
    m_marge.y = 5;

    ajouterComposant( m_bouton );
    ajouterComposant( m_label );
    ajouterComposant( m_curseur );

/*
    m_label->setTexte   ( m_texte );
    m_curseur->setTaille( { 2, 15 });
    m_bouton->setTaille ( m_taille );

*/
    // valeurs par defaut
    m_btnCouleurs.set       ( sf::Color( 0, 0, 0, 50 )     , Etat::desactive );
    m_btnCouleurs.set       ( sf::Color( 255,255,255, 0 ) , Etat::repos );
    m_btnCouleurs.set       ( sf::Color( 255,255,255, 20 ) , Etat::survol );
    m_btnCouleurs.set       ( sf::Color( 255,255,255, 40 ) , Etat::press );
    m_btnLgnCouleurs.set    ( sf::Color( 255,255,255, 20 ) );
    m_btnLgnepaisseurs.set  ( 1 );

    m_curseurCouleurs          = sf::Color(255,255,255,200) ;
    m_curseurCouleurs.set      ( sf::Color( 70, 70, 70 )  , Etat::desactive );
    m_curseurLgnCouleurs       = sf::Color( 255,255,0, 255 ) ;
    m_curseurLgnepaisseurs     = 0 ;

    m_textCouleur = sf::Color::White ;
    m_textTaille =  10  ;
    m_textPolice = Interface::ms_polices.get( "Defaut" )  ;
    m_textStyle = sf::Text::Style::Regular  ;



    // Declaration des fonctions de fonctionnement de l'interface interne du gadget.
    fn_valider = [this](){
        if ( m_ecritureActive ){
            setModeEcritureActif ( false );
            m_texte = m_valeur = m_label->getTexte() ;
            actualiser ();
            declencher( Evenement::on_valeurValide);
        }
    };
    fn_sortir = [this](){
        if ( m_ecritureActive ){
            setModeEcritureActif ( false );
            m_label->setTexte ( m_texte );
            actualiser ();
        }
    };
    fn_cliqueTexte = [this](){
        std::cout << "Clique zone de texte\n";
        if ( m_ecritureActive ){}
            // on place le curseur là où on a cliqué.(todo)
        else {
            // on active la saisie clavier
            setModeEcritureActif ( true ) ;
            actualiser ();
        }
    };


    // Action du bouton
    m_bouton->lier ( Evenement::onBtnG_relacher , fn_cliqueTexte );
    m_bouton->lier ( Evenement::onBtnG_relacherDehors , fn_valider );
    m_bouton->lier ( Evenement::onBtnD_relacherDehors , fn_sortir );

    m_bouton->lier ( Evenement::onBtnM_roulerHaut , [this](){ declencher ( Evenement::onBtnM_roulerHaut ) ;} );
    m_bouton->lier ( Evenement::onBtnM_roulerBas , [this](){ declencher ( Evenement::onBtnM_roulerBas ) ;} );
    actualiser ();

}

/////////////////////////////////////////////////
std::shared_ptr<Gadget>  DnZoneTexte::testerSurvol ( sf::Vector2i position )
{
    if ( m_globalBounds.contains( { position.x , position.y } ) )
        return m_bouton;

    return nullptr;
}

/////////////////////////////////////////////////
void DnZoneTexte::actualiserGeometrie ()
{
    m_bouton->setTaille ( m_taille );
    m_label->setPosition    ( m_marge.x , m_marge.y/2);

//    sf::Vector2f pos = m_label->getSFTexte()->findCharacterPos 	(  m_label->getTexte().size() ) ;
    sf::Vector2f pos = m_label->getSFTexte().findCharacterPos 	(  m_label->getTexte().size() ) ;

    m_curseur->setPosition ( pos.x , pos.y );
    m_curseur->move( 5 , m_marge.y/2 );
    m_curseur->setTaille( { 2, 15 });

    // actualiser
    if ( m_parent != nullptr ) m_parent->actualiserContenu();
}


/////////////////////////////////////////////////
void DnZoneTexte::actualiserStyle ()
{
    m_bouton->setFondCouleur (    m_btnCouleurs ) ;
    m_bouton->setLigneCouleur (    m_btnLgnCouleurs  ) ;
    m_bouton->setLigneEpaisseur ( m_btnLgnepaisseurs  );

    if ( ! m_ecritureActive ) {
        m_curseur->setFondCouleur ( m_curseurCouleurs.desactive  );
        m_curseur->setLigneCouleur (  m_curseurLgnCouleurs.desactive );
        m_curseur->setLigneEpaisseur ( m_curseurLgnepaisseurs.desactive  );
    } else {
        m_curseur->setFondCouleur ( m_curseurCouleurs.press );
        m_curseur->setLigneCouleur (  m_curseurLgnCouleurs.press);
        m_curseur->setLigneEpaisseur ( m_curseurLgnepaisseurs.press );
    }

    m_label->setCouleur    ( sf::Color (   m_textCouleur.r
                                            ,   m_textCouleur.g
                                            ,   m_textCouleur.b
                                            ,   m_textCouleur.a * m_opacite ) ) ;
    m_label->setTailleCharac     ( m_textTaille ) ;
    m_label->setTextePolice          ( m_textPolice ) ;
    m_label->setTexteStyle      ( m_textStyle ) ;

    if ( m_parent != nullptr ) m_parent->actualiserContenu();
}



/////////////////////////////////////////////////
void DnZoneTexte::traiterEvenements(const sf::Event& evenement ){

    // gestion de la saisie de texte
    if ( m_ecritureActive
    and  evenement.type == sf::Event::TextEntered
        /* and  event.text.unicode < 128*/ ) {



        std::cout << " (event.text.unicode)  : " << (evenement.text.unicode)  << "\n";

        // le texte avant modif dans le label
        std::string txt = m_label->getTexte() ;

        // touche Retour arriere : effacer arriere  //////////////////////////////
        if ( evenement.text.unicode == 8 )  {
            // si le champ est vide on retourne.
            if ( txt.size()==0 ) return;

            // sinon on retire une lettre et on declenche l'action
            txt.erase ( txt.size()-1 , 1);
            m_label->setTexte( txt  );
            declencher( Evenement::on_valeurChange );
        }

        // touche Entrée : Valider  //////////////////////////////
        else if ( evenement.text.unicode == 13 )  {
//            m_btn->setCoche( false);
            setModeEcritureActif ( false ) ;
            m_texte = m_valeur = txt;
//            m_texte = m_valeur;
            m_label->setTexte       ( m_texte ) ;
           declencher( Evenement::on_valeurValide );
        }

        // touche Echappe : Annuler  //////////////////////////////
        else if ( evenement.text.unicode == 27 )  {
//            m_label->setTexte( m_texteBack  );
//            m_btn->setCoche( false);
            setModeEcritureActif ( false ) ;
            m_label->setTexte    ( m_texte ) ;
            declencher( Evenement::on_valeurChange );
        }

        // les autres touches  //////////////////////////////
        else {
            if ( m_numerique ){
                if ( evenement.text.unicode >= 46 && evenement.text.unicode <= 57 ){
                    m_label->setTexte( txt + static_cast<char>(evenement.text.unicode)  );
                    declencher( Evenement::on_valeurChange );
                }
            } else  {
                m_label->setTexte( txt + static_cast<char>(evenement.text.unicode)  );
                declencher( Evenement::on_valeurChange );
            }

            // s'il ne reste plus de place pour ecrire on retourne
//            float largeurTexte = m_label->getSFTexte()->findCharacterPos 	(  m_label->getTexte().size() ).x;
//            if ( largeurTexte > m_btn->getSize().x - 1 )
//                m_label->setTexte( txt );


            // on déclenche et on ecrit.
//            declencher( onCha_ChangeValeur );
        }
actualiser ();
/*
        // clock pour clignotements du curseur
        m_timerClignot.restart();
        m_clignot = true;

        // et on demande une mise a jour du gadget.
        demanderActualisation();*/
    }


}






/////////////////////////////////////////////////
void DnZoneTexte::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    //On applique la transformation
    states.transform *= getTransform();

    // On dessine les éléments
    target.draw( *m_bouton, states );
    target.draw( *m_label, states );

    if ( m_ecritureActive )
        target.draw( *m_curseur, states );


}


} // fin namespace gui

