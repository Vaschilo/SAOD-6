#pragma once
#include "Team.h"

class Node
{
private:
	Team data;
public:
	Node* left;
	Node* rigth;
	Node() { this->left = nullptr; this->rigth = nullptr; }
	Node(Team data) { this->left = nullptr; this->rigth = nullptr; this->data = data; }
	~Node() {}

	Team GetData() { return this->data; }
	void SetData(Team a) { this->data = a; }

	int sum() 
	{ 
		int sum = this->data.GetPower();
		if (this->left != nullptr) sum += this->left->sum();
		if (this->rigth != nullptr) sum += this->rigth->sum();
		return sum;
	}

	void print(int a)
	{
		for (int i = 0; i < a; i++) cout << "  ";
		cout << data << endl;
		if (this->left != nullptr)this->left->print(a + 1);
		if (this->rigth != nullptr)this->rigth->print(a + 1);
	}

	void tournament_print(int a, int limit)
	{
		if (a <= limit) 
		{
			for (int i = 0; i < a; i++) cout << "  ";
			cout << data << endl;
			if (this->left != nullptr)this->left->tournament_print(a + 1, limit);
			if (this->rigth != nullptr)this->rigth->tournament_print(a + 1, limit);
			cout << endl;
		}
	}
};

class Tree
{
private:
	Node* root;
	int size;

	void funk(int i, Node* current, int this_num, Team data)
	{
		int buff = i;
		while (!(i == this_num * 2 || i == this_num * 2 + 1))
		{
			i /= 2;
		}
		if (i == this_num * 2)
		{
			if (current->left == nullptr)
			{
				current->left = new Node(current->GetData());
				current->rigth = new Node(data);
				++this->size;
				if (data.GetPower() > current->GetData().GetPower())
					current->SetData(data);
			}
			else
			{
				if (data.GetPower() > current->GetData().GetPower())
					current->SetData(data);
				funk(buff, current->left, i, data);
			}
		}
		else
		{
			if (data.GetPower() > current->GetData().GetPower())
				current->SetData(data);
			funk(buff, current->rigth, i, data);
		}
	};
	void clear_recurse(Node* current)
	{
		if (current == nullptr) return;
 		if (current->left != nullptr) { clear_recurse(current->left); delete current->left; }
		if (current->rigth != nullptr) { clear_recurse(current->rigth); delete current->rigth; }
	}

public:
	Tree() { this->root = nullptr; this->size = 0; }
	~Tree() { this->clear(); }
	void clear()
	{
		clear_recurse(this->root);
		delete this->root;
		this->root = nullptr;
		this->size = 0;
	}
	void push(Team alfa)
	{
		++this->size;
		if (this->root == nullptr)
		{
			this->root = new Node(alfa);
			return;
		}
		this->funk(this->size, this->root, 1, alfa);
	}

	int sum() 
	{
		if (this->root == nullptr) return 0;
		return this->root->sum();
	}
	void print() 
	{
		if (this->root == nullptr) return;
		this->root->print(0);
	}

	void tournament_print(int a)
	{
		if (this->root == nullptr) return;
		this->root->tournament_print(0, a);
	}
};