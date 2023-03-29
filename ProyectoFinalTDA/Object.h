#ifndef OBJECT_H
#define OBJECT_H

#include <string>
using namespace std;

class Object {
public:
	//Declaraci�n de m�todos para la clase Object
	Object();
	virtual ~Object();
	virtual string toString() = 0;
	virtual bool equals(Object*) = 0;
};

#endif