#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;
//Declare Structures
struct account {
    string username;
    string password;
};
struct Date_of_Birth {
    int dd;
    int mm;
    double yy;
};
struct address {
    string city;
};
struct Phone {
    int Pnum;
};
struct payment {
    double salary;
};
struct empolyee {
    int id = 0;
    string name;
    char sex;
    int age = 0;
    Date_of_Birth dob;
    address add;
    Phone telPhone;
    payment paid;
    string typeemp;
};

//Declare Functions///////////////////////////////////////////
void intro();
bool validate_id(int id);
int get_id();
bool validate_name(string name);
string get_name();
void add_Employee(empolyee emp[], int& count);
void view_Employee(empolyee emp[], int count);
void Employee_menu(empolyee emp[], int& count);
void admin_menu(empolyee emp[], int count);
void main_menu(empolyee emp[], int count);
account get_user();
account* get_users();
int get_number();
bool authenticate(string username, string password);
bool validate_string(string st);
string get_input(string s);
void login_menu(empolyee emp[], int count);
void register_menu();
int search_byID(empolyee emp[], int count, int id);
int search_byPHone(empolyee emp[], int count, int phone);
int search_byName(empolyee emp[], int count, string name);
void update(empolyee emp[], int count, int id);
void del_Byid(empolyee emp[], int& count, int id);
void del_ByName(empolyee emp[], int& count, string name);
void del_ByPhone(empolyee emp[], int& count, int phone);
void swap(empolyee& a, empolyee& b);
void sort(empolyee emp[], int count);
//Mian Functions//////////////////////////////////////////////
int main()
{
      system ("cls");
    intro();
    const int SIZE = 100;
    empolyee emp[SIZE];
    int count = 0;
    int choice;

    do {
        cout << "\t\t==============<< Main Menu >>==============" << endl;
        cout << "\t\t[1]. Login " << endl;
        cout << "\t\t[2]. Register Account" << endl;
        cout << "\t\t[0]. Exit" << endl;
        cout << "\t\tChoice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            login_menu(emp, count);
            break;
        case 2:
            register_menu();
            break;
        case 0:
            exit(0);

        default:
            cout << "Invalid" << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}
////////////////////////////////////////////////////////////////////

void intro()
{
    system("cls");
    cout << "\t\t===========<< Employee Project >>==========" << endl;
    cout << "\t\t# Project in C++                          #" << endl;
    cout << "\t\t# Employee Managament                     #" << endl;
    cout << "\t\t# Made by? Ally                           #" << endl;
    cout << "\t\t# School: IT Step Cambodia                #" << endl;
    cout << "\t\t===========================================" << endl;
    cout << "\n";

}

bool validate_id(int id) {
    if (cin.fail() || id <= 0) {
        return false;
    }
    else {
        return true;
    }
}

int get_id() {
    int id;
    while (true) {
        cout << "\t\tEnter ID: ";
        cin >> id;
        if (!validate_id(id)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: invalid id" << endl;
        }
        else {
            return id;
        }

    }

}

bool validate_name(string name) {
    if (name.length() <= 3) {
        return false;
    }

    for (int i = 0; i < name.length(); i++) {
        if (!(name[i] >= 65 && name[i] <= 122)) {
            return false;
        }
    }
    return true;
}

string get_name() {
    string name;

    while (true) {
        cout << "\t\tEnter name: ";
        cin >> name;
        if (!validate_name(name)) {
            cout << "Error: invalid" << endl;
        }
        else {
            return name;
        }
    }

}
int get_number() {
    int number;
    cout << "";
    cin >> number;
    return number;
}
void add_Employee(empolyee emp[], int& count) {
    cout << "\t\t=> CREATE A NEW EMPLOYYE" << endl;

    char choice;
    do {
        emp[count].id = get_id();
        emp[count].name = get_name();
        cout << "\t\tEnter Gender(M/F): ";
        cin >> emp[count].sex;
        cout << "\t\tEnter Age: ";
        cin >> emp[count].age;
        cout << "\t\tEnter Date Of Birth(dd/mm/yy): ";
        cin >> emp[count].dob.dd;
        cin >> emp[count].dob.mm;
        cin >> emp[count].dob.yy;
        cin.ignore();
        cout << "\t\tEnter Address(City): ";
        cin >> emp[count].add.city;
        cin.ignore();
        cout << "\t\tEnter Phone Number(+885):";
        emp[count].telPhone.Pnum = get_number();
        cout << "\t\tEnter Role: ";
        cin >> emp[count].typeemp;
        cout << "\t\tEnter SALARY:";
        emp[count].paid.salary = get_number();
        count++;
        cout << "\t\tDo you want to add more?(y/n):";
        cin >> choice;

    } while (choice == 'y');

}
void view_Employee(empolyee emp[], int count) {

    const int name_width = 15;
    const int int_width = 7;
    const string sep = "|";
    const int total_width = int_width + name_width + int_width * 2 + name_width * 3 + int_width + sep.size() * (name_width + 1);
    const string line = sep + string(total_width - 1, '-') + '|';

    cout << "\t\t===============<< Employee List >>================" << endl;
    cout << "\t\t" << line << '\n' << "\t\t" << sep
        << setw(int_width) << "ID" << sep << setw(name_width) << "NAME" << sep
        << setw(int_width) << "GENDER" << sep << setw(int_width) << "AGE" << sep
        << setw(name_width) << "DATE OF BIRTH" << sep << setw(name_width) << "ADDRESS" << sep
        << setw(name_width) << "PHONE NUMBER" << sep << setw(int_width) << "ROLE" << sep
        << setw(int_width) << "SALARY" << sep << '\n' << "\t\t" << line << '\n';

    for (int i = 0; i < count; i++) {
        cout << "\t\t" << sep << setw(int_width) << emp[i].id << sep << setw(name_width) << emp[i].name << sep
            << setw(int_width) << emp[i].sex << sep << setw(int_width) << emp[i].age << sep << " "
            << setw(int_width) << emp[i].dob.dd << "/" << emp[i].dob.mm << "/" << emp[i].dob.yy << sep
            << fixed << setprecision(2)
            << setw(name_width) << emp[i].add.city << sep << setw(name_width) << emp[i].telPhone.Pnum << sep
            << setw(int_width) << emp[i].typeemp << sep << setw(int_width) << fixed << setprecision(0) << emp[i].paid.salary << sep << endl;

    }
    cout << "\t\t" << line << '\n';
}
int search_byID(empolyee emp[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (emp[i].id == id) {
            return i;
        }
    }
    return -1;

}

int search_byPHone(empolyee emp[], int count, int phone) {
    for (int i = 0; i < count; i++) {
        if (emp[i].telPhone.Pnum == phone) {
            return i;
        }
    }
    return -1;

}

int search_byName(empolyee emp[], int count, string name) {
    for (int i = 0; i < count; i++) {
        if (emp[i].name == name) {
            return i;
        }
    }
    return -1;

}

void update(empolyee emp[], int count, int id) {
    int index = search_byID(emp, count, id);
    if (index != -1) {
        cout << "\t\tEnter new name: ";
        cin >> emp[index].name;
        cout << "\t\tEnter Gender(M/F): ";
        cin >> emp[index].sex;
        cout << "\t\tEnter Age: ";
        cin >> emp[index].age;
        cout << "\t\tEnter Date Of Birth(dd/mm/yy): ";
        cin >> emp[index].dob.dd;
        cin >> emp[index].dob.mm;
        cin >> emp[index].dob.yy;
        cin.ignore();
        cout << "\t\tEnter Address(City): ";
        cin >> emp[index].add.city;
        cin.ignore();
        cout << "\t\tEnter Phone Number(+885):";
        emp[index].telPhone.Pnum = get_number();
        cout << "\t\tEnter Role: ";
        cin >> emp[index].typeemp;
        cout << "\t\tEnter SALARY:";
        emp[index].paid.salary = get_number();
        cout << "\t\tupdated successfully" << endl;
    }
    else {
        cout << "\t\t\acannot update" << endl;
    }
}

void del_Byid(empolyee emp[], int& count, int id) {
    int index = search_byID(emp, count, id);
    if (index != -1) {
        for (int i = index; i < count; i++) {
            emp[i] = emp[i + 1];
        }
        count--;
        cout << "\t\tdelete successfully" << endl;
    }
    else {
        cout << "\t\tcannot delete" << endl;
    }
}

void del_ByName(empolyee emp[], int& count, string name) {
    int index = search_byName(emp, count, name);
    if (index != -1) {
        for (int i = index; i < count; i++) {
            emp[i] = emp[i + 1];
        }
        count--;
        cout << "\t\tdelete successfully" << endl;
    }
    else {
        cout << "\t\tcannot delete" << endl;
    }
}
void del_ByPhone(empolyee emp[], int& count, int phone) {
    int index = search_byPHone(emp, count, phone);
    if (index != -1) {
        for (int i = index; i < count; i++) {
            emp[i] = emp[i + 1];
        }
        count--;
        cout << "\t\tdelete successfully" << endl;
    }
    else {
        cout << "\t\tcannot delete" << endl;
    }
}


void Employee_menu(empolyee emp[], int& count) {
    int ch2;
    cout << "\n\n\n\t\t============<< EMPLOYEE MENU >>============";
    cout << "\n\n\t\t[1].CREATE EMPLOYEE RECORD";
    cout << "\n\n\t\t[2].DISPLAY ALL EMPLOYEE RECORD";
    cout << "\n\n\t\t[3].DISPLAY SPECIFIC EMPLOYEE RECORD ";
    cout << "\n\n\t\t[4].MODIFY EMPLOYEE RECORD";
    cout << "\n\n\t\t[5].DELETE EMPLOYEE RECORD";
    cout << "\n\n\t\t[6].SORT EMPLOYEE RECORD";
    cout << "\n\n\t\t[7].SAVE EMPLOYEE RECORD";
    cout << "\n\n\t\t[8].LOAD EMPLOYEE RECORD";
    cout << "\n\n\t\t[9].BACK TO ADMIN MENU";
    cout << "\n\n\t\tPlease Enter Your Choice (1-8) ";
    cin >> ch2;
    switch (ch2)
    {
    case 1:
        add_Employee(emp, count);
        break;
    case 2: {
        view_Employee(emp, count);

        break;
    }
    case 3: {

        int ch;
        enum command { BACK = 0, ID = 1, NAME = 2, PHONE = 3 };
        do {
            cin.get();
            cout << "\t\t=================<< Options to Search >>==============" << endl;
            cout << "\t\t\t\t [1]. By ID." << endl;
            cout << "\t\t\t\t [2]. By Name." << endl;
            cout << "\t\t\t\t [3]. By Phone Number." << endl;
            cout << "\t\t\t\t [0]. Back to Employee Menu." << endl;
            cout << "\t\t=======================================================" << endl;
            cout << "\t\tPlease one option:";
            cin >> ch;
            switch (ch)
            {
            case command::ID: {
                int id;
                cout << "\t\tEnter id:";
                cin >> id;
                int index = search_byID(emp, count, id);
                if (index != -1) {
                    cout << endl;
                    cout << "\t\tID has found" << endl;
                    cout << "\t\t=> Employee ID: ";
                    cout << emp[index].id << endl;
                    cout << "\t\t=> Employee NAME: ";
                    cout << emp[index].name << endl;
                    cout << "\t\t=> Employee Gender: ";
                    cout << emp[index].sex << endl;
                    cout << "\t\t=> Employee Age: ";
                    cout << emp[index].age << endl;
                    cout << "\t\t=> Employee Birthday: ";
                    cout << emp[index].dob.dd << "." << emp[index].dob.mm << "." << emp[index].dob.yy << endl;
                    cout << "\t\t=> Employee Address(City): ";
                    cout << emp[index].add.city << endl;
                    cout << "\t\t=> Employee Tel(+885): ";
                    cout << emp[index].telPhone.Pnum << endl;
                    cout << "\t\t=> Employee Role: ";
                    cout << emp[index].typeemp << endl;
                    cout << "\t\t=> Employee Salary: ";
                    cout << emp[index].paid.salary << endl;
                }
                else {
                    cout << "\t\t\a ID not found" << endl;
                }

                break;
            }
            case command::NAME: {
                string name;
                cout << "\t\tEnter Employee Name:";
                cin >> name;
                int index = search_byName(emp, count, name);
                if (index != -1) {
                    cout << endl;
                    cout << "\t\tID has found" << endl;
                    cout << "\t\t=> Employee ID: ";
                    cout << emp[index].id << endl;
                    cout << "\t\t=> Employee NAME: ";
                    cout << emp[index].name << endl;
                    cout << "\t\t=> Employee Gender: ";
                    cout << emp[index].sex << endl;
                    cout << "\t\t=> Employee Age: ";
                    cout << emp[index].age << endl;
                    cout << "\t\t=> Employee Birthday: ";
                    cout << emp[index].dob.dd << "." << emp[index].dob.mm << "." << emp[index].dob.yy << endl;
                    cout << "\t\t=> Employee Address(City): ";
                    cout << emp[index].add.city << endl;
                    cout << "\t\t=> Employee Tel(+885): ";
                    cout << emp[index].telPhone.Pnum << endl;
                    cout << "\t\t=> Employee Role: ";
                    cout << emp[index].typeemp << endl;
                    cout << "\t\t=> Employee Salary: ";
                    cout << emp[index].paid.salary << endl;
                }
                else {
                    cout << "\t\t\a Name not found" << endl;
                }
                break;
            }
            case command::PHONE: {
                int phone;
                cout << "\t\tEnter Phone Number:";
                cin >> phone;
                int index = search_byPHone(emp, count, phone);
                if (index != -1) {
                    cout << endl;
                    cout << "\t\tID has found" << endl;
                    cout << "\t\t=> Employee ID: ";
                    cout << emp[index].id << endl;
                    cout << "\t\t=> Employee NAME: ";
                    cout << emp[index].name << endl;
                    cout << "\t\t=> Employee Gender: ";
                    cout << emp[index].sex << endl;
                    cout << "\t\t=> Employee Age: ";
                    cout << emp[index].age << endl;
                    cout << "\t\t=> Employee Birthday: ";
                    cout << emp[index].dob.dd << "." << emp[index].dob.mm << "." << emp[index].dob.yy << endl;
                    cout << "\t\t=> Employee Address(City): ";
                    cout << emp[index].add.city << endl;
                    cout << "\t\t=> Employee Tel(+885): ";
                    cout << emp[index].telPhone.Pnum << endl;
                    cout << "\t\t=> Employee Role: ";
                    cout << emp[index].typeemp << endl;
                    cout << "\t\t=> Employee Salary: ";
                    cout << emp[index].paid.salary << endl;
                }
                else {
                    cout << "\t\t\a Phone Number not found" << endl;
                }
                break;
            }
            case command::BACK: {
                return;
                break;
            }
            default:
                cout << "\t\t\aInvalid Search" << endl;
                break;
            }
        } while (ch != 0);
        Employee_menu(emp, count);
        break;
    }
    case 4:
    {
        int id;
        view_Employee(emp, count);
        cout << "\t\t Enter ID: ";
        cin >> id;
        update(emp, count, id);
        break;
    }

    case 5: {
        string name;
        int id;
        int phone;
        char choiceDel;

        cout << endl;
        int ch;
        enum command { BACK = 0, ID = 1, NAME = 2, PHONE = 3 };
        do {
            cin.get();
            cout << "\t\t=================<< Options to Delete >>==============" << endl;
            cout << "\t\t\t\t [1]. By ID." << endl;
            cout << "\t\t\t\t [2]. By Name." << endl;
            cout << "\t\t\t\t [3]. By Phone Number." << endl;
            cout << "\t\t\t\t [0]. Back to Employee Menu." << endl;
            cout << "\t\t=======================================================" << endl;
            cout << "\t\tPlease one option:";
            cin >> ch;
            switch (ch)
            {
            case command::ID: {
                cout << "\t\tEnter id: ";
                id = get_number();
                cout << "\t\tAre you sur to delete?(y/n): ";
                cin >> choiceDel;
                if (choiceDel == 'y') {
                    del_Byid(emp, count, id);
                }
                else {
                    Employee_menu(emp, count);
                }
                break;
            }
            case command::NAME: {
                cout << "\t\tEnter Name: ";
                cin >> name;
                cout << "\t\tAre you sur to delete?(y/n): ";
                cin >> choiceDel;
                if (choiceDel == 'y') {
                    del_ByName(emp, count, name);
                }
                else {
                    Employee_menu(emp, count);
                }
                break;
            }

            case command::PHONE: {
                cout << "\t\tEnter Phone: ";
                phone = get_number();
                cout << "\t\tAre you sur to delete?(y/n): ";
                cin >> choiceDel;
                if (choiceDel == 'y') {
                    del_ByPhone(emp, count, phone);
                }
                else {
                    Employee_menu(emp, count);
                }
                break;
            }
            case command::BACK: {
                return;
                break;
            }
            default:
                cout << "\t\t\aInvalid Delete" << endl;
                break;
            }
            Employee_menu(emp, count);;
        } while (ch != 0);

        cout << "\t\tEnter id: ";
        cin >> id;
        cout << "Are you sur to delete?(y/n): ";
        cin >> choiceDel;
        if (choiceDel == 'y') {
            del_Byid(emp, count, id);
        }
        else {

        }
    }
          break;
    case 6: {
        sort(emp, count);
        cout << "\t\tSorted" << endl;
        break;
    }
    case 7:
    {
        ofstream outFile;
        outFile.open("Employees.dat", ios::out | ios::binary);
        for (int i = 0; i < count; i++) {
            outFile.write(reinterpret_cast<char*>(&emp[i]), sizeof(emp[i]));
        }
        outFile.close();
        cout << "Saved" << endl;
    }
    break;

    case 8: {
        empolyee s;
        count = 0;
        ifstream inFile;
        inFile.open("Employees.dat", ios::in);
        while (inFile.read(reinterpret_cast<char*>(&s), sizeof(s))) {
            emp[count] = s;
            count++;
            cout << s.id << " " << s.name << endl;
        }
        inFile.close();
        cout << "Loaded" << endl;
        break;
    }
    case 9:

        return;
    default:
        cout << "Error: invalid input\a\n";
    }
    Employee_menu(emp, count);
}

void admin_menu(empolyee emp[], int count)
{
    system("cls");
    int ch2;
    cout << "\n\n\n\t\t=============<< ADMIN MENU >>=============";
    cout << "\n\n\t\t[1]=>.EMPOLYEE MENU";
    cout << "\n\n\t\t[2]=>.BACK TO MAIN MENU";
    cout << "\n\n\t\tPlease Enter Your Choice (1-2) ";
    cin >> ch2;
    switch (ch2)
    {
    case 1:
        Employee_menu(emp, count);
        break;

    case 2:

        return;

    default:
        cout << "Error: invalid input\a\n";
    }
    admin_menu(emp, count);
}
void main_menu(empolyee emp[], int count) {
    system("cls");
    char ch;
    enum COMMAND { USER_UPDATE = '1', BOOK_DEPOSIT = '2', ADMIN_MENU = '3', EXIT = '0' };
    intro();
    do
    {
        cout << "\n\n\n\t\t=============<< MENU ACCOUNT >>=============";
        cout << "\n\n\t\t[01].=> UPDATE USERACCOUNT";
        cout << "\n\n\t\t[02].=> DELETE USERACCOUNT";
        cout << "\n\n\t\t[03].=> ADMINISTRATOR MENU";
        cout << "\n\n\t\t[00].=> EXIT";
        cout << "\n\n\t\t=> Please Select Your Option (0-3) ";
        cin >> ch;


        switch (ch)
        {
        case USER_UPDATE: {

            break;
        }

        case BOOK_DEPOSIT:
            break;
        case ADMIN_MENU:
            admin_menu(emp, count);
            break;
        case EXIT: {
            char c;
            cout << "\t\tAre you sure to exit(y/n)?";
            cin >> c;
            if (c == 'y') {
                exit(0);
            }
            else {
                main_menu(emp, count);
            }
            break;

        }
        default:
            cout << "\t\tError: invalid input\a\n";
            break;
        }
    } while (ch != EXIT);
}

account get_user() {
    account user;
    cout << "\t\tEnter username: ";
    cin >> user.username;
    cout << "\t\tEnter password: ";
    cin >> user.password;
    return user;
}

account* get_users() {
    const int SIZE = 3;
    account* users = new account[SIZE];
    users[0].username = "yaman";
    users[0].password = "1929";
    users[1].username = "daro";
    users[1].password = "1929";
    users[2].username = "ally";
    users[2].password = "1929";
    return users;
}

bool authenticate(string username, string password) {

    const int SIZE = 3;
    account users[2];
    account user;
    int count = 0;
    ifstream inFile;
    inFile.open("userAccounts.dat", ios::in);
    while (inFile.read(reinterpret_cast<char*>(&user), sizeof(user))) {
        users[count] = user;
        count++;
        cout << user.username << " " << user.password << endl;
    }

    inFile.close();

    for (int i = 0; i < 2; i++) {
        if (username == users[i].username && password == users[i].password) {
            cout << "true" << endl;
            return true;

        }
    }
    cout << "false" << endl;
    return false;
}

bool validate_string(string emp) {
    if (emp.length() < 3) {
        return false;
    }
    else {
        return true;
    }
}
string get_input(string s) {
    string emp;
    while (true) {
        cout << "\t\tEnter " << s << " : ";
        cin >> emp;
        if (validate_string(emp)) {
            return emp;
        }
        else {
            cout << "\t\tstring less than 3" << endl;
        }

    }

}

void login_menu(empolyee emp[], int count) {

    string username;
    string password;


    account users[2];
    account user;
    int c = 0;
    bool flag = false;

    ifstream inFile;
    inFile.open("userAccounts.dat", ios::in);
    while (inFile.read(reinterpret_cast<char*>(&user), sizeof(user))) {
        users[c] = user;
        c++;
    }

    inFile.close();

    do {

        cout << "\t\t=============<< LOGIN MENU >>============= " << endl;
        username = get_input("username");
        password = get_input("password");
        for (int i = 0; i < c; i++) {
            if (users[i].username == username && users[i].password == password) {
                flag = true;
                break;
            }
        }


    } while (!flag);
    cout << "h2" << endl;
    main_menu(emp, count);
}
void register_menu() {

    account acc;
    acc = get_user();
    ofstream outFile;
    outFile.open("userAccounts.dat", ios::out | ios::app | ios::binary);
    outFile.write(reinterpret_cast<char*>(&acc), sizeof(acc));
    outFile.close();

}
void swap(empolyee& a, empolyee& b) {
    empolyee temp;
    a = b;
    b = temp;
}
void sort(empolyee emp[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (emp[j].id > emp[j + 1].id) {
                swap(emp[j], emp[j + 1]);
            }
        }
    }
}