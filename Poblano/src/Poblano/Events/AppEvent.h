#pragma once

#include "Event.h"

#include <sstream>

namespace Poblano
{
	class POBLANO_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: width(width), height(height)
		{}

		inline unsigned int getWidth() { return width; }
		inline unsigned int getHeight() { return height; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << width << ", " << height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WINDOW_RESIZE)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APP)
	private:
		unsigned int width, height;
	};

	class POBLANO_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent()
		{}

		EVENT_CLASS_TYPE(WINDOW_CLOSE)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APP)
	};

	class POBLANO_API AppTickEvent : public Event
	{
	public:
		AppTickEvent()
		{}

		EVENT_CLASS_TYPE(APP_TICK)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APP)
	};

	class POBLANO_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent()
		{}

		EVENT_CLASS_TYPE(APP_UPDATE)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APP)
	};

	class POBLANO_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent()
		{}

		EVENT_CLASS_TYPE(APP_RENDER)
			EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APP)
	};
}