// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Box {
    int width;
    int height;
    int depth;

    bool operator<(const Box& b2) const {
        return width < b2.width && height < b2.height && depth < b2.depth;
    }
};

ostream& operator << (ostream& stream, const Box& b) {

    stream << "(" << b.width << ", " << b.height << ", " << b.depth << ")";
    return stream;
}

vector<Box> smallestBoxes (const vector<Box>& boxes) {
    vector<Box> smallest;
    smallest.push_back(boxes[0]);
    for (int i = 1; i < boxes.size(); i++) {
        bool subsumed = false;
        for (const Box& b : smallest) {
            if (b < boxes[i]) {
                subsumed = true;
                break;
            }
        }
        if (!subsumed) {
            smallest.push_back(boxes[i]);
        }
    }
    return smallest;
}

vector<Box> boxesBiggerThan(const vector<Box>& boxes, const Box& ref) {
    vector<Box> bigger;
    for (auto b: boxes) {
        if (ref < b) {
            bigger.push_back(b);
        }
    }
    return bigger;
}

int maxHeight(const vector<Box> box, int stackHeight) {
    if (box.size() == 0) { return stackHeight; }
    auto smallest = smallestBoxes(box);
    int max = 0;
    for (const auto& s : smallest) {
        int h = maxHeight(boxesBiggerThan(box, s), stackHeight + s.height);
        if (h > max) {
            max = h;
        }
    }
    return max;
}

int maxHeight(vector<Box> box) {
    sort(box.begin(),box.end());
    return maxHeight(box, 0);    
}

int main()
{
    // Read input
    int n;
    cin >> n;
    vector<Box> box(n);
    for (int i = 0; i < n; i++) {
        cin >> box[i].width >> box[i].height >> box[i].depth;
    }
    cout << maxHeight(box);
    cout << "\n";
    return 0;
}
