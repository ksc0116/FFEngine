#pragma once
#include <assert.h>

namespace FFEngine
{
	template <typename T>
	class Singleton
	{
	private:
#ifdef _DEBUG
		static bool isInit;
#endif
		
	public:
		Singleton(const Singleton& c) = delete;
		void operator=(const Singleton& c) = delete;

		static T& GetInstance()
		{
#ifdef _DEBUG
			isInit = true;
#endif
			static T inst;
#ifdef _DEBUG
			isInit = false;
#endif

			return inst;
		}

	protected:
		Singleton() 
		{
			// 여기서 assert에 걸린다면 싱글톤 객체를 외부에서 생성자를 통해 부르려하기 때문이다.
			assert(isInit);
		}
	};
}

template <typename T>
bool FFEngine::Singleton<T>::isInit = false;