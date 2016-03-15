#include "Log.h"
#include "Gadget.h"
#include "../patch.h"


namespace gui {

bool        Log::ms_debugLog = true;
std::string Log::ms_hierarchieBack = "";


/////////////////////////////////////////////////////
Log::Log()
{
    m_preLigne_hierarchie   = "";
    m_preLigne_courant      = "    ";
    m_preLigne_variable     = "        ";

//    m_couleur_hierarchie    = /*BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED |*/ BACKGROUND_INTENSITY;
//    m_couleur_nomGadget     = /*BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | */BACKGROUND_INTENSITY
//                            | FOREGROUND_GREEN | /*FOREGROUND_BLUE |*/ FOREGROUND_RED | FOREGROUND_INTENSITY  ;
//
//    m_couleur_nomInterface  = BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED /*| BACKGROUND_INTENSITY */
//                            | FOREGROUND_GREEN | /*FOREGROUND_BLUE |*/ FOREGROUND_RED | FOREGROUND_INTENSITY ;
//
//    m_couleur_titre         = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;
//    m_couleur_courant       = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED /*| FOREGROUND_INTENSITY*/;
//    m_couleur_variable       = /*FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED|*/ FOREGROUND_INTENSITY;


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


};

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
    int largeurMax = 77;

    int posNomCalque = 60;
    int posNomGadget = 10;
    int posNomInterface = 10;


    int compteurCharac = 0;
//    int compteurPosNomCalque = 0;
//    int compteurPosNomGadget = 0;
//    int compteurPosNomInterface = 0;


    std::string txtManip="";
    std::string txtHierarchie = getHierarchieGadget();
    txtHierarchie += getNomGadget();

    if ( ms_hierarchieBack !=  txtHierarchie )
    {
        ms_hierarchieBack = txtHierarchie;
//        compteurCharac = ms_hierarchieBack.size();

        logOut (  "\n");





        // le nom du gadget
        if ( txtHierarchie == "GUI") {

            SetConsoleTextAttribute( m_console , m_couleur_nomInterface );
            for ( int i = compteurCharac; i< posNomInterface; i++) {
                logOut (  "-" );
                compteurCharac ++;
            }
            logOut (  "  " );
            compteurCharac +=2;
        } else {


            SetConsoleTextAttribute( m_console , m_couleur_calque );
            // On rejoind la pos du nom du gadget
            for ( int i = compteurCharac; i< posNomGadget; i++) {
                logOut (  "-" );
                compteurCharac ++;
            }



            // on ecrit la hierarchie
            SetConsoleTextAttribute( m_console , m_couleur_hierarchie );
            txtManip = " " + getHierarchieGadget();
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
                    logOut (  "-" );
                    compteurCharac ++;
            }
            SetConsoleTextAttribute( m_console , m_couleur_calque );
            logOut("< ");
            compteurCharac+=2;


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
            for ( int i = compteurCharac; i< largeurMax; i++) logOut (  "-" );
        } else {
            SetConsoleTextAttribute( m_console , m_couleur_calque );
            compteurCharac++;
            for ( int i = compteurCharac; i< largeurMax ; i++) logOut (  "-" );
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

    // on regarde si on a changé de gadget
    checkGadget ( );

    SetConsoleTextAttribute( m_console , m_couleur_titre );
    logOut ( m_preLigne_courant + txt  + "\n" );

}


/////////////////////////////////////////////////
void Log::log ( std::string txt )
{
    if ( ! ms_debugLog || estUnCalque() ) return;

    // on regarde si on a changé de gadget
    checkGadget ( );

    SetConsoleTextAttribute( m_console , m_couleur_courant );
    logOut ( m_preLigne_courant + txt  + "\n" );

}


/////////////////////////////////////////////////
void Log::log (  std::string nomDuVariable , float variable )
{
    if ( ! ms_debugLog || estUnCalque() ) return;

    checkGadget ( );

    std::string valVar = patch::to_string(variable);

    SetConsoleTextAttribute( m_console , m_couleur_variable );

    logOut ( m_preLigne_variable + nomDuVariable + " = "  + valVar + "\n" );

}

/////////////////////////////////////////////////
void Log::log (  std::string nomDuVariable , sf::Vector2f variable ){
    log (  nomDuVariable , sf::Vector2i (variable) );
}

/////////////////////////////////////////////////
void Log::log (  std::string nomDuVariable , sf::Vector2i variable )
{
    if ( ! ms_debugLog || estUnCalque() ) return;

    checkGadget ( );

    std::string valVar1 = patch::to_string(variable.x);
    std::string valVar2 = patch::to_string(variable.y);

    SetConsoleTextAttribute( m_console , m_couleur_variable );

    logOut ( m_preLigne_variable + nomDuVariable + " = ( "  + valVar1 + " , "  + valVar2 + " )\n" );

}

/////////////////////////////////////////////////
void Log::log (  std::string nomDuVariable , std::string variable )
{
    if ( ! ms_debugLog || estUnCalque() ) return;

    checkGadget ( );

    SetConsoleTextAttribute( m_console , m_couleur_variable );

    logOut ( m_preLigne_variable + nomDuVariable + " = "  + variable + "\n" );

}

/////////////////////////////////////////////////
void Log::log (  std::string nomDuVariable , sf::Color couleur )
{
    if ( ms_debugLog ) return;

    checkGadget ( );

    std::string valVar1 = patch::to_string(couleur.r);
    std::string valVar2 = patch::to_string(couleur.g);
    std::string valVar3 = patch::to_string(couleur.b);
    std::string valVar4 = patch::to_string(couleur.a);

    SetConsoleTextAttribute( m_console , m_couleur_variable );

    logOut ( m_preLigne_variable + nomDuVariable + " = "  + valVar1 + " "  + valVar2 + " "  + valVar3 + " "  + valVar4 + "\n" );

}



} // fin namespace gui
