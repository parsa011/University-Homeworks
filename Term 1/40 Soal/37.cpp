#include "global.h"

void get_array(int *buf, int len)
{
    int temp;
    for (int i = 0; i < len; i++) {
        cout << "Element " << i + 1 << " : ";
        cin >> buf[i];
    }
}

int index_of(int *buf, int len, int target)
{
    for (int i = 0; i < len; i++) {
        if (buf[i] == target)
            return i;
    }
    return -1;
}

void shift_left(int *buf, int len, int start)
{
    for (; start < len - 1; start++) {
        buf[start] = buf[start + 1];
    }
}

void delete_member(int *buf, int &len, int target)
{
    int index = index_of(buf, len, target);
    shift_left(buf, len, index);
    buf = (int *)realloc(buf, sizeof(int) * --len);
}

void show_array(int *buf, int len)
{
    for (int i = 0; i < len; i++) {
        cout << buf[i] << endl;
    }
}

int main()
{
    int len;
    cout << "Enter Array Len : ";
    cin >> len;
    
    int *A = new int(len);
    get_array(A, len);
    
    int to_delete;
    cout << "Enter Number To delete : ";
    cin >> to_delete;
    
    delete_member(A, len, to_delete);
    show_array(A, len);
    free(A);
    return 0;
}
