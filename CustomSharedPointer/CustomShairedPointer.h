#pragma once

template <typename T>
class CustomSharedPointer final
{
public:
	CustomSharedPointer(const T& l_data);
	CustomSharedPointer(CustomSharedPointer<T>& l_source);

	T GetData();
	void ChangeData(const T& l_data);

	//TO BE DELETE CODE STARTS
	T* GetDataRawPointer();
	int* GetCounterRawPointer();

	//TO BE DELETE CODE ENDS

	int GetNumOfPointingObjects();

	~CustomSharedPointer();
private:
	int* m_counter = nullptr;
	T* m_data = nullptr;
};

template<typename T>
CustomSharedPointer<T>::CustomSharedPointer(const T& l_data)
{
	m_counter = new int(1);
	m_data = new T(l_data);
}

template<typename T>
CustomSharedPointer<T>::CustomSharedPointer(CustomSharedPointer<T>& l_source)
{
	m_counter = l_source.m_counter;
	(*m_counter)++;
	m_data = l_source.m_data;
}

template<typename T>
T CustomSharedPointer<T>::GetData()
{
	return *m_data;
}

template<typename T>
void CustomSharedPointer<T>::ChangeData(const T& l_data)
{
	(*m_data) = l_data;
}

template<typename T>
T* CustomSharedPointer<T>::GetDataRawPointer()
{
	return m_data;
}

template<typename T>
int* CustomSharedPointer<T>::GetCounterRawPointer()
{
	return m_counter;
}

template<typename T>
int CustomSharedPointer<T>::GetNumOfPointingObjects()
{
	return *m_counter;
}

template<typename T>
CustomSharedPointer<T>::~CustomSharedPointer()
{
	(*m_counter)--;

	if (*m_counter <= 0)
	{
		delete m_counter;
		delete m_data;
	}
}
