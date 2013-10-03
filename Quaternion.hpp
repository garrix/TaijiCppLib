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

#ifndef SMALLMATH_QUATERNION
#define SMALLMATH_QUATERNION

#include <cmath>
#include <iostream>
#include <limits>

#include "EulerAngles.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"

namespace Math
{
	class Matrix3;
	class EulerAngles;
	
	class Quaternion
	{
	public:
		Quaternion() : w(1.0f), x(0.0f), y(0.0f), z(0.0f) { }
		Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) { }
		Quaternion(float Angle, Vector3 const &Axis);
		Quaternion(Matrix3 const &Mat);
		Quaternion(EulerAngles const &Euler);
		
		// General operations
		inline void SetIdentity();
		inline float Dot(Quaternion const &b) const;
		inline float Magnitude() const;
		inline float MagnitudeSquared() const;
		inline Quaternion Slerp(Quaternion const &b, float t) const;
		inline float Normalize();
		inline Quaternion Normalized() const;
		inline Quaternion Conjugate() const;
		inline Quaternion Invert();
		inline Quaternion Inverted() const;
		inline float GetAngle() const;
		inline Vector3 GetAxis() const;
		
		// Binary and unary addition operators
		inline Quaternion operator+(Quaternion const &b) const;
		inline Quaternion operator+(float b) const;
		inline Quaternion &operator+=(Quaternion const &b);
		inline Quaternion &operator+=(float b);
		
		// Binary and unary subtraction operators
		inline Quaternion operator-(Quaternion const &b) const;
		inline Quaternion operator-(float b) const;
		inline Quaternion &operator-=(Quaternion const &b);
		inline Quaternion &operator-=(float b);
		
		// Binary and unary multiplication operators
		inline Quaternion operator*(Quaternion const &b) const;
		inline Vector3 operator*(Vector3 const &b) const; // Performs: *this * Quaternion(0.0f, b.x, b.y, b.z) * this->Conjugate()
		inline Quaternion operator*(float b) const;
		inline Quaternion &operator*=(Quaternion const &b);
		inline Quaternion &operator*=(float b);
		
		// Binary and unary division operators
		inline Quaternion operator/(float b) const;
		inline Quaternion &operator/=(float b);
		
