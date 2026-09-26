#include "mylist.h"

int main() {
  MyList<int> int_list;
  int_list.push_back(11);
  int_list.push_back(22);
  int_list.push_back(33);
  cout << "Original print of int list: ";
  int_list.show_list();

  cout << "Traverse int list with iterator: ";
  for (auto it = int_list.begin(); it != int_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;

  cout << "Range-based for loop for int list: ";
  for (int x : int_list) {
    cout << x << " ";
  }
  cout << "\n------------------------\n";

  cout << "Test --end() reverse: ";
  auto it = int_list.end();
  --it;
  for (; it != int_list.begin(); --it) {
    cout << *it << " ";
  }
  cout << *it << "\n------------------------\n";

  MyList<string> str_list;
  str_list.push_back("C++");
  str_list.push_back("MySTL");
  str_list.push_back("list iterator");
  cout << "Traverse string list with iterator: ";
  for (auto it = str_list.begin(); it != str_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;

  cout << "Range-based for loop for string list: ";
  for (string s : str_list) {
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
