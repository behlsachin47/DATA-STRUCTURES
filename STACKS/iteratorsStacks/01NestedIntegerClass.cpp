#include <iostream>
#include <vector>
#include <stack>

class NestedInteger {
  std::vector<NestedInteger> list;
  int integer;
  bool isInteger;
  bool isInitialized;
public:

  NestedInteger() {
    integer = -1;
    isInteger = 0;
  }

  void setInteger(int num) {
    isInteger = 1;
    integer = num;
  }

  int getInteger() const {
    if (!isInteger)
      throw 0;
    return integer;
  }

  bool isIntegerFunc() const {
    return isInteger;
  }

  void add(NestedInteger val) {
    if (isInteger)
      throw 0;

    list.push_back(val);
  }

  const std::vector<NestedInteger>& getList() const{
    if (isInteger)
      throw 0;

    return list;
  }
  

};
class Iterator {

  std::stack<const NestedInteger*> st;

public:
  Iterator(std::vector<NestedInteger>& list) {
    for (int i = list.size()-1; i >= 0; i--)
      st.push(&list[i]);
  }

  bool hasNext() {
    //ensure top element is integer
    while (!st.empty()) {
      const NestedInteger* curr = st.top();
      if (curr->isIntegerFunc())
        return true;
      else {
        st.pop();
        const std::vector<NestedInteger>& list = curr->getList();
        for (int i = list.size()-1; i >= 0; i--)
          st.push(&list[i]);
      }
    }

    return false;
  }

  int next() {
    int ans = st.top()->getInteger();
    st.pop();
    return ans;
  }
};


int main() {
  NestedInteger e1;
  e1.setInteger(1);

  NestedInteger e2_0;
  NestedInteger e2_1;
  e2_0.setInteger(1);
  e2_1.setInteger(2);
  NestedInteger e2;
  e2.add(e2_0);
  e2.add(e2_1);

  NestedInteger e3_0;
  NestedInteger e3_1_0;
  NestedInteger e3_1_1;
  NestedInteger e3_1;
  e3_0.setInteger(1);
  e3_1_0.setInteger(2);
  e3_1_1.setInteger(3);
  e3_1.add(e3_1_0);
  e3_1.add(e3_1_1);
  NestedInteger e3;
  e3.add(e3_0);
  e3.add(e3_1);

  NestedInteger n1;
  n1.add(e1);
  n1.add(e2);
  n1.add(e3);
  std::vector<NestedInteger> vec = n1.getList();
  Iterator it(vec);
  while (it.hasNext())
    std::cout << it.next() << std::endl;
  return 0;

}
