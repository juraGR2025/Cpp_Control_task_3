// Cpp_Control_task_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <typeinfo>

using namespace std;
/*Требуется реализовать функцию вычисления корней квадратного уравнения. 
• Функция должна возвращать значение 1, если корни найдены, значение 
нуля, если оба корня совпадают, и значение -1, если корней не существует.
• Значения корней уравнений должны возвращаться в качестве аргументов 
функции, передаваемых по ссылке.
Прототип функции должен выглядеть следующим образом:
int Myroot(double, double, double, double&, double&)*/

int Myroot(double, double, double, double&, double&);

int Myroot(double a, double b, double c, double& x1, double& x2)
{
    double D = b * b - 4.0 * a * c;
    if (D < 0) {
        return -1;
    }
    if (a == 0)
    {
        if (b == 0)
            return -1;
        x2 = x1 = -c / b;
        return 0;
    }
    if (D == 0)
    {
        x1 = -b / (2.0 * a);
        x2 = x1;

        return 0;
    }
    x1 = (-b + sqrt(D)) / (2.0 * a);
    x2 = (-b - sqrt(D)) / (2.0 * a);
    return 1;
}
/*Требуется реализовать функцию Input(a,b). 
В функции Input(a,b) должен быть реализован ввод данных с клавиатуры с 
проверкой корректности ввода (правила проверки корректности кода установите на 
ваше усмотрение).*/
bool Input(int a, int b) {
    cout << "Введите значения для функции Input(a,b): " << endl;
    cout << "a="; cin >> a;
    cout << "b="; cin >> b;
    if (a == 0 || b == 0) return false;
    if(typeid(a || b).name() == "char") return false;
    return true;
}
int main()
{
    setlocale(0, "");
    double a, b, c, x1=0, x2=0;
    int flag;
    cout << "a="; cin >> a;
    cout << "b="; cin >> b;
    cout << "c="; cin >> c;
    flag = Myroot(a, b, c, x1, x2);
    cout << "Flag = " << flag << endl;
    if (flag == 1) {
        cout << "x1=" << x1 << "\t" << "x2=" << x2 << endl;
    }
    else if(flag == 0)cout << "x1=x2=" << x1 << endl;
    else  cout << "Вещественных корней нет " << endl;
    int a1, b1;
    a1 = 0;
    b1 = 0;
    if (Input(a1, b1) == false) // if(!Input(a,b))
    {
        cerr << "error";
        return 1;
    }
    int s = a1 + b1;
    return 0;
}

