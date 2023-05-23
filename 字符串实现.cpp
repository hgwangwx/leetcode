#include <iostream>
#include <cstring>


using namespace std;


class String {
public: 
    // 默认构造函数，构造一个空字符串
    String() : m_data(new char[1]), m_size(0) {
        m_data[0] = '\0';
    }

    // 拷贝构造函数
    String(const String& other) : m_data(new char[other.m_size+1]), m_size(other.m_size){
        strcpy(m_data, other.m_data);
    }

    // 构造函数，从 C 风格字符串构造
    String(const char* other) : m_data(new char[strlen(other)+1], m_size(strlen(other))) {
        strcpy(m_data, other);
    }

    // 移动构造函数
    String(String&& other) : m_data(other.m_data), m_size(other.m_size) noexcept {
        other.m_data = nullptr;
        other.m_size = 0;
    }

    // 返回字符串长度
    size_t size() const {
        return m_size;
    }

    // 返回 C 风格字符串
    const char* c_str() const {
        return m_data;
    }

    // 重载赋值运算符
    String& operator=(const String& other) {
        if(this != &other)
        {
            delete[] m_data;
            m_data = new char[other.m_size+1];
            m_size = other.m_size;
            strcpy(m_data, other.m_data);
        }

        return *this;
    }

    // 重载赋值运算符
    String operator+(const String& ohter) {
        String result;
        result.m_size = other.m_size + m_size;
        result.m_data = new char[result.m_size+1];
        strcpy(result.m_data, m_data);
        strcat(result.m_data, other.m_data);
        return result;
    }
    
    // 重载运算符，用于输出String对象
    friend ostream& operator<<(ostream& os, const String& str) {
        os << str.m_data;
        return os;
    }

    // 析构函数
    ~String() {
        delete[] m_data;
    }
private:
    char* m_data;
    size_t m_size;
};