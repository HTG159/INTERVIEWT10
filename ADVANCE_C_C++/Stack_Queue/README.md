
## Stack-Queue

### Stack

Stack là một cấu trúc dữ liệu tuyến tính dựa trên nguyên tắc LIFO (Vào sau ra trước) trong đó việc chèn phần tử mới và xóa phần tử hiện có diễn ra ở cùng một đầu được biểu diễn là đỉnh của ngăn xếp.

Để triển khai ngăn xếp, cần phải duy trì con trỏ đến đầu ngăn xếp , đây là phần tử cuối cùng được chèn vào vì chúng ta chỉ có thể truy cập các phần tử ở đầu ngăn xếp.

![image](https://github.com/user-attachments/assets/dac33a21-2343-48dc-9da6-ecd54ddcb03f)

Các thao tác cơ bản trên cấu trúc dữ liệu ngăn xếp :

Để thực hiện thao tác trên ngăn xếp, chúng ta cần thực hiện một số thao tác nhất định.

- push() để chèn một phần tử vào ngăn xếp
- pop() để xóa một phần tử khỏi ngăn xếp
- top() Trả về phần tử trên cùng của ngăn xếp.
- isEmpty() trả về true nếu ngăn xếp rỗng, nếu không trả về false.
- isFull() trả về true nếu ngăn xếp đầy, nếu không trả về false.

Đầu tiên khởi tạo 1 Stack

```
 typedef struct Stack {
    int *items;
    int size;
    int top;
} Stack;

void initialize(Stack *stack, int size) {
    stack->items = (int *) malloc(sizeof(int) * size);
    stack->size = size;
    stack->top = -1;
} 
```

Khới tạo 1 Stack gồm:
- 1 con trỏ items để lưu giữ giá trị.
- 1 biến size kích thước của stack.
- 1 biến top để kiểm tra phần tử của stack.

Hàm kiểm tra isEmpty
```
int is_empty(Stack stack) {
    return stack.top == -1;
} 
```
Khi khởi tạo 1 Stack chưa có phần tử gì, chúng ta đã gán giá trị top là -1, nên khi gọi hàm is_empty chúng ta sẽ sử dụng phép so sánh nếu stack.top == -1 tức là chưa có phần tử gì thì sẽ trả về là true (1).

Hàm kiểm tra isFull
```
int is_full (Stack stack) {
    return stack.top == stack.size - 1;
} 
```
Khi khởi tạo stack chúng ta đã gán giá trị -1 cho top nên nếu stack có 5 phần tử thì top sẽ được gán với giá trị 5 - 1 tức là 4,
vì thế trong hàm is_full sẽ so sánh giá trị của top với size - 1, nếu giá trị của top là 4 sẽ trả về true(1) tức là stack đã full.

Hàm đẩy vào push
```
void push(Stack *stack, int value) {
    if(!is_full(*stack)) {
        stack->items[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
    }
}
```
Để có thể đẩy phần tử vào stack chúng ta cần phải check xem stack có đầy không. Gọi hàm is_full nếu return về false (0) tức là hàm không đầy và sử dụng phép toán ! để đổi thành 1 và thực hiện điều kiện if là đẩy giá trị vào items[++(stack)->top] (tức là đẩy giá trị top lên 1 trước rồi mới truy cập).Nếu hàm đã đầy thì in ra stack overflow.

Hàm lấy ra pop
```
int pop (Stack *stack) {
    if(!is_empty(*stack)) {
        return stack->items[stack->top--];
    }
    else{
        printf("Stack underflow\n");
        return -1;
    }
}
```
Để lấy phần tử ra stack thì phải check xem stack có phần tử nào không. Khi gọi hàm is_empty nếu giá trị trả về là flase (0) thì sử dụng phép toán ! để thực hiện điều kiện if trả về giá trị của stack->items[stack->top--] hiện tại rồi giảm giá trị của top.

Hàm đọc giá trị của top 
```
int top(Stack stack) {
    if(!is_empty(stack)) {
        return stack.items[stack.top];
    }
    else {
        printf("Stack is empty\n");
        return -1;
    }
}
```
Hàm này cũng sẽ kiểm tra stack có trống không. Nếu không sẽ trả về giá trị của stack.items hiện tại.

### Queue
Queue là cấu trúc hoạt động theo cơ chế FIFO, phần tử đầu tiên được thêm vào hàng đợi sẽ là phần tử đầu tiên được lấy ra.

Các thao tác cơ bản trên hàng đợi bao gồm:

- enqueue (thêm phần tử vào cuối hàng đợi)
- dequeue (lấy phần tử từ đầu hàng đợi).
- front để lấy giá trị của phần tử đứng đầu hàng đợi.

Các loại Queue:
- Linear Queue
- Circular Queue

#### Linear Queue
Khai báo:

```
typedef struct Queue {
    int* items;
    int size;
    int front, rear;
} Queue;
```
- items: Con trỏ tới mảng chứa các phần tử của Queue.
- size: Kích thước tối đa của queue.
- front: Chỉ số của phần tử đứng đầu của queue.
- rear: Chỉ số của phần tử đứng cuôi của queue.

```
Queue *initialize(int size){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->items = (int*)malloc(size * sizeof(int));
    queue->size  = size;
    queue->front = queue->rear = -1;
    return queue;
}
```
- Cấp phát động cho queue.
- Cấp phát động items với kích thước size.
- Size kính thước trước truyền vào.
- Khới tạo front và rear và gán giá trị -1, tức là hàng đợi đang trống.
- trả về địa chỉ của queue.

Hàm kiểm tra trống isEmpty:
```
int isEmpty(Queue queue){
    return (queue.front == -1 || queue.front > queue.rear);
}
```
Kiểm tra biến front có = -1 không. điều kiện front > rear có thể bỏ.

Hàm kiểm tra đầy isFull:
```
int isFull(Queue queue){
    return queue.rear == queue.size - 1;
}
```  
Hàm kiểm tra biến rear có = với size không.

Hàm thêm phần tử vào hàng đợi enqueue:
```
void enqueue(Queue *queue, int data){
    if (isFull(*queue)){
        printf("Queue is full! Cannot add more elements.\n");
    } 
    else{
        if (isEmpty(*queue)){
            queue->front = queue->rear = 0;
        }
        else{
            queue->rear++;
        }
        queue->items[queue->rear] = data;
        printf("Enqueued %d\n", data);
    }
}
```
Kiểm tra hàng đợi có full không. Nếu không thì kiể tra có trống không, nếu trống thì gán front và rear là 0 tức là phần tử đầu tiên. Còn nếu không trống thì tăng giá trị của rear lên 1 và gán phần tử cần thêm vào biến items.

Hàm đẩy phần tử ra khỏi hàng đợi dequeque:
```
int dequeue(Queue *queue){
    if (isEmpty(*queue)){
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    } 
    else{
        int value = queue->items[queue->front];
        if (queue->front == queue->rear){
            queue->front = queue->rear = -1;
        }
        else{
            queue->front++;
        }
        return value;
    }
}
```
Hàm kiểm tra hàng đợi có trống không. Nếu không trống thì sẽ lấy giá trị phần tử đầu hàng (front) sau đó kiểm tra xem front có bằng rear không tức là kiểm tra hàng đợi có hết phần tử chưa để reset hàng đợi. Nếu còn phần tử trong hàng đợi thì tăng giá trị biến front lên 1.
![image](https://github.com/user-attachments/assets/cb070d1a-1f5e-4d7c-8191-a825fc322541)

Nhược điểm của Linear Queue là: Khi giá trị rear = size -1 tức là hàng chờ đầy nhưng trước đó vẫn còn trống tức là front = 3 thì vẫn còn trống ở front = 0, 1, 2, mặc dù vẫn còn trống 3 vị trí nhưng không thể thêm phần tử mới vào hàng đợi. Phải bỏ hết tất cả phần tử ra khỏi hàng đợi mới có thể thêm phần tử mới.

#### Circular Queue

Để khắc phục nhược điểm của Linear Queue, chúng ta sẽ sử dụng Circular Queue.

Sẽ có 1 chút thay đổi ở hàm isFull:
```
bool isFull(Queue queue) {
    return (queue.rear + 1) % queue.size == queue.front;  
}
```
Nếu rear đã đạt giá trị tối đa tức là size + 1 thì khi % với size sẽ ra giá trị là 0 và nếu front = 0 tức là hàng đợi đang đầy về không có chỗ trống để thêm phần tử mới vào. Điều này giúp chúng ta biết được hàng chờ có đang trống vị trí nào không. Nếu có thì isFull sẽ trả về flase.