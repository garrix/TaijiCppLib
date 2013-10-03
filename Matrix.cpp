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

#include "Constants.hpp"
#include "Matrix.hpp"

using namespace Math;

Matrix2::Matrix2()
{
	m[0][0] = 1.0f; m[0][1] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = 1.0f;
}

Matrix2::Matrix2(float _00, float _01,
				 float _10, float _11)
{
	m[0][0] = _00; m[0][1] = _01;
	m[1][0] = _10; m[1][1] = _11;
}

Matrix2::Matrix2(Vector2 const &r0, Vector2 const &r1)
{
	m[0][0] = r0.x; m[0][1] = r0.y;
	m[1][0] = r1.x; m[1][1] = r1.y;
}

Matrix2::Matrix2(Matrix3 const &Mat)
{
	m[0][0] = Mat.m[0][0]; m[0][1] = Mat.m[0][1];
	m[1][0] = Mat.m[1][0]; m[1][1] = Mat.m[1][1];
}

Matrix2::Matrix2(Matrix4 const &Mat)
{
	m[0][0] = Mat.m[0][0]; m[0][1] = Mat.m[0][1];
	m[1][0] = Mat.m[1][0]; m[1][1] = Mat.m[1][1];
}

Matrix2::Matrix2(Vector2 const &Scale)
{
	m[0][0] = Scale.x; m[0][1] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = Scale.y;
}

Matrix2::Matrix2(float Rotation)
{
	m[0][0] = std::cos(Rotation); m[0][1] = -std::sin(Rotation);
	m[1][0] = std::sin(Rotation); m[1][1] = std::cos(Rotation);
}

Matrix2::Matrix2(Vector2 const &Scale, float Rotation)
{
	m[0][0] = Scale.x * std::cos(Rotation); m[0][1] = Scale.y * -std::sin(Rotation);
	m[1][0] = Scale.x * std::sin(Rotation); m[1][1] = Scale.y * std::cos(Rotation);
}

Matrix3::Matrix3()
{
	m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f;
}

Matrix3::Matrix3(float _00, float _01, float _02,
				 float _10, float _11, float _12,
				 float _20, float _21, float _22)
{
	m[0][0] = _00; m[0][1] = _01; m[0][2] = _02;
	m[1][0] = _10; m[1][1] = _11; m[1][2] = _12;
	m[2][0] = _20; m[2][1] = _21; m[2][2] = _22;
}

Matrix3::Matrix3(Vector3 const &r0, Vector3 const &r1, Vector3 const &r2)
{
	m[0][0] = r0.x; m[0][1] = r0.y; m[0][2] = r0.z;
	m[1][0] = r1.x; m[1][1] = r1.y; m[1][2] = r1.z;
	m[2][0] = r2.x; m[2][1] = r2.y; m[2][2] = r2.z;
}

Matrix3::Matrix3(Matrix2 const &Mat)
{
	m[0][0] = Mat.m[0][0]; m[0][1] = Mat.m[0][1]; m[0][2] = 0.0f;
	m[1][0] = Mat.m[1][0]; m[1][1] = Mat.m[1][1]; m[1][2] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f;
}

Matrix3::Matrix3(Matrix4 const &Mat)
{
	m[0][0] = Mat.m[0][0]; m[0][1] = Mat.m[0][1]; m[0][2] = Mat.m[0][2];
	m[1][0] = Mat.m[1][0]; m[1][1] = Mat.m[1][1]; m[1][2] = Mat.m[1][2];
	m[2][0] = Mat.m[2][0]; m[2][1] = Mat.m[2][1]; m[2][2] = Mat.m[2][2];
}

Matrix3::Matrix3(Vector3 const &Scale)
{
	m[0][0] = Scale.x; m[0][1] = 0.0f; m[0][2] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = Scale.y; m[1][2] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = Scale.z;
}

Matrix3::Matrix3(EulerAngles const &Rotation)
{
	Matrix3 r = RotationMatrix(Rotation);
	
	m[0][0] = r.m[0][0]; m[0][1] = r.m[0][1]; m[0][2] = r.m[0][2];
	m[1][0] = r.m[1][0]; m[1][1] = r.m[1][1]; m[1][2] = r.m[1][2];
	m[2][0] = r.m[2][0]; m[2][1] = r.m[2][1]; m[2][2] = r.m[2][2];
}

