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

#ifndef MATH_VECTOR
#define MATH_VECTOR

#include <cmath>
#include <iostream>
#include <limits>

namespace Math
{
	class Vector3;
	class Vector4;

	class Vector2
	{
	public:
		Vector2() : x(0.0f), y(0.0f) { }
		Vector2(float x, float y) : x(x), y(y) { }
		Vector2(Vector3 const &Vec);
		Vector2(Vector4 const &Vec);

		// General operations
		inline float Dot(Vector2 const &b) const;
		inline float Length() const;
		inline float LengthSquared() const;
		inline Vector2 Lerp(Vector2 const &b, float t) const;
		inline Vector2 Project(Vector2 const &b) const;
		inline float Normalize();
		inline float Normalize(float l);
		inline Vector2 Normalized() const;
		inline Vector2 Normalized(float l) const;
		inline bool IsZero() const;

		// Subscription operators
		inline float operator[](int Index) const;
		inline float &operator[](int Index);

		// Binary and unary addition operators
		inline Vector2 operator+(Vector2 const &b) const;
		inline Vector2 operator+(float b) const;
		inline Vector2 &operator+=(Vector2 const &b);
		inline Vector2 &operator+=(float b);

		// Binary and unary subtraction operators
		inline Vector2 operator-(Vector2 const &b) const;
		inline Vector2 operator-(float b) const;
		inline Vector2 &operator-=(Vector2 const &b);
		inline Vector2 &operator-=(float b);

		// Binary and unary multiplication operators
		inline Vector2 operator*(float b) const;
		inline Vector2 &operator*=(float b);

		// Binary and unary division operators
		inline Vector2 operator/(float b) const;
		inline Vector2 &operator/=(float b);

		float x, y;
	};

	class Vector3
	{
	public:
		Vector3() : x(0.0f), y(0.0f), z(0.0f) { }
		Vector3(float x, float y, float z) : x(x), y(y), z(z) { }
		Vector3(Vector2 const &Vec, float z = 0.0f) : x(Vec.x), y(Vec.y), z(z) { }
		Vector3(Vector4 const &Vec);

		// General operations
		inline float Dot(Vector3 const &b) const;
		inline Vector3 Cross(Vector3 const &b) const;
		inline float Length() const;
		inline float LengthSquared() const;
		inline Vector3 Lerp(Vector3 const &b, float t) const;
		inline Vector3 Project(Vector3 const &b) const;
		inline float Normalize();
		inline float Normalize(float l);
		inline Vector3 Normalized() const;
		inline Vector3 Normalized(float l) const;
		inline bool IsZero() const;

		// Subscription operators
		inline float operator[](int Index) const;
		inline float &operator[](int Index);

		// Binary and unary addition operators
		inline Vector3 operator+(Vector3 const &b) const;
		inline Vector3 operator+(float b) const;
		inline Vector3 &operator+=(Vector3 const &b);
		inline Vector3 &operator+=(float b);

		// Binary and unary subtraction operators
		inline Vector3 operator-(Vector3 const &b) const;
		inline Vector3 operator-(float b) const;
		inline Vector3 &operator-=(Vector3 const &b);
		inline Vector3 &operator-=(float b);

		// Binary and unary multiplication operators
		inline Vector3 operator*(float b) const;
		inline Vector3 &operator*=(float b);

		// Binary and unary division operators
		inline Vector3 operator/(float b) const;
		inline Vector3 &operator/=(float b);
		
		float x, y, z;
	};
	
	class Vector4
	{
	public:
		Vector4() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) { }
		Vector4(float x, float y, float z, float w = 1.0f) : x(x), y(y), z(z), w(w) { }
		Vector4(Vector2 const &Vec, float z = 0.0f, float w = 1.0f) : x(Vec.x), y(Vec.y), z(z), w(w) { }
		Vector4(Vector3 const &Vec, float w = 1.0f) : x(Vec.x), y(Vec.y), z(Vec.z), w(w) { }

