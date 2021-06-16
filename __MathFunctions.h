#pragma once

namespace Math
{
	DOUBLE GetDistanceBetweenPoints(const D2D1_POINT_2F& A, const D2D1_POINT_2F B)
	{
		return sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
	}

		
};