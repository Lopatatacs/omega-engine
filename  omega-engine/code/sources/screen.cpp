//-=Inclusion des headers=-//
#include "video/screen.hpp"
//-=Fin de la section=-//

namespace ohm
{
	namespace video
	{
		Screen::Screen(ohm::core::IrrlichtEngine* engine)
		: BaseModule(engine)
		{
			if(engineIsAppened())
			{
				setRenderUseBackBuffer(true);
				setRenderUseZBuffer(true);
				setRenderColor(irr::video::SColor(255, 0, 0, 0));
				setGeneralWindowCaption(L"Omega Engine Application");
			}
		}

		Screen::~Screen()
		{
		}

		void Screen::render()
		{
			_engine->getDriver()->beginScene(_render_use_backBuffer, _render_use_ZBuffer, _render_color);
			_engine->getScene()->drawAll();
			_engine->getGUI()->drawAll();
			_engine->getDriver()->endScene();

		}

		//-=Fonctions de réglages=-//
		//--Rendu
		void Screen::setRenderUseBackBuffer(bool value)
		{
			if(engineIsAppened()) _render_use_backBuffer = value;
		}

		void Screen::setRenderUseZBuffer(bool value)
		{
			if(engineIsAppened()) _render_use_ZBuffer = value;
		}

		void Screen::setRenderColor(irr::video::SColor value)
		{
			if(engineIsAppened()) _render_color = value;
		}

		void Screen::setRenderIsWire(bool value)
		{
			if(engineIsAppened())
			{
				if(value)
				{
					_engine->getDriver()->getOverrideMaterial().EnableFlags = irr::video::EMF_WIREFRAME;
					_engine->getDriver()->getOverrideMaterial().Material.setFlag(irr::video::EMF_WIREFRAME, true);
					_engine->getDriver()->getOverrideMaterial().EnablePasses = irr::scene::ESNRP_SOLID;
				}

				else
				{
					_engine->getDriver()->getOverrideMaterial().Material.setFlag(irr::video::EMF_WIREFRAME, false);
				}
			}
		}

		void Screen::setRenderLighting(bool value)
		{
			if(engineIsAppened())
			{
				if(value)
				{
					_engine->getDriver()->getOverrideMaterial().EnableFlags = irr::video::EMF_LIGHTING;
					_engine->getDriver()->getOverrideMaterial().Material.setFlag(irr::video::EMF_LIGHTING, true);
					_engine->getDriver()->getOverrideMaterial().EnablePasses = irr::scene::ESNRP_SOLID;
				}

				else
				{
					_engine->getDriver()->getOverrideMaterial().Material.setFlag(irr::video::EMF_LIGHTING, false);
				}
			}
		}

		void Screen::setRenderUseFog(bool value)
		{
			if(engineIsAppened())
			{
				if(value)
				{
					_engine->getDriver()->getOverrideMaterial().EnableFlags = irr::video::EMF_FOG_ENABLE;
					_engine->getDriver()->getOverrideMaterial().Material.setFlag(irr::video::EMF_FOG_ENABLE, true);
					_engine->getDriver()->getOverrideMaterial().EnablePasses = irr::scene::ESNRP_SOLID;
				}

				else
				{
					_engine->getDriver()->getOverrideMaterial().Material.setFlag(irr::video::EMF_FOG_ENABLE, false);
				}
			}
		}

		void Screen::setRenderFog(irr::video::SColor color, irr::video::E_FOG_TYPE fogType, irr::f32 start, irr::f32 stop, irr::f32 density, bool pixelFog, bool rangeFog)
		{
			if(engineIsAppened()) _engine->getDriver()->setFog(color, fogType, start, stop, density, pixelFog, rangeFog);
		}



		//--Général
		void Screen::setGeneralWindowCaption(wchar_t* text)
		{
			if(engineIsAppened()) _engine->getDevice()->setWindowCaption(text);
		}

		void Screen::setGeneralCursorIsVisible(bool value)
		{
			if(engineIsAppened()) _engine->getDevice()->getCursorControl()->setVisible(value);
		}
		//-=Fin de la section=-//
	}
}
