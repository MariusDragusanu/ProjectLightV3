#pragma once
namespace Mouse 
{
	constexpr auto LMButtonClick = 1;
	constexpr auto LMButtonRelease = 2;
	constexpr auto RMButtonClick = 3;
	constexpr auto RMButtonRelease = 4;
	constexpr auto LMbuttonDoubbleClick = 5;
	constexpr auto RMButtonDoubleClick = 6;
	constexpr auto MWHeelUp = 7;
	constexpr auto MWheelDown = 8;
}
using namespace Mouse;
class __Mouse
{
	
	struct
	{
		bool	LMButtonClick = false,
			LMButtonRelease = false,
			RMButtonClick = false,
			RMButtonRelease = false,
			LMbuttonDoubleClick = false,
			RMButtonDoubleClick = false,
			MWHeelUp = false,
			MWheelDown = false;
	}MouseState;
	D2D1_POINT_2F Position = {0,0};
public:void						SetPosition(float x ,float y);
	    D2D1_POINT_2F		GetPosition()const { return Position; }
	    bool						GetEvent(int M);
	    void						LMButtonIsPressed(float x, float y);
	    void						LMButtonIsReleased(float x, float y);
	    void						RMButtonIsPressed(float x, float y);
	    void						RMButtonIsReleased(float x, float y);
	    void						MouseMove(float x, float y);
	    void						RMButtonDBClick(float x, float y);
	    void						LMButtonDBclick(float x, float y);
	    void						DBClickEnd() { MouseState.LMbuttonDoubleClick = false; MouseState.RMButtonDoubleClick = false; }
};