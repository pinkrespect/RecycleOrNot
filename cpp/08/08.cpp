#include <iostream>
#include <string>
using namespace std;
 
class Console {
public :
    int menu() {
    int num;
    cout << "\n예약:1, 취소:2, 보기:3, 끝내기:4 >>";
    cin >> num;
    return num;
    }
    int time_menu() {
    int num;
    cout << "7시:1, 12시:2, 17시:3 >>";
    cin >> num;
    return num;
}
     
};
 
class Seat {
    string name;
    int number;
public :
    Seat() { this->name = "---"; this->number = -1; }
    void setName( string name) { this->name = name; }
    string getName() { return name; }
};
 
class Schedule {
    Seat *seat;
public :
    Schedule() {
        seat = new Seat[8];
    }
    void show(int num) {
        if( num == 1 ) cout << "7시:";
        else if( num == 2) cout << "12시:";
        else if( num == 3) cout << "17시:";
 
        for(int i=0; i<8; i++)
            cout << "\t" << seat[i].getName();
        cout << endl;
    }
    void setN(int num, string name) { seat[num-1].setName( name); }
    string getN(int num ) { return seat[num-1].getName(); }
};
 
class AirlineBook {
    Schedule *s;
public :
    AirlineBook() {
        s = new Schedule[3];
    }
    void program() {
        bool exit = true;
        int num;
        Console c;
        int seat_num;
        string name;
 
        while(exit) {
            num = c.menu();
        if( num == 1 ) {
            num = c.time_menu();
             
            if( num == 1 || num == 2 || num == 3 ) {
                s[num-1].show(num);
                cout << "좌석 번호 >>"; cin >> seat_num;
                cin.ignore(1);
                cout << "이름 입력 >>"; getline(cin, name);
                s[num-1].setN( seat_num, name);
            }
            else
                cout << "숫자를 잘못 입력하셨습니다." << endl;
        }
        else if( num == 2 ) {
            num = c.time_menu();
 
            if( num == 1 || num == 2 || num == 3 ) {
                s[num-1].show(num);
                cout << "좌석 번호 >>"; cin >> seat_num;
                cin.ignore(1);
                cout << "이름 입력 >>"; getline(cin, name);
                if( name != s[num-1].getN( seat_num) )
                    cout << "해당 좌석에 예약되어 있는 이름과 일치하지 않습니다." << endl;
                else
                    s[num-1].setN( seat_num, "---" );
            }
            else
                cout << "숫자를 잘못 입력하셨습니다." << endl;
        }
        else if( num == 3 ) {
             s[0].show(1);
             s[1].show(2);
             s[2].show(3);
        }
        else if( num == 4 ) {
            cout << "예약 시스템을 종료합니다." << endl;
            exit = false;
        }
        else
            cout << "숫자를 잘못 입력하셨습니다." << endl;
        }
    }
};
 
int main() {
    AirlineBook *Air = new AirlineBook();
 
    cout << "*** 한성한공에 오신것을 환영합니다. ***\n";
    Air->program();
}

