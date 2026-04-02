#include <iostream>
#include <cmath>
using namespace std;

//завдання 1.5
class Triangle {
private:
    double a, b, c;
    string color;

    bool isValid(double a, double b, double c) {
        return (a > 0 && b > 0 && c > 0 &&
            a + b > c && a + c > b && b + c > a);
    }

public:
    Triangle() {
        a = b = c = 1;
        color = "white";
    }

    Triangle(double a, double b, double c, string color) {
        if (isValid(a, b, c)) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
        else {
            this->a = this->b = this->c = 1;
        }
        this->color = color;
    }

    void setSides(double a, double b, double c) {
        if (isValid(a, b, c)) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
        else {
            cout << "Invalid triangle!\n";
        }
    }

    void setColor(string color) {
        this->color = color;
    }

    double getA() { return a; }
    double getB() { return b; }
    double getC() { return c; }
    string getColor() { return color; }

    double perimeter() {
        return a + b + c;
    }

    double area() {
        double p = perimeter() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    void print() {
        cout << "Triangle: " << a << ", " << b << ", " << c
            << " Color: " << color << endl;
        cout << "Perimeter: " << perimeter() << endl;
        cout << "Area: " << area() << endl;
    }
};

//завдання 2.7
class Vector3 {
private:
    double arr[3];
    int state;
    static int count;

public:
    Vector3() {
        for (int i = 0; i < 3; i++) arr[i] = 0;
        state = 0;
        count++;
    }

    Vector3(double val) {
        for (int i = 0; i < 3; i++) arr[i] = val;
        state = 0;
        count++;
    }

    Vector3(double* ptr) {
        if (ptr == nullptr) {
            state = -1;
            for (int i = 0; i < 3; i++) arr[i] = 0;
        }
        else {
            for (int i = 0; i < 3; i++) arr[i] = ptr[i];
            state = 0;
        }
        count++;
    }

    ~Vector3() {
        cout << "Vector destroyed. State = " << state << endl;
        count--;
    }

    void setAll(double val = 0) {
        for (int i = 0; i < 3; i++) arr[i] = val;
    }

    double get(int i) {
        if (i >= 0 && i < 3) return arr[i];
        return 0;
    }

    void print() {
        cout << "Vector: ";
        for (int i = 0; i < 3; i++) cout << arr[i] << " ";
        cout << endl;
    }

    Vector3 add(Vector3 v) {
        Vector3 res;
        for (int i = 0; i < 3; i++)
            res.arr[i] = arr[i] + v.arr[i];
        return res;
    }

    Vector3 sub(Vector3 v) {
        Vector3 res;
        for (int i = 0; i < 3; i++)
            res.arr[i] = arr[i] - v.arr[i];
        return res;
    }

    Vector3 cross(Vector3 v) {
        Vector3 res;
        res.arr[0] = arr[1] * v.arr[2] - arr[2] * v.arr[1];
        res.arr[1] = arr[2] * v.arr[0] - arr[0] * v.arr[2];
        res.arr[2] = arr[0] * v.arr[1] - arr[1] * v.arr[0];
        return res;
    }

    void divide(short val) {
        if (val == 0) {
            state = -2;
            cout << "Division by zero!\n";
            return;
        }
        for (int i = 0; i < 3; i++)
            arr[i] /= val;
    }

    double sum() {
        return arr[0] + arr[1] + arr[2];
    }

    bool isEqual(Vector3 v) {
        return sum() == v.sum();
    }

    bool isGreater(Vector3 v) {
        return sum() > v.sum();
    }

    bool isLess(Vector3 v) {
        return sum() < v.sum();
    }

    static int getCount() {
        return count;
    }
};

int Vector3::count = 0;

//тест 1.5
void testTriangle() {
    Triangle t1;
    t1.print();

    Triangle t2(3, 4, 5, "red");
    t2.print();

    t2.setSides(6, 7, 8);
    t2.setColor("blue");
    t2.print();
}

//тест 2.7
void testVector() {
    double arr[3] = { 1, 2, 3 };

    Vector3 v1;
    Vector3 v2(5);
    Vector3 v3(arr);

    v1.print();
    v2.print();
    v3.print();

    Vector3 v4 = v2.add(v3);
    v4.print();

    Vector3 v5 = v2.sub(v3);
    v5.print();

    Vector3 v6 = v2.cross(v3);
    v6.print();

    v2.divide(2);
    v2.print();

    cout << "Compare: " << v2.isGreater(v3) << endl;

    cout << "Objects count: " << Vector3::getCount() << endl;
}

int main() {
    int choice;

    do {
        cout << "\nMENU:\n";
        cout << "1 - Task 1.5 (Triangle)\n";
        cout << "2 - Task 2.7 (Vector)\n";
        cout << "0 - Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            testTriangle();
            break;
        case 2:
            testVector();
            break;
        }

    } while (choice != 0);

    return 0;
}