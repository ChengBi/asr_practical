#include "asr_array.h"
// #include "exception.h"
using namespace asr;

template <class Elem> Scalar<Elem>::Scalar (int n) {
	this->length = n;
	// this->value = new Elem[this->length];
};

template <class Elem> Scalar<Elem>::~Scalar () {
	// delete[] this->value;
	this->length = 0;
};

template <class Elem> Elem Scalar<Elem>::at (const int index) const {
	if (index >= this->length || index < 0) {
		// std::string err = "Invalid Index!";
		// throw IndexExceedException<Elem>();
	};
	// return this->value[index];
};

template <class Elem> int Scalar<Elem>::size () const {
	return this->length;
};

template <class Elem> void Scalar<Elem>::clear () {

}
