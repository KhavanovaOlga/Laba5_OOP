// Laba5_OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Birds.h"
#include "BaseAndDesc.h"

using namespace std;

//Для проверки механизма передачи объектов как параметров в функции создаем три функции:
void func1(Base obj) {
    cout << "***** func1 *****\n";
}
void func2(Base* obj) {
    cout << "***** func2 *****\n";
}
void func3(Base& obj) {
    cout << "***** func3 *****\n";
}

//Форматирование по пунктам действий в отладке
void format(int count) {
    int N = 12;
    cout << endl;
    for (int i = 0; i < N; ++i)
        cout << "*";
    cout << " " << count << " ";
    for (int i = 0; i < N; ++i)
        cout << "*";
    cout << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    format(1);
    cout << "Создание объектов классов Birds, Swan_Bird и Crown_Bird(приведенное к классу Birds):\n";
    Birds* birds1 = new Birds(); //new Birds()-тип объекта Birds
    Swan_Bird* swan_bird = new Swan_Bird();
    //Создание объекта класса Crow_Bird и перемещение его в переменную типа класса-предка
    Birds* birds2 = new Crow_Bird();

    format(2);
    cout << "Проверка на принадлежность к определенному классу:\n\n";
    //true-сам класс или предок(вирт.метод)
    cout << "(Проверка через метод isA)\n";
    cout << birds1->isA("Birds") << endl;
    cout << swan_bird->isA("Swan_Bird") << endl;
    cout << birds2->isA("Birds") << endl;

    //Перекрываемый метод
    cout << "\n(Проверка через метод ClassName)\n";
    cout << birds1->ClassName() << endl;
    cout << swan_bird->ClassName() << endl;
    cout << birds2->ClassName() << endl;

    //Наследуемый метод
    birds1->Inheritance();
    swan_bird->Inheritance();
    birds2->Inheritance();

    format(3);
    cout << "Безопасное приведение типов (dynamic_cast):\n";
    //Нужно для того, чтобы выполнить операции, определенные в производном классе, для объекта, который,
    //принадлежит производному классу, но при этом есть только указатель или ссылка на базовый класс, 
    //посредством которой нужно манипулировать объектом
    Crow_Bird* crow_bird = dynamic_cast<Crow_Bird*>(birds2);
    cout << crow_bird->ClassName() << endl;
    crow_bird->Method();
    birds2->Method();

    //Опасное приведение типов и предварительная проверка типа с помощью реализованного метода isA.
    format(4);
    Crow_Bird* crow_bird1 = new Crow_Bird;
    cout << "\nОпасное приведение типов:\n";
    if (birds2->isA("Crow_Bird"))
        crow_bird1 = (Crow_Bird*)birds2;//объект birds2 приводим к типу crow_bird
    cout << crow_bird1->ClassName() << endl;

    //Работа с деструкторами
    format(5);
    cout << "Удаление объектов с помощью виртуального деструктора:\n";
    delete birds1;
    delete swan_bird;
    delete birds2;
    cout << "\nУдаление объектов с помощью невиртуального деструктора:\n";
    Base* probdel = new Desc();
    delete probdel;

    //Вызов функций с объектами классов Base и Desc в качестве параметров
    format(6);
    cout << "Передача объектов классов Base и Desс в качестве параметров функций:\n\n";
    cout << "\tBase:\n";
    Base base1;
    func1(base1); 
    //Объекты передаем функциям в качестве аргументов так же, как передаются данные других типов. 
    //При этом будет создан локальный экземпляр объекта, являющийся независимой копией переданного объекта.
    //После чего отрабатывается уже сама функция.
    cout << endl;
    //Указатель на объект класса Base.
    Base* base2 = new Base();
    func2(base2);
    //Функция принимает указатель на объект, поэтому конструктор копирования не вызывается, как и деструктор
    cout << endl;
    Base base3;
    func3(base3);
    //Функция принимает саму ссылку на объект, поэтому конструктор копирования не вызывается, как и деструктор
    cout << endl;

    cout << "\tDesc:\n";
    Desc desc1; 
    //Сначала создается конструктор по умолчанию у предка, затем у потомка
    func1(desc1); 
    //Сама Функция1 принимает объект Base, поэтому вызовется конструктор копирования Base,
    //т.е. функция таким образом обработает копию объекта класса Desc
    cout << endl;
    Desc* desc2 = new Desc(); 
    //Cначала создается констр.по умолчанию у предка, затем у потомка
    func2(desc2);
    cout << endl;
    Desc desc3; 
    func3(desc3);
    cout << endl;
    format(7); 
    //Срабатывание всех деструкторов, деструкторов у указателей не бывает
}


