#ifndef DSAVL_TREE_H
#define DSAVL_TREE_H
#define DEBUG
#include <stdexcept>
#include <algorithm>
#include <iostream>

// This implementation is based on the unbalanced binary search tree and adds hight information
// to the nodes and a balance function to perform the needed rotations.

// THIS IS CURRENTLY IMPLEMENTED AS A SET BUT NEEDS TO BE AS A MAP

template <typename Comparable>
class DSAvlTree
{
private:
    struct DSAvlNode
    {
        Comparable key;
        DSAvlNode *left;
        DSAvlNode *right;
        int height;

        DSAvlNode(const Comparable &theKey, DSAvlNode *lt, DSAvlNode *rt, int h)
            : key{theKey}, left{lt}, right{rt}, height{h} {}
    };

    DSAvlNode *root;

public:
    DSAvlTree() : root{nullptr} // default constructor
    {
    }

    DSAvlTree(const DSAvlTree &rhs) : root{nullptr} // copy constructor
    {
        root = clone(rhs.root);
    }

    ~DSAvlTree() // destructor
    {
        makeEmpty();
    }

    DSAvlTree &operator=(const DSAvlTree &rhs) // copy constructor
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

    void prettyPrintTree() const
    {
        prettyPrintTree("", root, false);
    }

    void updatePersistance() // public function because it should not be called until the program exits
    {
    }

    void populateDSAVLTreeFromPersistance() // public function because it should not be called until the program exits
    {
    }

private:
    void insert(const Comparable &x, DSAvlNode *&t) // inserts x into a subtree, t is the node that roots the subtree
    {
        if (t == nullptr)
        {
            t = new DSAvlNode{x, nullptr, nullptr, 0};
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

    void remove(const Comparable &x, DSAvlNode *&t) // removes x from a subtree, t is the node that roots the subtree
    {
        if (t == nullptr)
        {
            throw std::runtime_error("Error, could not find 'x' in private remove function");
        }
        if (x < t->key)
        {
            remove(x, t->left);
        }
        else if (t->key < x)
        {
            remove(x, t->right);
        }
        else
        {
            if (t->right != nullptr)
            {
                DSAvlNode *tCopy = t;
                t->key = deleteLeftMostIn(tCopy->right);
                t->height = std::max(height(t->left), height(t->right)) + 1;

                // DSAvlNode *tCopy = t;
                // DSAvlNode *previous = tCopy;
                // DSAvlNode *temp = tCopy;
                // tCopy = tCopy->right;
                // while (tCopy->left != nullptr)
                // {
                //     previous = tCopy;
                //     tCopy = tCopy->left;
                // }
                // temp->key = tCopy->key;
                // if (temp == previous)
                // {
                //     delete tCopy;
                //     previous->right = nullptr;
                // }
                // else
                // {
                //     delete tCopy;
                //     previous->left = nullptr;
                // }
            }
            else if (t->left != nullptr)
            {
                DSAvlNode *tCopy = t;
                t = t->left;
                delete tCopy;
                if (t != nullptr) {
                t->height = std::max(height(t->left), height(t->right)) + 1;
                }
                else {
                    return;
                }
            }
            else {
                // need to update height of parent of t
                t = nullptr;
                delete t;
                return;
            }
        }
        t->height = std::max(height(t->left), height(t->right)) + 1;
        balance(t);
    }

    Comparable deleteLeftMostIn(DSAvlNode *&t) { // delete left most node in the passed subtree, and returns the key in that node
        if (t == nullptr)
        {
            // this should not happen
            throw std::runtime_error("Error in Comparable deleteLeftMostIn(DSAvlNode *t)");
        }
        if (t->left == nullptr)
        {
            // found left most node in subtree
            Comparable valueToReturn = t->key;
            delete t;
            t = nullptr;

            return valueToReturn;
        }
        else {
            Comparable valueToReturn = deleteLeftMostIn(t->left);
            t->height = std::max(height(t->left), height(t->right)) + 1;
            balance(t);
            return valueToReturn;
        }
    }

    bool contains(const Comparable &x, DSAvlNode *t) const
    {
        if (t == nullptr)
        {
            return false;
        }
        if (x < t->key)
        {
            return contains(x, t->left);
        }
        else if (t->key < x)
        {
            return contains(x, t->right);
        }
        else
        {
            return true;
        }
    }

    void makeEmpty(DSAvlNode *&t) // emptys the subtree
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

    DSAvlNode *clone(DSAvlNode *t) const // clones the subtree
    {
        if (t == nullptr)
        {
            return nullptr;
        }
        return new DSAvlNode{t->key, clone(t->left), clone(t->right), t->height};
    }

    // Balancing: DSAVL Rotations

    int height(DSAvlNode *t) const // returns the height of node t or -1 if nullptr
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
    void balance(DSAvlNode *&t)
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

    /**
     * Uses preorder traversal with R and L swapped (NRL)
     *
     * Modified from: https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
     */

    void prettyPrintTree(const std::string &prefix, const DSAvlNode *node, bool isRight) const
    {
        if (node == nullptr)
        {
            return;
        }

        std::cout << prefix;
        std::cout << (isRight ? "├──" : "└──");
        // print the value of the node
        std::cout << node->key << std::endl;
        // enter the next tree level - left and right branch
        prettyPrintTree(prefix + (isRight ? "│   " : "    "), node->right, true);
        prettyPrintTree(prefix + (isRight ? "│   " : "    "), node->left, false);
    }

    /**
     * Rotate binary tree node with left child.
     * For DSAVL trees, this is a single rotation for case 1.
     * Update heights, then set new root.
     */
    void rotateWithLeftChild(DSAvlNode *&k2)
    {
#ifdef DEBUG
        std::cout << "need to rotateWithLeftChild for node " << k2->key << std::endl;
        std::cout << "Before:" << std::endl;
        prettyPrintTree();
#endif

        DSAvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), k2->height) + 1;
        k2 = k1;
#ifdef DEBUG
        std::cout << "After:" << std::endl;
        prettyPrintTree();
#endif
    }

    /**
     * Rotate binary tree node with right child.
     * For DSAVL trees, this is a single rotation for case 4.
     * Update heights, then set new root.
     */
    void rotateWithRightChild(DSAvlNode *&k1)
    {
#ifdef DEBUG
        std::cout << "need to rotateWithRightChild for node " << k1->key << std::endl;
        std::cout << "Before:" << std::endl;
        prettyPrintTree();

#endif

        DSAvlNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2->height = max(height(k2->right), k1->height) + 1;
        k1 = k2;
#ifdef DEBUG
        std::cout << "After:" << std::endl;
        prettyPrintTree();
#endif
    }

    /**
     * Double rotate binary tree node: first left child.
     * with its right child; then node k3 with new left child.
     * For AVL trees, this is a double rotation for case 2.
     * Update heights, then set new root.
     */
    void doubleWithLeftChild(DSAvlNode *&k3)
    {
#ifdef DEBUG
        std::cout << "doubleWithLeftChild" << std::endl;
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
    void doubleWithRightChild(DSAvlNode *&k1)
    {
#ifdef DEBUG
        std::cout << "doubleWithRightChild" << std::endl;
#endif
        rotateWithLeftChild(k1->right);
        rotateWithRightChild(k1);
    }
};

#endif