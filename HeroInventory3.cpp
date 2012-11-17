/*
 * HeroInventory3.cpp
 *
 *  Created on: Nov 17, 2012
 *      Author: Brian
 *  Demonstrates Iterators
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	vector<string>::iterator myIterator;
	vector<string>::const_iterator iter;

	cout << "Your items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << "\nYou trade your sword for a battle axe.";
	myIterator = inventory.begin();
	*myIterator = "battle axe";
	cout << "\nYour items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << "\nThe item name '" << *myIterator << "' has ";
	cout << (*myIterator).size() << " letters in it.\n";

	cout << "\nThe item name '" << *myIterator << "' has ";
	cout << myIterator->size() << " letters in it.\n";

	cout << "\nYou recover a crossbow from a slain enemy.";
	inventory.insert(inventory.begin(), "crossbow");
	cout << "Your items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << "\nYour armor is destroyed in a fierce battle.";
	inventory.erase((inventory.begin() + 2));
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		cout << *iter << endl;
	}

	cin.get();
	return 0;
}
