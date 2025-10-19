#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <list>

int main()
{
	std::cout << "\n" << bYELLOW << "================ test 02 ================" << RESET << std::endl;
	std::cout << "\n----------- creation mstack" << std::endl;
	MutantStack<int> mstack;
	std::cout << "\n*push 5 17 et 1755*" << std::endl;
	mstack.push(5);
	mstack.push(17);
	mstack.push(1755);

	std::cout << "\n----------- une copie (copy)" << std::endl;
	MutantStack<int> copy(mstack);
	std::cout << "\n----------- une surchargee (surcharge)" << std::endl;
	MutantStack<int> surcharge = copy;
	std::cout << "\n----------- une 4e pour reverse const it" << std::endl;
	MutantStack<int> same = copy;

	std::cout << "\n============ top des stacks" << std::endl;
	std::cout << "mstack.top() : " << mstack.top() << std::endl;
	std::cout << "copy.top() : " << copy.top() << std::endl;
	std::cout << "surcharge.top() : " << surcharge.top() << std::endl;
	std::cout << "same.top() : " << surcharge.top() << std::endl;

	std::cout << "\n*pop*" << std::endl;
	mstack.pop();

	std::cout << "\nmstack.size() : " << mstack.size() << std::endl;
	std::cout << "mstack.top() : " << mstack.top() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	copy.pop();
	copy.push(3);
	copy.push(5);
	copy.push(737);
	copy.push(0);
	surcharge.pop();
	surcharge.push(3);
	surcharge.push(5);
	surcharge.push(737);
	surcharge.push(0);
	same.pop();
	same.push(3);
	same.push(5);
	same.push(737);
	same.push(0);

	std::cout << "\n*push 3, 5, 737 et 0 en plus*" << std::endl;

	std::cout << "\n\033[0;1mSTACK INITIALE : 5 17 3 5 737 0" << RESET << std::endl;

	std::cout << "\n============ iterator" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	std::cout << "it (begin) : " << *it << std::endl;
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "ite (end) : " << *ite << std::endl;
	++it;
	--it;
	std::cout << "\n*** mstack avec +2 a chacun puisque c pas const***" << std::endl;
	while (it != ite)
	{
		*it += 2;
		std::cout << *it << ", ";
		++it;
	}

	std::cout << std::endl;

	std::cout << "\n============ const iterator" << std::endl;
	MutantStack<int>::const_iterator cit = copy.cbegin();
	std::cout << "cit (begin) : " << *cit << std::endl;
	MutantStack<int>::const_iterator cite = copy.cend();
	std::cout << "cite (end) : " << *cite << std::endl;
	++cit;
	--cit;
	std::cout << "\n*** copy_stack (decommentez pour tester si on peut les modifier, normalement non puisque const iterator)***" << std::endl;
	while (cit != cite)
	{
		//*cit += 2; 
		std::cout << *cit << ", "; 
		++cit;
	}

	std::cout << std::endl;

	std::cout << "\n============ reverse iterator" << std::endl;
	MutantStack<int>::reverse_iterator rit = copy.rbegin();
	std::cout << "rit (begin) : " << *rit << std::endl;
	MutantStack<int>::reverse_iterator rite = copy.rend();
	// std::cout << "rite (end) : " << *rite << std::endl;
	++rit;
	--rit;
	std::cout << "\n*** copy_stack reverse avec +2 a chacun puisque c pas const***" << std::endl;
	while (rit != rite)
	{
		*rit += 2;
		std::cout << *rit << ", ";
		++rit;
	}

	std::cout << std::endl;

	std::cout << "\n============ const reverse iterator" << std::endl;
	MutantStack<int>::const_reverse_iterator crit = same.rbegin();
	std::cout << "rit (begin) : " << *crit << std::endl;
	MutantStack<int>::const_reverse_iterator crite = same.rend();
	// std::cout << "rite (end) : " << *crite << std::endl;
	++crit;
	--crit;
	std::cout << "\n*** same_stack (decommentez pour tester si on peut les modifier, normalement non puisque const reverse iterator)***" << std::endl;
	while (crit != crite)
	{
		// *crit += 2;
		std::cout << *crit << ", ";
		++crit;
	}

	std::cout << std::endl;
	
	std::stack<int> s(mstack);
	return 0;
}



// //avec std::list
// int main()
// {
// 	std::cout << "\n" << bYELLOW << "========== ex02 ==========" << RESET << std::endl;
// 	// MutantStack<int> mstack;
// 	std::list<int> mstack;

// 	mstack.push_back(5);
// 	mstack.push_back(17);
// 	mstack.push_back(1755);

// 	std::cout << "mstack.back() : " << mstack.back() << std::endl;

// 	mstack.pop_back();

// 	std::cout << "mstack.size() : " << mstack.size() << std::endl;
// 	std::cout << "mstack.back() : " << mstack.back() << std::endl;

// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	//[...]
// 	mstack.push_back(0);
// 	//mstack: 5, 17, 3, 5, 737, 0
// 	std::cout << "push 3, 5, 737 et 0" << std::endl;

// 	std::list<int>::iterator it = mstack.begin();
// 	std::cout << "it (begin) : " << *it << std::endl;
// 	std::list<int>::iterator ite = mstack.end();
// 	std::cout << "ite (end) : " << *ite << std::endl;

// 	++it;
// 	--it;

// 	while (it != ite)
// 	{
// 		std::cout << "it : " << *it << ", ++it" << std::endl;
// 		++it;
// 	}
// 	return 0;
// }