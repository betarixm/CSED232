/* CSED232 OOP Assgin 4 Skeleton Code
This code is made based on Prof.Sunghyun Cho's code.
Do not modify outline of the code.*/
#ifndef __SMARTPTR_H__
#define __SMARTPTR_H__

#include <iostream>
#include <cassert>

/*
 *
 *  ██╗  ██╗ ██████╗ ███╗   ██╗ ██████╗ ██████╗
 *  ██║  ██║██╔═══██╗████╗  ██║██╔═══██╗██╔══██╗
 *  ███████║██║   ██║██╔██╗ ██║██║   ██║██████╔╝
 *  ██╔══██║██║   ██║██║╚██╗██║██║   ██║██╔══██╗
 *  ██║  ██║╚██████╔╝██║ ╚████║╚██████╔╝██║  ██║
 *  ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝
 *
 *        ██████╗ ██████╗ ██████╗ ███████╗
 *       ██╔════╝██╔═══██╗██╔══██╗██╔════╝
 *       ██║     ██║   ██║██║  ██║█████╗
 *       ██║     ██║   ██║██║  ██║██╔══╝
 *       ╚██████╗╚██████╔╝██████╔╝███████╗
 *        ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝
 *
 *
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 *
 */

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

		// 파라미터의 오브젝트 복사
		m_ref_object = pointer.m_ref_object;
		m_ref_object->increase_ref_count(); // 오브젝트 카운트 증가
	}
	~SmartPtr()
	{
		/*
		////////////////////////////////////
		2. Destructor
		You should implement your code here!
		////////////////////////////////////
		*/

		// 참조 카운트 감소
		// 카운트 감소 시 동적 할당 해제 체크하므로 따로 해제할 필요는 없음
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

		// nullptr가 아닌 경우 카운트 감소
		if(m_ref_object != nullptr) { m_ref_object->decrease_ref_count(); }
		m_ref_object = new CountedObjectContainer(object); // 새로운 컨테이너 할당

		return *this; // 자기 자신 참조형으로 반환
	}
	SmartPtr& operator=(const SmartPtr &ref_pointer)
	{
		/*
		////////////////////////////////////
		3. Assignment Operator
		You should implement your code here!
		////////////////////////////////////
		*/

		// 자기 자신을 대입하는 경우 반환
		if(&ref_pointer == this){ return *this; }

		// nullptr이 아닌 경우에만 대입될 카운트 증가
		if(ref_pointer.m_ref_object != nullptr) { ref_pointer.m_ref_object->increase_ref_count(); }

		// nullptr이 아닌 경우에만 현재 카운트 감소
		if(m_ref_object != nullptr) { m_ref_object->decrease_ref_count();}

		// 컨테이너 복사
		m_ref_object = ref_pointer.m_ref_object;
		return *this;
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
		// 행, 열 개수 정보 복사
		m_rows = rows;
		m_cols = cols;

		// 새로운 배열 할당
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

		// 행, 열 개수 복사
		m_rows = mtx.m_rows;
		m_cols = mtx.m_cols;
		// m_values = mtx.m_values;

		// 복사하는 경우 새로운 배열 할당
		auto tmp = new T[m_rows * m_cols]();

		// 값 딥카피
		for(int i = 0; i < m_rows * m_cols; i++){
		    tmp[i] = mtx.m_values[i];
		}

		// 임시 오브젝트 복사
		m_values = tmp;
	}
	SmartMatrix(int rows, int cols, const T* values)
	{
		/*
		////////////////////////////////////
		4. Constructor
		You should implement your code here!
		////////////////////////////////////
		*/

		// 임시로 사이즈 설정
		int size = rows * cols;

		// 행렬 사이즈 설정
		m_rows = rows;
		m_cols = cols;

		// 임시 배열 설정
        T* tmp = new T[size]();

        // 값 딥카피
        for(int i = 0; i < size; i++){
            tmp[i] = values[i];
        }

        // 임시 배열 대입
        m_values = tmp;
	}
	~SmartMatrix() {}
	// You don't have to implement Destructor because SmartMatrix use Smart Pointer.

	SmartMatrix<T>& operator=(const SmartMatrix<T>& mtx)
	{
		//Assignment operator
		m_rows = mtx.m_rows;
		m_cols = mtx.m_cols;
		m_values = new T[m_cols * m_rows]();
		for(int i = 0; i < m_cols * m_rows; i++){
		    m_values[i] = mtx.m_values[i];
		}
        // m_values = mtx.m_values;

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

		// 임시 배열 할당
		T* tmp = new T[m_cols * (m_rows+1)]();

		// 기존 값 딥 카피
		int i = 0;
		for(; i < m_cols * m_rows; i++){
		    tmp[i] = m_values[i];
		}

		// 새로운 row 값을 메모리 복사
		for(int j = 0; j < m_rows; j++){
		    tmp[i++] = values[j];
		}

		// 임시 배열 할당
		m_values = tmp;

		// 행 수 증가
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

		int col_counter = 0; // 새로운 칼럼 카운터
		int counter = 0; // 기존 데이터 카운터

		// 임시 배열 할당
		T* tmp = new T[(cols())*rows()]();

		// 새로운 값 딥카피
		for(int i = 0; i < (cols() + 1)*rows(); i++){
		    if(i % (cols() + 1) == cols()){ // 새로운 칼럼에 해당되는 경우
		        tmp[i] = values[col_counter++];
		    } else { // 기존 값을 복사하는 경우
		        tmp[i] = m_values[counter++];
		    }
		}

		// 임시 배열 복사
		m_values = tmp;

		// 칼럼 개수 증가
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

		// 행, 열 개수가 2인지 확인
		assert(rows() == 2);
		assert(cols() == 2);

		// determinant 확인
		T det = (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];

		// determinant가 0이 아닌지 확인
		assert(det != 0);

		// 임시 배열 할당
        T* tmp = new T[4] {(*this)[1][1] / det, -(*this)[0][1] / det, -(*this)[1][0] / det, (*this)[0][0] / det};

        // 기존 행렬도 수정
        m_values = tmp;

        // 역행렬 리턴
        return SmartMatrix<T>(rows(), cols(), tmp);
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

	// 행, 열 개수 체크
	assert(a.cols() == b.cols());
	assert(a.rows() == b.rows());

	// 새로운 행렬 설정
    SmartMatrix<T> ret(a.rows(), a.cols());
	for(int row = 0; row < a.rows(); row++){
	    for(int col = 0; col < a.cols(); col++){
            ret[row][col] = a[row][col] + b[row][col]; // 새로운 배열에 더한 값 설정
	    }
	}

	// 새로운 배열 설정
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

	// 행, 열 개수가 같은지 확인
    assert(a.cols() == b.cols());
    assert(a.rows() == b.rows());

    // 새로운 배열 설정
    SmartMatrix<T> ret(a.rows(), a.cols());
    for(int row = 0; row < a.rows(); row++){
        for(int col = 0; col < a.cols(); col++){
            ret[row][col] = a[row][col] - b[row][col]; // 새로운 배열에 뺀 값 설정
        }
    }

    // 새로운 배열 반환
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

    // 스칼라곱 구현
	for(int row = 0; row < a.rows(); row++){
	    for(int col = 0; col < a.cols(); col++){
	        ret[row][col] = a[row][col] *  s; // 스칼라 곱 된 결과로 설정
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

	// 앞 파라미터 열 개수와 뒤 파라미터 행 개수가 같은지 확인
	assert(a.cols() == b.rows());

	// ret 탐색
	for(int row = 0; row < a.rows(); row++){
	    for(int col = 0; col < b.cols(); col++){
	        int entry = 0;
            // a의 i번째 row b의 i번째 column을 내적
	        for(int i = 0; i < a.cols(); i++){
	            entry += (a[row][i] * b[i][col]);
	        }
	        // 내적 값으로 새로운 행렬 설정
	        ret[row][col] = entry;
	    }
	}
	return ret;
}
#endif