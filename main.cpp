#include <iostream>
// 万能引用
template<typename T>
constexpr T&& forward (T& arg) noexcept{
    return static_cast<T&&>(arg);
}

int main() {
    // 只有右值引用的右值引用才是右值引用 其他均为左值引用
    int a = 10;
    ::forward<int>(a); // 返回int&
    ::forward<int&>(a); // 返回 int&
    ::forward<int&&>(a); // 返回右值引用 
    return 0;
}
