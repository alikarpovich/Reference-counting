#include "Header.h"

Char::Char() {
	Ref = new Referencable;
	Ref->s = new char[1];
	strcpy(Ref->s, "");
}

Char::Char(const char* str) {
	Ref = new Referencable;
	Ref->s = new char[strlen(str) + 1];
	strcpy(Ref->s, str);
}

Char::Char(const Char &e) : Ref(e.Ref) {
	Ref->incr();
}

Char &Char::operator=(const Char &e) {
	if (this == &e)
		return *this;
	Ref->decr();
	this->Ref = e.Ref;
	Ref->incr();

	return *this;
}

void Char::Clone(const Char &e) {
	Ref->decr();
	Ref = new Referencable;
	Ref->s = new char[strlen(e.Ref->s) + 1];
	strcpy(Ref->s, e.Ref->s);
}

Char Char::operator +(const Char &e) {
	char* tmp = new char[strlen(this->Ref->s) + strlen(e.Ref->s) + 1];
	strcpy(tmp, this->Ref->s);
	strcat(tmp, e.Ref->s);
	Char temp(tmp);
	return temp;
}

bool Char::operator<(const Char &e) {
	return (strcmp((*this).Ref->s, e.Ref->s) == -1);
}

bool Char::operator>(const Char &e) {
	return (strcmp((*this).Ref->s, e.Ref->s) == 1);
}

bool Char::operator==(const Char &e) {
	return (!strcmp((*this).Ref->s, e.Ref->s));
}

int Char::length() const {
	return strlen((*this).Ref->s);
}

char &Char::operator[](int n) {
	if (n >= strlen((*this).Ref->s)) {
		throw MyException();
	}
	if (n < 0)
		throw MyException();
	return (*this).Ref->s[n];
}

ostream &operator<<(ostream &o, const Char &e) {
	cout << "\n" << e.GetChar() << "\n";
	return o;
}

istream &operator>>(istream &i, Char &e) {
	char str[100];
	i.getline(str, 99, '\n');
	e.Str(str);
	return i;
}