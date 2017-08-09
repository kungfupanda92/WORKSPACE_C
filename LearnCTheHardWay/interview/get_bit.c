#include <stdio.h>

void msb_check();
int get_int(char *ins);
void get_nth_bit();
void set_nth_bit();
void high_other_set_bit();
void flip_number();
void count_bit();
void convert_binary();

int main(int argc, char *argv[])
{
    // get_nth_bit();
    // set_nth_bit();
    // high_other_set_bit();
    // flip_number();
    // count_bit();
    convert_binary();
    return 0;
}
void convert_binary()
{
    int input = get_int("Input:");
    printf("Output: ");
    while(input)
    {
        if(input & 1)
            putchar('1');
        else   
            putchar('0');
        
        input >>= 1;
    }
}
void count_bit()
{
    int count_ones=0;
    int input = get_int("Input number: ");
    while(input)
    {
        if(input & 1)
            count_ones++;
        input >>= 1;
    }
    printf("Output: %d", count_ones);
}
void flip_number()
{
    int input = get_int("Input number: ");
    printf("Input: %X\n", input);
    printf("Output: %X\n", ~input);
}
void high_other_set_bit()
{
    int input= get_int("Input number: ");
    int index=0;
    if (input <0) return;
    while(!(input & 1))
    {
        index++;
        input >>=1;
    }
    printf("Output is %d", index);
}
void set_nth_bit()
{
    int input= get_int("Input number: ");
    int nth_bit = get_int("Input nth bit to set: ");
    int out = input | (1 << nth_bit);
    printf("Number befor setting %d bit: %d (in decimal)\n", nth_bit, input);
    printf("Number after setting %d bit: %d (in decimal)\n", nth_bit, out);
}
void get_nth_bit()
{
    int input= get_int("Please enter a number: ");
    int nth_bit = get_int("Enter nth bit(0-31): ");
    int bitstatus = (input >> nth_bit) & 1;

    printf("The %d bit of %d is set to %d", nth_bit, input, bitstatus);
}
int get_int(char *ins){
    int input;
    printf("%s",ins);
    fscanf(stdin, "%d", &input);
    return input;
}
void msb_check()
{
    int num,msb;
    //Read a number from user
    printf("Please enter a number: ");
    scanf("%d", &num);

    msb = 1 << (sizeof(char)*8 -1);
    printf("msb = %X\n", msb);

    if(num & msb)
        printf("MSB of %d is 1", num);
    else    
        printf("MSB of %d is 0", num);
    
}