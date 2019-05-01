#include <iostream>
using namespace std;

template <class T> class BTnode
{
  public:
    BTnode(const T& x, BTnode* L = nullptr, BTnode* R = nullptr)
      : data(x), left(L), right(R) { } 

    ~BTnode() 
    {
        delete left;
        delete right;
    }

    const T& get_data() const { return data; }
    BTnode* get_left()  const { return left; }
    BTnode* get_right() const { return right; }
    void set_left(BTnode *left) { this->left = left; }
    void set_right(BTnode *right) { this->right = right; }

    void print(int depth = 0) const {
        if (right)
            right->print(depth + 1);

        for (int d = 0; d < depth; ++d)
            cout << '\t';
        cout << data << endl;

        if (left)
            left->print(depth + 1);
    }

    bool is_ancestor_of(const T& data) const {
        if (data == this->data)
            return true;

        if (left)
            if (left->is_ancestor_of(data))
                return true;

        if (right)
            if (right->is_ancestor_of(data))
                return true;

        return false;
    }

    const T find_max() const {
        T result = data;

        if (left) {
            T left_result = left->find_max();
            if (left_result > result)
                result = left_result;
        }

        if (right) {
            T right_result = right->find_max();
            if (right_result > result)
                result = right_result;
        }

        return result;
    }

    const T find_min() const {
        T result = data;

        if (left) {
            T left_result = left->find_min();
            if (left_result < result)
                result = left_result;
        }

        if (right) {
            T right_result = right->find_min();
            if (right_result < result)
                result = right_result;
        }

        return result;
    }
    
  private:
    T data;             // Stored information
    BTnode* left;       // Left child
    BTnode* right;      // Right child
};
