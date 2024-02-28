#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <Windows.h> 

using namespace std;

template<class InputIterator>
InputIterator Find_if(InputIterator first, InputIterator last)
{
    while (first != last)
    {
        if (pred(*first) != "")
        {
            return first;
        }
        else
        {
            --first;
        }
    }
    return last;
}

template<class InputIterator>
InputIterator Find_if_down(InputIterator first, InputIterator last)
{
    while (first != last)
    {
        if (pred(*first) != "")
        {
        return first;
        }
        else
        {
        --first;
        }
        
    }
    return last;
}



void SplitNum (string num_line, pair <char, pair<int, int>>& thing)
{
    int a;
    int b;

    char sv;
    string a_str;
    for (int i=0; i< num_line.size();++i)
    {
        if (num_line[i] == '*' || num_line[i] == '/' || num_line[i] == '-' || num_line[i] == '+' || num_line[i] == '^')
        {
            a = stoi(a_str);
            sv = num_line[i];
            b = stoi(num_line.substr(i + 1));
            break;
           
        }
    
        else
         {
            a_str += num_line[i];
         }
    }
    thing = { sv, {a,b} };
}



vector <string> SplitNum (string num_line)
{

    vector <string> thing;

    char sv;
    string a_str;
    for (int i = 0; i < num_line.size(); ++i)
    {
        if (num_line[i] == '*' || num_line[i] == '/' || num_line[i] == '-' || num_line[i] == '+' || num_line[i] == '^')
        {
            thing.push_back(a_str);
            string f;
            f+= num_line[i];
            thing.push_back(f);
            a_str.clear();

        }

        else
        {
            a_str += num_line[i];
        }
       
    }
    thing.push_back(a_str);
    return thing;
}



double Resalt(vector <string> thing)

{
    double res;

    if (count(thing.begin(), thing.end(), "/") > 0 || count(thing.begin(), thing.end(), "*") > 0)
    {
        for (int i = 0; i < thing.size(); ++i)
        {
            if (thing[i] == "/")
            {
                auto left = Find_if_down (thing.begin() + i - 1, thing.begin());
               
                auto right = Find_if (thing.begin() + i + 1, thing.end());
                double k = stod(*left) / stod(*right); //разыменовали итератор
                *right = "";
                thing[i - 1] = "";
                thing[i] = to_string(k);
                *left = "";
                res = k;
            }

            if (thing[i] == "*")
            {
                auto left = Find_if_down(thing.begin() + i - 1, thing.begin());
                auto right = Find_if(thing.begin() + i + 1, thing.end());

                double k = stod(*left) * stod(*right); //разыменовали итератор
                *right = "";
                thing[i - 1] = "";
                thing[i] = to_string(k);
                *left = "";
                res = k;
            }
        }
    }
    for (int i = 0; i < thing.size(); ++i)
    {
        if (thing[i] == "+")
        {
            auto left = Find_if_down(thing.begin() + i - 1, thing.begin());
            auto right = Find_if(thing.begin() + i + 1, thing.end());

            double k = stod(*left) + stod(*right); //разыменовали итератор
            *right = "";
            thing[i - 1] = "";
            thing[i] = to_string(k);
            *left = "";
            res = k;
        }

        if (thing[i] == "-")
        {
            auto left = Find_if_down(thing.begin() + i - 1, thing.begin());
            auto right = Find_if(thing.begin() + i + 1, thing.end());
            double k = stod(*left) - stod(*right); //разыменовали итератор
            *right = "";
            thing[i - 1] = "";
            thing[i] = to_string(k);
            *left = "";
            res = k;
        }
    }
    
    
    return res;
    
}

int Step(int i, int j)
{
    if (j == 1)
        return i;
    if (j==0)
        return 1;
    return i * Step(i, --j);

}
double sqrt(int a)
{
    double X, Xn;
    X = 0;
    Xn = 0.5 * (1 + a); // начальное приближение

    while (abs(X - Xn) > 0.0001) //   0.0001 - точность значения
        X = Xn,
        Xn = 0.5 * (Xn + a / Xn); // Итерационная формула Герона
    return Xn;
}



int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

  
    string x;
    cout << "Введите пример" << endl;
    getline(cin >> ws, x);
    vector <string> k = SplitNum(x);
    cout << Resalt(k) << endl;
  
}
