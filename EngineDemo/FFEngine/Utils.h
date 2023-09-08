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
			// ���⼭ assert�� �ɸ��ٸ� �̱��� ��ü�� �ܺο��� �����ڸ� ���� �θ����ϱ� �����̴�.
			assert(isInit);
		}
	};
}

template <typename T>
bool FFEngine::Singleton<T>::isInit = false;