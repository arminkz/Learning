template<typename T>
class SharedPtr {

public:

    explicit SharedPtr(T* raw) {
        count_ = new long(1);
        ptr_ = raw;
    }

    ~SharedPtr() {
        destroy();
    }

    SharedPtr(const SharedPtr& other) {
        count_ = other.count_;
        ptr_ = other.ptr_;
        (*count_)++;
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (this == &other) { return *this; }

        destroy();

        count_ = other.count_;
        ptr_ = other.ptr_;
        (*count_)++;

        return *this;
    }

    SharedPtr(SharedPtr&& other) noexcept {
        count_ = other.count_;
        ptr_ = other.ptr_;

        other.count_ = nullptr;
        other.ptr_ = nullptr;
    }

    SharedPtr& operator=(SharedPtr&& other) noexcept {
        if (this == &other) { return *this; }

        destroy();

        count_ = other.count_;
        ptr_ = other.ptr_;

        other.count_ = nullptr;
        other.ptr_ = nullptr;

        return *this;
    }

    T* get() const { return ptr_; }
    T* operator->() const { return ptr_; }
    T& operator*() const { return *ptr_; }

private:

    T* ptr_;
    long* count_;


    void destroy() {
        if (count_ == nullptr) return;
        if (--(*count_) == 0) { 
            delete ptr_; 
            delete count_; 
        }
    }

};