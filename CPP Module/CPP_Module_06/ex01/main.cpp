#include "Serializer.hpp"

int main()
{
	Data		d;
	uintptr_t	u;
	Data		*tmp;

	d.data = 42;
	u = Serializer::serialize(&d);
	tmp = Serializer::deserialize(u);
	
	cout << "pointer of d : " << &d << endl;
	cout << "Serialized d : " << u << endl;
	cout << "Deserialized u : " << tmp << endl;
	cout << "check struct member : " << tmp->data << endl;

	return (0);
}