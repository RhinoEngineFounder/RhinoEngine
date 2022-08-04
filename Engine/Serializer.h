#pragma once

#include <fstream>

template<typename t>
void serialize(std::string file, std::string name, t value)
{
    std::ofstream outfile(file);
    outfile << name << ' ' << value << std::endl;
    outfile.close();
}

template<typename t>
t GetValue(std::string file, std::string name)
{
    std::ifstream infile(file); // the file
    std::string line; // the whole line 
    std::string currentVar; // The name of the current variable

    while(getline(infile, line)) // Read each of the lines of the file
    {
        currentVar = line.substr(0, line.find(' ')); // The variable we're currently reading
        if(currentVar == name) // If the variable we're reading is the one we're searching for
        {
            return atof(line.substr(1, line.find(' ')).c_str()); // Cast it's value to the type you wish, and return!
        }
    }

    return 0;
}