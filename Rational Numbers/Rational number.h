#pragma once
#ifndef _RATIONAL_NUMBERS_H
#define _RATIONAL_NUMBERS_H
#include <iostream>

namespace RATIONAL_NUMBERS
{
	template<typename T>
	class RatNum
	{
	private:
		T numerator;
		T denominator;

		RatNum& Reduction() {
			auto nod = NOD(numerator, denumerator);
			numerator /= nod;
			denumerator /= nod;

			return *this;
		}

		T NOD(const T& lhs, const T& rhs) const {
			auto a = lhs;
			auto b = rhs;

			if (a < 0) {
				a *= -1;
			}
			while (b){
				a %= b;
				std::swap(a, b);
			}
			return a;
		} 
		T NOK(const T& lhs, const T& rhs) const {
			auto a = lhs;
			auto b = rhs;

			return a*b / NOD(a, b);
		}
	public:
		RatNum();
		RatNum(T, T);
		RatNum(const RatNum&);

		RatNum operator+(const RatNum& vv) const;
		RatNum operator-(const RatNum& vv) const;
		RatNum operator*(const RatNum& vv) const;
		RatNum operator/(const RatNum& vv) const;
		RatNum& operator=(const RatNum& vv);

		operator double() const;
		operator int() const;

		inline T get_numerator() const {
			return numerator;
		}
		inline T get_denominator() const {
			return denominator;
		}

		friend std::ostream& operator<<(std::ostream& os, const RatNum& vv) {
			os << vv.numerator << "/" << vv.denominator;
			return os;
		}
	};
}
namespace RatNum = RATIONAL_NUMBERS;
#endif