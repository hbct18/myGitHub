#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <iostream>
#include "BTnode.h"

template <typename elemType>
class BinaryTree
{
    friend std::ostream& operator<<(std::ostream&, const BinaryTree<elemType>&);

public:
    BinaryTree();
    BinaryTree(const BinaryTree&);
    ~BinaryTree();
    BinaryTree& operator=(const BinaryTree&);

    bool empty() { return _root == 0; }
    void clear(){ if (_root){ clear(_root); _root = 0; }}
    void insert(const elemType&);
    void remove(const elemType&);
    void remove_root();

private:
    void clear(BTnode<elemType>*);
    BTnode<elemType> *_root;
    
    // 将 src 所指子树复制到 tar 所指子树
    void copy(BTnode<elemType> *tar, BTnode<elemType> *src);
};

template <typename elemType>
inline BinaryTree<elemType>::BinaryTree() : _root(0){}

template <typename elemType>
inline BinaryTree<elemType>::BinaryTree(const BinaryTree &rhs)
{ copy(_root, rhs._root);}

template <typename elemType>
inline BinaryTree<elemType>::~BinaryTree(){ clear(); }

template <typename elemType>
inline BinaryTree<elemType>& BinaryTree<elemType>::
operator=(const BinaryTree &rhs)
{
    if (this != &rhs)
        { clear(); copy(_root, rhs._root); }
    return *this;
}

template <typename elemType>
inline void BinaryTree<elemType>::insert(const elemType &elem)
{
    if (!_root)
        _root = new BTnode<elemType>(elem);
    else
        _root->insert_value(elem);
}

template <typename elemType>
inline void BinaryTree<elemType>::remove(const elemType &elem)
{
    if (_root)
    {
        if (_root->_val == elem)
            remove_root();
        else
            _root->remove_value(elem, _root);
    }
}

template <typename elemType>
void BinaryTree<elemType>::remove_root()
{
    if (!_root) return;

    BTnode<elemType> *tmp = _root;
    if (_root->_rchild)
    {
        _root = _root->_rchild;
        
        // 将左子节点搬移到右子节点的左子树的最底部
        if (tmp->_lchild)
        {
            BTnode<elemType> *lc = tmp->_lchild;
            BTnode<elemType> *newlc = _root->_lchild;
            if (!newlc)
                //没有任何子树，直接接上
                _root->_lchild = lc;
            
            // lchild_leaf 会遍历整个左子树
            // 寻找某个可黏接上去的 null 左子节点
            else
                BTnode<elemType>::lchild_leaf(lc, newlc);
        }
    }
    else
        _root = _root->_lchild;
    
    delete tmp; //移除根节点
}

template <typename elemType>
void BinaryTree<elemType>::clear(BTnode<elemType> *pt)
{
    if (pt)
    {
        clear(pt->_lchild);
        clear(pt->_rchild);
        delete pt;
    }
}

template <typename elemType>
inline std::ostream& operator<<(std::ostream &os, const BinaryTree<elemType> &bt)
{
    os << "Tree: " << std::endl;
    bt.print(os);
    return os;
}

#endif // !_BINARY_TREE_H_