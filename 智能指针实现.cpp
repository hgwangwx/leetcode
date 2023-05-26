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

    SmartPtr<T>& operator=(const SmartPtr<T>& other)
    {
        // 自我赋值
        if (this != &other) {
            // 当前指针引用计数减一
            if (--(*ref_count) == 0) {
                delete ptr;
                delete ref_count;
                ptr = nullptr;
                ref_count = nullptr;
            }

            ptr = other.ptr;
            ref_count = other.ref_count;
            (*ref_count)++;
    }

    // 拷贝构造函数
    SmartPtr(const SmartPtr<T>& other)
        : ptr(other.ptr), ref_count(other.ref_count) {
        (*ref_count)++;
    }

     // 移动构造函数
    SmartPtr(SmartPtr&& other) noexcept : ptr_(other.ptr_), refCount_(other.refCount_) {
        other.ptr_ = nullptr;
        other.refCount_ = nullptr;
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

    size_t count() const {
        return *ref_count;
    }

private:
    T* ptr;
    size_t* ref_count;

};