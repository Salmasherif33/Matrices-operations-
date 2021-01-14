#include <iostream>
#include<string>
 #include<cstdlib>
using namespace std;

class Resistor{
public:
    void set_resisitor_area(double a){
    Area = a;
    }
    void set_resisitor_length(double g){
    Length = g;
    }
    void set_resisitor_rho(double h){
    Rho = h;
    }
    void setlabel(string l){
    label = l;
    }
    double get_resistor_value(){
    double Value = (Rho * Length) / Area;
    return Value;
    }
    double getarea(){
    return Area;
    }
    double getlength(){
    return Length;
    }
    double getrho(){
    return Rho;
    }
    string getlabel(){
    return label;
    }

private:
    double Area, Length, Rho;
    string label;
};


 int main()
  {
int N;
double i;
string res;
cout <<"the value of current:";
cin>>i;
cout << "the number of resistors is (less than 100):";
cin >> N;
cout<<"the value of the resistor in the format R01(Rho,length,area)"<<"\n";
Resistor Rt[100];
int count1 = 0;
int flag =0;
int flag2;
for (int j = 0; j < N; j++){
    cin>>res;
flag = 0;
count1 = 0;
  for(int k = 0; k < res.length();k++){

    if(res[k] == 'R'){
        Rt[j].setlabel(res.substr(k,3));
    }
    else if(res[k] == '('){
         count1 =k;;
    }
         else if (res[k] == ','&& flag == 0){
        string r = res.substr(count1+1, k-count1-1);
        Rt[j].set_resisitor_rho(atof(r.c_str()));
        flag = k;
            }
            else if(flag != 0 && res[k] == ','){
                string len = res.substr(flag +1,k-flag-1 );
                Rt[j].set_resisitor_length(atof(len.c_str()));
                 flag2 = k;
            }
            else if (res[k] == ')'){
                string ar = res.substr(flag2+1,k - flag2 -1);
                Rt[j].set_resisitor_area(atof(ar.c_str()));
            }
}
}

for (int j = 0; j < N; j++){

    cout << Rt[j].getlabel() << "volt = "<< i * Rt[j].get_resistor_value() <<"v"<<"\n";
}
           return 0;
            }


