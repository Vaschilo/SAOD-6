#pragma once
#include <iostream>
using namespace std;

class Team
{
private:
	string name;
	int power;
public:
	Team() { this->name = "Std_name"; this->power = 0; }
	Team(string name, int Power) { this->name = name; this->power = Power; }
	~Team() {}

	string GetName() { return this->name; }
	int GetPower() { return this->power; }

	void operator = (Team a)
	{
		this->name = a.name;
		this->power = a.power;
	}
	bool operator > (Team a)
	{
		if (this->power > a.power) return 1;
		return 0;
	}
	friend ostream& operator <<(ostream& out, Team a)
	{
		out << a.name << " " << a.power;
		return out;
	}
	friend istream& operator >>(istream& in, Team& a)
	{
		in >> a.name >> a.power;
		return in;
	}
};
