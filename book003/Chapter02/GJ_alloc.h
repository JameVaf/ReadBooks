# ifndef __GJ_ALLOC_H__
#define __GJ_ALLOC_H__

#include<new> //主要是使用定位new
#include<cstddef> //use ptrdiff_t ,size_t
#include<cstdlib> //use exit()
#include<climits> //for UINT_MAX
#include<iostream>

namespace GJ
{

    void no_memory()
    {
        std::cout << "Failed to allocate memory!\n";
        std::exit(1);
    }
   
    template<class T>
    inline T* _allocate(ptrdiff_t size,T*)
    {
        std::set_new_handler(no_memory); //设置new 失败时调用的函数 ,参数0,使用默认的抛出bad_alloc
        T *temp = (T *)(::operator new((size_t)(size * sizeof(T))));
        if(nullptr == temp)
        {
            std::cerr << "out of memory" << std::endl;
            exit(1);
        }
        return temp;
    }

    template<class T>
    inline void _deallocate(T* buffer)
    { 
        ::operator delete(buffer);
    }

    template<class T1,class T2>
    inline void _construct(T1 *p,const T2&value )
    {
        new (p)T1(value);//定位new到p中
    }

    template<class T>
    inline void _destroy(T* ptr)
    {
        ptr->~T();
    }

    template<class T>
    class allocator
    {
    public:
        typedef T value_type;
        typedef T *pointer;
        typedef const T *const_pointer;
        typedef T &reference;
        typedef const T &const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t diffrence_type;

        // 重新绑定allocator U
        template <class U>
        struct rebind
        {
            typedef allocator<U> other; 
        };

        //用于位置提示
        pointer allocate(size_type n,const void* hint = 0)
        {
            return _allocate((diffrence_type)n, (pointer)0);
        };

        void deallocate(pointer p, size_type n) { _deallocate(p); }

        void construct(pointer p,const T& value)
        {
            _construct(p, value);
        };

        void destroy(pointer p) { _destroy(p); }

        pointer address(reference x) { return (pointer)&x; };

        const_pointer const_address(const_reference x) { return (const_pointer)&x; }

        size_type max_size()const 
        {
            return size_type(UINT_MAX / sizeof(T));
        };
    };
};//end of namespace GJ

#endif //__GJ_ALLOC_H__