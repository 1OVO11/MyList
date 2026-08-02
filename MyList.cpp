#include <iostream>
#include <iterator>
#include <string>
using namespace std;

template<class T>
struct Node
{
    T data;
    Node* next;
    Node* prev;
    Node(const T& val):data(val), prev(nullptr), next(nullptr){}
};

template<class T>
struct ListIterator
{
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using difference_type = ptrdiff_t;
    using iterator_category = bidirectional_iterator_tag;

    Node<T>* cur;

    ListIterator(Node<T>* p = nullptr):cur(p){}

    // 解引用
    reference operator*() const
    {
        return cur->data;
    }
    // 箭头访问
    pointer operator->() const
    {
        return &(cur->data);
    };
    // 前置++重载
    ListIterator& operator++()
    {
        cur = cur->next;
        return *this;
   };
   // 前置--重载
   ListIterator& operator--()
   {
        cur = cur->prev;
        return *this;
   }
   // 后置++重载
   ListIterator operator++(int)
   {
        ListIterator tem = *this;
        cur = cur->next;
        return tem;
   }
    // 后置--重载
    ListIterator operator--(int)
    {
        ListIterator tem = *this;
        cur = cur->prev;
        return tem;
    }

    bool operator==(const ListIterator& other) const
    {
        return cur == other.cur;
    }

    bool operator!=(const ListIterator& other) const
    {
        return cur != other.cur;
    }
};

template<class T>
class MyList
{
private:
    Node<T>* head;  //哨兵头结点，不存放有效数据
    int size;
public:
    using iterator = ListIterator<T>;

    //构造函数：创建哨兵结点
    MyList()
    {
        head = new Node<T>(T());
        size = 0;
    }

    
    ~MyList()
    {
       clear();
       delete head;
    }

    
    void clear()
    {
        Node<T>* cur = head->next;
        while(cur != nullptr)
        {
            Node<T>* del = cur;
            cur = cur->next;
            delete del;
        }
        head->next = nullptr;
        size = 0;
    }

    //尾插法
    void push_back(const T& val)
    {
        Node<T>* tail = head;
        while(tail->next != nullptr)
        {
            tail = tail->next;
        }
        Node<T>* newnode = new Node<T>(val);
        tail->next = newnode;
        newnode->prev = tail;
        size++;
    }

    //尾删法
    void pop_back()
    {
        if(size == 0)
        {
            return;
        }
        Node<T>* tail = head;
        while(tail->next != nullptr)
        {
            tail = tail->next;
        }
        Node<T>* pre_tail = tail->prev;
        pre_tail->next = nullptr;
        delete tail;
        size--;
    }

    iterator begin()
    {
        return iterator(head->next);
    }
    iterator end()
    {
        return iterator(nullptr);
    }

    int get_size() const
    {
        return size;
    }
    bool empty() const
    {
        return size == 0;
    }

    // 测试函数
    void show_list()
    {
        Node<T>* cur = head->next;
        while (cur != nullptr)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};


int main()
{
    
    MyList<int> int_list;
    int_list.push_back(11);
    int_list.push_back(22);
    int_list.push_back(33);
    cout << "Original print of int list: ";
    int_list.show_list();

    cout << "Traverse int list with iterator: ";
    for (auto it = int_list.begin(); it != int_list.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Range-based for loop for int list: ";
    for (int x : int_list)
    {
        cout << x << " ";
    }
    cout << "\n------------------------\n";

    
    MyList<string> str_list;
    str_list.push_back("C++");
    str_list.push_back("MySTL");
    str_list.push_back("list iterator");
    cout << "Traverse string list with iterator: ";
    for (auto it = str_list.begin(); it != str_list.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Range-based for loop for string list: ";
    for (string s : str_list)
    {
        cout << s << " ";
    }
    cout << endl;

    
    str_list.pop_back();
    cout << "After deleting tail element: ";
    str_list.show_list();

    
    str_list.clear();
    cout << "After clear all elements: ";
    str_list.show_list();

    return 0;
}