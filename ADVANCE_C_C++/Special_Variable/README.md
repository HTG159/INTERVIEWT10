
# Extern_Static_Volatile_Register
## Extern 
Biến này sử dụng khi bạn muốn sử dụng biến hoặc hàm đã được định nghĩa ở file khác.
Biến phải được khai báo toàn cục.

ví dụ:

file 1:
```
int a = 10;  

void func() {  
    printf("Hello from func!\n");
}
```
file 2:
```
#include <stdio.h>

extern int a;  
extern void func();  // có thể khai báo extern hoặc khôngkhông

int main() {
    printf("a = %d\n", a);  
    func();  
    return 0;
}
```
Sử dụng gcc để liên kết lại với nhau:
```
gcc file1.c file2.c -o output
```
kết quả:
```
a = 10
Hello from func!
```
## Static 
### Static cục bộ
Biến sẽ chỉ được khỏi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi và được duy trì giữa các lần gọi hàm.
```
#include <stdio.h>

void increment() {
    static int count = 0;  // Biến static cục bộ
    count++;
    printf("Count = %d\n", count);
}

int main() {
    increment();  // In ra: Count = 1
    increment();  // In ra: Count = 2
    increment();  // In ra: Count = 3
    return 0;
}
```
Kết quả:
```
Count = 1
Count = 2
Count = 3
```
### Biến Static toàn cục 
Phạm vi của biến chỉ trong file được khai báo, tránh việc truy cập vào biến từ các file khác (sử dụng extern để truy cập từ file khác).
```
#include <stdio.h>

static int a = 10;  // Biến static toàn cục, chỉ có phạm vi trong file này

void display() {
    printf("a = %d\n", a);
}

int main() {
    display();  // In ra: a = 10
    return 0;
}
```
## Register 
Thông thường để thực hiện 1 phép toán: Các đối tượng sẽ được lưu trên Ram (giá trị biến, phép toán) sau đó chuyển từ Ram qua thanh ghi Register, rồi từ thanh ghi đưa vào ALU để tính toán, sau đó lại trả về Register để đưa ra Ram.

Với việc sử dụng biến Register sẽ yêu cầu trình biên dịch lưu trữ giá trị biến vào thanh ghi thay vì Ram.
```
#include <stdio.h>

int main() {
    register int i;  // Đề nghị lưu trữ biến i trong thanh ghi CPU
    for (i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
    return 0;
}
```
## Volatile 
Khi sử dụng biến Volatile để khai báo sẽ giúp trình biên dịch biết được giá trị của biến này sẽ có thể thay đổi bới luồng khác hoặc ngoại vi trên vi điều khiển, giúp trình biên dịch không tối ưu hóa biến này (đưa giá trị biến vào thanh ghi).
```
#include <stdio.h>

volatile int flag = 0; // Khai báo với từ khóa volatile

void interrupt() {
    flag = 1; // Giả sử hàm này được gọi từ một ngắt
}

int main() {
    while (flag == 0) {
        // Giả sử có các xử lý khác
    }
    printf("Flag is set!\n");

    return 0;
}
```