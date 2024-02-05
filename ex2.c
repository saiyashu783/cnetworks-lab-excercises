/* Write a Program to implement the data link layer farming methods such as  
i) Character stuffing ii) bit stuffing. */
#include<stdio.h>
#include<string.h>

void char_stuffing(char *data, int data_len, char *stuffed_data){
    int i;
    int stuffed_len = 0;
    char flag_byte = '<';
    char escape_byte = '@';
    if(data_len == 0){
        return;
    }
    stuffed_data[stuffed_len] = flag_byte;
    (stuffed_len)++;
    for (i=0; i<data_len ; i++){
        if(data[i] ==  flag_byte || data[i] == escape_byte){
            stuffed_data[stuffed_len] = escape_byte;
            (stuffed_len)++;
        }
        stuffed_data[stuffed_len] = data[i];
        (stuffed_len)++;
    }
    stuffed_data[stuffed_len] = flag_byte;
}

/*void bit_stuffing(char *data, int data_len, char *stuffed_data_bit, int *stuffed_bit_len){

}*/

int main(){
    char data[] = "hello@my@name@is@venkata@sai";
    int data_len = strlen(data);
    char stuffed_data_char[100];
    char_stuffing(data, data_len, stuffed_data_char);
    printf("stuffed data: %s\n", stuffed_data_char);
    /*char stuffed_data_bit[100];
    int stuffed_bit_len;
    bit_stuffing(data, data_len, stuffed_data_bit, stuffed_bit_len);
    printf("Bit Stuffed Data :%s \n",stuffed_data_bit);*/
    return 0;
}