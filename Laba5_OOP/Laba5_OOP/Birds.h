#pragma once
#include <iostream>

using namespace std;

//�������� ������-������ Birds

class Birds {
private:
	string Class_Name = "Birds";
public:
	string color; //����
	int age; //�������
	Birds() {
		color = "";
		age = 0;
		cout << "����������� �� ��������� Birds()\n";
	}
	Birds(string color, int age) {
		this->color = color;
		this->age = age;
		cout << "����������� � ����������� Birds(string color)\n";
	}
	Birds(Birds& bird) {
		color = bird.color;
		age = bird.age;
		cout << "����������� ���������� Birds(Birds& bird)\n";
	}
	//����������� �����, ������� ��������������� � �������-�����������
	//��� �������,�� ������� ����������� ������ ����������, ����� ������
	//������������ ������ ����� ���������
	virtual string ClassName() {
		cout << "����������� ����� ClassName Birds\n";
		return Class_Name;
	}
	virtual bool isA(string cn) {
		cout << "����������� ����� isA Birds\n";
		if (Class_Name == cn)
			return true;
		else
			return false;
	}
	void Method() {
		cout << "����� Birds\n";
	}
	virtual ~Birds() {
		cout << "����������� ���������� Birds\n";
	}

	void Inheritance() {
		cout << "����������� ����� ������ Bird - Inheritance\n";
	}
};
	//���������� ������-������� Swan_Bird
class Swan_Bird :public Birds {
private:
	string Class_Name = "Swan_Bird";
public:
	Swan_Bird() {
		color = "White";
		age = 0;
		cout << "����������� �� ��������� Swan_Bird()\n";
	}
	Swan_Bird(string color, int age) {
		this->color = color;
		this->age = age;
		cout << "����������� c ����������� Swan_Bird(string color)\n";
	}
	Swan_Bird(Swan_Bird& bird) {
		color = bird.color;
		age = bird.age;
		cout << "����������� Swan_Bird(Birds& bird)\n";
	}
	string ClassName() {
		cout << "��������������� ����� �lassName Swan_Bird\n";
		return Class_Name;
	}
	bool isA(string cn) {
		cout << "��������������� ����� isA Swan_Bird\n";
		if (Class_Name == cn)
			return true;
		else
			return false;
	}
	void Method() {
		cout << "����� Swan_Bird\n";
	}
	~Swan_Bird() {
		cout << "���������� Swan_Bird\n";
	}
};

//���������� ������-������� Crow_Bird
class Crow_Bird :public Birds {
private:
	string Class_Name = "Crow_Bird";
public:
	Crow_Bird() {
		color = "Black";
		age = 0;
		cout << "����������� �� ��������� Crow_Bird()\n";
	}
	Crow_Bird(string color, int age) {
		this->color = color;
		this->age = age;
		cout << "����������� � ����������� Crow_Bird(string �olor)\n";
	}
	Crow_Bird(Crow_Bird& bird) {
		color = bird.color;
		age = bird.age;
		cout << "����������� ���������� Crow_Bird(Birds& bird)\n";
	}
	string ClassName() {
		cout << "��������������� ����� �lassName Crow_Bird\n";
		return Class_Name;
	}
	bool isA(string cn) {
		cout << "��������������� ����� isA Crow_Bird\n";
		if (Class_Name == cn)
			return true;
		else
			return false;
	}
	void Method() {
		cout << "����� Crow_Bird\n";
	}
	~Crow_Bird() {
		cout << "���������� Crow_Bird\n";
	}
	
};