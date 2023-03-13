#include <cctype>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

string temp;
bool isname(string s){
    for(int i=0;i<s.length();i++){
        if((s[i]<65) && s[i]!=32 )
        return false;
        else if(s[i]>90 && s[i]<97)return false;
        else if(s[i]>122)return false;
    }
    return true;
}
bool isnum(string s){
    for(int i=0;i<s.length();i++){
        if(!isdigit(s[i]))return false;
    }
    return true;
}
bool isdouble(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]=='.')
        continue;
        if(!isdigit(s[i]))return false;
    }
    return true;
}

class Payroll_system
{
private:
    string name,desg;
    int E_id, days;
    long double basic_salary, hra, da, ma, pf, insurance, netsalary, deduction, overtime;
    double extra_hours;

public:
    void get_record();
    void put_record();
    void calc_record();
    void put_slip();

    int show_id()
    {
        return E_id;
    }
    void updatename(string cname)
    {
        name = cname;
    }
    void update_workdays(int cdays)
    {
        days = cdays;
    }
    void update_extrahours(double cextra_hours)
    {
        extra_hours = cextra_hours;
    }
    void update_basic_salary(long double cbasic_salary)
    {
        basic_salary = cbasic_salary;
    }
    void update_designation(string cdesg)
    {
        desg=cdesg;
    }
};

void Payroll_system::get_record()
{
    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t";
    cout << "Enter name of Employee: ";
    getline(cin >> ws, name);
    while(!isname(name)){
        cout<<"\t\t\t\t\t\t\tPlease only enter name in alphabets: ";
        getline(cin >> ws, name);
    }
    
    cout << "\n\t\t\t\t\t\t\tEnter Employee Id: ";
    cin>>temp;
    while(!isnum(temp)) {
        cout<<"\t\t\t\t\t\t\tPlease only enter ID in digits: ";
        cin>>temp;
    }
    E_id=stoi(temp);


    cout << "\n\t\t\t\t\t\t\tEnter Designation: ";
    getline(cin>>ws,desg);
    while(!isname(desg)){
        cout<<"\t\t\t\t\t\t\tPlease enter your desination in alphabets";
        getline(cin >> ws, desg);
    }


    cout << "\n\t\t\t\t\t\t\tEnter Employee's Basic Salary: ";
    cin >> temp;
    while(!isdouble(temp)) {
        cout<<"\t\t\t\t\t\t\tPlease only enter basic salary in digits: ";
        cin>>temp;
    }
    basic_salary=stold(temp);


    cout << "\n\t\t\t\t\t\t\tEnter working days (out of 31): ";
    cin >> temp;
    while(!isnum(temp)) {
        cout<<"\t\t\t\t\t\t\tPlease only enter days in digits: ";
        cin>>temp;
    }
    days=stoi(temp);

    cout << "\n\t\t\t\t\t\t\tExtra working Hours if any: ";
    cin >> temp;
    while(!isdouble(temp)) {
        cout<<"\t\t\t\t\t\t\tPlease only enter basic salary in digits: ";
        cin>>temp;
    }
    extra_hours=stod(temp);

}
void Payroll_system::calc_record()
{
    deduction = (31 - days) * (basic_salary / 31);
    overtime = extra_hours * ((basic_salary / (26 * 8)) + 200);
    hra = 12 * basic_salary / 100;
    da = 6.5 * basic_salary / 100;
    ma = 15 * basic_salary / 100;
    pf = 10 * basic_salary / 100;
    insurance = 4 * basic_salary / 100;
    netsalary = basic_salary + hra + da + ma + overtime - pf - insurance - deduction;
}

void Payroll_system::put_record()
{
    cout << setw(8) << E_id << setw(20) << name << setw(17) << days << setw(14) << extra_hours << setw(14) << basic_salary << setw(14) << overtime << setw(14) << deduction << setw(8) << hra << setw(8) << da << setw(8) << ma << setw(8) << pf << setw(14) << insurance << setw(15) << desg << endl;
}

