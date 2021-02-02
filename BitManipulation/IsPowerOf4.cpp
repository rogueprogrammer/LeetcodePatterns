vector<bool> getBits(int num) {
    vector<bool> bits;
    while (num >= 1) {
        bits.push_back(num % 2); //0011
        num /= 2;
    }
    reverse(bits.begin(), bits.end());
    return bits;
}

bool isPowerOf4(int num) {
    
    vector<bool> bits = getBits(num);
    if (bits[0] == 0) {
        return false;
    }
    int numOnes = 1; 
    int numZeros = 0;
    for (int i = 1; i < bits.size(); ++i) {
        if (bits[i]) {
            return false;
        }
    }

    return true;
}
