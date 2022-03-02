/****************************************************************************
** SAKARYA ÜNÝVERSÝTESÝ
** BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
** BÝLÝÞÝM SÝSTEMLERÝ MÜHENDÝSLÝÐÝ BÖLÜMÜ
** VERÝ YAPILARI
** 2020-2021 YAZ DÖNEMÝ
**
** ÖDEV NUMARASI..........:1
** ÖÐRENCÝ ADI............:Ayþe Tuba Kahraman
** ÖÐRENCÝ NUMARASI.......:b191200025
** DERSÝN ALINDIÐI GRUP...:C GRUBU
****************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdbool.h>

struct linkedList {
	int data;
	struct linkedList* before;
	struct linkedList* after;
};
struct linkedList* firstLink1 = NULL;
struct linkedList* firstLink2 = NULL;

struct linkedList* init(int data)
{
	struct linkedList* newLink = (struct linkedList*)malloc(sizeof(struct linkedList));
	newLink->data = data;
	newLink->before = NULL;
	newLink->after = NULL;
	return newLink;
}

void AddEnd(int data);
void AddEnd2(int data);
void PrintLinkedList(struct linkedList* link);
void AddEnd(int data)
{
	if (firstLink1 == NULL)
	{
		firstLink1 = init(data);
	}
	else
	{
		struct linkedList* temp1 = firstLink1;
		struct linkedList* temp2 = (struct linkedList*)malloc(sizeof(struct linkedList));
		while (temp1->after != NULL)
		{
			temp1 = temp1->after;
		}
		temp2->data = data;
		temp2->before = temp1;
		temp2->after = NULL;
		temp1->after = temp2;
	}
}
void AddEnd2(int data)
{
	if (firstLink2 == NULL)
	{
		firstLink2 = init(data);
	}
	else
	{
		struct linkedList* temp1 = firstLink2;
		struct linkedList* temp2 = (struct linkedList*)malloc(sizeof(struct linkedList));
		while (temp1->after != NULL)
		{
			temp1 = temp1->after;
		}
		temp2->data = data;		
		temp2->after = NULL;
		temp2->before = temp1;
		temp1->after = temp2;
	}
}
void Reverse(struct linkedList** head)
{
	struct linkedList* temp = NULL;
	struct linkedList* current = *head;
	while (current->before != NULL)
	{
		current = current->before;
	}
	while (current != NULL)
	{
		temp = current->before;
		current->before = current->after;
		current->after = temp;
		current = current->before;
	}
}
void PrintLinkedList(struct linkedList* link)
{
	struct linkedList* temp = link;
	while (temp->before != NULL)
	{
		temp = temp->before;
	}
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->after;
	}
	printf("\n");
}

struct linkedList* GetAtRank(struct linkedList* link, int rank)
{
	struct linkedList* temp = link;
	while (temp->before != NULL)
	{
		temp = temp->before;
	}
	for (size_t i = 0; i < rank; i++)
	{
		temp = temp->after;
	}
	return temp;
}

void SwapLink(struct linkedList* link1, struct linkedList* link2)
{
	struct linkedList* temp1 = link1;
	struct linkedList* temp2 = link2;
	if (temp1->after == NULL)//SONUNDAYSA 
	{
		struct linkedList* templink1Before = link1->before;
		struct linkedList* templink2Before = link2->before;
		struct linkedList* templink1 = link1;

		temp1->before->after = link2;
		temp2->before = templink1Before;
		temp1->before = templink2Before;
		templink1->before->after = link1;
	}
	else if (temp1->before == NULL)//BAÞINDAYSA
	{
		struct linkedList* templink1After = link1->after;
		struct linkedList* templink2After = link2->after;
		struct linkedList* templink1 = link1;

		temp1->after->before = link2;
		temp2->after = templink1After;
		temp1->after = templink2After;
		templink1->after->before = link1;
	}
	else //ORTADAYSA
	{
		struct linkedList* templink1After = link1->after;
		struct linkedList* templink1Before = link1->before;

		struct linkedList* templink2After = link2->after;
		struct linkedList* templink2Before = link2->before;

		struct linkedList* templink1 = link1;

		temp1->before->after = link2;
		temp1->after->before = link2;

		temp2->after = templink1After;
		temp2->before = templink1Before;

		temp1->after = templink2After;
		temp1->before = templink2Before;

		templink1->before->after = link1;
		templink1->after->before = link1;
	}
}

void Function(struct linkedList* _link1, struct linkedList* _link2)
{
	struct linkedList* link1 = _link1;
	struct linkedList* link2 = _link2;
	int i = 0;
	while (link1 != NULL)
	{
		if (link1->data > link2->data)
		{
			printf("\nsayi1: %d > sayi2: %d", link1->data, link2->data);
			Reverse(&link1);
		}
		else if (link1->data == link2->data)
		{
			printf("\nsayi1: %d == sayi2: %d", link1->data, link2->data);
			Reverse(&link2);
		}
		else if (link1->data < link2->data)
		{
			printf("\nsayi1: %d < sayi2: %d", link1->data, link2->data);
			SwapLink(link1, link2);
			link1 = _link1;
			link2 = _link2;
		}
		printf("\n");
		printf("sayi1 ");
		PrintLinkedList(_link1);
		printf("sayi2 ");
		PrintLinkedList(_link2);

		i++;
		link1 = GetAtRank(link1, i);
		link2 = GetAtRank(link2, i);
	}
}
int main()
{
	//815102162524#622101830754
	char text[100] = "";
	FILE* fp;
	fp = fopen("Sayi.txt", "r");
	fscanf(fp, "%s", text);

	int size = strlen(text);
	int count = ((size - 1) / 2) / 3;
	int j = 0;
	int k = 0;
	int t = 0;
	char text2[3] = "000";
	int numberList1[100] = { 0,0 };
	int numberList2[100] = { 0,0 };

	bool secondPart = false;
	for (size_t i = 0; i < size; i++)
	{
		if (text[i] == '#')
		{
			secondPart = true;
			continue;
		}
		if (text[i] == 0 && j == 0)
			text2[j] = 1;
		else
			text2[j] = text[i];
		j++;
		if (j == 3)
		{
			if (!secondPart)
			{
				numberList1[k] = atoi(text2);
				k++;
			}
			else
			{
				numberList2[t] = atoi(text2);
				t++;
			}
			j = 0;
		}
	}
	for (size_t i = 0; i < count; i++)
	{
		AddEnd(numberList1[i]);
		AddEnd2(numberList2[i]);
	}
	printf("sayi1 ");
	PrintLinkedList(firstLink1);
	printf("sayi2 ");
	PrintLinkedList(firstLink2);

	Function(firstLink1, firstLink2);
}

