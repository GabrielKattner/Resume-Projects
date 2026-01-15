#include <iostream>

using namespace std;

void userInput(int& f, int& in){
    
    cout << "Please Enter How Many Feet: ";
    cin >> f;

    cout << "Please Enter How Many Inches: ";
    cin >> in;

}

int calculation(double f, int in, double& m, double& cm){

    int temp;
    int temp2;

    if(in == 12){
        f++;
        in = 0;
    } else if((in/12) >= 1){
        temp = in / 12;
        temp2 = in % 12;
        f += temp;
        in = temp2;
    }
    
    m = f*0.3048;
    cm = in*2.54;


    return m, cm;

}

void output(double m, double cm){
    cout << "Meters: " << m << endl;

    cout << "Centimeters: " << cm << endl;
}

int main(){

    int feet;
    int inches;
    double meters;
    double centimeters;

    userInput(feet, inches);

    calculation(feet, inches, meters, centimeters);

    output(meters, centimeters);

    


}