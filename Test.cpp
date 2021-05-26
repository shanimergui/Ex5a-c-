#include "doctest.h"
#include "sources/BinaryTree.hpp"
using namespace std;
using namespace ariel;


TEST_CASE("check preorder"){
        BinaryTree<int> tree_of_ints;
        CHECK_NOTHROW(tree_of_ints.add_root(1)
                      .add_left(1, 9)
                      .add_left(9, 4)
                      .add_right(9, 5)
                      .add_right(1, 3)
                      .add_left(1, 2));

        CHECK_THROWS(tree_of_ints.add_left(8,9));

        CHECK_THROWS(tree_of_ints.add_right(8,9));

        int i = 0;
        for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {

                if(i==0) {
                        CHECK_EQ((*it),1);
                }
                if(i==1) {
                        CHECK_EQ((*it),2);
                }
                if(i==2) {
                        CHECK_EQ((*it),4);
                }
                if(i==3) {
                        CHECK_EQ((*it),5);
                }
                if(i==4) {
                        CHECK_EQ((*it),3);
                }

                i++;
        } // prints: 1 2 4 5 3
        
}


TEST_CASE("check inorder"){
BinaryTree<int> tree_of_ints;
CHECK_NOTHROW(tree_of_ints.add_root(1)
.add_left(1, 8)
.add_left(8, 12)
.add_right(8, 5)
.add_right(1, 10)
.add_left(10, 4)
.add_right(10, 3));

CHECK_THROWS(tree_of_ints.add_left(11,8));

CHECK_THROWS(tree_of_ints.add_right(11,8));

int i=0;
for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
if(i==0) {
CHECK_EQ((*it),12);
}
if(i==1) {
CHECK_EQ((*it),8);
}
if(i==2) {
CHECK_EQ((*it),5);
}
if(i==3) {
CHECK_EQ((*it),1);
}
if(i==4) {
CHECK_EQ((*it),4);
}
if(i==5) {
CHECK_EQ((*it),10);
}
if(i==6) {
CHECK_EQ((*it),3);
}

i++;
} // prints: 12 8 5 1 4 10 3

}


TEST_CASE("check postorder"){
BinaryTree<int> tree_of_ints;
CHECK_NOTHROW(tree_of_ints.add_root(1)
.add_left(1, 8)
.add_left(8, 7)
.add_right(8, 5)
.add_right(1, 10)
.add_left(10, 4)
.add_right(10, 3));

CHECK_THROWS(tree_of_ints.add_left(11,8));

CHECK_THROWS(tree_of_ints.add_right(11,8));

int i=0;
for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
if(i==0) {
CHECK_EQ((*it),7);
}
if(i==1) {
CHECK_EQ((*it),5);
}
if(i==2) {
CHECK_EQ((*it),8);
}
if(i==3) {
CHECK_EQ((*it),4);
}
if(i==4) {
CHECK_EQ((*it),3);
}
if(i==5) {
CHECK_EQ((*it),10);
}
if(i==6) {
CHECK_EQ((*it),1);
}

i++;
} // prints: 7 5 8 4 3 10 1

}
TEST_CASE("check size in string"){
 
    BinaryTree<string> tree_of_strings;
    tree_of_strings.add_root("1")     
    .add_left("1", "9")      
    .add_left("9", "4")      
    .add_right("1", "3")     
    .add_left("1", "2"); 

    for (auto it=tree_of_strings.begin_postorder(); it!=tree_of_strings.end_postorder(); ++it){
            CHECK_EQ (it->size() ,1); 
            CHECK_EQ (it->size() ,2); 
            cout<<"size: "<<it->size()<<endl;
            // prints: 1 1 1 1 
    }

}


TEST_CASE("check if the tree exists"){
BinaryTree<int> tree_of_ints1;

CHECK_THROWS( tree_of_ints1.add_left(1, 9)  );
CHECK_THROWS( tree_of_ints1.add_left(1, 8)  );
CHECK_THROWS( tree_of_ints1.add_left(1, 7)  );
CHECK_THROWS( tree_of_ints1.add_left(8, 9)  );

CHECK_THROWS( tree_of_ints1.add_left(1, 8)  );
CHECK_THROWS( tree_of_ints1.add_left(1, 9)  );
CHECK_THROWS( tree_of_ints1.add_left(5, 9)  );
CHECK_THROWS( tree_of_ints1.add_left(1, 8)  );
CHECK_THROWS( tree_of_ints1.add_left(2, 7)  );
CHECK_THROWS( tree_of_ints1.add_left(3, 9)  );
CHECK_THROWS( tree_of_ints1.add_left(1, 8)  );
CHECK_THROWS( tree_of_ints1.add_left(1, 7)  );

}

TEST_CASE("test strings") {
    BinaryTree<string> tree;
    CHECK_NOTHROW(tree.add_root("1")
                .add_left("1", "9") 
                .add_left("9", "4") 
                .add_right("9", "5")
                .add_right("1", "3"));

    string s;
    for (auto it=tree.begin_preorder(); it!=tree.end_preorder(); ++it) {
      
        CHECK_NOTHROW(s += (*it) + " ") ;
    }
    CHECK(s == "1 9 4 5 3 ");
    s = "";
    for (auto it=tree.begin_inorder(); it!=tree.end_inorder(); ++it) {
        CHECK_NOTHROW(s += (*it) + " ") ;
    }
    CHECK(s == "4 9 5 1 3 ");
    s = "";
    for (auto it=tree.begin_postorder(); it!=tree.end_postorder(); ++it) {
        CHECK_NOTHROW(s += (*it) + " ") ;
    }
    CHECK(s == "4 5 9 3 1 ");
}


TEST_CASE("test  ints") {
    BinaryTree<int> tree;
    CHECK_NOTHROW(tree.add_root(1)
                .add_left(1, 9) 
                .add_left(9, 4) 
                .add_right(9, 5)
                .add_right(1, 3));

    string s;
    for (auto it=tree.begin_preorder(); it!=tree.end_preorder(); ++it) {
        CHECK_NOTHROW(s += to_string(*it) + " " );
    }
    CHECK(s == "1 9 4 5 3 ");
    s = "";
    for (auto it=tree.begin_inorder(); it!=tree.end_inorder(); ++it) {
        CHECK_NOTHROW(s += to_string(*it) + " " );
    }
    CHECK(s == "4 9 5 1 3 ");
    s = "";
    for (auto it=tree.begin_postorder(); it!=tree.end_postorder(); ++it) {
        CHECK_NOTHROW(s += to_string(*it) + " " );
    }
    CHECK(s == "4 5 9 3 1 ");
}
