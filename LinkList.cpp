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
    //��ʼ������
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
        curr->next = NULL;//ָ���ڲ���ʼ��������»��������ֵ��������Ҫ�ֶ���ĩβnextΪ��
    }

    //չʾ����
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

    //��Pos����Ԫ��
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

    //��curr�����Ԫ��
    void insertElement(const E& it){
        Node<E>* temp = new Node<E>;
        temp->val = it;
        temp->next = curr->next;
        curr->next = temp;
        count++;
    }
    //����б�
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
        count = 0;
    }
    //β�����Ԫ��
    void appendElement(const E& it){
        Node<E>* temp =new Node<E>;
        while(curr->next != NULL){
            curr = curr->next;
        }
        temp->val = it;
        curr->next = temp;
        curr = temp;
        temp->next = NULL;
        count++;
    }
    //ɾ��Ԫ��,ɾ������curr��Ԫ��
    void deleteElement(){
        if(count==0){
            cout<<"linklist no more element"<<endl;
            return;
        }
        Node<E>* temp = curr;
        curr = head;
        while(curr!=temp&&curr->next!=temp){
            curr = curr->next;
        }
        curr->next=temp->next;
        cout<<"delete element:"<<temp->val<<endl;
        delete temp;
        count--;
    }
    //ͨ��Posɾ��Ԫ��
    void deletePos(const E& it){
        curr = head;
        for(int i = 0;i<it;i++){
            curr = curr->next;
        }
        Node<E>* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        count--;
    }


};
int main(){
    LinkList<int> list;
    cout<<"����������";
    list.showLinkList();
    cout<<"��curr������Ԫ��:";
    list.insertByPos(0,10);
    list.showLinkList();
    cout<<"��պ������:";
    list.clear();
    list.showLinkList();
    cout<<"���Ԫ�غ������:";
    list.appendElement(1);
    list.appendElement(3);
    list.appendElement(5);
    list.appendElement(7);
    list.appendElement(9);
    list.showLinkList();
    cout<<"��curr������100�������:";
    list.insertElement(100);//����append��curr�Ƿ񷵻ص�ԭ����λ��
    list.showLinkList();
    cout<<"ɾ��curr��Ԫ�غ������:";
    list.deleteElement();
    list.showLinkList();
    //list.test();
    cout<<"ɾ��λ��2����Ԫ�غ������:";
    list.deletePos(2);
    list.showLinkList();
    cout<<"��λ��2����99�������:";
    list.insertByPos(2,99);
    list.showLinkList();
}