void Payroll_system::put_slip()
{
    cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tP A Y  S L I P \n\n\n";
    cout << "\t\t\t\t\t\t\t\t" << setw(22) << left << "Name: " << name << "\n\n";
    cout << "\t\t\t\t\t\t\t\t" << setw(22) << left << "Employee id: " << E_id << "\n\n";
    cout << "\t\t\t\t\t\t\t\t" << setw(22) << left << "Designation: " << desg << "\n\n";
    cout << "\t\t\t\t\t\t\t\t" << setw(22) << left << "Basic Salary: " << basic_salary << "\n\n";
    cout << "\t\t\t\t\t\t\t\t" << setw(22) << left << "Working days " << days << "\n\n";
    cout << "\t\t\t\t\t\t\t\t" << setw(22) << left << "Overtime: " << overtime << "\n\n";
    cout << "\t\t\t\t\t\t\t\t" << setw(22) << left << "Deduction: " << deduction << "\n\n";
    cout << "\t\t\t\t\t\t\t\t" << setw(22) << left << "HRA: " << hra << "\n\n";
    cout << "\t\t\t\t\t\t\t\t" << setw(22) << left << "DA: " << da << "\n\n";
    cout << "\t\t\t\t\t\t\t\t" << setw(22) << left << "MA: " << ma << "\n\n";
    cout << "\t\t\t\t\t\t\t\t" << setw(22) << left << "Insurance: " << insurance << "\n\n";
    cout << "\t\t\t\t\t\t\t\t" << setw(22) << left << "Net Salary: " << netsalary << "\n\n";
}

void add_record();
void show_record();
void show_all();
void delete_record();
void modify_record();
void generate_slip();

Payroll_system slip;
fstream file;

void login()
{
    system("cls");
    string pass = "";
    char ch;
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    cout<<"____________________";
    cout<<"            P A Y R O L L  S Y S T E M            ";
    cout<<"____________________";
    cout << "\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\tP A S S W O R D :";
    ch = _getwch();

    while (ch != 13)
    {
            pass.push_back(ch);
            cout << '*';
            ch = _getch();

    }
    if (pass == "Pass123")
    {
        cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tL O A D I N G ";
        for (int a = 1; a < 8; a++) 
        {
            Sleep(500);
            cout << "...";
        }
        cout << "\n\n\n\t\t\t\t\t\t\t\t\tAccess Granted..!! \n\n\n";
        
        system("CLS");
    }
    else
    {
        cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\tAccess Aborted...!!\n";
        cout<<"\n\n\t\t\t\t\t\t\t\t\t";system("pause");
        login();
    }
}

int main()
{
    int option;
    login();

    while (1)
    {
        system("cls");
        cout << "\n\n\n\n";
        cout << "\n\t\t\t\t\t\t\t>>>>>>>>>>>>>>>  PAYROLL SYSTEM  <<<<<<<<<<<<<<";
        cout << "\n";
        cout << "\n\t\t\t\t\t\t\t------------------------------------------------";
        cout << "\n\t\t\t\t\t\t\tENTER   1:   To Add New Employee Details";
        cout << "\n\t\t\t\t\t\t\t------------------------------------------------";
        cout << "\n\t\t\t\t\t\t\tENTER   2:   To View List of Employees";
        cout << "\n\t\t\t\t\t\t\t------------------------------------------------";
        cout << "\n\t\t\t\t\t\t\tENTER   3:   To View a particular Employees";
        cout << "\n\t\t\t\t\t\t\t------------------------------------------------";
        cout << "\n\t\t\t\t\t\t\tENTER   4:   To Remove an Employee Details";
        cout << "\n\t\t\t\t\t\t\t------------------------------------------------";
        cout << "\n\t\t\t\t\t\t\tENTER   5:   To Modify Existing Employee Details";
        cout << "\n\t\t\t\t\t\t\t------------------------------------------------";
        cout << "\n\t\t\t\t\t\t\tENTER   6:   To Generate PaySlip";
        cout << "\n\t\t\t\t\t\t\t------------------------------------------------";
        cout << "\n\t\t\t\t\t\t\tENTER   7:   To Exit     ";
        cout << "\n\t\t\t\t\t\t\t------------------------------------------------";
        cout << "\n\n\t\t\t\t\t\t\tPlease Enter Your Choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            system("cls");
            add_record();
            cout << "\n\t\t\t\t\t\t\tpress any key for Main Menu...";
            getch();
            break;
        }

        case 2:
        {
            system("cls");
            cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
            cout << setw(8) << "ID" << setw(20) << "NAME" << setw(17) << "WORKING DAYS" << setw(14) << "EXTRA_HOURS" << setw(14) << "BASIC_SALARY" << setw(14) << "OVERTIME" << setw(14) << "DEDUCTION" << setw(8) << "HRA" << setw(8) << "DA" << setw(8) << "MA" << setw(8) << "PF" << setw(14) << "INSURANCE" << setw(15) << "DESIGNATION" << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
            show_all();
            cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
            cout << "\n\t\t\t\t\t\t\tPress any key for Main Menu... ";
            getch();
            break;
        }

        case 3:
        {
            system("cls");
            show_record();
            cout << "\n\t\t\t\t\t\t\tPress any key for Main Menu... ";
            getch();
            break;
        }

        case 4:
        {
            system("cls");
            delete_record();
            cout << "\n\n\t\t\t\t\t\t\t\tPress any key for Main Menu... ";
            getch();
            break;
        }

        case 5:
        {
            system("cls");
            modify_record();
            cout << "\n\t\t\t\t\t\t\tPress any key for Main Menu... ";
            getch();
            break;
        }

        case 6:
        {
            system("cls");
            generate_slip();
            cout << "\n\t\t\t\t\t\t\tpress any key for Main Menu... ";
            getch();
            break;
        }

        case 7:
        {
            exit(0);
        }

        default:
        {

            cout << "\n\n\n\n\t\t\t\t\t\t\tIncorrect option!!" << endl;
            cout << "Press any key for Main Menu... ";
            getch();
            break;
        }
        }
    }

    return 0;
}

