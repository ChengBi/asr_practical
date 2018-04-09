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
		virtual Elem& at(const int) const = 0;
		virtual int size() const = 0;
		virtual void clear() = 0;
		virtual std::string tostring() const = 0;
	};

	template <class Elem> class Scalar: public Array<Elem> {
	private:
		void deleteall();
	public:
		Elem* value;
		int length;
		int tail_index;
		Scalar(const int);
		~Scalar();
		Elem& at(const int) const;
		int size() const;
		void clear();
		std::string tostring() const;
		bool isFull() const;
		Scalar<Elem> operator + (const Scalar<Elem>&) const;
		void operator << (Elem);
		// Elem& operator [] (const int);
		void operator = (const Scalar<Elem>&);
	};
}

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

template <class Elem> Elem& asr::Scalar<Elem>::at(const int index) const {
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
	for (int i = 0; i < this->length; i ++) {
		ss << this->value[i];
		ss >> temp;
		str += temp + " ";
		ss.clear();
		temp = "";
	}
	// ss.close();
	return str;
}
template <class Elem> bool asr::Scalar<Elem>::isFull() const {
	if (this->length == this->tail_index)
		return true;
	return false;
}

template <class Elem> asr::Scalar<Elem> asr::Scalar<Elem>::operator + (const asr::Scalar<Elem>& b) const {
	// std::cout << this->size() << std::endl;
	// std::cout << b.size() << std::endl;
	// std::cout << this->isFull() << std::endl;
	// std::cout << b.isFull() << std::endl;
	// std::cout << "---------------------------------" << std::endl;
	try {
		if ((this->size() != b.size()) || !this->isFull() || !b.isFull()) {
			// printf("catch1");
			throw asr::ArraySizeMismatchException();
		} else {
			// printf("true");
			std::cout << this->length << std::endl;
			asr::Scalar<Elem> res(this->length);
			for (int i = 0; i < this->size(); i ++) {
				// std::cout << i << "=>" << b.at(i) << " " << this->at(i) << " " << res.at(i) << std::endl;
				// res[i] = b.at(i) + this->at(i);
				std::cout << i <<" " << res.value[i] <<std::endl;
				res.value[i] = 0;
				std::cout << i <<" " << res.value[i] <<std::endl;
				// this->at(i) = 1;
				// std::cout << i << "=>"  << b.at(i) << " " << this->at(i) << " " << res.at(i) << std::endl;
			}
			return res;
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

template <class Elem> void asr::Scalar<Elem>::operator = (const asr::Scalar<Elem> element) {
	if (this->size() != element.size()) {
		this->deleteall();
		this->value = new Elem[element.size()];
	}
	for (int i = 0; i< this->length; i ++ ) {
		this->value[i] = element.at(i);
	}
}

// template <class Elem> Elem& asr::Scalar<Elem>::operator [] (const int index) {
// 	return this->at(index);
// }

#endif
