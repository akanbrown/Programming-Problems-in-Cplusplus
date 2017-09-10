#include <iostream>
#include <sstream>
#include <stdexcept>
#include <fstream>
#include <vector>

class VaEtVient
{
private:
    int current;
    int start;
    int end;
    bool backwards;
public:
    VaEtVient(int start, int end);
    void startFrom(int number, bool backwards);
    int nextNumber();
};

class Rektangle
{
private:
    std::vector<std::vector<char>> grid;
    std::string input;

    void fillColumn(int col, VaEtVient& vev);
    void fillRow(int row, VaEtVient& vev);

public:
    Rektangle(std::string input, int width, int height);
    void fill();
    void display();
};

int main(int argc, char *argv[])
{
    std::ifstream fh(argv[1]);
    std::string input;
    int width, height;
    getline(fh, input);
    fh >> width >> height;

    Rektangle rekt(input, width, height);
    rekt.fill();
    rekt.display();
    return 0;
}

Rektangle::Rektangle(std::string input, int width, int height)
{
    this->input = input;
    for(std::string::size_type r = 0; r < (input.length() - 1) * height + 1; r++)
    {
        std::vector<char> row((input.length() - 1) * width + 1, ' ');
        grid.push_back(row);
    }
}

void Rektangle::fill()
{
    VaEtVient vev(0, input.length() - 1);
    fillRow(0, vev);
    vev.startFrom(0, false);
    fillColumn(0, vev);

    for(std::string::size_type col = 1; col < grid[0].size(); col++)
    {
        if(grid[0][col] == input[0])
        {
            vev.startFrom(0, false);
            fillColumn(col, vev);
        }
        else if(grid[0][col] == input[input.length() - 1])
        {
            vev.startFrom(input.length() - 1, true);
            fillColumn(col, vev);
        }
    }

    for(std::string::size_type row = 1; row < grid.size(); row++)
    {
        if(grid[row][0] == input[0])
        {
            vev.startFrom(0, false);
            fillRow(row, vev);
        }
        else if(grid[row][0] == input[input.length() - 1])
        {
            vev.startFrom(input.length() - 1, true);
            fillRow(row, vev);
        }
    }
}

void Rektangle::fillRow(int row, VaEtVient &vev)
{
    for(std::string::size_type col = 0; col < grid[row].size(); col++)
        grid[row][col] = input[vev.nextNumber()];
}

void Rektangle::fillColumn(int col, VaEtVient &vev)
{
    for(std::string::size_type row = 0; row < grid.size(); row++)
        grid[row][col] = input[vev.nextNumber()];
}

void Rektangle::display()
{
    for(std::string::size_type row = 0; row < grid.size(); row++)
    {
        for(std::string::size_type col = 0; col < grid[row].size(); col++)
            std::cout << grid[row][col] << ' ';
        std::cout << std::endl;
    }
}

VaEtVient::VaEtVient(int start, int end)
{
    this->start = start;
    this->end = end;
    current = start - 1;
    backwards = false;
}

void VaEtVient::startFrom(int number, bool backwards)
{
    if(number > end || number < start)
    {
        std::stringstream error;
        error << number << " should be between " << start << " and " << end;
        throw std::invalid_argument(error.str());
    }
    this->current = backwards ? number + 1 : number - 1;
    this->backwards = backwards;
}

int VaEtVient::nextNumber()
{
    if(backwards)
    {
        if(--current < start)
        {
            current = start + 1;
            backwards = false;
        }
    }
    else
    {
        if(++current > end)
        {
            current = end - 1;
            backwards = true;
        }
    }
    return current;
}