void add_record()
{
    char ch = 'y';
    file.open("stock.txt", ios::app | ios::binary);
    while (ch == 'y' || ch == 'Y')
    {
        system("cls");
        slip.get_record();
        slip.calc_record();
        file.write((char*)&slip, sizeof(slip));
        cout << "\n\n\n\t\t\t\t\t\t\tAdd more records....(y)? ";
        cin >> ch;
    }
    file.close();
}

void show_all(void)
{
    file.open("stock.txt", ios::in | ios::binary);
    if (!file)
    {
        cout << "No Employee record\n";
        return;
    }
    else
    {
        file.read((char*)&slip, sizeof(slip));
        while (!file.eof())
        {
            slip.put_record();
            file.read((char*)&slip, sizeof(slip));
        }
    }

    file.close();
}

void show_record(void)
{
    int no, flag = 0;

    file.open("stock.txt", ios::in | ios::binary);
    if (!file)
    {
        cout << "File not found\n";
    }
    else
    {
        cout << "\n\n\n\t\t\t\t\t\t\tEnter Employee Id. to search: ";
        cin >> no;

        file.read((char*)&slip, sizeof(slip));
        while (!file.eof())
        {
            if (no == slip.show_id())
            {
                flag = 1;
                cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                cout << setw(8) << "ID" << setw(20) << "NAME" << setw(17) << "WORKING DAYS" << setw(14) << "EXTRA_HOURS" << setw(14) << "BASIC_SALARY" << setw(14) << "OVERTIME" << setw(14) << "DEDUCTION" << setw(8) << "HRA" << setw(8) << "DA" << setw(8) << "MA" << setw(8) << "PF" << setw(14) << "INSURANCE" << setw(15) << "DESIGNATION" << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                slip.put_record();
                cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                break;
            }
            file.read((char*)&slip, sizeof(slip));
        }
        if (flag == 0)
        {
            cout << "\n\t\t\t\t\t\t\tEmployee not found..\n\n";
        }
    }
    file.close();
}

void delete_record()
{
    int no,flag=0;
    cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tEnter Employee id to delete: ";
    cin >> no;

    file.open("stock.txt",ios::in | ios::binary);
    while (file.read((char *)&slip, sizeof(slip)))
   {
    if (no == slip.show_id())
    {
        flag++;
      
    }
   }
   file.close();

   if(flag==0)
   {
        cout << "\n\n\t\t\t\t\t\t\t\tNo Employee found";
      return; 
   }
   else
   {
       cout<<"\n\n\t\t\t\t\t\t\t\tRecord deleted";
   } 


    fstream file2;

    file2.open("new.txt", ios::out | ios::binary);

    file.open("stock.txt", ios::in | ios::binary);
   
    if (!file)
    {
        cout << "File not found\n";
        return;
    }
    else
    {
        file.read((char*)&slip, sizeof(slip));
        while (!file.eof())
        {
            
            if (no != slip.show_id())
            {
                
                file2.write((char*)&slip, sizeof(slip));
            }
            file.read((char*)&slip, sizeof(slip));
        }
    }

    file2.close();
    file.close();
    remove("stock.txt");
    rename("new.txt", "stock.txt");

}

