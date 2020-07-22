/**
 * author:LHW
 * time:2020-7-16
 * description:Link List
 */
#include<iostream>
using namespace  std;
int count = 0;
template<typename T>
struct Node{
    Node* next;
    T val;
};

template<typename E>
class LinkList{
private:
    int count = 0;
    Node<E>* head;
    Node<E>* curr;
public:
    //初始化链表
    LinkList(){
        head = new Node<E>;
        curr = head;
        cout<<"input the size of link list:";
        cin>>count;
        cout<<"input nums:";
        for(int i = 0;i<count;i++){
            Node<E>*temp = new Node<E>;
            int value;
            cin>>value;
            temp->val = value;
            curr->next = temp;
            curr = temp;
        }
        curr->next = NULL;//指针在不初始化的情况下会随机分配值，所以需要手动让末尾next为空
    }

    //展示链表
    void showLinkList(){
        cout<<"(";
        Node<E>* temp = head->next;
        for(int i = 0;i<count;i++){
            if(i!=count-1){
                cout<<temp->val<<" ";
                temp = temp->next;
            }else{
                cout<<temp->val;
            }

        }
        cout<<")"<<endl;
    }

    //通过Pos插入元素
    void insertByPos(int pos,const E& it){
        if(pos<0&&pos>=count){
            cout<<"Wrong pos"<<endl;
            return;
        }
        Node<E>*temp = new Node<E>;
        temp->val = it;
        curr=head;
        for(int i=0;i<pos;i++){
            curr=curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
        count++;
    }

    //在curr插入元素
    void insertElement(const E& it){
        Node<E>* temp = new Node<E>;
        temp->val = it;
        temp->next = curr->next;
        curr->next = temp;
        count++;
    }
    //清空列表
    void clear(){
        curr=head->next;
        Node<E>* temp = curr;
        for(int i=0;i<count;i++){
            temp = curr->next;
            delete curr;
            curr = temp;
        }
        curr = head;
        head->next = NULL;
        //curr->next = NULL;
        count = 0;
    }
    //尾部添加元素
    void appendElement(const E& it){
        Node<E>* tempptr = curr;
        Node<E>* temp =new Node<E>;
        while(curr->next != NULL){
            curr = curr->next;
        }
        temp->val = it;
        curr->next = temp;
        curr = tempptr;
        temp->next = NULL;
        count++;
    }
    //删除元素,删除的是curr的元素
    void deleteElement(){
        cout<<1<<endl;
        if(count==0){
            cout<<"linklist no more element"<<endl;
            return;
        }
        cout<<2<<endl;
        Node<E>* temp = curr;
        curr=head;
        while(curr->next!=temp){
            curr=curr->next;
        }
        cout<<3<<endl;
        curr->next=temp->next;
        cout<<"delete element:"<<temp->val<<endl;
        delete temp;
    }
    //通过Pos删除元素
    void deletePos(){}


};
int main(){
    LinkList<int> list;
    list.showLinkList();
    list.insertByPos(0,10);
    list.showLinkList();
    list.clear();
    list.showLinkList();
    list.appendElement(1);
    list.appendElement(3);
    list.appendElement(5);
    list.appendElement(7);
    list.appendElement(9);
    list.showLinkList();
    list.insertElement(100);//测试append后curr是否返回到原本的位置
    list.showLinkList();
    cout<<"hi"<<endl;
    list.deleteElement();
    list.showLinkList();
    //list.test();
}