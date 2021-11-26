<h1 align="center">
F T _ P R I N T F
</h1>

___

## :memo: **About**

_This project is pretty straightforward, you have to recode printf. You will learn what is and how to implement variadic functions. Once you validate it, you will reuse this function in your future projects._.

### *Objectives*  
> + Unix logic

### *Skills*
> + Rigor
> + Algorithms & AI

For detailed information, refer to the [**subject of this project**](https://github.com/CherdantsevIlya/ft_printf/blob/master/en.subject.pdf).

___

## 🚀 **Description**

To print some message, use the line below as a prototype

```c
    ft_printf(" ... %[flags][width][.precision][length]type", ... );
```

All that is in brackets is:

+ Before % : some text (it may not be there)
+ After % : format
+ Atfer , : arguments

format is divided into the following categories:

### **Type**

| TYPE | DESCRIPTION |
|--------|--------|
| d / i | Signed decimal integer |
| u | Unsigned decimal integer	|
| x | Unsigned hexadecimal integer (lowercase) |
| X | Unsigned hexadecimal integer (uppercase) |
| c | Single character |
| s | String of characters |
| p | Pointer address |
| % | A % followed by another % character will write a single % |

### **Flags**

| FLAGS | DESCRIPTION |
|--------|--------|
| 0 | The value should be zero padded. For d, i, u, x, and X conversions, the converted value is padded on the left with zeros rather than blanks. If the 0 and - flags both appear, the 0 flag is ignored. If a precision is given with a numeric conversion (d, i, u, x, and X), the 0 flag is ignored. For other conversions, the behavior is undefined. |
| - | The converted value is to be left adjusted on the field boundary. (The default is right justification.)	|

### **Width**

An optional decimal digit string (with nonzero first digit) specifying a minimum field width. If the converted value has fewer characters than the field width, it will be padded with spaces on the left (or right, if the left-adjustment flag has been given). Instead of a decimal digit string one may write "*" or "*m$" (for some decimal integer m) to specify that the field width is given in the next argument, or in the m-th argument, respectively, which must be of type int. A negative field width is taken as a '-' flag followed by a positive field width. In no case does a nonexistent or small field width cause truncation of a field; if the result of a conversion is wider than the field width, the field is expanded to contain the conversion result.

### **Precision**

An optional precision, in the form of a period ('.') followed by an optional decimal digit string. Instead of a decimal digit string one may write "*" or "*m$" (for some decimal integer m) to specify that the precision is given in the next argument, or in the m-th argument, respectively, which must be of type int. If the precision is given as just '.', or the precision is negative, the precision is taken to be zero. This gives the minimum number of digits to appear for d, i, u, x, and X conversions, or the maximum number of characters to be printed from a string for s.

### **Length**

(Bonus part)

____

### **Example**

```c
#include "ft_printf.h"

int main()
{
    ft_printf("1. print int (%%d): %d\n", 1234);
    ft_printf("2. print int (%%i): %.6d\n", 1234);
    ft_printf("3. print unsigned int (%%u): %u\n", -1234);
    ft_printf("4. print unsigned hex (%%x): %#x\n", 1234);
    ft_printf("5. print unsigned hex (%%X): %#X\n", -1234);
    ft_printf("6. print char (%%c): %c\n", 70);
    ft_printf("7. print char * (%%s): %s\n", "Hello, world!");
    ft_printf("8. print char * (%%s): %15s\n", "Hello, world!");
    ft_printf("9. print pointer (%%p): %p\n", 4321);
    return 0;
}
```

### **Output**

```
    1. print int (%d): 1234
    2. print int (%i): 001234
    3. Print unsigned int (%u): 4294966062
    4. print unsigned hex (%x): 0x4d2
    5. print unsigned hex (%X): 0XFFFFFB2E
    6. print char (%c): F
    7. print char * (%s): Hello, world!
    8. print char * (%s):   Hello, world!
    9. print pointer (%p): 0x10e1
```
___

## 🧨 **Tests**
+ [ft_printf test](https://github.com/cacharle/ft_printf_test)
+ [42TESTER-PRINTF](https://github.com/Mazoise/42TESTERS-PRINTF)
+ [PFT](https://github.com/gavinfielder/pft)
+ [PRINTF_LOVER_V2](https://github.com/charMstr/printf_lover_v2)
