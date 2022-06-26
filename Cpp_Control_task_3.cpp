// Cpp_Control_task_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <cmath>
#include <iostream>
#include "math.h"

using namespace std;
/*Требуется написать программу для вычисления площади выпуклого 
пятиугольника. Исходные данные: координаты вершин пятиугольника (значения задайте 
самостоятельно). Для решения задачи следует использовать метод декомпозиции: сначала 
получить площадь треугольников, а затем их сложить. Для расчета сторон и площади 
треугольника использовать отдельные соответствующие функции.
Исходные данные: координаты вершин пятиугольника (значения задайте
самостоятельно). */
double area_of_pentagon()
{
    system("chcp 1251");
    double x1, x2, x3, x4, x5, y1, y2, y3, y4, y5, a, b, c, d, e, f, g, S, s1, s2, s3, p1, p2, p3;
    x1 = -2;   y1 = 0;//Хардкодим координаты точек...
    x2 = -2;   y2 = 2;
    x3 = 1.8;  y3 = 4;
    x4 = 2;    y4 = 2.5;
    x5 = 1;    y5 = 0;
    //Расчет длин сторон треугольников, из которых состоит пятиугольник.
    a = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    b = sqrt(pow((x5 - x1), 2) + pow((y5 - y1), 2));
    c = sqrt(pow((x5 - x4), 2) + pow((y5 - y4), 2));
    d = sqrt(pow((x4 - x3), 2) + pow((y4 - y3), 2));
    e = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    f = sqrt(pow((x5 - x2), 2) + pow((y5 - y2), 2));
    g = sqrt(pow((x4 - x2), 2) + pow((y4 - y2), 2));

    p1 = (a + b + f) / 2;
    p2 = (f + g + c) / 2;
    p3 = (e + d + g) / 2;

    s1 = sqrt(p1 * (p1 - a) * (p1 - b) * (p1 - f));
    s2 = sqrt(p2 * (p2 - f) * (p2 - g) * (p2 - c));
    s3 = sqrt(p3 * (p3 - e) * (p3 - g) * (p3 - d));
    S = s1 + s2 + s3;
    return S;
}
/*Задание 2. Применение итерации реализации функции
Требуется реализовать функцию вычисления кубического корня в двух 
вариантах: в первом, используя стандартную функцию pow(a,1.0/3), а во втором 
– итерационную формулу. В функции main() протестируйте работу созданных функций.*/
double cubic_root(double n) {
    double Rez = 0;
    Rez = pow(n, (1.0 / 3.0));
    return (Rez);
}
double cubic_root2(double n) {
    double y = n;              // начальная инициализация y
    double yi = 0;             // промежуточная переменная
    double y_abs = 0;           // промежуточная переменная
    double endcalc = 0.00001;   // точность вычисления

    do
    {
        yi = 0.5 * (y + (3 * n / (2 * y * y + n / y)));
        y_abs = abs(yi - y);
        y = yi;
    } while (y_abs > endcalc);
    return (y);
}
/*Задание 3. Требуется написать программу, рассчитывающую площадь треугольников двух 
типов: равностороннего и разностороннего. 
Для решения задачи реализуйте перегруженные функции: первая должна
принимать один параметр – сторону и вычислять площадь равностороннего 
треугольника, вторая – принимать три параметра-стороны треугольника для 
вычисления площади разностороннего треугольника.
Выбор типа треугольника реализуйте с помощью диалога с пользователем.*/
double area_of_triangles(double a) {
    //Площадь равностороннего треугольника.
    double p, S;
    p = (3*a) / 2;
    S = sqrt(p * 3*(p - a));
    return S;
}
double area_of_triangles(double a, double b, double c) {
    //Площадь разностороннего треугольника.
    double p, S;
    p = (a + b + c) / 2;
    S = sqrt(p * (p - a) * (p - b) * (p - c));

    return S;
}
/*Задание 4. Рекурсивная функция суммы ряда
Разработайте рекурсивную функцию вычисления суммы ряда
S = 5 + 10 + 15 + … + 5·n...*/
int recursive_function(int n) {
    if (n == 1) return 5;
    return 5 * n + recursive_function(n - 1);
}
/*Задание 5. Применение рекурсии для перевода целого числа в двоичный код
Требуется написать рекурсивную функцию перевода целого положительного 
числа из десятичной системы исчисления в двоичную.
Классический алгоритм перевода: нужно входной параметр num делить на 2 до 
тех пор, пока num>2. При каждом делении нужно выделять остаток с помощью 
выражения num%2.*/
void binary_recursion(int n) {
    if (n >= 2)
    {   binary_recursion(n / 2);
    std::cout << n % 2;
}
    else if (n == 1)std::cout << 1;
    else if (n == 0)std::cout << 0;
}
int main()
{
    double area = 0;
    double cubic = 0;
    area = area_of_pentagon();
    cout << "Площадь пятиугольника равна " << area << endl;
    cubic = cubic_root(6);
    cout << "Корень кубический " << cubic << endl;
    cubic = cubic_root2(6);
    cout << "Корень кубический по итерационной формуле " << cubic << endl;
    cout << "Треугольник равносторонний? (Y/N) " << endl;
    string Ans;
    double side_triangle = 0;
    double side_triangle_1 = 0;
    double side_triangle_2 = 0;
    double side_triangle_3 = 0;
    cin >> Ans;
    if (Ans == "Y" || Ans == "y") {
        cout << "Введите длину стороны " << endl;
        cin >> side_triangle;
        area = area_of_triangles(side_triangle);
        cout << "Площадь треугольника равна " << area << endl;
    }
    else if (Ans == "N" || Ans == "n") {
        cout << "Введите длины сторон " << endl;
        cin >> side_triangle_1;
        cin >> side_triangle_2;
        cin >> side_triangle_3;
        area = area_of_triangles(side_triangle_1, side_triangle_2, side_triangle_3);
        cout << "Площадь треугольника равна " << area << endl;
    }
    else {
        cout << "Простите не понял" << endl;
    }
    int n = 0;
    cout << "Введите параметр n рекурсии" << endl;
    cin >> n;
    int Rez = 0;
    Rez = recursive_function(n);
    cout << "Результат рекурсии: " << Rez << endl;

    cout << "Введите десятичное число для перевода в двоичное" << endl;
    cin >> n;
    std::cout << "\nBinary number = ";
    binary_recursion(n);
}
