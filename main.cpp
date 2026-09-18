#include <iostream>
#include <string>
#include <typeinfo> // для определения типа объекта
#include <windows.h> // локаль

using namespace std;

# // Supported OS:
# // - Windows
# // - Linux


// абстрактный класс
class device {
protected:
    string country; // будут у каждого наследника, только наследники имеют доступ к этим полям
    string model;
    int price;
    bool power = false;

public:
    // конструкторы
    device() : device("китай", "1", 0) {}
    device(string c, string m, int p) : country(c), model(m), price(p) {}

    // виртуальный деструктор
    virtual ~device() {}

    // геттеры
    string get_country() { return country; }
    string get_model() { return model; }
    int get_price() { return price; }
    bool is_power() { return power; }

    // сеттеры (теперь по значению)
    void set_country(string new_country) { country = new_country; }
    void set_model(string new_model) { model = new_model; }
    void set_price(int new_price) { price = new_price; }

    virtual void sound() = 0;  // чтобы класс был абстрактным
    virtual void power_on() = 0;
    virtual void power_off() = 0;
    virtual void class_name() = 0;
    virtual void print_info() = 0;
};

// класс телевизора
class tv : public device {
private:
    bool hd;
    int diagonal;
    int ram;

public:
    // конструкторы
    tv() : device(), hd(false), diagonal(0), ram(0) {}
    tv(string c, string m, int p, bool h, int d, int r)
        : device(c, m, p), hd(h), diagonal(d), ram(r) {
    }

    // конструктор копирования
    tv(const tv& other)
        : device(other), hd(other.hd), diagonal(other.diagonal), ram(other.ram) {
    }

    // деструктор
    ~tv() {}

    // геттеры
    bool get_hd() { return hd; }
    int get_diagonal() { return diagonal; }
    int get_ram() { return ram; }

    // сеттеры
    void set_hd(bool new_hd) { hd = new_hd; }
    void set_diagonal(int new_diag) { diagonal = new_diag; }
    void set_ram(int new_ram) { ram = new_ram; }

    // методы
    void sound() override {
        if (power)
            cout << "телевизор издаёт звук!" << endl;
        else
            cout << "звука нет, телевизор выключен" << endl;
    }

    void power_on() override {
        power = true;
        cout << "телевизор включён" << endl;
    }

    void power_off() override {
        power = false;
        cout << "телевизор выключен" << endl;
    }

    void class_name() override {
        cout << "tv" << endl;
    }

    void print_info() override {
        cout << "тип: tv\n"
            << "страна: " << country << "\n"
            << "модель: " << model << "\n"
            << "цена: " << price << "\n"
            << "питание: " << (power ? "вкл" : "выкл") << "\n"
            << "hd: " << (hd ? "да" : "нет") << "\n"
            << "диагональ: " << diagonal << "\n"
            << "оперативная память: " << ram << "\n";
    }

    // уникальный метод
    void watch() {
        if (power) {
            cout << "вы смотрите телевизор";
            if (hd) cout << " в hd!";
            cout << endl;
        }
        else {
            cout << "вы ничего не смотрите, телевизор выключен" << endl;
        }
    }
};

// класс телефона
class phone : public device {
private:
    string brand;
    int memory;  // в гб
    int mass;  // в граммах

public:
    phone() : device(), brand("xiaomi"), memory(1), mass(1) {}
    phone(string c, string m, int p, string b, int mem, int new_mass)
        : device(c, m, p), brand(b), memory(mem), mass(new_mass) {
    }

    phone(const phone& other)
        : device(other), brand(other.brand), memory(other.memory), mass(other.mass) {
    }

    ~phone() {}

    string get_brand() { return brand; }
    int get_memory() { return memory; }
    int get_mass() { return mass; }

    // сеттер
    void set_brand(string new_brand) { brand = new_brand; }
    void set_memory(int new_mem) { memory = new_mem; }
    void set_mass(int new_mass) { mass = new_mass; }

    void sound() override {
        if (power)
            cout << "телефон издаёт звук!" << endl;
        else
            cout << "звука нет, телефон выключен" << endl;
    }

    void power_on() override {
        power = true;
        cout << "телефон включён" << endl;
    }

    void power_off() override {
        power = false;
        cout << "телефон выключен" << endl;
    }

    void class_name() override {
        cout << "phone" << endl;
    }

    void print_info() override {
        cout << "тип: phone\n"
            << "страна: " << country << "\n"
            << "модель: " << model << "\n"
            << "цена: " << price << "\n"
            << "питание: " << (power ? "вкл" : "выкл") << "\n"
            << "бренд: " << brand << "\n"
            << "память: " << memory << " гб\n"
            << "масса: " << mass << " г\n";
    }

