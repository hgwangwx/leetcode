template<typename T>
class SmartPtr {
public:
    SmartPtr(): ptr(nullptr), ref_count(nullptr) {}
    SmartPtr(T* t): ptr(t), ref_count(new int(1)){}
    SmartPtr(SmartPtr& other) {
        ptr = other.ptr;
        ref_count = other.ref_count;
        (*ref_count)++;
    }

    // 析构函数
    ~SmartPtr() {
        if(0 == --(*ref_count))
        {
            delete ptr;
            delete ref_count;
            ptr = nullptr;
            ref_count = nullptr;
        }
    }

    SmartPtr<T> operator=(const SmartPtr<T>& other)
    {
        // 自我赋值
        if (this != &other) {
            // 当前指针引用计数减一
            if (--(*ref_count) == 0) {
                delete ptr;
                delete ref_count;
            }

        ptr = other.ptr;
        ref_count = other.ref_count;
        (*ref_count)++;
    }

    // 解引用运算符
    T& operator*() const {
        assert(this->_ptr == nullptr);
        return *(this->ptr);
    }

    // 指针运算符
    T* operator->() const {
        assert(this->_ptr == nullptr);
        return this->ptr;
    }

private:
    T* ptr;
    int* ref_count;

};