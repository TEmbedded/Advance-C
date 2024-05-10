ADVANCE C
# *LESSION 1: Compiler - Macro*
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

## *I. Stdarg:*
Cung cấp các phương thức để làm việc với các hàm có số lượng input parameter không cố định. Các hàm như `printf` và `scanf` là ví dụ điển hình.

Cú pháp thư viện: `#include<stdarg.h>`.

- `va_list`: là một kiểu dữ liệu để đại diện cho danh sách các đối số biến đổi.

- `va_start`: Bắt đầu một danh sách đối số biến đổi. Nó cần được gọi trước khi truy cập các đối số biến đổi đầu tiên.

- `va_arg`: Truy cập một đối số trong danh sách. Hàm này nhận một đối số của kiểu được xác định bởi tham số thứ hai.

- `va_end`: Kết thúc việc sử dụng danh sách đối số biến đổi. Nó cần được gọi trước khi kết thúc hàm.

>Ví dụ 1:
```c
#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...) {
    va_list args;// đây là 1 kiểu dữ liệu ,để lưu 1 địa chỉ 
    va_start(args, count); //Khởi tạo va_list và đọc giá trị ở sau cout 
	//trong trường hợp này là 4....

    int result = 0;
    for (int i = 0; i < count; i++) {
        result += va_arg(args, int);// ép kiểu dữ liệu 
    }	

    va_end(args); //thu hồi vùng nhớ của va_list args;

    return result;
}

int main() {
    printf("Sum: %d\n", sum(4, 1, 2, 3, 4));// sum:10 , vì chỉ đọc giá trị phía sau cout truyền vào là 4 tham số
    return 0; 
```
>Ví dụ 2:
```c
#include <stdio.h>
#include <stdarg.h>


typedef struct Data
{
    int x;
    double y;
} Data;

void display(int count, ...) {

    va_list args;

    va_start(args, count);

    int result = 0;

    for (int i = 0; i < count; i++)
    {
        Data tmp = va_arg(args,Data);
        printf("Data.x at %d is: %d\n", i,tmp.x);
        printf("Data.y at %d is: %f\n", i,tmp.y);
    }
   

    va_end(args);


}

int main() {

    display(3, (Data){2,5.0} , (Data){10,57.0}, (Data){29,36.0});
    return 0;
}
```
>Ví dụ 3: Bài toán thực tế, làm sao viết 1 hàm chung , để phù hợp với bất kỳ số lượng tham số đầu vào. Cảm biến độ ẩm 2 tham số , nhiệt độ 3 tham số >> cần 1 hàm phù hợp
```c
#include <stdio.h>
#include <stdarg.h>

typedef enum {
    TEMPERATURE_SENSOR, 
    PRESSURE_SENSOR // áp suất
} SensorType;

void processSensorData(SensorType type, ...) {
    va_list args;
    va_start(args, type);

    switch (type) {
        case TEMPERATURE_SENSOR: {// khi có bài toán lựa chọn thì dùng switch..case
            int numArgs = va_arg(args, int);
            int sensorId = va_arg(args, int);
            float temperature = va_arg(args, double); // float được promote thành double
            printf("Temperature Sensor ID: %d, Reading: %.2f degrees\n", sensorId, temperature);
            if (numArgs > 2) {
                // Xử lý thêm tham số nếu có
                char* additionalInfo = va_arg(args, char*);
                printf("Additional Info: %s\n", additionalInfo);
            }
            break;
        }
        case PRESSURE_SENSOR: {
            int numArgs = va_arg(args, int);
            int sensorId = va_arg(args, int);
            int pressure = va_arg(args, int);
            printf("Pressure Sensor ID: %d, Reading: %d Pa\n", sensorId, pressure);
            if (numArgs > 2) {
                // Xử lý thêm tham số nếu có
                char* unit = va_arg(args, char*);
                printf("Unit: %s\n", unit);
            }
            break;
        }
    }

    va_end(args);
}

int main() {
    processSensorData(TEMPERATURE_SENSOR, 3, 1, 36.5, "Room Temperature");
    processSensorData(PRESSURE_SENSOR, 2, 2, 101325);
    return 0;
}
```
## *II. Assent*
### Thư viện Assent: `include <assent.h>`

- Cung cấp macro assert. Macro này được sử dụng để kiểm tra một điều kiện:

  - Nếu điều kiện đúng (true), không có gì xảy ra và chương trình tiếp tục thực thi.
  - Nếu điều kiện sai (false), chương trình dừng lại và thông báo một thông điệp lỗi.
- Dùng trong debug, dùng #define NDEBUG để tắt debug
- Tóm lại, assert thường được sử dụng để kiểm tra điều kiện và kết thúc chương trình khi có lỗi.
>Ví dụ:
```c
#include <assert.h>
#define ASSERT_IN_RANGE(val, min, max) assert((val) >= (min) && (val) <= (max))

void setLevel(int level) {
    ASSERT_IN_RANGE(level, 1, 31);// Thiết lập cấp độ
}
int main(){
	int x=45;
	int day =5;
	ASSERT_IN_RANGE	(day,0,31);// day <31 thì sẽ thực hiện code tiếp theo
	//sai thì thông báo 
	printf("day bang %d\n",day);

}
```
---
# *LESSION 3: POINTER*
## *Pointer*
 - Là 1 biến không lưu giá trị bình thường, nó lưu địa chỉ.
 - kiểu dữ liệu con trỏ phải trùng kiểu dữ liệu biến nó trỏ tới.
 - Thông qua con trỏ có thể thay đổi giá trị tại biến mà nó trỏ tới.
 - Cách khai báo con trỏ: <kiểu dữ liệu> * <tên biến>
 > Ví dụ:
```c
 int main(){
	int a =10;
	int *ptr =&a;//&lấy địa chỉ
	return 0;
 }
```
 - Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch: 
    - Môi trường Windows 32 bit: 4 bytes
    - Môi trường Windows 64 bit: 8 bytes
```c
int main()
{
    int *ptr;
    printf("Size of pointer: %d bytes\n", sizeof(ptr));    
    return 0;

}
```
### Ví dụ Ứng dụng để truyền tham trị .
```c
#include <stdio.h>

// Hàm swap: Đổi giá trị của hai biến sử dụng con trỏ
void swap(int *a, int *b)
{
    int tmp = *a;   // Lưu giá trị của biến a vào biến tạm thời tmp
    *a = *b;        // Gán giá trị của biến b cho biến a
    *b = tmp;       // Gán giá trị của biến tạm thời tmp (ban đầu là giá trị của a) cho biến b
}

int main()
{
    int a = 10, b = 20; // Khai báo và khởi tạo hai biến a và b

    swap(&a, &b);       // Gọi hàm swap để đổi giá trị của a và b

    // In ra giá trị của a và b sau khi đã đổi giá trị
    printf("value a is: %d\n", a);
    printf("value b is: %d\n", b);

    return 0; // Kết thúc chương trình
}
```
## Con trỏ NULL: 
*Con trỏ NULL là con trỏ lưu địa chỉ 0x00000000. Tức địa chỉ bộ nhớ 0, có ý nghĩa đặc biệt, cho biết con trỏ không trỏ vào đâu cả.*
### Ví dụ:
```
 int *p2; //con trỏ chưa khởi tạo, vẫn trỏ đến một vùng nhớ nào đó không xác định
 int *p3 = NULL; //con trỏ null không trỏ đến vùng nhớ nào
 int *p4 = null; // Lỗi "null" phải viết in hoa
 ```

