#include "Queues.h"

typedef ListQueues<int> Queues;

int main()
{
	Queues* queues = new Queues();
	for (int i = 1; i <= 7; i++)
	{
		int* index = new int;
		*index = *(&i);
		queues->Push_Back(Queues::Create(&index));
	}

	queues->Print();

	cout << queues->GetSize() << endl << endl;

	ListQueues<int>::Node* node = queues->Pop_Front();

	cout << *node->Data << endl;

	queues->Print();

	cout << queues->GetSize() << endl << endl;

	queues->RemoveAll();

	cout << queues->GetSize() << endl << endl;

	return 0;
}