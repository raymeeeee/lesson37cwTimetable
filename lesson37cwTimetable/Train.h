#pragma once
#include "Time_.h"
#include <string>
#include <iostream>
using namespace std;


class Train
{
protected:
	string number;
	string station;
	Time_ departure;
	int duration;
public:
	Train() {
		number = "undefined";
		station = "undefined";
		duration = 0;
	}

	Train(string number, string station, Time_ departure, int duration) {
		this->number = number;
		this->station = station;
		this->departure = departure;
		this->duration = duration;
	}

	void setDeparture(Time_ departure) { this->departure = departure; }
	void setDuration(int duration) { this->duration = duration; }

	string getNumber()const { return number; }
	string getStation()const { return station; }
	Time_ getDeparture()const { return departure; }
	int getDuration()const { return duration; }

	void showLine()const {
		cout << departure << " - " << departure + duration << " " << number << " " << station << endl;
	}

	void show()const {
		cout << "Number: " << number << endl;
		cout << "Station: " << station << endl;
		cout << "Departure: " << departure << endl;
		cout << "Duration: " << duration << " minutes" << endl;
	}
};

