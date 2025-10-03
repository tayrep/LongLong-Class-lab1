#pragma once
#include <string>

class LongLong {
	long high;
	unsigned long low;

public:
	LongLong();
	LongLong(long _high, unsigned long _low);
	LongLong(long num);

	void setHigh(long _high);
	void setLow(unsigned long _low);

	std::string toString();
	long getHigh();
	unsigned long getLow();

	long long to64();
	LongLong from64(long long num);

	bool equal(LongLong second);
	bool notEqual(LongLong second);
	bool less(LongLong second);
	bool more(LongLong second);
	bool moreEqual(LongLong second);
	bool lessEqual(LongLong second);

	LongLong add(LongLong second);
	LongLong subtr(LongLong second);
	LongLong mult(LongLong second);
	LongLong div(LongLong second);
	LongLong mod(LongLong second);
};