/*
To disarm the bomb you have to cut some wires. These wires are either white, black, purple, red, green or orange.
The rules for disarming are simple:
If you cut a white cable you can't cut white or black cable.
If you cut a red cable you have to cut a green one
If you cut a black cable it is not allowed to cut a white, green or orange one
If you cut a orange cable you should cut a red or black one
If you cut a green one you have to cut a orange or white one
If you cut a purple cable you can't cut a purple, green, orange or white cable
If you have anything wrong in the wrong order, the bomb will explode.
There can be multiple wires with the same colour and these instructions are for one wire at a time. Once you cut a wire you can forget about the previous ones.
*/

#include <iostream>
#include <fstream>
#include <vector>

enum Wires {WHITE, RED, BLACK, ORANGE, GREEN, PURPLE};
bool diffuse(const std::vector<Wires>& wires);
Wires parse_wire(const std::string& wire);

int main(int argc, char *argv[])
{
    std::ifstream fh(argv[1]);
    std::string line;
    std::vector<Wires> wires;
    while(getline(fh, line))
        wires.push_back(parse_wire(line));
    if(diffuse(wires))
        std::cout << "Bomb defused" << std::endl;
    else
        std::cout << "Boom" << std::endl;

    return 0;
}

bool diffuse(const std::vector<Wires>& wires)
{
    for(size_t i = 0; i < wires.size() - 1; i++)
    {
        Wires current = wires[i], next = wires[i + 1];
        switch(current)
        {
            case WHITE: if(next == WHITE || next == BLACK) return false; break;
            case RED: if(next != GREEN) return false; break;
            case BLACK: if(next == GREEN || next == WHITE || next == ORANGE) return false; break;
            case ORANGE: if(next != RED || next != BLACK) return false; break;
            case GREEN: if(next != ORANGE && next != WHITE) return false; break;
            case PURPLE: if(next == PURPLE || next == GREEN || next == ORANGE || next == WHITE) return false; break;
        }
    }
    return true;
}

Wires parse_wire(const std::string& wire)
{
    if(wire == "white")
        return WHITE;
    if(wire == "red")
        return RED;
    if(wire == "black")
        return BLACK;
    if(wire == "orange")
        return ORANGE;
    if(wire == "green")
        return GREEN;
    return PURPLE;
}
