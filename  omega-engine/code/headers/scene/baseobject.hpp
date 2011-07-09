/********************
 *-=baseobject.hpp=-*
 ********************

 Auteur : My?terious
 Description : Contient la base pour créer un objet.
*/
#ifndef HEADER_SCENE_BASEOBJECT
#define HEADER_SCENE_BASEOBJECT

//-=Inclusion des headers=-//
#include <irrlicht.h>
#include "core/basemodule.hpp"
//-=Fin de la section=-//

namespace ohm
{
	namespace scene
	{
		class BaseObject : public ohm::core::BaseModule, public irr::scene::ISceneNode
		{
			public:
			BaseObject(ohm::core::IrrlichtEngine* engine, irr::scene::ISceneNode* parent, irr::core::vector3df position,
						irr::core::vector3df rotation, irr::core::vector3df scale, irr::core::stringc name, irr::s32 id);
			virtual ~BaseObject();

			virtual void OnRegisterSceneNode();
			virtual void render();

			virtual irr::core::aabbox3d<irr::f32> getBoundingBox();

			private:
			irr::core::aabbox3d<irr::f32> _bbox;
		};
	}
}

#endif
