
# Memory layout

Trong ngôn ngữ lập trình C, bộ nhớ của chương trình thường được phân chia thành các phân vùng khác nhau, mỗi phân vùng có mục đích và quy tắc sử dụng riêng.

Có 5 phân vùng nhớ:

- Text Segment
- Data Segment(DS và BSS)
- Heap Segment
- Stack Segment

![image](https://github.com/user-attachments/assets/ed3be26d-848d-4b89-98be-44612301d789)

## Text Segment

Text Segment ở vùng nhớ của địa chỉ thấp nhất, đây là phần chứa các đoạn mã lệnh của chương trình, được biên dịch từ mã nguồn của chương trình và được CPU thực thi. 

Chỉ có quyền đọc và thực thi, nhưng không có quyền ghi. 

Kích thước cố định khi chương trình được biên dịch.

Lưu trữ  mã máy của các hàm và các hằng số

## Data Segment

Data Segment là một phần của bộ nhớ trong các chương trình được sử dụng để lưu trữ các biến toàn cục và hằng số. Đây là vùng nhớ cố định, không thay đổi kích thước trong suốt vòng đời của chương trình.

Quyền truy cập: Data Segment thường có quyền đọc và ghi, nghĩa là dữ liệu có thể được đọc và sửa đổi trong quá trình thực thi của chương trình.

Kích thước cố định: Kích thước của Data Segment có thể thay đổi trong quá trình thực thi của chương trình khi các biến được khởi tạo hoặc giải phóng.


### Initialized Data (DS)

Chứa giá trị của các biến toàn cục và biến tĩnh được khởi tạo với giá trị ban đầu.
Dữ liệu này được sao chép từ bộ nhớ của chương trình thực thi.

### Uninitialized Data 

Chứa giá trị mặc định của các biến toàn cục và biến tĩnh mà không cần khởi tạo giá trị ban đầu.
Dữ liệu trong phân vùng này thường được xác định bởi giá trị 0

## Heap

Heap là một phần của bộ nhớ trong mô hình bộ nhớ của một chương trình máy tính, được sử dụng để cấp phát bộ nhớ động. Các biến được cấp phát trên heap không có kích thước xác định tại thời điểm biên dịch và có thể được quản lý động trong quá trình thực thi của chương trình.
- Kích thước linh hoạt: Heap cho phép cấp phát bộ nhớ với kích thước linh hoạt và chỉ giải phóng khi chương trình yêu cầu.
- Quản lý thủ công: Bộ nhớ heap phải được cấp phát (allocate) và giải phóng (deallocate) thủ công bằng các hàm như malloc(), calloc(), và free() trong ngôn ngữ C.



| Thuộc tính             | `malloc`                                      | `calloc`                                     |
|------------------------|-----------------------------------------------|----------------------------------------------|
| **Cú pháp**            | `void* malloc(size_t size);`                  | `void* calloc(size_t num, size_t size);`     |
| **Chức năng**          | Cấp phát một khối bộ nhớ có kích thước `size` | Cấp phát nhiều khối bộ nhớ liên tiếp, mỗi khối có kích thước `size` |
| **Khởi tạo bộ nhớ**    | Không khởi tạo (bộ nhớ có thể chứa giá trị rác) | Khởi tạo tất cả các byte trong khối bộ nhớ về 0 |
| **Tốc độ**             | Nhanh hơn do không cần khởi tạo               | Chậm hơn `malloc` do cần khởi tạo về 0       |
| **Dùng trong trường hợp** | Khi không cần giá trị khởi tạo             | Khi cần bộ nhớ sạch với các giá trị 0 ban đầu |


## Stack

Stack là một vùng nhớ được cấp phát tự động và có cấu trúc LIFO (Last In First Out). Mỗi khi chương trình được gọi, thì các function frame sẽ được gọi và push vào trong stack. Function Frame có cấu trúc như ví dụ dưới đây.

![image](https://images.viblo.asia/full/a5cce181-5aab-481f-ad25-84c3ce8d2b48.png)

Khi main() được gọi, function frame của main() sẽ được push vào stack, và khi function foo() được gọi thì function frame của foo() sẽ được push vào. 

Cấu trúc của một function frame gồm bốn phần chính:
- Function Parameter
- Return Address
- Saved Previus Frame Pointer
- Local Variable.

Funtion Parameter là các tham số truyền vào.
Return Address trong ví dụ trên, Return Address trả về địa chỉ p trong hàm main() chính là Local Variable.
Saved Previus Frame Pointer trỏ vào vị trí đầu tiên của function foo() tức là kết thúc của function main()
Local Variable là các biến local của function