#include <iostream>
using std::string;

int main(int ac, char **av)
{
    if(ac == 1)
        return 1;
    
    for (int i = 1 ; i < ac ;i++)
    {
        string str = av[i];
        for (int j = 0; av[i][j];j++)
        {
            char c = av[i][j];
            std::cout << (char)std::toupper(c);
        }
    }
    std::cout << std::endl;
}