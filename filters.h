#ifndef FILTERS_H
#define FILTERS_H

#include<string>
template<typename T>
bool cmp(T a, T b )
{
    for (unsigned int i = 0; i < a.size(); i++) {
        if  (atoi(a[i].c_str()) != atoi(b[i].c_str()))
            return (atoi(a[i].c_str()) > atoi(b[i].c_str()));

    }
    return false;
}



#endif // FILTERS_H
