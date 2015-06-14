#pragma once

#include <memory>

template <typename T>
class CMyArray
{
public:
	CMyArray()
		:m_size(0)
	{}

	CMyArray(const CMyArray& otherArray)
	{
		m_elements = make_unique<T[]>(otherArray.GetSize());
		for (size_t i = 0; i < otherArray.GetSize(); ++i)
		{
			m_elements[i] = otherArray[i];
		}
		m_size = otherArray.GetSize();
	}

	~CMyArray()
	{}

	void Add(const T& value)
	{
		auto tempElements = std::make_unique<T[]>(m_size + 1);
		for (size_t i = 0; i < m_size; ++i)
		{
			tempElements[i] = m_elements[i];
		}
		tempElements[m_size] = value;
		m_elements = std::move(tempElements);
		m_size++;
	}


	void Resize(size_t size)
	{
		auto tempElements = std::make_unique<T[]>(size);
		for (size_t i = 0; i < size; i++)
		{
			tempElements[i] = m_elements[i];
		}
		m_elements.reset();
		m_elements = move(tempElements);
		m_size = size;
	}

	void Clear()
	{
		m_size = 0;
		m_elements.reset();
	}

	CMyArray & operator = (const CMyArray& otherArray)
	{
		m_size = otherArray.GetSize();
		m_elements = std::make_unique<T[]>(m_size);
		for (size_t i = 0; i < m_size; i++)
		{
			m_elements[i] = otherArray[i];
		}
		return *this;
	}

	size_t GetSize()const
	{
		return m_size;
	}

	T & operator [](size_t index) const
	{
		if ((index >= 0) && (index < m_size))
		{
			return m_elements[index];
		}
		else
		{
			throw std::out_of_range("item index is out of range");
			return m_elements[0];
		}
	}

private:
	size_t m_size;
	std::unique_ptr<T[]> m_elements;
};
