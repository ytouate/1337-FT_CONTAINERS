/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:51:20 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/10 16:08:47 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  Includes

#include <vector>
#include <iostream>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include "../inc.hpp"

// Colors

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

void vector_tests(void)
{
	Color::Modifier green(Color::FG_GREEN);
	Color::Modifier blue(Color::FG_BLUE);
	Color::Modifier yellow(Color::FG_YELLOW); // right answer
	Color::Modifier red(Color::FG_RED);		  // false answer
	Color::Modifier def(Color::FG_DEFAULT);
	try
	{
		// ! timeLimitTest
		std::cout << std::left << std::setw(15) << std::left << "\nFill Constructor ";
		time_t start, end, diff;
		start = get_time();
		std::vector<int> v(1e7, 10);
		end = get_time();
		print_time(start, end);
		diff = (end - start) + 1;
		start = get_time();
		ft::vector<int> ft_v(1e7, 10);
		end = get_time();
		print_time(start, end);

		std::string res, ft_res;
		size_t c, ft_c, s, ft_s;

		std::vector<std::string> v1(10, "f");
		ft::vector<std::string> ft_v1(10, "f");

		c = v1.capacity();
		ft_c = ft_v1.capacity();
		s = v1.size();
		ft_s = ft_v1.size();
		for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it)
			res += *it;

		for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
			ft_res += *it;
		if ((end - start) > (diff * 20))
			std::cout << "\t\t" << blue << "TL" << def << std::endl;
		else if ((res == ft_res) && (s == ft_s) && (c == ft_c))
			std::cout << "\t\t" << green << "OK" << def << std::endl;
		else
			std::cout << "\t\t" << red << "KO" << def << std::endl;

		std::cout << std::left << std::setw(15) << std::left << "Range Constructor ";
		{
			// ! timeLimitTest
			time_t start, end, diff;
			std::vector<int> input(1e6, 10);
			start = get_time();
			std::vector<int> v(input.begin(), input.end());
			end = get_time();
			print_time(start, end);
			diff = (end - start) + 1;
			ft::vector<int> ft_input(1e6, 10);
			start = get_time();
			ft::vector<int> ft_v(ft_input.begin(), ft_input.end());
			end = get_time();
			print_time(start, end);

			std::string res, ft_res;
			size_t c, ft_c, s, ft_s;

			std::vector<std::string> v2(10, "range");
			std::vector<std::string> v1(v2.begin(), v2.end());
			ft::vector<std::string> ft_v2(10, "range");
			ft::vector<std::string> ft_v1(ft_v2.begin(), ft_v2.end());

			c = v1.capacity();
			ft_c = ft_v1.capacity();
			s = v1.size();
			ft_s = ft_v1.size();
			for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it)
				res += *it;

			for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
				ft_res += *it;
			if ((end - start) > (diff * 20))
				std::cout << "\t\t" << blue << "TL" << def << std::endl;
			if ((res == ft_res) && (s == ft_s) && (c == ft_c))
				std::cout << "\t\t" << green << "OK" << def << std::endl;
			else
				std::cout << "\t\t" << red << "KO" << def << std::endl;
		}
		std::cout << std::left << std::setw(15) << std::left << "Copy Constructor";
		{
			// ! timeLimitTest
			time_t start, end, diff;
			std::vector<int> copy(1e6, 10);
			start = get_time();
			std::vector<int> v(copy);
			end = get_time();
			print_time(start, end);
			diff = (end - start) + 1;
			ft::vector<int> ft_copy(1e6, 10);
			start = get_time();
			ft::vector<int> ft_v(ft_copy);
			end = get_time();
			print_time(start, end);

			std::string res, ft_res;
			size_t c, ft_c, s, ft_s;

			std::vector<std::string> v2(10, "range");
			std::vector<std::string> v1(v2);
			ft::vector<std::string> ft_v2(10, "range");
			ft::vector<std::string> ft_v1(ft_v2);

			c = v1.capacity();
			ft_c = ft_v1.capacity();
			s = v1.size();
			ft_s = ft_v1.size();
			for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it)
				res += *it;

			for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
				ft_res += *it;
			if ((end - start) > (diff * 20))
				std::cout << "\t\t" << blue << "TL" << def << std::endl;
			else if ((res == ft_res) && (s == ft_s) && (c == ft_c))
				std::cout << "\t\t" << green << "OK" << def << std::endl;
			else
				std::cout << "\t\t" << red << "KO" << def << std::endl;
		}
		std::cout << std::left << std::setw(15) << std::left << "Assignement Operator";
		{
			time_t start, end, diff;
			std::vector<int> copy(1e6, 10);
			std::vector<int> v;
			start = get_time();
			v = copy;
			end = get_time();
			print_time(start, end);
			diff = (end - start) + 1;
			ft::vector<int> ft_copy(1e6, 10);
			start = get_time();
			ft::vector<int> ft_v;
			ft_v = ft_copy;
			end = get_time();
			print_time(start, end);

			std::string res, ft_res;
			size_t c, ft_c, s, ft_s;

			std::vector<std::string> v2(10, "range");
			std::vector<std::string> v1;
			v1 = v2;
			ft::vector<std::string> ft_v1;
			ft::vector<std::string> ft_v2(10, "range");
			ft_v1 = ft_v2;

			c = v1.capacity();
			ft_c = ft_v1.capacity();
			s = v1.size();
			ft_s = ft_v1.size();
			for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it)
				res += *it;

			for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
				ft_res += *it;
			if ((end - start) > (diff * 20))
				std::cout << "\t\t" << blue << "TL" << def << std::endl;
			else if ((res == ft_res) && (s == ft_s) && (c == ft_c))
				std::cout << "\t\t" << green << "OK" << def << std::endl;
			else
				std::cout << "\t\t" << red << "KO" << def << std::endl;
		}
		std::cout << std::left << std::setw(35) << std::left << "Begin End method";
		{
			std::vector<std::string> v1(10, "f");
			ft::vector<std::string> ft_v1(10, "f");
			std::vector<std::string>::iterator it1 = v1.begin();
			std::vector<std::string>::iterator it1_end = v1.end();
			ft::vector<std::string>::iterator ft_it1 = ft_v1.begin();
			ft::vector<std::string>::iterator ft_it1_end = ft_v1.end();

			std::vector<std::string> v; //! empty vector
			ft::vector<std::string> ft_v;
			std::vector<std::string>::iterator it = v1.begin();
			ft::vector<std::string>::iterator ft_it = ft_v1.begin();
			if ((*it == *ft_it) && (*it1 == *ft_it1) && (*--it1_end == *--ft_it1_end))
				std::cout << "\t\t\t\t" << green << "OK" << def << std::endl;
			else
				std::cout << "\t\t\t\t" << red << "KO" << def << std::endl;
		}
		std::cout << std::left << std::setw(35) << std::left << "Rbegin Rend method";
		{
			std::vector<std::string> v1(10, "f");
			ft::vector<std::string> ft_v1(10, "f");
			std::vector<std::string>::reverse_iterator it1 = v1.rbegin();
			std::vector<std::string>::const_reverse_iterator it1_end = v1.rend(); //! const
			ft::vector<std::string>::reverse_iterator ft_it1 = ft_v1.rbegin();
			ft::vector<std::string>::const_reverse_iterator ft_it1_end = ft_v1.rend();

			std::vector<std::string> v(5, "end");
			ft::vector<std::string> ft_v(5, "end");
			std::vector<std::string>::reverse_iterator it = v1.rbegin();
			ft::vector<std::string>::reverse_iterator ft_it = ft_v1.rbegin();
			if ((*it == *ft_it) && (*it1 == *ft_it1) && (*--it1_end == *--ft_it1_end))
				std::cout << "\t\t\t\t" << green << "OK" << def << std::endl;
			else
				std::cout << "\t\t\t\t" << red << "KO" << def << std::endl;
		}
		std::cout << std::left << std::setw(35) << std::left << "Size Capacity method";
		{
			std::vector<std::string> v1(10, "f");
			ft::vector<std::string> ft_v1(10, "f");

			v1.reserve(100);
			ft_v1.reserve(100);

			std::vector<std::string> v(1e6, "f");
			ft::vector<std::string> ft_v(1e6, "f");
			if ((v1.size() == ft_v1.size()) && (v1.capacity() == ft_v1.capacity()) && (v.size() == ft_v.size()) && (v.capacity() == ft_v.capacity()))
				std::cout << "\t\t\t\t" << green << "OK" << def << std::endl;
			else
				std::cout << "\t\t\t\t" << red << "KO" << def << std::endl;
		}
		std::cout << std::left << std::setw(40) << std::left << "Max_size get_alloc method";
		{
			std::vector<std::string> v(15, "f");
			ft::vector<std::string> ft_v(15, "f");

			if (v.max_size() == ft_v.max_size() && (v.get_allocator() == ft_v.get_allocator()))
				std::cout << "\t\t\t" << green << "OK" << def << std::endl;
			else
				std::cout << "\t\t\t" << red << "KO" << def << std::endl;
		}
		std::cout << std::left << std::setw(35) << std::left << "Swap Clear method";
		{
			size_t s, ft_s, c, ft_c;
			std::vector<std::string> v(15, "f");
			ft::vector<std::string> ft_v(15, "f");

			std::vector<std::string> v1;
			ft::vector<std::string> ft_v1;

			v.swap(v1);
			ft_v.swap(ft_v1);

			s = v.size();
			ft_s = ft_v.size();
			c = v.capacity();
			ft_c = ft_v.capacity();

			v.clear();
			ft_v.clear();
			if ((s == ft_s) && (c == ft_c) && (v.size() == ft_v.size()) && (v.capacity() == ft_v.capacity()))
				std::cout << "\t\t\t\t" << green << "OK" << def << std::endl;
			else
				std::cout << "\t\t\t\t" << red << "KO" << def << std::endl;
		}
		std::cout << std::left << std::setw(35) << std::left << "Assign method";
		{
			size_t s, ft_s, c, ft_c;
			std::vector<std::string> v(10, "a");
			ft::vector<std::string> ft_v(10, "a");

			std::vector<std::string> v1(15, "f");
			ft::vector<std::string> ft_v1(15, "f");

			v.assign(v1.begin() + 2, v1.end());
			ft_v.assign(ft_v1.begin() + 2, ft_v1.end());

			s = v.size();
			ft_s = ft_v.size();
			c = v.capacity();
			ft_c = ft_v.capacity();
			if ((s == ft_s) && (c == ft_c) && (v.size() == ft_v.size()) && (v.capacity() == ft_v.capacity()))
				std::cout << "\t\t\t\t" << green << "OK" << def << std::endl;
			else
				std::cout << "\t\t\t\t" << red << "KO" << def << std::endl;
		}
		std::cout << std::left << std::setw(35) << std::left << "Resize method";
		{
			size_t s, ft_s, c, ft_c;
			std::vector<std::string> v(106, "a");
			ft::vector<std::string> ft_v(106, "a");

			v.resize(53);
			ft_v.resize(53);

			s = v.size();
			ft_s = ft_v.size();
			c = v.capacity();
			ft_c = ft_v.capacity();
			if ((s == ft_s) && (c == ft_c) && (v.size() == ft_v.size()) && (v.capacity() == ft_v.capacity()))
				std::cout << "\t\t\t\t" << green << "OK" << def << std::endl;
			else
				std::cout << "\t\t\t\t" << red << "KO" << def << std::endl;
		}
		std::cout << std::left << std::setw(35) << std::left << "Erase method";
		{
			size_t s, ft_s, c, ft_c;
			std::vector<std::string> v(106, "a");
			ft::vector<std::string> ft_v(106, "a");

			std::vector<std::string>::iterator it = v.erase(v.begin());
			ft::vector<std::string>::iterator ft_it = ft_v.erase(ft_v.begin());
			std::vector<std::string>::iterator r_it = v.erase(v.begin() + 5, v.end());
			ft::vector<std::string>::iterator r_ft_it = ft_v.erase(ft_v.begin() + 5, ft_v.end());

			s = v.size();
			ft_s = ft_v.size();
			c = v.capacity();
			ft_c = ft_v.capacity();

			if ((s == ft_s) && (c == ft_c) && (*it == *ft_it) && (*r_it == *r_ft_it))
				std::cout << "\t\t\t\t" << green << "OK" << def << std::endl;
			else
				std::cout << "\t\t\t\t" << red << "KO" << def << std::endl;
		}
		std::cout << std::left << std::setw(35) << std::left << "Insert method";
		{
			size_t s, ft_s, c, ft_c;
			std::vector<std::string> v(106, "a");
			ft::vector<std::string> ft_v(106, "a");
			std::vector<std::string> v1(106, "a");
			ft::vector<std::string> ft_v1(106, "a");

			std::vector<std::string>::iterator it;
			ft::vector<std::string>::iterator ft_it;

			v.insert(v.begin(), v1.begin(), v1.end());
			ft_v.insert(ft_v.begin(), ft_v1.begin(), ft_v1.end());

			s = v.size();
			ft_s = ft_v.size();
			c = v.capacity();
			ft_c = ft_v.capacity();

			v.insert(v.begin(), "f");
			ft_v.insert(ft_v.begin(), "f");

			it = v.begin();
			ft_it = ft_v.begin();

			if ((s == ft_s) && (c == ft_c) && (*it == *ft_it))
				std::cout << "\t\t\t\t" << green << "OK" << def << std::endl;
			else
				std::cout << "\t\t\t\t" << red << "KO" << def << std::endl;
		}
		std::cout << std::left << std::setw(35) << std::left << "Reserve method";
		{
			size_t s, ft_s, c, ft_c;
			std::vector<std::string> v(106, "a");
			ft::vector<std::string> ft_v(106, "a");

			v.reserve(1000);
			ft_v.reserve(1000);
			s = v.size();
			ft_s = ft_v.size();
			c = v.capacity();
			ft_c = ft_v.capacity();
			if ((s == ft_s) && (c == ft_c))
				std::cout << "\t\t\t\t" << green << "OK" << def << std::endl;
			else
				std::cout << "\t\t\t\t" << red << "KO" << def << std::endl;
		}
		std::cout << std::left << std::setw(35) << std::left << "Compare Const Iterator & Iterator ";
		{
			ft::vector<int> ft_v(106, 8);

			ft::vector<int>::iterator ft_it, ft_it1;
			ft::vector<int>::const_iterator ft_cit, ft_cit1;

			ft_it = ft_v.begin();
			ft_cit = ft_v.begin();

			ft_it1 = ft_v.begin() + 5;
			ft_cit1 = ft_v.begin() + 5;

			if ((ft_it == ft_cit) && (ft_it < ft_cit1) && (ft_it1 != ft_cit))
				std::cout << "\t\t\t\t" << green << "OK" << def << std::endl;
			else
				std::cout << "\t\t\t\t" << red << "KO" << def << std::endl;
		}
	}
	catch (std::exception &e)
	{
	}
}

int main()
{

	Color::Modifier green(Color::FG_GREEN);
	Color::Modifier blue(Color::FG_BLUE);
	Color::Modifier def(Color::FG_DEFAULT);

	std::cout << blue << "-----------------------------------------------------------" << def << std::endl;
	std::cout << blue << "---------------------- vector Tests -----------------------" << def << std::endl;
	std::cout << blue << "-----------------------------------------------------------" << def << std::endl;
	vector_tests();
	// system("leaks vector.out");
	return EXIT_SUCCESS;
}

//! explicit