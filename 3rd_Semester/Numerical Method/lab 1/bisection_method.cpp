#include <iostream>
#include <cmath>
using namespace std;

class Bisection_method
{
private:
    int iteration = 0, breaker = 0;
    float Xu = 0, fXu = 0, Xl = 0, fXl = 0, XmOld = 0, XmNew = 0, fXmNew = 0, fXmOld = 0, error = 1;

public:
    // We suppose the equation is Sin(X)+X^2+5X-9
     float function_calculator(float temp_input)
     {
         float result = sin(temp_input) + pow(temp_input, 2) + (5 * temp_input) - 9;
         return result;
     }

    // We suppose the equation is sin(x)-2X+1=0
    // float function_calculator(float temp_input)
    // {
    //     float result = sin(temp_input) - (2 * temp_input) + 1;
    //     return result;
    // }

    // We suppose the equation is ln(X)-cos(X)
//    float function_calculator(float temp_input)
//    {
//        float result = log(temp_input) - cos(temp_input);
//        return result;
//    }

    void user_input()
    {
        cout << "Enter value of Xu: ";
        cin >> Xu;
        cout << "Enter value of Xl: ";
        cin >> Xl;
    }

    float XmCalc(float num1, float num2)
    {
        float temp = num1 + num2;
        return temp / 2;
    }

    float error_calculator()
    {
        float temp = (fXmNew - fXmOld) / fXmNew;
        return abs(temp);
    }

    void process()
    {
        user_input();
        // TABLE HEADINGS
        cout << "Iteration\tXu\tf(Xu)\t\tXl\tf(Xl)\t\tXm\tf(Xm)\tError" << endl;
        do
        {
            iteration++;
            fXu = function_calculator(Xu);
            fXl = function_calculator(Xl);
            XmNew = XmCalc(Xu, Xl);
            fXmOld = fXmNew;
            fXmNew = function_calculator(XmNew);
            error = error_calculator();

            // DISPLAYING VALUES OF ITEMS

            cout << iteration << "\t\t" << Xu << "\t" << fXu << "\t\t" << Xl << "\t" << fXl << "\t\t" << XmNew << "\t" << fXmNew << "\t\t" << error << endl;

            if (fXmNew < 0)
            {
                Xl = XmNew;
                fXl = fXmNew;
            }
            else
            {
                Xu = XmNew;
                fXu = fXmNew;
            }

            XmOld = XmNew;
            if (error <= 0.05)
            {
                XmNew = XmCalc(Xu, Xl);
                fXmNew = function_calculator(XmNew);
                breaker = 1;
            }
        } while (breaker != 1);

        cout << endl
             << "Final values are: " << endl;
        cout << "Xu: " << Xu << endl;
        cout << "f(Xu): " << fXu << endl;
        cout << "Xl: " << Xl << endl;
        cout << "f(Xl): " << fXl << endl;
        cout << "Xm: " << XmNew << endl;
        cout << "f(Xm): " << fXmNew << endl;
    }
};

int main()
{
    Bisection_method b1;
    b1.process();
    return 0;
}