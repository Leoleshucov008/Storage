#include "Storage.h"

using namespace std;
//-------------------------------class Storage --------------------//
Storage* Storage::instance = NULL;

Storage & Storage::getInstance()
{
	if (instance == NULL)
		instance = new Storage();
	return *instance;
}

void Storage::save(const string fileName) const
{
	ofstream stream(fileName.c_str(), ios::out);
	for(auto it : data)
		it.toStream(stream);
	stream.close();
}

void Storage::load(const string fileName)
{
	ifstream stream(fileName.c_str(), ios::in);
	data.clear();
	while(!stream.eof())
	{
		Car buf;
		buf.fromStream(stream);
		data.push_back(buf);
		if (stream.peek() == EOF)
			break;
	}
	stream.close();
}

void Storage::add(Car & c)
{
	data.push_back(c);
}

Car & Storage::get(const unsigned int index)
{
	if (index < 0 || index >= data.size())
		throw BadIndex("Can not get element by index.\nStorage size: " + to_string(data.size()) + "\nIndex: "  + to_string(index));
	return data[index];
}

void Storage::remove(const unsigned int index) 
{
	if (index < 0 || index >= data.size())
		throw BadIndex("Can not remove element by index.\nStorage size: " + to_string(data.size()) + "\nIndex: "  + to_string(index));
	data.erase(data.begin() + index);
}


//----------------------class Car-------------------------------//
Car::Car(const string & b, const string & m, const unsigned int y)
{
	brand = b;
	model = m;
	year = y;
}

void Car::fromStream(ifstream & stream)
{
	stream >> brand;
	stream >> model;
	stream >> year;
}

void Car::toStream(ofstream & stream)
{
	stream << brand << ' ';
	stream << model << ' ';
	stream << year << ' ';
}

