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

#include <cmath>
#include <limits>
#include "EulerAngles.hpp"

using namespace Math;

EulerAngles::EulerAngles(Vector3 const &Vec, TransformOrder Order)
{
	x = Vec.x; y = Vec.y; z = Vec.z;
	EulerAngles::Order = Order;
}

EulerAngles::EulerAngles(Matrix3 const &Mat)
{
	SetFromMatrix3(Mat);
}

EulerAngles::EulerAngles(Quaternion const &Quat)
{
	SetFromMatrix3(Matrix3(Quat));
}

// Private ================================================

void EulerAngles::SetFromMatrix3(Matrix3 const &Mat)
{
	Matrix3 Rotation = Mat.RotationComponent();
	EulerAngles e1, e2;
	
	float CosY = std::sqrt(Rotation.m[0][0] * Rotation.m[0][0] + Rotation.m[1][0] * Rotation.m[1][0]);
	
	if (CosY > 8.0f * std::numeric_limits<float>::epsilon())
	{
		e1.x = std::atan2(Rotation.m[2][1], Rotation.m[2][2]);
		e1.y = std::atan2(-Rotation.m[2][0], CosY);
		e1.z = std::atan2(Rotation.m[1][0], Rotation.m[0][0]);
		
		e2.x = std::atan2(-Rotation.m[2][1], -Rotation.m[2][2]);
		e2.y = std::atan2(-Rotation.m[2][0], -CosY);
		e2.z = std::atan2(-Rotation.m[1][0], -Rotation.m[0][0]);
	}
	else
	{
		e1.x = std::atan2(-Rotation.m[1][2], Rotation.m[1][1]);
		e1.y = std::atan2(-Rotation.m[2][0], CosY);
		e1.z = 0.0f;
		
		e2 = e1;
	}
	
	// Select the one with the lowest values
	if (std::abs(e1.x) + std::abs(e1.y) + std::abs(e1.z) > std::abs(e2.x) + std::abs(e2.y) + std::abs(e2.z))
	{
		x = e2.x;
		y = e2.y;
		z = e2.z;
	}
	else
	{
		x = e1.x;
		y = e1.y;
		z = e1.z;
	}
	
	Order = XYZ;
}

