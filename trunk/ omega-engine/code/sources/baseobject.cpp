//-=Inclusion des headers=-//
#include "scene/baseobject.hpp"
//-=Fin de la section=-//

namespace  ohm
{
	namespace scene
	{
		BaseObject::BaseObject(ohm::core::IrrlichtEngine* engine, irr::scene::ISceneNode* parent, irr::core::vector3df position, irr::core::vector3df rotation, irr::core::vector3df scale, irr::core::stringc name, irr::s32 id)
		: BaseModule(engine),
		  ISceneNode(parent, engine->getScene(), id, position, rotation, scale)
		{
			setName(name);
		}
		
		BaseObject::~BaseObject()
		{
		}
			
		void BaseObject::OnRegisterSceneNode()
		{
			if(engineIsAppened())
			{
				if (IsVisible)
					SceneManager->registerNodeForRendering(this);

				ISceneNode::OnRegisterSceneNode();
			}
		}
		
		void BaseObject::render()
		{
		}
		
		irr::core::aabbox3d<irr::f32> BaseObject::getBoundingBox()
		{
			if(engineIsAppened()) return _bbox;
		}
	}
}