		// General operations
		inline float Dot(Vector3 const &b) const;
		inline Vector4 Cross(Vector3 const &b) const;
		inline float Length() const; 					// Calculates 3D length
		inline float LengthSquared() const;				// Calculates 3D length squared
		inline Vector4 Lerp(Vector4 const &b, float t) const;
		inline Vector4 Project(Vector4 const &b) const;
		inline float Normalize();						// Normalizes with 3D length
		inline float Normalize(float l);				
		inline float NormalizeW();					// Normalizes with w component
		inline Vector4 Normalized() const;
		inline Vector4 Normalized(float l) const;
		inline Vector4 NormalizedW() const;
		inline bool IsZero() const;						// Checks only 3D components

		// Subscription operators
		inline float operator[](int Index) const;
		inline float &operator[](int Index);

		// Binary and unary addition operators
		inline Vector4 operator+(Vector4 const &b) const;
		inline Vector4 operator+(float b) const;
		inline Vector4 &operator+=(Vector4 const &b);
		inline Vector4 &operator+=(float b);

		// Binary and unary subtraction operators
		inline Vector4 operator-(Vector4 const &b) const;
		inline Vector4 operator-(float b) const;
		inline Vector4 &operator-=(Vector4 const &b);
		inline Vector4 &operator-=(float b);

		// Binary and unary multiplication operators
		inline Vector4 operator*(float b) const;
		inline Vector4 &operator*=(float b);

		// Binary and unary division operators
		inline Vector4 operator/(float b) const;
		inline Vector4 &operator/=(float b);
		
