#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

const int DO_NOT_ADD = -1;

void mergeLists(const vector<string> originalList, const vector<string> addList,
                const vector<string> removeList);

int main() {
  // Initialize lists
  vector<string> originalList;
  originalList.push_back("one");
  originalList.push_back("two");
  originalList.push_back("three");
  vector<string> addList;
  addList.push_back("one");
  addList.push_back("two");
  addList.push_back("five");
  addList.push_back("six");
  vector<string> removeList;
  removeList.push_back("two");
  removeList.push_back("five");

  vector<string> originalList2;
  originalList2.push_back("aaa");
  originalList2.push_back("bbbb");
  originalList2.push_back("ccccc");
  vector<string> addList2;
  addList2.push_back("ccccc");
  addList2.push_back("dddddd");
  addList2.push_back("eeeeeee");
  addList2.push_back("aaa");
  vector<string> removeList2;
  removeList2.push_back("dddddd");
  removeList2.push_back("ccccc");

  cout << "Test mergeLists(['one', 'two', 'three'], ['one', 'two', 'five', 'six'], "
          "['two', 'five'] )"
       << endl;
  cout << "\tExpect: three six one" << endl;
  cout << "\tActual: ";
  mergeLists(originalList, addList, removeList);
  cout << endl << endl;

  cout << "Test mergeLists(['aaa', 'bbb', 'ccccc'], ['ccccc', 'dddddd', 'eeeeeee', "
          "'aaa'], "
          "['dddddd', 'ccccc'] )"
       << endl;
  cout << "\tExpect: eeeeeee bbbb aaa" << endl;
  cout << "\tActual: ";
  mergeLists(originalList2, addList2, removeList2);

  cout << endl;

  return 0;
}

void mergeLists(const vector<string> originalList, const vector<string> addList,
                const vector<string> removeList) {
  map<string, int> sizeCache;  // Stores length of each string
  vector<string> finalList;    // Builds the final string

  // Get lengths for all lists, marks cache with sentinel if the string
  // is to be removed
  for (string s : originalList) sizeCache[s] = s.length();
  for (string s : addList) sizeCache[s] = s.length();
  for (string s : removeList) sizeCache[s] = DO_NOT_ADD;

  // Iterate through the cache
  for (map<string, int>::iterator it = sizeCache.begin(); it != sizeCache.end(); it++) {
    // If the string is not marked to be removed
    if (it->second != DO_NOT_ADD) {
      // Add string to final list
      finalList.push_back(it->first);
      if (finalList.size() == 1) continue;  // and go to next iteration if it is the first

      // Start comparing from the back of the final list
      unsigned int i = finalList.size() - 1;
      string prev = finalList[i - 1];
      string current = finalList[i];

      // And look for the right position in the final string
      while (i >= 1 && sizeCache[prev] <= sizeCache[current]) {
        // If they are the same size but alphabetically in the right order
        // just break, otherwise keep swapping
        if (prev.size() == current.size() && prev[0] > current[0]) break;

        string temp = finalList[i - 1];
        finalList[i - 1] = finalList[i];
        finalList[i] = temp;
        i--;
      }
    }
  }

  // Pring final list for test purposes only
  for (string s : finalList) cout << s << " ";
}