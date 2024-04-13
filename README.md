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







