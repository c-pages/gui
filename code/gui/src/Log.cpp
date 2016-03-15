#include "Log.h"
#include "Gadget.h"
#include "../patch.h"


namespace gui {

bool        Log::ms_debugLog = true;
std::string Log::ms_hierarchieBack = "";



/////////////////////////////////////////////////////
Log::Log()
: m_afficher_bureau                 ( true )
, m_afficher_panneau_G              ( true )
, m_afficher_panneau_D              ( true )
, m_afficher_bandeaux               ( true )
, m_afficher_bandeauMenuDeroulants  ( true )
, m_afficher_fenetres               ( true )
, m_afficher_menuDeroulants         ( true )
, m_afficher_souris                 ( false )
, m_afficher_GUI                    ( true )
, m_afficher_horsCalques            ( false )
{
    m_preLigne_hierarchie   = "";
    m_preLigne_courant      = "    ";
    m_preLigne_variable     = "";
    m_preLigne_interface    = "";
    m_ligneInterface        = "-";

    bool styleFondEnCouleur = true;

    if ( styleFondEnCouleur )
    {
          // version fond couleur qui fait deconner la console ... //
        m_couleur_calque    = /*BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | */BACKGROUND_INTENSITY /*|
                                FOREGROUND_GREEN | FOREGROUND_BLUE |  FOREGROUND_RED |  FOREGROUND_INTENSITY */;
        m_couleur_hierarchie    = /*BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED |*/ BACKGROUND_INTENSITY
                                | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED /*| FOREGROUND_INTENSITY*/  ;
        m_couleur_nomGadget     = /*BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | */BACKGROUND_INTENSITY
                                | FOREGROUND_GREEN | /*FOREGROUND_BLUE |*/ FOREGROUND_RED | FOREGROUND_INTENSITY  ;

        m_couleur_nomInterface  = BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED /*| BACKGROUND_INTENSITY */
                                | FOREGROUND_GREEN | /**/FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ;

        m_couleur_titre         = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;
        m_couleur_courant       = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED /*| FOREGROUND_INTENSITY*/;
        m_couleur_variable       = /*FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED|*/ FOREGROUND_INTENSITY;
        m_ligneInterface = " ";
    }

    else
    {

        // version fond noir qui fait pas deconner la console ... //
        m_couleur_calque    = /*BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY |
                               */ /*FOREGROUND_GREEN | FOREGROUND_BLUE |  FOREGROUND_RED | */ FOREGROUND_INTENSITY ;

        m_couleur_hierarchie    = /*BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY
                                | */FOREGROUND_GREEN | FOREGROUND_BLUE |  FOREGROUND_RED /*|FOREGROUND_INTENSITY */  ;
        m_couleur_nomGadget     = /*BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY
                                | */FOREGROUND_GREEN | /*FOREGROUND_BLUE |  */FOREGROUND_RED | FOREGROUND_INTENSITY ;

        m_couleur_nomInterface  = /*BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY
                                | */FOREGROUND_GREEN | /* */FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ;

        m_couleur_titre         = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;
        m_couleur_courant       = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED /*| FOREGROUND_INTENSITY*/;
        m_couleur_variable       = /*FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED|*/ FOREGROUND_INTENSITY;
    }

//
};


/////////////////////////////////////////////////
bool Log::checkAffichage()
{
    auto nomCalque = getCalqueGadget();

    if      ( nomCalque == "Bureau")    return m_afficher_bureau ;
    else if ( nomCalque == "Fenetres")  return m_afficher_fenetres ;
    else if ( nomCalque == "PanneauG")  return m_afficher_panneau_G ;
    else if ( nomCalque == "PanneauD")  return m_afficher_panneau_D ;
    else if ( nomCalque == "Bandeaux")  return m_afficher_bandeaux ;
    else if ( nomCalque == "BandeauMD") return m_afficher_bandeauMenuDeroulants ;
    else if ( nomCalque == "Menus")     return m_afficher_menuDeroulants ;
    else if ( nomCalque == "Souris")    return m_afficher_souris ;

    else if ( getNomGadget()  == "GUI") return m_afficher_GUI ;

    else return m_afficher_horsCalques;
}

/////////////////////////////////////////////////
std::string Log::getHierarchieGadget()
{
    return static_cast<Gadget*>(this)->getHierarchie();
};
/////////////////////////////////////////////////
std::string Log::getNomGadget()
{
    return static_cast<Gadget*>(this)->getNom();
};

/////////////////////////////////////////////////
std::string Log::getCalqueGadget()
{
    return static_cast<Gadget*>(this)->getCalqueNom();
};
/////////////////////////////////////////////////
bool    Log::estUnCalque()    {
    return ( static_cast<Gadget*>(this)->getNom()[0] == '_' );
};





/////////////////////////////////////////////////
void Log::checkGadget ( )
{
    if ( ! checkAffichage() ) return;


    int largeurMax = 77;
    int compteurCharac = 0;

    int posNomCalque = 60;
    int posNomGadget = 12;
    int posNomInterface = 12;

    std::string txtManip;
    std::string txtHierarchie = getHierarchieGadget()+ getNomGadget();


    if ( ms_hierarchieBack !=  txtHierarchie )
    {
        ms_hierarchieBack = txtHierarchie;



//        logOut (  "\n");

        // le nom du gadget
        if ( txtHierarchie == "GUI") {

            logOut (  "\n\n" );

            SetConsoleTextAttribute( m_console , m_couleur_nomInterface );

//            // ligne horizontale
//            for ( int i = 0; i< largeurMax; i++)  logOut (  "-" );
//            logOut (  "\n");


            for ( int i = compteurCharac; i< posNomInterface; i++) {
                logOut (  m_ligneInterface );
                compteurCharac ++;
            }
//            logOut (  "  " );
//            compteurCharac +=2;
        } else {
            /*
            // le decallage
            txtManip = m_preLigne_courant;
            compteurCharac += txtManip.size();
            logOut ( txtManip );
            */

            SetConsoleTextAttribute( m_console , m_couleur_calque );
            // On rejoind la pos du nom du gadget
            for ( int i = compteurCharac; i< posNomGadget; i++) {
                logOut (  m_ligneInterface );
                compteurCharac ++;
            }



            // on ecrit la hierarchie
            SetConsoleTextAttribute( m_console , m_couleur_hierarchie );
            txtManip = getHierarchieGadget();
            compteurCharac += txtManip.size();
            logOut ( txtManip );

            SetConsoleTextAttribute( m_console    , m_couleur_nomGadget  );
        }



        // le nom

        txtManip = getNomGadget() + " ";
        compteurCharac += txtManip.size();
        logOut ( txtManip );



        // le calque
        if ( getCalqueGadget() != "") {

            SetConsoleTextAttribute( m_console , m_couleur_calque );
            for ( int i = compteurCharac; i< posNomCalque; i++) {
                    logOut (  m_ligneInterface );
                    compteurCharac ++;
            }
            SetConsoleTextAttribute( m_console , m_couleur_calque );
            logOut("< ");
            compteurCharac+=2;

            // le nom du calsue
            SetConsoleTextAttribute( m_console , m_couleur_hierarchie );
            txtManip = m_preLigne_hierarchie + getCalqueGadget();
            compteurCharac += txtManip.size();
            logOut ( txtManip );


            SetConsoleTextAttribute( m_console , m_couleur_calque );
            logOut(" >");
            compteurCharac+=2;

        }


        // la fin de la ligne (pour un fond autre que noir)
        if ( txtHierarchie == "GUI") {
            SetConsoleTextAttribute( m_console , m_couleur_nomInterface );
            logOut (  " " );
            compteurCharac++;
            for ( int i = compteurCharac; i< largeurMax; i++) logOut (  m_ligneInterface );



//            // ligne horizontale
//            logOut (  "\n");
//            for ( int i = 0; i< largeurMax; i++)  logOut (  "-" );

        } else {
            SetConsoleTextAttribute( m_console , m_couleur_calque );

            for ( int i = compteurCharac; i< largeurMax ; i++) logOut (  m_ligneInterface );
            //for ( int i = compteurCharac; i< largeurMax; i++) logOut (  "-" );
        }


        logOut (  "\n");




//        if ( txtHierarchie == "GUI"){
//            for ( int i = 0; i< largeurMax; i++) logOut (  " " );
//            logOut("\n");
//        }
    }

}

/////////////////////////////////////////////////
void Log::logTitre ( std::string txt )
{
    if ( ! ms_debugLog || estUnCalque() ) return;
    if ( ! checkAffichage() ) return;

    // on regarde si on a changé de gadget
    checkGadget ( );

//    // decalage pour les textes du GUI
//    if ( getNomGadget() != "GUI") logOut ( "    " );


    SetConsoleTextAttribute( m_console , m_couleur_titre );
    std::string  preLigne = ( getNomGadget() == "GUI" ) ? m_preLigne_interface : m_preLigne_courant;
    logOut ( preLigne  +  txt  + "\n" );

}


/////////////////////////////////////////////////
void Log::log ( std::string txt )
{
    if ( ! ms_debugLog || estUnCalque() ) return;
    if ( ! checkAffichage() ) return;

    // on regarde si on a changé de gadget
    checkGadget ( );

    SetConsoleTextAttribute( m_console , m_couleur_courant );
    std::string  preLigne = ( getNomGadget() == "GUI" ) ? m_preLigne_interface : m_preLigne_courant;
    logOut ( preLigne + txt  + "\n" );

}


/////////////////////////////////////////////////
void Log::log (  std::string nomDuVariable , float variable )
{
    if ( ! ms_debugLog || estUnCalque() ) return;
    if ( ! checkAffichage() ) return;

    checkGadget ( );

    std::string valVar = patch::to_string(variable);

    SetConsoleTextAttribute( m_console , m_couleur_variable );

    std::string  preLigne = ( getNomGadget() == "GUI" ) ? m_preLigne_interface + m_preLigne_variable : m_preLigne_courant + m_preLigne_variable;
    logOut ( preLigne +  nomDuVariable + " = "  + valVar + "\n" );

}

/////////////////////////////////////////////////
void Log::log (  std::string nomDuVariable , sf::Vector2f variable ){
    log (  nomDuVariable , sf::Vector2i (variable) );
}

/////////////////////////////////////////////////
void Log::log (  std::string nomDuVariable , sf::Vector2i variable )
{
    if ( ! ms_debugLog || estUnCalque() ) return;
    if ( ! checkAffichage() ) return;

    checkGadget ( );

    std::string valVar1 = patch::to_string(variable.x);
    std::string valVar2 = patch::to_string(variable.y);

    SetConsoleTextAttribute( m_console , m_couleur_variable );


    std::string  preLigne = ( getNomGadget() == "GUI" ) ? m_preLigne_interface + m_preLigne_variable : m_preLigne_courant + m_preLigne_variable;
    logOut ( preLigne +  nomDuVariable + " = ( "  + valVar1 + " , "  + valVar2 + " )\n" );

}

/////////////////////////////////////////////////
void Log::log (  std::string nomDuVariable , std::string variable )
{
    if ( ! ms_debugLog || estUnCalque() ) return;
    if ( ! checkAffichage() ) return;

    checkGadget ( );

    SetConsoleTextAttribute( m_console , m_couleur_variable );

    std::string  preLigne = ( getNomGadget() == "GUI" ) ? m_preLigne_interface + m_preLigne_variable : m_preLigne_courant + m_preLigne_variable;
    logOut ( preLigne +  nomDuVariable + " = "  + variable + "\n" );

}

/////////////////////////////////////////////////
void Log::log (  std::string nomDuVariable , sf::Color couleur )
{
    if ( ! ms_debugLog || estUnCalque()  ) return;
    if ( ! checkAffichage() ) return;

    checkGadget ( );

    std::string valVar1 = patch::to_string(couleur.r);
    std::string valVar2 = patch::to_string(couleur.g);
    std::string valVar3 = patch::to_string(couleur.b);
    std::string valVar4 = patch::to_string(couleur.a);

    SetConsoleTextAttribute( m_console , m_couleur_variable );

    std::string  preLigne = ( getNomGadget() == "GUI" ) ? m_preLigne_interface + m_preLigne_variable : m_preLigne_courant + m_preLigne_variable;
    logOut ( preLigne +  nomDuVariable + " = "  + valVar1 + " "  + valVar2 + " "  + valVar3 + " "  + valVar4 + "\n" );

}

/////////////////////////////////////////////////
void Log::log (  std::string nomDuVariable , bool &variable )
{
    if ( ! ms_debugLog || estUnCalque()  ) return;
    if ( ! checkAffichage() ) return;

    checkGadget ( );

    std::string valVar1 = variable ? "true" : "false" ;

    SetConsoleTextAttribute( m_console , m_couleur_variable );


    std::string  preLigne = ( getNomGadget() == "GUI" ) ? m_preLigne_interface + m_preLigne_variable : m_preLigne_courant + m_preLigne_variable;
    logOut ( preLigne +  nomDuVariable + " = "  + valVar1 + "\n" );

}



} // fin namespace gui







































