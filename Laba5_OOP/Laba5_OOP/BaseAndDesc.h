#pragma once
#include <iostream>

using namespace std;

//Реализация класса Base и его потомка Desc

class Base {
public:
	Base() {
		cout << "Конструктор Base()\n";
	}
	Base(Base* obj) {
		cout << "Конструктор Base(Base* obj)\n";
	}
	Base(Base& obj) {
		cout << "Конструктор Base(Base& obj)\n";
	}
	~Base() {
		cout << "Конструктор Base()\n";
	}
};

class Desc : public Base {
public:
	Desc() {
		cout << "Конструктор Desc()\n";
	}
	Desc(Desc* obj) {
		cout << "Конструктор Desc(Desc* obj)\n";
	}
	Desc(Desc& obj) {
		cout << "Конструктор Desc(Desc& obj)\n";
	}
	~Desc() {
		cout << "Конструктор Desc()\n";
	}
};