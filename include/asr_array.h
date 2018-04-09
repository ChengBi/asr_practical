#ifndef ARRAY_H
#define ARRAY_H
#include <cstdio>
// #include <string>

namespace asr {

	template <class Elem> class Array {
	public:
		virtual Elem at(const int) const = 0;
		virtual int size() const = 0;
		virtual void clear() = 0;
	};

	template <class Elem> class Scalar: public Array<Elem> {
	private:
		Elem* value;
		int length;
	public:
		Scalar(int n);
		~Scalar();
		Elem at(const int index) const;
		int size() const;
		void clear();
	};
};




#endif
