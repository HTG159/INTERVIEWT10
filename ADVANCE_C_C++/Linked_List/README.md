
# Linked List   

Linked list là một cấu trúc dữ liệu tuyến tính, trong đó các phần tử (node) được liên kết với nhau bằng các con trỏ. Không giống như mảng, các phần tử trong linked list không nằm liên tiếp trong bộ nhớ.

![image](https://github.com/user-attachments/assets/4e0554f7-5d9e-4d52-a2ed-c31b593c6468)

Một Node sẽ bao gồm các thành phần:
- Dữ liệu của node đó.
- Một con trỏ để trỏ đến node tiếp theo. Nếu đó là node cuối sẽ trỏ tới NULL.

con trỏ head luôn trỏ vào node đầu tiên.

### Đặc điểm của Linked List
Dễ dàng thêm, xóa phần tử mà không cần thay đổi kích thước của cả List như Mảng.

Khó truy cập phần tử hơn Mảng vì Mảng sẽ được xếp liền kề nhau.

## Triển khai code
### Khởi tạo

```
typedef struct Node {
    int data;
     struct Node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation fail!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
```
Khởi tạo Node với data và con trỏ next.

Một số thao tác với Linked list:

- Thêm phần tử đầu.
- Thêm phần tử cuối.
- Xóa phần tử đầu.
- Xóa phần tử cuối.
- Đọc phần tử đầu.
- Đọc phần tử cuối.
- Đọc phần tử bất kì.
- Thêm phần tử bất kì.
- Xóa phần tử bất kì.
- In ra danh sách.
- Giải phóng danh sách.

### Thêm phần tử đầu
```
void insertFrist(Node**head, int data){
    Node*newNode = createNode(data);
    if(newNode == NULL)
    return;
    newNode->next = *head;
    *head = newNode;
}
```
Kiểm tra nếu danh sách chưa có phần tử thì gán con trỏ next là NULL. 
### Thêm phần tử cuối
```
void insertLast(Node **head, int data){
    Node* newNode = createNode(data);
    if(newNode == NULL)
        return;
    if(*head == NULL){
        insertFrist(head,data);
        return;
    }
    Node*temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
```
cho chạy vòng lặp tới phần tử có con trỏ next là NULL thì gán con trỏ next vào node mới và node mới khi mới khởi tạo đã được trỏ vào NULL sẽ trở thành phần tử cuối của danh sách.
### Xóa phần tử đầu
```
void deleteFirst(Node**head){
    if(*head == NULL){
        printf("The List is empty!\n");
    }
    Node*temp = *head;
    *head = temp->next;
    free(temp);
}
```
Khởi tạo 1 con trỏ temp để lưu giữ địa chỉ phần tử sẽ xóa và gán địa chỉ của phần tử sau vào con trỏ head, sau đó giải phóng con trỏ temp để tránh việc quên giải phóng con trỏ đó.
### Xóa phần tử cuối
```
void deleteLast(Node **head){
    if(*head == NULL){
        printf("The List is empty!\n");
    }
    Node *temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
```
Để xóa được node cuối mà vẫn giữ được node kế cuối để trỏ next của node kế cuối vào NULL cần sử dụng vòng lặp truy cập vào con trỏ next của con trỏ next của node temp.
