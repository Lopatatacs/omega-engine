/**************************
 *-=ressourcemanager.hpp=-*
 **************************
 
 Auteur : My?terious
 Description : gère les ressources du programme.
*/
#ifndef HEADER_MEDIA_RESSOURCEMANAGER
#define HEADER_MEDIA_RESSOURCEMANAGER

//-=Inclusion des headers=-//
#include <irrlicht.h>
#include "core/basemodule.hpp"
//-=Fin de la section=-//

namespace ohm
{
	namespace media
	{	
		class RessourceManager : public ohm::core::BaseModule
		{
			public:
			RessourceManager(ohm::core::IrrlichtEngine* engine);
			~RessourceManager();
			
			//-=Fonctions de chargement=-//
			irr::video::ITexture* loadTexture(irr::io::path);
			irr::scene::IAnimatedMesh* loadMesh(irr::io::path);
			void addFilesFromZip(irr::c8*);
			void addWorkingDir(irr::c8*);
			//-=Fin de la section=-//
		};
	}
}

#endif
