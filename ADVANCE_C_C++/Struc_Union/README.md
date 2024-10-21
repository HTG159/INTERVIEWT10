
# Struct_Union
## Struct
### Định nghĩa
Struct là 1 cấu trúc dữ liệu của ngôn ngữ lập trình c, giúp lập trình viên tự định nghĩa một kiểu dữ liệu mới với các các biến có kiểu dữ liệu khác nhau.
Khai báo:
```
struct tenStruct {
    kieuDuLieu1 ThanhVien1;
    kieuDuLieu2 thanhVien2;
    ...
}
```

với typedef:
```
typedef struct {
    kieuDuLieu1 thanhVien1;
    kieuDuLieu2 thanhVien2;
    ...
} tenStruct;
```

Khai báo biến
```
struct tenStruct bien1;
struct tenStruct *bien2; // con trỏ 
//khai báo biến với typedef 
tenStruct bien1;
tenStruct *bien2;
```
Truy cập các thành phần của struct:
```
tenThanhVien.tenBientenBien = 1;
tenThanhVien->tenBien = 1; //con trỏ struct truy cập bằng ->
```

Kích thước của struct:

Bằng tổng kích thước các thành viên với padding cho phù hợp với yêu cầu căn chỉnh  của cpu:

ví dụ 1:
```
struct Example {
    uint8_t a;  // 1 byte  
    uint16_t b; // 2 byte
    uint32_t c; // 4 byte
}; // Kích thước: 12
```
![image](https://github.com/user-attachments/assets/6f3a7e4b-f15b-4526-845a-3916be0b74ff)

ví dụ 2:
```
struct Example {
    uint8_t var1[9];  // 1 byte   = 4 + 4 + 1 + 3(padding)
    uint32_t var2[2]; // 4 byte   = 4 + 4 
    uint16_t var3[10]; // 2 byte  = 4 + 4 + 4 + 4 + 4
}; // Kích thước: 40
```
## Union
Union là kiểu dữ liệu tương tự struct nhưng chứa chung địa chỉ. Chỉ có thể tương tác 1 thành viên trong 1 thời điểm.

Khai báo:
```
union tenUnion {
    kieuDuLieu1 tenThanhPhan1;
    kieuDuLieu2 tenThanhPhan2;
};
```
kích thước dữ liệu:
```
union Data {
    uint8_t var1[3];  // 1 byte     3 byte + 1 (padding)
    uint16_t var2[10]; // 2 byte    4 + 4 + 4 + 4 + 4
    uint32_t var3[4]; // 4 byte     4 + 4 + 4 + 4
};// Kích thước : 20 byte
```
ví dụ 1:
```
union Data{
    uint8_t a;
    uint32_t b;
    uint16_t c;
}
// gán giá trị lần lượt cho biến 
Data.a = 20;
Data.b = 15;
Data.c = 50;
printf("%d",Data.a);
printf("%d",Data.bb);
printf("%d",Data.c);
// kết quả in ra sẽ là 50 50 50. vì chung 1 địa chỉ nên khi gán giá trị sẽ dẫn tới biến sẽ được gán giá trị mới nhất.
```
ví dụ 2:
```
union Data {
    uint8_t var1;    
    uint32_t var2; 
    uint16_t var3; 
};
nếu gán giá trị 4294967296 (2 mũ 32 ) vào biến sẽ ảnh hưởng đến kết quả in ra của các biến khác.
Data.var2 = 4294967296;

printf("%d",Data.a);// in ra 255 vì kích thước biến là 1 byte
printf("%d",Data.bb);// in ra 4294967296 vì kích thước là 4 byte
printf("%d",Data.c);// in ra 65536 vì kích thước là 2 bytebyte
```
