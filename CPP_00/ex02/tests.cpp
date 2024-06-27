// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int		main( void ) 
{
	//alias
	typedef std::vector<Account::t> accounts_t; // Define accounts_t as a vector of Account::t objects
	typedef std::vector<int> ints_t; // Define ints_t as a vector of integers
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t; // Define acc_int_t as a pair of iterators: one for accounts_t and one for ints_t

	//amounts (array and size)

	int const amounts[] = { 42, 54, 957, 432, 1234, 0, 754, 16576 }; // Define a constant array of integers named amounts
	size_t const amounts_size( sizeof(amounts) / sizeof(int) ); // Calculate the size of the amounts array (number of elements)

    std::cout << "******************************** constructor ********************************"<< std::endl;
	//accounts holds info for amounts
	accounts_t accounts( amounts, amounts + amounts_size ); // Initialize accounts with elements from the amounts array
	accounts_t::iterator acc_begin = accounts.begin(); // Define an iterator to the beginning of the accounts vector
	accounts_t::iterator acc_end = accounts.end(); // Define an iterator to the end of the accounts vector

	//deposit /array of deposit, init, beginning and end
	int const d[] = { 5, 765, 564, 2, 87, 23, 9, 20 }; // Define a constant array of integers named d (deposit amounts)
	size_t const d_size( sizeof(d) / sizeof(int) ); // Calculate the size of the d array (number of elements)
	ints_t deposits( d, d + d_size ); // Initialize deposits with elements from the d array. Why is it so dificult to do?
	ints_t::iterator dep_begin = deposits.begin(); // Define an iterator to the beginning of the deposits vector
	ints_t::iterator dep_end = deposits.end(); // Define an iterator to the end of the deposits vector

	//withdrawal /array of withdrawal, init, beginning and end
	int const w[] = { 321, 34, 657, 4, 76, 275, 657, 7654 }; // Define a constant array of integers named w (withdrawal amounts)
	size_t const w_size( sizeof(w) / sizeof(int) ); // Calculate the size of the w array (number of elements)
	ints_t withdrawals( w, w + w_size ); // Initialize withdrawals with elements from the w array
	ints_t::iterator wit_begin = withdrawals.begin(); // Define an iterator to the beginning of the withdrawals vector
	ints_t::iterator wit_end = withdrawals.end(); // Define an iterator to the end of the withdrawals vector

    std::cout << "********************************    status   ********************************"<< std::endl;
	Account::displayAccountsInfos();
	//displayStatus member function to each Account object within the specified range [acc_begin, acc_end).
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	//make deposit in very complex way
    std::cout << "********************************   deposit   ********************************"<< std::endl;
	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	//make withdrawal in very complex way
    std::cout << "********************************   status    ********************************"<< std::endl;
	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

    std::cout << "********************************  withdrawal ********************************"<< std::endl;
	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

    std::cout << "********************************   status    ********************************"<< std::endl;
	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

    std::cout << "********************************  destructor ********************************"<< std::endl;
	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
