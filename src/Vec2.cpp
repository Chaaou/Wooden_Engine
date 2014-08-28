/*
 * Vec2.cpp
 *
 *  Created on: 25 авг. 2014 г.
 *      Author: snickers
 */

#include "Vec2.h"

Vec2::Vec2() {
	this->x = 0;
	this->y = 0;
}

Vec2::Vec2(const float& x, const float& y) {
	this->x = x;
	this->y = y;
}

float Vec2::GetLength(){
	return sqrt(x*x + y*y);
}

Vec2 Vec2::GetNormalized(){
	float len = GetLength();
	return Vec2(x/len, y/len);
}

Vec2 Vec2::GetRotated(const double& angle){
	double rad = angle*GRADUS;
	double sn = sin(rad);
	double cs = cos(rad);
	return Vec2(  (float)(x * cs - y * sn), (float)(x * sn + y * cs) );
}

const Vec2 operator+(const Vec2& left, const Vec2& right){
	 return Vec2(left.x + right.x, left.y + left.y);
}

const Vec2 operator-(const Vec2& left, const Vec2& right){
	 return Vec2(left.x - right.x, left.y - left.y);
}

const Vec2 operator*(const Vec2& left, const float& scale){
	return Vec2(left.x * scale, left.y * scale);
}

Vec2& operator+=(Vec2& left, const Vec2& right){
	left.x += right.x;
	left.y += right.y;
	return left;
}

Vec2& operator-=(Vec2& left, const Vec2& right){
	left.x -= right.x;
	left.y -= right.y;
	return left;
}

bool operator==(Vec2& left, Vec2& right) {
	return left.GetLength() == right.GetLength();
}

