#include <iostream>
#include "btree.h"

using namespace std;

template <class T>
void
invert(BTnode<T>* root)
{
	//Doesnt matter whether it is null or not
	if(root==nullptr)return;	//Base case
	//Swapping of the left and right ptr
	BTnode<T>* temp=root->get_left();
	root->set_left(root->get_right());
	root->set_right(temp);
	//Recursively call the function
	invert(root->get_left());
	invert(root->get_right());
}

template <class T>
BTnode<T>*
lowest_common_ancestor(BTnode<T>* root, const T& a, const T& b)
{
	BTnode<T>* leftresult;
	BTnode<T>* rightresult;
	if(root->is_ancestor_of(a) && root->is_ancestor_of(b)){
		if(root->get_left()!=nullptr){
			if(root->get_left()->is_ancestor_of(a) && root->get_left()->is_ancestor_of(b)){
				leftresult=lowest_common_ancestor(root->get_left(),a,b);
			}else{
				leftresult=root;
			}
		}else{
			leftresult=root;
		}
		if(root->get_right()!=nullptr){
			if(root->get_right()->is_ancestor_of(a)&& root->get_right()->is_ancestor_of(b)){
				rightresult=lowest_common_ancestor(root->get_right(),a,b);
			}else{
				rightresult=root;
			}
		}else{
			rightresult=root;
		}
		return leftresult->is_ancestor_of(rightresult->get_data())?rightresult:leftresult;
	}else{
		return nullptr;
	}
}

template <class T>
int
get_height(BTnode<T>* root)
{
	if(root==nullptr)return -1;

	int left_height=get_height(root->get_left());
	int right_height=get_height(root->get_right());

	return left_height>right_height?1+left_height:1+right_height;
}

template <class T>
bool
is_bst(BTnode<T>* root)
{
	bool ls=false;
	bool rs=false;
	if(root->get_left()){
		if(root->get_left()->find_max()<root->get_data()){
			ls=is_bst(root->get_left());
		}else{
			ls=false;
		}
	}else{
		ls=true;
	}
	if(root->get_right()){
		if(root->get_right()->find_min()>root->get_data()){
			rs=is_bst(root->get_right());
		}else{
			rs=false;
		}
	}else{
		rs=true;
	}
	if(ls && rs)return true;
	else return false;
}

void
test_invert()
{
	BTnode<int>* node4 = new BTnode<int>(4);
	BTnode<int>* node5 = new BTnode<int>(5);
	BTnode<int>* node2 = new BTnode<int>(2, node4, node5);

	BTnode<int>* node6 = new BTnode<int>(6);
	BTnode<int>* node7 = new BTnode<int>(7);
	BTnode<int>* node3 = new BTnode<int>(3, node6, node7);

	BTnode<int>* root = new BTnode<int>(1, node2, node3);

	cout << "invert" << endl;

	cout << "Before invert" << endl;
	root->print();

	invert(root);

	cout << "After invert" << endl;
	root->print();

	cout << endl;

	delete root;
}

template <class T>
void
test_lowest_common_ancestor_output(BTnode<T>* root, const T& a, const T& b)
{
	BTnode<T>* lca = lowest_common_ancestor(root, a, b);
	if (lca)
		cout << "Lowest common ancestor of " << a << " and " << b << " is " << lca->get_data() << endl;
	else
		cout << a << " and " << b << " have no common ancestor" << endl;
}

