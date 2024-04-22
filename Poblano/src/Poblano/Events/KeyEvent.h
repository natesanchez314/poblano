#pragma once

#include "Event.h"

#include <sstream>

namespace Poblano
{
	class POBLANO_API KeyEvent : public Event
	{
	public:
		inline int getKeyCode() const { return m_KeyCode; }
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_KEYBOARD | EVENT_CATEGORY_INPUT)
	protected:
		KeyEvent(int keycode)
			: keyCode(keycode) 
		{}

		int keyCode;
	};

	class POBLANO_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount)
		{}
		
		inline int getRepeatCount() const { return m_RepeatCount; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << "repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(kEY_PRESSED)
	private:
		int repeatCount;
	};

	class POBLANO_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode)
			: KeyEvent(keyCode)
		{}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KEY_RELEASED)
	};
}