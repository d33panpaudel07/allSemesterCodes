#include <iostream>
#define MAX_LENGTH 5
using namespace std;

class DividedDifference
{
protected:
    int steps, gap, nOD;
    float Arr[MAX_LENGTH + 1][MAX_LENGTH] = {
        {1, 2, 3, 4, 5},
        {1, 1.4142, 1.7321, 2, 2.2361},
        {0},
        {0},
        {0},
        {0}};

public:
    DividedDifference()
    {
        steps = 0;
        gap = 0;
        nOD = 0;
    }

    void mainProcess()
    {
        for (int i = 2; i <= MAX_LENGTH; i++)
        {
        	steps=MAX_LENGTH - i;
        	nOD = i-1;	
            gap = nOD;
            cout << "Value of d" << nOD << "f will be : "<<endl ;
            for (int j = 0; j <= steps; j++)
            {
            	float upperValue=Arr[i - 1][j + 1] - Arr[i - 1][j];
            	float lowerValue=Arr[0][gap + j] - Arr[0][j];
                Arr[i][j] = upperValue/lowerValue;
                cout<<j+1<<" ) "<<Arr[i][j]<<endl;
            }
            cout<<endl;
        }
    }
};

int main()
{
    DividedDifference d1;
    d1.mainProcess();
}