    // звонок — тоже строка по значению
    void call(string number) {
        if (power) {
            cout << "вы звоните на номер " << number << endl;
        }
        else {
            cout << "вы никому не звоните, телефон выключен" << endl;
        }
    }
};

// класс наушников
class headphones : public device {
private:
    bool micro;
    int sensitivity;  // в дб
    int mass;  // в граммах

public:
    headphones() : device(), micro(false), sensitivity(50), mass(1) {}
    headphones(string c, string m, int p, bool mic, int sens, int new_mass)
        : device(c, m, p), micro(mic), sensitivity(sens), mass(new_mass) {
    }

    headphones(const headphones& other)
        : device(other), micro(other.micro), sensitivity(other.sensitivity), mass(other.mass) {
    }

    ~headphones() {}

    bool get_micro() { return micro; }
    int get_sensitivity() { return sensitivity; }
    int get_mass() { return mass; }

    void set_micro(bool new_micro) { micro = new_micro; }
    void set_sensitivity(int new_sens) { sensitivity = new_sens; }
    void set_mass(int new_mass) { mass = new_mass; }

    void sound() override {
        if (power)
            cout << "наушники издают звук!" << endl;
        else
            cout << "звука нет, наушники выключены" << endl;
    }

    void power_on() override {
        power = true;
        cout << "наушники включены" << endl;
    }

    void power_off() override {
        power = false;
        cout << "наушники выключены" << endl;
    }

    void class_name() override {
        cout << "headphones" << endl;
    }

    void print_info() override {
        cout << "тип: headphones\n"
            << "страна: " << country << "\n"
            << "модель: " << model << "\n"
            << "цена: " << price << "\n"
            << "питание: " << (power ? "вкл" : "выкл") << "\n"
            << "наличие микрофона: " << (micro ? "да" : "нет") << "\n"
            << "чувствительность: " << sensitivity << " дб\n"
            << "масса: " << mass << " г\n";
    }

    // слушать музыку
    void listen_music() {
        if (power) {
            cout << "вы слушаете музыку в наушниках!" << endl;
        }
        else {
            cout << "вы не слушаете музыку, наушники выключены" << endl;
        }
    }
};

// класс патефона
class patephone : public device {
private:
    string needle_type; // тип иглы
    int speed;  // скорость вращения

public:
    patephone() : device(), needle_type("стальная"), speed(78) {}
    patephone(string c, string m, int p, string needle, int sp)
        : device(c, m, p), needle_type(needle), speed(sp) {
    }

    patephone(const patephone& other)
        : device(other), needle_type(other.needle_type), speed(other.speed) {
    }

    ~patephone() {}

    string get_needle_type() { return needle_type; }
    int get_speed() { return speed; }

    // сеттер по значению
    void set_needle_type(string new_needle) { needle_type = new_needle; }
    void set_speed(int new_speed) { speed = new_speed; }

    void sound() override {
        if (power)
            cout << "патефон играет музыку с пластинки!" << endl;
        else
            cout << "патефон не играет музыку, он выключен" << endl;
    }

    void power_on() override {
        power = true;
        cout << "патефон включён" << endl;
    }

    void power_off() override {
        power = false;
        cout << "патефон выключен" << endl;
    }

    void class_name() override {
        cout << "patephone" << endl;
    }

    void print_info() override {
        cout << "тип: patephone\n"
            << "страна: " << country << "\n"
            << "модель: " << model << "\n"
            << "цена: " << price << "\n"
            << "питание: " << (power ? "вкл" : "выкл") << "\n"
            << "тип иглы: " << needle_type << "\n"
            << "скорость: " << speed << " об/мин\n";
    }

    // завести пластинку
    void play_record() {
        if (power) {
            cout << "играет пластинка на патефоне!" << endl;
        }
        else {
            cout << "патефон выключен, включите его." << endl;
        }
    }
};
void clear_input() {
    cin.clear();
    cin.ignore(10000, '\n');
}