## *Con trỏ đến con trỏ(pointer to pointer): *
Con trỏ này dùng để lưu địa chỉ của một con trỏ khác.
Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép thay đổi giá trị của con trỏ gốc. Cấp bậc này có thể hữu ích trong nhiều tình huống, đặc biệt là khi bạn làm việc với các hàm cần thay đổi giá trị của con trỏ.
### Ví dụ:
```c
#include <stdio.h>

int main() {
    int value = 42;
    int *ptr1 = &value;  // Con trỏ thường trỏ đến một biến

    int **ptr2 = &ptr1;  // Con trỏ đến con trỏ

    /*
        **ptr2 = &ptr1
        ptr2 = &ptr1;
        *ptr2 = ptr1 = &value;
        **ptr2 = *ptr1 = value
    */

    printf("address of value: %p\n", &value); //địa chỉ của value
    printf("value of ptr1: %p\n", ptr1);     //địa chỉ của value

    printf("address of ptr1: %p\n", &ptr1);  //địa chỉ của ptr1
    printf("value of ptr2: %p\n", ptr2);     //địa chỉ của ptr1|ptr2 = &ptr1;

    printf("dereference ptr2 first time: %p\n", *ptr2); // địa chỉ của value|*ptr2 = ptr1 = &value;

    printf("dereference ptr2 second time: %d\n", **ptr2); // giá trị của value| **ptr2 = *ptr1 = value;

    return 0;
}
```
## *Void Pointer*
Con trỏ void trong C và C++ là con trỏ có thể trỏ đến các đối tượng thuộc bất kỳ kiểu dữ liệu nào (không cần biết kiểu dữ liệu con trỏ trỏ tới). Con trỏ void được khai báo bằng kiểu `void *ptr`
### Ví dụ:
```c
/* 
Trong ví dụ này, chúng ta có một con trỏ void ptr được gán địa chỉ của các biến có kiểu dữ liệu khác nhau (int, float và char). 
** cần ép kiểu thích hợp khi lấy giá trị mà con trỏ trỏ tới
 */
#include <stdio.h>

int main() {
    int num = 10;
    float pi = 3.14;
    char letter = 'A';

    // Declaring void pointer
    void *ptr;

    // Pointing void pointer to different types of data
    ptr = &num;
    printf("Value pointed by void pointer (integer): %d\n", *(int*)ptr);

    ptr = &pi;
    printf("Value pointed by void pointer (float): %.2f\n", *(float*)ptr);

    ptr = &letter;
    printf("Value pointed by void pointer (character): %c\n", *(char*)ptr);

    return 0;
}
```

## *Con trỏ hàm (Pointer to function)*
*Con trỏ hàm là một biến lưu giữ địa chỉ của một hàm. Có nghĩa nó trỏ đến vùng nhớ chứa mã máy của hàm được định nghĩa*.
- Có thể sử dụng con trỏ hàm để truy cập và gọi hàm từ một địa chỉ bộ nhớ cụ thể.
- Cú pháp: kiểu dữ liệu (*tên con trỏ hàm)(kieu du liêu1, kieu du liêu2)
- kiểu dữ liệu phải trùng với kiểu dữ liệu của hàm trỏ tới.
Nếu cần truyền tham số thì kiểu dữ liệu 1, 2 phải trùng với hàm truyền vào.
### Ví dụ minh họa:
```c
#include <stdio.h>
int add(int a, int b) {
    return a + b;
}
int main() {
    int (*sum)(int, int); // Khai báo con trỏ hàm
    sum = add;            // Gán địa chỉ của hàm add cho con trỏ sum

    printf("Sum: %d\n", sum(3, 4)); // Gọi hàm thông qua con trỏ hàm

    return 0;
}
```
Ứng dụng : Con trỏ hàm thường được sử dụng trong các tình huống như việc truyền hàm làm đối số cho một hàm khác (callbacks), xử lý sự kiện, hoặc khi cần chọn lựa hàm để gọi dựa trên điều kiện trong thời gian chạy.
### Ví dụ:
```c
#include <stdio.h>
// Hàm mẫu 1
void greetEnglish() {
    printf("Hello!\n");
}

// Hàm mẫu 2
void greetFrench() {
    printf("Bonjour!\n");
}

int main() {
    // Khai báo con trỏ hàm
    void (*ptrToGreet)();

    // Gán địa chỉ của hàm greetEnglish cho con trỏ hàm
    ptrToGreet = greetEnglish;

    // Gọi hàm thông qua con trỏ hàm
    (*ptrToGreet)();  // In ra: Hello!

    // Gán địa chỉ của hàm greetFrench cho con trỏ hàm
    ptrToGreet = greetFrench;

    // Gọi hàm thông qua con trỏ hàm
    (*ptrToGreet)();  // In ra: Bonjour!

    return 0;
}
```
## *Hàm con trỏ (Function of pointer)*
 - Hàm con trỏ là một hàm mà tham số của nó là một con trỏ hàm.
 - Điều này cho phép bạn truyền một hàm cụ thể vào một hàm khác để thực hiện các tác vụ động linh hoạt.
### Ví dụ:
 ```c
 #include <stdio.h>
// Hàm con trỏ làm tham số cho một hàm khác
void processNumbers(int (*operation)(int, int), int a, int b) {
    int result = operation(a, b);
    printf("Result: %d\n", result);
}

// Đặt hàm add truyền vào giá trị cho con trỏ hàm
int add(int a, int b) {
    return a + b;
}

int main() {
    int a = 10, b = 5;
    processNumbers(add, a, b);

    return 0;
}
```
## *Con trỏ hằng- Pointer to Constant*
- Khai báo:const　<Kiểu dữ liệu>　* <Tên con trỏ>;
- Không thể thay đổi giá trị tại biến mà nó đang trỏ đến.
- Ứng dụng:Trong bài toán thao tác với mảng, lý do arr trả về địa chỉ ,là 1 con trỏ , có thể thay đổi giá trị thông qua địa chỉ .
### Ví dụ:
```c
 int *ptr;// con trỏ thường
 const int *ptr1;//con trỏ hằng
 x=5;
 ptr=&x;
 *ptr=10;
 printf("x la %d",x);//x =10
 *ptr1 =10;//lỗi , vì nó làm thay đổi giá trị biến
```
## *Hằng con trỏ- Constant Pointer*
Khai báo: `int *const const_ptr = &value;`
Đặc điểm:
- Khi khai báo hằng con trỏ cần khởi tạo giá trị địa chỉ cho nó.
- Khi hằng con trỏ đã trỏ đến 1 địa chỉ nào rồi,nó không thể trỏ tới bất kỳ 1 địa chỉ nào khác.
- Có thể thay đổi được giá trị tại địa chỉ đã khởi gán ban đầu.
### Ví dụ:
```c
#include <stdio.h>
#include <stdlib.h>
int main() {    
	int value = 5;    
	int test = 15;    
	int *const const_ptr = &value;   
	printf("value: %d\n", *const_ptr);    
	*const_ptr = 7   
	printf("value: %d\n", *const_ptr);   
	const_ptr = &test; // LỖI vì đã cố định vào value
	return 0;
}
```
---
# *LESSION 4: Memory layout*

**Phân vùng bộ nhớ trên RAM(Memory layout):**
- Chương trình main.exe trên window hoặc main.hex với VĐK (lưu ở bộ nhớ SSD hoặc FLASH).
- Khi nhấn run chương trình trên window hoặc cấp nguồn cho vi điều khiển thì những chương trình này sẽ được copy vào bộ nhớ RAM để thực thi.

| Stack |   
|:-----:|
|   ↓   |
|   ↑   |	
|  Heap |
|  Bss(Uninitialized data)  |
|  Data(Initialized data)   |
|  Text |
## ***Text:*** 
Quyền truy cập chỉ có thể Read( không thay đổi)
	- Lưu các hằng số: Ví dụ `const int x =2` 
	- Kích thước là cố định
	- Nó chưa lệnh thực thi: Mã assembly...
## ***Data (Initialized data segment): Dữ liệu Đã Khởi Tạo*** 
Quyền truy cập Read-Write. Tức là có thể đọc và thay đổi giá trị của biến.
	- Chứa biến toàn cục đã được khởi tạo hoặc biến static khác 0: `int a=1, int b=2;`
	- Tất cả các biến sẽ được thu hồi sau khi chương trình kết thúc.
	- Kích thước có thể thay đổi.
### Ví dụ:
```c
#include <stdio.h>

int a = 10;
double d = 20.5;

static int var = 5;

void test()
{
    static int local = 10;
}


int main(int argc, char const *argv[])
{  
    a = 15;
    d = 25.7;
    var = 12;
    printf("a: %d\n", a);
    printf("d: %f\n", d);
    printf("var: %d\n", var);



    return 0;
}
```
## ***Bss (Uninitialized data): Dữ liệu chưa Khởi Tạo*** 
Quyền truy cập Read-Write
	- Chứa biến toàn cục và biến static chưa khởi tạo, hoặc giá trị khởi tạo bằng 0: `int a=0, int b;`
	- Tất cả các biến sẽ được thu hồi sau khi chương trình kết thúc.
	- Kích thước có thể thay đổi
