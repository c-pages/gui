


GUI -> traiterEvenements( event ) { ---------------------------------------------------------

    ( I ) ON S OCCUPE DES EVENEMNTS DE LA SOURIS
    1) on enregistre le precedant bouton survolé


    2) on actualise notre bouton survolé
    m_btnSurvol = chercheBoutonSurvol ( x , y )


    3) en fonction du type d evenement :
        |
        |   A) event est BOUGE_SOURIS:
        |       |
        |       |   Si on a un bouton pressé, on change rien :
        |       |       |   SORTIR
        |       |
        |       |   si le bouton survolé à changé, on actualise :
        |       |       |   on actualise l ancien bouton survolé :      #survol
        |       |       |   on déclenche l ancien bouton survolé :      EVT_ENTRER
        |       |       |
        |       |       |   on actualise le nouveau bouton survolé :    #repos
        |       |       |   on déclenche l ancien bouton survolé :      EVT_SORTIR
        |
        |
        |   B) event est PRESSE_SOURIS:
        |   ( prendre en compte quel bouton est pressé (droite, gauche ou milieu) )
        |       |
        |       |   Si on a un bouton survolé :
        |       |       |   le bouton pressé est le bouton survolé.
        |       |       |
        |       |       |   on actualise le bouton survolé :            #presse
        |       |       |   on déclenche le bouton survolé :            EVT_PRESSE ( droite, gauche ou milieu )
        |       |       |
        |       |       |   on déclenche tout les autres bouton :       EVT_PRESSE_DEHORS ( droite, gauche ou milieu )
        |
        |
        |   C) event est RELACHE_SOURIS:
        |   ( prendre en compte quel bouton est pressé (droite, gauche ou milieu) )
        |       |
        |       |   Si on a pas de bouton survolé
        |       |   OU Si le bouton survolé est different du bouton pressé:
        |       |       |   on actualise le bouton pressé :             #repos
        |       |       |   on déclenche tout les boutons :             EVT_RELACHE_DEHORS ( droite, gauche ou milieu )
        |       |       |
        |       |   Sinon, on survol un bouton donc :
        |       |       |   on actualise le bouton survolé :            #survol
        |       |       |   on déclenche le bouton survolé :            EVT_RELACHE ( droite, gauche ou milieu )
        |       |       |
        |       |       |   on déclenche tout les autres boutons :      EVT_RELACHE_DEHORS ( droite, gauche ou milieu )
        |
        |
        |   D) event est ROULETTE_SOURIS:
        |       |
        |       |   Si on a un bouton survolé
        |       |       |   si ROULETTE vers le haut:
        |       |       |       |   on déclenche le bouton survolé  :   EVT_ROULETTE_HAUT
        |       |       |   si ROULETTE vers le Bas:
        |       |       |       |   on déclenche le bouton survolé  :   EVT_ROULETTE_BAS



    ( II ) ON S OCCUPE DES AUTRES EVENEMENTS

        1) On traite les evenements de tout les gadgets interactifs
        Pour gadget dans gadgetsInteractifs
                |   traiter les evenements du gadget



} ----------------------------------------------------------------------------------------








BOUTON -> actualiser( event ) { ---------------------------------------------------------

    1) on redessine le gadget en fonction de son nouvel etat

} ----------------------------------------------------------------------------------------
















gererEtats( event ) { ---------------------------------------------------------

    A)  les differents evenements possibles :
                |
            --- cas event est PRESSE : -----------------------------------------------------------------
                |
                |   1) On cherche un bouton survolé
                |   m_btnSurvol = chercheBoutonSurvol ( x , y )
                |
                |
                |   2) si m_btnSurvol n est pas vide
                |       |   etat du m_btnSurvol     => PRESSE
                |       |
                |       |   Demander une actualisation.
                |       sinon
                |
                |
            --- cas event est BOUGE : -----------------------------------------------------------------
                |
                |   1) Si un bouton est pressé ( m_btnPresse = un truc ) alors :
                |   Pas besoin de regarder le survol
                |       |   SORTIR
                |
                |
                |   2) On garde la trace du bouton survolé precedent :
                |   ancien_btnSurvol = m_btnSurvol.
                |
                |
                |   3) on cherche un bouton survolé:
                |   m_btnSurvol = chercheBoutonSurvol ( x , y )
                |
                |
                |   4) si ancien_btnSurvol != m_btnSurvol
                |       |   si l ancien bouton n est pas vide alors :
                |       |           |   etat de l ancien_btnSurvol      => REPOS
                |       |
                |       |   si le nouveau bouton n est pas vide alors :
                |       |           |   etat du nouveau m_btnSurvol     => SURVOL
                |       |
                |       |   Demander une actualisation.
                |
                |
            --- cas event est RELACHE : -----------------------------------------------------------------
                |
                |   1)  Si le btn_pressé est survolé :
                |       |   etat du nouveau m_btnSurvol                 => SURVOL
                |       sinon :
                |       |   etat du nouveau m_btnSurvol                 => REPOS
                |
                |       Demander une actualisation.
                |
            --- cas event est ROULE : -----------------------------------------------------------------
                |
                |   1)
                |
                |
            ----|-----


    B)  Si on a demandé une actualisation :
        |   on actualise!^^


} ----------------------------------------------------------------------------------------



ptr chercheBoutonSurvol ( x , y ) { ---------------------------------------------------------


        1) btn_resultat : le bouton resultat = vide


        2) on cherche le premier bouton survolé
        Pour chaque GADGET de la liste totale ( du plus haut au plus bas dans l ordre d affichage ) :
            |
            |   si la souris (x,y) le survol ET que c est un bouton (type::Bouton) alors :
            |       |   btn_resultat = ce gadget
            |       |   SORTIR


        3) on renvoie le bouton resultat ( vide si rien de survolé )


}   ----------------------------------------------------------------------------------------







actualiser ()  { ------------------------------------------------------------------------

    pour chaque GADGET ( du plus haut au plus bas dans l ordre d affichage )
    on gère l état puis la mise à jour :
        |   actualiser le gadget.

} -------------------------------------------------------------------------------------------












