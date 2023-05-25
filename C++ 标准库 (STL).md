# C++ 标准库 (STL)

对 C++ 标准库的实现通常称为 STL 或标准模板库

## string

### 构造函数

```cpp
//default (1)
//默认构造函数(空串)
string();

//copy (2)	
//拷贝构造函数(必须使用引用否则引起无限递归)
string (const string& str);

//substring (3)	
//截取字符串部分拷贝
string (const string& str, size_t pos, size_t len = npos);

//from c-string (4)	
//C风格的字符数组进行赋值
string (const char* s);

//from sequence (5)	
//该字符数组前n个字符
string (const char* s, size_t n);

//fill (6)	
//赋值为n个c字符
string (size_t n, char c);

//range (7)	
template <class InputIterator>  string  (InputIterator first, InputIterator last);
```















