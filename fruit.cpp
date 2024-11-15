#include <iostream>
using namespace std;

class Apples 
{
  public:
    int apple;
    int apples()
    {
        cout << "Enter number of apples: ";
        cin >> apple;
        cout << "Number of Apples: " << apple << endl;

        return apple;
    }
};

class Mangoes 
{
  public:
    int mango;
    int mangoes()
    {
        cout << "\nEnter number of Mangoes: ";
        cin >> mango;
        cout << "Number of Mangoes: " << mango << endl;

        return mango;
    }
};

class Fruits : public Apples, public Mangoes
{
  public:
    void cal(int a, int b) 
    {
        cout << "\nTotal Number of Fruits: " << a + b << endl;
    }
};

int main() 
{
    Fruits obj;
    obj.apples();
    obj.mangoes();
    int a = obj.apple;
    int b = obj.mango;

    obj.cal(a, b);
    return 0;
}









