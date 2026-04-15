string multiplyStrings(string a, int b) {
    string result = "";
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        int prod = (a[i] - '0') * b + carry;
        result = char((prod % 10) + '0') + result;
        carry = prod / 10;
    }
    while (carry) {
        result = char((carry % 10) + '0') + result;
        carry /= 10;
    }
    return result;
}
