    #include <iostream>
    #include <string.h>
    

class Parent {
    public:
    std::string lastName;
    Parent()
    {
                std::cout << "parent class constructor ";
    }
    Parent(std::string name, std::string lastName, int age):Name(name),lastName(lastName),age(age)
    {

    }
    std::string talk()
    {
        return  Name;

    }
    int sleep()
    {
        return age;
    }

    void setTalk()
    {
       int a;
       std::cin >> age;
    }
    
    private:
    std::string Name;
    int age;
};


class Child :  public Parent{
    public:
    Child(std::string name, int age):Name(name),age(age)
    {
            std::cout << "chikd class constructor ";
    }
    private:
    std::string Name;
    int age;
};


int main()
{
    Parent Me("issam", "ch", 25);
    Child Son("issam", 25);
    // std::cout << Son.sleep() << std::endl;
    // std::cout << "=====================" << std::endl;
    Son.setTalk();
    std::cout << Son.sleep();
    return 0;
}