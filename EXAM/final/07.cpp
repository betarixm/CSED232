template<class T> class my_unique_ptr{
public:
    my_unique_ptr(): m_ptr(nullptr){}
    explicit my_unique_ptr(T* p) : m_ptr(p) {};
    my_unique_ptr(const my_unique_ptr& p) = delete;

    // move constructor
    /// Answer ////////////////////////////////////////////////
    my_unique_ptr(my_unique_ptr&& p) noexcept{
        this->m_ptr = p.m_ptr;
        p.m_ptr = nullptr;
    }
    ///////////////////////////////////////////////////////////

    ~my_unique_ptr() { delete m_ptr; }
    my_unique_ptr& operator=(const my_unique_ptr& p) = delete;

    // move assignment operator
    /// Answer ////////////////////////////////////////////////
    my_unique_ptr& operator=(my_unique_ptr&& p) noexcept {
        if(this == &p){ return *this; }
        delete m_ptr;
        m_ptr = p.m_ptr;
        p.m_ptr = nullptr;
        return *this;
    }
    ///////////////////////////////////////////////////////////

    T& operator*() { return *m_ptr; }
    const T& operator*() const { return *m_ptr; }

    T& operator->() { return *m_ptr; }
    const T& operator->() const { return *m_ptr; }


private:
    T* m_ptr;
};