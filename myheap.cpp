//https://stackoverflow.com/questions/31577866/c-convert-integer-to-binary-array
//SUNARTHSH METATROPHS INT SE ARRAY APO BITS
void int_to_bin_digit(unsigned int in, int count, int* out)
{
    /* assert: count <= sizeof(int)*CHAR_BIT */
    unsigned int mask = 1U << (count-1);
    int i;
    for (i = 0; i < count; i++) {
        out[i] = (in & mask) ? 1 : 0;
        in <<= 1;
    }
}
