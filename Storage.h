#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <string>
#include <fstream>

using namespace std;

//-------------------------------class Exception --------------------/
class Exception
{
	const string mes;
public:
	Exception (string m): mes(m) {}
	string getMessage() { return mes; }
	virtual ~Exception(){}
};

class BadIndex : public Exception
{
public:
	BadIndex(string m) : Exception("Bad index\n" + m) {}
};

//-------------------------------class Item ------------------------/
class Item
{
	
public:
	virtual ~Item() {}

	virtual void fromStream(ifstream & stream) = 0;
	virtual void toStream(ofstream & stream) = 0;
};

//-------------------------------class Car -------------------------/
class Car : public Item
{
	string brand;
	string model;
	unsigned int year; // year of construction

public:
	Car(){}
	Car(const string & b, const string & m, const unsigned int y);
	
	void fromStream(ifstream & stream);
	void toStream(ofstream & stream);

	// Getters
	string getBrand() const { return brand; }
	string getModel() const { return model; }
	unsigned int getYear() const { return year; }
	
	// Setters
	void setBrand(string & b) { brand = b; }
	void setModel(string & m) { model = m; }
	void setYear(const unsigned int y) { year = y; }

};

//-------------------------------class Storage ----------------------/
class Storage
{
	static Storage *instance;
	vector<Car> data;

	Storage(){};
	Storage(const Storage &){};
	Storage & operator = (const Storage &);

public:
	~Storage() {instance = NULL;}
	void add(Car & c); //Add new elem to storage
	Car & get(const unsigned int index); //Get elem by index
	void remove(const unsigned int index); // Remove elem by index
	
	void save(const string fileName) const; //Save to file
	void load(const string fileName); //Load from file

	unsigned int size() { return data.size(); }

	static Storage & getInstance();
};
#endif