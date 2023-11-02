#ifndef AVL_TREE_H
#define AVL_TREE_H
#define DEBUG
#include <stdexcept>
#include <algorithm>
#include <iostream>

// This implementation is based on the unbalanced binary search tree and adds hight information
// to the nodes and a balance function to perform the needed rotations.

// THIS IS CURRENTLY IMPLEMENTED AS A SET BUT NEEDS TO BE AS A MAP

template <typename Comparable, typename Value>
class AvlTree
{
private:
    struct AvlNode
    {
        Comparable key;
        AvlNode *left;
        AvlNode *right;
        int height;

        AvlNode(const Comparable &theKey, AvlNode *lt, AvlNode *rt, int h)
            : key{theKey}, left{lt}, right{rt}, height{h} {}
    };

    AvlNode *root;

public:
    AvlTree() : root{nullptr} // default constructor
    {
    }

    AvlTree(const AvlTree &rhs) : root{nullptr} // copy constructor
    {
        root = clone(rhs.root);
    }

    ~AvlTree() // descructor
    {
        makeEmpty();
    }

    AvlTree &operator=(const AvlTree &rhs) // copy constructor
    {
        makeEmpty();
        root = clone(rhs.root);
        return *this;
    }

    bool contains(const Comparable &x) const // returns true if x is found in the tree
    {
        return contains(x, root);
    }

    bool isEmpty() const // is the tree empty?
    {
        return root == nullptr;
    }

    void makeEmpty() // emptys the tree
    {
        makeEmpty(root);
    }

    void insert(const Comparable &x) // inserts x into the tree
    {
        insert(x, root);
    }

    void remove(const Comparable &x) // removes x from the tree
    {
        remove(x, root);
    }

private:
    void insert(const Comparable &x, AvlNode *&t) // inserts x into a subtree, t is the node that roots the subtree
    {
        if (t == nullptr)
        {
            t = new AvlNode{x, nullptr, nullptr, 0};
            return;
        }
        if (x < t->key)
        {
            insert(x, t->left);
        }
        else if (t->key < x)
        {
            insert(x, t->right);
        }
        else
        {
        }
        balance(t);
    }

    void remove(const Comparable &x, AvlNode *&t) // removes x from a subtree, t is the node that roots the subtree
    {
        throw std::runtime_error("Not implemented yet!");

        // same as in a binary search tree

        balance(t);
    }

    void makeEmpty(AvlNode *&t) // emptys the subtree
    {
        if (t == nullptr)
        {
            return;
        }
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = nullptr;
    }

    AvlNode *clone(AvlNode *t) const // clones the subtree
    {
        if (t == nullptr)
        {
            return nullptr;
        }
        return new AvlNode{t->key, clone(t->left), clone(t->right), t->height};
    }

    // Balancing: AVL Rotations

    int height(AvlNode *t) const // returns the height of node t or -1 if nullptr
    {
        return t == nullptr ? -1 : t->height;
    }

    static const int ALLOWED_IMBALANCE = 1; // 1 is the default; more will make balancing cheaper but the search is less efficent

    /**
     * 1. Performs rotations if the the the difference of the height stored in t's two child nodes
     *    more than ALLOWED_IMBALANCE.
     * 2. Updates the height information of the note t.
     *
     * Assumes that the high information in the child nodes is correct. This is guaranteed by calling
     * balance() recursivly from the inserted node up to the tree node (see insert()). Rotations will
     * only be performed for node alpha (parent of the parent of the inserted node). For all other nodes,
     * only the height will be updated.
     */
    void balance(AvlNode *&t)
    {
        if (t == nullptr)
        {
            return;
        }

        if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE) // unbalancing insertion was left
        {
            if (height(t->left->left) >= height(t->left->right))
            {
                rotateWithLeftChild(t); // case 1 (outside)
            }
            else
            {
                doubleWithLeftChild(t); // case 2 (inside)
            }
        }
        else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE) // unbalancing insertion was right
        {
            if (height(t->right->right) >= height(t->right->left))
            {
                rotateWithRightChild(t); // case 4 (outside)
            }
            else
            {
                doubleWithRightChild(t); // case 3 (inside)
            }
        }
        t->height = max(height(t->left), height(t->right)) + 1;
    }

    int max(int lhs, int rhs) const
    {
        return lhs > rhs ? lhs : rhs;
    }

    void updatePersistance()
    {
    }

    void populateAVLTreeFromPersistance()
    {
    }

    /**
     * Rotate binary tree node with left child.
     * For AVL trees, this is a single rotation for case 1.
     * Update heights, then set new root.
     */
    void rotateWithLeftChild(AvlNode *&k2)
    {
#ifdef DEBUG
        cout << "need to rotateWithLeftChild for node " << k2->key << endl;
        cout << "Before:" << endl;
        prettyPrintTree();
#endif

        AvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), k2->height) + 1;
        k2 = k1;
#ifdef DEBUG
        cout << "After:" << endl;
        prettyPrintTree();
#endif
    }

    /**
     * Rotate binary tree node with right child.
     * For AVL trees, this is a single rotation for case 4.
     * Update heights, then set new root.
     */
    void rotateWithRightChild(AvlNode *&k1)
    {
#ifdef DEBUG
        cout << "need to rotateWithRightChild for node " << k1->key << endl;
        cout << "Before:" << endl;
        prettyPrintTree();

#endif

        AvlNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2->height = max(height(k2->right), k1->height) + 1;
        k1 = k2;
#ifdef DEBUG
        cout << "After:" << endl;
        prettyPrintTree();
#endif
    }

    /**
     * Double rotate binary tree node: first left child.
     * with its right child; then node k3 with new left child.
     * For AVL trees, this is a double rotation for case 2.
     * Update heights, then set new root.
     */
    void doubleWithLeftChild(AvlNode *&k3)
    {
#ifdef DEBUG
        cout << "doubleWithLeftChild" << endl;
#endif
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }

    /**
     * Double rotate binary tree node: first right child.
     * with its left child; then node k1 with new right child.
     * For AVL trees, this is a double rotation for case 3.
     * Update heights, then set new root.
     */
    void doubleWithRightChild(AvlNode *&k1)
    {
#ifdef DEBUG
        cout << "doubleWithRightChild" << endl;
#endif
        rotateWithLeftChild(k1->right);
        rotateWithRightChild(k1);
    }
};

#endif

// PRETTY PRINT TREE IMPLEMENTATIONS

/**
 * Print the tree structure.
 */
// void prettyPrintTree() const
// {
//     prettyPrintTree("", root, false);
// }
/**
 * Pretty print the tree structure
 * Uses preorder traversal with R and L swapped (NRL)
 *
 * Modified from: https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
 */
// void prettyPrintTree(const std::string &prefix, const AvlNode *node, bool isRight) const
// {
//     if (node == nullptr)
//         return;

//     std::cout << prefix;
//     // Note: this uses unicode characters for the tree structure. They might not print correctly on
//     // all systems (Windows!?!) and all types of output devices.
//     std::cout << (isRight ? "├──" : "└──");
//     // print the value of the node
//     std::cout << node->key << std::endl;

//     // enter the next tree level - left and right branch
//     prettyPrintTree(prefix + (isRight ? "│   " : "    "), node->right, true);
//     prettyPrintTree(prefix + (isRight ? "│   " : "    "), node->left, false);
// }