### Ví dụ:
```c
#include <stdio.h>


typedef struct 
{
    int x;
    int y;
} Point_Data;


int a = 0;
int b;

static int global = 0;
static int global_2;

static Point_Data p1 = {5,7};



void test()
{
    static int local = 0;
    static int local_2;
}

int main() {

    
    printf("a: %d\n", a);
    printf("global: %d\n", global);
   

    
    
    return 0;
}
```
## ***Stack:*** 
Quyền truy cập là Read-Write.
	- Chứa các biến cục bộ, tham số truyền vào.
	- Các tham số truyền vào và các giá trị trả về từ hàm.
	- Sau khi ra khỏi hàm, sẽ thu hồi vùng nhớ.
### ví dụ:
```c
#include <stdio.h>

void test()
{
    int test = 0;
    test = 5;
    printf("test: %d\n",test);
}

int sum(int a, int b)
{
    int c = a + b;
    printf("sum: %d\n",c);
    return c;
}



int main() {

    sum(3,5);
    /*
        0x01
        0x02
        0x03
    */
   test();
   /*
    int test = 0; // 0x01
   */


    
    return 0;
}
```
## ***Heap:*** 
 Quyền truy cập là Read-Write.
 - Được sử dụng để cấp phát bộ nhớ động trong quá trình thực thi chương trình như: Malloc, Calloc, Realloc,...
 - Kích thước không cố định.
 - Điều này cho phép chương trình tạo ra và giải phóng bộ nhớ theo nhu cầu khi gọi hàm `free(.)` trong C hoặc `Delete(.)` trong C++, thích ứng với sự biến đổi của dữ liệu trong quá trình chạy.


## So sánh Stack và Heap?
### Bộ nhớ: 
Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.
- Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
- Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C)
### Kích thước vùng nhớ:
- Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành.
- Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.
### Đặc điểm vùng nhớ
- Stack: 
    - Vùng nhớ Stack được quản lý bởi hệ điều hành, 
	- Dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình.
- Heap: 
	-  Kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu,
	- Dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ. 
## Các cách sử dụng malloc, calloc, realloc, free:
### ***Malloc:*** 
Cấp phát bộ nhớ động mỗi phần tử, không khởi tạo giá trị, trả về con trỏ NULL khi cấp phát thành công.
### ***Calloc:*** 
Cấp phát bộ nhớ động và khởi tạo cho các phần tử là 0, trả về con trỏ NULL khi cấp phát thành công.
- Vậy `Malloc` sẽ nhanh hơn `Calloc`
### ***Realloc:*** 
Thay đổi kích thước bộ nhớ của bộ nhớ đã được cấp phát trước đó của Malloc và Calloc, trả về con trỏ NULL khi thay đổi thành công.
#### Ví dụ realloc:
```C
void* realloc(void* ptr, size_t size);
```
- ***Free:*** Giải phóng bộ nhớ đã được cấp phát bằng Malloc, Calloc, Realloc sau khi sử dụng xong, không có trả về.
```C
void free(void* ptr);
```
### Ví dụ 1:
```c
int main() {
int *arr_malloc, *arr_calloc;
size_t size = 5;

// Sử dụng malloc
arr_malloc = (int*)malloc(size * sizeof(int));

// Sử dụng calloc
arr_calloc = (int*)calloc(size, sizeof(int));

// Sử dụng Realloc
arr_malloc = (int*)realloc(arr_malloc, sizeof(int) * 7); 
// size arr_malloc lúc này là 7

// Giải phóng bộ nhớ
free(arr_malloc);
free(arr_calloc);

return 0;
}
```
### Ví dụ 2:

```C
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{  
    int soluongkytu = 0;
    char* ten = (char*) malloc(sizeof(char) * soluongkytu)
    for (int i = 0; i < 3; i++)
    {
        printf("Nhap so luong ky tu trong ten: \n");
        scanf("%d", &soluongkytu);
        ten = realloc(ten, sizeof(char) * soluongkytu);
        printf("Nhap ten cua ban: \n");
        scanf("%s", ten);
        printf("Hello %s\n", ten);
    }

}

```


## Lưu ý: 
- Việc tự động dọn vùng nhớ còn tùy thuộc vào trình biên dịch trung gian.
- Vấn đề lỗi xảy ra đối với vùng nhớ Stack: Bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,..
> Ví dụ về tràn bộ nhớ stack với hàm đệ quy vô hạn:
```C
	int foo(int x){
		printf("De quy khong gioi han\n");
		return foo(x);
	}
```
- Vấn đề lỗi xảy ra đối với vùng nhớ Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow). Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.
> Ví dụ trường hợp khởi tạo vùng nhớ Heap quá lớn:
```C 
	int *A = (int *)malloc(18446744073709551615); 
```

#### Ví dụ realloc:
```C
void* realloc(void* ptr, size_t size);
```
- ***Free:*** Giải phóng bộ nhớ đã được cấp phát bằng Malloc, Calloc, Realloc sau khi sử dụng xong, không có trả về
```C
void free(void* ptr);
```
### Khác nhau của static cục bộ và static toàn cục:

- Biến static cục bộ: Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi. Biến static sẽ lưu vào vùng nhớ Data/ Bss, được giải phóng khi kết thúc chương trình.

- Ví dụ:

```C
 	#include <stdio.h>
	void printMessage() {
    static int count = 0;
    // Tăng giá trị biến mỗi lần hàm được gọi
    count++;
    printf("Count: %d\n", count);
	}

	int main() {
    // Gọi hàm có sử dụng biến static
    printMessage();//
    printMessage();

    return 0;
	}// KQ:Count: 1,Count: 2

```

- Biến static toàn cục (Static global variables): Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được.
- Ví dụ:globalStaticVar được khai báo là static và nằm trong file "File1.c". Do đó, bạn không thể trực tiếp truy cập nó từ file "File2.c", bằng extern int globalStaticVar; trong File2.c, chương trình sẽ không biên dịch được và thông báo lỗi.
- Biến static cục bộ (Static local variables): khác với biến cục bộ lưu vào vùng nhớ stack thì biến static cục bộ sẽ lưu trong vùng BSS/Data và thu hồi vùng nhớ sau khi kết thúc chương trình.

---
# LESSION 5: EXTERN - STATIC - VOLATILE - REGISTTER

## I. EXTERN
- `Entern` dùng để khai báo đối tượng cụ thể (biến, hàm) đã tồn tại ở nơi khác trong chương trình hoặc file nguồn khác mà không cấp phát bộ nhớ cho chúng giúp tránh lỗi liên kết khi có nhiều bản sao của đối tượng trong các tệp nguồn khác nhau.
- Trong khi, `#include` là chèn nội dung từ tệp tiêu đề vào vị trí hiện tại trong tệp nguồn. Thường ứng dụng trong việc tải thư viện và mã nguồn vào chương trình.
### Ví dụ:
![](image.png) ![](image-1.png)![](image-2.png)

## II.STATIC LOCAL VARIABLES
- Biến static cục bộ chỉ khởi tạo 1 lần duy nhất và tồn tại trong suốt thời gian chương trình chạy. Điều này giúp ích cho việc khi gọi hàm chứa nó nhiều lần mà không bị lỗi quay lại giá trị khởi tạo ban đầu.
- Thuộc phân vùng nhớ BSS/Data.
### Ví dụ:
![alt text](image-4.png)
## III. STATIC GLOBAL VARIABLES
- Biến static cục bộ chỉ có thể truy cập và sử dụng được trong file mã nguồn chứa nó, các file khác không có cách nào có thể truy cập hay sử dụng trực tiếp được.
### Ví dụ: file main.c chỉ sử dụng được biến static qua hàm trung gian.
![alt text](image-5.png)
- Ứng dụng: dùng để thiết kế các file thư viện.
## IV. VOLATILE
- Thông báo cho quá trình biên dịch không được tối ưu hóa biến này.
- Volatile đại diện cho các biến cố thể thay đổi bất thường mà không qua mã nguồn code.
### Ví dụ:
![](image-6.png)
## V. REGISTER
- Là từ khóa yêu cầu biến lưu vào thanh ghi (register) trong CPU. Giúp tăng tốc độ xử lý nhanh hơn với việc lưu trong bộ nhớ RAM.
### Ví dụ:
![alt text](image-7.png)

