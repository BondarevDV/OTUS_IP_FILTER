#ifndef EXAMPLE_1_H
#define EXAMPLE_1_H

#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<filters.h>


template<typename T>
bool if_filter_1(T v, int num_order, int border_cond)
{
    return  (atoi(v[num_order].c_str()) == border_cond);
}


template<typename T>
bool if_filter_2(T v, int index_a, int index_b, int value_a, int value_b)
{
    if ((atoi(v[index_a].c_str()) == value_a) && (atoi(v[index_b].c_str()) == value_b))
        return true;
    return  false;
}


template<typename T>
bool if_filter_3(T v, int border_cond_xor)
{
    for (unsigned int i = 0; i < v.size(); i++) {
        if (atoi(v[i].c_str()) == border_cond_xor)
            return  true;
    }
    return  false;
}





template<typename T>
class pred_adapter_1
{
   int num_order;
   int border_cond;

public:
   pred_adapter_1(int in_num_order,
                int in_border_cond): num_order(in_num_order),
                                     border_cond(in_border_cond){}
   bool operator()(T a)
   const {
       return if_filter_1(a, num_order, border_cond);
   }


};


template<typename T>
class pred_adapter_2
{
   int index_a;
   int index_b;
   int value_a;
   int value_b;
public:
   pred_adapter_2(int in_index_a,
                int in_index_b,
                int in_value_a,
                int in_value_b): index_a(in_index_a),
                                       index_b(in_index_b),
                                       value_a(in_value_a),
                                       value_b(in_value_b){}
   bool operator()(T a)
   const {
       return if_filter_2(a, index_a, index_b, value_a, value_b );
   }

};



template<typename T>
class pred_adapter_3
{
   int border_cond_xor;

public:
   pred_adapter_3(int in_num_order_xor): border_cond_xor(in_num_order_xor){}
   bool operator()(T a)
   const {
       return if_filter_3(a, border_cond_xor );
   }

};





template<typename T>
T filter_remove(T data, int ip_filter)
{

    pred_adapter_1<std::vector<std::string>> pred_func(0, ip_filter);
    auto newEnd = std::remove_if(data.begin(), data.end(),  pred_func);
    data.erase(newEnd, data.end());
    std::sort(data.begin(), data.end(), cmp<std::vector<std::string>>);
    return data;
}



template<typename T, typename T_pred>
T filter_copy(T data, T_pred func)
{
    T buff(data.size());
    auto newEnd = std::copy_if(data.begin(), data.end(), buff.begin(), func);
    buff.erase(newEnd, buff.end());
    std::sort(buff.begin(), buff.end(), cmp<decltype(data[0])>);
    return buff;
}


#endif // EXAMPLE_1_H
