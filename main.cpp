#include <iostream>
// 万能引用
using namespace std;
template<typename T>
constexpr T&& forward (T& arg) noexcept{
    return static_cast<T&&>(arg);
}

template<typename T>
struct base{
    template<typename U>
    void init(){
        cout << "init\n";
    }
};
/**
base<T> 是一个依赖类型名称（依赖于模板参数 T）
init<int> 是一个依赖模板名称（因为 init 是从属于 base<T> 的模板）
 * */
template <typename T>
struct parser : base<T>{
    void parse(){
        base<T>::template init<int>();
        cout << "parse\n";
    }
};

template<unsigned N>
struct factorial{
    //当实例化一个类模板特化时，编译器需要检查所有声明的有效性，即使这些声明最终不会被使用。
    static constexpr int value = N * factorial<N - 1> :: value;
};
template<>
struct factorial<0>{
    // 这里不能对1 做特化 因为主模板会有factor<0>
    static constexpr int value = 1;
};



int main() {
    // 只有右值引用的右值引用才是右值引用 其他均为左值引用
    int a = 10;
//    ::forward<int>(a); // 返回int&
//    ::forward<int&>(a); // 返回 int&
//    ::forward<int&&>(a); // 返回右值引用
    int res = factorial<5>::value;
    cout << res <<endl;
    return 0;
}
