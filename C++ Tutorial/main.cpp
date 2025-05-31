#include <iostream>
#include "Tommy.h"
#include <string>
using namespace std;


class Cool{
    public:

        Cool(string z, int y){
            setName(z);
            setAge(y);
        }


        void setAge(int num){
            age = num;
        }

        int getAge(){
            return age;
        }
         void setName(string str){
            name = str;
         }
         string getName(){
            return name ;
         }

    private:
        string name;
        int age;
};

int addNum(int a, int b){
    return a + b;
}


int main()
{

    int i = 0;
    int sum = 0;
    int input;
    while (i<5){
        cout << "Enter a number:\n";
        cin >> input;
        sum += input;
        i++;
    }
    cout << "The average is: " << sum/i+1 << endl;





    if (true) {
        cout << "hello";
    }


    Tommy green;


    Cool cheeseobject("Jude", 31);
    //cheeseobject.setName("Ryan");
    string name = cheeseobject.getName();
    int age = cheeseobject.getAge();
    cout << name << " is " << age << ".\n";


    sum =-10;

    if (sum > 10){
        cout << "The number is bigger than 10";
    }

    cout << sum << endl;
    cout << "Hello world!\n";
    cout << "man I really really like really love, no, boy I am obsessed with BACON!";
    cout << " and ham\n" << endl;

    int x;
    int y;

    cout << "Enter a number: \n";
    cin >> x;
    cout << "Enter another number: \n";
    cin >> y;
    sum = x + y;
    cout << "The answer is: " << sum << endl;
    int o = 24;
    int p = 7;
    int quotient = o/p;
    int remainder = o%p;
    cout << quotient;
    cout << " remainder: " << remainder << endl;

    cout << addNum(4, 5) << endl;


    return 0;
}
