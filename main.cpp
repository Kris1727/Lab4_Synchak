#include <iostream>
#include <string>
using namespace std;

class LivingBeing {
protected:
    string name;
public:
    LivingBeing(string n) : name(n) {}
    void output() {
        cout << "Жива істота: " << name << endl;
    }
    friend istream& operator>>(istream& in, LivingBeing& o) {
        in >> o.name;
        return in;
    }
};

class Bird : public LivingBeing {
protected:
    double wingspan;
public:
    Bird(string n, double w) : LivingBeing(n), wingspan(w) {}
    void output() {
        LivingBeing::output();
        cout << "Розмах крил: " << wingspan << endl;
    }
    friend istream& operator>>(istream& in, Bird& o) {
        in >> o.name >> o.wingspan;
        return in;
    }
};

class Fish : public LivingBeing {
protected:
    string habitat;
public:
    Fish(string n, string h) : LivingBeing(n), habitat(h) {}
    void output() {
        LivingBeing::output();
        cout << "Середовище: " << habitat << endl;
    }
    friend istream& operator>>(istream& in, Fish& o) {
        in >> o.name >> o.habitat;
        return in;
    }
};

class MigratoryBird : public Bird {
protected:
    string destination;
public:
    MigratoryBird(string n, double w, string d) : Bird(n, w), destination(d) {}
    void output() {
        Bird::output();
        cout << "Мігрує до: " << destination << endl;
    }
    friend istream& operator>>(istream& in, MigratoryBird& o) {
        in >> o.name >> o.wingspan >> o.destination;
        return in;
    }
};

int main() {
    LivingBeing a("Тварина");
    Bird b("Орел", 2.1);
    Fish c("Короп", "Річка");
    MigratoryBird d("Лелека", 1.9, "Африка");

    cout << "--- Конструктори ---" << endl;
    a.output();
    b.output();
    c.output();
    d.output();

    cout << endl << "--- Введення ---" << endl;
    cout << "Жива істота (ім'я): ";
    cin >> a;
    cout << "Птах (ім'я розмах): ";
    cin >> b;
    cout << "Риба (ім'я середовище): ";
    cin >> c;
    cout << "Перелітний птах (ім'я розмах куди): ";
    cin >> d;

    cout << endl << "--- Після введення ---" << endl;
    a.output();
    b.output();
    c.output();
    d.output();

    return 0;
}