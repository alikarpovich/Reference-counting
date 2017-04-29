#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

class MyException : public exception {
public:
	char* what() {
		return "Index is out of range\n";
	}
};

class Char {
private:

	class Referencable {
	private:
		int kol;
		friend class Char;
		char* s;
	public:
		Referencable() : kol(1) {}
		Referencable(Referencable &r) : kol(1) { s = r.s; }
		~Referencable() {}
		int get() const { return kol; }
		void incr() { kol++; }
		void decr() {
			if (--kol == 0) this->~Referencable();
		}
		void set(int n) { kol = n; }
	};
	Referencable* Ref;
public:
	void Clone(const Char &);
	Char();
	Char(const Char &);
	Char(const char*);
	~Char() {
		Ref->decr();
	}

	char* GetChar() const {
		char* str = new char[strlen(Ref->s) + 1];
		strcpy(str, Ref->s);
		return str;
	}

	Char &operator = (const Char &);
	bool operator == (const Char &);
	bool operator < (const Char &);
	bool operator > (const Char &);
	Char operator + (const Char &);
	int length() const;
	char& operator [] (int);

	friend ostream &operator<<(ostream &, const Char &);
	friend istream &operator>>(istream &, Char &);

	void Str(const char* str) {
		Ref->decr();
		Ref = new Referencable;
		Ref->s = new char[strlen(str) + 1];
		strcpy(Ref->s, str);
	}
};