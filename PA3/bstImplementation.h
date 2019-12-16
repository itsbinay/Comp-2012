//submit this file
//you do NOT need to include any header in this file
//just write your BST implementation here right away

template<typename T>
BST<T>::BST(const BST&another){
  if(another.isEmpty()){
    this->root=nullptr;
    return;
  }else{
    this->root=new BSTNode(*another.root);
  }
}

template<typename T>
bool BST<T>::isEmpty() const {
  if(root==nullptr)return true;
  else return false;
}

template<typename T>
bool BST<T>::add(string key,T value){
  if(isEmpty()){
    root=new BSTNode(key,value);
    return true;
  }
  else if(key<root->key){
    bool a=(root->left).add(key,value);
    return a;
  }
  else if(key>root->key){
    bool a=(root->right.add(key,value));
    return a;
  }
  else{
    return false;
  }
}

template<typename T>
bool BST<T>::remove(string key){
  if(isEmpty()){
    return false;
  }
  else if(key<root->key){
    bool a=root->left.remove(key);
    return a;
  }
  else if(key>root->key){
    bool a=root->right.remove(key);
    return a;
  }
  else if((!root->left.isEmpty()) && (!root->right.isEmpty())){//Found node has two children
    root->ke`y=root->right.findMin()->root->key;  //Copy the right value to the current node
    root->value=root->right.findMin()->root->value;
    return root->right.remove(root->key);
  }
  else{
    BSTNode* deleting_node=root;
    //If the left root is empty, move the right root upwards,else
    //left root should move upwards 1 step
    root=(root->left.isEmpty())?root->right.root:root->left.root;
    deleting_node->left.root=deleting_node->right.root=nullptr;
    delete deleting_node;
    deleting_node=nullptr;
    return true;
  }
}

template<typename T>
const BST<T>* BST<T>::findMin()const{
  if(!isEmpty()){
    const BST<T>* node=this;
    while(!node->root->left.isEmpty()){
      node=&node->root->left;
    }
    return node;
  }
  else{
    return nullptr;
  }
}

template<typename T>
T* BST<T>::get(string key)const{
  if(!isEmpty()){//If it isn't empty
    if(key<root->key){  //Less than the current
      return root->left.get(key);
    }
    else if(key>root->key){ //more than the current key
      return root->right.get(key);
    }
    else if(key==root->key){ //Base case 1ß
      return &(this->root->value);
    }else{  //Base case 2
      return nullptr;
    }
  }else{
    return nullptr;
  }
}

template<typename T>
void BST<T>::merge(BST<T>& another){
  //Rearranging the first tree
  if(!isEmpty()){
    BST newtree=*this;  //Copys the new tree
    //std::cout<<newtree<<std::endl;
    while(!this->isEmpty()){
      remove(findMin()->root->key);
    }

    while(!newtree.isEmpty()){
      this->add(newtree.findMin()->root->key,newtree.findMin()->root->value);
      newtree.remove(newtree.findMin()->root->key);
    }

    while(!another.isEmpty()){
      this->add(another.findMin()->root->key,another.findMin()->root->value);
      another.remove(another.findMin()->root->key);
    }
  }
}
