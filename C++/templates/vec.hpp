#include <utility>


template<typename T>
class Vec {

public:
    Vec() {
        size_ = 0;
        capacity_ = 4;
        buffer_ = new T[capacity_];
    }

    ~Vec() {
        delete[] buffer_;
    }

    Vec(const Vec& other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        buffer_ = new T[capacity_];
        for(int i=0; i<size_; i++) {
            buffer_[i] = other.buffer_[i];
        }
    }

    Vec& operator=(const Vec& other) {
        if(this == &other) return *this;
        delete[] buffer_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        buffer_ = new T[capacity_];
        for(int i=0; i<size_; i++) {
            buffer_[i] = other.buffer_[i];
        }
        return *this;
    }

    Vec(Vec&& other) noexcept {
        //steal
        size_ = other.size_;
        capacity_ = other.capacity_;
        buffer_ = other.buffer_;
        //nullify
        other.capacity_ = 0;
        other.size_ = 0;
        other.buffer_ = nullptr;
    }

    Vec& operator=(Vec&& other) noexcept {
        if(this == &other) return *this;
        //cleanup
        delete[] buffer_;
        //steal
        size_ = other.size_;
        capacity_ = other.capacity_;
        buffer_ = other.buffer_;
        //nullify
        other.capacity_ = 0;
        other.size_ = 0;
        other.buffer_ = nullptr;
        return *this;
    }

    void push_back(const T& val) {
        grow_if_full();
        buffer_[size_] = val;
        size_++;
    }

    template<typename... Args>
    void emplace_back(Args&&... args) {
        grow_if_full();
        buffer_[size_] = T(std::forward<Args>(args)...);
        size_++;
    }

    int size() const { return size_; }
    int capacity() const { return capacity_; }
    T& operator[](int idx) { return buffer_[idx]; }
    const T& operator[](int idx) const { return buffer_[idx]; }

private:

    int capacity_;
    int size_;
    T* buffer_;

    void grow_if_full() {
        //handle when buffer gets full
        if (size_ == capacity_) {
            capacity_ *= 2;
            T* new_buffer = new T[capacity_];
            for(int i=0; i<size_; i++) {
                new_buffer[i] = buffer_[i];
            }
            delete[] buffer_;
            buffer_ = new_buffer;
        }
    }

};