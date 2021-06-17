#pragma once
const double pi = 3.14159265359;

namespace Matrix
{
	struct __Matrix3f
	{
		float Matrix[3][3];
		__Matrix3f() :Matrix() { Matrix[0][0] = 1.0; Matrix[1][1] = 1.0; Matrix[2][2] = 1.0; };

	};
	struct __TranslationMatrix3f :__Matrix3f
	{

		float dx, dy;
		__TranslationMatrix3f(float dx, float dy) :dx(dx), dy(dy), __Matrix3f()
		{
			Matrix[0][0] = 1.0f;
			Matrix[1][1] = 1.0f;
			Matrix[2][0] = dx;
			Matrix[2][1] = dy;

		}
	};
	struct __ScalingMatrix3f :__Matrix3f
	{
		float dx, dy;
		__ScalingMatrix3f(float dx, float dy) :dx(dx), dy(dy), __Matrix3f()
		{
			Matrix[0][0] = dx;
			Matrix[1][1] = dy;

		}
	};
	struct __RotationAroundOriginMatrix3f :__Matrix3f
	{
		float angle;
		__RotationAroundOriginMatrix3f(float angle) :angle(angle), __Matrix3f()
		{
			
		
			Matrix[0][0] = std::cosf(angle);
			Matrix[0][1] = -std::sinf(angle);
			Matrix[1][0] = std::sinf(angle);
			Matrix[1][1] = std::cosf(angle);
			Matrix[2][2] = 1;
		}
	};
	struct __RotationAroundAnPoint3f :__Matrix3f
	{
		D2D1_POINT_2F Point;
		float angle;
		__RotationAroundAnPoint3f(D2D1_POINT_2F point, float angle) :Point(point), angle(angle)
		{
			
			Matrix[0][0] = std::cosf(angle);
			Matrix[0][1] = std::sinf(angle);
			Matrix[1][0] = -std::sinf(angle);
			Matrix[1][1] = std::cosf(angle);
			Matrix[2][0] = -Point.x * (std::cosf(angle)) + Point.y * (std::sinf(angle))+Point.x;
			Matrix[2][1] = -Point.x * (std::sinf(angle)) - Point.y * (std::cosf(angle))+Point.y;
		
			
		};
	};

	void operator<<(std::ostream&, const __Matrix3f& matrix)
	{
		std::cout << std::endl;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++) {
				std::cout << "[" << matrix.Matrix[i][j] << "]" << " ";
			}
			std::cout << std::endl;
		}
	}
	__Matrix3f operator*(const __Matrix3f& a, const __Matrix3f& b)
	{
		__Matrix3f matrix;




		for (int i = 0; i <= 2; i++)
			for (int j = 0; j <= 2; j++)
			{
				matrix.Matrix[i][j] = 0;
			}

		for (int i = 0; i <= 2; i++)
			for (int j = 0; j <= 2; j++)
				for (int k = 0; k <= 2; k++)
				{
					matrix.Matrix[i][j] += a.Matrix[i][k] * b.Matrix[k][j];
				}
		return matrix;
	}
}