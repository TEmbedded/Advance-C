ADVANCE C
# **LESSION 1: Compiler - Macro**
---
## **I. Compiler:**
### ***Compiler:*** 
 *Chuyển đổi ngôn ngữ bậc cao (NNBC)(C/C++, Pascal, Java,C#,...) sang ngôn ngữ máy để máy tính có thể hiểu và thực thi.*


### Quá trình *Compiler* được chia làm 4 giai đoạn chính:
![](https://cdn.nerdyelectronics.com/wp-content/webp-express/webp-images/uploads/2017/07/GCC_CompilationProcess.png.webp)
    - Giai đoạn tiền xử lý (Pre - processor)
    - Giai đoạn dịch NNBC sang Asembly (Compiler)
    - Giai đoạn dịch Asembly sang ngôn ngữ máy (Asembler)
    - Giai đoạn liên kết (Linker)
#### *1. Giai đoạn tiền xử lý - Preprocessor:*
- Thực hiện định nghĩa Macro (#define)
- Chèn nội dung của các file header (#include).
- Xóa bỏ tất cả chú thích, comments của chương trình

Quy trình tiền xử lý thực hiện tổng hợp dữ liệu các file và được lưu trữ trong [filename].i. bằng lệnh:
 ```
        gcc -E main.c -o main.i 
 ```
#### *2. Giai đoạn dịch NNBC sang Asembly (Compiler):*
- Phân tích cú pháp (syntax) của mã nguồn NNBC
- Chuyển chúng sang dạng mã Asembly (hợp ngữ) là NNBT gần với tập lệnh của bộ vi xử lý.

Trong giai đoạn này thực hiện biên dịch filename.i sang filename.s và tạo filename .s trong thư viện
```
        gcc -S main.i -o main.s
        gcc main.i -S -o main.s
```
#### *3. Giai đoạn dịch Asembly sang ngôn ngữ máy:*
- Dịch chương trình sang mã máy thực thi: 0 và 1
- Biên dịch tệp filename.s sang filename.o (Object) và tạo file trong hệ thống sau đó.
```
        gcc -c main.s -o main.o
```
#### *4. Giai đoạn Linker:*
- Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn ( file.c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất
- Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối giai đoạn này.
- Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.
Kết thúc quá trình tất cả các đối tượng được liên kết lại với nhau thành 1 chương trình có thể thực thi được (`file.exe`) thống nhất.
```
gcc main.o - o my_program // tong hop file.o thanh file.exe
```

## *II. Macro:*
*Macro là những thông tin được xử lý ở trong quá trình tiền xử lý (Preprocessor). Thay thế đoạn code được khai báo macro vào bất cứ chỗ nào xuất hiện macro đó. Chia làm 3 nhóm chính:*
- #include
- #define, #undef
- #if, #elif, #else, #ifdef, #ifndef

Ví dụ: #define sum(a,b) (a+b). Trong quá trình preprocesser khi gặp bất kỳ lời gọi sum(first+last) nào thì thay ngay bằng (first+last)
### #include : thêm nội dung của một file mã nguồn vào mã nguồn khác. 
#include thường được sử dụng để chèn nội dung của một file vào mã nguồn chương trình hiện tại.

Cho phép tái sử dụng mã nguồn, phân chia mã nguồn thành các tệp nhỏ hơn, và tạo ra các thư viện và module trong các dự án lớn. Ví dụ:
```c
#include <stdio.h>

int main() {
    printf("Hello, world!\n");
    return 0;
}
```
### #define : Dùng để thay thế một chuỗi mã nguồn bằng một chuỗi khác trước khi chương trình biên dịch. Được sử dụng để tạo ra các hằng số, các macro, hoặc định nghĩa các hàm ngắn gọn
> Ví dụ về sử dụng #define để định nghĩa hằng số PI:
```c
#include <stdio.h>

// Định nghĩa hằng số Pi sử dụng #define
#define PI 3.14
int main() {
    // Sử dụng hằng số Pi trong chương trình
    double radius = 5.0;
    double area = PI * radius * radius;

    printf("Radius: %.2f\n", radius);
    printf("Area of the circle: %.2f\n", area);

    return 0;
}
```
> Ví dụ về sử dụng #define để tạo ra macro:
```c
#include <stdio.h>

#define SQUARE(x) ((x) * (x))

int main() {

    
    // Sử dụng macro để tính bình phương của num
    int result = SQUARE(5);

    printf("Result is: %d\n", result);

    return 0;
}

```
SQUARE là một macro, và mỗi khi chương trình biên dịch gặp SQUARE(a), nó sẽ được thay thế bằng biểu thức ((a) * (a)).

'#define' là một công cụ trong tiền xử lý của ngôn ngữ C và C++, cho phép định nghĩa các hằng số, macro, hoặc các hàm ngắn gọn giúp làm cho mã nguồn dễ đọc và dễ bảo trì hơn.
### '#undef ' được sử dụng để hủy định nghĩa của một macro trước đó đã được định nghĩa bằng #define
> Ví dụ ứng dụng #undef để ghi đè và thay thế giá trị mới lên giá trị macro `SENSOR_DATA` trước đó trong mã nguồn:
```C
#include <stdio.h>

// Định nghĩa SENSOR_DATA 
#define SENSOR_DATA 42

int main() {
    printf("Value of MY_MACRO: %d\n", MY_MACRO);

    // Hủy định nghĩa SENSOR_DATA 
    #undef SENSOR_DATA 
    // Định nghĩa SENSOR_DATA 
    #define SENSOR_DATA 50

    printf("Value of MY_MACRO: %d\n", MY_MACRO);

    return 0;
}
```
### #if, #elif, và #else
 - #if: Chỉ thị này cho phép kiểm tra một điều kiện và biên dịch một phần của mã nguồn nếu điều kiện đó là đúng.

- #elif: Viết tắt của "else if" và được sử dụng để kiểm tra một điều kiện mới nếu điều kiện trước đó không đúng.

- #else: Được sử dụng khi không có điều kiện nào trong #if hoặc #elif trước đó là đúng.
```C
#include <iostream>
using namespace std;

const int M = 10;

int main() {
    int i = 5;
    #if M > 8
        cout << "Sum of i and i: " << i + i << endl;
    #elif M <= 8
        cout << "Product of i and i: " << i * i << endl;
    #else
        cout << "Unexpected value of M" << endl;
    #endif

    return 0;
}
//Trong trường hợp này, với M có giá trị lớn hơn 8, dòng in ra sẽ là “Sum of i and i: 10”. Nếu không, dòng in ra sẽ là “Product of i and i: 25”.
```

### #ifdef và #ifndef
*Là các directive (chỉ thị tiền xử lý) được sử dụng để kiểm tra xem một macro đã được định nghĩa trước đó chưa.*

- #ifdef dùng để kiểm tra một macro đã được định nghĩa hay chưa. Nếu macro đã được định nghĩa thì mã nguồn sau #ifdef sẽ được biên dịch.
- #ifndef dùng để kiểm tra một macro đã được định nghĩa hay chưa. Nếu macro chưa được định nghĩa thì mã nguồn sau #ifndef sẽ được biên dịch.
Ứng dụng chèn thêm thư viện nhiều lần nhưng không gặp lỗi lặp lại định nghĩa macro.
### Toán tử trong Macro
 #### Toán tử chuỗi hóa hay STRINGIZE(X) '#' cho phép chuyển đổi một tham số macro thành một chuỗi kí tự.
> Ví dụ 1: Chuyển đổi giá trị tham số của macro thành chuỗi kí tự
```c
#include <stdio.h>
#define STRINGIZE(x) #x
#define DATA 40

int main() {
    // Sử dụng toán tử #    
    printf("The value is: %s\n", STRINGIZE(DATA));
    
    return 0;
    //output: The value is: DATA
  }
```
>Ví dụ 2: Chuyển đổi giá trị tham số của macro thành chuỗi kí tự. Sau đó chuyển thành giá trị hằng số.
```C
#define STRINGIZE_RESULT(x) STRINGIZE(x) 
#define STRINGIZE(x) #x
#define DATA 40

int main() {

    // Sử dụng toán tử #
    printf("The value is: %s\n", STRINGIZE_RESULT(DATA));

    return 0; // output: The value is: 40
}
```
Toán tử ' # ' chỉ hoạt động với các tham số của macro, không thể sử dụng trực tiếp với các hằng số.
Có thể tạo ra một macro trung gian để chuyển đổi giá trị của hằng số thành chuỗi kí tự, như trong ví dụ trên.

#### Toán tử nối '## ' cho phép kết nối các token riêng biệt trong định nghĩa của một macro thành một token duy nhất. Đây là một cách tiện lợi để tạo ra các tên biến hoặc hằng số động dựa trên các thông tin khác nhau.
>Ví dụ: Kết nối các token
```c
#include <stdio.h>
#define merge(X, Y) X##Y

int main() {
    printf("%d\n", merge(20, 24));
    return 0;
}
// Output: 2024
```
#### Variadic macro
- Là một dạng macro cho phép nhận một số lượng biến tham số có thể thay đổi.
- Giúp định nghĩa các macro có thể xử lý một lượng biến đầu vào khác nhau
```
    #define MACRO_NAME(...) // Body macro
```
> Ví dụ:
```c
#include <stdio.h>

#define CASE_OPTION(number, function) case number: function(); break;
#define HANDLE_OPTION(option, ...) \
    switch (option) { \ //switch case
        __VA_ARGS__ \
        default: printf("Invalid option!\n"); \
    }
// #define PRINT_MENU(...) printf(__VA_ARGS__);

#define PRINT_MENU_ITEM(number, item) printf("%d. %s\n", number, item)

#define PRINT_MENU(...) \
        const char* items[] = {__VA_ARGS__}; \
        int n = sizeof(items) / sizeof(items[0]); \
        for (int i = 0; i < n; i++) { \
            PRINT_MENU_ITEM(i + 1, items[i]); \
        } \

void feature1() {
    printf("You chose feature 1.\n");
}

void feature2() {
    printf("You chose feature 2.\n");
}

void feature3() {
    printf("You chose feature 3.\n");
}

void feature4() {
    printf("You chose feature 4.\n");
}

int main() {
    // PRINT_MENU("1. Option 1\n2. Option 2\n3. Option 3\n4. Option 4\n5. Exit\n");

    PRINT_MENU("Option 1", "Option 2", "Option 3","Option4", "Exit");

    // Giả sử option được nhập từ người dùng
    int option;
    scanf("%d", &option);

    HANDLE_OPTION(option,
        CASE_OPTION(1, feature1)
        CASE_OPTION(2, feature2)
        CASE_OPTION(3, feature3)
        CASE_OPTION(4, feature4)
    )

    return 0;
}

```
### Câu 1. Ưu điểm của Macro là gì?
  Macro trong lập trình C mang lại nhiều lợi ích quan trọng:
 - Tăng tốc độ thực thi chương trình: Việc sử dụng macro giúp tối ưu hóa thời gian thực thi của chương trình.
 - Macro tích hợp đầy đủ câu lệnh giống như một chương trình quen thuộc (ví dụ: lệnh If, for, jmp, so sánh, biến đổi). Giúp thay đổi dữ liệu, điều kiện hoạt động và chuỗi hoạt động
 - Hỗ trợ công cụ tiện lợi giúp cho hệ thống được lập trình tối ưu nhất có thể. Phân loại Macro:
   - Macro toàn cục: Sử dụng cho ứng dụng chung, ví dụ như Start up Macro, Main Macro, Event Macro, Time Macro.
   - Macros bộ phận: Thiết lập nội trong đối tượng, không ảnh hưởng tới chương trình chính.
   - Sub-Macro: Nằm trong chương trình Macro khác và được gọi bằng lệnh gọi.

### Câu 2. Nhược điểm của Macro là gì?
Một số nhược điểm của việc sử dụng macro trong ngôn ngữ lập trình là:

- Khó phát hiện lỗi và gỡ rối: Compiler chỉ thay thế lời gọi macro bằng nội dung của chúng mà không kiểm tra tính hợp lệ của đoạn mã. Việc sử dụng macro không cẩn thận có thể dẫn đến lỗi logic hoặc lỗi biên dịch khó khăn trong quá trình phát triển chương trình1.
- Khó đọc và hiểu mã nguồn: Một số macro có tên ngắn gọn nhưng nội dung phức tạp, làm cho mã nguồn trở nên khó đọc và hiểu1.
- Không hỗ trợ xác thực chính thức: Macro không được kiểm tra tính hợp lệ trước khi biên dịch, do đó không có cơ chế xác thực chính thức. Điều này có thể gây ra lỗi không mong muốn trong chương trình.
- Tăng độ phức tạp của dữ liệu: Sử dụng quá nhiều macro có thể làm cho mã nguồn trở nên phức tạp và khó quản lý.
---

# **LESSION 2: STDARG - ASSERT**
___

