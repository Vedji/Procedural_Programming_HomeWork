#include <iostream>
#include <vector>
using namespace std;

struct dict {
    int key;
    int value;
};

class DictArray {
private:
    vector<dict> _arr;
public:
    int get(int key, int default_key = 0) {
        for (int i = 0; i < _arr.size(); i++) {
            if (_arr[i].key == key) {
                return _arr[i].value;
            }
        }
        return default_key;
    }
    void setValue(int key, int value) {
        for (int i = 0; i < _arr.size(); i++) {
            if (_arr[i].key == key) {
                _arr[i].value = value;
                return;
            }
        }
        _arr.push_back(dict{ key, value });
    }
    void delValueByKey(int key){
        if (_arr.size() <= 0) return;
        vector<dict>::iterator  iter = _arr.begin();
        int i = 0;
        for (; i < _arr.size(); i++) if (_arr[i].key == key) break;
        if (i != 0)
            advance(iter, i - 1);
        _arr.erase(iter);
    }
    int getMaxFromValues() {
        if (_arr.size() <= 0) return 0;
        int maxim = _arr.back().value;
        for (int i = 0; i < _arr.size() - 1; i++) {
            if (_arr[i].value > maxim) maxim = _arr[i].value;
        }
        return maxim;
    }
    int getMaxFromKeys() {
        if (_arr.size() <= 0) return 0;
        int maxim = _arr.back().key;
        for (int i = 0; i < _arr.size() - 1; i++) {
            if (_arr[i].key > maxim) maxim = _arr[i].key;
        }
        return maxim;
    }
};

int main()
{
    int N = 100;
    int K = 30;
    int left = 0;
    int right = 0;
    DictArray* myDict = new DictArray();
    myDict->setValue(N, 1);
    while (K > 0) {
        int maximus = myDict->getMaxFromKeys();
        int minimus = (K >  myDict->get(maximus, K)) ? myDict->get(maximus) : K;
        myDict->delValueByKey(maximus);
        K -= minimus;
        left = (maximus - 1) / 2;
        right = maximus - 1 - left;
        myDict->setValue(left, 
            (myDict->get(left) + minimus)
        );
        myDict->setValue(right,
            (myDict->get(right, 0) + minimus)
        );
    }
    cout << left << endl;
    cout << right << endl;
}
