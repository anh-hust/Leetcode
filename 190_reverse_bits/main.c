int reverseBits(int n) {
    int reversed_num = 0;
    int number_of_bits = sizeof(n) * 8;
    int i;

    for (i = 0; i < number_of_bits; i++){
        if ((n & (1U << i)))
            reversed_num |= 1U << ((number_of_bits - 1) - i);
    }

    return (int)reversed_num;
}