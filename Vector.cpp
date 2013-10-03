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

#include "Vector.hpp"

using namespace Math;

Vector2::Vector2(Vector3 const &Vec)
{
	x = Vec.x;
	y = Vec.y;
}

Vector2::Vector2(Vector4 const &Vec)
{
	x = Vec.x;
	y = Vec.y;
}

Vector3::Vector3(Vector4 const &Vec)
{
	x = Vec.x;
	y = Vec.y;
	z = Vec.z;
}

