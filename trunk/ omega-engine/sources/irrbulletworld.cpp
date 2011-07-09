//-=Inclusion des headers=-//
#include "physics/irrbulletengine.hpp"
//-=Fin de la section=-//

namespace ohm
{
	namespace physics
	{
		IrrBulletEngine::IrrBulletEngine(ohm::core::IrrlichtEngine* engine)
		{
			_world = createIrrBulletWorld(_engine->getDevice(), true, false);
			_world->setGravity(irr::core::vector3df(0, -20, 0));
			
			irr::u32 TimeStamp = _engine->getDevice()->getTimer()->getTime();
			irr::u32 DeltaTime = 0;
		}
		
		IrrBulletEngine::~IrrBulletEngine()
		{
		}
			
		void IrrBulletEngine::update()
		{
			DeltaTime = _engine->getDevice()->getTimer()->getTime() - TimeStamp;
			TimeStamp = _engine->getDevice()->getTimer()->getTime();
			
			_world->stepSimulation(DeltaTime * 0.001f, 120);
		}
			
		IrrBulletWorld* IrrBulletEngine::getWorld() {return _world;}
	}
}