		float x, y, z, w;
	};

	// Stream print =======================================
	
	inline std::ostream &operator<<(std::ostream &a, Vector2 const &b)
	{
		a << "(" << b.x << ", " << b.y << ")";
		return a;
	}
	
	inline std::ostream &operator<<(std::ostream &a, Vector3 const &b)
	{
		a << "(" << b.x << ", " << b.y << ", " << b.z << ")";
		return a;
	}
	
	inline std::ostream &operator<<(std::ostream &a, Vector4 const &b)
	{
		a << "(" << b.x << ", " << b.y << ", " << b.z << ", " << b.w << ")";
		return a;
	}

	// General operations =================================
	
	inline float Vector2::Dot(Vector2 const &b) const
	{
		return (x * b.x + y * b.y);
	}

	inline float Vector2::Length() const
	{
		return std::sqrt(x * x + y * y);
	}

	inline float Vector2::LengthSquared() const
	{
		return (x * x + y * y);
	}
	
	inline Vector2 Vector2::Lerp(Vector2 const &b, float t) const
	{
		return *this * (1.0f - t) + b * t;
	}
	
	inline Vector2 Vector2::Project(Vector2 const &b) const
	{
		float t = this->Dot(b) / b.LengthSquared();
		return b * t;
	}

	inline float Vector2::Normalize()
	{
		float l = this->Length();
		
		x /= l;
		y /= l;
		
		return l;
	}

	inline float Vector2::Normalize(float l)
	{
		*this = this->Normalized(l);
		return l;
	}

	inline Vector2 Vector2::Normalized() const
	{
		return *this / this->Length();
	}

	inline Vector2 Vector2::Normalized(float l) const
	{
		return *this / l;
	}

	inline bool Vector2::IsZero() const
	{
		float const Epsilon = std::numeric_limits<float>::epsilon();

		if (std::abs(x) < Epsilon)
			if (std::abs(y) < Epsilon)
				return true;

		return false;
	}
	
	inline float Vector3::Dot(Vector3 const &b) const
	{
		return (x * b.x + y * b.y + z * b.z);
	}
	
	inline Vector3 Vector3::Cross(Vector3 const &b) const
	{
		return Vector3(y * b.z - z * b.y,
					   z * b.x - x * b.z,
					   x * b.y - y * b.x);
	}

	inline float Vector3::Length() const
	{
		return std::sqrt(x * x + y * y + z * z);
	}

	inline float Vector3::LengthSquared() const
	{
		return (x * x + y * y + z * z);
	}
	
	inline Vector3 Vector3::Lerp(Vector3 const &b, float t) const
	{
		return *this * (1.0f - t) + b * t;
	}
	
	inline Vector3 Vector3::Project(Vector3 const &b) const
	{
		float t = this->Dot(b) / b.LengthSquared();
		return b * t;
	}

	inline float Vector3::Normalize()
	{
		float l = this->Length();
		
		x /= l;
		y /= l;
		z /= l;
		
		return l;
	}

	inline float Vector3::Normalize(float l)
	{
		*this = this->Normalized(l);
		return l;
	}

	inline Vector3 Vector3::Normalized() const
	{
		return *this / this->Length();
	}

	inline Vector3 Vector3::Normalized(float l) const
	{
		return *this / l;
	}

	inline bool Vector3::IsZero() const
	{
		float const Epsilon = std::numeric_limits<float>::epsilon();

		if (std::abs(x) < Epsilon)
			if (std::abs(y) < Epsilon)
				if (std::abs(z) < Epsilon)
					return true;

		return false;
	}
	
	inline float Vector4::Dot(Vector3 const &b) const
	{
		return (x * b.x + y * b.y + z * b.z);
	}
		
	inline Vector4 Vector4::Cross(Vector3 const &b) const
	{
		return Vector4(y * b.z - z * b.y,
					   z * b.x - x * b.z,
					   x * b.y - y * b.x);
	}

	inline float Vector4::Length() const
	{
		return std::sqrt(x * x + y * y + z * z);
	}

	inline float Vector4::LengthSquared() const
	{
		return (x * x + y * y + z * z);
	}
	
	inline Vector4 Vector4::Lerp(Vector4 const &b, float t) const
	{
		return *this * (1.0f - t) + b * t;
	}
	
	inline Vector4 Vector4::Project(Vector4 const &b) const
	{
		float t = this->Dot(b) / b.LengthSquared();
		return b * t;
	}

	inline float Vector4::Normalize()
	{
		float l = this->Length();
		
		x /= l;
		y /= l;
		z /= l;
		w = 1.0f;
		
		return l;
	}

	inline float Vector4::Normalize(float l)
	{
		*this = this->Normalized(l);
		return l;
	}
	
	inline float Vector4::NormalizeW()
	{
		float l = w;
		*this = this->NormalizedW();
		return l;
	}
	
	inline Vector4 Vector4::Normalized() const
	{
		float l = this->Length();
		
		return Vector4(x / l,
					   y / l,
					   z / l,
					   1.0f);
	}
	
	inline Vector4 Vector4::Normalized(float l) const
	{
		return *this / l;
	}
	
	inline Vector4 Vector4::NormalizedW() const
	{
		return Vector4(x / w,
					   y / w,
					   z / w,
					   1.0f);
	}

	inline bool Vector4::IsZero() const
	{
		float const Epsilon = std::numeric_limits<float>::epsilon();

		if (std::abs(x) < Epsilon)
			if (std::abs(y) < Epsilon)
				if (std::abs(z) < Epsilon)
					return true;

		return false;
	}

	// Subscription operators =============================
	
	inline float Vector2::operator[](int Index) const
	{
		return (&x)[Index];
	}

	inline float &Vector2::operator[](int Index)
	{
		return (&x)[Index];
	}

	inline float Vector3::operator[](int Index) const
	{
		return (&x)[Index];
	}

	inline float &Vector3::operator[](int Index)
	{
		return (&x)[Index];
	}
	
	inline float Vector4::operator[](int Index) const
	{
		return (&x)[Index];
	}

	inline float &Vector4::operator[](int Index)
	{
		return (&x)[Index];
	}

	// Binary and unary addition operators ================
	
	inline Vector2 Vector2::operator+(Vector2 const &b) const
	{
		return Vector2(x + b.x, y + b.y);
	}

	inline Vector2 Vector2::operator+(float b) const
	{
		return Vector2(x + b, y + b);
	}

	inline Vector2 &Vector2::operator+=(Vector2 const &b)
	{
		x += b.x;
		y += b.y;
		return *this;
	}

	inline Vector2 &Vector2::operator+=(float b)
	{
		x += b;
		y += b;
		return *this;
	}

	inline Vector3 Vector3::operator+(Vector3 const &b) const
	{
		return Vector3(x + b.x, y + b.y, z + b.z);
	}
	
	inline Vector3 Vector3::operator+(float b) const
	{
		return Vector3(x + b, y + b, z + b);
	}

	inline Vector3 &Vector3::operator+=(Vector3 const &b)
	{
		x += b.x;
		y += b.y;
		z += b.z;
		return *this;
	}

	inline Vector3 &Vector3::operator+=(float b)
	{
		x += b;
		y += b;
		z += b;
		return *this;
	}

	inline Vector4 Vector4::operator+(Vector4 const &b) const
	{
		return Vector4(x + b.x, y + b.y, z + b.z);
	}

	inline Vector4 Vector4::operator+(float b) const
	{
		return Vector4(x + b, y + b, z + b);
	}

	inline Vector4 &Vector4::operator+=(Vector4 const &b)
	{
		x += b.x;
		y += b.y;
		z += b.z;
		return *this;
	}

	inline Vector4 &Vector4::operator+=(float b)
	{
		x += b;
		y += b;
		z += b;
		return *this;
	}

	// Binary and unary subtraction operators
	
	inline Vector2 Vector2::operator-(Vector2 const &b) const
	{
		return Vector2(x - b.x, y - b.y);
	}

	inline Vector2 Vector2::operator-(float b) const
	{
		return Vector2(x - b, y - b);
	}

	inline Vector2 &Vector2::operator-=(Vector2 const &b)
	{
		x -= b.x;
		y -= b.y;
		return *this;
	}

	inline Vector2 &Vector2::operator-=(float b)
	{
		x -= b;
		y -= b;
		return *this;
	}

	inline Vector3 Vector3::operator-(Vector3 const &b) const
	{
		return Vector3(x - b.x, y - b.y, z - b.z);
	}

	inline Vector3 Vector3::operator-(float b) const
	{
		return Vector3(x - b, y - b, z - b);
	}

	inline Vector3 &Vector3::operator-=(Vector3 const &b)
	{
		x -= b.x;
		y -= b.y;
		z -= b.z;
		return *this;
	}

	inline Vector3 &Vector3::operator-=(float b)
	{
		x -= b;
		y -= b;
		z -= b;
		return *this;
	}

	inline Vector4 Vector4::operator-(Vector4 const &b) const
	{
		return Vector4(x - b.x, y - b.y, z - b.z);
	}

	inline Vector4 Vector4::operator-(float b) const
	{
		return Vector4(x - b, y - b, z - b);
	}

	inline Vector4 &Vector4::operator-=(Vector4 const &b)
	{
		x -= b.x;
		y -= b.y;
		z -= b.z;
		return *this;
	}

	inline Vector4 &Vector4::operator-=(float b)
	{
		x -= b;
		y -= b;
		z -= b;
		return *this;
	}

	// Binary and unary multiplication operators ==========
	
	inline Vector2 Vector2::operator*(float b) const
	{
		return Vector2(x * b, y * b);
	}

	inline Vector2 &Vector2::operator*=(float b)
	{
		x *= b;
		y *= b;
		return *this;
	}

	inline Vector3 Vector3::operator*(float b) const
	{
		return Vector3(x * b, y * b, z * b);
	}

	inline Vector3 &Vector3::operator*=(float b)
	{
		x *= b;
		y *= b;
		z *= b;
		return *this;
	}
	
	inline Vector4 Vector4::operator*(float b) const
	{
		return Vector4(x * b, y * b, z * b, 1.0f);
	}

	inline Vector4 &Vector4::operator*=(float b)
	{
		x *= b;
		y *= b;
		z *= b;
		return *this;
	}

	// Binary and unary division operators ================
	
	inline Vector2 Vector2::operator/(float b) const
	{
		return Vector2(x / b, y / b);
	}

	inline Vector2 &Vector2::operator/=(float b)
	{
		x /= b;
		y /= b;
		return *this;
	}

	inline Vector3 Vector3::operator/(float b) const
	{
		return Vector3(x / b, y / b, z / b);
	}

	inline Vector3 &Vector3::operator/=(float b)
	{
		x /= b;
		y /= b;
		z /= b;
		return *this;
	}
	
	inline Vector4 Vector4::operator/(float b) const
	{
		return Vector4(x / b, y / b, z / b, 1.0f);
	}

	inline Vector4 &Vector4::operator/=(float b)
	{
		x /= b;
		y /= b;
		z /= b;
		return *this;
	}
}

#endif

