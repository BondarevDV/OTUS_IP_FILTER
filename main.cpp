#include<filters.h>
#include<tools.h>
#include<example_1.h>



int main()
{
    try
    {

        std::vector<std::vector<std::string>> ip_pool;
        ip_pool = read_data_fr_stream<std::vector<std::string>, decltype (ip_pool)>();

        pred_adapter_1<decltype(ip_pool[0])> pred_func_1(0, 1);
        auto  data_fltr0 = filter_copy(ip_pool, pred_func_1);
        print_ip_pool(data_fltr0);


        pred_adapter_2<decltype(ip_pool[0])> pred_func_2(0, 1, 46, 70);
        auto  data_fltr1 = filter_copy(ip_pool, pred_func_2);
        print_ip_pool(data_fltr1);

        pred_adapter_3<decltype(ip_pool[0])> pred_func_3(46);
        auto  data_fltr2 = filter_copy(ip_pool, pred_func_3);
        print_ip_pool(data_fltr2);



    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
