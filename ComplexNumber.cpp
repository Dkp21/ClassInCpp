#include <iostream>
#include <memory>

using namespace std;

class ComplexNumber
{
    public:
        ComplexNumber(int a = 0, int b = 0): x(a), y(b)
        {
            cout << __func__ << " (" << x << ") + (" << y << "i)" << endl;
        };

        ~ComplexNumber()
        {
            cout << __func__ << endl;
        }

        ComplexNumber & operator++()
        {
            ++x;
            ++y;
            return *this;
        };

        ComplexNumber operator++(int)
        {
            ComplexNumber tmp(*this);
            operator++();
            return tmp;
        };

        friend ostream& operator<<(ostream& o, const ComplexNumber & n);

    private:
        int x;
        int y;
};

ostream& operator<<(ostream & o, const ComplexNumber & n)
{
    o << " (" << n.x << ") + (" << n.y << "i)";
    return o;
}

int main(int argc, char **argv)
{

    unique_ptr<ComplexNumber> a = make_unique<ComplexNumber>(-1, -9);    

    cout << "Original number: " << (*a)  << endl;
    cout << "Pre increment : " << ++(*a) << endl;
    (*a)++;
    cout << "Post increment: " << (*a) << endl;

    return 0;
}