Matrix3::Matrix3(Quaternion const &Rotation)
{
	float w = Constants::Sqrt2 * Rotation.w;
	float x = Constants::Sqrt2 * Rotation.x;
	float y = Constants::Sqrt2 * Rotation.y;
	float z = Constants::Sqrt2 * Rotation.z;
	
	float wx = w * x; // 2 * w * x
	float wy = w * y; // etc...
	float wz = w * z;
	float xx = x * x;
	float xy = x * y;
	float xz = x * z;
	float yy = y * y;
	float yz = y * z;
	float zz = z * z;
	
	m[0][0] = 1.0f - yy - zz;
	m[1][1] = 1.0f - xx - zz;
	m[2][2] = 1.0f - xx - yy;
	
	m[0][1] = xy - wz;
	m[1][0] = xy + wz;
	
	m[0][2] = xz + wy;
	m[2][0] = xz - wy;
	
	m[1][2] = yz - wx;
	m[2][1] = yz + wx;
}

Matrix3::Matrix3(Vector3 const &Scale, EulerAngles const &Rotation)
{
	Matrix3 r = Matrix3(Rotation) * Matrix3(Scale);
	
	m[0][0] = r.m[0][0]; m[0][1] = r.m[0][1]; m[0][2] = r.m[0][2];
	m[1][0] = r.m[1][0]; m[1][1] = r.m[1][1]; m[1][2] = r.m[1][2];
	m[2][0] = r.m[2][0]; m[2][1] = r.m[2][1]; m[2][2] = r.m[2][2];
}

Matrix3::Matrix3(Vector3 const &Scale, Quaternion const &Rotation)
{
	Matrix3 r = Matrix3(Rotation) * Matrix3(Scale);
	
	m[0][0] = r.m[0][0]; m[0][1] = r.m[0][1]; m[0][2] = r.m[0][2];
	m[1][0] = r.m[1][0]; m[1][1] = r.m[1][1]; m[1][2] = r.m[1][2];
	m[2][0] = r.m[2][0]; m[2][1] = r.m[2][1]; m[2][2] = r.m[2][2];
}

Matrix4::Matrix4()
{
	m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
}

Matrix4::Matrix4(float _00, float _01, float _02, float _03,
				 float _10, float _11, float _12, float _13,
				 float _20, float _21, float _22, float _23,
				 float _30, float _31, float _32, float _33)
{
	m[0][0] = _00; m[0][1] = _01; m[0][2] = _02; m[0][3] = _03;
	m[1][0] = _10; m[1][1] = _11; m[1][2] = _12; m[1][3] = _13;
	m[2][0] = _20; m[2][1] = _21; m[2][2] = _22; m[2][3] = _23;
	m[3][0] = _30; m[3][1] = _31; m[3][2] = _32; m[3][3] = _33;
}

Matrix4::Matrix4(Vector4 const &r0, Vector4 const &r1, Vector4 const &r2, Vector4 const &r3)
{
	m[0][0] = r0.x; m[0][1] = r0.y; m[0][2] = r0.z; m[0][3] = r0.w;
	m[1][0] = r1.x; m[1][1] = r1.y; m[1][2] = r1.z; m[1][3] = r1.w;
	m[2][0] = r2.x; m[2][1] = r2.y; m[2][2] = r2.z; m[2][3] = r2.w;
	m[3][0] = r3.x; m[3][1] = r3.y; m[3][2] = r3.z; m[3][3] = r3.w;
}