---
# LESSION 6: GOTO - SETJMP
## I. GOTO
- là một từ khóa trong ngôn ngữ lập trình C, cho phép chương trình nhảy nhảy tới 1 nhãn (Label) đã được đặt trước đó trong cùng một hàm.
### Ví dụ:
```c
#include <stdio.h>
void delay(double second)
{
    double start = 0;
    while (start < second * 6000000)
    {
        start++;
    }
    
}
// Khai báo các trạng thái đèn giao thông
typedef enum 
{
    RED,
    YELLOW,
    GREEN
} TrafficLightState;


int main() {
    
    // Ban đầu, đèn giao thông ở trạng thái đỏ
    TrafficLightState state = RED;

    // Vòng lặp vô hạn để mô phỏng đèn giao thông
    while (1) {
        switch (state) {
            case RED:
                printf("RED Light\n");
                delay(50);  // Giữ trạng thái đèn đỏ trong x giây
                
                // Chuyển đến trạng thái đèn vàng
                state = GREEN;
                goto skip_sleep;  // Nhảy qua sleep() khi chuyển trạng thái
            case YELLOW:
                printf("YELLOW Light\n");
                delay(20);  // Giữ trạng thái đèn vàng trong y giây
                
                // Chuyển đến trạng thái đèn xanh
                state = RED;
                goto skip_sleep;  // Nhảy qua sleep() khi chuyển trạng thái
            case GREEN:
                printf("GREEN Light\n");
                delay(100);  // Giữ trạng thái đèn xanh trong z giây
                
                // Chuyển đến trạng thái đèn đỏ
                state = YELLOW;
                goto skip_sleep;  // Nhảy qua sleep() khi chuyển trạng thái
        }

        // Nhãn để nhảy qua sleep() khi chuyển trạng thái
        skip_sleep:;
    }

    return 0; // Vi du nay it su dung
}
```
- Mặc dù nó cung cấp khả năng kiểm soát flow của chương trình, nhưng việc sử dụng goto thường được xem là không tốt vì nó có thể làm cho mã nguồn trở nên khó đọc và khó bảo trì.
- Matrix Led 8x8 : điều khiển mảng led (and giá trị hàng và cột )
![alt text](image-8.png)
## II. SETJMP
Setjmp.h là một thư viện trong ngôn ngữ lập trình C cung cấp 2 hàm là `setjmp` và `longjmp` dùng để xử lí ngoại lệ trong C. (so sánh với assert)
- Ngoại lệ (exception) là một sự kiện không mong muốn xảy ra trong quá trình thực thi chương trình, làm ảnh hưởng đến luồng bình thường của chương trình.

- `setjum`: sử dụng hàm để đặt một điểm trong chương trình. Nó lưu trữ trạng thái hiện tại của cá biến và các thông số của hàm gọi nó vào kiểu dữ liệu là jmp_buf. Sau khi gọi setjmp, chương trình có thể tiếp tục thực hiện và thể quay lại điểm đã đánh dấu bằng cách sử dụng longjmp.

- `longjmp`: Hàm này được sử dụng để quay lại điểm đã đánh dấu trước đó bởi setjmp. Nó khôi phục trạng thái của các biến và thông số của hàm gọi đến trạng thái đã lưu trữ trong `jmp_buf`, cho phép chương trình nhảy đến điểm đó mà không cần hoàn thành các lệnh ở giữa.
### Ví dụ:
```c
#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x) longjmp(buf, (x))


double divide(int a, int b) {
    if (b == 0) {
        THROW(1); // Mã lỗi 1 cho lỗi chia cho 0
    }
    return (double)a / b;
}

int main() {
    int a = 10;
    int b = 0;
    double result = 0.0;

    TRY {
        result = divide(a, b);
        printf("Result: %f\n", result);
    } CATCH(1) {
        printf("Error: Divide by 0!\n");
    }


    // Các xử lý khác của chương trình
    return 0;
}
```
Bài tập: https://docs.google.com/document/d/1xmmRqDHt0Ewai3tRQ-eVVE_VvHZ7kIF2GQvNv8Ayaps/edit

---
# LESSION 7: BITMASK

- NOT `~` bit: Đảo bit. Ví dụ: ~1 = 0 hoặc ~0 = 1
- AND `&` biswise: Nhân bit. 0 & 0 = 0 1 & 0 = 0 0 & 1 = 0 1 & 1 = 1
- OR `|` biswise: cộng bit. 0 & 0 = 0 1 & 0 = 1 0 & 1 = 1 1 & 1 = 1
- XOR `^` bitwise: cộng bit. 0 & 0 = 0 1 & 0 = 1 0 & 1 = 1 1 & 1 = 0

- Sift Left và Shif Right bitwise: `<<` (dịch trái) , `>>` (dịch phải).

  - Thường ta sẽ bù bit 0 nhưng khi dịch phải có 1 lưu ý đó là: phải chú ý đến bit cao nhất (bit dấu).
  - Bit dấu: nếu bit max là 1 thì đó là số âm nên khi dịch phải mình bù vào số 1.
  - Còn nếu là số dương (bit dấu = 0) thì khi dịch phải truyền vào số   
---
# LESSION 8: STRUCT AND UNION IN C
## 1. Struct

`struct` là một cấu trúc dữ liệu được sử dụng để tổ chức các biến có liên quan lại với nhau trong một khối duy nhất. Một `struct` **cho phép bạn tự định nghĩa các kiểu dữ liệu phức tạp bằng cách kết hợp nhiều kiểu dữ liệu cơ bản lại với nhau.**

```c
typedef struct <tên_struct> {
    // các thành phần (fields) của struct
    <kiểu_dữ_liệu1> <tên_biến1>;
    <kiểu_dữ_liệu2> <tên_biến2>;
    //...
}<bí danh>; // sd typedef để đặt tên cho Struct
```

Kích thước dữ liệu cơ sở tạo bởi `stuct` được xác định bằng kích thước kiểu dữ liệu lớn nhất được khởi tạo trong `struct` đó.

