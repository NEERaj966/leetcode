class MedianFinder {
public:
    priority_queue<int> left;  // max heap
    priority_queue<int, vector<int>, greater<int>> right; // min heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        // Step 1: Put number into left heap
        left.push(num);

        // Step 2: Make sure every element in left <= every element in right
        if (!right.empty() && left.top() > right.top()) {
            int x = left.top();
            left.pop();

            int y = right.top();
            right.pop();

            left.push(y);
            right.push(x);
        }

        // Step 3: Balance the sizes
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {

        // Odd number of elements
        if (left.size() > right.size()) {
            return left.top();
        }

        // Even number of elements
        return (left.top() + right.top()) / 2.0;
    }
};