Matrix4::Matrix4(Matrix2 const &Mat)
{
	m[0][0] = Mat.m[0][0]; m[0][1] = Mat.m[0][1]; m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = Mat.m[1][0]; m[1][1] = Mat.m[1][1]; m[1][2] = 0.0f; m[2][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
}

Matrix4::Matrix4(Matrix3 const &Mat)
{
	m[0][0] = Mat.m[0][0]; m[0][1] = Mat.m[0][1]; m[0][2] = Mat.m[0][2]; m[0][3] = 0.0f;
	m[1][0] = Mat.m[1][0]; m[1][1] = Mat.m[1][1]; m[1][2] = Mat.m[1][2]; m[2][3] = 0.0f;
	m[2][0] = Mat.m[2][0]; m[2][1] = Mat.m[2][1]; m[2][2] = Mat.m[2][2]; m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
}

Matrix4::Matrix4(Vector3 const &Scale, Vector3 const &Translation)
{
	Matrix4 r = TranslationMatrix(Translation) * Matrix3(Scale);
	
	m[0][0] = r.m[0][0]; m[0][1] = r.m[0][1]; m[0][2] = r.m[0][2]; m[0][3] = r.m[0][3];
	m[1][0] = r.m[1][0]; m[1][1] = r.m[1][1]; m[1][2] = r.m[1][2]; m[1][3] = r.m[1][3];
	m[2][0] = r.m[2][0]; m[2][1] = r.m[2][1]; m[2][2] = r.m[2][2]; m[2][3] = r.m[2][3];
	m[3][0] = r.m[3][0]; m[3][1] = r.m[3][1]; m[3][2] = r.m[3][2]; m[3][3] = r.m[3][3];
}

Matrix4::Matrix4(EulerAngles const &Rotation)
{
	Matrix4 r = Matrix3(Rotation);
	
	m[0][0] = r.m[0][0]; m[0][1] = r.m[0][1]; m[0][2] = r.m[0][2]; m[0][3] = r.m[0][3];
	m[1][0] = r.m[1][0]; m[1][1] = r.m[1][1]; m[1][2] = r.m[1][2]; m[1][3] = r.m[1][3];
	m[2][0] = r.m[2][0]; m[2][1] = r.m[2][1]; m[2][2] = r.m[2][2]; m[2][3] = r.m[2][3];
	m[3][0] = r.m[3][0]; m[3][1] = r.m[3][1]; m[3][2] = r.m[3][2]; m[3][3] = r.m[3][3];
}

Matrix4::Matrix4(Quaternion const &Rotation)
{
	float w = Constants::Sqrt2 * Rotation.w;
	float x = Constants::Sqrt2 * Rotation.x;
	float y = Constants::Sqrt2 * Rotation.y;
	float z = Constants::Sqrt2 * Rotation.z;
	
	float wx = w * x; // 2 * w * x
	float wy = w * y; // etc...
	float wz = w * z;
	float xx = x * x;
	float xy = x * y;
	float xz = x * z;
	float yy = y * y;
	float yz = y * z;
	float zz = z * z;
	
	m[0][0] = 1.0f - yy - zz;
	m[1][1] = 1.0f - xx - zz;
	m[2][2] = 1.0f - xx - yy;
	
	m[0][1] = xy - wz;
	m[1][0] = xy + wz;
	
	m[0][2] = xz + wy;
	m[2][0] = xz - wy;
	
	m[1][2] = yz - wx;
	m[2][1] = yz + wx;
	
	m[0][3] = m[1][3] = m[2][3] = 0.0f;
	m[3][0] = m[3][1] = m[3][2] = 0.0f;
	m[3][3] = 1.0f;
}

Matrix4::Matrix4(Vector3 const &Scale, EulerAngles const &Rotation, Vector3 const &Translation)
{
	Matrix4 r = TranslationMatrix(Translation) * Matrix4(Rotation) * Matrix4(Scale);
	
	m[0][0] = r.m[0][0]; m[0][1] = r.m[0][1]; m[0][2] = r.m[0][2]; m[0][3] = r.m[0][3];
	m[1][0] = r.m[1][0]; m[1][1] = r.m[1][1]; m[1][2] = r.m[1][2]; m[1][3] = r.m[1][3];
	m[2][0] = r.m[2][0]; m[2][1] = r.m[2][1]; m[2][2] = r.m[2][2]; m[2][3] = r.m[2][3];
	m[3][0] = r.m[3][0]; m[3][1] = r.m[3][1]; m[3][2] = r.m[3][2]; m[3][3] = r.m[3][3];
}

Matrix4::Matrix4(Vector3 const &Scale, Quaternion const &Rotation, Vector3 const &Translation)
{
	Matrix4 r = TranslationMatrix(Translation) * Matrix4(Rotation) * Matrix4(Scale);
	
	m[0][0] = r.m[0][0]; m[0][1] = r.m[0][1]; m[0][2] = r.m[0][2]; m[0][3] = r.m[0][3];
	m[1][0] = r.m[1][0]; m[1][1] = r.m[1][1]; m[1][2] = r.m[1][2]; m[1][3] = r.m[1][3];
	m[2][0] = r.m[2][0]; m[2][1] = r.m[2][1]; m[2][2] = r.m[2][2]; m[2][3] = r.m[2][3];
	m[3][0] = r.m[3][0]; m[3][1] = r.m[3][1]; m[3][2] = r.m[3][2]; m[3][3] = r.m[3][3];
}

// General operations =====================================

float Matrix2::Determinant() const
{
	return (m[0][0] * m[1][1] - m[1][0] * m[0][1]);
}

Matrix2 Matrix2::Adjugate() const
{
	return Matrix2(m[1][1], -m[0][1],
				   -m[1][0], m[0][0]);
}

Matrix2 Matrix2::Invert()
{
	*this = this->Inverted();
	return *this;
}

Matrix2 Matrix2::Inverted() const
{
	float d = this->Determinant();
	
	if (std::abs(d) < std::numeric_limits<float>::epsilon())
		return Matrix2(); // The matrix is uninvertible
	
	return this->Adjugate() / d;
}

Matrix2 Matrix2::Normalize()
{
	*this = this->Normalized();
	return *this;
}

Matrix2 Matrix2::Normalized() const
{
	return Matrix2(this->XAxis().Normalized(),
				   this->YAxis().Normalized());
}

float Matrix3::Determinant() const
{
	return (m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2]) -
			m[0][1] * (m[1][0] * m[2][2] - m[2][0] * m[1][2]) +
			m[0][2] * (m[1][0] * m[2][1] - m[2][0] * m[1][1]));
}

