#include "__Mouse.h"

void __Mouse::SetPosition(float x, float y)
{
	this->Position.x = x;
	this->Position.y = y;
}

bool __Mouse::GetEvent(int M)
{
	switch (M)
	{
	case LMButtonClick:return MouseState.LMButtonClick; break;
	case LMButtonRelease:return MouseState.LMButtonRelease; break;
	case RMButtonClick:return MouseState.RMButtonClick; break;
	case RMButtonRelease:return MouseState.RMButtonRelease; break;
	case LMbuttonDoubbleClick:return MouseState.LMbuttonDoubleClick; break;
	case RMButtonDoubleClick:return MouseState.RMButtonDoubleClick; break;
	case MWHeelUp:return MouseState.MWHeelUp; break;
	case MWheelDown:return MouseState.MWheelDown; break;

	};
}

void __Mouse::LMButtonIsPressed(float x, float y)
{
	this->Position.x = x;
	this->Position.y = y;
	MouseState.LMButtonClick = true;
	MouseState.LMButtonRelease = false;
}

void __Mouse::LMButtonIsReleased(float x, float y)
{
	this->Position.x = x;
	this->Position.y = y;
	MouseState.LMButtonClick = false;
	MouseState.LMButtonRelease = true;
}

void __Mouse::RMButtonIsPressed(float x, float y)
{
	this->Position.x = x;
	this->Position.y = y;
	MouseState.RMButtonClick = true;
	MouseState.RMButtonRelease = false;
}

void __Mouse::RMButtonIsReleased(float x, float y)
{
	this->Position.x = x;
	this->Position.y = y;
	MouseState.RMButtonClick = false;
	MouseState.RMButtonRelease = true;
}

void __Mouse::MouseMove(float x, float y)
{
	this->Position.x = x;
	this->Position.y = y;
	
}

void __Mouse::RMButtonDBClick(float x, float y)
{
	this->Position.x = x;
	this->Position.y = y;
	MouseState.LMbuttonDoubleClick = true;
}

void __Mouse::LMButtonDBclick(float x, float y)
{
	this->Position.x = x;
	this->Position.y = y;
	MouseState.RMButtonDoubleClick = true;
}
