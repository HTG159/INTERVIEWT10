
## Goto-setjump.h
# Goto
Goto là một từ khóa trong C cho phép chương trình nhảy đến một label đã được đặt trước đó trong cùng một hàm.
```
int main()
{
    label:
    if(...)
    goto label;

    return 0;
}
```
# Setjump.h
Setjump.h là một thư viện trong C, cung cấp 2 hàm chính là setjmp và longjmp. Có thể nhảy tới vị trí đặt label như goto nhưng có thể nhảy ra khỏi hàm. Hai hàm này thường được sử dụng để xử lý ngoại lệ trong C.
```
#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x) longjmp(buf, (x))
```