Matrix3 Matrix3::Adjugate() const
{
	Matrix3 a;
	
	a.m[0][0] =  (m[1][1] * m[2][2] - m[2][1] * m[1][2]);
	a.m[1][0] = -(m[1][0] * m[2][2] - m[2][0] * m[1][2]);
	a.m[2][0] =  (m[1][0] * m[2][1] - m[2][0] * m[1][1]);
	
	a.m[0][1] = -(m[0][1] * m[2][2] - m[2][1] * m[0][2]);
	a.m[1][1] =  (m[0][0] * m[2][2] - m[2][0] * m[0][2]);
	a.m[2][1] = -(m[0][0] * m[2][1] - m[2][0] * m[0][1]);
	
	a.m[0][2] =  (m[0][1] * m[1][2] - m[1][1] * m[0][2]);
	a.m[1][2] = -(m[0][0] * m[1][2] - m[1][0] * m[0][2]);
	a.m[2][2] =  (m[0][0] * m[1][1] - m[1][0] * m[0][1]);
	
	return a;
}

Matrix3 Matrix3::Invert()
{
	*this = this->Inverted();
	return *this;
}

Matrix3 Matrix3::Inverted() const
{
	float d = this->Determinant();
	
	if (std::abs(d) < std::numeric_limits<float>::epsilon())
		return Matrix2(); // The matrix is uninvertible
	
	return this->Adjugate() / d;
}

Matrix3 Matrix3::Normalize()
{
	*this = this->Normalized();
	return *this;
}

Matrix3 Matrix3::Normalized() const
{
	return Matrix3(this->XAxis().Normalized(),
				   this->YAxis().Normalized(),
				   this->ZAxis().Normalized());
}

