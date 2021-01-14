#include <iostream>

using namespace std;

int det(int r, int matrix1[4][4]);
int main()
{

    int m2[4][4];

 for(int i =0; i<4;i++){
        for (int j=0; j<4; j++){
            cin >> m2[i][j];
        }
    }

        int r1;
        cin>> r1;
       int v = det(r1,m2);
       cout << v <<"\n";

}
int det(int r, int m2[4][4]){

    int d;
    int x =0;
    if (r!= 2)
    x = m2[0][0];

    if (r ==2){
            for (int i = 0; i < r-1; i++){
            for (int j = 0; j < r-1; j++){
                m2[i][j] = m2[i+1][j+1];
            }
        }
      d =  (m2[0][0] * m2[1][1]) - (m2[0][1] * m2[1][0]);
      return d;
    }
    else{
        for (int i = 0; i < r-1; i++){
            for (int j = 0; j < r-1; j++){
                m2[i][j] = m2[i+1][j+1];
            }
        }
        r--;
        d = x * det(r, m2);
        return d;
    }
}

