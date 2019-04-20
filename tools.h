#ifndef TOOLS_H
#define TOOLS_H
#include <iostream>
#include <string>
#include <vector>





template<typename T>
void print_ip_pool(T ip_pool)
{
    for(std::vector<std::vector<std::string> >::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
        {
            for(std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
            {
                if (ip_part != ip->cbegin())
                {
                    std::cout << ".";
                }
                std::cout << *ip_part;
            }
            std::cout<<std::endl;
        }
}

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]

// Проверить на разных структурах

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }
    r.push_back(str.substr(start));

    return r;
}

template <typename T_data, typename T_out>
T_out read_data_fr_stream()
{
    T_out data;
    for(std::string line; std::getline(std::cin, line);)
    {
        T_data v = split(line, '\t');
        data.push_back(split(v.at(0), '.'));
    }

    return data;
}

#endif // TOOLS_H
