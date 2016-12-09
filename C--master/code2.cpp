#include <iostream>
#include <stdlib.h>
using namespace std;

int set_flag =0;
int flag = 0;
#define X 9
#define Y 9

void Fillrect(int arr[][Y], int x, int y, int replace);
void paint(int arr[][Y], int x, int y, int cordinate, int replace);



//main method to let the user input the co-ordiates.
int main(int argc, char const *argv[])
 {
    int arr[X][Y] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 1, 1, 1, 0},
                        {0, 0, 1, 0, 0, 0, 0, 1, 0},
                        {0, 0, 1, 0, 0, 0, 0, 1, 0},
                        {0, 0, 1, 0, 0, 0, 0, 1, 0},
                        {0, 0, 1, 0, 0, 0, 0, 1, 0},
                        {0, 0, 1, 1, 1, 1, 1, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       
                        };
    int replace = 1;
    int b = (sizeof((arr[0]))/sizeof((arr[0][0])));
    int a = (sizeof((arr))/sizeof((arr[0])));
    while(flag!=1) {
        int x, y;
        cout << "Please Insert the X cordinate of element : ";
        cin >> x;
                if(x < 0){
                cerr <<"Negative index entered"<<endl;
                cerr<<"Please re-enter from beginning"<<endl;
                continue;
                }
        if(x > a - 1) {
            cerr << "Out of bound index, Rows entered exceeds:"<<X<< endl;
                         cerr<<"Please re-enter from beginning"<<endl;
            continue;
        }
        cout << "Please Insert the Y cordinate of element: ";
        cin >> y;
                if(y < 0){
                cerr <<"Negative index entered"<<endl;
                cerr<<"Please re-enter from beginning"<<endl;
                continue;
                }
        if( y > b - 1) {
            cerr << "Out of bound indexRows entered exceeds:"<<Y<< endl;
                        cerr<<"Please re-enter from beginning"<<endl;
            continue;
        }

    Fillrect(arr, x, y, replace);
    //int cordinate = arr[x][y];
    if(set_flag == 0)
    {
      for (int i=0; i<X; i++)
      {
          for (int j=0; j<Y; j++)
             cout << arr[i][j] << " ";
          cout << endl;
     } }
else{
cerr<<"Figure not in a closed boundary"<<endl;
    }
}}





void paint(int arr[][Y], int x, int y, int cordinate, int replace)
{
  
    if (x < 0 || x >= X || y < 0 || y >= Y)
    {
      set_flag =1;
      return;
    }
    if (arr[x][y] != cordinate)
       return;
 
    // Replace the color at (x,y)
    arr[x][y] = replace;
 
  
    paint(arr, x+1, y, cordinate, replace);
    paint(arr, x-1, y, cordinate, replace);
    paint(arr, x, y+1, cordinate, replace);
    paint(arr, x, y-1, cordinate, replace);
}

void Fillrect(int arr[][Y], int x, int y, int replace)
{
    int cordinate = arr[x][y];
    paint(arr, x, y, cordinate, replace);
}
