#include "Storage.h"
#include <iostream>
int main ()
{
	Storage & s = Storage::getInstance();
	
	cout << "Storage size: " << s.size() << endl;
	s.add(Car("Audi", "TT", 2005));
	cout << "Storage size: " << s.size() << endl;
	cout << "Storage[0]: " << s.get(0).getBrand() << endl;
	s.add(Car("Mersedec", "Benz", 2001));
	s.save("s.data");
	s.remove(0);
	cout << "Storage size: " << s.size() << endl;
	s.load("s.data");
	for(int i = 0; i < s.size(); ++i)
		cout << "Storage[" << i << "]: " << s.get(i).getBrand() << ", " << s.get(i).getModel() << ", " << s.get(i).getYear() << endl;
	return 0;
}