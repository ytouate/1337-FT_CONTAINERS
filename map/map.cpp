/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:07:07 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/09 16:13:10 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc.hpp"
#include <map>

#include <vector>
#include <iostream>
#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <random>
#include <chrono>
namespace Color
{
    enum Code
    {
        FG_RED = 31,
        FG_GREEN = 32,
        FG_BLUE = 36,
        FG_YELLOW = 33,
        FG_DEFAULT = 39,
    };
    class Modifier
    {
        Code code;

    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream &
        operator<<(std::ostream &os, const Modifier &mod)
        {
            return os << "\033[" << mod.code << "m";
        }
    };
}

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

void print_time(time_t start, time_t end)
{
    Color::Modifier yellow(Color::FG_YELLOW); // right answer
    Color::Modifier def(Color::FG_DEFAULT);
    time_t res = end - start;
    std::cout << std::setw(5) << "\t" << yellow << res << "msecs " << def;
}

int start(void)
{
    Color::Modifier green(Color::FG_GREEN);
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier yellow(Color::FG_YELLOW); // right answer
    Color::Modifier red(Color::FG_RED);       // false answer
    Color::Modifier def(Color::FG_DEFAULT);
    {
        try
        {
            std::cout << blue << "-----------------------------------------------------------" << def << std::endl;
            std::cout << blue << "------------------------ Map Tests ------------------------" << def << std::endl;
            std::cout << std::left << std::setw(15) << std::left << "\nDefault Constructor 			";
            {
                std::map<char, int> m;
                ft::map<char, int> ft_m;

                //! try to insert elem
                m['a'] = 10;
                m['b'] = 30;
                m['c'] = 50;
                m['d'] = 70;

                ft_m['a'] = 10;
                ft_m['b'] = 30;
                ft_m['c'] = 50;
                ft_m['d'] = 70;

                size_t size, ft_size;
                size = m.size();
                ft_size = ft_m.size();

                if ((size == ft_size) && (m['b'] == ft_m['b']))
                    std::cout << "\t\t" << green << "OK" << def << std::endl;
                else
                    std::cout << "\t\t" << red << "KO" << def << std::endl;
            }

            std::cout << std::left << std::setw(15) << std::left << "Range Constructor 			";
            {
                //! fill a map
                std::map<int, std::string> sm;
                ft::map<int, std::string> my_m;

                for (size_t i = 0; i < 1e4; i++)
                {
                    sm.insert(std::make_pair(i, "range"));
                    my_m.insert(ft::make_pair(i, "ft range"));
                }

                std::map<int, std::string> m(sm.begin(), sm.end());
                ft::map<int, std::string> ft_m(my_m.begin(), my_m.end());

                std::map<int, int>::iterator it, it_end;
                ft::map<int, int>::iterator ft_it, ft_it_end;

                size_t size, ft_size;
                size = m.size();
                ft_size = ft_m.size();
                if ((size == ft_size) && (m.begin()->first == ft_m.begin()->first))
                    std::cout << "\t\t" << green << "OK" << def << std::endl;
                else
                    std::cout << "\t\t" << red << "KO" << def << std::endl;
            }

            std::cout << std::left << std::setw(15) << std::left << "Assignement  Operator=			";
            {
                //! fill a map
                std::map<int, std::string> sm;
                ft::map<int, std::string> my_m;
                std::map<int, std::string> m;
                ft::map<int, std::string> ft_m;

                for (size_t i = 0; i < 1e4; i++)
                {
                    sm.insert(std::make_pair(i, "std"));
                    my_m.insert(ft::make_pair(i, "ft"));
                }
                m = sm;
                ft_m = my_m;
                std::map<int, int>::iterator it, it_end;
                ft::map<int, int>::iterator ft_it, ft_it_end;
                if ((m.size() == ft_m.size()) && (m.begin()->first == ft_m.begin()->first))
                    std::cout << "\t\t" << green << "OK" << def << std::endl;
                else
                    std::cout << "\t\t" << red << "KO" << def << std::endl;
            }

            std::cout << std::left << std::setw(15) << std::left << "Copy Constructor 			";
            {
                //! fill a map
                std::map<int, std::string> sm;
                ft::map<int, std::string> my_m;

                for (size_t i = 0; i < 1e4; i++)
                {
                    sm.insert(std::make_pair(i, "v"));
                    my_m.insert(ft::make_pair(i, "v"));
                }
                std::map<int, std::string> m(sm.begin(), sm.end());
                ft::map<int, std::string> ft_m(my_m.begin(), my_m.end());

                std::map<int, int>::iterator it, it_end;
                ft::map<int, int>::iterator ft_it, ft_it_end;

                size_t size, ft_size;
                size = m.size();
                ft_size = ft_m.size();
                if ((size == ft_size) && (m.begin()->first == ft_m.begin()->first))
                    std::cout << "\t\t" << green << "OK" << def << std::endl;
                else
                    std::cout << "\t\t" << red << "KO" << def << std::endl;
            }

            std::cout << std::left << std::setw(15) << std::left << "Clear  Method 			";
            {
                std::map<int, char> m;
                ft::map<int, char> ft_m;

                m.clear();
                ft_m.clear();
                for (size_t i = 0; i < 14; i++)
                {
                    m.insert(std::make_pair(i, 'Z'));
                    ft_m.insert(ft::make_pair(i, 'Z'));
                }
                m.clear();
                ft_m.clear();
                if ((m.size() == ft_m.size()) && (m.empty() == ft_m.empty()))
                    std::cout << "\t\t\t" << green << "OK" << def << std::endl;
                else
                    std::cout << "\t\t\t" << red << "KO" << def << std::endl;
            }

            std::cout << std::left << std::setw(15) << std::left << "Empty  Method			";
            {
                std::map<int, char> m;
                ft::map<int, char> ft_m;

                bool ret = m.empty();
                bool ft_ret = ft_m.empty();
                for (size_t i = 0; i < 14; i++)
                {
                    m.insert(std::make_pair(i, 'Z'));
                    ft_m.insert(ft::make_pair(i, 'Z'));
                }
                if ((ret == ft_ret) && (m.empty() == ft_m.empty()))
                    std::cout << "\t\t\t" << green << "OK" << def << std::endl;
                else
                    std::cout << "\t\t\t" << red << "KO" << def << std::endl;
            }

            std::cout << std::left << std::setw(15) << std::left << "Find  Method 			";
            {
                std::map<int, char> m;
                ft::map<int, char> ft_m;

                for (size_t i = 0; i < 1e4; i++)
                {
                    m.insert(std::make_pair(i, 'Z'));
                    ft_m.insert(ft::make_pair(i, 'Z'));
                }
                m[1000] = 'P';
                ft_m[1000] = 'P';
                std::map<int, char>::iterator it, p_it;
                ft::map<int, char>::iterator ft_it, ft_p_it;
                it = m.find('P'); //! ASCII 80
                ft_it = ft_m.find('P');
                p_it = m.find(1000);
                ft_p_it = ft_m.find(1000);
                if ((m.size() == ft_m.size()) && (it->second == ft_it->second))
                    std::cout << "\t\t\t" << green << "OK" << def << std::endl;
                else
                    std::cout << "\t\t\t" << red << "KO" << def << std::endl;
            }

            std::cout << std::left << std::setw(15) << std::left << "Get_allocator  Method 		";
            {
                int psize, ft_psize;
                std::map<char, int> mymap;
                ft::map<char, int> ftmap;
                std::pair<const char, int> *p;
                ft::pair<const char, int> *ft_p;

                p = mymap.get_allocator().allocate(5);
                ft_p = ftmap.get_allocator().allocate(5);

                psize = sizeof(std::map<char, int>::value_type) * 5;
                ft_psize = sizeof(ft::map<char, int>::value_type) * 5;
                if (psize == ft_psize)
                    std::cout << "\t\t\t" << green << "OK" << def << std::endl;
                else
                    std::cout << "\t\t\t" << red << "KO" << def << std::endl;
                mymap.get_allocator().deallocate(p, 1);
                ftmap.get_allocator().deallocate(ft_p, 1);
            }

            std::cout << std::left << std::setw(15) << std::left << "Insert  Method 			";
            {
                std::map<int, int> m;
                ft::map<int, int> ft_m;

                for (int i = 0; i < 5; i++)
                {
                    m.insert(std::make_pair(i, i));
                    ft_m.insert(ft::make_pair(i, i));
                }
                std::map<int, int>::iterator it, it_end;
                ft::map<int, int>::iterator ft_it, ft_it_end;

                it = m.begin();
                it_end = m.end();
                ft_it = ft_m.begin();
                ft_it_end = ft_m.end();
                --it_end;
                --ft_it_end;
                if ((it->first == ft_it->first) && (it_end->first == ft_it_end->first) && (m.size() == ft_m.size()))
                    std::cout << "\t\t\t" << green << "OK" << def << std::endl;
                else
                    std::cout << "\t\t\t" << red << "KO" << def << std::endl;
            }

            std::cout << std::left << std::setw(15) << std::left << "Access  Operator[] 		";
            {
                std::map<char, std::string> m;
                ft::map<char, std::string> ft_m;

                m['a'] = "an element";
                m['b'] = "another element";
                m['c'] = m['b'];

                ft_m['a'] = "an element";
                ft_m['b'] = "another element";
                ft_m['c'] = ft_m['b'];
                if ((m.size() == ft_m.size()) && (ft_m['a'] == m['a']) && (ft_m['c'] == m['c']))
                    std::cout << "\t\t\t" << green << "OK" << def << std::endl;
                else
                    std::cout << "\t\t\t" << red << "KO" << def << std::endl;
            }
            std::cout << std::left << std::setw(15) << std::left << "Upper Lower Bound Methods	";
            {
                std::map<char, int> mymap;
                std::map<char, int>::iterator itlow, itup;

                mymap['a'] = 20;
                mymap['b'] = 40;
                mymap['c'] = 60;
                mymap['d'] = 80;
                mymap['e'] = 100;

                itlow = mymap.lower_bound('b'); // itlow points to b
                itup = mymap.upper_bound('d');
                ft::map<char, int> ftmap;
                ft::map<char, int>::iterator ft_itlow, ft_itup;

                ftmap['a'] = 20;
                ftmap['b'] = 40;
                ftmap['c'] = 60;
                ftmap['d'] = 80;
                ftmap['e'] = 100;

                ft_itlow = ftmap.lower_bound('b'); // itlow points to b
                ft_itup = ftmap.upper_bound('d');
                if (mymap.size() == ftmap.size() && (ft_itlow->second == itlow->second) && (itup->second == ft_itup->second))
                    std::cout << "\t\t\t" << green << "OK" << def << std::endl;
                else
                    std::cout << "\t\t\t" << red << "KO" << def << std::endl;
            }
            std::cout << std::left << std::setw(35) << std::left << "Compare Const Iterator & Iterator ";
            {
                ft::map<char, int> ft_v;

                ft::map<char, int>::iterator ft_it, ft_it1;
                ft::map<char, int>::const_iterator ft_cit, ft_cit1;

                ft_v['a'] = 20;
                ft_v['b'] = 40;
                ft_v['c'] = 60;
                ft_v['d'] = 80;
                ft_v['e'] = 100;

                ft_it = ft_v.begin();
                ft_cit = ft_v.begin();

                ft_it1 = ft_v.begin();
                ft_cit1 = ft_v.begin()++;
                ft_it1++;
                ft_cit1++;
                if ((ft_it == ft_cit) && (ft_it1 != ft_cit))
                    std::cout << "\t\t\t" << green << "OK" << def << std::endl;
                else
                    std::cout << "\t\t\t" << red << "KO" << def << std::endl;
            }
        }
        catch (std::exception &e)
        {
            std::cout << "Exception Occured" << std::endl;
        }
    }
    return EXIT_SUCCESS;
}

int main()
{
    start();
    system("leaks map.out");
    return 0;
}