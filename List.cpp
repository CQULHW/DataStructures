/*
*author:LHW
*time:2020-7-14
*description:array based list
*/
#define defaultSize 10
#include<iostream>
using namespace std;
template<typename E>
class List{
private:
    int maxSize;    //˳�����󳤶�
    int listSize;   //˳���ĳ���
    int current;    //˳�������Ԫ�����ڵ�λ��
    E* listArray;   //����Ԫ�ص�����
public:
    //���캯��
    List(int size = defaultSize){
        maxSize = size;
        listSize = current = 0;
        listArray = new E[maxSize];
    }

    //��������
    ~List(){delete [] listArray;}

    //���Ԫ��
    void clear(){
        delete [] listArray;        //�ͷ������ȫ���ڴ�ռ�
        listSize = current =0;
        listArray = new E[maxSize]; //ɾ����������·���

    }

    //����Ԫ��
    //ʹ������
    void insert(const E& it){
        for(int i = listSize; i > current;i--){
            listArray[i] = listArray[i-1];
        }
        listArray[current] = it;
        listSize++;
    }

    //β������Ԫ��
    void append(const E& it){
        listArray[listSize++] = it;
    }

    //ɾ����ǰԪ��
    E remove(){
        E it=listArray[current];
        for(int i=current;i<listSize-1;i++){
            listArray[i]=listArray[i+1];
        }
    }

    //���ص���ʼλ��
    void moveToStrat(){
        current = 0;
    }

    //����ĩβλ��
    void moveToEnd(){
        current = listSize;
    }

    //��ǰ�ƶ�
    void prev(){
        if(current!=0){
            current--;
        }
    }

    //�����ƶ�
    void next(){
        if(current < listSize){
            current++;
        }
    }

    //�������鳤��
    //const���α�ʾ����ֻ��
    int length() const {
        return listSize;
    }

    //����ָ�����ڵ�λ��
    int currentPos() const {
        return current;
    }

    //�ƶ���ĳ���ض���λ��
    void moveToPos(int Pos){
        current = Pos;
    }

    //�õ���ǰָ���ֵ
    //�����ڷ������ã�listArray[current]�����ھֲ������������
    //����������ֱ�ӷ��ض��󣬶��Ƿ���һ����ʱ��ֵ��һ������÷��ض����ȸ��Ƹ�һ����ʱ��ֵ�����������ʱ��ֵ
    //�������Ϊ E& getvalue()==listArray[current],����ָ����listArray[current]�������
    const E& getValue() const {
        return listArray[current];
    }

    //��maxSizeֵ
    int getMaxSize(){
        return maxSize;
    }

    //չʾlist
    void showList(){
        for(int i=0;i<listSize;i++){
            if(i==listSize-1){
                cout<<listArray[i]<<endl;
            }
            else{
                cout<<listArray[i]<<",";
            }

        }
    }

    //ͨ������λ�ý��в���
    void insertByPos(int Pos,int value){
        for(int i=listSize-1;i>=Pos;i--){
            listArray[i+1]=listArray[i];
        }
        listArray[Pos]=value;
        listSize++;
    }
};
int main(){
  List<int> list = List<int>(5);
  cout<<"Ŀǰ���������:"<<list.getMaxSize()<<endl;
  list.append(1);
  list.append(2);
  list.append(3);
  list.append(4);
  list.append(5);
    cout<<"���뼸��Ԫ�غ�:";
  list.showList();
  cout<<"�ڿ�ͷ����10��:";
  list.insert(10);
  list.showList();
  list.insertByPos(0,5);
  cout<<"��listArray[0]����5��:";
  list.showList();
  cout<<"Ŀǰ���鳤��:"<<list.length()<<endl;
  list.next();
  list.next();
  cout<<"����2�����current:"<<list.currentPos()<<endl;
  list.prev();
  cout<<"ǰ��1�����current:"<<list.currentPos()<<endl;
  list.moveToStrat();
  cout<<"�ƶ�����ͷ��current:"<<list.currentPos()<<endl;
  list.moveToEnd();
  cout<<"�ƶ���ĩβ��current:"<<list.currentPos()<<endl;
  list.moveToPos(3);
  cout<<"�ƶ���λ��3��current:"<<list.currentPos()<<endl;
  list.clear();
  cout<<"������list����:"<<list.length()<<endl;
}

