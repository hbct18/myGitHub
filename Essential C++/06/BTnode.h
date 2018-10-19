#ifndef _BTNODE_H_
#define _BTNODE_H_

#include <iostream>
//#include "BinaryTree.h"

template <typename elemType>
class BinaryTree;

template <typename valType>
class BTnode
{
friend class BinaryTree<valType>;

public:
    BTnode(const valType&);
    void insert_value(const valType&);
    void lchild_leaf(BTnode *leaf, BTnode *subtree);
    void remove_value(const valType &val, BTnode *&prev);
    void preorder(BTnode*, std::ostream&) const;
    void inorder(BTnode*, std::ostream&) const;
    void postorder(BTnode*, std::ostream&) const;

private:
    valType _val;
    int _cnt;
    BTnode *_lchild;
    BTnode *_rchild;
};

template <typename valType>
inline BTnode<valType>::BTnode(const valType &val)
    : _val(val)
{
    _cnt = 1;
    _lchild = _rchild = 0;
}

template <typename valType>
void BTnode<valType>::insert_value(const valType &val)
{
    if (val == _val)
        { _cnt++; return; }
    
    if (val < _val)
    {
        if (!_lchild)
            _lchild = new BTnode(val);
        else
            _lchild->insert_value(val);
    }
    else
    {
        if (!_rchild)
            _rchild = new BTnode(val);
        else
            _rchild->insert_value(val);
    }
}

template <typename valType>
void BTnode<valType>::lchild_leaf(BTnode *leaf, BTnode *subtree)
{
    while (subtree->_lchild)
        subtree = subtree->_lchild;
    subtree->_lchild = leaf;
}

template <typename valType>
void BTnode<valType>::remove_value(const valType &val, BTnode *&prev)
{
    if (val < _val)
    {
        if (!_lchild)
            return;
        else
            _lchild->remove_value(val, _lchild);
    }
    else if (val > _val)
    {
        if (!_rchild)
            return;
        else
            _rchild->remove_value(val, _rchild);
    }
    else
    {
        // 找到了，重置此树，然后删除这一节点
        if (_rchild)
        {
            prev = _rchild;
            if (_lchild)
            {
                if (!prev->_lchild)
                    prev->_lchild = _lchild;
                else
                    BTnode<valType>::lchild_leaf(_lchild, prev->_lchild);
            }
        }
        else
            prev = _lchild;
        delete this;
    }
}

template <typename valType>
void BTnode<valType>::preorder(BTnode *pt, std::ostream &os) const
{
    if (pt)
    {
        display_val(pt, os);
        if (pt->_lchild) preorder(pt->_lchild, os);
        if (pt->_rchild) preorder(pt->_rchild, os);
    }
}

template <typename valType>
void BTnode<valType>::inorder(BTnode *pt, std::ostream &os) const
{
    if (pt)
    {
        if (pt->_lchild) inorder(pt->_lchild, os);
        display_val(pt, os);
        if (pt->_rchild) inorder(pt->_rchild, os);
    }
}

template <typename valType>
void BTnode<valType>::postorder(BTnode *pt, std::ostream &os) const
{
    if (pt)
    {
        if (pt->_lchild) postorder(pt->_lchild, os);
        if (pt->_rchild) postorder(pt->_rchild, os);
        display_val(pt, os);
    }
}


#endif // !_BTNODE_H_