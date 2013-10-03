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

#include "Quaternion.hpp"

using namespace Math;

Quaternion::Quaternion(float Angle, Vector3 const &Axis)
{
	w = std::cos(Angle / 2);
	
	float SinAngle = std::sin(Angle / 2);
	x = Axis.x * SinAngle;
	y = Axis.y * SinAngle;
	z = Axis.z * SinAngle;
}

Quaternion::Quaternion(Matrix3 const &Mat)
{
	// Adapted from Martin Baker's examples at euclideanspace.com
	Matrix3 n = Mat.Normalized();
	
	float Trace = n.m[0][0] + n.m[1][1] + n.m[2][2];
	
	Quaternion r;
	
	if (Trace > std::numeric_limits<float>::epsilon())
	{
		float s = 2 * std::sqrt(Trace + 1.0f);
		r.w = 0.25f * s;
		r.x = (n.m[2][1] - n.m[1][2]) / s;
		r.y = (n.m[0][2] - n.m[2][0]) / s;
		r.z = (n.m[1][0] - n.m[0][1]) / s;
	}
	else if ((n.m[0][0] > n.m[1][1]) & (n.m[0][0] > n.m[2][2]))
	{
		float s = 2 * std::sqrt(1.0f + n.m[0][0] - n.m[1][1] - n.m[2][2]);
		r.w = (n.m[2][1] - n.m[1][2]) / s;
		r.x = 0.25f * s;
		r.y = (n.m[0][1] + n.m[1][0]) / s;
		r.z = (n.m[0][2] + n.m[2][0]) / s;
	}
	else if (n.m[1][1] > n.m[2][2])
	{
		float s = 2 * std::sqrt(1.0f + n.m[1][1] - n.m[0][0] - n.m[2][2]);
		r.w = (n.m[0][2] - n.m[2][0]) / s;
		r.x = (n.m[0][1] + n.m[1][0]) / s;
		r.y = 0.25f * s;
		r.z = (n.m[1][2] + n.m[2][1]) / s;
	}
	else
	{
		float s = 2 * std::sqrt(1.0f + n.m[2][2] - n.m[0][0] - n.m[1][1]);
		r.w = (n.m[1][0] - n.m[0][1]) / s;
		r.x = (n.m[0][2] + n.m[2][0]) / s;
		r.y = (n.m[1][2] + n.m[2][1]) / s;
		r.z = 0.25f * s;
	}
	
	r.Normalize();
	w = r.w;
	x = r.x;
	y = r.y;
	z = r.z;
}

Quaternion::Quaternion(EulerAngles const &Euler)
{
	Quaternion r = Quaternion(Matrix3(Euler));
	
	w = r.w;
	x = r.x;
	y = r.y;
	z = r.z;
}

