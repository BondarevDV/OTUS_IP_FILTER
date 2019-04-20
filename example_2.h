#ifndef EXAMPLE_2_H
#define EXAMPLE_2_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<filters.h>



template<typename T>
bool if_filter_1(T v)
{
    return  (atoi(v[0].c_str()) != 1);
}

template<typename T>
bool if_filter_2(T v)
{
    if ((atoi(v[0].c_str()) == 46) && (atoi(v[1].c_str()) == 70))
        return false;
    return  true;
}

template<typename T>
bool if_filter_3(T v)
{
    for (unsigned int i = 0; i < v.size(); i++) {
        if (atoi(v[i].c_str()) == 46)
            return  false;
    }
    return  true;
}




template<typename T>
T filter(T data, int if_filter)
{
    if (data.size() != 0){
        if (if_filter == 1)
        {
             auto newEnd = std::remove_if(data.begin(), data.end(), if_filter_1<decltype (data[0])>);
             data.erase(newEnd, data.end());
        }
        if (if_filter == 46)
        {
             auto newEnd = std::remove_if(data.begin(), data.end(), if_filter_3<decltype (data[0])>);
             data.erase(newEnd, data.end());
        }
        std::sort(data.begin(), data.end(), cmp<decltype (data[0])>);
    }
    return data;
}

template<typename T>
T filter(T data, int if_filter_a, int if_filter_b)
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
    // TODO reverse lexicographically sort
    if (data.size() != 0){
        if ((if_filter_a == 46) && (if_filter_b == 70))
        {
             auto newEnd = std::remove_if(data.begin(), data.end(), if_filter_2<decltype (data[0])>);
             data.erase(newEnd, data.end());
        }
        std::sort(data.begin(), data.end(), cmp<decltype (data[0])>);
    }
    return data;
}





template<typename T, typename ... Args>
T filter_test(T data, Args...args)
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
    // TODO reverse lexicographically sort
    auto t = std::make_tuple(std::forward<Args>(args)...);
    //for (unsigned int i = 0; i < sizeof...(Args); i++) {
    //    std::cout <<std::get<0>(t)<<std::endl;
    //}
    std::cout << "sizeof = "<<sizeof...(Args) <<std::endl;
    std::cout << "(" << std::get<0>(t) << ", " << std::get<1>(t)
                 << ", " << std::get<2>(t) << ")\n";
    //std::vector<T> params{{args...}};
    //if (sizeof...(Args) == 1)

    if (data.size() != 0){
//        if ((if_filter_a == 46) && (if_filter_b == 70))
//        {
//             auto newEnd = std::remove_if(data.begin(), data.end(), if_filter_2<decltype (data[0])>);
//             data.erase(newEnd, data.end());
//        }
//        std::sort(data.begin(), data.end(), cmp<decltype (data[0])>);
    }
    return data;
}









#endif // EXAMPLE_2_H
