/****************
 *-=screen.hpp=-*
 ****************
 
 Auteur : My?terious
 Description : Permet de gérer l'affichage
*/
#ifndef HEADER_VIDEO_SCREEN
#define HEADER_VIDEO_SCREEN

//-=Inclusion des headers=-//
#include <irrlicht.h>
#include "core/basemodule.hpp"
//-=Fin de la section=-//

namespace ohm
{
	namespace video
	{
		class Screen : public ohm::core::BaseModule
		{
			public:
			Screen(ohm::core::IrrlichtEngine* engine);
			~Screen();
			
			void render();
			
			//-=Fonctions de réglages=-//
			//--Rendu
			void setRenderUseBackBuffer(bool);
			void setRenderUseZBuffer(bool);
			void setRenderColor(irr::video::SColor);
			void setRenderIsWire(bool);
			void setRenderLighting(bool);
			void setRenderUseFog(bool);
			void setRenderFog(irr::video::SColor color, irr::video::E_FOG_TYPE fogType, irr::f32 start, irr::f32 stop, irr::f32 density, bool pixelFog, bool rangeFog);
			
			
			//--Général
			void setGeneralWindowCaption(wchar_t* text);
			void setGeneralCursorIsVisible(bool);
			
			//-=Fin de la section=-//

			private:
			bool _render_use_backBuffer;
			bool _render_use_ZBuffer;
			irr::video::SColor _render_color;
		};
	}
}

#endif