![image](https://github.com/hnaht1126/advanced-C/assets/152061415/47d85127-ff5f-424e-8e2b-1dbc04e942ac)

với struct trên mỗi lần quét dữ liệu sẽ tạo 4 byte dữ liệu.

Quét kích thước cơ sở -> kiểm tra kích thước -> sắp xếp dữ liệu vào ô nhớ.

Việc sắp xếp dữ liệu hợp lý giúp tôi ưu bộ nhớ, làm giảm số lượng các ô nhớ trống.

**Ứng dụng:** Tổ chức dữ liệu theo một cấu trúc nhất định để dễ dàng quản lý và thao tác với chúng.

Ứng dụng của struct trong:
json....... 
list.....

## 2. Union

`Union` là một cấu trúc dữ liệu mà kết hợp nhiều kiểu dữ liệu khác nhau vào cùng một vùng nhớ. Điều này có nghĩa là mỗi thành viên của `union chia sẻ cùng một địa chỉ bắt đầu`, do đó chỉ một thành viên của `union` có thể lưu trữ giá trị tại một thời điểm.

```c

union <tên_union> {
    // các thành phần (fields) của union
    <kiểu_dữ_liệu1> <tên_biến1>;
    <kiểu_dữ_liệu2> <tên_biến2>;
    //...
};
```
**Ứng dụng:** Đọc dữ liệu cảm biến ( mỗi lần đọc 1 cảm biến rồi in dữ liệu ra -> tiết kiệm bộ nhớ ).

---
# LESSION 9: JSON
## Định nghĩa:
- JSON là viết tắt của "JavaScript Object Notation" (Định dạng đối tượng JavaScript).
- JSON là một định dạng văn bản được sử dụng để lưu trữ và truyền dữ liệu; nó được sử dụng để trao đổi dữ liệu giữa máu chủ và trình duyệt web, cũng như giữa các hệ thống khác nhau.
- JSON được biểu diễn dưới dạng các cặp key-value (khóa-giá trị) và có thể nhóm thành các đối tượng (objects) và mảng (arrays), giúp tổ chức dữ liệu một cách cấu trúc và linh hoạt, để dễ đọc và viết cho con người.
## Đặc điểm:
- Mỗi chuỗi JSON phải đặt trong cặp dấu ngoặc nhọn `{}`
- Nó sử dụng cú pháp nhẹ dựa trên cặp key: value, tương tự như các đối tượng và mảng trong JavaScript.
- Các cặp key - value ngăn cách nhau bằng dấu `,`. Giữa key và value ngăn cách nhau bằng dấu `:`.
- Định dạng của `key` mặc định là dạng `string` và trong dấu ngoặc kép.
## Các định dạng:
- Định dạng JSON_NUMBER: value là giá trị số nguyên hoặc số thực
- Định dạng JSON_BOOLEAN: value là giá trị true/ false
- Định dạng JSON_STRING: value là đối tượng thuộc kiểu dữ liệu string
Ví dụ:
```c
{"name":"John"}
```
- Định dạng JSON_NULL: value là giá trị không tồn tại hoặc không xác định. được biểu diễn bởi từ khóa `null`.
Ví dụ:
```c
{"middlename":null}
```
- Định dạng JSON_ARRAY: value là các giá trị đặt trong dấu ngoặc vuông `[]`
Ví dụ: 
```c 
{
    "grades": [85, 90, 78]
}
```
- Định dạng JSON_OBJECT: Tập hợp các cặp key – value được biểu diễn trong dấu ngoặc nhọn `{}`. Mỗi cặp key – value ngăn cách nhau bởi dấu `,`. 
Ví dụ :
```c

const char* json_str = "{"


       "\"ThuongTru\":{“

                          "\"Duong\":\"73 Ba Huyen Thanh Quan\",“

                          "\"Phuong_Xa\":\"Phuong 6\",“

                          "\"Tinh_TP\":\"Ho Chi Minh\“,"
                          "}"
"}"
```
## Ví dụ mẫu:
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <stdbool.h>




typedef enum {
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;


typedef struct JsonValue {
    JsonType type;
    union {
        int boolean;
        double number;
        char *string;
        struct {
            struct JsonValue *values;
            size_t count;
        } array;
        struct {
            char **keys;
            struct JsonValue *values;
            size_t count;
        } object;
    } value;
} JsonValue;



JsonValue *parse_json(const char **json);

void free_json_value(JsonValue *json_value);

static void skip_whitespace(const char **json) {
    while (isspace(**json)) {
        (*json)++;
    }
}

JsonValue *parse_null(const char **json) {
    skip_whitespace(json);
    if (strncmp(*json, "null", 4) == 0) {
        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
        value->type = JSON_NULL;
        *json += 4;
        return value;
    }
    return NULL;
}

JsonValue *parse_boolean(const char **json) {
    skip_whitespace(json);
    JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
    if (strncmp(*json, "true", 4) == 0) {
        value->type = JSON_BOOLEAN;
        value->value.boolean = true;
        *json += 4;
    } else if (strncmp(*json, "false", 5) == 0) {
        value->type = JSON_BOOLEAN;
        value->value.boolean = false;
        *json += 5;
    } else {
        free(value);
        return NULL;
    }
    return value;
}

JsonValue *parse_number(const char **json) {
    skip_whitespace(json);
    char *end;


    double num = strtod(*json, &end);
    if (end != *json) {
        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
        value->type = JSON_NUMBER;
        value->value.number = num;
        *json = end;
        return value;
    }
    return NULL;
}

JsonValue *parse_string(const char **json) {
    skip_whitespace(json);


    if (**json == '\"') {
        (*json)++;
        const char *start = *json;
        while (**json != '\"' && **json != '\0') {
            (*json)++;
        }
        if (**json == '\"') {
            size_t length = *json - start; // 3
            char *str = (char *) malloc((length + 1) * sizeof(char));
            strncpy(str, start, length);
            str[length] = '\0';


            JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
            value->type = JSON_STRING;
            value->value.string = str;
            (*json)++;
            return value;
        }
    }
    return NULL;
}



JsonValue *parse_array(const char **json) {
    skip_whitespace(json);
    if (**json == '[') {
        (*json)++;
        skip_whitespace(json);

        JsonValue *array_value = (JsonValue *)malloc(sizeof(JsonValue));
        array_value->type = JSON_ARRAY;
        array_value->value.array.count = 0;
        array_value->value.array.values = NULL;

        /*
        double arr[2] = {};
        arr[0] = 30;
        arr[1] = 70;
        */

        while (**json != ']' && **json != '\0') {
            JsonValue *element = parse_json(json); // 70
            if (element) {
                array_value->value.array.count++;
                array_value->value.array.values = (JsonValue *)realloc(array_value->value.array.values, array_value->value.array.count * sizeof(JsonValue));
                array_value->value.array.values[array_value->value.array.count - 1] = *element;
                free(element);
            } else {
                break;
            }
            skip_whitespace(json);
            if (**json == ',') {
                (*json)++;
            }
        }
        if (**json == ']') {
            (*json)++;
            return array_value;
        } else {
            free_json_value(array_value);
            return NULL;
        }
    }
    return NULL;
}

JsonValue *parse_object(const char **json) {
    skip_whitespace(json);
    if (**json == '{') {
        (*json)++;
        skip_whitespace(json);

        JsonValue *object_value = (JsonValue *)malloc(sizeof(JsonValue));
        object_value->type = JSON_OBJECT;
        object_value->value.object.count = 0;
        object_value->value.object.keys = NULL;
        object_value->value.object.values = NULL;



        while (**json != '}' && **json != '\0') {
            JsonValue *key = parse_string(json);
            if (key) {
                skip_whitespace(json);
                if (**json == ':') {
                    (*json)++;
                    JsonValue *value = parse_json(json);
                    if (value) {
                        object_value->value.object.count++;
                        object_value->value.object.keys = (char **)realloc(object_value->value.object.keys, object_value->value.object.count * sizeof(char *));
                        object_value->value.object.keys[object_value->value.object.count - 1] = key->value.string;

                        object_value->value.object.values = (JsonValue *)realloc(object_value->value.object.values, object_value->value.object.count * sizeof(JsonValue));
                        object_value->value.object.values[object_value->value.object.count - 1] = *value;
                        free(value);
                    } else {
                        free_json_value(key);
                        break;
                    }
                } else {
                    free_json_value(key);
                    break;
                }
            } else {
                break;
            }
            skip_whitespace(json);
            if (**json == ',') {
                (*json)++;
            }
        }
        if (**json == '}') {
            (*json)++;
            return object_value;
        } else {
            free_json_value(object_value);
            return NULL;
        }
    }
    return NULL;
}


JsonValue *parse_json(const char **json) { 
    while (isspace(**json)) {
        (*json)++;
    }



    switch (**json) {
        case 'n':
            return parse_null(json);
        case 't':
        case 'f':
            return parse_boolean(json);
        case '\"':
            return parse_string(json);
        case '[':
            return parse_array(json);
        case '{':
            return parse_object(json);
        default:
            if (isdigit(**json) || **json == '-') {
                return parse_number(json);
            } else {
                // Lỗi phân tích cú pháp
                return NULL;
            }
    }
}



////////////




/////////////

void free_json_value(JsonValue *json_value) {
    if (json_value == NULL) {
        return;
    }

    switch (json_value->type) {
        case JSON_STRING:
            free(json_value->value.string);
            break;

        case JSON_ARRAY:
            for (size_t i = 0; i < json_value->value.array.count; i++) {
                free_json_value(&json_value->value.array.values[i]);
            }
            free(json_value->value.array.values);
            break;

        case JSON_OBJECT:
            for (size_t i = 0; i < json_value->value.object.count; i++) {
                free(json_value->value.object.keys[i]);
                free_json_value(&json_value->value.object.values[i]);
            }
            free(json_value->value.object.keys);
            free(json_value->value.object.values);
            break;

        default:
            break;
    }
}



void test(JsonValue* json_value){
    if (json_value != NULL && json_value->type == JSON_OBJECT) {
        // Truy cập giá trị của các trường trong đối tượng JSON
        size_t num_fields = json_value->value.object.count;
        size_t num_fields2 = json_value->value.object.values->value.object.count;
        for (size_t i = 0; i < num_fields; ++i) {

            char* key = json_value->value.object.keys[i];
            JsonValue* value = &json_value->value.object.values[i];

            JsonType type = (int)(json_value->value.object.values[i].type);


            if(type == JSON_STRING){
                printf("%s: %s\n", key, value->value.string);
            }

            if(type == JSON_NUMBER){
                printf("%s: %f\n", key, value->value.number);
            }

            if(type == JSON_BOOLEAN){
                printf("%s: %s\n", key, value->value.boolean ? "True":"False");
            }

            if(type == JSON_OBJECT){
                printf("%s: \n", key);
                test(value);
            }

            if(type == JSON_ARRAY){
                printf("%s: ", key);
                for (int i = 0; i < value->value.array.count; i++)
                {
                   test(value->value.array.values + i);
                } 
                printf("\n");
            }

  
        }

     
    }
    else 
    {
            if(json_value->type == JSON_STRING){
                printf("%s ", json_value->value.string);
            }

            if(json_value->type == JSON_NUMBER){
                printf("%f ", json_value->value.number);
            }

            if(json_value->type == JSON_BOOLEAN){
                printf("%s ", json_value->value.boolean ? "True":"False");
            }

            if(json_value->type == JSON_OBJECT){
                printf("%s: \n", json_value->value.object.keys);
                test(json_value->value.object.values);
                           
            }
    }

}




int main(int argc, char const *argv[])
{
     // Chuỗi JSON đầu vào
    
    const char* json_str = "{"
                        "\"1001\":{"
                          "\"SoPhong\":3,"
                          "\"NguoiThue\":{"
                            "\"Ten\":\"Nguyen Van A\","
                            "\"CCCD\":\"1920517781\","
                            "\"Tuoi\":26,"
                            "\"ThuongTru\":{"
                              "\"Duong\":\"73 Ba Huyen Thanh Quan\","
                              "\"Phuong_Xa\":\"Phuong 6\","
                              "\"Tinh_TP\":\"Ho Chi Minh\""
                            "}"
                          "},"
                          "\"SoNguoiO\":{"
                            "\"1\":\"Nguyen Van A\","
                            "\"2\":\"Nguyen Van B\","
                            "\"3\":\"Nguyen Van C\""
                          "},"
                          "\"TienDien\": [24, 56, 98],"
                          "\"TienNuoc\":30.000"
                        "},"
                        "\"1002\":{"
                          "\"SoPhong\":5,"
                          "\"NguoiThue\":{"
                            "\"Ten\":\"Phan Hoang Trung\","
                            "\"CCCD\":\"012345678912\","
                            "\"Tuoi\":24,"
                            "\"ThuongTru\":{"
                              "\"Duong\":\"53 Le Dai Hanh\","
                              "\"Phuong_Xa\":\"Phuong 11\","
                              "\"Tinh_TP\":\"Ho Chi Minh\""
                            "}"
                          "},"
                          "\"SoNguoiO\":{"
                            "\"1\":\"Phan Van Nhat\","
                            "\"2\":\"Phan Van Nhi\","
                            "\"2\":\"Phan Van Tam\","
                            "\"3\":\"Phan Van Tu\""
                          "},"
                          "\"TienDien\":23.000,"
                          "\"TienNuoc\":40.000"
                        "}"
                      "}";
    

    // Phân tích cú pháp chuỗi JSON
    JsonValue* json_value = parse_json(&json_str);



   test(json_value);

    // Kiểm tra kết quả phân tích cú pháp

       // Giải phóng bộ nhớ được cấp phát cho JsonValue
    free_json_value(json_value);
    
    

        //printf("test = %x", '\"');

       // hienthi(5);
    
    return 0;
}
```
---
# LESSION 10: LINKED LIST
 - Danh sách liên kết ( Linked list): là một cấu trúc dữ liệu trong lập trình dùng để tổ chức và lưu trữ dữ liệu. Một linked list bao gồm một chuỗi các node (nút) liên kết với nhau. Mỗi node chứa một giá trị dữ liệu và một con trỏ (pointer) đến địa chỉ node tiếp theo trong chuỗi. Con trỏ của node cuối cùng trỏ đến địa chỉ Null báo hiệu kết thúc chuỗi.
 - Các thao tác với Linked list:
   - Thêm một node vào cuối chuỗi (push_back)
   - Thêm một node vào đầu chuỗi (push_front)
   - Xóa một node vào cuối chuỗi (pop_back)
   - Xóa một node vào đầu chuỗi (pop_front)
   - Thêm một node vào vị trí bất kỳ trong chuỗi (insert)
   - Xóa một node vào vị trí bất kỳ trong chuỗi (delete)
   - Lấy giá trị ở vị trí đầu hoặc cuối trong chuỗi
   - Lấy kích thước của chuỗi
   - Kiểm tra chuỗi có rổng hay không
## Ví dụ:
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Khai báo một node*/
typedef struct node
{
    int value; // data input node
    struct node* next; // address of next node in linked list
    
}node;
/*
node *createNode(int value); 
void push_back(node** array, int value); // them 1 node vao phia cuoi
void push_front(node **array, int value); // them 1 node vao phia truoc
void pop_back(node **array); // xoa node cuoi
void pop_front(node **array); // xoa node dau tien
int front(node *array); // lay gia tri cua node dau tien
int back(node *array); // lay gia tri cua node cuoi cung
void insert(node **array, int value, int pos); // them 1 node vao mot vi tri bat ky
void deletee(node **array, int pos); // xoa 1 node tai mot vi tri bat ky
int size(node **array); // lay kich thuoc cua list
int get(node **array, int pos); 
bool empty(node **array); // kiem tra list co rong hay khong

*/
 //Function to create a new node
node *createNode(int value){
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}
/*
Add a new node input the front position of linkedlist
*/
void push_front(node **array, int value){
    node* temp; // Create a new node with the provided value
    temp = createNode(value);
    if(*array = NULL){
        array = temp;
    }
    else{
        temp->next = *array; 
        *array = temp;
    }
}

// Add a new node input the last position of linkedlist
void push_back(node** array, int value)
{
    node* temp;
    temp = createNode(value);
    if (*array = NULL){ //if linkedlist doesn't any node yet
        array= temp;
    }
    else{               // if linkedlist has some node
        node* p = *array; // use p instead of array because we using pointer, use array will change the structure of linked list
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;     //check next node until it's a last node
        }
        p->next = temp; // assign next of previous node equal address of the new created node 
    }
    
} 
/* ---------------------------------------------- */  
/*----- Delete the last node of the Linkedlist----*/ 
/* ---------------------------------------------- */
void pop_back(node **array){
    if ( array == NULL) return; // if linkedlist haven't any node yet
    node* p, * temp;
    p = *array;
    if(p->next = NULL){ //if linkedlist have an only node
        temp = p->next;
    }
    else // if linkedlist have more than a node
    {
        while (p->next->next != NULL)     // free the last node in the list
        {
        p = p->next;
        }
        temp = p->next;
        p->next = NULL;
    }
    free(temp);
}
/* ---------------------------------------------- */  
/*---- Delete the front node of the Linkedlist----*/ 
/* ---------------------------------------------- */
void pop_front(node **array){
    if ( array == NULL) return; // if linkedlist haven't any node yet

    node* temp = *array; 
    *array = (*array)->next; 
    free(temp); 
}
/* ---------------------------------------------- */  
/*-- return the first value of the Linked list----*/ 
/* ---------------------------------------------- */
int front(node *array){
    int value = array->value;
    return value;
}
/* ---------------------------------------------- */  
/*--- return the last value of the Linked list----*/ 
/* ---------------------------------------------- */
int back(node *array){
    while (array->next != NULL)
    {
        array = array->next;
    }
    int value = array->value;
    return value;
}
/* ---------------------------------------------- */  
/*- Add a node in any position of the Linked list-*/ 
/* ---------------------------------------------- */
void insert(node** array, int value, int pos){
     node* tempt;
     tempt = createNode(value);
     if(array == NULL){
        return tempt;
     }
    // thêm vào vị trí đầu tiên trong linked list
    if (pos = 0){
        tempt->next = *array;
        *array = tempt;
    }
     
     int i = 0;
     node* p = *array;
     
     while (p->next != NULL && i < pos -1)
     {
        p = p->next;
        i++;
     }
     tempt->next = p->next; //thay con trỏ null bằng địa chỉ con trỏ của node pos -1 
     p->next = tempt; // thay con trỏ địa chỉ pos -1 bằng địa chỉ tempt
}   
/* ------------------------------------------------- */  
/*- Delete a node in any position of the Linked list-*/ 
/* ------------------------------------------------- */
void delete(node **array, int pos){
    // có hàm kiểm tra linkedlist có rỗng không rồi
    int count = 0;
    node* temp = *array;
    node* prev= NULL;

    while (temp->next != NULL && count < pos)
     {
        prev = temp;
        temp = temp->next;
        count++;
     }
     if(temp == NULL){ // If it can't find temp which we want delete
        printf ( " Position need to delete haven't exist.\n");
        return;
     } 
    prev->next = temp->next;
    free(temp);
} 
/* ------------------------------------------------- */  
/*-------- To get size of the Linked list------------*/ 
/* ------------------------------------------------- */
int size(node* array){   
    int count = 1;
    if( array == NULL){
        count = 0;
        return count;
    }
    while ( array != NULL)
    {
        count++;
        array = array->next;
    }
    return count;   
}
/* -----------------------------------------------------*/  
/*--- Return value at the position of the Linked list---*/ 
/* -----------------------------------------------------*/
int get(node **array, int pos){
    int i = 0;
    node* p = * array;
    while(p->next != NULL && pos != i){
        p = p->next;
        i++;
    }
    int value = p->value;
    return value;
}
/* --------------------------------------------------*/  
/*--- Check if linked list is empty or not-----------*/ 
/* --------------------------------------------------*/
bool empty(node *array){
    if(array == NULL){
        return true;
    }else{
        return false;
    }
}

int main()
{
    node* arr = NULL;
    push_back(&arr, 2);
    push_back(&arr, 7);
    push_back(&arr, 4);
    push_back(&arr, 5);
    push_back(&arr, 3);
    push_back(&arr, 10);

    printf("Value test: %d\n", get(arr, 2));
    printf("Value test: %d\n", get(arr, 0));
    printf("Value test: %d\n", get(arr, 5));


	return 0;
}
```
---
# LESSION 11: STACK - QUEUE
## I. STACK:
- Stack (ngăn xếp) là một cấu trúc dữ liệu trong đó việc chèn một phần tử hay loại bỏ một phần tử được diễn ra tại một đầu, được biểu diễn bởi một đỉnh của ngăn xếp. Nó tuân theo nguyên tắc Last in First Out - Có nghĩa là phần tử được chèn cuối cùng vào ngăn xếp sẽ được loại bỏ đầu tiên.

- Các hoạt động liên quan đến ngăn xếp bao gồm:

  - Push: Thêm một phần tử vào đầu ngăn xếp.

  - Pop: Loại bỏ phần tử trên cùng khỏi ngăn xếp.

  - Peek hoặc Top: Lấy giá trị phần tử ở trên cùng.

  - IsEmpty: Kiểm tra xem ngăn xếp có trống không.

  - Size: Xác định số lượng phần tử trong ngăn xếp.
- Các phép toán hoạt động như sau:
  - Sử dụng một con trỏ được gọi là TOP để theo dõi phần tử đỉnh trong ngăn xếp.
  - Khi khởi tạo ngăn xếp, ta đặt giá trị của nó là -1 để kiểm tra xem ngăn xếp có trống không bằng cách so sánh TOP == -1.
  - Khi đẩy một phần tử, ta tăng giá trị của TOP và đặt phần tử mới vào vị trí mà TOP đang chỉ đến.
  - Khi lấy ra một phần tử, ta trả về phần tử mà TOP đang chỉ đến và giảm giá trị của nó.
  - Trước khi đẩy, ta kiểm tra xem ngăn xếp đã đầy chưa.
  - Trước khi lấy ra, ta kiểm tra xem ngăn xếp đã trống không chưa.
  ![STACK](image-9.png)
- Giải thích hàm:
  - 1, peek()
  ```c
  		int peek() {
		   return stack[top];
		}
  ```
  - 2, isempty() and isfull():
  ```c
  		bool isempty() {
		   if(top == -1)
		      return true;
		   else
		      return false;
		}
		
		bool isfull() {
		   if(top == MAXSIZE)
		      return true;
		   else
		      return false;
		}
   ```
   - 3, push()
   ```c
   
		void push(int data) {
		   if(!isFull()) {
		      top = top + 1;   
		      stack[top] = data;
		   } else {
		      printf("Stack overflow\n");
		   }
		}
    ```
    - 4, pop()
    ```c
    int pop(int data) {
		   if(!isempty()) {
		      data = stack[top];
		      top = top - 1;   
		      return data;
		   } else {
		      printf("Stack underflow\n");
		   }
		}
    ```
### Ví dụ 1:
```c
	#include <stdio.h>
	#include <stdlib.h>
	
	typedef struct Stack {
	    int* items; // mảng để lưu giá trị của từng ô
	    int size;
	    int top;
	} Stack;
	
	void initialize( Stack *stack, int size) {
	    stack->items = (int*) malloc(sizeof(int) * size);
	    stack->size = size;
	    stack->top = -1;
	}
	
	int is_empty( Stack stack) {
	    return stack.top == -1;
	}
	
	int is_full( Stack stack) {
	    return stack.top == stack.size - 1;
	}
	
	void push( Stack *stack, int value) {
	    if (!is_full(*stack)) {
	        stack->items[++stack->top] = value;
	    } else {
	        printf("Stack overflow\n");
	    }
	}
	
	int pop( Stack *stack) {
	    if (!is_empty(*stack)) {
	        return stack->items[stack->top--];
	    } else {
	        printf("Stack underflow\n");
	        return -1;
	    }
	}
	
	int top( Stack stack) {
	    if (!is_empty(stack)) {
	        return stack.items[stack.top];
	    } else {
	        printf("Stack is empty\n");
	        return -1;
	    }
	}
	
	int main() {
	    Stack stack1;
	    initialize(&stack1, 5);
	
	
	    push(&stack1, 10);
	    push(&stack1, 20);
	    push(&stack1, 30);
	    push(&stack1, 40);
	    push(&stack1, 50);
	    push(&stack1, 60);
	
	    printf("Top element: %d\n", top(stack1)); // 50
	
	    printf("Pop element: %d\n", pop(&stack1)); // 50
	    printf("Pop element: %d\n", pop(&stack1)); // 40
	
	    printf("Top element: %d\n", top(stack1)); // 30
	
	    return 0;
	}
```
### Ví dụ 2:
```c
	#include <stdio.h>
	#include <stdlib.h>

	void push();
	void pop();
	void display();

	struct node {
	    int data;
	    struct node* next;
	};
	
	struct node* temp; // Variable to store the top of the stack
	
	int main() {
	    printf("LINKED LIST IMPLEMENTATION USING STACKS\n\n");
	    do {
	        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
	        printf("Enter your choice:");
	        int choice; scanf("%d", &choice);
	        
	        switch (choice) {
	            case 1:
	                push();
	                break;
	            case 2:
	                pop();
	                break;
	            case 3:
	                display();
	                break;
	            case 4:
	                exit(0);
	                break;
	            default:
	                printf("Please re-enter!\n");
	                break;
	        }
	    } while (choice != 4);
	    return 0;
	}
	
	void push() {
	    int data;
	    struct node* pointer = (struct node*)malloc(sizeof(struct node));
	    
	    if (pointer == NULL) printf("Stack overflow\n");
	    else {
	        printf("Enter the element to be inserted: ");
	        scanf("%d", &data);
	        
	        if (temp == NULL) {
	            pointer->data = data;
	            pointer->next = NULL;
	            temp = pointer;
	        } else {
	            pointer->data = data;
	            pointer->next = temp;
	            temp = pointer;
	        }
	    }
	}
	
	void pop() {
	    int item;
	    struct node* pointer;
	    
	    if (temp == NULL) {
	        printf("Stack underflow\n");
	    }
	    else {
	        item = temp->data;
	        pointer = temp;
	        temp = temp->next;
	        free(pointer);
	        printf("The deleted item is %d\n", item);
	    }
	}
	
	void display() {
	    struct node* pointer;
	    pointer = temp;
	    
	    if (pointer == NULL) {
	        printf("Stack underflow\n");
	    }
	    else {
	        printf("The elements of the stack are:\n");
	        
	        while (pointer != NULL) {
	            printf("%d\n", pointer->data);
	            pointer = pointer->next;
	        }
	    }
	}
```

## II. QUEUE
![hàng đợi](image-11.png)
- QUEUE là cấu trúc dữ liệu tuân theo nguyên tắc " First In, First Out ". Nghĩa là, phần tử đầu tiên thêm vào hàng đợi sẽ là phần tử đầu tiên được lấy ra.

![alt text](image-12.png)
- Các hoạt động liên quan đến hàng đợi bao gồm:
  - Enqueue: Thêm một phần tử vào cuối hàng đợi.
  - Dequeue: Loại bỏ một phần tử ở đầu hàng đợi.
  - Peek or Front: Giá trị phần tử đầu hàng đợi.
  - IsEmpty: Kiểm tra xem hàng đợi có trống không.
  - Size: Xác định số lượng phần tử trong hàng đợi.
  - IsFull: Kiểm tra xem hàng đợi có đầy không.


- Các phép toán trên hàng đợi hoạt động như sau:
  - Hai con trỏ FRONT và REAR
  - FRONT theo dõi phần tử đầu tiên của hàng đợi
  - REAR theo dõi phần tử cuối cùng của hàng đợi
  - Ban đầu, đặt giá trị của FRONT và REAR là -1
### Ví dụ:
```c
#include <stdio.h>
#include <stdlib.h>
	
	
typedef struct Queue {
	int* items; // mảng để lưu giá trị của từng ô
	int size;
	int front, rear; // để xác định phần tử nào đứng đầu, phần tử nào đứng cuối hàng
} Queue;
	
void initialize(Queue *queue, int size) {
	queue->items = (int*) malloc(sizeof(int)* size);
	queue->front = -1;
	queue->rear = -1;
	queue->size = size;
}
	
int is_empty(Queue queue) {
	return queue.front == -1;
}
	
int is_full(Queue queue) {
	return (queue.rear + 1) % queue.size == queue.front;
}
	
void enqueue(Queue *queue, int value) {
	if (!is_full(*queue)) {
	    if (is_empty(*queue)) {
	        queue->front = queue->rear = 0;
	    } else {
	        queue->rear = (queue->rear + 1) % queue->size;
	    }
	    queue->items[queue->rear] = value;
	} else {
	    printf("Queue overflow\n");
	}
}
	
int dequeue(Queue *queue) {
	if (!is_empty(*queue)) {
	    int dequeued_value = queue->items[queue->front];
	    if (queue->front == queue->rear) {
	        queue->front = queue->rear = -1;
	    } else {
	        queue->front = (queue->front + 1) % queue->size;
	    }
	    return dequeued_value;
	} else {
	    printf("Queue underflow\n");
	    return -1;
	}
}
	
int front(Queue queue) {
	if (!is_empty(queue)) {
	     return queue.items[queue.front];
	} else {
	    printf("Queue is empty\n");
	    return -1;
	}
}
	
int main() {
	Queue queue;
	initialize(&queue, 3);
	
	enqueue(&queue, 10);
	enqueue(&queue, 20);
	enqueue(&queue, 30);
	
	printf("Front element: %d\n", front(queue));
	
	printf("Dequeue element: %d\n", dequeue(&queue));
	printf("Dequeue element: %d\n", dequeue(&queue));
	
	printf("Front element: %d\n", front(queue));
	
	enqueue(&queue, 40);
	enqueue(&queue, 50);
	printf("Dequeue element: %d\n", dequeue(&queue));
	printf("Front element: %d\n", front(queue));
	
	return 0;
}
```

---
# LESSION 12: BINARY SEARCH - FILE OPERATIONS - CODE STANDARD

## I. BINARY SEARCH
- Binary search là thuật toán tìm kiếm dữ liệu của phần tử trên mảng đã được sắp xếp theo thứ tự tăng dần (hoặc giảm dần). Ý tưởng là so sánh giá trị cần tìm với giá trị ở giữa mảng, và dựa vào kết quả so sánh để xác định giá trị cần tìm ở nữa trên hay nữa dưới của mảng. 
- Nếu giá trị cần tìm bằng giá trị tại vị trí giữa được so sánh, kết thúc thuật toán. Nếu khác, dựa vào thứ tự sắp xếp có thể loại đi một nữa của mảng. Tiếp tục, so sánh như trên cho đến khi tìm thấy phần tử cần tìm hoặc thăm hết phần tử nhưng không tìm ra phần tử cần tìm đó.
### Ví dụ:
```c
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Kiểm tra xem giá trị ở giữa có bằng giá trị cần tìm không
        if (arr[mid] == target)
            return mid;

        // Nếu giá trị ở giữa lớn hơn target, tìm ở nửa trái của mảng
        if (arr[mid] > target)
            high = mid - 1;

        // Nếu giá trị ở giữa nhỏ hơn target, tìm ở nửa phải của mảng
        else
            low = mid + 1;
    }

    // Trả về -1 nếu không tìm thấy giá trị cần tìm
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    printf("nhap gia tri can tim\n");
    scanf("%d",&target);

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        printf("Giá trị %d được tìm thấy tại vị trí %d.\n", target, result);
    else
        printf("Giá trị %d không tồn tại trong mảng.\n", target);

    return 0;
}
```
## II. FILE OPERATIONS
- File operations là các hoạt động thao tác với tập tin trên hệ thống máy tính. Các hoạt động này bao gồm đọc từ tập tin, ghi vào tập tin, xóa tập tin, di chuyển hoặc đổi tên tập tin, và kiểm tra sự tồn tại của tập tin.
- Các hoạt động tập tin có thể liên quan đến việc nhập xuất dữ liệu, lưu trữ cấu trúc dữ liệu, cài đặt các cơ chế lưu trữ dữ liệu như cơ sở dữ liệu, và nhiều ứng dụng khác. Điều này rất quan trọng trong việc xử lý thông tin trong môi trường máy tính.
### File CSV (Comma-Separated Values)
- File CSV ( Comma - Separated Values) là một loại định dạng tập tin dữ liệu được sử dụng để lưu trữ và truyền tải dữ liệu dưới dạng văn bản. Trong đó, mỗi dòng của tập tin biểu diễn một bản ghi dữ liệu, và mỗi trường dữ liệu của bản ghi được phân tách bằng dấu phẩy `,`.
Ví dụ về một tập tin CSV:
```c
Name, Age, City
John, 25, New York
Alice, 30, London
Bob, 28, Paris
```
- Các hàm để thao tác file:
  - fscanf (): Sử dụng chuỗi được định dạng và danh sách đối số biến để lấy đầu vào từ một File
  - fgets(): Copy nội dung trong File vào mảng dùng để lưu trữ với tối đa số lượng phần tử của mảng hoặc tới khi gặp ký tự xuống dòng.
  - fgetc(): Lấy giá trị tại địa chỉ hiện tại của file, sau đó di chuyển tới địa chỉ tiếp theo. Kiểu trả về là char
  - fread(): Đọc một số lượng byte được chỉ định từ File .bin
  - fprintf():Ghi chuỗi vào File, và có thể thêm danh sách các đối số
  - fputs() :Ghi chuỗi vào File
  - fputc() :Ghi một ký tự vào File
  - fwrite() :Ghi một số byte được chỉ định vào File .bin
  - fclose(): Đóng File đã mở
  - feof(): Để kiểm tra địa chỉ hiện tại có phải ký tự cuối cùng của File hay chưa

### Ví dụ thêm dữ liệu vào file example.csv:
```c
#include <stdio.h>
void addRow(const char* filename, const char* uid, const char* room, const char* name) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("Không thể mở file %s để ghi dữ liệu.\n", filename);
        return;
    }
    fprintf(file, "%s,%s,%s\n", uid, room, name);

    fclose(file);
}
int main() {
    addRow("example.csv", "4", "D404", "A Johson");
    addRow("example.csv", "5", "D424", "Ale ");
    addRow("example.csv", "6", "D425", "Alice ");
    return 0;
}
```
## CODE STANDARD
https://hala.edu.vn/c-co-ban/cac_quy_tac_ve_dat_ten_theo_tieu_chuan_autosar_c_coding_guidelines/