float Matrix4::Determinant() const
{
	return (m[0][0] * Matrix3(m[1][1], m[1][2], m[1][3],
							  m[2][1], m[2][2], m[2][3],
							  m[3][1], m[3][2], m[3][3]).Determinant() -
			m[0][1] * Matrix3(m[1][0], m[1][2], m[1][3],
							  m[2][0], m[2][2], m[2][3],
							  m[3][0], m[3][2], m[3][3]).Determinant() +
			m[0][2] * Matrix3(m[1][0], m[1][1], m[1][3],
							  m[2][0], m[2][1], m[2][3],
							  m[3][0], m[3][1], m[3][3]).Determinant() -
			m[0][3] * Matrix3(m[1][0], m[1][1], m[1][2],
							  m[2][0], m[2][1], m[2][2],
							  m[3][0], m[3][1], m[3][2]).Determinant());
}

Matrix4 Matrix4::Adjugate() const
{
	Matrix4 a;
	
	a.m[0][0] =  Matrix3(m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]).Determinant();
	a.m[1][0] = -Matrix3(m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]).Determinant();
	a.m[2][0] =  Matrix3(m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]).Determinant();
	a.m[3][0] = -Matrix3(m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]).Determinant();
	
	a.m[0][1] = -Matrix3(m[0][1], m[0][2], m[0][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]).Determinant();
	a.m[1][1] =  Matrix3(m[0][0], m[0][2], m[0][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]).Determinant();
	a.m[2][1] = -Matrix3(m[0][0], m[0][1], m[0][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]).Determinant();
	a.m[3][1] =  Matrix3(m[0][0], m[0][1], m[0][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]).Determinant();
	
	a.m[0][2] =  Matrix3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[3][1], m[3][2], m[3][3]).Determinant();
	a.m[1][2] = -Matrix3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[3][0], m[3][2], m[3][3]).Determinant();
	a.m[2][2] =  Matrix3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[3][0], m[3][1], m[3][3]).Determinant();
	a.m[3][2] = -Matrix3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[3][0], m[3][1], m[3][2]).Determinant();
	
	a.m[0][3] = -Matrix3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3]).Determinant();
	a.m[1][3] =  Matrix3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3]).Determinant();
	a.m[2][3] = -Matrix3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3]).Determinant();
	a.m[3][3] =  Matrix3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2]).Determinant();
	
	return a;
}

Matrix4 Matrix4::Invert()
{
	*this = this->Inverted();
	return *this;
}

// This routine is adapted from Blender's invert_m4_m4().  Presumably faster than Adj/Det?
Matrix4 Matrix4::Inverted() const
{
	Matrix4 r, Temp;

	Temp = *this;

	// Effectively, we shrink the matrix with each iteration by ignoring an additional row and column.
	for (short FirstColumn = 0; FirstColumn < 4; FirstColumn++)
	{
		short &FirstRow = FirstColumn; // For ease of reading in different contexts
		float Max = std::fabs(Temp.m[FirstRow][FirstColumn]);
		short MaxRow = FirstColumn; // This will contain the Row in this Column that contains the maximum.

		for (short Row = FirstColumn + 1; Row < 4; Row++)
		{
			if (std::fabs(Temp.m[Row][FirstColumn]) > Max)
			{
				Max = std::fabs(Temp.m[Row][FirstColumn]);
				MaxRow = Row;
			}
		}

		if (std::abs(Max) < std::numeric_limits<float>::epsilon())
			return Matrix4(); // The matrix is uninvertible

		// If the max was not in the first row, swap its row with the first.
		if (MaxRow != FirstRow)
		{
			for (short Index = 0; Index < 4; Index++)
			{
				std::swap(Temp.m[MaxRow][Index], Temp.m[FirstRow][Index]);
				std::swap(r.m[MaxRow][Index], r.m[FirstRow][Index]);
			}
		}

		float SignedMax = Temp.m[FirstRow][FirstColumn];
		for (short Index = 0; Index < 4; Index++)
		{
			Temp.m[FirstRow][Index] /= SignedMax;
			r.m[FirstRow][Index] /= SignedMax;
		}

		for (short Row = 0; Row < 4; Row++)
		{
			if (Row != FirstRow)
			{
				float RowValue = Temp.m[Row][FirstColumn];
				for (short Index = 0; Index < 4; Index++)
				{
					Temp.m[Row][Index] -= Temp.m[FirstRow][Index] * RowValue;
					r.m[Row][Index] -= r.m[FirstRow][Index] * RowValue;
				}
			}
		}
	}

	return r;
}

