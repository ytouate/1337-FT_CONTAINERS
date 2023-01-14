

/*
    AVL : MANY ROTATIONS TO BALANCE THE TREE
    RED-BLACK-TREE : MAX TWO ROTATIONS SOMETIMES COLORING IS WHAT YOU NEED
*/

/*
    What is red-black tree
    a red-black tree is a self-balancing binary search tree, that is a binary search tree
    that automatically maintains some balance

    Red-Black tree is a self-balancing of binary search trees that aim to keep the tree balanced without affecting
    the complexity of the primative operations This is done by coloring each node in the tree with either red or black
    and preserving a set of properties that guarantee that the deepest path in the tree is ot longer than twise the
    shortest one
*/

/*
why red-black tree
    For binary search tree, although the average time complexity for the search insertion and deletion
    are all O(log n) where  is the number of node in the tree, the time complexity becomes O(n) in the worst case
    BST is not balanced

    we can guarantee O(log n) time for all three operations by using a balanced tree a tree
    that always has height log(n)
*/

/*
    Red-black tree properties
    it is a self-balancing bst
    each node is either red or black
    the root is black
    all nil nodes are black
    a red node must not have red children
    all paths from a node to the leaes below contain the same number of black nodes
*/

/*
    Finding the in-order predecessor and successor of node
    First, Compare the 15 with the root
    root > node -> successor, make a recursive call to root. left (why we do it is explained in step 3)
    the new root which is node, now stops making recursive calls
    now successor will be the left most node in the right subtree which has the root 18 here
*/

/*
    RED-BLACK TREE INSERTION
    - if the tree is empty create a new node as root with color black;
    - if the tree is not empty create a leaf node with color red
    - parent of newnode is black then exit
    - if parent of newnode is red then check the color of parent sibling of newnode
        - if color is black or null then do suitable rotation & recolor
        - if color is red then recolor & also check if parent of newnode is not root node the recolor
    10 18 7 15 16 30 25 40 60 2 1 70
*/

/*
    Rotations
*/