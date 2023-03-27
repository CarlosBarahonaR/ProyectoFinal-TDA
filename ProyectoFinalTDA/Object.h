#ifndef OBJECT_H
#define OBJECT_H

#include <string>
using namespace std;

class Object {
public:
	//Declaración de métodos para la clase Object
	virtual string toString() = 0;
	virtual bool equals(Object*) = 0;
};

#endif