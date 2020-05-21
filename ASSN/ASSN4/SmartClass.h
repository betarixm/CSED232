/* CSED232 OOP Assgin 4 Skeleton Code
This code is made based on Prof.Sunghyun Cho's code.
Do not modify outline of the code.*/
#ifndef __SMARTPTR_H__
#define __SMARTPTR_H__

#include <iostream>
#include <cassert>

template<typename ObjectType>
void Deallocator(ObjectType* ptr)
{
	#ifdef DeallocMessage
	std::cout << "Deallocate an object" << std::endl;
	#endif
	delete ptr;
}

template<typename ObjectType>
void ArrayDeallocator(ObjectType* ptr)
{
	#ifdef DeallocMessage
	std::cout << "Deallocate an array" << std::endl;
	#endif
	delete[] ptr;
}

template<typename T>
using DeallocatorFuncType = void (T*);

//SmartPtr Decralation
template<typename ObjectType, DeallocatorFuncType<ObjectType> Dealloc = Deallocator<ObjectType> >
class SmartPtr
{
	class CountedObjectContainer
	{
	private:
		~CountedObjectContainer() { if( m_object ) { Dealloc(m_object); } }

	public:
		CountedObjectContainer() : m_ref_count(0), m_object(nullptr) {} 
		CountedObjectContainer(ObjectType* obj) : m_ref_count(1), m_object(obj) {}

		void increase_ref_count() { ++m_ref_count; }
		void decrease_ref_count() { if(--m_ref_count == 0) delete this; }
		const ObjectType* get_object() const { return m_object; }
		ObjectType* get_object() { return m_object; }
		int get_ref_count() const { return m_ref_count; }

	private:
		int m_ref_count;
		ObjectType* m_object;
	};

private:
	CountedObjectContainer *m_ref_object;
public:
	SmartPtr() : m_ref_object(nullptr) {}
	SmartPtr(ObjectType* object)	
	{
		/*
		////////////////////////////////////
		1. Constructor
		You should implement your code here!
		////////////////////////////////////
		*/

		m_ref_object = new CountedObjectContainer(object);
	}
	SmartPtr(const SmartPtr& pointer)
	{
		/*
		////////////////////////////////////
		1. Copy Constructor
		You should implement your code here!
		////////////////////////////////////
		*/

		m_ref_object = pointer.m_ref_object;
		m_ref_object->increase_ref_count();
	}
	~SmartPtr()
	{
		/*
		////////////////////////////////////
		2. Destructor
		You should implement your code here!
		////////////////////////////////////
		*/

        if(m_ref_object != nullptr) m_ref_object->decrease_ref_count();
	}
	SmartPtr& operator=(ObjectType *object)
	{
		/*
		////////////////////////////////////
		3. Assignment Operator
		You should implement your code here!
		////////////////////////////////////
		*/

		if(m_ref_object != nullptr) { m_ref_object->decrease_ref_count(); }
		m_ref_object = new CountedObjectContainer(object);

		return *this;
	}
	SmartPtr& operator=(const SmartPtr &ref_pointer)
	{
		/*
		////////////////////////////////////
		3. Assignment Operator
		You should implement your code here!
		////////////////////////////////////
		*/

		if(&ref_pointer == this){ return *this; }
		if(ref_pointer.m_ref_object != nullptr) { ref_pointer.m_ref_object->increase_ref_count(); }
		if(m_ref_object != nullptr) { m_ref_object->decrease_ref_count();}
		m_ref_object = ref_pointer.m_ref_object;
		return *this;
	}

	int ref_count()
	{
		return m_ref_object->get_ref_count();
	}

	const ObjectType* operator->() const
	{
		assert(m_ref_object);
		return m_ref_object->get_object();
	}

	ObjectType* operator->()
	{
		assert(m_ref_object);
		return m_ref_object->get_object();
	}

	const ObjectType& operator*() const
	{
		assert(m_ref_object);
		return *(m_ref_object->get_object());
	}

	ObjectType& operator*()
	{
		assert(m_ref_object);
		return *(m_ref_object->get_object());
	}

	const ObjectType& operator[](int i) const
	{
		assert(m_ref_object);
		return (m_ref_object->get_object())[i];
	}

	ObjectType& operator[](int i)
	{
		assert(m_ref_object);
		return (m_ref_object->get_object())[i];
	}

	operator ObjectType const*() const
	{
		assert(m_ref_object);
		return m_ref_object->get_object();
	}

	operator ObjectType *()
	{
		assert(m_ref_object);
		return m_ref_object->get_object();
	}
};
template<typename T>
using SmartArray = SmartPtr<T, ArrayDeallocator<T> >;

#endif


//SmartMatrix Declartion.
#ifndef __SMARTMATRIX_H__
#define __SMARTMATRIX_H__

template<typename T>
class SmartMatrix
{
private:
	int m_rows, m_cols;
	SmartArray<T> m_values;
public:
	SmartMatrix() : m_rows(0), m_cols(0), m_values(nullptr) {}
	SmartMatrix(int rows, int cols) 
	{
		/*
		////////////////////////////////////
		4. Constructor
		You should implement your code here!
		////////////////////////////////////
		*/
		m_rows = rows;
		m_cols = cols;
		m_values = new T[rows * cols]();
	}
	SmartMatrix(const SmartMatrix<T>& mtx)
	{
		/*
		////////////////////////////////////
		4. Copy Constructor
		You should implement your code here!
		////////////////////////////////////
		*/
		m_rows = mtx.m_rows;
		m_cols = mtx.m_cols;
		m_values = mtx.m_values;
	}
	SmartMatrix(int rows, int cols, const T* values)
	{
		/*
		////////////////////////////////////
		4. Constructor
		You should implement your code here!
		////////////////////////////////////
		*/
		int size = rows * cols;
		m_rows = rows;
		m_cols = cols;
        T* tmp = new T[size]();
        for(int i = 0; i < size; i++){
            tmp[i] = values[i];
        }

        m_values = tmp;
	}
	~SmartMatrix() {}
	// You don't have to implement Destructor because SmartMatrix use Smart Pointer.

