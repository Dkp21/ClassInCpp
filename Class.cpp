#include <iostream>
#include <memory>

using namespace std;

class Person
{
    public:

        Person()
        {
            cout << "Constructor : " << __func__ << endl;
        }

#ifdef DEMO_VIRTUAL_DESTRUCTOR
        virtual ~Person()
#else 
        ~Person()
#endif
        {
            cout << "Destructor : " << __func__ << endl;
        }

#ifdef DEMO_PURE_VIRTUAL_CLASS
        virtual void aboutMe(void) = 0;
#else
        void aboutMe(void)
        {
            cout << "Person - " << __func__ << endl;
        }
#endif
};

class Student: public Person
{
    public:
        Student()
        {
            cout << "Constructor : " << __func__ << endl;
        }

        ~Student()
        {
            cout << "Destructor : " << __func__ << endl;
        }

        void aboutMe(void)
        {
            cout << "Student - " << __func__ << endl;
        }
};


int main(int argc, char **argv)
{
    unique_ptr<Person> p = make_unique<Student>();

    p->aboutMe();
    
    return 0;
}
