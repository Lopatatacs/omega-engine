/************************
 *-=irrlichtengine.hpp=-*
 ************************
 
 Auteur : My?terious
 Descripition : IrrlichtEngine est la classe qui contient les éléments principaux d'IrrlichtEngine.
*/
#ifndef HEADER_CORE_IRRLICHTENGINE
#define HEADER_CORE_IRRLICHTENGINE

//-=Inclusion des headers=-//
#include <irrlicht.h>
//-=Fin de la section=-//

namespace ohm
{
	namespace core
	{
		class IrrlichtEngine
		{
			public:
			IrrlichtEngine(irr::core::dimension2d<irr::u32> windowSize = irr::core::dimension2d<irr::u32>(800, 600), irr::s32 bits = 32, bool fullscreen = false, bool stencilBuffer = true, bool vsync = false);
			~IrrlichtEngine();
			
			bool run();
			
			irr::IrrlichtDevice* getDevice();
			irr::video::IVideoDriver* getDriver();
			irr::scene::ISceneManager* getScene();
			irr::gui::IGUIEnvironment* getGUI();
			
			private:
			irr::IrrlichtDevice* _device;
			irr::video::IVideoDriver* _driver;
			irr::scene::ISceneManager* _scene;
			irr::gui::IGUIEnvironment *_gui;
		};
	}
}

#endif