	SmartMatrix<T>& operator=(const SmartMatrix<T>& mtx)
	{
		//Assignment operator
		m_rows = mtx.m_rows;
		m_cols = mtx.m_cols;
		m_values = mtx.m_values;
		return *this;
	}
	void AddRow(const T* values)
	{
		/*
		////////////////////////////////////
		5. Add Row
		You should implement your code here!
		////////////////////////////////////
		*/
		int counter = 0;
		T* tmp = new T[m_cols * (m_rows+1)]();

		while(counter < m_cols * m_rows){
		    tmp[counter] = m_values[counter++];
		}
		memcpy(&(tmp[m_cols * m_rows]), values, m_rows * sizeof(int));
		m_values = tmp;
		m_rows++;
	}
	void AddCol(const T* values)
	{
		/*
		////////////////////////////////////
		6. Add Colomn
		You should implement your code here!
		////////////////////////////////////
		*/
		int counter = 0;
		T* tmp = new T[(cols())*rows()]();
		for(int i = 0; i < (cols() + 1)*rows(); i++){
		    if(i % cols() == 0 && i > 0){
		        tmp[i] = values[counter++];
		    } else {
		        tmp[i] = m_values[i];
		    }
		}
		m_values = tmp;
		m_cols++;
	}
	const SmartMatrix<T> Inverse()
	{
		/*
		////////////////////////////////////
		7. Calculate Inverse Matrix oif 2x2 Matrix
		You should implement your code here!
		////////////////////////////////////
		*/

		assert(rows() == 2);
		assert(cols() == 2);
		T det = (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
        assert(det != 0);
        T tmp[4] = {(*this)[1][1] / det, -(*this)[0][1] / det, -(*this)[1][0] / det, (*this)[1][1] / det};
        return SmartMatrix<T>(2, 2, tmp);
	}

	T* operator[](int r)
	{
		return &m_values[r * m_cols];
	}

	const T* operator[](int r) const
	{
		return &m_values[r * m_cols];
	}

	int rows() const { return m_rows; }
	int cols() const { return m_cols; }

	const SmartMatrix<T> clone() const
	{
		return SmartMatrix<T>(m_rows, m_cols, (const T*)m_values);
	}
};

//Operator Overloading

template<typename T>
std::ostream& operator<<(std::ostream& os, const SmartMatrix<T>& m)
{
	//Stream extraction operator overloading
	//Now you can print SmartMatrix
	for(int r = 0; r < m.rows(); r++) { 
		for(int c = 0; c < m.cols(); c++) {
			os << m[r][c] << " ";
		}
		os << std::endl;
	}

	return os;
}

template<typename T>
const SmartMatrix<T> operator+(const SmartMatrix<T>& a, const SmartMatrix<T>& b)
{
	/*
	////////////////////////////////////
	8. Add Operator Overloading
	You should implement your code here!
	////////////////////////////////////
    */

	assert(a.cols() == b.cols());
	assert(a.rows() == b.rows());

    SmartMatrix<T> ret(a.rows(), a.cols());
	for(int row = 0; row < a.rows(); row++){
	    for(int col = 0; col < a.cols(); col++){
            ret[row][col] = a[row][col] + b[row][col];
	    }
	}

	return ret;

}


template<typename T>
const SmartMatrix<T> operator-(const SmartMatrix<T>& a, const SmartMatrix<T>& b)
{
	/*
	////////////////////////////////////
	9. Subtract Operator Overloading
	You should implement your code here!
	////////////////////////////////////
     */
    assert(a.cols() == b.cols());
    assert(a.rows() == b.rows());

    SmartMatrix<T> ret(a.rows(), a.cols());
    for(int row = 0; row < a.rows(); row++){
        for(int col = 0; col < a.cols(); col++){
            ret[row][col] = a[row][col] + b[row][col];
        }
    }

    return ret;

}

template<typename T>
const SmartMatrix<T> operator*(const SmartMatrix<T>& a, T s)
{
	SmartMatrix<T> ret(a.rows(), a.cols());
	/*
	////////////////////////////////////
	10. Multiply Operator Overloading
	You should implement your code here!
	////////////////////////////////////
	*/

	for(int row = 0; row < a.rows(); row++){
	    for(int col = 0; col < a.cols(); col++){
	        ret[row][col] = a[row][col] *  s;
	    }
	}
	return ret;
}

template<typename T>
inline const SmartMatrix<T> operator*(T s, const SmartMatrix<T>& a)
{
	/*
	Multiply Operator Overloading
	You Don't have to implement here.
	*/
	return a * s;
}
template<typename T>
inline const SmartMatrix<T> operator*(const SmartMatrix<T>& a, const SmartMatrix<T>& b)
{
	SmartMatrix<T> ret(a.rows(), b.cols());
	/*
	////////////////////////////////////
	10. Multiply Operator Overloading
	You should implement your code here!
	////////////////////////////////////
	*/

	assert(a.cols() == b.rows());

	for(int row = 0; row < a.rows(); row++){
	    for(int col = 0; col < b.cols(); col++){
	        int entry = 0;
	        for(int i = 0; i < a.cols(); i++){
	            entry += (a[row][i] * b[i][col]);
	        }
	        ret[row][col] = entry;
	    }
	}
	return ret;
}
#endif