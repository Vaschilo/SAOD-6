#pragma once
#include "Team.h"

class Node
{
private:
	Team data;
public:
	Node* left;
	Node* right;
	Node() { this->left = nullptr; this->right = nullptr; }
	Node(Team data) { this->left = nullptr; this->right = nullptr; this->data = data; }
	~Node() {}

	Team GetData() { return this->data; }
	void SetData(Team a) { this->data = a; }

	void print(int a)
	{
		for (int i = 0; i < a; i++) cout << "  ";
		cout << data << endl;
		if (this->left != nullptr)this->left->print(a + 1);
		if (this->right != nullptr)this->right->print(a + 1);
	}

	void tournament_print(int a, int limit)
	{
		if (a >= limit) 
		{
			for (int i = 0; i < a; i++) cout << "  ";
			cout << data << endl;
		}
		if (this->left != nullptr)this->left->tournament_print(a + 1, limit);
		if (this->right != nullptr)this->right->tournament_print(a + 1, limit);
		cout << endl;
	}

	Team max(Node* current, bool a)
	{
		if (current->left == nullptr) return Team();
		if (current->left->GetData() > current->right->GetData())
		{
			if (a) return current->left->GetData();
			else return current->right->GetData();
		}
		else
		{
			if (a) return current->right->GetData();
			else return current->left->GetData();
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
				current->right = new Node(data);
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
			funk(buff, current->right, i, data);
		}
	};
	void clear_recurse(Node* current)
	{
		if (current == nullptr) return;
 		if (current->left != nullptr) { clear_recurse(current->left); delete current->left; }
		if (current->right != nullptr) { clear_recurse(current->right); delete current->right; }
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
	void finalists()
	{
		Team ar; 
		Team ar2;
		if (this->root != nullptr)
		{
			ar = this->root->max(this->root, 1);
			cout << "Победитель ";
			cout << ar << endl;
			ar = this->root->max(this->root, 0);
			cout << "2 призёр " << ar << endl;
			if (this->root->left != nullptr)
			{
				ar2 = this->root->max(this->root->left, 0);
				ar = this->root->max(this->root->right, 0);
				if (ar > ar2) cout << "3 призёр " << ar << endl;
				else cout << "3 призёр " << ar2 << endl;
			}
		}
	}
};