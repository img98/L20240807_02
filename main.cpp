#include <iostream>
#include <random>
#include "Player.h"
#include "Goblin.h"
#include "Slime.h"
#include "Boar.h"
using namespace std;

//����� Ŀ�� ����

template<typename T> //�ڷ����� ����ó�� �޴´�. ���ø��Լ�
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
	//F7�� ������ �����Ϸ��� ��������� �̷��� ��Ÿ�ڵ����Ѵ�.
	//������ �Ҷ� �ڵ尡 �����ȴ�.
	Add<int>(1, 2);
	Add<char>('A', 'B');


	vector<AActor*> Actors;

	//���� ����
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

	//���� �ൿ
	for (auto Actor : Actors)
	{
		Actor->Move();
	}

	//���� ����	
	for (auto Actor : Actors)
	{
		delete Actor;
	}
	Actors.clear();
	
	return 0;
}