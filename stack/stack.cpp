/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:55:42 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/10 16:10:34 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc.hpp"

#include <vector>
#include <stack>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define BLUE "\e[0;34m"
#define _RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[1;33m"
#define RESET "\e[0m"

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mOK\033[0m\n") : (std::cout << "\033[1;31mKO\033[0m\n"))
#define TIME_FAC 3 // the ft::Map methods can be slower up to std::map methods * TIME_FAC (MAX 20)

#define TEST_CASE(fn) \
	fn();             \
	using namespace std;

time_t get_time(void)
{
	struct timeval time_now;

	gettimeofday(&time_now, NULL);
	time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
	return (msecs_time);
}

void testConstructors(void)
{
	std::cout << std::setw(40) << std::left << " default constructor ";
	{
		std::vector<int> myvector(2, 200);
		ft::stack<int, std::vector<int> > s(myvector);
		EQUAL(s.size() == 2);
	}
}

void testMemberMethods(void)
{
	std::cout << std::setw(40) << std::left << " empty method ";
	{
		ft::stack<int> mystack;
		int sum(0);

		for (int i = 1; i <= 10; i++)
			mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
		EQUAL(sum == 55);
	}
	std::cout << std::setw(40) << std::left << " size method ";
	{
		bool cond(false);
		ft::stack<int> myints;
		cond = myints.size() == 0;

		for (int i = 0; i < 5; i++)
			myints.push(i);
		cond = cond && (myints.size() == 5);

		myints.pop();
		cond = cond && (myints.size() == 4);
		EQUAL(cond);
	}
	std::cout << std::setw(40) << std::left << " top method ";
	{
		ft::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;
		std::vector<int> vec(10, 50);
		vec.push_back(300);
		ft::stack<int, std::vector<int> > const c_mystack(vec);

		EQUAL(mystack.top() == 15 && c_mystack.top() == 300);
	}
	std::cout << std::setw(40) << std::left << " push & pop methods ";
	{
		int sum(0);
		ft::stack<int> mystack;

		for (int i = 0; i < 5; ++i)
			mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
		EQUAL(sum == 10);
	}
}

void testRelationalOperators(void)
{
	std::cout << std::setw(40) << std::left << " operator== ";
	{
		bool cond(false);
		std::vector<int> vec(100, 2);
		std::vector<int> vec1(100, 2);
		{
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = (mystack == mystack1) == (stack == stack1);
		}
		{
			vec.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack == mystack1) == (stack == stack1);
		}
		{
			vec.pop_back();
			vec1.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack == mystack1) == (stack == stack1);
		}
		EQUAL(cond);
	}
	std::cout << std::setw(40) << std::left << " operator!= ";
	{
		bool cond(false);
		std::vector<int> vec(100, 2);
		std::vector<int> vec1(100, 2);
		{
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = (mystack != mystack1) == (stack != stack1);
		}
		{
			vec.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack != mystack1) == (stack != stack1);
		}
		{
			vec.pop_back();
			vec1.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack != mystack1) == (stack != stack1);
		}
		EQUAL(cond);
	}
	std::cout << std::setw(40) << std::left << " operator< ";
	{
		bool cond(false);
		std::vector<int> vec(100, 2);
		std::vector<int> vec1(100, 2);
		{
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = (mystack < mystack1) == (stack < stack1);
		}
		{
			vec.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack < mystack1) == (stack < stack1);
		}
		{
			vec.pop_back();
			vec1.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack < mystack1) == (stack < stack1);
		}
		EQUAL(cond);
	}
	std::cout << std::setw(40) << std::left << " operator<= ";
	{
		bool cond(false);
		std::vector<int> vec(100, 2);
		std::vector<int> vec1(100, 2);
		{
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = (mystack <= mystack1) == (stack <= stack1);
		}
		{
			vec.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack <= mystack1) == (stack <= stack1);
		}
		{
			vec.pop_back();
			vec1.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack <= mystack1) == (stack <= stack1);
		}
		EQUAL(cond);
	}
	std::cout << std::setw(40) << std::left << " operator> ";
	{
		bool cond(false);
		std::vector<int> vec(100, 2);
		std::vector<int> vec1(100, 2);
		{
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = (mystack > mystack1) == (stack > stack1);
		}
		{
			vec.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack > mystack1) == (stack > stack1);
		}
		{
			vec.pop_back();
			vec1.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack > mystack1) == (stack > stack1);
		}
		EQUAL(cond);
	}
	std::cout << std::setw(40) << std::left << " operator>= ";
	{
		bool cond(false);
		std::vector<int> vec(100, 2);
		std::vector<int> vec1(100, 2);
		{
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = (mystack >= mystack1) == (stack >= stack1);
		}
		{
			vec.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack >= mystack1) == (stack >= stack1);
		}
		{
			vec.pop_back();
			vec1.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack >= mystack1) == (stack >= stack1);
		}
		EQUAL(cond);
	}
}

void alarm_handler(int seg)
{
	(void)seg;
	std::cout << "\033[1;33mTLE\033[0m\n";
	kill(getpid(), SIGINT);
}

int main()
{
	std::cout << _RED << "________________________________________________________________________________________________________" << std::endl;
	std::cout << _RED << "**** The test is taking so much time to test the all cases and the time complexity of each method ****" << std::endl;
	std::cout << _RED << "--------------------------------------------------------------------------------------------------------" << RESET << std::endl;
	signal(SIGALRM, alarm_handler);

	TEST_CASE(testConstructors);
	TEST_CASE(testMemberMethods);
	TEST_CASE(testRelationalOperators);

	return 0;
}
