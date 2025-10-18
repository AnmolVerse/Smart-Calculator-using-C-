#include <iostream>
#include <cmath>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

// Calculator Functions
double add(double a, double b){ 
    return a+b; 
}
double subtract(double a, double b){ 
    return a-b; 
}
double multiply(double a, double b){ 
    return a*b; 
}
double division(double a, double b){
    if(b==0){
        cout<<"Division by zero isn't possible\n";
        return 0;
    }
    return a/b;
}
double mod(double a, double b){
     return fmod(a,b); 
    }
double pwr(double a, double b){
     return pow(a,b); 
    }
double square(double a){ 
    return a*a;
 }
double cube(double a){
     return a*a*a;
     }
long long fact(int a){
    if(a<0){
        cout<<"Factorial not defined for negative numbers\n";
        return -1;
    }
    long long result =1;
    for(int i=1; i<=a; i++)
        result *= i;
    return result; 
}
double cuberoot(double a){ return cbrt(a); }

// History Function to store
void saveHistory(const string& operation){    
    ofstream file("History.txt", ios::app);
    if(file.is_open()){
        file << operation << endl;
        file.close();
    }
}

void viewHistory(){
    ifstream file("History.txt");
    string line;
    if(file.is_open()){
        cout<<"----- Calculation History -----\n";
        while(getline(file, line))
            cout << line << endl;
        cout<<"-------------------------------\n";
        file.close();
        
        cout<<"\nPress 1 to clear history\n Press 2 to go back to main menu\n";
        int choice;
        cin >> choice;
        if(choice == 1){
            ofstream clearFile("History.txt", ios::trunc);
            clearFile.close();
            system("cls");
            cout<<"History cleared!\n";
            system("pause");
        }
    } else {
        cout<<"No History Found!\n";
        system("pause");
    }
}
// Main Function
int main(){
    system("cls");
    int choice;
    double num1, num2;

    cout<<"Loading Smart Calculator";
    for(int i=0; i<3; i++){
        cout<<".";
        Sleep(500);
    }
    system("cls");

    while(true){
        cout<<"\n==========================================\n";
        cout<<"             SMART CALCULATOR             \n";
        cout<<"==========================================\n";
        cout<<"1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n6. Power\n7. Square\n8. Cube\n9. Square Root\n10. Cube Root\n11. Factorial\n12. View History\n13. Exit\n";
        cout<<"--------------------------------------------\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        system("cls");

        ostringstream op;
        double resultD;
        long long resultL;

        if(choice >=1 && choice <=5){
            cout<<"Enter two numbers: ";
            cin >> num1 >> num2;
        }
        else if(choice ==6){
            cout<<"Enter base: ";
            cin >> num1;
            cout<<"Enter exponent: ";
            cin >> num2;
        }
        else if(choice >=7 && choice <=11){
            cout<<"Enter number: ";
            cin >> num1;
        }
        else if(choice ==13){
            cout<<"Exiting Smart Calculator...\n";
            break;
        }
        else if(choice ==12){
            viewHistory();
            continue;
        }
        else{
            cout<<"Invalid choice! Try again...\n";
            system("pause");
            continue;
        }
        // Operations
        switch(choice){
            case 1:
                resultD = add(num1,num2);
                cout<<"-------------------------\n";
                cout<<"Result => "<<num1<<" + "<<num2<<" = "<<resultD<<"\n";
                cout<<"-------------------------\n";
                op << num1 << " + " << num2 << " = " << resultD;
                break;
            case 2:
                resultD = subtract(num1,num2);
                cout<<"-------------------------\n";
                cout<<"Result => "<<num1<<" - "<<num2<<" = "<<resultD<<"\n";
                cout<<"-------------------------\n";
                op << num1 << " - " << num2 << " = " << resultD;
                break;
            case 3:
                resultD = multiply(num1,num2);
                cout<<"-------------------------\n";
                cout<<"Result => "<<num1<<" * "<<num2<<" = "<<resultD<<"\n";
                cout<<"-------------------------\n";
                op << num1 << " * " << num2 << " = " << resultD;
                break; 
            case 4:
                resultD = division(num1,num2);
                 cout<<"-------------------------\n";
                cout<<"Result => "<<num1<<" / "<<num2<<" = "<<resultD<<"\n";
                cout<<"-------------------------\n";
                op << num1 << " / " << num2 << " = " << resultD;
                break;
            case 5:
                resultD = mod(num1,num2);
                cout<<"-------------------------\n";
                cout<<"Result => "<<num1<<" % "<<num2<<" = "<<resultD<<"\n";
                cout<<"-------------------------\n";
                op << num1 << " % " << num2 << " = " << resultD;
                break;
            case 6:
                resultD = pwr(num1,num2);
                cout<<"-------------------------\n";

                cout<<"Result => "<<num1<<" ^ "<<num2<<" = "<<resultD<<"\n";
                cout<<"-------------------------\n";
                op << num1 << " ^ " << num2 << " = " << resultD;
                break;
            case 7:
                resultD = square(num1);
                cout<<"-------------------------\n";

                cout<<"Result => "<<num1<<" ^ 2 = "<<resultD<<"\n";
                cout<<"-------------------------\n";
                op << num1 << " ^ 2 = " << resultD;
                break;
            case 8:
                resultD = cube(num1);
                cout<<"-------------------------\n";

                cout<<"Result => "<<num1<<" ^ 3 = "<<resultD<<"\n";
                cout<<"-------------------------\n";
                op << num1 << " ^ 3 = " << resultD;
                break;
            case 9:
                 cout<<"-------------------------------------\n";

                if(num1 >= 0){
                    cout<<"Result => Sqaure Root of"<<num1<<" = "<<sqrt(num1)<<"\n";
                    op << "Square root of " << num1 << " = " << sqrt(num1);
                } else {
                    double imag = sqrt(-num1);
                    cout<<"Result => Square root of "<<num1<<" = "<<imag<<"i\n";
                    op << "Square Root of " << num1 << " = " << imag << "i";
                }
                cout<<"-------------------------------------\n";
                break;
            case 10:
                resultD = cuberoot(num1);
             cout<<"-----------------------------------\n";
             cout<<"Result => Cube root of "<<num1<<" = "<<resultD<<"\n";
             cout<<"-----------------------------------\n";
            op << "Cube root of " << num1 << " = " << resultD;
            break;
            case 11:
             resultL = fact((int)num1);
             cout<<"-------------------------\n";

                cout<<"Result => "<<(int)num1<<"! = "<<resultL<<"\n";
                cout<<"-------------------------\n";
                op << (int)num1 << "! = " << resultL;
                break;
        }

        // Save to history
        if(choice >=1 && choice <=11){
            saveHistory(op.str());
        }
        system("pause");
        system("cls");
    }

    return 0;
}