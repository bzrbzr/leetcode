#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ListNode
{
	struct ListNode *next;
	int value;
};

struct ListNode *creatnext(int n)
{
	struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->value = rand()%100;
	head->next = NULL;

	struct ListNode *last = head;

	while(--n)
	{
		struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
		tmp->value = rand()%100;
		tmp->next = NULL;
		last->next = tmp;
		last = tmp;
	}
	return head;
}


void printnode(struct ListNode *head)
{
	struct ListNode *p = head;
	if (p == NULL)
	{
		printf(" 123\n");
	}
	else
	{
		while(p->next != NULL)
		{
			printf("%d ",p->value);
			p = p->next;
		}
		printf("%d\n",p->value);
	}

}


int nodelen(struct ListNode *head)
{
	struct ListNode *p = head;
	int len = 0;
	while(p->next != NULL)
	{
		p = p->next;
		len++;
	}
	return ++len;
}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if (l1 == NULL)
	{
		return l2;
	}
	else if(l2 == NULL)
	{
		return l1;
	}

	if (l1->value <= l2->value)
	{
		l1->next = mergeTwoLists(l1->next,l2);
		return l1;
	}
	else
	{
		l2->next = mergeTwoLists(l1,l2->next);
		return l2;
	}

}


int main(int argc, char const *argv[])
{
	int lenth = 0;
	int findval = 0;
	struct ListNode *p1 = NULL;
	struct ListNode *p2 = NULL;
	struct ListNode *p3 = NULL;
	p1 = creatnext(2);
	p2 = creatnext(3);
	printnode(p1);
	printnode(p2);
	p3 = mergeTwoLists(p1,p2);
	//lenth = nodelen(p);
	//printf("lenth = %d\n",lenth);
	//p = clearlist(p);
	//lenth = nodelen(p);
	//printf("lenth = %d\n",lenth);
	//findval = findnode(p,7);
	//printf("findval = %d\n",findval);

	printnode(p3);

	return 0;
}