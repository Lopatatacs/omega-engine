/********************
 *-=basemodule.hpp=-*
 ********************
 
 Auteur : My?terious
 Description : Classe qui est héritée par une grande majoritée d'autres classes. Elle permet en fait un accès facile à l'engine.
*/
#ifndef HEADER_CORE_BASEMODULE
#define HEADER_CORE_BASEMODULE

//-=Inclusion des headers=-//
#include <irrlicht.h>
#include "core/irrlichtengine.hpp"
//-=Fin de la section=-//

namespace ohm
{
	namespace core
	{
		class BaseModule
		{
			public:
			BaseModule(ohm::core::IrrlichtEngine* engine);
			~BaseModule();
			
			void setEngine(ohm::core::IrrlichtEngine* newEngine);
			void clearEngine();
			ohm::core::IrrlichtEngine* getEngine();
			
			protected:
			bool engineIsAppened();
			
			ohm::core::IrrlichtEngine* _engine;
		};
	}
}


#endif
