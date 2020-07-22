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
    int maxSize;    //顺序表最大长度
    int listSize;   //顺序表的长度
    int current;    //顺序表现在元素所在的位置
    E* listArray;   //持有元素的数组
public:
    //构造函数
    List(int size = defaultSize){
        maxSize = size;
        listSize = current = 0;
        listArray = new E[maxSize];
    }

    //析构函数
    ~List(){delete [] listArray;}

    //清除元素
    void clear(){
        delete [] listArray;        //释放数组的全部内存空间
        listSize = current =0;
        listArray = new E[maxSize]; //删除数组后重新分配

    }

    //插入元素
    //使用引用
    void insert(const E& it){
        for(int i = listSize; i > current;i--){
            listArray[i] = listArray[i-1];
        }
        listArray[current] = it;
        listSize++;
    }

    //尾部增添元素
    void append(const E& it){
        listArray[listSize++] = it;
    }

    //删除当前元素
    E remove(){
        E it=listArray[current];
        for(int i=current;i<listSize-1;i++){
            listArray[i]=listArray[i+1];
        }
    }

    //返回到起始位置
    void moveToStrat(){
        current = 0;
    }

    //返回末尾位置
    void moveToEnd(){
        current = listSize;
    }

    //往前移动
    void prev(){
        if(current!=0){
            current--;
        }
    }

    //往后移动
    void next(){
        if(current < listSize){
            current++;
        }
    }

    //返回数组长度
    //const修饰表示函数只读
    int length() const {
        return listSize;
    }

    //返回指针现在的位置
    int currentPos() const {
        return current;
    }

    //移动到某个特定的位置
    void moveToPos(int Pos){
        current = Pos;
    }

    //得到当前指针的值
    //这属于返回引用，listArray[current]不属于局部对象可以引用
    //返回引用是直接返回对象，而非返回一个临时的值，一般非引用返回都是先复制给一个临时的值，返回这个临时的值
    //可以理解为 E& getvalue()==listArray[current],就是指代的listArray[current]这个对象
    const E& getValue() const {
        return listArray[current];
    }

    //返maxSize值
    int getMaxSize(){
        return maxSize;
    }

    //展示list
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

    //通过传递位置进行插入
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
  cout<<"目前数组的容量:"<<list.getMaxSize()<<endl;
  list.append(1);
  list.append(2);
  list.append(3);
  list.append(4);
  list.append(5);
    cout<<"插入几个元素后:";
  list.showList();
  cout<<"在开头插入10后:";
  list.insert(10);
  list.showList();
  list.insertByPos(0,5);
  cout<<"在listArray[0]插入5后:";
  list.showList();
  cout<<"目前数组长度:"<<list.length()<<endl;
  list.next();
  list.next();
  cout<<"后移2个后的current:"<<list.currentPos()<<endl;
  list.prev();
  cout<<"前移1个后的current:"<<list.currentPos()<<endl;
  list.moveToStrat();
  cout<<"移动到开头的current:"<<list.currentPos()<<endl;
  list.moveToEnd();
  cout<<"移动到末尾是current:"<<list.currentPos()<<endl;
  list.moveToPos(3);
  cout<<"移动到位置3的current:"<<list.currentPos()<<endl;
  list.clear();
  cout<<"清除后的list长度:"<<list.length()<<endl;
}

