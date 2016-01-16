#ifndef RESOURCEMGR__H
#define RESOURCEMGR__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <memory>
#include <map>



namespace gui {



/////////////////////////////////////////////////
/// \brief Manager de ressources (images, icones...)
///
/////////////////////////////////////////////////
template <typename RESOURCE, typename IDENTIFIANT = int>
class ResourceMgr {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ResourceMgr ();

    /////////////////////////////////////////////////
    /// \brief Charger une image ou une police depuis un fichier et l'associe à un identifiant. template<typename ... Args>
    ///
    /// \param id		 l'identenfiant unique.
    /// \param args		 Le fichier image.
    /////////////////////////////////////////////////
    void load (const IDENTIFIANT& id, Args&& ... args);

    RESOURCE& get (const IDENTIFIANT& id) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::unordered_map<IDENTIFIANT,std::unique_ptr<RESOURCE>>  m_plan;    ///< Les resources enregistrés avec leur identifiant unique.

}; // fin class ResourceMgr

} // fin namespace gui

#endif
