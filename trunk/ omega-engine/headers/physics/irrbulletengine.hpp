/*************************
 *-=irrbulletengine.hpp=-*
 *************************
 
 Auteur : My?terious
 Description : Module qui permet d'intégrer le wrapper Bullet Physics "IrrBullet" à ohmengine.
*/
#ifndef HEADER_PHYSICS_IRRBULLETENGINE
#define HEADER_PHYSICS_IRRBULLETENGINE

//-=Inclusion des headers=-//
#include <irrlicht.h>
#include <irrBullet.h>

#include "core/basemodule.hpp"
//-=Fin de la section=-//

namespace ohm
{
	namespace physics
	{
		class IrrBulletEngine : public ohm::core::BaseModule
		{
			public:
			IrrBulletEngine(ohm::core::IrrlichtEngine* engine);
			~IrrBulletEngine();
			
			void update();
			
			IrrBulletWorld* getWorld();
			
			private:
			IrrBulletWorld* _world;
		};
	}
}

#endif