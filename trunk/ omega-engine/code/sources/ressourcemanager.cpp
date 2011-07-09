//-=Inclusion des headers=-//
#include "media/ressourcemanager.hpp"
//-=Fin de la section=-//

namespace ohm
{
	namespace media
	{
		RessourceManager::RessourceManager(ohm::core::IrrlichtEngine* engine)
		: BaseModule(engine)
		{
		}

		RessourceManager::~RessourceManager()
		{
		}

		//-=Fonctions de chargement=-//
		irr::video::ITexture* RessourceManager::loadTexture(irr::io::path path) {if(engineIsAppened()) return _engine->getDriver()->getTexture(path);}
		irr::scene::IAnimatedMesh* RessourceManager::loadMesh(irr::io::path path) {if(engineIsAppened()) return _engine->getScene()->getMesh(path);}
		void RessourceManager::addFilesFromZip(irr::c8* path) {if(engineIsAppened()) _engine->getDevice()->getFileSystem()->addZipFileArchive(path);}
		void RessourceManager::addWorkingDir(irr::c8* path) {if(engineIsAppened()) _engine->getDevice()->getFileSystem()->addFolderFileArchive(path);}
		//-=Fin de la section=-//
	}
}
