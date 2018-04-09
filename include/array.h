#ifndef ARRAY_H
#define ARRAY_H
#include <cstdio>
#include <string>
#include <sstream>
#include "exception.h"
// #include <string>

namespace asr {

	template <class Elem> class Array {
	public:
		virtual Elem at(const int) const = 0;
		virtual int size() const = 0;
		virtual void clear() = 0;
		virtual std::string tostring() const = 0;
	};

	template <class Elem> class Scalar: public Array<Elem> {
	private:
		Elem* value;
		int length;
		int tail_index;
		void deleteall();
	public:
		Scalar(const int);
		~Scalar();
		Elem at(const int) const;
		int size() const;
		void clear();
		std::string tostring() const;
		Scalar<Elem> operator + (Scalar<Elem>);
		void operator << (Elem);
	};
};
template <class Elem> void asr::Scalar<Elem>::deleteall() {
	delete[] this->value;
	this->length = 0;
	this->tail_index = 0;
}

template <class Elem> asr::Scalar<Elem>::Scalar(const int n) {
	this->length = n;
	this->value = new Elem[this->length];
}

template <class Elem> asr::Scalar<Elem>::~Scalar() {
	this->deleteall();
}

template <class Elem> Elem asr::Scalar<Elem>::at(const int index) const {
	try {
		if (index < 0 || index >= this->length) {
			throw asr::IndexExceedException();
		} else {
			return this->value[index];
		}
	} catch (asr::IndexExceedException& e) {
		printf("\033[0;31;43m%s\033[0m", e.what());
		exit(-1);
	}

}

template <class Elem> int asr::Scalar<Elem>::size() const {
	return this->length;
}

template <class Elem> void asr::Scalar<Elem>::clear() {
	this->deleteall();
	this->value = new Elem[this->length];
}

template <class Elem> std::string asr::Scalar<Elem>::tostring() const {
	std::string str = "Value is: ";
	std::stringstream ss;
	std::string temp = "";
	// for (int i = 0; i < this->length; i ++) {
	// 	ss << this->value[i];
	// 	ss >> temp;
	// 	str += temp;
	// 	ss.clear();
	// 	temp = "";
	// }
	// ss.close();
	return str;
}

template <class Elem> asr::Scalar<Elem> asr::Scalar<Elem>::operator + (asr::Scalar<Elem> b) {
	try {
		if ((this->size() != b.size()) || this->tail_index != this->length) {
			// printf("catch1");
			throw asr::ArraySizeMismatchException();
		} else {
			// printf("true");
			for (int i = 0; i < this->size(); i ++) {
				this->value[i] += b.at(i);
			}
			return *this;
		}
		// printf("here1");
	} catch (asr::ArraySizeMismatchException& e) {
		// printf("catch");
		printf("\033[0;31;43m%s\033[0m", e.what());
		exit(-1);
	}
}

template <class Elem> void asr::Scalar<Elem>::operator << (Elem value) {
	if (this->tail_index == this->length) {
		printf("This scalar is full, please clear it first if you want to add elements!\n");
	} else {
		this->value[this->tail_index] = value;
		this->tail_index += 1;
	}
}






#endif
