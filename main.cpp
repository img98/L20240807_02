#include <iostream>
#include <random>
#include "Player.h"
#include "Goblin.h"
#include "Slime.h"
#include "Boar.h"
using namespace std;

//깃허브 커밋 실험

template<typename T> //자료형을 변수처럼 받는다. 템플릿함수
T Add(T A, T B)
{
	return A + B;
}
template<typename T>
T Sub(T A, T B)
{

}
template<typename T>
T Mul(T A, T B)
{

}


int main()
{
	//F7을 누르면 컴파일러가 생서오디는 이런걸 메타코드라고한다.
	//컴파일 할때 코드가 생성된다.
	Add<int>(1, 2);
	Add<char>('A', 'B');


	vector<AActor*> Actors;

	//액터 생성
	APlayer* Player = new APlayer;
	Actors.push_back(new APlayer);
	{
		random_device RandomMachine;
		mt19937 RandomSeed(RandomMachine());
		uniform_int_distribution<> dist(3, 15);
		int RandomCount = dist(RandomSeed);
		for (int i = 0; i < RandomCount; ++i)
		{
			if (i % 3 == 0)
			{
				Actors.push_back(new AGoblin);
			}
			if (i % 3 == 1)
			{
				Actors.push_back(new ASlime);
			}
			if (i % 3 == 2)
			{
				Actors.push_back(new ABoar);
			}
		}
	}

	//액터 행동
	for (auto Actor : Actors)
	{
		Actor->Move();
	}

	//액터 해제	
	for (auto Actor : Actors)
	{
		delete Actor;
	}
	Actors.clear();
	
	return 0;
}