void
test_lowest_common_ancestor()
{
	BTnode<char>* nodeH = new BTnode<char>('H');
	BTnode<char>* nodeI = new BTnode<char>('I');
	BTnode<char>* nodeJ = new BTnode<char>('J');
	BTnode<char>* nodeK = new BTnode<char>('K');
	BTnode<char>* nodeL = new BTnode<char>('L');
	BTnode<char>* nodeM = new BTnode<char>('M');
	BTnode<char>* nodeN = new BTnode<char>('N');
	BTnode<char>* nodeO = new BTnode<char>('O');

	BTnode<char>* nodeD = new BTnode<char>('D', nodeH, nodeI);
	BTnode<char>* nodeE = new BTnode<char>('E', nodeJ, nodeK);
	BTnode<char>* nodeF = new BTnode<char>('F', nodeL, nodeM);
	BTnode<char>* nodeG = new BTnode<char>('G', nodeN, nodeO);

	BTnode<char>* nodeB = new BTnode<char>('B', nodeD, nodeE);
	BTnode<char>* nodeC = new BTnode<char>('C', nodeF, nodeG);

	BTnode<char>* root = new BTnode<char>('A', nodeB, nodeC);

	cout << "lowest_common_ancestor" << endl;
	root->print();

	test_lowest_common_ancestor_output(root, 'I', 'H');
	test_lowest_common_ancestor_output(root, 'B', 'F');
	test_lowest_common_ancestor_output(root, 'A', 'O');
	test_lowest_common_ancestor_output(root, 'A', 'Z');

	cout << endl;

	delete root;
}

void
test_get_height()
{
	BTnode<char>* nodeI = new BTnode<char>('I');



	BTnode<char>* nodeD = new BTnode<char>('D', nullptr, nodeI);

	BTnode<char>* nodeF = new BTnode<char>('F');
	BTnode<char>* nodeG = new BTnode<char>('G');

	BTnode<char>* nodeB = new BTnode<char>('B', nodeD, nullptr);
	BTnode<char>* nodeC = new BTnode<char>('C', nodeF, nodeG);

	BTnode<char>* root = new BTnode<char>('A', nodeB, nodeC);

	cout << "get_height" << endl;
	root->print();

	cout << "Height is " << get_height(root) << endl;

	cout << endl;

	delete root;
}

void
test_is_bst()
{
	cout << "is_bst" << endl;

	{
		BTnode<int>* node1 = new BTnode<int>(1);
		BTnode<int>* node3 = new BTnode<int>(3);
		BTnode<int>* node5 = new BTnode<int>(5);
		BTnode<int>* node7 = new BTnode<int>(7);

		BTnode<int>* node2 = new BTnode<int>(2, node1, node3);
		BTnode<int>* node6 = new BTnode<int>(6, node5, node7);

		BTnode<int>* root = new BTnode<int>(4, node2, node6);

		root->print();
		cout << boolalpha << "Is bst? " << is_bst(root) << endl;

		delete root;
	}

	{
		BTnode<int>* node1 = new BTnode<int>(1);
		BTnode<int>* node4 = new BTnode<int>(4);
		BTnode<int>* node5 = new BTnode<int>(5);
		BTnode<int>* node7 = new BTnode<int>(7);

		BTnode<int>* node2 = new BTnode<int>(2, node1, node4);
		BTnode<int>* node6 = new BTnode<int>(6, node5, node7);

		BTnode<int>* root = new BTnode<int>(3, node2, node6);

		root->print();
		cout << boolalpha << "Is bst? " << is_bst(root) << endl;

		delete root;
	}

	{
		BTnode<int>* node3 = new BTnode<int>(3);
		BTnode<int>* node1 = new BTnode<int>(1);
		BTnode<int>* node5 = new BTnode<int>(5);
		BTnode<int>* node7 = new BTnode<int>(7);

		BTnode<int>* node2 = new BTnode<int>(2, node3, node1);
		BTnode<int>* node6 = new BTnode<int>(6, node5, node7);

		BTnode<int>* root = new BTnode<int>(4, node2, node6);

		root->print();
		cout << boolalpha << "Is bst? " << is_bst(root) << endl;

		delete root;
	}

	{
		BTnode<int>* node4 = new BTnode<int>(4);
		BTnode<int>* node3 = new BTnode<int>(3, nullptr, node4);
		BTnode<int>* node2 = new BTnode<int>(2, nullptr, node3);
		BTnode<int>* root = new BTnode<int>(1, nullptr, node2);

		root->print();
		cout << boolalpha << "Is bst? " << is_bst(root) << endl;

		delete root;
	}
}

int
main()
{
	test_invert();

	test_lowest_common_ancestor();

	test_get_height();

	test_is_bst();

	return 0;
}