int main() {
    SetConsoleOutputCP(65001);
    const int size = 6;
    device* devices[size] = { nullptr }; // массив 6 указателей на device
    int choice;
    bool exit_flag = false;
    while (!exit_flag) {
        cout << "\n --== меню ==--\n";
        cout << "1 добавить новый объект\n";
        cout << "2 выполнить метод базового класса для всех объектов\n";
        cout << "3 вывести типы и поля всех объектов\n";
        cout << "4 выполнить уникальный метод для выбранного объекта\n";
        cout << "5 выход\n";
        cout << "Введите цифру (1-5): ";
        cin >> choice;
        clear_input();

        switch (choice) {
        case 1: { 
            int index = -1; // ищем первую пустую ячейку
            for (int i = 0; i < size; ++i) {
                if (devices[i] == nullptr) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                cout << "массив заполнен, нельзя добавить больше объектов\n";
                break;
            }

            cout << "выберите тип объекта:\n";
            cout << "1. tv\n2. phone\n3. headphones\n4. patephone\n";
            int type_choice;
            cin >> type_choice;
            clear_input();

            // общие поля для всех устройств
            string country, model;
            int price;
            cout << "страна: "; getline(cin, country);
            cout << "модель: "; getline(cin, model);
            cout << "цена: "; cin >> price;
            clear_input();
            // создаём объект нужного типа и кладём в массив
            switch (type_choice) {
            case 1: {
                bool hd;
                int diag, ram;
                cout << "hd (1 - да, 0 - нет): "; cin >> hd;
                cout << "диагональ: "; cin >> diag;
                cout << "оперативная память: "; cin >> ram;
                clear_input();
                devices[index] = new tv(country, model, price, hd, diag, ram);
                break;
            }
            case 2: {
                string brand;
                int mem, mass;
                cout << "бренд: "; getline(cin, brand);
                cout << "память (гб): "; cin >> mem;
                cout << "масса (г): "; cin >> mass;
                clear_input();
                devices[index] = new phone(country, model, price, brand, mem, mass);
                break;
            }
            case 3: {
                bool mic;
                int sens, mass;
                cout << "наличие микрофона (1 - да, 0 - нет): "; cin >> mic;
                cout << "чувствительность (дб): "; cin >> sens;
                cout << "масса (г): "; cin >> mass;
                clear_input();
                devices[index] = new headphones(country, model, price, mic, sens, mass);
                break;
            }
            case 4: {
                string needle;
                int sp;
                cout << "тип иглы: "; getline(cin, needle);
                cout << "скорость (об/мин): "; cin >> sp;
                clear_input();
                devices[index] = new patephone(country, model, price, needle, sp);
                break;
            }
            default:
                cout << "неверный выбор\n";
                break;
            }
            if (devices[index] != nullptr)
                cout << "объект добавлен в ячейку " << index << "\n";
            break;
        }

        case 2: {
            // выполнение указанного метода базового класса для всех объектов
            // массива (у каждого должен выполнится свой перегруженный вариант)
            cout << "выберите метод:\n";
            cout << "1. sound\n2. power_on\n3. power_off\n4. class_name\n";
            int method_choice;
            cin >> method_choice;
            clear_input();

            for (int i = 0; i < size; ++i) {
                if (devices[i] != nullptr) {
                    cout << "объект " << i << ": ";
                    switch (method_choice) {
                    case 1: devices[i]->sound(); break;
                    case 2: devices[i]->power_on(); break;
                    case 3: devices[i]->power_off(); break;
                    case 4: devices[i]->class_name(); break;
                    default: cout << "неверный метод\n"; break;
                    }
                }
            }
            break;
        }

        case 3: {
            // выводим инфу о каждом объекте
            for (int i = 0; i < size; ++i) {
                if (devices[i] != nullptr) {
                    cout << "\n = объект " << i << "= \n";
                    devices[i]->print_info();
                }
                else {
                    cout << "ячейка " << i << " пуста\n";
                }
            }
            break;
        }

        case 4: {
            // уникальный метод конкретного объекта
            cout << "введите индекс объекта (0-" << size - 1 << "): ";
            int idx; // индекс объекта
            cin >> idx;
            clear_input();
            if (idx < 0 || idx >= size || devices[idx] == nullptr) { // проверяем корректность индекса
                cout << "некорректный индекс или объект отсутствует\n";
                break;
            }

            // сначала проверяем typeid потом dynamic_cast
            if (typeid(*devices[idx]) == typeid(tv)) { // сравниваем объекты которые typeid вернул
                tv* t = dynamic_cast<tv*>(devices[idx]);
                if (t) t->watch();
            }
            else if (typeid(*devices[idx]) == typeid(phone)) {
                phone* p = dynamic_cast<phone*>(devices[idx]);
                if (p) {
                    cout << "введите номер для звонка: ";
                    string number;
                    getline(cin, number);
                    p->call(number);
                }
            }
            else if (typeid(*devices[idx]) == typeid(headphones)) {
                headphones* h = dynamic_cast<headphones*>(devices[idx]);
                if (h) h->listen_music();
            }
            else if (typeid(*devices[idx]) == typeid(patephone)) {
                patephone* pp = dynamic_cast<patephone*>(devices[idx]);
                if (pp) pp->play_record();
            }
            else {
                cout << "неизвестный тип объекта\n";
            }
            break;
        }

        case 5:
            exit_flag = true;
            break;

        default:
            cout << "неверный пункт меню\n";
            break;
        }
    }
    for (int i = 0; i < size; ++i) {
        delete devices[i];
    }

    return 0;
}