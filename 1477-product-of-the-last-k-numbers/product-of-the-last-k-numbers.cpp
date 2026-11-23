class ProductOfNumbers {
private:
    vector<int> prefix; // prefix[i] = product of first i numbers (excluding 0 resets)
    int lastZeroIndex;

public:
    ProductOfNumbers() {
        prefix.push_back(1);  // Initialize with 1 for multiplication
        lastZeroIndex = -1;   // No zero yet
    }
    
    void add(int num) {
        if (num == 0) {
            // Reset the prefix list after zero
            prefix.clear();
            prefix.push_back(1);
            lastZeroIndex = prefix.size() - 1; // Track last zero position
        } else {
            // Multiply last prefix with num and add to list
            int lastProduct = prefix.back();
            prefix.push_back(lastProduct * num);
        }
    }
    
    int getProduct(int k) {
        int size = prefix.size();
        if (k >= size) return 0;  // If k extends before last zero, product must be 0
        return prefix.back() / prefix[size - k - 1];
    }
};
