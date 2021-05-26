    #include <iostream>
    #include <fstream>
    #include <sstream>
    #include <stdexcept>
    #include <vector>
    using namespace std;

    namespace ariel{

      template<typename Temp>
        class BinaryTree{

            using iter =typename vector<Temp>::iterator;

            private:

              vector<Temp> myvec;

            public:
              BinaryTree<Temp>& add_root(Temp Root){
                //change
                return *this;
              }
              BinaryTree<Temp>& add_left(Temp InsideTheTree , Temp NewAddOnLeftSide){
                return *this;
              }
              BinaryTree<Temp>& add_right(Temp InsideTheTree , Temp NewAddOnRightSide){
                return *this;
              }
              iter begin_preorder(){
                return myvec.end();
              }
              iter end_preorder(){
                  return myvec.end();
              }
              iter begin_inorder(){
                  return myvec.end();
              }
              iter end_inorder(){
                  return myvec.begin();
              }
              iter begin_postorder(){
                  return myvec.begin();
              }
              iter end_postorder(){
                  return myvec.begin();
              }
              iter begin(){
                  return myvec.begin();
              }
              iter end(){
                  return myvec.begin();
              }
              friend ostream& operator<<(ostream& os,BinaryTree<Temp> tree){
                return os;
              }
            };
          }
