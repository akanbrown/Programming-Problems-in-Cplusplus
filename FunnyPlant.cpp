#include <iostream>

int main(int argc, char* argv[])
{
    int people = std::stoi(argv[1]);
    int n_plants = std::stoi(argv[2]);
    int weeks = 1;
    int n_fruits = 0;
    while (n_fruits < people) {
        ++weeks;
        n_fruits += n_plants;
        n_plants += n_fruits;
    }

    std::cout << weeks << std::endl;

    return 0;
}
