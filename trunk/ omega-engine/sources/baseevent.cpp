//-=Inclusion des headers=-//
#include "core/baseevent.hpp"
//-=Fin de la section=-//

namespace ohm
{
	namespace core
	{
		BaseEvent::BaseEvent(ohm::core::IrrlichtEngine* engine, bool setAsDefault)
		: BaseModule(engine)
		{
            if(setAsDefault)
                assign();
		}

		BaseEvent::~BaseEvent()
		{
		}

		void BaseEvent::assign()
		{
		    _engine->getDevice()->setEventReceiver(this);
		}

		bool BaseEvent::OnEvent(const irr::SEvent& event)
		{
			if(engineIsAppened())
			{
				//-=Contrôle des évènements pour le clavier=-//
				if(event.EventType == irr::EET_KEY_INPUT_EVENT)
				{
					if(event.KeyInput.PressedDown == true)
					{
						_keysPressed[event.KeyInput.Key] = true;
					}

					else
					{
						_keysPressed[event.KeyInput.Key] = false;
					}
				}

				else if(event.EventType == irr::EET_MOUSE_INPUT_EVENT)
				{
					if(event.MouseInput.isLeftPressed() == true)
					{
						_mouse_leftButton_isPressed = true;
					}

					else
					{
						_mouse_leftButton_isPressed = false;
					}

					if(event.MouseInput.isRightPressed() == true)
					{
						_mouse_rightButton_isPressed = true;
					}

					else
					{
						_mouse_rightButton_isPressed = false;
					}

					if(event.MouseInput.isMiddlePressed() == true)
					{
						_mouse_middleButton_isPressed = true;
					}

					else
					{
						_mouse_middleButton_isPressed = false;
					}
				}
				//-=Fin de la section=-//

				return false;
			}
		}

		//-=Fonctions d'état=-//
		bool BaseEvent::keyIsPressed(irr::EKEY_CODE key) {if(engineIsAppened()) return _keysPressed[key];}
		bool BaseEvent::mouseLeftButtonPressed() {if(engineIsAppened()) return _mouse_leftButton_isPressed;}
		bool BaseEvent::mouseRightButtonPressed() {if(engineIsAppened()) return _mouse_rightButton_isPressed;}
		bool BaseEvent::mouseMiddleButtonPressed() {if(engineIsAppened()) return _mouse_middleButton_isPressed;}
		bool BaseEvent::mouseIsMoved() {if(engineIsAppened()) return _mouse_isMoved;}
		irr::core::vector2d<irr::s32> BaseEvent::mousePosition() {return _engine->getDevice()->getCursorControl()->getPosition();}

		//-=Fin de la section=-//
	}
}
