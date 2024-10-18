
# Pointer
Con trỏ là một biến chứa địa chỉ của một biến khác.

Syntax:
```
int a = 10;
int *ptr = &a;// phải sử dụng & để gán địa chỉ của biến a cho con trỏ ptr.
```
Kích thước của con trỏ sẽ phụ thuộc vào kiến trúc máy tính, trình biên dịch (64 bit thì kích thước là 8 Byte, 32bit thì 4 Byte).

# Các kiểu con trỏ
## Void Pointer
Đây là con trỏ có kiểu void, có thể trỏ đến bất kì địa chỉ của biến mà không cần biết kiểu dữ liệu của biến đó. Tuy nhiên muốn lấy giá trị của con trỏ này thì phải ép kiểu dữ liệu cho nó.
```
int main()
{
    void *voidPtr;
    int a = 10;
    float b = 5.5;
    char c = 'C';

    voidPtr = &a;
    printf("Gia tri cua a: %d", *(int *)voidPtr);
    return 0;
}
```
## Function Pointer
Con trỏ hàm là con trỏ trỏ tới địa chỉ của hàm, có thể trỏ đến nhiều hàm nhưng phải cùng kiểu trả về và các đối số cũng phải cùng kiểu dữ liệu.
```
int Tru(int a, int b)
{
    return a - b;
}
int Cong(int a, int b)
{
    return a + b;
}
int main()
{
    int a = 10;
    int b = 5;
    int (* funcPtr)(int, int);
    funcPtr = &Tru;
    printf("A - B = %d\n",funcPtr(a,b));

    funcPtr = &Cong;
    printf("A + B = %d\n",funcPtr(a,b));

    return 0;
}
```
## Pointer to Constant,Constant to Pointer
### Pointer to Constant
Là một con trỏ mà giá trị của biến trỏ tới không thể bị thay đổi thông qua con trỏ. Nhưng con trỏ này vẫn có thể thay đổi (người lập trình có thể gán địa chỉ khác cho con trỏ này).Có thể hiểu là con trỏ này chỉ có quyền read giá trị của biến mà con trỏ này trỏ vào.
```
int main()
{
    int a = 10;
    int b = 5;

    const int* ptr;
    ptr = &a;
    printf("Gia tri a: %d\n", *ptr);
    ptr = &b;
    printf("Gia tri b: %d\n", *ptr);
    return 0;
}
```
### Constant to Pointer
Là con trỏ chỉ có thể trỏ tới địa chỉ mà được gán vào lúc khởi tạo, không thể gán địa chỉ khác. Có thể thay đổi giá trị của biến mà con trỏ này trỏ vào (trừ khi biến đó là 1 const).
```
int main()
{
    int a = 10;
    int const* ptr = &a; // khi khởi tạo phải gán địa chỉ cho con trỏ này vì đây là 1 biến Constant
    
    int  b = 5;
    ptr = &b; // sẽ xảy ra lỗi
}
```
## Pointer to Pointer

Là con trỏ trỏ tới địa chỉ 1 con trỏ khác đang trỏ đến 1 biến khác. Có thể truy cập vào biến mà con trỏ cấp 1 đang trỏ đến.
```
int main()
{
    int a = 10;
    int *ptr1 = &a;
    int **ptr2 = &ptr;
    printf("gia tri cua a: %dd", **ptr2);
    return 0;
}
```
## NULL Pointer

Con trỏ Null để biểu hiện con trỏ đang không trỏ đến vị trí bất kỳ nào.

```
int main()
{
    int *ptr = NULL;
    if(ptr == NULL) printf("ptr đang trỏ tới NULL");
    return 0;
}
```