void modify_record()
{

    string cname,cdesg;
    char cont, ch;
    int cid, cdays, opt,flag=0;
    long double cbasic_salary;
    double cextra_hours;

CID:

    cout << "\n\t\t\t\t\t\t\tEnter Employee id: ";
    cin >> cid;
  file.open("stock.txt", ios::in | ios::out | ios::binary);

   while (file.read((char *)&slip, sizeof(slip)))
   {
    if (slip.show_id() == cid)
    {
        
        flag++;
    }
   }
   file.close();

    if(flag==0)
    {
         cout << "\n\n\t\t\t\t\t\t\tNo Employee found";
        cout << "\n\n\t\t\t\t\t\t\tTry again(y) or press any key to go back: ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
            goto CID;
        else
        return;
    }
    

    do
    {
        system("cls");
        cout << "\n\t\t\t\t\t\t\t------------------------------------------------";
        cout << "\n\t\t\t\t\t\t\t\t\t\tUPDATE MENU";
        cout << "\n\t\t\t\t\t\t\t------------------------------------------------";
        cout << "\n\t\t\t\t\t\t\tPress1: Update employee name:";
        cout << "\n\t\t\t\t\t\t\t------------------------------------------------";
        cout << "\n\t\t\t\t\t\t\tPress2: Update employee Working days:";
        cout << "\n\t\t\t\t\t\t\t------------------------------------------------";
        cout << "\n\t\t\t\t\t\t\tPress3: Update employee Extra hours:";
        cout << "\n\t\t\t\t\t\t\t------------------------------------------------";
        cout << "\n\t\t\t\t\t\t\tPress4: Update employee Basic Salary:";
        cout << "\n\t\t\t\t\t\t\t------------------------------------------------";
        cout << "\n\t\t\t\t\t\t\tPress5: Update employee Designation";
        cout << "\n\t\t\t\t\t\t\t------------------------------------------------";
        cout << "\n\t\t\t\t\t\t\tPress6: Exit the Update Menu:";
        cout << "\n\t\t\t\t\t\t\t------------------------------------------------";
        cout << "\n\t\t\t\t\t\t\tEnter option: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "\n\n\t\t\t\t\t\t\tEnter employee name: ";
            getline(cin >> ws, cname);
            while(!isname(cname)){
            cout<<"\t\t\t\t\t\t\tPlease only enter name in alphabets: ";
            getline(cin >> ws, cname);
             }
            break;

        case 2:
            cout << "\n\t\t\t\t\t\t\tEnter working days (out of 31): ";
            cin >> temp;
            while(!isnum(temp)) {
            cout<<"\t\t\t\t\t\t\tPlease only enter days in digits: ";
            cin>>temp;
            }
            cdays=stoi(temp);
            break;

        case 3:
            cout << "\n\n\t\t\t\t\t\t\tEnter Extra hours: ";
             cin >> temp;
            while(!isdouble(temp)) {
            cout<<"\t\t\t\t\t\t\tPlease only enter basic salary in digits: ";
            cin>>temp;
            }
            cextra_hours=stod(temp);
            break;
        case 4:
            cout << "\n\n\t\t\t\t\t\t\tEnter basic salary: ";
            cin >> temp;
            while(!isdouble(temp)) {
            cout<<"\t\t\t\t\t\t\tPlease only enter basic salary in digits: ";
            cin>>temp;
            }
            cbasic_salary=stold(temp);
            break;
        case 5:
            cout<<"\n\n\t\t\t\t\t\t\tEnter Designation: ";
            getline(cin >> ws, cdesg);
            while(!isname(cdesg)){
            cout<<"\t\t\t\t\t\t\tPlease enter Designation in alphabets: ";
            getline(cin >> ws, cdesg);
            }
            break;
        case 6:
            return;
            break;
        default:
            cout << "\n\n\t\t\t\t\t\t\tinvalid option\n";
            return;
        }

        file.open("stock.txt", ios::in | ios::out | ios::binary);
        if (!file)
        {
            cout << "file not found";
            return;
        }

        while (file.read((char *)&slip, sizeof(slip)))
        {
            if (slip.show_id() == cid)
            {
                if (opt == 1)
                    slip.updatename(cname);
                else if (opt == 2)
                {
                    slip.update_workdays(cdays);
                    slip.calc_record();
                }
                else if (opt == 3)
                {
                    slip.update_extrahours(cextra_hours);
                    slip.calc_record();
                }
                else if (opt == 4)
                {
                    slip.update_basic_salary(cbasic_salary);
                    slip.calc_record();
                }
                else
                {
                    slip.update_designation(cdesg);
                }
                int pos = sizeof(slip);
                file.seekp(-pos, ios::cur);
                file.write((char *)&slip, sizeof(slip));
            }
        }
        file.close();

        cout << "\n\t\t\t\t\t\t\tTo update more(y) or press any key to go back:";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');

}

void generate_slip()
{

    int no, flag = 0;

    file.open("stock.txt", ios::in | ios::binary);
    if (!file)
    {
        cout << "File not found\n";
    }
    else
    {
        cout << "\n\n\n\t\t\t\t\t\t\tEnter Employee Id. ";
        cin >> no;

        file.read((char *)&slip, sizeof(slip));
        while (!file.eof())
        {
            if (no == slip.show_id())
            {
                flag = 1;
                system("cls");
                slip.put_slip();
                break;
            }
            file.read((char *)&slip, sizeof(slip));
        }
        if (flag == 0)
        {
            cout << "\n\n\t\t\t\t\t\t\tEmployee not found..\n";
        }
    }
    file.close();
}
