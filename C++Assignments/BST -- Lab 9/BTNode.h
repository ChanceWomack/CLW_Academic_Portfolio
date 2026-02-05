#ifndef BTNODE_H
#define BTNODE_H

template <class Type>
class BTNode {
   public:
    Type data;
    BTNode<Type> *leftC;//points at left subtree
    BTNode<Type> *rightC;//points at right subtree
    BTNode<Type>() {//constructor (could just set pointers to nullptr instead
        leftC = 0;
        rightC = 0;
    }//end constructor
};

#endif /* BTNODE_H */