Matrix4 Matrix4::Normalize()
{
	*this = this->Normalized();
	return *this;
}

Matrix4 Matrix4::Normalized() const
{
	float l;
	
	Vector4 r0 = this->XAxis();
	l = r0.Normalize(); r0.w = m[0][3] / l;
	Vector4 r1 = this->YAxis();
	l = r1.Normalize(); r1.w = m[1][3] / l;
	Vector4 r2 = this->ZAxis();
	l = r2.Normalize(); r2.w = m[2][3] / l;
	
	Vector4 r3(m[3][0], m[3][1], m[3][2], 1.0f);
	
	return Matrix4(r0, r1, r2, r3);
}

// Decomposition operations ===============================

Vector2 Matrix2::ScaleComponent() const
{
	return Vector2(this->XAxis().Length(), this->YAxis().Length());
}

Matrix2 Matrix2::RotationComponent() const
{
	return this->Normalized();
}

Vector3 Matrix3::ScaleComponent() const
{
	return Vector3(this->XAxis().Length(), this->YAxis().Length(), this->ZAxis().Length());
}
	
Matrix3 Matrix3::RotationComponent() const
{
	Matrix3 n = this->Normalized();
	
	if (this->IsNegative())
	{
		n.SetRow(0, n.XAxis() * -1.0f);
		n.SetRow(1, n.YAxis() * -1.0f);
		n.SetRow(2, n.ZAxis() * -1.0f);
	}
	
	return n;
}

Vector3 Matrix4::ScaleComponent() const
{
	return Vector3(this->XAxis().Length(), this->YAxis().Length(), this->ZAxis().Length());
}

Matrix3 Matrix4::RotationComponent() const
{
	return Matrix3(*this).RotationComponent();
}

Vector3 Matrix4::TranslationComponent() const
{
	return this->GetColumn(3);
}

// Private ================================================

bool Matrix3::IsNegative() const
{
	Vector3 z = this->XAxis().Cross(this->YAxis());
	return (z.Dot(this->ZAxis()) < 0.0f);
}

Matrix3 Matrix3::RotationMatrix(EulerAngles const &Rotation)
{
	Matrix3 XRotation, YRotation, ZRotation;

	if (std::abs(Rotation.x) > std::numeric_limits<float>::epsilon())
		XRotation = Matrix3(1.0f, 0.0f, 0.0f,
							0.0f, std::cos(Rotation.x), -std::sin(Rotation.x),
							0.0f, std::sin(Rotation.x), std::cos(Rotation.x));

	if (std::abs(Rotation.y) > std::numeric_limits<float>::epsilon())
		YRotation = Matrix3(std::cos(Rotation.y), 0.0f, std::sin(Rotation.y),
							0.0f, 1.0f, 0.0f,
							-std::sin(Rotation.y), 0.0f, std::cos(Rotation.y));

	if (std::abs(Rotation.z) > std::numeric_limits<float>::epsilon())
		ZRotation = Matrix3(std::cos(Rotation.z), -std::sin(Rotation.z), 0.0f,
							std::sin(Rotation.z), std::cos(Rotation.z), 0.0f,
							0.0f, 0.0f, 1.0f);
	
	switch (Rotation.Order)
	{
	case EulerAngles::XYZ:
		return ZRotation * YRotation * XRotation;
	case EulerAngles::XZY:
		return YRotation * ZRotation * XRotation;
	case EulerAngles::YXZ:
		return ZRotation * XRotation * YRotation;
	case EulerAngles::YZX:
		return XRotation * ZRotation * YRotation;
	case EulerAngles::ZXY:
		return YRotation * XRotation * ZRotation;
	default:
		return XRotation * YRotation * ZRotation;
	}
}

Matrix4 Matrix4::TranslationMatrix(Vector3 const &Translation)
{
	return Matrix4(1.0f, 0.0f, 0.0f, Translation.x,
				   0.0f, 1.0f, 0.0f, Translation.y,
				   0.0f, 0.0f, 1.0f, Translation.z,
				   0.0f, 0.0f, 0.0f, 1.0f);
}

