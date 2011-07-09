//-=Inclusion des headers=-//
#include "core/basemodule.hpp"
//-=Fin de la section=-//

namespace ohm
{
	namespace core
	{
		BaseModule::BaseModule(ohm::core::IrrlichtEngine* engine)
		{
			setEngine(engine);
		}
		
		BaseModule::~BaseModule()
		{
			clearEngine();
		}
					
		void BaseModule::setEngine(ohm::core::IrrlichtEngine* newEngine) {_engine = newEngine;}
		void BaseModule::clearEngine() {_engine = NULL;}
		ohm::core::IrrlichtEngine* BaseModule::getEngine() {return _engine;}
		
		bool BaseModule::engineIsAppened()
		{
			if(_engine != NULL)
			{
				return true;
			}
			
			else
				return false;
		}
	}
}
