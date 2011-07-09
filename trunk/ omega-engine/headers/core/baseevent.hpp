/*******************
 *-=baseevent.hpp=-*
 *******************
 Auteur : My?terious
 Description : Classe pour gérer les évènements
*/
#ifndef HEADER_CORE_BASEEVENT
#define HEADER_CORE_BASEEVENT

//-=Inclusion desheaders=-//
#include <irrlicht.h>
#include <map>
#include "core/basemodule.hpp"
//-=Fin de la section=-//

namespace ohm
{
	namespace core
	{
		class BaseEvent : public ohm::core::BaseModule, public irr::IEventReceiver
		{
			public:
			BaseEvent(ohm::core::IrrlichtEngine* engine, bool setAsDefault = false);
			~BaseEvent();

			virtual bool OnEvent(const irr::SEvent&);

			void assign();

			//-=Fonctions d'état=-//
			bool keyIsPressed(irr::EKEY_CODE);
			bool mouseLeftButtonPressed();
			bool mouseRightButtonPressed();
			bool mouseMiddleButtonPressed();
			bool mouseIsMoved();
			irr::core::position2d<irr::s32> mousePosition();
			//-=Fin de la section=-//

			protected:
			std::map<irr::EKEY_CODE, bool> _keysPressed;
			bool _mouse_leftButton_isPressed;
			bool _mouse_rightButton_isPressed;
			bool _mouse_middleButton_isPressed;
			bool _mouse_isMoved;
		};
	}
}

#endif
