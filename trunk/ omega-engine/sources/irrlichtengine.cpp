//-=Inclusion des headers=-//
#include "core/irrlichtengine.hpp"
//-=Fin de la section=-//

namespace ohm
{
	namespace core
	{
		IrrlichtEngine::IrrlichtEngine(irr::core::dimension2d<irr::u32> windowSize, irr::s32 bits, bool fullscreen, bool stencilBuffer, bool vsync)
		{
			//-=Initialisation du device=-//
			_device = irr::createDevice(irr::video::EDT_OPENGL, windowSize, bits, fullscreen, stencilBuffer, vsync);
			//-=Fin de la section=-//
			
			//-=Initialsiation des autres éléments=-//
			_driver = _device->getVideoDriver();
			_scene = _device->getSceneManager();
			_gui = _device->getGUIEnvironment();
			//-=Fin de la section=-//
		}
		
		IrrlichtEngine::~IrrlichtEngine()
		{
			_device->drop();
		}
		
		bool IrrlichtEngine::run() {return _device->run();}
			
		irr::IrrlichtDevice* IrrlichtEngine::getDevice() {return _device;}
		irr::video::IVideoDriver* IrrlichtEngine::getDriver() {return _driver;}
		irr::scene::ISceneManager* IrrlichtEngine::getScene() {return _scene;}
		irr::gui::IGUIEnvironment* IrrlichtEngine::getGUI() {return _gui;}
	}
}
