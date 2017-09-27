
int reverse(int num) {
    int reverse_num = 0;
    while (num > 0) {
        reverse_num = reverse_num * 10 + (num % 10);
        num = num/10;
    }
    return reverse_num;
}
