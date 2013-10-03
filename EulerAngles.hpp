/*
* This file is part of SmallMath.
*
* SmallMath is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* SmallMath is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with SmallMath. If not, see <http://www.gnu.org/licenses/>.
*
* Copyright 2013 Chris Foster
*/

#ifndef SMALLMATH_EULERANGLES
#define SMALLMATH_EULERANGLES

#include <iostream>

#include "Matrix.hpp"
#include "Quaternion.hpp"
#include "Vector.hpp"

namespace Math
{
	class Matrix3;
	class Quaternion;
	
	class EulerAngles
	{
	public:
		enum TransformOrder {XYZ, XZY, YXZ, YZX, ZXY, ZYX};
		
		EulerAngles() : x(0.0f), y(0.0f), z(0.0f), Order(XYZ) { }
		EulerAngles(float x, float y, float z, TransformOrder Order = XYZ) : x(x), y(y), z(z), Order(Order) { }
		EulerAngles(Vector3 const &Vec, TransformOrder Order = XYZ);
		EulerAngles(Matrix3 const &Mat);
		EulerAngles(Quaternion const &Quat);
		
		// General operations
		inline void Set(float x, float y, float z);
		inline void SetZero();
		
		float x, y, z;
		TransformOrder Order;
	
	private:
		void SetFromMatrix3(Matrix3 const &Mat);
	};
	
	// Stream print =======================================
	
	inline std::ostream &operator<<(std::ostream &a, EulerAngles const &b)
	{
		a << "((" << b.x << ", " << b.y << ", " << b.z << "), ";
		
		switch (b.Order)
		{
		case EulerAngles::XYZ:
			a << "XYZ";
			break;
		case EulerAngles::XZY:
			a << "XZY";
			break;
		case EulerAngles::YXZ:
			a << "YXZ";
			break;
		case EulerAngles::YZX:
			a << "YZX";
			break;
		case EulerAngles::ZXY:
			a << "ZXY";
			break;
		case EulerAngles::ZYX:
			a << "ZYX";
		}
		
		a << ")";
		return a;
	}
	
	// General operations =================================
	
	inline void EulerAngles::Set(float x, float y, float z)
	{
		EulerAngles::x = x;
		EulerAngles::y = y;
		EulerAngles::z = z;
	}
	
	inline void EulerAngles::SetZero()
	{
		x = 0.0f; y = 0.0f; z = 0.0f;
	}
}

#endif