		float w, x, y, z;
	};
	
	// Stream print =======================================
	
	inline std::ostream &operator<<(std::ostream &a, Quaternion const &b)
	{
		a << "(" << b.w << ", (" << b.x << ", " << b.y << ", " << b.z << "))";
		return a;
	}
	
	// General operations =================================
	
	inline void Quaternion::SetIdentity()
	{
		w = 1.0f; x = 0.0f; y = 0.0f; z = 0.0f;
	}
	
	inline float Quaternion::Dot(Quaternion const &b) const
	{
		return (w * b.w + x * b.x + y * b.y + z * b.z);
	}
	
	inline float Quaternion::Magnitude() const
	{
		return std::sqrt(w * w + x * x + y * y + z * z);
	}
	
	inline float Quaternion::MagnitudeSquared() const
	{
		return (w * w + x * x + y * y + z * z);
	}
	
	inline Quaternion Quaternion::Slerp(Quaternion const &b, float t) const
	{
		float CosTheta = this->Dot(b);
		Quaternion a = *this;
		
		if (CosTheta < 0.0f)
		{
			CosTheta *= -1.0f;
			a *= -1.0f;
		}
		
		float ra, rb;
		
		if ((1.0f - CosTheta) > std::numeric_limits<float>::epsilon())
		{
			float Theta = std::acos(CosTheta);
			float SinTheta = std::sin(Theta);
			ra = std::sin((1.0f - t) * Theta) / SinTheta;
			rb = std::sin(t * Theta) / SinTheta;
		}
		else
		{
			ra = 1.0f - t;
			rb = t;
		}
		
		return a * ra + b * rb;
	}
	
	inline float Quaternion::Normalize()
	{
		float m = this->Magnitude();
		
		w /= m;
		x /= m;
		y /= m;
		z /= m;
		
		return m;
	}
	
	inline Quaternion Quaternion::Normalized() const
	{
		return *this / this->Magnitude();
	}
	
	inline Quaternion Quaternion::Conjugate() const
	{
		return Quaternion(w, -x, -y, -z);
	}
	
	inline Quaternion Quaternion::Invert()
	{
		*this = this->Inverted();
		return *this;
	}
	
	inline Quaternion Quaternion::Inverted() const
	{
		return this->Conjugate() / this->MagnitudeSquared();
	}
	
	inline float Quaternion::GetAngle() const
	{
		return (2 * std::acos(w));
	}
	
	inline Vector3 Quaternion::GetAxis() const
	{
		float SinTheta = 1.0f - (w * w);
		
		if (std::abs(SinTheta) < std::numeric_limits<float>::epsilon())
			return Vector3();
		
		return Vector3(x / SinTheta, y / SinTheta, z / SinTheta);
	}
	
	// Binary and unary addition operators ================
	
	inline Quaternion Quaternion::operator+(Quaternion const &b) const
	{
		return Quaternion(w + b.w, x + b.x, y + b.y, z + b.z);
	}
	
	inline Quaternion Quaternion::operator+(float b) const
	{
		return Quaternion(w + b, x + b, y + b, z + b);
	}
	
	inline Quaternion &Quaternion::operator+=(Quaternion const &b)
	{
		w += b.w;
		x += b.x;
		y += b.y;
		z += b.z;
		return *this;
	}
	
	inline Quaternion &Quaternion::operator+=(float b)
	{
		w += b;
		x += b;
		y += b;
		z += b;
		return *this;
	}
	
	// Binary and unary subtraction operators ================
	
	inline Quaternion Quaternion::operator-(Quaternion const &b) const
	{
		return Quaternion(w - b.w, x - b.x, y - b.y, z - b.z);
	}
	
	inline Quaternion Quaternion::operator-(float b) const
	{
		return Quaternion(w - b, x - b, y - b, z - b);
	}
	
	inline Quaternion &Quaternion::operator-=(Quaternion const &b)
	{
		w -= b.w;
		x -= b.x;
		y -= b.y;
		z -= b.z;
		return *this;
	}
	
	inline Quaternion &Quaternion::operator-=(float b)
	{
		w -= b;
		x -= b;
		y -= b;
		z -= b;
		return *this;
	}
	
	// Binary and unary multiplication operators ==========
	
	inline Quaternion Quaternion::operator*(Quaternion const &b) const
	{
		return Quaternion(w *  b.w - x * b.x - y * b.y - z * b.z,
						  x *  b.w + w * b.x + y * b.z - z * b.y,
						  w *  b.y - x * b.z + y * b.w + z * b.x,
						  w *  b.z + x * b.y - y * b.x + z * b.w);
	}
	
	inline Vector3 Quaternion::operator*(Vector3 const &b) const
	{
		Quaternion r = *this * Quaternion(0.0f, b.x, b.y, b.z) * this->Conjugate();
		return Vector3(r.x, r.y, r.z);
	}
	
	inline Quaternion Quaternion::operator*(float b) const
	{
		return Quaternion(w * b, x * b, y * b, z * b);
	}
	
	inline Quaternion &Quaternion::operator*=(Quaternion const &b)
	{
		*this = *this * b;
		return *this;
	}
	
	inline Quaternion &Quaternion::operator*=(float b)
	{
		w *= b;
		x *= b;
		y *= b;
		z *= b;
		return *this;
	}
	
	// Binary and unary division operators ================
	
	inline Quaternion Quaternion::operator/(float b) const
	{
		return Quaternion(w / b, x / b, y / b, z / b);
	}
	
	inline Quaternion &Quaternion::operator/=(float b)
	{
		w /= b;
		x /= b;
		y /= b;
		z /= b;
		return *this;
	}
}

#endif


