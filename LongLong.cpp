#include "LongLong.h"
#include <string>

LongLong::LongLong()
{
	high = 0;
	low = 0;
}

LongLong::LongLong(long _high, unsigned long _low)
{
	high = _high;
	low = _low;
}

LongLong::LongLong(long num)
{
	if (num < 0)
		high = -1;
	else
		high = 0;

	low = static_cast<unsigned long>(num);
}

void LongLong::setHigh(long _high)
{
	high = _high;
}

void LongLong::setLow(unsigned long _low)
{
	low = _low;
}

std::string LongLong::toString()
{
	return std::to_string(to64());
}

long LongLong::getHigh()
{
	return high;
}

unsigned long LongLong::getLow()
{
	return low;
}

long long LongLong::to64()
{
	return (static_cast<long long>(high) << 32) | low;
}

LongLong LongLong::from64(long long num)
{
	long _high = static_cast<long>(num >> 32);
	unsigned long _low = static_cast<unsigned long>(num & 0xFFFFFFFFULL);
	return LongLong(_high, _low);
}

bool LongLong::equal(LongLong second)
{
	return high == second.high && low == second.low;
}

bool LongLong::notEqual(LongLong second)
{
	return !equal(second);
}

bool LongLong::less(LongLong second)
{
	if (high != second.high)
		return high < second.high;
	return low < second.low;
}

bool LongLong::more(LongLong second)
{
	if (high != second.high)
		return high > second.high;
	return low > second.low;;
}

bool LongLong::moreEqual(LongLong second)
{
	return !less(second);
}

bool LongLong::lessEqual(LongLong second)
{
	return !more(second);
}

LongLong LongLong::add(LongLong second)
{
	unsigned long nLow = low + second.low;
	long nHigh = high + second.high;

	if (nLow < low || nLow < second.low)
		nHigh++;

	return LongLong(nHigh, nLow);
}

LongLong LongLong::subtr(LongLong second)
{
	unsigned long nLow = low - second.low;
	long nHigh = high - second.high;

	if (low < second.low)
		nHigh--;

	return LongLong(nHigh, nLow);
}

LongLong LongLong::mult(LongLong second)
{
	return from64(to64() * second.to64());
}

// Если делитель ноль, возвращает 0
LongLong LongLong::div(LongLong second)
{
	if (second.notEqual(LongLong()))
		return from64(to64() / second.to64());
	else
		return LongLong();
}

// Если делитель ноль, возвращает 0
LongLong LongLong::mod(LongLong second)
{
	if (second.notEqual(LongLong()))
		return from64(to64() % second.to64());
	else
		return LongLong();
}