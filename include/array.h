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
		void deleteall();
		int length;
		int tail_index;
		Elem* value;
	public:
		Scalar(const int);
		Scalar();
		~Scalar();
		int size() const;
		void clear();
		bool isFull() const;
		Elem at(const int) const;
		std::string tostring() const;
		void operator << (Elem);
		Elem& operator [] (const int);
		Scalar<Elem>& operator + (const Scalar<Elem>&) const;
		Scalar<Elem>& operator = (const Scalar<Elem>&);
	};
}

template <class Elem> void asr::Scalar<Elem>::deleteall() {
	// std::cout << "---------- delete ------------" << std::endl;
	delete[] this->value;
	this->length = 0;
	this->tail_index = 0;
}

template <class Elem> asr::Scalar<Elem>::Scalar(const int n) {
	this->length = n;
	this->value = new Elem[this->length];
	this->tail_index = 0;
	for (int i = 0; i < this->length; i ++) {
		this->value[i] = 0;
	}
}

template <class Elem> asr::Scalar<Elem>::~Scalar() {
	this->deleteall();
}

template <class Elem> Elem asr::Scalar<Elem>::at(const int index) const {
	try {
		if (index < 0 || index >= this->size()) {
			throw asr::IndexExceedException();
		} else {
			return this->value[index];
		}
	} catch (asr::IndexExceedException& e) {
		printf("\033[0;31;43m%s\033[0m\n", e.what());
		exit(-1);
	}

}

template <class Elem> int asr::Scalar<Elem>::size() const {
	return this->length;
}

template <class Elem> void asr::Scalar<Elem>::clear() {
	this->deleteall();
	this->value = new Elem[this->size()];
}

template <class Elem> std::string asr::Scalar<Elem>::tostring() const {
	std::string str = "Value is: ";
	for (int i = 0; i < this->size(); i ++) {
		std::stringstream ss;
		ss << this->value[i];
		str += ss.str() + " ";
	}
	return str;
}
template <class Elem> bool asr::Scalar<Elem>::isFull() const {
	if (this->size() == this->tail_index)
		return true;
	return false;
}

template <class Elem> asr::Scalar<Elem>& asr::Scalar<Elem>::operator + (const asr::Scalar<Elem>& b) const {
	try {
		if ((this->size() != b.size()) || !this->isFull() || !b.isFull()) {
			throw asr::ArraySizeMismatchException();
		} else {
			asr::Scalar<Elem>* res = new asr::Scalar<Elem>(this->size());
			for (int i = 0; i < this->size(); i ++) {
				(*res)[i] = b.at(i) + this->at(i);
			}
			return *res;
		}
		// printf("here1");
	} catch (asr::ArraySizeMismatchException& e) {
		// printf("catch");
		printf("\033[0;31;43m%s\033[0m\n", e.what());
		exit(-1);
	}
}

template <class Elem> void asr::Scalar<Elem>::operator << (Elem value) {
	if (this->tail_index == this->size()) {
		printf("This scalar is full, please clear it first if you want to add elements!\n");
	} else {
		this->value[this->tail_index] = value;
		this->tail_index += 1;
	}
}

template <class Elem> asr::Scalar<Elem>& asr::Scalar<Elem>::operator = (const asr::Scalar<Elem>& element) {
	if (this->size() != element.size()) {
		this->deleteall();
		this->value = new Elem[element.size()];
		this->length = element.size();
	}
	for (int i = 0; i< this->size(); i ++ ) {
		this->value[i] = element.at(i);
	}
	return *this;
}

template <class Elem> Elem& asr::Scalar<Elem>::operator [] (const int index) {
	try {
		if (index < 0 || index >= this->size()) {
			throw asr::IndexExceedException();
		} else {
			return this->value[index];
		}
	} catch (asr::IndexExceedException& e) {
		printf("\033[0;31;43m%s\033[0m\n", e.what());
		exit(-1);
	}
}

#endif
