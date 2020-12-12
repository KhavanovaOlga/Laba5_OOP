#pragma once
#include <iostream>

using namespace std;

//Создание класса-предка Birds

class Birds {
private:
	string Class_Name = "Birds";
public:
	string color; //цвет
	int age; //возраст
	Birds() {
		color = "";
		age = 0;
		cout << "Конструктор по умолчанию Birds()\n";
	}
	Birds(string color, int age) {
		this->color = color;
		this->age = age;
		cout << "Конструктор с параметрами Birds(string color)\n";
	}
	Birds(Birds& bird) {
		color = bird.color;
		age = bird.age;
		cout << "Конструктор копирующий Birds(Birds& bird)\n";
	}
	//Виртуальный метод, который преопределяется в классах-наследниках
	//Тип объекта,на которых указывается ссылка определяет, какая версия
	//виртуального метода будет выполнена
	virtual string ClassName() {
		cout << "Виртуальный метод ClassName Birds\n";
		return Class_Name;
	}
	virtual bool isA(string cn) {
		cout << "Виртуальный метод isA Birds\n";
		if (Class_Name == cn)
			return true;
		else
			return false;
	}
	void Method() {
		cout << "Метод Birds\n";
	}
	virtual ~Birds() {
		cout << "Виртуальный деструктор Birds\n";
	}

	void Inheritance() {
		cout << "Наследуемый метод класса Bird - Inheritance\n";
	}
};
	//Реализация класса-потомка Swan_Bird
class Swan_Bird :public Birds {
private:
	string Class_Name = "Swan_Bird";
public:
	Swan_Bird() {
		color = "White";
		age = 0;
		cout << "Конструктор по умолчанию Swan_Bird()\n";
	}
	Swan_Bird(string color, int age) {
		this->color = color;
		this->age = age;
		cout << "Конструктор c параметрами Swan_Bird(string color)\n";
	}
	Swan_Bird(Swan_Bird& bird) {
		color = bird.color;
		age = bird.age;
		cout << "Конструктор Swan_Bird(Birds& bird)\n";
	}
	string ClassName() {
		cout << "Переопределимый метод СlassName Swan_Bird\n";
		return Class_Name;
	}
	bool isA(string cn) {
		cout << "Переопределимый метод isA Swan_Bird\n";
		if (Class_Name == cn)
			return true;
		else
			return false;
	}
	void Method() {
		cout << "Метод Swan_Bird\n";
	}
	~Swan_Bird() {
		cout << "Деструктор Swan_Bird\n";
	}
};

//Реализация класса-потомка Crow_Bird
class Crow_Bird :public Birds {
private:
	string Class_Name = "Crow_Bird";
public:
	Crow_Bird() {
		color = "Black";
		age = 0;
		cout << "Конструктор по умолчанию Crow_Bird()\n";
	}
	Crow_Bird(string color, int age) {
		this->color = color;
		this->age = age;
		cout << "Конструктор с параметрами Crow_Bird(string сolor)\n";
	}
	Crow_Bird(Crow_Bird& bird) {
		color = bird.color;
		age = bird.age;
		cout << "Конструктор копирующий Crow_Bird(Birds& bird)\n";
	}
	string ClassName() {
		cout << "Переопределимый метод СlassName Crow_Bird\n";
		return Class_Name;
	}
	bool isA(string cn) {
		cout << "Переопределимый метод isA Crow_Bird\n";
		if (Class_Name == cn)
			return true;
		else
			return false;
	}
	void Method() {
		cout << "Метод Crow_Bird\n";
	}
	~Crow_Bird() {
		cout << "Деструктор Crow_Bird\n";
	}
	
};